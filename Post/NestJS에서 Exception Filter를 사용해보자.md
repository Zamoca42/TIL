NestJS로 회원 정보 관리자 페이지를 제작하다가 알게된 전역으로 예외처리 할 수 있는 방법인 Exception Filter에 대해 알아보려고 합니다.

처음 Exception Filter를 사용하게 된 계기는 회원 정보를 담당하는 Service에서 메서드마다 try/catch문을 작성하고 있었는데, 여기서 try/catch는 단순히 예외처리(catch)를 위해 사용 중이였습니다.

이걸 본 코드리뷰를 해주시는 개발자님께서 Exception Filter를 사용해보라고 조언해주셔서 Exception Filter에 대해 알게 되었습니다.

공식문서에 [Exception Filter](https://docs.nestjs.com/exception-filters)에 대해 친절하게 설명되어 있습니다. 

아래는 공식문서에 나와있는 간단한 설명입니다.

Nest에는 애플리케이션에서 처리되지 않은 모든 예외를 처리하는 내장 **예외 레이어**가 제공됩니다. 응용 프로그램 코드에서 예외를 처리하지 않으면이 계층에서 예외를 포착하여 적절한 사용자 친화적인 응답을 자동으로 보냅니다.

![Filter001](https://github.com/Zamoca42/vue-django-blog/assets/96982072/0bdae43f-bec1-47de-84e0-9806e6f4378d)

기본적으로 이 동작은 내장 된 **전역 예외 필터**에 의해 수행되는데, 이 예외는 `HttpException` 유형 (및 그 하위 클래스)의 예외를 처리합니다. 예외가 **unrecognized** 인 경우 ( `HttpException` 또는 `HttpException`에서 상속되는 클래스가 아님) 클라이언트는 다음과 같은 기본 JSON 응답을받습니다.

```Json
{
	"statusCode": 500,
	"message": "Internal server error"
}
```

여기까지 공식문서에 나와있는 내용이고, 저는 직접 커스텀해서 사용하고 적용해볼 예정입니다.

1. Exception Filter 커스텀
2. main.ts 설정
3. try/catch 수정

이런 순서로 진행해보겠습니다.

## Exception Filter

```javascript
import {
	ExceptionFilter,
	Catch,
	ArgumentsHost,
	HttpException,
	HttpStatus,
	Logger,
	BadRequestException,
} from '@nestjs/common';
import { Request, Response } from 'express';
  
@Catch(HttpException)
export class HttpExceptionFilter implements ExceptionFilter {
	private readonly logger = new Logger(HttpExceptionFilter.name);
	catch(exception: HttpException, host: ArgumentsHost): void {
		const ctx = host.switchToHttp();
		const response = ctx.getResponse<Response>();
		const request = ctx.getRequest<Request>();
		const status =
			exception instanceof HttpException
				? exception.getStatus()
				: HttpStatus.INTERNAL_SERVER_ERROR;

		this.logger.error(
			`Request URL: ${request.url} | Status: ${status} | Message: ${
				exception.message || 'Internal server error'
			}`,
		);

		if (exception instanceof BadRequestException) {
			response.status(exception.getStatus()).json(exception);
			return;
		}
		
		response.status(status).json({
			statusCode: status,
			message: exception.message || 'Internal server error',
			path: request.url,
			timestamp: new Date().toISOString(),
		});
	}
}
```

`@Catch(HttpException)` 데코레이터는 NestJS에서 제공하는 데코레이터로, 이를 사용하여 특정 예외를 잡아내는 예외 필터를 생성할 수 있습니다.

여기서 `HttpException`은 NestJS에서 제공하는 예외 클래스로, HTTP 요청 처리 중에 발생할 수 있는 일반적인 예외를 나타냅니다.

`@Catch(HttpException)` 데코레이터를 사용하면, 이 필터는 `HttpException` 또는 그 하위 클래스가 발생할 때마다 호출됩니다.

`HttpExceptionFilter` 클래스에서는 이 예외가 발생하면 로그를 기록하고, 적절한 HTTP 상태 코드와 메시지를 포함하는 응답을 클라이언트에게 전송합니다.

나머지는 공식문서에 나와있는 Exception Filter와 유사하지만, 다른 점은 Logger 입니다.

```javascript
this.logger.error(
	`Request URL: ${request.url} | Status: ${status} | Message: ${
		exception.message || 'Internal server error'
	}`,
);
```

해당 부분을 추가해서 Logger를 통해 오류 메시지를 로그에 기록하는 역할을 합니다. 

콘솔에서도 서버로그를 볼 수 있어 예외 발생 시 요청 정보와 예외 메시지를 쉽게 확인할 수 있어 디버깅에 도움이 됩니다.

## Binding Filter

만약 특정 Module에서만 ExceptionFilter를 사용하려고하면 

```javascript
@UseFilters(new HttpExceptionFilter())
export class CatsController {}
```

이렇게 사용할 수 있습니다

전역적으로 사용하려면 main.ts에서 `userGlobalFilters` 사용하면 됩니다.

```javascript
import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { ValidationPipe } from '@nestjs/common';
import { HttpExceptionFilter } from './common/filter/http-exception.filter';

async function bootstrap(): Promise<void> {
	const app = await NestFactory.create(AppModule);
	const allowedOrigins = process.env.ALLOWED_ORIGINS.split(',');
  
	app.useGlobalPipes(
		new ValidationPipe({
			whitelist: true,
			transform: true,
			forbidNonWhitelisted: true,
		}),
	);
  
	app.useGlobalFilters(new HttpExceptionFilter());
  
	app.enableCors({
		origin: allowedOrigins,
		methods: 'GET,HEAD,PUT,PATCH,POST,DELETE',
		allowedHeaders: 'Content-Type, Accept, Authorization',
	});
	await app.listen(3000);
}
bootstrap();
```

이제 어떤 라우트에서든 `HttpException`이 발생하면 `HttpExceptionFilter`에 의해 처리됩니다.

## try/catch 수정

HttpExceptionFilter를 사용한 후에는 Service 로직에서 메서드를 try/catch문을 수정할 수 있습니다

```javascript
async findCustomerByUserId(userId: string): Promise<CustomerDto> { 
	try { 
		const customer = await this.customerModel.get(userId); 
		
		if (!customer) { 
			throw new NotFoundException('고객 아이디를 찾지 못했습니다'); 
		} 
		
		return plainToClass(CustomerDto, customer); 
	} catch (error) {
		if (error instanceof NotFoundException) {
			throw error;
		}
	} 
}
```

이렇게 try/catch로 작성된 메서드가 있으면 `HttpExceptionFilter`를 사용한 후에는

```javascript
async findCustomerByUserId(userId: string): Promise<CustomerDto> {
	const customer = await this.customerModel.get(userId);
	if (!customer) {
		throw new NotFoundException('고객 아이디를 찾지 못했습니다');
	}
  
	return plainToClass(CustomerDto, customer);
}
```

이렇게 변경하여 모든 메서드에서 간결하게 사용할 수 있습니다. 
`NotFoundException`은 @nestjs/common 패키지에서 찾을 수 있는 일반적인 HTTP 예외 중 하나입니다.
@nestjs/common에서 다양한 HTTP예외를 제공합니다. [Built-in HTTP exceptions](https://docs.nestjs.com/exception-filters#built-in-http-exceptions)

## 결론

Exception Filter를 사용하면 다음과 같은 이점을 가질 수 있습니다.

1. 각 메서드에서 예외를 처리하기 위해 반복적으로 try/catch를 사용하는 대신, 전역 예외 필터를 사용하면 중복성을 피하고 코드를 더 간결하고 읽기 쉽게 만들 수 있습니다. 

2. 모든 예외가 하나의 필터를 통과하므로 응답 형식을 일관되게 유지할 수 있습니다.

3. 예외 필터에서 로깅을 수행하면 모든 예외에 대한 로그를 한 곳에서 관리할 수 있으므로, 문제를 추적하고 디버깅하는데 더 효과적일 수 있습니다.

긴 글 읽어주셔서 감사합니다.
