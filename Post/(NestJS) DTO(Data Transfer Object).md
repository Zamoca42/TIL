NestJS를 사용하게 되면서 조금 생소한 개념 DTO(Data Transfer Object)에 대해 알아보려고 합니다. 처음 알게 되었던 DTO의 역할은 단순히 타입설정 정도로 알고 있었는데, 큰 오해였습니다.

DTO는 MVC 패턴에서 View와 도메인의 Model의 데이터를 주고 받을 때 사용하는 객체로 어떠한 비즈니스 로직을 가져서는 안되며, 저장, 검색, 직렬화, 역직렬화 로직만을 가져야 한다고 합니다.

NestJS에서는 Service나 Controller와는 분리된 데이터 변환 계층에서 데이터를 전달하는 객체라고 정리해볼 수 있습니다. [이번 프로젝트]()에서는 회원 조회, 수정하는데에 사용하면서 DTO의 역할을 체감하게 되었는데 
이 부분을 정리해보도록 하겠습니다

## 모델

```javascript
export class Customer extends Item {
	user_id: string;
	email: string;
	phone_number: string;
	marketing_information_agree_date: string;
	personal_data_retention_period: Date;
	archive_time: number;
	create_time: Date;
	update_time: Date; 
}

export class CustomerMeta extends Item {
	id: string;
	lastSignInIp: string;
	subscriptionPath: string;
	lastSignInTime: Date;
	businessAddress: string;
	businessName: string;
	name: string;
	gender: string;
	businessItem: string;
	accountStatus: string;
	businessType: string;
	businessNumber: string;
	job: string;
	age: number;
}

// dynamoose.model은 생략
```

모델부터 살펴보도록 하겠습니다 여기서 Item은 [Dynamoose의 모델의 Item](https://dynamoosejs.com/getting_started/Introduction)입니다
Customer와 CustomerMeta를 비교해보면 Customer에는 필드 이름이 `snake_case`로 사용되었고, CustomerMeta에는 필드가 `CamelCase`로 사용했습니다. 이 부분은 제가 작성한게 아니라 존재하는 프로덕션의 DB 테이블을 가져왔기 때문에 바꿀 수가 없습니다. 
Frontend에 영향을 주지 않도록 DTO에서 변환을 시켜줘야 합니다. 

## Get DTO

유저에 대한 정보를 요구할 때 DB와 Service를 mapping하기 위한 DTO입니다. [`class-transformer` 의 `@Expose`](https://docs.nestjs.com/techniques/serialization#expose-properties)로 나타내고 싶은 필드를 정의하고, 제외하고 싶은 필드는 `@Exclude`를 사용합니다

```javascript
import { Exclude, Expose } from 'class-transformer';

export class CustomerDto {
	@Expose({ name: 'user_id' })
	id: string;
  
	@Expose()
	email: string;
  
	@Expose({ name: 'phone_number' })
	phoneNumber: string;
  
	@Expose({ name: 'marketing_information_agree_date' })
	marketingInformationAgreeDate: string;
  
	@Expose({ name: 'create_time' })
	createTime: Date;
  
	@Exclude()
	update_time: Date;
  
	@Exclude()
	personal_data_retention_period?: number;

	@Exclude()
	archive_time?: number;
}
```

여기서 `@Expose({name: '필드 이름' })`을 지정하게 되면 **name에 일치하는 값으로 매핑**이 되어 프로젝트의 컨벤션을 훼손하지 않는 선에서 DB와 연결하여 외부의 컨벤션을 대응할 수 있습니다.

```javascript
async findCustomerByUserId(userId: string): Promise<CustomerDto> {
	const customer = await this.customerModel.get(userId);
	if (!customer) {
		throw new NotFoundException('고객 아이디를 찾지 못했습니다');
	}
  
	return plainToClass(CustomerDto, customer);
}
```

Service에서는 이렇게 mapping에 사용할 수 있습니다.

```javascript
@Get('customers/:userId')
async getCustomer(
	@Param('userId', new ParseIDPipe())
	userId: string,
): Promise<GetCustomerResponseDto> {
	const customerDto: CustomerDto =
		await this.customerService.findCustomerByUserId(userId);
	const customerMetaDto: CustomerMetaDto =
		await this.customerService.findCustomerMetaByUserId(userId);
	return { ...customerDto, ...customerMetaDto };
}
```

Controller에서는 `customers/:userId`로 GET 요청을 보내면 유저 정보를 보냅니다.

## Update DTO

Update에서는 외부에서 들어오는 데이터를 받아서 DB에 저장해야하기 때문에 유효성 검증과정을 추가합니다.
NestJS에서는 [`class-validator`]( https://docs.nestjs.com/techniques/validation)라는 유효성 검증 패키지를 지원합니다. 

```js
import { IsEmail, IsPhoneNumber, IsOptional, IsString } from 'class-validator';

export class UpdateCustomerRequestDto {

	@IsEmail()
	@IsOptional()
	email: string;
  
	@IsPhoneNumber()
	@IsOptional()
	phoneNumber: string;
  
	@IsString()
	@IsOptional()
	subscriptionPath: string;
	  
	@IsString()
	@IsOptional()
	businessAddress: string;
	
	@IsString()
	@IsOptional()
	businessName: string;
  
	@IsString()
	@IsOptional()
	businessItem: string;
  
	@IsString()
	@IsOptional()
	accountStatus: string;
  
	@IsString()
	@IsOptional()
	businessType: string;
}
```

`UpdateCustomerRequestDto`에서는 외부에서 들어오는 데이터를 `class-validator`로 검증하도록 설정했습니다. 내부의 필드들은 수정가능한 필드들만 설정했습니다. 다른 필드와 값들이 들어온다면 400 Error(`BadRequestException`)를 발생시킵니다

```js
export class UpdateCustomerDto {
	@IsEmail()
	@IsOptional()
	@Expose()
	email: string;
  
	@Expose()
	@Transform(
		({ obj }) => {
		return obj.phoneNumber;
		},
		{ toClassOnly: true },
	)
	phone_number: string;
}
```

GetDTO에서 했던 것 처럼 mapping을 해줄 Dto도 만들었습니다. 해당 `UpdateCustomerDto`는 `Customer` 모델로 들어갈 필드들을 정의합니다. 여기서 [`@Transform`](https://docs.nestjs.com/techniques/serialization#transform)을 사용해서 camelCase인 phoneNumber를 snake_case로 변환했기 때문에 Customer 모델로 넣어 줄 수 있습니다.

```js
async updateCustomerWithMeta(
	userId: string,
	request: UpdateCustomerRequestDto,
): Promise<void> {

	function isEmptyObject(object: object): boolean {
		return !object || Object.keys(object).length === 0;
	}
  
	const customerData = plainToClass(UpdateCustomerDto, request, {
		excludeExtraneousValues: true,
		exposeUnsetFields: false,
	});

	const customerMetaData = plainToClass(UpdateCustomerMetaDto, request, {
		excludeExtraneousValues: true,
		exposeUnsetFields: false,
	});

	if (isEmptyObject(customerData) && isEmptyObject(customerMetaData)) {
		throw new BadRequestException(
			'customer 또는 customerMeta 속성이 누락되었습니다',
		);
	}
  
	if (!isEmptyObject(customerData)) {
		this.customerModel.update(userId, customerData);
	}
  
	if (!isEmptyObject(customerMetaData)) {
		this.customerMetaModel.update(userId, customerMetaData);
	}
}
```

Service에서는 외부에서 들어온 request 필드들을 모델에 맞게 나눠주고 전부 비어있으면 업데이트를 건너 뛰는 과정을 거칩니다.
[`planToClass`](https://github.com/typestack/class-transformer#enforcing-type-safe-instance)의 excludeExtraneousValues 옵션은 true일때 관련없는 필드는 제외하는 옵션이고, exposeUnsetFields 옵션은 false일 때 undefined인 필드는 제외하는 옵션입니다.

```js
@Patch('customers/:userId')
async updateCustomer(
	@Param('userId', new ParseIDPipe())
	userId: string,
	@Body()
	request: UpdateCustomerRequestDto,
): Promise<CustomerIdResponse> {
	await this.customerService.updateCustomerWithMeta(userId, request);
	return new CustomerIdResponse(userId);
}
```

Controller에서는 Patch 요청이 들어오면 `updateCustomerWithMeta` 메서드를 호출합니다.

## 정리

계층 간 데이터를 전달하는데에 유용한 DTO에 대해 알아봤습니다. 이번 프로젝트에서는 mapper, 검증, 변환에 주로 사용 되었는데, 프로젝트의 컨벤션을 훼손하지 않는 선에서 DB와 연결하여 외부의 컨벤션을 대응하는 방법 중에 하나도 알게 되었고 DTO를 사용해야하는 범위에 대해 알게된 프로젝트였습니다.

java에 대해 전혀 몰랐지만 nestJS가 MVC패턴을 가지게 되면서 java의 MVC패턴과 더불어 DTO에 대한 개념도 배울 수 있었습니다. 이 후 java도 공부하는데도 도움이 될거 같습니다.

아래의 링크들은 DTO에 대해 이해하는데 도움을 많이 받은 링크들을 추가했습니다.

## 참고 링크

- https://tecoble.techcourse.co.kr/post/2021-04-25-dto-layer-scope/
- https://hudi.blog/data-transfer-object/
- https://www.baeldung.com/java-dto-pattern
- https://jojoldu.tistory.com/685
- https://jojoldu.tistory.com/617