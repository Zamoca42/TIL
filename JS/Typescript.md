# 기본 타입 정리(primitive types)

타입스크립트는 변수만들 때 변수의 타입을 지정가능합니다.

```ts
let 이름: string = "kim";
```

변수명:타입 이렇게 정하면 됩니다.  
방금 여러분은 변수에 실드를 씌운 것입니다.  
이제 이름이라는 변수는 string 타입이 되며  
갑자기 숫자 이런걸 할당하려고 하면 실드로 튕겨냅니다 (에러가 나게 됩니다)  
진짜 시험삼아 숫자 할당해보십시오. 타입 실드가 바로 튕겨내줄걸요

(참고) name이라는 변수명은 전역변수로 사용불가능합니다

자주 쓰는 primitive types 들을 소개하자면  
string, number, boolean 이런게 있습니다.

```ts
let 이름: string = "kim";
let 나이: number = 20;
let 결혼했니: boolean = false;
```

(대문자 String 아닙니다 소문자 string임)

추가로 null, undefined 이런 것도 있습니다.  
근데 굳이 사용하진 않습니다.

여러 자료를 한 곳에 저장하고 싶을 때 array 또는 object 자료형을 사용합니다.  
근데 그 안에 들어갈 자료들도 전부 타입지정이 가능합니다.

```ts
let 회원들: string[] = ["kim", "park"];
```

array 자료안에 들어갈 타입은 타입명[] 이렇게 지정하면 됩니다.  
그럼 array 자료에 각각 string이라는 타입 실드를 장착한 겁니다.  
이제 숫자로 수정하려면 실드가 튕겨냅니다

```js
let 내정보: { age: number } = { age: 20 };
```

object 자료안에 들어갈 타입은 내가 만들 object와 똑같은 모습으로 지정하면 됩니다.  
뭔가 이상해보이지만 변수명 오른쪽에 오는 것들은 전부 타입지정 문법입니다.  
아무튼 이러면 age 속성에 number 실드를 씌워준 것입니다.

```js
let 이름: string = "kim";
이름 = 30;
```

타입을 잘 지정해준다면 타입이 실수로 변경될 때 이런 경고성 에러가 납니다.

```
Type 'number' is not assignable to type 'string'.(2322)
```

엄격하게 타입을 지켜서 코드짜는걸 도와주는 에러니 앞으로 반겨주면 됩니다.  
(물론 이 에러는 ts에서만 나는 에러고 실제 변환된 .js 파일 가보시면 별일 없습니다)

## Pro tips

그렇다고 모든 변수에 타입지정하러 다니면 초보티가 납니다.  
숙련자들은 타입을 귀찮게 굳이 적지 않습니다.  
왜냐면 변수 생성시 타입스크립트가 타입을 자동으로 부여해주니까요.

```ts
let 이름 = "kim";
let 나이 = 20;
```

이렇게만 써도 자동으로 이름변수는 string, 나이 변수는 number를 가지고 있습니다.
(변수명에 마우스 올려보면 바로바로 확인가능)
array, object 만들 때도 자동으로 알아서 됩니다. 굳이 복잡하게 타입 명시할 필요 없음

```ts
let 이름;
이름 = "kim";
```

심지어 변수만 만들고  
나중에 가서 여기에 'kim'을 할당해도 타입이 자동으로 string으로 변합니다.  
그래서 간단한 변수들은 타입을 생략하도록 합시다.타입지정하는게 보기좋으시다면 그렇게 하도록 합시다.

# 타입 미리 정하기 애매할때 (union type, any, unknown)

이 변수에 들어올게 string일지 number일지 아직 애매하다면  
방법이 몇가지 있습니다.

## union type

"이 변수엔 string 또는 number가 들어올 수 있습니다~" 라고 타입정의를 하고싶으면 `|` 연산자를 씁시다.  
OR 연산자 같은 느낌인데 이런 타입을 전문용어로 Union type 이라고 부릅니다.

```ts
let 이름: string | number = "kim";
let 나이: string | number = 100;
```

심심하면 괄호쳐도 됩니다.  
이러면 name, age 변수엔 string 또는 number만 들어올 수 있습니다.  
그리고 할당하는 순간 타입은 string 또는 number 중 하나로 변합니다.

그럼 array, object 자료 만들 때 union type (OR 연산자) 쓰려면 어떻게 할까요

```js
var 어레이: number[] = [1, "2", 3];
var 오브젝트: { data: number } = { data: "123" };
```

위 코드에 정의된 어레이와 오브젝트는 지금 타입 때문에 에러가 납니다.  
array와 object 자료에 number 또는 string이 들어올 수 있게 타입을 좀 고쳐보면

```js
var 어레이: (number | string)[] = [1, "2", 3];
var 오브젝트: { data: number | string } = { data: "123" };
```

특징은 변수에 정의된 Union 타입은 할당과 동시에 OR 역할이 사라집니다.  
array, object에 정의된 Union 타입은 OR 연산자가 유지됩니다.

## any type

아무 자료나 집어넣을 수 있는 타입입니다.  
쉽게 비유하면 실드해제입니다.

```js
let 이름: any = "kim";
이름 = 123;
이름 = undefined;
이름 = [];
```

any 타입은 실드 해제 문법이기 때문에 갑자기 타입을 마구 바꿔도 에러가 나지 않습니다.  
any 타입은 좋다고 막쓰면 안되는데  
그럼 타입관련 버그가 생길 경우 왜 그런지 추적하기가 어려우니까요.  
타입 실드를 안씌우면 타입스크립트를 쓸 이유가 없습니다.  
그래서 비상시 쓰는 변수 타입체크 해제기능 이런 용도로 씁시다.

## unknown type

요즘 타입스크립트는 unknown 타입을 사용합니다.  
any와 똑같이 모든 타입을 집어넣을 수 있습니다.

```js
let 이름: unknown = "kim";
이름 = 123;
이름 = undefined;
이름 = [];
```

이래도 에러가 나지 않습니다.  
아직 어떤 타입이 들어올지 모를 경우, 다양한 타입을 집어넣어야할 경우 이걸 사용해보시길 바랍니다.

중요한 특징은

1. unknown 타입엔 모든 자료 다 집어넣을 수 있음

2. 자료집어넣어도 타입은 그대로 unknown입니다.

```js
let 이름: unknown;

let 변수1: string = 이름;
let 변수2: boolean = 이름;
let 변수3: number = 이름;
```

당연히 unknown 타입을 다른 곳에 집어넣으려고 하면  
그쪽 실드가 발동해서 에러가 납니다.  
(any는 안그럼)

```js
let 이름: unknown;
이름[0];
이름 - 1;
이름.data;
```

이래도 에러가 납니다. (any는 안그럼)

왜냐면 타입스크립트는 정확하고 확실한걸 좋아합니다.  
확실하지않은 타입에 뺄셈해주고 그런거 싫어합니다.  
숫자가 아닌걸 뺄셈할 수는 없으니까요.  
타입스크립트에선 뺄셈은 number 류의 타입만 할 수 있고  
.name 이런건 object 류의 타입만 할 수 있다라고 미리 정의되어있습니다.

그래서 결론은 아직 뭘 집어넣을지 모르겠는데 약간의 안정성을 도모하고 싶으면 unknown 타입을 써봅시다.  
근데 실은 코드짜다가 any, unknown 부여할 경우는 별로 없습니다.

(참고) unknown 타입인 변수를 조작하려면  
내가 조작할 변수의 타입이 무엇인지 확실하게 체크하는 narrowing 또는 assertion 스킬을 사용해야합니다.  
그것이 타입스크립트의 근간이 되는 코딩방법이고  
변수에 뭐가 들어있을지 애매한, 추측해야하는 상황이 나오는 시점에선 반드시 사용해야합니다.

# 함수에 타입 지정 & void 타입

함수라는 문법은 원래 용도가 긴 코드 짧게 축약하려고 만든 것도 있는데  
실은 어떤 자료를 입력하면 다른 자료를 뿅 뱉는 기계 역할도 합니다.  
2를 넣으면 4가 되고  
4를 넣으면 8이 되는  
그런 기계를 만들고 싶으면 함수를 가져다가 씁니다.

실제로 코드로 만들어보면

```js
function 내함수(x) {
  return x * 2;
}
내함수(2); //이러면 4가 이 자리에 남음
내함수(4); //이러면 8이 이 자리에 남음
```

이렇게 되겠군요. 멋진 곱셈기계가 완성되었습니다.  
소괄호 안에 들어가는 x같은 자료들을 파라미터라고 부르고  
return 오른쪽에 있는 자료들을 리턴값 이런식으로 부릅니다.

1. 파라미터를 작명해주면 함수를 사용할 때 ( ) 소괄호 안에 아무 자료나 집어넣을 수 있게되고

2. 리턴값은 함수가 사용되고나서 그 자리에 남는 값입니다.

내함수(2) 이렇게 쓰고나면 진짜 그 자리에 return 우측에 있던 값이 남습니다.

그래서 함수는 총 두 군데 타입지정이 가능합니다.

1. 함수로 들어오는 자료 (파라미터)

2. 함수에서 나가는 자료 (return)

```js
function 내함수(x: number): number {
  return x * 2;
}
```

1. 함수로 들어오는 파라미터 타입지정은 파라미터 옆에 적으면 됩니다.

2. 함수가 실행된 후 남는 값 (return 우측에 있는 값) 타입지정하고 싶으면 함수명() 우측에 적으면 됩니다.

함수에 멋있게 타입 실드를 장착했기 때문에  
이제 파라미터와 리턴값이 이상해지면 자동으로 혼내줍니다.

- 파라미터에 타입을 지정하면 필수 파라미터가 됩니다.

함수는 특이하게도 void라는 타입을 사용가능합니다.  
'아무것도 없이 공허함'을 뜻하는 타입인데  
return할 자료가 없는 함수의 타입으로 사용가능합니다.

```js
function 내함수(x: number): void {
  return x * 2; //여기서 에러남
}
```

그럼 이제 이 함수에서 뭔가를 return하려고할 때 에러를 냅니다.  
함수에 return 방지장치를 주고 싶을 때 void 타입을 활용하시면 되겠습니다.

함수에 파라미터자리를 만들어놨지만 가끔 파라미터 없이 쓸 때도 있습니다.  
그럴 경우 타입스크립트에선 미리 "이 파라미터는 옵션임" 이렇게 정의를 해주셔야 에러가 나지 않습니다.

```js
function 내함수(x?: number) {}
내함수(); //가능
내함수(2); //가능
```

파라미터 우측에 그냥 물음표치면 됩니다. 그럼 앞으로 내함수()를 사용할 때 파라미터없이도 쓸 수 있습니다.  
근데 물음표는 실은 **x : number | undefined** 이거랑 똑같은 의미입니다 (중요)  
파라미터가 정의가 안되면 자동으로 undefined가 되니까 그걸 반영한거라고 볼 수도 있겠습니다.

함수도 예외없이 Union type을 사용하면  
엄격근엄진지한 타입스크립트가 딴지를 걸 수 있습니다.

Q. 예를 들어서 함수에 숫자 또는 문자를 집어넣으면 + 1 해주는 함수를 만들어봅시다.

```js
function 자릿수세기(x: number | string) {
  return x + 1;
}
```

그냥 쌩 자바스크립트에서는 문자나 숫자나 모두 +1 이 가능하지만  
타입스크립트에선 변수의 타입이 number | string 이런 union type인 경우 자료 조작을 금지시킵니다.  
아직 이 파라미터의 타입이 확실하지 않으니까 파라미터 조작을 일단 실드로 막고 금지하는 것입니다.

```js
function 내함수(x?: number): number {
  return x * 2;
}
```

x라는 파라미터는 옵션이고, 옵션인 파라미터는 number | undefined 이런 식으로 타입정의가 되는데  
아직 x라는 파라미터가 뭔지 확실하지 않기 때문에 에러를 내줍니다.

그래서 엄격한 타입스크립트 성격에 맞춰주려면 여러분이 코드를 애초에 엄격하게 짜야합니다.

# 타입 확정하기 Narrowing & Assertion

저번 시간에 만든 함수에 숫자 또는 문자를 집어넣으면 + 1 해주는 함수입니다.

```js
function 내함수(x: number | string) {
  return x + 1; //에러남
}
```

근데 이런 에러가 납니다.

```
Operator '+' cannot be applied to types 'string | number' and 'number'
```

string | number 같은 union type 에는 일반적으로 조작을 못하게 막아놔서 그렇습니다.  
이런 메세지를 보면

1. 타입을 하나로 Narrowing 해주거나

2. Assert 해주거나 둘 중 하나 해주면 됩니다.

## Type Narrowing

if문 등으로 타입을 하나로 정해주는 것을 뜻합니다.  
그래서 아까 함수를 사용할 때

```js
function 내함수(x: number | string) {
  if (typeof x === "number") {
    return x + 1;
  } else if (typeof x === "string") {
    return x + 1;
  } else {
    return 0;
  }
}
```

if문과 typeof 키워드로 현재 파라미터의 타입을 검사해서  
"이게 'number' 타입일 경우 이렇게 해주세요~"  
"이게 'string' 타입일 경우 이렇게 해주세요~"  
이렇게 코드를 짜야 정상적으로 사용이 가능합니다.

타입스크립트는 타입 애매한걸 싫어해서 귀찮아도 하셔야함  
타입이 확실하지 않을 때 생기는 부작용을 막기위한 장치라고 보시면 되겠습니다.  
가끔 이걸 "defensive 하게 코딩한다"라고 하기도 합니다.

근데 또 함수 안에서 if문 쓸 때는 마지막에 else {} 이거 없으면 에러가 납니다.  
return 하지않는 조건문이 있다면 나중에 버그가 생길 수 있어서 에러를 내주는 것인데  
"noImplicitReturns": false,
이게 성가시다면 tsconfig.js 파일에서 이걸 추가하면 됩니다. 근데 굳이 수정하는 것 보다는 엄격하게 씁시다.

- 꼭 typeof를 쓸 필요는 없고 타입을 하나로 확정지을 수 있는 코드라면 어떤 것도 Narrowing 역할을 할 수 있습니다.
- in, instanceof 키워드도 사용가능합니다.

## Type Assertion

아니면 타입을 간편하게 assert 할 수도 있습니다.  
"이 변수의 타입을 number로 생각해주세요"  
이런 뜻으로 코드를 짜면 타입스크립트 컴파일러가 눈감아줍니다.  
변수명 as string  
이런 식으로 as라는 키워드 쓰면 됩니다.

```js
function 내함수(x :number | string){
    return (x as number) + 1
}
console.log( 내함수(123) )
```

변수명 as number 라고 쓰시면  
"나는 이 변수를 number라고 주장하겠습니다~" 라는 뜻이며 실제로 그렇게 타입을 변경해줍니다.  
아무튼 이렇게 타입스크립트 컴파일러에게 반기를 들 수 있습니다.  
근데 이러려면 내가 "함수에 무조건 숫자가 들어올 것이다"라는 사실을 알고 있어야 안전하게 쓸 수 있는 문법이겠죠?

as 키워드 사용시 특징이 있는데

1. as 키워드는 union type 같은 복잡한 타입을 하나의 정확한 타입으로 줄이는 역할을 수행합니다.  
   (number 타입을 as string 이렇게 바꾸려고 하면 에러날걸요)

2. 실은 그냥 타입실드 임시 해제용입니다. 실제 코드 실행결과는 as 있을 때나 없을 때나 거의 동일합니다.

그러면 이제 변수를 숫자로 가정해서 가공할 수 있습니다.

Q. 근데 내함수('123') 이렇게 숫자말고 문자를 입력하면 어떻게 됩니까

A. as number라고 썼긴 했지만 number 타입처럼 +1 해주진 않습니다. 콘솔창에 결과 출력해보면 '1231' 이렇게 출력됩니다.

as는 그냥 주장만 하는거지 실제로 타입을 바꿔주는건 아니기 때문입니다.  
as 쓰면 간편해쥬금 하지만 정확히 코드짜려면 narrowing을 씁시다.  
as 키워드는 맘대로 타입을 개발자 맘대로 주장하는 역할이라 때문에 엄격한 타입체크기능을 잠깐 안쓰겠다는 뜻과 동일합니다.  
그래서 as 문법은 이럴 때 쓰도록 합시다.

1. 왜 타입에러가 나는지 정말 모르겠는 상황에 임시로 에러해결용으로 사용하거나

2. 내가 어떤 타입이 들어올지 정말 확실하게 알고 있는데 컴파일러 에러가 방해할 때

물론 대부분의 상황에선 as 보다 훨씬 엄격하고 좋은 type narrowing으로 해결할 수 있습니다.

# 타입도 변수에 담아쓰기 & readonly

코드 열심히 짜다보면

```js
let 동물: string | number | undefined;
```

매우 길고 복잡하게 타입을 나열하는 경우가 많습니다.

1. 이게 길고 보기싫으면

2. 나중에 또 사용하고 싶으면

변수에 담아쓰십시오.  
변수만드는 것 처럼 type 이라는 키워드를 쓰면 됩니다.  
type 키워드 쓰는걸 type alias 라고 합니다.  
alias를 번역하자면 별칭인데 저는 그냥 쉽게 변수라고 부르겠습니다.

```js
type Animal = string | number | undefined;
let 동물: Animal;
```

type 타입변수명 = 타입종류  
타입을 변수처럼 만들어서 쓰는 alias 문법입니다. 관습적으로 대문자로 시작합니다.  
일반 자바스크립트 변수랑 차별을 두기 위해 AnimalType 이런 식으로 작명하는게 어떨까요.

object 타입도 저장가능합니다

```js
type 사람 = {
  name: string,
  age: number,
};

let teacher: 사람 = { name: "john", age: 20 };
```

object에 타입지정할 때 자주 활용할 수 있겠군요  
type 키워드 안쓰면 이렇게 만들어야함

```js
let teacher: {
  name: string,
  age: number,
} = { name: "john", age: 20 };
```

미래의 내가 봤을 때 이해가 어려울 것 같으면 좋은 코드가 아닙니다

## readonly로 잠그기

```js
const 출생지역 = "seoul";
출생지역 = "busan"; //const 변수는 여기서 에러남
```

const 변수라고 아십니까.  
const 변수는 값이 변하지 않는 변수를 만들고 싶을 때 const 쓰면 됩니다.  
재할당시 에러가 나기 때문에 값이 변하는걸 미리 감지하고 차단할 수 있으니까요.

```js
const 여친 = {
  name: "엠버",
};
여친.name = "유라"; //const 변수지만 에러안남
```

하지만 object 자료를 const에 집어넣어도 object 내부는 마음대로 변경가능합니다.  
const 변수는 재할당만 막아줄 뿐이지 그 안에 있는 object 속성 바꾸는 것 까지 관여하지 않기 때문입니다.  
object 속성을 바뀌지 않게 막고 싶으면 타입스크립트 문법을 쓰십시오.

readonly 키워드는 속성 왼쪽에 붙일 수 있으며  
특정 속성을 변경불가능하게 잠궈줍니다.

```js
type Girlfriend = {
  readonly name : string,
}

let 여친 :Girlfriend = {
  name : '엠버'
}

여친.name = '유라' //readonly라서 에러남
```

한번 부여된 후엔 앞으로 바뀌면 안될 속성들을 readonly로 잠궈봅시다.  
(물론 readonly는 컴파일시 에러를 내는 것일 뿐 변환된 js 파일 보시면 잘 바뀌긴 합니다)

만약 어떤 object자료는 color, width 속성이 둘다 필요하지만  
어떤 object 자료는 color 속성이 선택사항이라면  
type alias를 여러개 만들어야하는게 아니라 물음표연산자만 추가하면 됩니다.

```js
type Square = {
  color?: string,
  width: number,
};

let 네모2: Square = {
  width: 100,
};
```

Square라는 type alias를 적용한 object 자료를 하나 만들었습니다.  
근데 color 속성이 없어도 에러가 나지 않습니다.  
함수시간에 배웠죠? 넘어가도록 합시다.

실은 물음표는 "undefined 라는 타입도 가질 수 있다~"라는 뜻임을 잘 기억해둡시다.  
진짠지 확인하고싶으면 마우스 올려보면 됩니다.

## type 키워드는 여러개를 합칠 수 있습니다

```js
type Name = string;
type Age = number;
type NewOne = Name | Age;
```

OR 연산자를 이용해서 Union type을 만들 수도 있습니다.  
위 코드에서 NewOne 타입에 마우스 올려보시면 string | number라고 나올겁니다.

```js
type PositionX = { x: number };
type PositionY = { y: number };
type XandY = PositionX & PositionY;
let 좌표: XandY = { x: 1, y: 2 };
```

object에 지정한 타입의 경우 합치기도 가능합니다.  
`&` 기호를 쓴다면 object 안의 두개의 속성을 합쳐줍니다.  
위 코드에서 XandY 타입은 { x : number, y : number } 이렇게 정의되어있을 겁니다.  
합치기는 초딩용어고 멋진 개발자말로 extend 한다라고 합니다.

물론 Type alias & Type alias 만 가능한게 아니라  
Type alias & { name : string } 이런 것도 가능합니다.

## type 키워드는 재정의가 불가능합니다.

```js
type Name = string;
type Name = number;
```

이러면 에러가 날 겁니다.  
나중에 type 키워드랑 매우 유사한 interface 키워드를 배우게 될텐데  
이 키워드를 쓰면 재정의가 가능합니다. 재정의하면 & 하는거랑 똑같은 기능을 하는데  
하지만 재정의 불가능한 편이 더 안전하지 않을까요.

# Literal Types로 만드는 const 변수 유사품

어떤 변수는 1이라는 값만 가질 수 있게 제한하고 싶으면 어쩌죠.  
자바스크립트 const 변수 쓰면 되겠군요. 근데 1 또는 0만 가질 수 있게 제한하고 싶으면 어쩌죠.  
그 변수에 number 이런 식으로 타입을 지정하면 너무 광범위하지않습니까.  
그럴 땐 Literal type을 선언하도록 합시다.  
어떤 변수가 미리 골라놓은 데이터만 가질 수 있게 도와줍니다.

## Literal Type 만드는 법

tring, number 이런 것만 타입이 될 수 있는게 아닙니다.  
일반 글자같은 것도 타입이 될 수 있습니다.

```js
let john: "대머리";
let kim: "솔로";
```

제가 방금 '대머리', '솔로'라는 타입을 만들었습니다.  
마음대로 변수나 함수에 할당 가능합니다.

그럼 신기하게도  
john이라는 변수는 이제 '대머리' 라는 글자만 할당할 수 있습니다.  
kim이라는 변수는 이제 '솔로' 라는 글자만 할당할 수 있습니다.  
특정 글자나 숫자만 가질 수 있게 제한을 두는 타입을 literal type 이라고 부릅니다.  
더욱 엄격한 실드라고 보면 되겠군요.

```js
let 방향: "left" | "right";
방향 = "left";
```

or 기호 써도 됩니다. 이제 'left' 또는 'right' 글자만 가질 수 있는 변수가 완성되었군요.

```js
function 함수(a: "hello"): 1 | 0 | -1 {
  return 1;
}
```

함수도 똑같습니다.  
파라미터 타입선언할 때 글자나 숫자를 집어넣으시면 그 만 파라미터로 넣을 수 있고  
return 타입선언할 때도 글자나 숫자를 집어넣으시면 그 값만 return할 수 있습니다.

어떻게보면 const 변수의 업그레이드버전이라고 보면 되는데  
const 변수는 값을 바꿀 수 없는 변수입니다.

```js
const 변하면안되는변수 = 123;
```

그래서 중요한, 변하지않는 정보를 저장하고 싶을 때 const를 자주 쓰는데  
가끔은 변하는 중요한 정보를 저장하고 싶을 땐 const가 무쓸모입니다.  
예를 들어 변수가 'kim' 또는 'park' 만 가질 수 있는 이런 식의 엄격한 변수는 못만듭니다.

```js
const 이름 = 'kim' | 'park' (이런 식의 문법은 자바스크립트에 없음)
```

그럴 때 타입스크립트 설치하고 literal type 쓰면 되는 것입니다.

## as const 문법

'kim' 이라는 타입만 들어올 수 있는 함수를 만들었습니다.  
근데 자료.name을 입력하고 싶은겁니다.

```js
var 자료 = {
  name: "kim",
};

function 내함수(a: "kim") {}
내함수(자료.name);
```

그래서 코드를 이렇게 짜봤는데 위 코드는 에러가 납니다.

왜 에러가 나겠습니까.  
함수는 'kim' 타입만 입력할 수 있다고 해놨고  
자료.name 이라는건 string 타입이지 'kim' 타입이 아니기 때문입니다.

이런걸 해결하고 싶으면

1. object 만들 때 타입을 잘 미리 정하든가

2. 예전에 배웠던 assertion을 쓰시든가 (as 'kim' 이런걸 붙이는 겁니다)

3. 아니면 as const 라는걸 애초에 object 자료에 붙일 수 있습니다.

```js
var 자료 = {
  name : 'kim'
} as const;

function 내함수(a : 'kim') {

}
내함수(자료.name)
```

as const는 효과가 2개인데

1. 타입을 object의 value로 바꿔줍니다. (타입을 'kim'으로 바꿔줍니다)

2. object안에 있는 모든 속성을 readonly로 바꿔줍니다 (변경하면 에러나게)

object를 잠그고 싶으면 as const를 활용해보도록 합시다.

# 함수와 methods에 type alias 지정하는 법

함수에 들어갈 파라미터와 return으로 뱉을 값들을 타입지정할 수 있다고 배워봤습니다.  
함수 타입도 type alias로 저장해서 쓸 수 있습니다.  
예를 들어서

1. 숫자 두개를 파라미터로 입력할 수 있고

2. 숫자를 return 하는 함수를 별명을 지어서 사용하려면

type NumOut = (x : number, y : number ) => number ;
이런 식입니다.

이걸 함수 만들 때 사용하려면  
function 함수이름 :NumOut (){}
이런 식은 불가능합니다. function 키워드에는 () 이거 내부랑 오른쪽에만 타입지정이 가능해서요.
그래서 이렇게 합니다.

```js
type NumOut = (x: number, y: number) => number;
let ABC: NumOut = function (x, y) {
  return x + y;
};
```

함수를 만들 때  
let 함수명 = function(){} 이렇게 해도 되니까  
함수명 오른쪽에 함수명 : 타입별명  
이렇게 지정해서 사용하는 것입니다.  
type alias 만들기 싫으면 그냥 함수만들 때 직접 타입작성하면 되겠죠 뭐

## methods안에 타입지정하기

object 자료 안에 함수도 맘대로 집어넣을 수 있습니다.  
몰랐다면 대충 어떻게 생겼는지 알아봅시다.

```js
let 회원정보 = {
  name: "kim",
  age: 30,
  plusOne(x) {
    return x + 1;
  },
  changeName: () => {
    console.log("안녕");
  },
};
회원정보.plusOne(1);
회원정보.changeName();
```

plusOne 그리고 changeName 함수를 object 자료에 집어넣었습니다.  
arrow function, 일반함수 전부 object 안에 맘대로 집어넣을 수 있습니다.  
넣은 함수들은 똑같이 점찍어서 사용가능합니다.

왜 넣냐고요? 그냥 함수도 자료안에 보관해서 쓰고싶을 때가 있기 때문입니다.

위 코드에서 회원정보라는 변수에 타입지정

- plusOne이라는 속성은 함수여야하고, 숫자를 넣어서 숫자를 뱉는 함수여야합니다.

- changeName이라는 속성은 함수여야하고, 아무것도 return하면 안됩니다.

- type 키워드를 쓰든 말든 알아서 합시다.

```js
type Member = {
  name: string,
  age: number,
  plusOne: (x: number) => number,
  changeName: () => void,
};
```

# 타입스크립트로 HTML 변경과 조작할 때 주의점

자바스크립트의 원래 존재 목적은 단연 html 조작과 변경입니다.  
그래서 타입스크립트를 써도 html 조작이 가능한데 근데 그냥 자바스크립트 쓸 때와 약간 다른 점이 존재합니다.  
귀찮다는 점이요  
왜인지는 실제로 html 조작해보며 알아봅시다.
document.getElementById() 이거 쓰는 법을 설명할 것인데  
근데 또 react, vue 이런걸 쓰다보면 html 조작과 변경하는 법은 몰라도 되긴 합니다.  
근데 react, vue 사용할 때도 html 직접조작이 간혹 필요한 경우가 있어서 아예 모르면 안되겠죠

우선 strictNullCheck 옵션을 켜봅시다

많은 환경에서 null이 들어올 경우 체크해주는 옵션을 켜고 코드짭니다.  
변수 조작하기 전에 이게 null인지 아닌지 캐치해낼 수 있으니까요.  
특히 html 조작할 때 셀렉터로 찾으면 null 어쩌구가 많이 발생하는데 그거 잡을 때도 도움됩니다.

```js
{
    "compilerOptions": {
        "target": "ES5",
        "module": "commonjs",
        "strictNullChecks": true
    }
}
```

tsconfig.json 파일을 열어서 strickNullChecks 옵션을 true로 바꾸고 코드짜봅시다.  
혹은 그냥 "strict" : true 이런걸 써두면 strickNullChecks 옵션도 자동으로 true로 켜집니다.

## HTML 파일 준비

```js
(index.html)

<h4 id="title">안녕하세요</h4>
<a href="naver.com">링크</a>
<button id="button">버튼</button>

<script src="변환된 자바스크립트파일.js"></script>
```

당연히 타입스크립트 파일을 html에 집어넣어야 html 조작을 하든말든 하겠죠?  
html 파일만들고 타입스크립트 -> 자바스크립트 변환된 파일을 집어넣도록 합시다.  
그리고 조작을 체험하기 위한 html 몇개 작성했습니다.

## HTML 찾고 변경해보기

`<h4>`제목을 다른 글자로 변경해봅시다.

```js
let 제목 = document.querySelector("#title");
제목.innerHTML = "반갑소";
```

이러면 원래 변경되어야하는데 타입스크립트는 에러를 내줍니다.  
"제목이라는 변수가 null일 수 있습니다"  
아까 켜놨던 strict 옵션 덕분에 이런 에러를 내주는데  
이유는 셀렉터로 html을 찾으면 타입이 Element | null 이기 때문에 그렇습니다.  
(html을 못찾을 경우 null이 됩니다)

그래서 아직 확실하지 않아서 점찍고 조작하고 변경하는걸 금지시켜주는 것입니다.  
이거 어떻게 해결하죠? 제가 앞선 강의에서 잘 기억하라던 TS 동작원리나 그런걸 떠올리면 해결책이 나올듯요  
정답은 제목이라는 변수가 union type이기 때문에 if문으로 type narrowing 하면 됩니다.  
아니면 as 문법으로 assertion 해도 되긴 되겠군요.

### 해결책1. narrowing 하면 됩니다.

```js
let 제목 = document.querySelector("#title");
if (제목 != null) {
  제목.innerHTML = "반갑소";
}
```

멋있게 else문도 추가하면 더 완벽한 코드가 되겠군요.

### 해결책2. 더 좋은 instanceof 사용하는 narrowing 방법도 있습니다.

```js
let 제목 = document.querySelector("#title");
if (제목 instanceof HTMLElement) {
  제목.innerHTML = "반갑소";
}
```

instanceof 라는 연산자를 쓰는 것인데 우측에 HTMLElement 입력하면 그 타입인지 체크해줍니다.  
나중에 배우게 될 것이니 맛만 보도록 합시다.

### 해결책3. assertion 써도 될듯요

```js
let 제목 = document.querySelector('#title') as HTMLElement;
제목.innerHTML = '반갑소'
```

as 키워드를 쓰면 타입을 구라칠 수 있다고 배웠습니다.  
HTMLElement 혹은 그냥 Element 이걸로 구라치면 됩니다.  
물론 좋지 않은 임시 땜빵문법이 맞습니다.

### 해결책4. optional chaining 연산자

```js
let 제목 = document.querySelector("#title");
if (제목?.innerHTML != undefined) {
  제목.innerHTML = "반갑소";
}
```

이건 몰라도 되는데 가끔 innerHTML 작성할 때 엔터키로 자동완성시키면 ?. 이런 연산자가 자동으로 붙습니다.  
js 신문법인데 뭔 뜻이냐면 왼쪽에 있는 object 자료안에 .innerHTML이 존재하면 그거 써주시고 없으면 undefined 남기셈~ 입니다.  
그래서 가끔 ?. 연산자로 해결할 때도 있습니다.

### 해결책5. 그냥 strict 설정 false로 끄셈

null 체크해주는게 귀찮으면 그냥 설정 끄면 모든 고민이 해결되긴 합니다.  
가장 좋은 방법은 해결책2 instanceof 연산자를 쓰는 것인데  
이걸 써야 조작가능한 부분이 있기 때문입니다.

## a 태그의 href 속성을 바꿔보자

html 파일에 `<a href="naver.com"></a>` 이런 태그가 있었습니다.  
이 태그의 href 속성을 바꾸고 싶으면 셀렉터로찾고.href = `'https://kakao.com'` 이렇게 쓰면 됩니다.  
근데 그냥 하면 안될걸요

```js
let 링크 = document.querySelector("#link");
if (링크 instanceof HTMLElement) {
  링크.href = "https://kakao.com"; //에러남 ㅅㄱ
}
```

에러납니다. HTMLElement 타입은 href 그런 속성 없다~고 하네요.  
그럴 경우 그냥 이렇게 바꿔주면 됩니다.

```js
let 링크 = document.querySelector("#link");
if (링크 instanceof HTMLAnchorElement) {
  링크.href = "https://kakao.com"; //잘됨
}
```

이러면 에러나지 않습니다.  
html 태그 종류별로 정확한 타입명칭이 있습니다.

```
a 태그는 HTMLAnchorElement
img 태그는 HTMLImageElement
h4 태그는 HTMLHeadingElement
..
```

백만개가 있는데 이런 정확한 타입으로 narrowing 해주셔야 html 속성 수정을 제대로할 수 있습니다.  
전부 외울 필요는 없고 자동완성 잘 될걸요

잠깐 왜 그래야하는지 원리를 설명하자면  
타입스크립트에서 쓸 수 있는 HTML 타입들은 이렇게 됩니다.  
Element, HTMLElement, HTMLAnchorElement 등이 있는데  
Element에 들어있는걸 복사해서 몇개 더 추가해서 HTMLElement 타입을 만들어놨고  
HTMLElement에 들어있는걸 복사해서 몇개 더 추가해서 HTMLAnchorElement 타입을 만들어놨습니다.

셀렉터로 대충 찾으면 Element 타입이라는게 부여가 됩니다.  
아직 이 태그가 뭔지 몰라서 그냥 광범위한 타입하나를 달랑 지정해주는 겁니다.  
이건 광범위한 그냥 일반 html 태그의 특징을 정리해둔 타입이기 때문에 안에 .href .src 이런거 안들어있습니다.

반면 HTMLAnchorElement 이건 조금 상세한 타입입니다.  
이 타입은 "href, style, class, id 이런 속성을 가질 수 있다~" 라고 타입이 정의되어있습니다.  
그래서 a태그에게 어울리는 타입인 HTMLAnchorElement 라는 타입을 쓸 수 있는지 instanceof 키워드로 확인해야합니다.  
확인하는 과정을 narrowing으로 인정해줍니다.

## 이벤트리스너 부착해보기

버튼 누르면 뭐 실행해주세요~라는 코드도 많이 짭니다.  
이것도 그냥 쓰시면 안되고 타입지정해야 잘 사용가능합니다.

```js
let 버튼 = document.getElementById("button");
버튼.addEventListener("click", function () {
  console.log("안녕");
});
```

이러면 에러납니다. 버튼이라는 변수가 null 일 수도 있어요~ 라는 에러가 날걸요  
어떻게 해결할까요? narrowing 알아서 해보십시오.

근데 이런 해결책도 있습니다.

```js
let 버튼 = document.getElementById("button");
버튼?.addEventListener("click", function () {
  console.log("안녕");
});
```

addEventListener 함수 붙일 때 물음표도 붙이는 것인데 이게 무슨 뜻이냐면

### optional chaining 신문법

2020년 이후 브라우저들은 ?. 연산자를 이용가능합니다.  
그니까 object에서 자료뽑을 때 object.어쩌구 이렇게 자료를 뽑는데  
object?.어쩌구 이렇게도 뽑을 수 있다는 겁니다.  
이걸 쓰면 어쩌구라는 자료가 object에 존재하면 그거 뽑아주시고요  
존재하지 않으면 undefined 남겨주세요~ 라는 뜻과 동일합니다.  
그래서 간혹 narrowing할 때 && 연산자로 undefined 체크하기 귀찮을 때 간혹 사용됩니다.

그래서 혹여나 버튼이라는 변수가 없을 경우 그 자리에 undefined를 내보내고,  
HTMLElement로 잘 있으면 addEventListener() 잘 부착해주기 때문에  
이것도 일종의 narrowing 이라고 보면 되겠습니다.  
그래서 에러안내고 봐줌

# class 만들 때 타입지정 가능

class 내부에는 모든 자식 object들이 사용가능한 속성같은걸 만들 수 있습니다.  
예를 들어서 모든 Person 클래스의 자식들에게 data 라는 속성을 부여해주고 싶으면

```js
class Person {
  data = 0;
}

let john = new Person();
let kim = new Person();

console.log(john.data);
console.log(kim.data);
```

그냥 class 중괄호 안에다가 변수처럼 만들면 됩니다. (var let 키워드 안씀)  
그럼 Person이 출산한 모든 자식에게 data = 0을 하나씩 복사해줍니다.  
당연히 자식들은 object 자료형이니 점찍고 data 쓰면 됩니다.  
class 안에 저렇게 대충 만드는 속성을 필드라고 합니다.

근데 타입이 없군요.  
저거 data라는 속성엔 number만 들어올 수 있다고 타입지정을 해봅시다.  
저거 가만히 냅두셔도 자동으로 number 타입이 됩니다.  
타입스크립트는 많은 것들을 알아서 자동으로 타입지정해준다니까요.  
굳이 명시하고 싶으면 일반 변수처럼 타입 지정해주면 끝임

```js
class Person {
  data: number = 0;
}

let john = new Person();
john.data = "1"; //이제 문자할당시 에러남
```

## constructor 타입지정

class는 간단히 말하면 object 복사기계라고 했습니다.  
예를 들어서 { name : 어쩌구, age : 어쩌구 } 이렇게 생긴 object 자료를 복사해주는 기계를 만들어봅시다.  
ES6 신문법에선 constructor 함수를 쓰면 된다고 했습니다.

```js
class Person {
  constructor() {
    this.name = "kim";
    this.age = 20;
  }
}
```

이렇게 생겼는데 실은 타입스크립트에선 이 문법이 맞지 않습니다.  
에러날걸요 Error : Property 'name' does not exist on type 'Person'  
this.어쩌구를 사용하고 싶으면 어쩌구를 미리 필드값으로 만들어줘야합니다.

```js
class Person {
  name;
  age;
  constructor() {
    this.name = "kim";
    this.age = 20;
  }
}
```

필드 값으로 name, age가 미리 정의되어있어야 constructor 안에서도 사용가능합니다.  
"옳은 JS문법은 옳은 TS문법이라던데 왜 이건 아님? 뭐여 다른 언어임?"  
이런 말이 나옵니다.

```js
class Person {
  name;
  age;
  constructor(a) {
    this.name = a;
    this.age = 20;
  }
}
```

constructor 함수엔 변수를 집어넣을 수 있다고 했습니다.  
그러면 이제 new Person('hello') 할 때 소괄호안에 들어가는 'hello' 이런 자료가 저기 a라는 파라미터자리에 들어갑니다.  
생산되는 object마다 각각 다른 이름을 부여하고 싶을 때 유용하겠군요.  
근데 저거 a라는 파라미터에 타입지정을 미리 해줘야할듯 합니다.

```js
class Person {
  name;
  age;
  constructor(a: string) {
    this.name = a;
    this.age = 20;
  }
}
```

뭔가 함수같이 생긴 것들은 함수처럼 타입지정하면 됩니다.

```js
class Person {
  name;
  age;
  constructor(a = "kim") {
    this.name = a;
    this.age = 20;
  }
}
```

혹은 함수 문법 중에 기본 파라미터 이런게 있습니다 (default parameter)  
파라미터에 값을 입력 안하면 자동으로 할당해주는 그런걸 지정가능한데  
파라미터 = 자료 이렇게 씁니다.  
이런거 활용하면 그냥 타입지정 안해도 될 듯

## mothods 타입지정

class 내부엔 함수를 입력할 수 있습니다.  
그냥 함수명(){} 이거 넣으면 끝인데  
이 함수는 Person이라는 클래스의 prototype에 추가됩니다.

```js
class Person {
  add(숫자) {
    console.log(숫자 + 1);
  }
}
```

이러면 모든 Person의 자식들은 add 라는 함수를 이용가능합니다.  
이 때 add라는 함수 타입지정은 어떻게 하게요  
그냥 함수랑 똑같습니다. 파라미터 & return 타입지정 자유롭게 할 수 있습니다. 해보십시오.

# Object에 타입지정할 때 interface

type 키워드를 이용해서 타입을 변수처럼 저장해서 쓰는 건 앞에서 해봤죠?  
근데 더 좋은 방법이 있습니다.  
interface 문법을 쓰시면 object 자료형의 타입을 보다 편리하게 지정가능합니다.  
예를 들어서 { color : 'red', width : 100 }  
이런 object를 만들고 싶은데 type을 미리 정의하고 싶으면 interface 키워드를 이렇게 만들어봅시다.

```js
interface Square {
  color: string;
  width: number;
}

let 네모: Square = { color: "red", width: 100 };
```

interface는 object랑 비슷한 모습으로 작성하면 됩니다.  
type alias와 용도와 기능이 똑같습니다.

1. 대문자로 작명하고

2. { } 안에 타입을 명시해주면 됩니다.

만들어두면 앞으로 object자료 만들 때 interface 만든걸 집어넣으시면 간편하게 타입지정이 가능합니다.

(참고) 한 줄 끝나면 콤마대신 세미콜론도 가능합니다.

## interface 장점은 extends도 가능합니다

Student interface & Teacher interface가 필요하다고 가정해봅시다.  
Student는 name 속성이 들어가야하고  
Teacher는 name 속성과 age 속성이 들어가야합니다.

```js
interface Student {
  name: string;
}
interface Teacher {
  name: string;
  age: number;
}
```

저는 이렇게 만들었습니다.  
이제 object에 자유롭게 집어넣고 그러면 될텐데  
근데 안에 중복사항들이 좀 보이는 것 같군요.  
이런건 extends 문법쓰시면 줄일 수 있습니다.  
extends 문법은 interface 여기에 복사해달라는 뜻입니다.

```js
interface Student {
  name: string;
}
interface Teacher extends Student {
  age: number;
}
```

Student interface를 extends 해달라고 적으면 Student 안에 있던걸 복사해서 Teacher에 넣어줍니다.  
이제 Teacher 타입은 age, name 속성을 가지고 있습니다.

## type 키워드와의 차이점

type alias와 interface는 거의 똑같은 기능을 제공합니다.  
그래서 차이점은 extends 문법이 약간 다르다 이런건데

```js
interface Animal {
  name: string;
}
interface Cat extends Animal {
  legs: number;
}
```

interface의 경우 일반적으로 이렇게 extends 합니다.

```js
type Animal = {
  name: string,
};
type Cat = Animal & { legs: number };
```

type alias의 경우 extends는 안되고 & 기호를 쓰면 object 두개를 합칠 수 있습니다.  
이러면 Cat 타입은 name, legs 속성을 가질 수 있습니다.

실은 interface도 type처럼 & 기호를 이용해도 복사가능

```js
interface Student {
  name: string;
}
interface Teacher {
  age: number;
}

let 변수: Student & Teacher = { name: "kim", age: 90 };
```

& 기호 쓰는걸 intersection이라고 부르는데 extends 와 유사하게 사용가능합니다.  
(주의) extends 쓸 때 타입끼리 중복속성이 발견될 경우 에러로 혼내주는데 & 쓰면 때에 따라 아닐 수도 있습니다.

## 타입이름 중복선언시

```js
interface Animal {
  name: string;
}
interface Animal {
  legs: number;
}
```

interface의 경우 타입이름 중복선언을 허용해주며 중복시 extends 한 것이랑 동일하게 동작합니다.  
이러면 Animal 타입은 name, legs 속성을 가질 수 있습니다.  
(장점) type 선언을 자주 쓰는 외부 라이브러리 이용시 type 선언을 내가 덮어쓰기, override 하기 편리합니다.

```js
type Animal = {
  name: string,
};
type Animal = {
  legs: number,
};
```

type의 경우 중복선언을 허용하지 않습니다. 에러남  
(장점) 엄격하고 진지함

그래서 일반적인 상황에선 type 키워드 자주 활용하면 되는데  
다른 사람이 내 코드를 이용하는 상황이 많으면 interface로 유연하게 만드는게 좋습니다.  
그래서 타입스크립트로 작성된 라이브러리들은 interface로 타입정해놓은 곳이 많습니다.  
혹은 object 자료형은 전부 interface로 만들고 다른 자료형은 type 키워드로 만들고 이런 것들도 괜찮습니다.  
type과 interface 문법을 잘 알고 있으면 기준은 정하기 나름입니다.

## extend 할 때 object 안의 속성이 중복될 경우

```js
interface Animal {
  name: string;
}
interface Dog extends Animal {
  name: number;
}
```

Animal을 복사해서 Dog interface를 만들어봤습니다.  
근데 name 속성이 중복되네요? 그럼 에러납니다

```js
interface Animal {
  name: string;
}
interface Dog {
  name: number;
}

let 변수: Dog & Animal = { name: "멍멍" };
```

& 연산자로 Dog, Animal을 합쳐봤습니다.  
근데 name 속성이 중복되네요? 그럼 에러납니다
interface 말고도 type 키워드도 똑같은 현상이 일어납니다.

(주의) 근데 name : string , name : number 라서 에러가 나는 것이지  
둘다 name : string 타입이면 에러가 나지 않습니다. 하나로 합쳐줌

만약 Object 안에 함수를 2개 넣고 싶다면

1. 이 object 자료는 plus() 함수를 내부에 가지고 있으며 plus 함수는 파라미터 2개를 입력하면 더해서 return 해줍니다.

2. 이 object 자료는 minus() 함수를 내부에 가지고 있으며 minus 함수는 파라미터 2개를 입력하면 빼서 return 해줍니다.

이 object 자료를 어떻게 만들면 될까요?  
interface를 이용해서 object에 타입지정도 해보면

```js
interface MathObj {
  plus: (a: number, b: number) => number;
  minus: (a: number, b: number) => number;
}

let 오브젝트: MathObj = {
  plus(a, b) {
    return a + b;
  },
  minus(a, b) {
    return a - b;
  },
};
```

함수타입은 ()=>{} 이렇게 만들면 됩니다.

# 함수 rest 파라미터, destructuring 할 때 타입지정

잠깐 rest 파라미터 개념설명을 하자면
함수에 어떤 파라미터가 몇개 들어올지 미리 정의가 불가능한 경우가 있습니다.  
3개일지 4개일지 100개일지 모른다면 점3개 ...로 rest 파라미터를 만들어주면 됩니다.

```js
function 전부더하기(...a) {
  console.log(a);
}

전부더하기(1, 2, 3, 4, 5);
```

함수 파라미터 작명할 때 점3개 붙여주면 여기엔 파라미터 잔뜩 들어올 수 있습니다~라고 정의가 가능합니다.  
전문 용어로 rest 파라미터라고 합니다.

- rest 파라미터는 다른 일반 파라미터 뒤에만 올 수 있습니다.

- rest 파라미터자리에 집어넣은 값들은 전부 [ ] 안에 담겨있습니다.

rest 파라미터 타입지정은

```js
function 전부더하기(...a: number[]) {
  console.log(a);
}
```

전부더하기(1,2,3,4,5)  
rest 파라미터는 항상 [ ] 안에 담겨오기 때문에 타입지정도 array처럼 해주시면 됩니다.

Spread operator와 다른겁니다
코드짜다보면 점 3개 붙이는 경우가 또 있는데  
array 혹은 object 괄호 벗기고 싶을 때 왼쪽에 사용합니다.

```js
let arr = [3, 4, 5];
let arr2 = [1, 2, ...arr];
console.log(arr2);
```

array 혹은 object 왼쪽에 점3개 붙이면 괄호 벗겨주세요~ 라는 뜻입니다.  
그래서 arr2 출력해보면 `[1,2,3,4,5]` 나옵니다.

괄호벗겨주는 ...spread는 array, object 자료 왼쪽에,  
여러개의 파라미터를 의미하는 ...rest는 함수선언할 때 소괄호 안에 출몰합니다.

잠깐 Destructuring 문법 개념설명을 하자면
자바스크립트에서 array, object 안에 있는 데이터를 빼서 변수로 만들고 싶을 때 쓰는 문법이 있습니다.

```js
let 사람 = { student: true, age: 20 };
let student = 사람.student;
let age = 사람.age;
```

이렇게 쓰면 되긴 하는데 개발자들이 귀찮아서 새로운 문법을 만들어냈습니다.  
Destructuring 이라는 것인데 변수로 빠르고 쉽게 뺄 수 있도록 도와주는 문법입니다.

```js
let { student, age } = { student: true, age: 20 };
```

이렇게 쓰면 똑같이 변수로 뺄 수 있습니다.  
진짭니다 student 한 번 출력해보면 true 들어있을 걸요  
이걸 destructuring 문법이라고 하며 왼쪽 오른쪽 틀린그림찾기처럼 변수 작명해주시면 끝입니다.

```js
let [a, b] = ["안녕", 100];
```

array 자료도 왼쪽오른쪽 똑같아보이게 변수 작명해주시면 변수로 쉽게 뺄 수 있습니다.  
다만 특징은 object destructuring할 땐 변수이름을 속성이름과 맞춰주는게 편리하고 (안맞추면 더 복잡함)  
array destructuring할 땐 변수이름 맘대로 작명가능합니다.

## Destructuring 문법도 함수 파라미터에 사용가능

왜냐면 함수 파라미터 작명하는 것도 변수만드는 문법과 똑같아서 그렇습니다

변수만들 때 기존 object에 있던 자료를 파라미터로 집어넣고 싶으면

```js
let person = { student: true, age: 20 };

function 함수(a, b) {
  console.log(a, b);
}
함수(person.student, person.age);
```

기존 object에 있던걸 person.student 이렇게 각각 찝어서 집어넣으면 되긴 되는데  
destructuring 문법을 이용하면 약간 더 쉽게 사용가능합니다.

```js
let person = { student: true, age: 20 };

function 함수({ student, age }) {
  console.log(student, age);
}
함수({ student: true, age: 20 });
```

실은 안쉬운듯  
그니까 파라미터 변수만들 때 { student, age }라고 쓰면  
파라미터로 들어오는 { student : 어쩌구 }는 student 라는 변수에 저장해주세요~  
파라미터로 들어오는 { age : 어쩌구 }는 age 라는 변수에 저장해주세요~  
라는 뜻입니다. (object 자료니까 변수 작명할 때 object 속성명으로 잘 작명해야함)  
항상 같은 모습의 object, array 자료가 들어올 때 쓰는 문법이라고 보면 되겠습니다.

# Narrowing 할 수 있는 방법 더 알아보기

Narrowing 하면서 코드짜는 것도 힘든데 특히나

1. undefined 타입일 경우 처리하는거

2. 복잡한 object자료들 narrowing 하는거

이게 가장 잦고 귀찮습니다. 이걸 쉽게 하는 법을 좀 알아봅시다.

## null & undefined 체크하는 법

실제로 개발할 때 어떤 변수나 함수파라미터에 null, undefined가 들어올 경우

어떻게 대처할지 if문으로 코드짜는 경우가 매우 많을 겁니다.

```js
if (저 변수가 undefined일 경우) 어쩌구~
```

이런 코드 많이 짤 텐데 왜냐면 저런 상황을 미리 방어하는게 언제나 좋기 때문입니다.  
근데&& 스킬을 쓰면 저런 if문을 생략할 수 있습니다.  
원래 && 이건 조건식 2개가 참이면 전부 참으로 판정해주세요~ 라는 논리연산자인데  
여러개를 사용하면 이상한 현상이 있습니다.

&& 기호로 비교할 때 true와 false를 넣는게 아니라 자료형을 넣으면  
&& 사이에서 처음 등장하는 falsy 값을 찾아주고 그게 아니면 마지막 값을 남겨줍니다.  
falsy 값은 false와 유사한 기능을 하는 null, undefined, NaN 이런 값들을 의미합니다.

```js
1 && null && 3; // null이 남음
undefined && "안녕" && 100; // undefined 남음
```

이걸 약간 exploit 하면 if문을 조금 더 간략하게 쓸 수 있습니다.  
그래서 && 기호를 이용해서

```js
if (변수 && typeof strs === "string") {
}
```

이렇게 사용하면 변수가 undefined라면 undefined가 남아서 if문이 실행되지 않고,  
(if문 조건식안에 falsy 값이 남으면 if문 실행되지 않습니다)  
변수가 string 타입이면 if문이 실행됩니다.  
변수가 null, undefined인 경우를 쉽게 거를 수 있는 문법이라고 보면 되겠습니다.

```js
function printAll(strs: string | undefined) {
  if (strs && typeof strs === "string") {
    console.log(s);
  }
}
```

근데 한 눈에 안들어온다면 안쓰는게 좋습니다.
그냥 if (저 변수가 undefined일 경우) 어쩌구~ 이렇게 if문을 하나 더 쓰는게 어떨까요.  
참고로 if (변수 != null) 이렇게 조건식을 써도 null, undefined 이거 두 개를 동시에 거를 수 있습니다.

## in 연산자로 object 자료 narrowing

예를 들어서 파라미터로 object가 2개 들어올 수 있다고 타입지정을 해놓은 것입니다.  
하나는 {a : 'kim}  
다른 하나는 {b : 'park'}  
이렇게 서로 다른 유니크한 속성들을 가지고 있다면

if (이 파라미터가 a라는 속성을 안에 가지고 있냐)  
이런 if문을 써도 narrowing이 가능하다는 뜻입니다.  
if (키값 in object자료형) 이렇게 쓰면 됩니다.  
타입스크립트 컴파일러는 똑똑한 편이라 이런 것들도 narrowing 으로 판정해줍니다.

```js
type Fish = { swim: string };
type Bird = { fly: string };
function 함수(animal: Fish | Bird) {
  if ("swim" in animal) {
    return animal.swim;
  }
  return animal.fly;
}
```

서로 배타적인 속성을 가져와야 narrowing이 가능합니다.  
예를 들어서 Fish와 Bird 타입이 둘 다 swim 속성을 가지고 있고 Bird만 fly 속성을 추가로 가지고 있으면 어쩌죠?  
어떻게 narrowing하면 좋을지 한 번 생각해봅시다.

## class로부터 생산된 object라면 instanceof로 narrowing

class 문법을 아는 분들만 들어보도록 합시다.  
어떤 클래스로부터 new 키워드로 생산된 object들이 있습니다.  
그런 object 들은 instanceof 키워드를 붙여서 부모 클래스가 누군지 검사할 수 있는데  
이것도 narrowing 역할을 할 수 있습니다.

가장 쉽게 new 키워드로 object 생산할 수 있는게 바로 날짜인데  
자바스크립트에선 new Date() 이렇게 하면 date object 라는게 생성됩니다.  
그래서 instanceof로 부모 클래스가 누군지 검사할 수 있습니다.

```js
let 날짜 = new Date();
if (날짜 instanceof Date) {
  console.log("참이에요");
}
```

이렇게 쓸 수 있고 이런 문법도 narrowing 역할을 할 수 있습니다.  
이 변수가 Date()로 부터 생성된 object 자료인지, 아니면 다른 애로부터 생성된 자료인지 이런걸 구분가능하기 때문입니다.  
class 문법모르면 뭔소린지 모르겠죠? 그럴 경우엔 뒷부분 class, prototype 수업듣고 다시 놀러오도록 합시다.

## literal type이 있으면 narrowing 쉬움

```js
type Car = {
  wheel : '4개',
  color : string
}
type Bike = {
  wheel : '2개',
  color : string
}

function 함수(x : Car | Bike){
  if (x가 Car타입이면요){
    console.log('이 차는 ' + x.color)
  } else {
    console.log('이 바이크는 ' + x.color)
  }
}
```

지금 Car, Bike 타입을 각각 만들었는데 object 자료가 들어올 수 있습니다.  
함수에 Car 타입을 입력할 경우 뭔가 실행하고 싶은데  
근데 if문 안에서 narrowing 어떻게 하죠?

typeof 연산자 써도 그냥 object 입니다~ 라고만 나올걸요 왜냐면 typeof 연산자는 string, number, object 이런 것만 구분해주기 때문입니다.  
위에서 배웠던 in 문법 이런걸로 narrowing하기엔 힘들어보입니다. Car, Bike 둘 다 배타적인 속성이 없으니까요.

실은 object들 구분할 일이 많을 때 literal type을 만들어두면 편리한데  
그럼 서로 비슷한 object들이 들어와도 literal type으로 narrowing 가능하기 때문입니다.  
제가 literal type 하나씩 적어둔거 보이시죠?  
지금 Car 타입은 무조건 wheel 출력해보면 4  
Bike 타입은 wheel 출력해보면 무조건 2가 나옵니다.  
이거 가지고 object 끼리 narrowing 가능합니다.  
그냥 if문으로 "지금 이 변수가 wheel 속성에 저장된게 4냐" 라고 물어보면 이건 누가봐도 Car 타입아니겠습니까.

타입스크립트는 스마트하니까 그렇게 쓰면 narrowing 충분히 가능합니다.  
그래서 빨리 위에 코드 if문 조건식 채워보셈

```js
type Car = {
  wheel: "4개",
  color: string,
};
type Bike = {
  wheel: "2개",
  color: string,
};

function 함수(x: Car | Bike) {
  if (x.wheel === "4개") {
    console.log("the car is " + x.color);
  } else {
    console.log("the bike is " + x.color);
  }
}
```

그냥 literal type 으로 선언된 속성이 뭔지 찾아냈을 뿐입니다. 그러면 narrowing 가능  
그래서 결론은 object 자료 비슷한걸 많이 다룰 땐  
literal type으로 object 안에 각각 유니크한 자료를 달아두거나 그러면 나중에 구분하기 편리할 수 있습니다.

# 함수에 사용하는 never 타입

함수에 붙이는 return type으로 사용가능합니다.  
근데 좀 특이합니다.

```js
function 함수(): never {}
```

어떤 함수가

1. 절대 return을 하지 않아야하고

2. 함수 실행이 끝나지 않아야합니다 (전문용어로 endpoint가 없어야합니다)

그런 함수에 붙일 수 있는 타입니다.  
실은 조건1, 2는 같은 소리인데 모든 자바스크립트 함수 맨 밑엔 return undefined 라는 숨겨진 코드를 가지고 있습니다.  
그래서 조건2가 맞으면 1도 맞음

```js
function 함수() {
  console.log(123);
}
```

이런 함수들에 never를 붙일 순 없습니다.  
왜냐면 조건 1번은 만족하지만 2번은 만족하지 않습니다.  
2번 조건은 함수 내부 코드 실행이 끝나지 않는 함수여야합니다.

```js
function 함수(): never {
  while (true) {
    console.log(123);
  }
}
```

이런 함수엔 붙일 수 있습니다.
while 문법은 ( ) 소괄호안의 조건식이 true일 경우 계속 내부 코드를 실행해라~ 라는 뜻입니다.  
무한히 실행되기 때문에 끝이안나죠? 그래서 never 타입을 사용가능합니다.

```js
function 함수(): never {
  throw new Error("에러메세지");
}
```

이런 함수에도 붙일 수 있습니다.  
throw new Error() 문법은 그냥 강제로 에러내라~ 라는 뜻인데  
에러가 나면 전체 코드실행이 중단되니까 2번 조건도 나름 충족하는 것이기 때문에  
never를 사용가능합니다.

그래서 1. 무언가 return 하지 않고 2. 끝나지도 않는 함수를 표현하고 싶을 때 never 타입을 지정하면 되는데  
2번 조건의 함수를 만들 일이 거의 없기 때문에 never 타입은 쓸 일이 없습니다.  
무언가를 return하고싶지 않을 경우 그냥 void 타입을 이용하시면 되며  
배우는 이유는 가끔 코드 이상하게 짜다보면 자동으로 등장하기 때문입니다.  
이 때 never 이게 뭘 의미하는지 이해만 잘 하면 됩니다.  
어떨 때 등장하는지 알아봅시다.

## 파라미터가 never 타입이 되는 경우도 있음

```js
function 함수(parameter: string) {
  if (typeof parameter === "string") {
    parameter + 1;
  } else {
    parameter;
  }
}
```

위 함수는 뭔가 이상한 함수입니다.  
지금 narrowing을 이용해서 파라미터의 타입이 string 이면 뭔가 해달라고 써놨는데  
else 문이 존재합니다. 타입이 string이 아닐 경우 이거 해달라는 뜻입니다.  
근데 else문은 말이 안되죠? 지금 파라미터가 string 밖에 못들어오는데 말입니다.

이런 잘못된 narrowing을 사용했을 때 파라미터의 타입이 never로 변합니다. 파라미터에 마우스 올려보셈  
이런 건 있을 수 없다, 일어나면 안된다고 알려주는 느낌입니다.  
그럴 때 never를 구경할 수 있으니 never 타입이 발견되는 경우 코드를 수정하는게 어떨까요.

## 자동으로 never 타입을 가지는 경우

자바스크립트는 함수를 만드는 방법이 2개 있습니다.

```js
function 함수() {}

let 함수2 = function () {};
```

위는 함수 선언문,  
밑은 함수 표현식이라고 부릅니다. 똑같이 함수만들 수 있는 문법입니다.

```js
function 함수() {
  throw new Error();
}

let 함수2 = function () {
  throw new Error();
};
```

함수 선언문이 아무것도 return 하지 않고 끝나지도 않을 경우 void 타입이 자동으로 return 타입으로 할당되며  
함수 표현식이 아무것도 return 하지 않고 끝나지도 않을 경우 never 타입이 자동으로 return 타입으로 할당됩니다.  
마우스 올려보면 나옵니다.

또는 tsconfig.json에서 strict 옵션을 켜둘 경우  
함부로 any 타입을 지정해주지 않는 경우가 있습니다.  
그럴 때 array 같은거 대충 타입지정 안하고 만들면

```js
let arr = [];
```

원래는 any[] 이런 타입이 되는데 any를 가질 수 없어서  
never[] 이런 타입이 발견되기도 합니다.  
아무튼 쓸 일이 별로 없기 때문에 이럴 때도 등장한다고 알아두기만 하면 됩니다.

# public, private 쓰는거 보니까 타입스크립트 귀여운편

타입스크립트 쓰면 자바스크립트에 없는 문법도 사용가능합니다.  
객체지향 언어에서 제공하는 public, private, static, protected 이런 키워드를 사용가능한데  
뭔지 한번 알아봅시다.

## public, private 키워드로 사용제한두기

타입스크립트는 class 안에서 public 키워드를 사용가능합니다.  
원하는 속성 왼쪽에 붙이면 그 속성은 아무데서나 수정이 가능합니다.

```js
class User {
  public name: string;

  constructor(){
    this.name = 'kim';
  }
}

let 유저1 = new User();
유저1.name = 'park';  //가능
```

public이 붙은 속성은 자식 object들이 마음대로 사용하고 수정가능합니다.  
실은 public 붙이든 안붙이든 똑같긴 합니다. 맞잖아요 실험해보셈  
왜냐면 필드값 같은걸 그냥 만들면 public이 몰래 왼쪽에 부여되기 때문입니다.

(참고) public 키워드는 class 내의 prototype 함수에도 붙일 수 있습니다.

근데 private 키워드를 붙이면 수정이 불가능해집니다.  
무조건 class { } 중괄호 안에서만 수정 및 사용가능합니다.  
심지어 class로 부터 생산된 자식 object에서도 private 붙은건 사용불가능합니다.  
(class 중괄호 내부가 아니니까요)

```js
class User {
  public name :string;
  private familyName :string;

  constructor(){
    this.name = 'kim';
    let hello = this.familyName + '안뇽'; //가능
  }
}

let 유저1 = new User();
유저1.name = 'park';  //가능
유저1.familyName = 456; //에러남
```

secretId 라는 속성에는 private 키워드를 추가했더니 아무데서나 수정이 불가능해졌습니다.  
private 붙은 속성들은 오직 class { } 안에서만 수정이 가능합니다.  
이렇게 속성을 외부에서 숨기고 싶을 때 private 키워드를 이용합니다.  
실은 오리지널 자바스크립트 문법에서도 #이걸 속성옆에 붙이면 private 속성이 됩니다.

(참고) private 키워드는 class 내의 함수에도 붙일 수 있습니다.

Q. private 부여된 속성을 class 밖에서 수정해야할 경우?

1.  private 속성을 수정하는 함수를 class 안에 만들어서

2.  함수를 실행시키면 됩니다.

위에서 private 붙여놓은 secretId 이런걸 바깥에서 수정하고 싶은 경우 이렇게 합니다.

```js
class User {
  public name :string;
  private familyName :string;

  constructor(){
    this.name = 'kim';
    let hello = this.familyName + '안뇽';
  }
  changeSecret(){
    this.familyName = 'park';
  }
}

let 유저1 = new User();
유저1.familyName = 'park';  //에러남
유저1.changeSecret()        //가능
```

1. changeSecret() 함수를 class 안에 만들었습니다.

이 함수는 familyName을 수정해주는 함수입니다.

2. 그러면 이제 class 바깥에서도 changeSecret() 함수를 이용하면 간접적으로 familyName을 수정가능합니다.

함수 불러도 에러안나고 수정 잘 됩니다.  
중요한건 아니고 참고로 알아둡시다.

## public, private 키워드 쓰면 이런 것도 가능

```js
class Person {
  name;
  constructor ( name :string ){
    this.name = name;
  }
}
let 사람1 = new Person('john')


class Person {
  constructor ( public name :string ){

  }
}
let 사람1 = new Person('john')
```

위 두개의 코드는 같은 역할을 하는 코드입니다.  
"constructor 파라미터에 public 붙이면 this.name = name 이거 생략가능하다" 라는걸 참고해주시면 되며  
이제 Person으로부터 새로 생산되는 object들은 name 속성을 가질 수 있습니다.

# class 안에서 쓰는 protected 키워드

private 이거랑 비슷한 키워드가 하나 있는데

private인데 약간 보안을 해제하고 싶을 때 씁니다.

protected를 달아놓으면 1. private 이거랑 똑같은데 2. extends 된 class 안에서도 사용가능하게 약간 보안을 풀어줍니다.

예제를 쉽게 다시 만들어봅시다

```js
class User {
  protected x = 10;
}
```

User 라는 class의 x 속성은 protected 입니다.  
그럼 private와 동일하게 class 안에서만 사용이 가능해지며  
User의 자식들도 함부로 사용이 불가능합니다.

```js
class User {
  protected x = 10;
}

class NewUser extends User {
  doThis(){
    this.x = 20;
  }
}
```

User를 extends 하는 NewUser class를 만들었습니다.  
NewUser가 갑자기 this.x 이런 식으로 x를 가져다가 쓰려고 하면  
x가 private 속성일 경우엔 에러가 나지만  
x가 protected 속성일 경우엔 에러가 나지 않습니다.

그래서 class 여러개 만들 때 class 끼리 공유할 수 있는 속성을 만들고 싶으면 protected,  
class 하나 안에서만 쓸 수 있는 속성을 만들고 싶으면 private 이걸 쓰도록 합시다.  
class 여러개 만들 일이 없으면 쓸모없습니다.

# class 안에서 쓰는 static 키워드

우리가 class { } 안에 집어넣는 변수, 함수 이런건 전부 class로 부터 새로 생성되는 object (일명 instance) 에 부여됩니다.  
근데 class에 직접 변수나 함수를 부여하고 싶으면 static 키워드를 왼쪽에 붙여주면 됩니다.

예를 들어 봅시다.

```js
class User {
  x = 10;
  y = 20;
}

let john = new User();
```

john.x //가능
User.x //불가능
이런 x와 y같은 변수들은 User로 부터 생성된 object들만 사용가능합니다.

근데 static 키워드를 붙이면

```js
class User {
  static x = 10;
  y = 20;
}

let john = new User();
```

john.x //불가능
User.x //가능
john은 사용불가능하고

User는 직접 사용가능합니다.

- 함수도 static 붙이기 가능

- extends 로 class를 복사할 경우 static 붙은 것들도 따라옵니다.

(참고) static은 private, protected, public 키워드와 동시 사용가능합니다.

```js
class User {
  private static x = 10;
  public static y = 20;
}
```

1. 필드값은 원래는 모든 User의 자식들에게 물려주는 속성이지만  
   x와 y에는 static 키워드가 붙었기 때문에 User.x 이런 식으로만 접근해서 쓸 수 있습니다.  
   User의 자식들은 x와 y를 쓸 수 없습니다.

2. private static x는 class 내부에서만 수정가능합니다.

3. public static y는 class 내부 외부 상관없이 수정가능합니다. public 키워드 지워도 똑같이 동작할 듯

4. protected z는 private 키워드와 유사하게 class 내부에서만 사용이 가능한데  
   약간 범위가 넓어서 extends로 복사한 class 내부에서도 사용할 수 있습니다.

Q. static 이런걸 언제 씁니까

주로 class 안에 간단한 메모를 하거나, 기본 설정값을 입력하거나  
class로 부터 생성되는 object가 사용할 필요가 없는 변수들을 만들어놓고 싶을 때 사용합니다.

## 무작위 박스 생성

```js
let 네모 = new Square(30, 30, "red");
네모.draw();
네모.draw();
네모.draw();
네모.draw();
```

이렇게 네모.draw()를 할 때마다  
index.html에 가로 30px, 세로 30px, 배경색이 'red' 의 `<div>` 박스가 무작위로 배치되어야합니다.

```js
class Square {
  constructor (public width :number, public height :number, public color :string){
  }
  draw(){
    let a = Math.random();
    let square = `<div style="position:relative;
      top:${a * 400}px;
      left:${a * 400}px;
      width:${this.width}px;
      height : ${this.height}px;
      background:${this.color}"></div>`;
    document.body.insertAdjacentHTML( 'beforeend', square );
  }
}


let 네모 = new Square(30, 30, 'red');
네모.draw()
네모.draw()
네모.draw()
네모.draw()
```

1. constructor를 이용해서 새로뽑는 object 들은 width, height, color를 입력할 수 있게 만들었습니다.

2. 자식들은 draw()를 쓰면

(1) 0과 1사이의 무작위 숫자를 뽑습니다. 그걸 변수 a에 저장해둡니다.

(2) `<div>`를 디자인합니다. 근데 `<div>`박스의 폭, 높이, 색상은 constructor로 입력한 것들을 활용합니다.

(3) `<div>` 박스의 위치는 left, right 속성을 이용해서 0~400px 사이로 무작위로 배치합니다.

(4) insertAdjacentHTML 이런거 이용하면 원하는 곳에 html 추가가 가능합니다.

그래서 실제로 자식을 하나 뽑아서 draw() 했더니 진짜 빨간 박스 4개 나옵니다.  
다른 사이즈, 다른 색상으로도 뽑아서 draw() 이것도 가능하겠군요

# 타입도 import export 해서 씁니다 그리고 namespace

만든 타입변수를 다른 파일에서 사용하고 싶은 경우 자바스크립트 import export 문법 그대로 사용가능합니다.  
import export 문법이 처음이라면 듣는 의미가 없을 수 있으니 간략하게 설명하자면

a.ts -> b.ts 이렇게 변수나 함수를 가져다쓰고 싶은 경우

```js
a.ts;

export var 이름 = "kim";
export var 나이 = 30;

b.ts;

import { 이름, 나이 } from "./a";
console.log(이름);
```

이렇게 사용하면 됩니다.

1. 우선 변수를 다른 파일에서 쓰이게 내보내고 싶으면 export 문법으로 내보내야하고

2. export된 변수를 가져와서 쓰고 싶으면 import 문법으로 가져와야합니다.

export 하고 싶으면 변수나 함수 정의부분 왼쪽에 export 키워드 붙이면 되고  
import 하고 싶으면 import {변수명} from 파일경로  
이렇게 쓰면 됩니다. 경로는 ./ 부터 시작해야합니다 현재경로라는 뜻이고 ts 파일 확장자는 안붙여야합니다.

```js
import * from './a';
console.log(이름);
console.log(나이);
```

변수명 쓰기 귀찮으면 import \* 하셔도 됩니다. 그 파일에서 export된 변수를 전부 import 해오는 문법입니다.

a.ts -> b.ts 이렇게 정의된 타입을 가져다 쓰고 싶은 경우

```js
a.ts;

export type Name = string | boolean;
export type Age = (a: number) => number;
b.ts;

import { Name, Age } from "./a";
let 이름: Name = "kim";
let 함수: Age = (a) => {
  return a + 10;
};
```

타입도 똑같이 사용하면 됩니다.

# 타입을 파라미터로 입력하는 Generic

함수만들 때 () 여기에 파라미터 입력하지않습니까  
근데 타입스크립트를 쓰시면 파라미터로 타입을 입력할 수도 있습니다.  
<> 여기에 집어넣으면 됩니다.

함수 return 값의 타입이 애매하면
예를 들어

1. 아무렇게나 생긴 array 자료를 입력하면

2. array의 첫 자료를 그대로 출력해주는 함수를 만들었다고 합시다.

```js
function 함수(x: unknown[]) {
  return x[0];
}

let a = 함수([4, 2]);
console.log(a);
```

이러면 콘솔창에 4가 출력됩니다.  
근데 마우스 올려서 a의 타입을 확인해보면 숫자는 아니고 unknown 타입입니다.  
왜냐면 지금 입력하는 array도 unknown 타입이라서 그렇습니다.  
여기서 중요포인트는 타입스크립트는 타입을 알아서 변경해주지 않습니다.  
스마트하게 숫자가 return 되면 "number 타입입니다~" 문자가 return 되면 "string 타입입니다~"  
그런거 안해준다는 것입니다.

```js
function 함수(x: unknown[]) {
  return x[0];
}

let a = 함수([4, 2]);
console.log(a + 1);
```

그래서 이런 연산도 에러가 납니다.  
a는 사람이 보기에 분명히 숫자가 맞지만 아직 타입은 unknown 타입이니까요.  
님들이 함수의 return 타입지정을 :number 이런 걸로 강제로 바꾸기 전까지는 number 타입으로 변하지 않습니다.

그래서 여러분이 함수에 불확실한 unknown, any, union 타입을 입력하면
나오는 값도 unknown, any, union 타입이고, 이 때문에 일어나는 문제들이 많습니다.  
예를 들면 "함수가 10을 return 하는데 타입이 unknown 이라서 맘대로 조작을 못하네" 문제요  
해결책은

1. narrowing 잘 하면 해결됩니다. 근데 귀찮음

2. 그냥 애초에 타입을 파라미터로 함수에 미리 입력하는 방법도 있습니다. 그럼 원하는 곳에 가변적으로 타입지정 가능

2번을 Generic 이라고 부릅니다.

## Generic 적용한 함수만들기

함수에 <> 이런 괄호를 열면 파라미터를 또 입력할 수 있습니다.

근데 여기 안엔 타입만 입력할 수 있습니다. 타입파라미터 문법임

```js
function 함수<MyType>(x: MyType[]): MyType {
  return x[0];
}

let a = 함수 < number > [4, 2];
let b = 함수 < string > ["kim", "park"];
```

그럼 이제 함수를 사용할 때도 <> 안에 파라미터처럼 타입을 입력할 수 있습니다.  
그럼 님들이 이제 `함수<number>( )` 이렇게 쓰는 순간  
MyType 이라는 변수에 number 라는게 들어간다고 보시면 됩니다.  
그럼 이제 함수( x : number[] ) :number { } 이거랑 똑같이 동작합니다.

그럼 뭐가 좋겠습니까. 아까 unknown 가득한 예제와는 다르게  
return 되는 타입이 number입니다.  
b 변수는 return되는 타입은 string이 될겁니다.

아무튼 결론 : Generic을 쓰면 여러분이 정한 타입을 return 값으로 뱉는 함수를 제작가능한 것입니다.  
<> 문법만 잘 쓰면 됩니다.

```js
function 함수<MyType>(x: MyType[]): MyType {
  return x[0];
}

let a = 함수([4, 2]);
let b = 함수(["kim", "park"]);
```

실은 함수 사용시 꼭 <> 안써도 알아서 기본 타입을 유추해서 집어넣어줍니다.  
이래도 결과는 똑같습니다.

(참고)

- 타입파라미터는 자유작명가능 보통 `<T>` 이런걸로 많이 합니다.

- 일반 함수파라미터 처럼 2개 이상 넣기도 가능합니다

## 근데 왜 - 1은 불가능함

함수 이런거 만들었는데 왜 에러가 나는 것이죠?

```js
function 함수<MyType>(x: MyType) {
  return x - 1;
}

let a = 함수 < number > 100;
```

`<MyType>` 자리에 number 이런거 타입 꽂아넣으면  
MyType 붙은 곳에 다 집어넣어진다면서요  
근데 x - 1 은 불가능하네요?

이유는 에러메세지를 잘 보면 됩니다.

```
The left-hand side of an arithmetic operation must be of type 'any','number','bigint' or an enum type. (2362)
```

어디서 많이 보던 문장입니다.  
`<MyType>` 이라는 곳에 number 말고도 다른거 혹시 집어넣을 수 있으니까 저런 - 1 연산을 미리 방지해주는 것입니다.  
그래서 해결책은 narrowing을 하셔도 되는데 MyType에 집어넣을 수 있는 타입을 미리 제한하는 것도 하나의 해결책입니다.

## Generic 타입 제한하기 (constraints)

extends 문법을 쓰면 넣을 수 있는 타입을 제한할 수 있습니다.  
그래서 MyType extends number 라고 쓰면 타입 파라미터에 넣을 수 있는 타입을 제한가능합니다.  
interface 문법에 쓰는 extends와는 살짝 다른 느낌입니다.  
그 extends는 복사인데 이번 extends는 number와 비슷한 속성을 가지고 있는지 if 문으로 체크하는 문법이라고 보면 됩니다.

```js
function 함수<MyType extends number>(x: MyType) {
  return x - 1
}

let a = 함수<number>(100) //잘됩니다
```

그래서 그렇게 써봤습니다. 이러면 에러없이 잘됩니다.  
return 타입지정을 안한 이유는 숫자 - 숫자를 했으니 알아서 number 타입이 됩니다.

## 언제나 커스텀 타입도 extends 가능

예를 들어서 문자로 파라미터를 넣으면 자릿수를 세어서 출력해주는 함수를 Generic으로 만들고 싶습니다.

```js
function 함수<MyType>(x: MyType) {
  return x.length;
}

let a = 함수 < string > "hello";
```

문자에 .length 붙이면 몇자리의 문자인지 출력해주는데  
에러나고 안됩니다.  
왜냐면 MyType에 string을 집어넣었지만 나중에 number 이런거 실수로 집어넣으면 어쩔 것임  
그럴 수 있어서 아직 .length같은 조작을 일단 방지해주는 것입니다.  
그래서 MyType을 extends 이런걸로 정확히 제한해주면 되는데  
이번엔 interface로 만들어둔 타입을 extends 해봅시다.

```js
interface lengthCheck {
  length : number
}
function 함수<MyType extends lengthCheck>(x: MyType) {
  return x.length
}

let a = 함수<string>('hello')  //가능
let a = 함수<number>(1234) //에러남
```

1. length 속성을 가지고 있는 타입을 하나 만들었습니다. 이름은 lengthCheck로 했습니다.

2. 그걸 extends 해주면 MyType도 length 속성을 복사해서 가집니다.

3. 그래서 MyType은 length가 분명히 있기 때문에 맘대로 MyType을 부여받은 x는 .length 조작이 가능합니다.

(참고) class도 class `<MyType> {}` 이런 식으로 만들면 new로 뽑을 때 타입파라미터를 집어넣을 수 있습니다.  
`type Age<MyType> = MyType` 이런 식으로 타입변수에도 사용가능

# React + TypeScript 사용할 때 알아야할 점

리액트프로젝트 설치는 이런 명령어를 사용합니다.

```
npx create-react-app 프로젝트명 --template typescript
```

typescript 셋팅이 완료된 프로젝트 설치하는 법인데

기존 프로젝트에 타입스크립트만 더하고 싶으면  
기존 프로젝트 경로에서 터미널을 오픈하신 후

```
npm install --save typescript @types/node @types/react @types/react-dom @types/jest
```

입력해주면 끝입니다. 이제 .js 파일을 .ts 파일로 바꿔서 이용가능합니다.  
이런거 할 바엔 깔끔하게 그냥 새로 프로젝트 만드는게 안전합니다.

그럼 프로젝트가 생성되는데 일반 프로젝트와 다른 점은  
컴포넌트 파일은 js가 아니라 tsx로 확장자를 사용하셔야한다는 점입니다. ts랑 똑같은데 jsx 문법을 지원합니다.  
코드짜는 것은 일반 리액트와 큰 다른점이 없습니다.  
다만 함수, 컴포넌트, state, props 타입체크를 잘 해줘야 에러가 나지 않습니다.  
그래서 리액트에선 TS 문법을 어디에 써야하는지 4개로 정리해드리겠습니다.  
그냥 타입관련 버그가 생길 것 같은 곳에 타입지정하면 끝입니다.

## 일반 변수, 함수 타입지정

그냥 타입스크립트 배웠던 대로 똑같이 하면 됩니다.

## JSX 타입지정

리액트에선 변수나 자료에 `<div></div>` 이런걸 쌩으로 담아서 쓸 수 있습니다.  
왜냐면 리액트에서 `<div></div>` 이렇게 쓰면 HTML이 아니라 JSX라고 부르는 자료가 됩니다.  
이런 자료를 타입지정하고 싶으면 JSX.Element 라는 타입을 쓰시면 됩니다.

```js
let 박스: JSX.Element = <div></div>;
let 버튼: JSX.Element = <button></button>;
```

이러면 끝입니다.

실은 더 정확히 타입지정하시려면

`<div>`, `<a>`, `<h4>` 같은 기본 태그들은 JSX.IntrinsicElements 라는 이름의 타입을 쓰면 됩니다.

```js
let 박스: JSX.IntrinsicElements["div"] = React.createElement("div");
let 버튼: JSX.IntrinsicElements["button"] = <button></button>;
```

위처럼 `<button>` 이런 간단한 태그를 타입지정하고 싶으면 저렇게 쓰십시오.  
참고로 React.createElement('div') 이건 `<div></div>` 가 남습니다.  
JSX 안쓰면 createElement 라는 이상한 함수로 리액트 코딩하셔야합니다.

## function component 타입지정

```js
function App() {
  return <div>안녕하세요</div>;
}
```

리액트의 컴포넌트는 이렇게 생겼습니다.  
컴포넌트 타입지정은 어떻게 하게요  
당연히 함수니까 파라미터와 return 타입지정하면 됩니다.  
파라미터는 항상 props기 때문에 props가 어떻게 생겼는지 조사해서 타입지정하시면 되고  
근데 컴포넌트는 JSX를 return 한다는게 문제입니다. return 타입에 대체 뭘 기입해야하죠

```js
type AppProps = {
  name: string,
};

function App(props: AppProps): JSX.Element {
  return <div>{message}</div>;
}
```

props 파라미터는 어떻게 생겼는지 조사해서 알아서 타입지정해주면 되고  
return 타입은 JSX.Element 써주시면 됩니다. 근데 생략해도 자동으로 타입지정됩니다.

## state 문법 사용시 타입지정

state 만들 땐 그냥 자동으로 타입이 할당되어서 걱정할 필요는 없습니다.  
state 타입이 나중에 변화할 수 있다고요? 그런 경우는 흔치 않겠지만 그러면 미리 지정하십시오.

```js
const [user, setUser] = (useState < string) | (null > "kim");
```

그냥 <> 열고 타입넣으시면 됩니다.  
Generic 문법을 이용해서 타입을 useState함수에 집어넣는 식으로 설정하면 됩니다.

## type assertion 문법 사용할 때

```js
let code: any = 123;
let employeeCode = <number> code; //안됩니다
```

assertion 하고 싶으면 as 또는 <> 쓰면 되는데  
리액트에서 컴포넌트로 오해할 수 있어서 꺾쇠 괄호는 리액트에서 쓰지않습니다.  
as 키워드만 씁시다.  
하지만 as 키워드는 타입스크립트 보안해제기 때문에 타입이 100% 확실할 때만 사용하도록 합시다.  
결론은 타입스크립트 쓴다고 뭔가 리액트 개발방식이 달라지는게 아니라  
함수 변수 정의부분 타입지정을 할 수 있다는 것만 달라집니다.  
"props엔 무조건 { name : string }만 들어올 수 있습니다"  
이런 문법을 작성하는게 끝이고 그냥 에디터 부가기능 수준일 뿐임  
여러분이 변수 함수 class 타입지정 하는 법을 잘 배우셨으면 누구나 응용가능합니다.

# array 자료에 붙일 수 있는 tuple type

array 자료에 타입을 지정하고 싶으면 string[] 이렇게 기입하라고 했습니다.  
하지만 보다 구체적으로 타입지정하고싶을 때가 있습니다.  
"첫 자료는 무조건 string, 둘째 자료는 무조건 number인 array"  
이런 것도 가능합니다. tuple 타입 쓰면 됩니다.

tuple type은 array에 붙일 수 있는 타입인데  
자료의 위치까지 정확히 지정할 수 있는 타입입니다.

```js
let 멍멍이: [string, boolean];
멍멍이 = ["dog", true];
```

[ ] 괄호 안에 타입 적으시면 tuple type이 됩니다.  
[ ] 안에 차례로 세부 타입을 기입하면 됩니다.  
그럼 정말 첫 자료는 무조건 string, 둘째 자료는 무조건 boolean만 허용해주고 다른게 들어오면 에러로 잡아줍니다.

## Tuple 응용 : rest parameter

```js
function 함수(...x: string[]) {
  console.log(x);
}
```

함수 정의할 때 파라미터 왼쪽에 점3개 붙이면 rest parameter라고 했습니다.  
"여기에 파라미터가 몇 개 들어올지 아직 몰라요~" 라는 뜻으로 사용하는 파라미터입니다.  
x 자리에 입력한 파라미터들은 array에 담겨오기 때문에 array 처럼 타입지정을 해주는게 일반적입니다.  
근데 tuple을 이용해서 타입지정을 해주는 것도 가능

```js
function 함수(...x: [string, number]) {
  console.log(x);
}
함수("kim", 123); //가능
함수("kim", 123, 456); //에러
함수("kim", "park"); //에러
```

rest parameter를 엄격하게 사용가능합니다.  
일반 파라미터 2개 넣는 것과 기능상 다를 바는 없는데  
차이는 rest parameter 쓰시면 파라미터가 전부 array에 담겨서 오는게 차이입니다.

## tuple 안에도 옵션가능

```js
type Num = [number, number?, number?];
let 변수1: Num = [10];
let 변수2: Num = [10, 20];
let 변수3: Num = [10, 20, 10];
```

물음표 넣어서 옵션이라고 표현가능합니다.  
하지만 이런 코드는 어떻습니까.

```js
type Num = [number, number?, number];
```

이거 말이 됩니까  
array 중간에 있는 자료는 옵션이라고요?  
중간을 빼고 만들 수도 없고 뭔가 논리적으로 이상합니다.

그래서 ? 옵션기호는 뒤에만 붙일 수 있습니다.  
물음표 2개 쓰고 싶으시면 뒤에서 2개만 붙일 수 있음  
물음표 100개 쓰고 싶으시면 뒤에서 100개만 붙일 수 있음

## array 두개를 spread 연산자로 합치는 경우 타입지정은?

```js
let arr = [1, 2, 3];
let arr2 = [4, 5, ...arr];
```

점 3개 spread 연산자를 사용하면 array의 괄호를 벗겨준다고 했습니다.  
그래서 위 예제처럼 쓰면 array 두개를 합치고 그럴 수 있습니다.  
근데 그럼 arr2 타입지정은 대체 어떻게 해야할까요 tuple 타입으로요.  
arr 자리에 자료 몇개가 들어올지도 모르는 상황이라면요

```js
let arr = [1,2,3]
let arr2 :[number, number, ...number[]] = [4,5, ...arr]
```

tuple 타입에 점3개 붙이면 됩니다.  
점3개 붙이면 아직 여기에 몇개의 자료가 들어올지 모른다는  
rest parameter 같은 느낌으로다가 활용가능합니다.

```js
let arr2 :[number, number, ...number[]] = [4,5,6,7,8,9,10]
```

rest parameter 처럼 맘껏 집어넣을 수 있습니다.

# 외부 파일 이용시 declare & 이상한 특징인 ambient module

님들이 코드를 짜다보면 외부 자바스크립트 파일을 이용하는 경우가 있을 겁니다.  
import 문법으로 가져다가 쓰면 되는데  
근데 안타깝게도 그 파일이 Typescript로 작성된게 아니라 JavaScript 로 작성된 파일이면  
무수한 에러가 여러분들을 기다리고 있습니다.  
당연히 타입지정이 안되어있으니까요.

예를 들어서 data.js 라는 파일이 있다고 칩시다.  
그리고 index.ts 파일에서 저기 있던 a라는 변수를 쓰고싶으면 어떻게 합니까.

```js
data.js;

var a = 10;
var b = { name: "kim" };

index.ts;

console.log(a + 1);
```

간단한 html css js 개발시엔 index.html에 저 파일 두개를 첨부하면 됩니다.

```js
(index.html)

<script src="data.js"></script>
<script src="index.js"></script>  //index.ts에서 변환된 js 파일
```

이게 원래 프론트엔드에서 import하는 방법입니다.  
아무튼 콘솔창에 11 잘 나옵니다.  
근데 타입스크립트 파일에선 a가 정의가 안되었다고 에러가 나는군요.

왜냐면 저거 `<script>` 태그로 자바스크립트 파일 2개를 연결해서 쓰는건 html 입장이고  
ts 입장에서는 a라는 변수를 import 해온 적이 없기 때문에 에러가 나는 것입니다.  
컴파일러가 징징대는걸 제압해봅시다.

## declare 키워드로 재정의하기

declare 쓰면 이미 정의된 변수나 함수를 재정의할 수 있습니다.  
물론 타입도 포함해서 재정의가 가능합니다.

```js
(data.js)

var a = 10;
var b = {name :'kim'};


(index.ts)

declare let a :number;
console.log(a + 1);
```

declare 우측에 let a 같은 변수 정의 집어넣으면 됩니다.  
"a 라는 변수를 이 파일에서 잠깐 정의해주세요" 라는 뜻입니다.  
"a 라는 변수는 분명 어딘가에 있긴 하니까 그만 징징대세요" 라는 뜻이 더 맞습니다.  
그래서 js파일 변수를 가져다 쓰는데 '타입에러나 변수없다는 에러'를 방지하고 싶으면  
징징대는걸 막을 수 있는 공갈젖꼭지 declare 키워드를 씁시다.

(특징) declare 이게 붙은 코드들은 js로 변환되지 않습니다.  
그냥 컴파일러에게 힌트를 주는 역할의 코드라서 그렇습니다.

그래서 자바스크립트로만 작성된 외부 라이브러리들을 쓸 때도 나름 유용합니다.  
타입스크립트 버전이 없다면 직접 declare로 타입작성하면 됩니다.  
ts 파일들은 변수만들 때 타입까먹어도 자동으로 타입지정이 되어있으니 굳이 쓸 이유는 없습니다

근데 여러분이 tsconfig.json 안에 allowJs 옵션을 true로 켜두면  
js파일도 타입지정이 알아서 implicit 하게 됩니다.  
리액트 같은 프로젝트에서 유용

## TS의 이상한 특징 : Ambient Module

타입스크립트가 제공하는 이상한 기능이 있습니다.  
바로 import export 없이도 타입들을 다른 파일에서 가져다쓸 수 있다는 점인데  
그니까 a.ts 에 있던 변수나 타입정의를 b.ts 에서도 아무런 설정없이 그냥 가져다쓸 수 있습니다.

```js
data.ts;

type Age = number;
let 나이: Age = 20;

index.ts;

console.log(나이 + 1); //가능
let 철수: Age = 30; //가능
```

지금 같은 폴더에 아무데나 data.ts 만들고 타입, 변수 이런거 넣어보십시오.  
그럼 index.ts에서도 data.ts에 있던 변수와 타입을 자유롭게 사용가능합니다.
import export 그런거 안해도 같은 폴더에 있는 ts 파일은 그냥 사용가능합니다.  
왜냐면 그냥 ts 파일에 대충 입력한 변수와 타입들은 전부 global 변수 취급을 받습니다.  
전역으로 쓸 수 있는 파일을 전문용어로 ambient module 이라고 칭합니다.  
(타입스크립트에서 let name 이라는 이름의 변수생성이 안되는 이유를 여기서 찾을 수 있습니다. 어디선가 기본으로 let name 이미 쓰고있음)

반면에 import 혹은 export 키워드가 들어간 ts 파일은 다릅니다.  
import / export 키워드가 적어도 하나 있으면 그 파일은 로컬 모듈이 되고  
거기 있는 모든 변수는 export를 해줘야 다른 파일에서 사용가능합니다.  
그래서 타입스크립트 파일이 다른 파일에 영향끼치는걸 막고싶으면 export 키워드를 강제로 추가하면 됩니다.

```js
data.ts;
export {};
type Age = number;
let 나이: Age = 20;
index.ts;

console.log(나이 + 1); //불가능
let 철수: Age = 30; //불가능
```

이러면 data.ts에 있던 파일은 더 이상 글로벌 모듈 (ambient module)이 되지 않으며  
다른 파일에서 함부로 가져다쓸 수 없습니다. import export 써야함

대체 왜 이딴식인가 생각을 해보면 옛날 js 파일과의 호환성 때문에 그런 것 같은데 약간 불편할 때가 많습니다.

## delare global

ts 파일에 import export 문법이 없으면 글로벌 모듈이 됩니다.  
ts 파일에 import export 문법이 있으면 로컬 모듈입니다.  
근데 로컬 모듈에서 갑자기 전역으로 변수를 만들고 싶을 때가 있습니다.  
실은 별로 없는데 아무튼 있다고 가정합시다.  
따로 설정 없어도 프로젝트 내의 모든 파일에서 이용가능한 타입을 만들고 싶으면 이걸 붙여서 만드시면 됩니다.

```js
declare global {
  type Dog = string;
}
```

이런 코드를 로컬 파일에 적어두시면 모든 파일에서 Dog 타입을 이용가능합니다.  
이것도 일종의 namespace 문법인데 여기다 적은건 global 이라는 이름의 namespace에 추가된다고 보시면 됩니다.  
그리고 global namespace는 모든 파일에서 기본적으로 이용이 가능하고요.  
아무튼 로컬 모듈에서 전역변수 만들고 싶을 때 씁시다.

# d.ts 파일 이용하기

declare 키워드를 배웠으면 이제 d.ts 파일도 이해가 갑니다.  
코드짜다보면 어디선가 d.ts 파일이 등장합니다.  
이 파일은 타입만 저장할 수 있는 파일형식입니다. (그래서 definition의 약자인 d가 들어감)  
그리고 자바스크립트로 컴파일되지 않습니다.

어디다 쓰냐면

1. 타입정의만 따로 저장해놓고 import 해서 쓰려고

2. 프로젝트에서 사용하는 타입을 쭉 정리해놓을 레퍼런스용으로 사용

## 타입만 따로 d.ts에 모아놓으려면

1. 어쩌구.d.ts 라고 작성하신 파일은 타입 정의만 넣을 수 있습니다.  
   type 키워드, interface 이런걸로요.  
   함수의 경우 함수에 { } 중괄호 붙이기는 불가능합니다. 파라미터 & return 타입만 지정가능합니다.

```js
export type Age = number;
export type multiply = (x: number, y: number) => number;
export interface Person {
  name: string;
}
```

2. 정의해둔 타입은 export 해서 써야합니다.  
   d.ts 파일은 ts 파일이 아니기 때문에 그냥 써도 ambient module이 되지 않습니다.  
   그래서 export를 추가해줘야 다른 ts 파일에서 가져다쓸 수 있습니다.

3. 한 번에 많은 타입을 export 하고 싶은 경우 namespace에 담든가  
   아니면 자바스크립트 배운 사람처럼 import \* as 어쩌구 문법을 쓰십시오.

d.ts 파일을 레퍼런스용으로 쓰려면  
ts파일마다 d.ts 파일을 자동생성하시면 됩니다.

```js
(tsconfig.json)

{
    "compilerOptions": {
        "target": "es5",
        "module": "es6",
        "declaration": true,
    }
}
```

tsconfig에다가 declaration 옵션을 true로 바꿔주면 됩니다.  
그럼 저장시 자동으로 ts파일마다 d.ts 파일이 옆에 생성됩니다.  
열어보시면 타입정의만 쭉 정리되어서 담겨있음

```js
index.ts;

let 이름: string = "kim";
let 나이 = 20;
interface Person {
  name: string;
}
let 사람: Person = { name: "park" };
```

이렇게 작성하면

```js
(index.d.ts)

declare let 이름: string;
declare let 나이: number;
interface Person {
    name: string;
}
declare let 사람: Person;
```

이런 파일이 생성됩니다. (안생기면 import 문법 다 지워보셈)  
어쩌구.d.ts 라는 파일엔 어쩌구.ts 파일에 있는 모든 변수와 함수 타입정의가 들어있습니다.  
자동생성의 경우 따로 수정하거나 그럴 순 없어서 (수정해도 어쩌구.ts 저장시 자동생성이라 의미없음)  
그냥 레퍼런스용으로 사용하거나 하시면 됩니다.

## export 없이 d.ts 파일을 글로벌 모듈 만들기

원래 d.ts 파일은 import export 없어도 로컬모듈입니다.  
그래서 다른 ts파일에서 import를 해서 쓸 수 밖에 없는데  
이게 귀찮으면 d.ts를 글로벌 모듈로 만들어보십시오.  
파일이 많아지면 섞이기 때문에 굳이 왜 하나 싶지만

프로젝트 내에 types/common 이런 폴더 두개를 만드시고  
tsconfig.json 파일에 `"typeRoots": ["./types"]` 이런 옵션을 추가해주면 됩니다.  
이러면 ts 파일 작성할 때 타입없으면 자동으로 여기서 타입 찾아서 적용해줌

- 다만 이걸 쓸 경우 파일명.d.ts 자동생성 기능은 끄는게 좋을 듯 합니다.

- d.ts 파일명은 기존 ts 파일명과 안겹치게 작성하는게 좋습니다.

- 하지만 이런거 쓰다가 로컬 타입과 저런 글로벌 타입이 겹치면 어쩌쥬 역시 import export가 안전합니다.

## 유명한 JS 라이브러리들은 d.ts 파일을 제공

님들이 jQuery 혹은 Bootstrap 애니메이션 라이브러리를 가져다 쓴다고 합시다.  
근데 이건 당연히 .js 로 끝나는 자바스크립트 파일이겠죠?  
그럼 당연히 ts 파일에서 쓰려면 에러가 나겠죠?

그럼 여러분들이 직접 jquery.d.ts 파일을 만들어서 타입정의를 하시거나 그러면 되는데  
근데 유명한 라이브러리들은 전부 d.ts 파일을 누군가 만들어 놨기 때문에  
그거 찾아서 다운받거나 하시면 됩니다  
[Definitely Typed](https://github.com/DefinitelyTyped/DefinitelyTyped) 여기가 주로 쓰는 라이브러리 모아놓은 github repository인데  
아마 대부분 라이브러리의 타입정의 파일을 찾을 수 있을 겁니다.

근데 요즘은 npm으로 라이브러리 설치시 타입스크립트 타입정의된 버전을 따로 찾아서 설치하실 수 있습니다.  
[TypeSearch](https://www.typescriptlang.org/dt/search?search=) 여기 들어가면 타입정의된 npm 패키지 찾아볼 수 있음  
타입이 정의된 라이브러리를 npm으로 설치하면  
node_modules/@types 이런 경로에 타입이 설치됩니다.  
그리고 타입스크립트 컴파일러는 자동으로 여기 있는 타입 파일을 참고해서 타입을 가져오게 되어있습니다.

(참고) "typeRoots" 옵션이 있을 경우 node_modules/@types 폴더를 추가해야합니다. 아니면 그냥 "typeRoots" 옵션을 제거해보자

혹은 따로 타입부분만 설치할 수도 있습니다.  
예를 들어 타입파일이 제공되지 않는 jQuery 같은 경우

```
npm install --save @types/jquery
```

이렇게 강제로 설치하시면 이제 jQuery 문법 사용할 때 타입정의 안하셔도 됩니다.

# implements

interface는 object 타입지정할 때 쓴다고 배워봤습니다.  
하지만 용도가 하나 더 있는데 class 타입을 확인하고 싶을 때도 interface 문법을 사용할 수 있습니다.  
근데 implements 키워드도 필요함

class를 하나 만들어봅시다.

```js
class Car {
  model: string;
  price: number = 1000;
  constructor(a: string) {
    this.model = a;
  }
}
let 붕붕이 = new Car("morning");
```

class Car 로부터 생산되는 object들은 model과 price 속성을 가지게 됩니다.  
근데 class가 model, price 속성을 가지고 있는지 타입으로 확인하고 싶으면 어떻게합니까.  
그럴 경우 interface + implements 키워드로 확인하면 됩니다.

```js
interface CarType {
  model: string;
  price: number;
}

class Car implements CarType {
  model: string;
  price: number = 1000;
  constructor(a: string) {
    this.model = a;
  }
}
let 붕붕이 = new Car("morning");
```

class 이름 우측에 implements를 쓰고 interface 이름을 쓰면  
"이 class가 이 interface에 있는 속성을 다 들고있냐"  
라고 확인이 가능합니다.  
그래서 다 갖고 있으면 별말 안해주고  
혹여나 빠진 속성이 있으면 에러로 알려줍니다.

implements는 타입지정문법이 아닙니다  
implements라는건 interface에 들어있는 속성을 가지고 있는지 확인만하라는 뜻입니다.  
class에다가 타입을 할당하고 변형시키는 키워드는 아닙니다.

```js
interface CarType {
  model: string;
  tax: (price: number) => number;
}

class Car implements CarType {
  model; ///any 타입됨
  tax(a) {
    ///a 파라미터는 any 타입됨
    return a * 0.1;
  }
}
```

지금 CarType을 implements 했냐고 써봤습니다.
근데 CarType에 있던 model : string 이런게 반영되는건 아닙니다. class 안에서의 model은 any 타입임  
class 함수도 마찬가지로 함수에 있던 number 타입이 전혀 반영되지 않습니다.  
결론은 implements는 class의 타입을 체크하는 용도지 할당하는게 아님을 명심합시다.

# object index signatures

object 자료에 타입을 미리 만들어주고 싶은데

1. object 자료에 어떤 속성들이 들어올 수 있는지 아직 모르는 경우

2. 타입지정할 속성이 너무 많은 경우

index signatures를 사용하면 편리합니다.

이렇게 작성해봅시다.

```js
interface StringOnly {
  [key: string]: string;
}

let obj: StringOnly = {
  name: "kim",
  age: "20",
  location: "seoul",
};
```

StringOnly 라는 interface를 하나 만들었습니다.  
근데 안에 타입을 적을 때 [어쩌구 : string] : string 이렇게 적으면  
모든 string으로 들어오는 key값에 할당되는 value는 string 이어야합니다~ 라는 타입이 됩니다.  
쉽게 말하면 { 모든속성 : string } 이라는 뜻과 동일합니다.  
이제 이 object에 들어오는 모든 속성은 우측에 string을 가져야합니다.  
딱 코드 한 줄로 모든 속성 타입지정이 가능해서 편리할 수 있습니다.

```js
interface StringOnly {
  age: number; ///에러남 ㅅㄱ
  [key: string]: string;
}

interface StringOnly {
  age: string; ///가능
  [key: string]: string;
}
```

[ ] 이 문법은 다른 속성과 함께 사용할 수 있지만  
{ 모든 속성 : string, age : number } 이건 뭔가 논리적으로 말이 되지 않아 금지시킵니다.

```js
interface StringOnly {
  age: number; ///가능
  [key: string]: string | number;
}
```

이건 가능합니다.  
{ 모든속성 : string | number, age : number } 이렇게 해주면 논리적으로 말이 됩니다.

## array 형태도 가능

님들 자바스크립트에서 array와 object는 실은 별 다를게 없는 같은 자료형입니다.

```js
let obj = {
  0 : 'kim'
  1 : '20',
  2 : 'seoul'
}
console.log(obj[2]) //이러면 'seoul' 출력됨
```

위 코드를 보면 array랑 똑같이 사용가능하죠?  
아무튼 object로도 array 처럼 사용가능  
(object 자료도 대괄호쳐서 안에 있는 데이터 뽑을 수 있습니다)

```js
interface StringOnly {
  [key: number]: string,
}

let obj :StringOnly = {
  0 : 'kim'
  1 : '20',
  2 : 'seoul'
}
```

[ ] 여기 안에 key값의 타입을 number 로 지정할 수도 있습니다. (대괄호 안엔 string 또는 number만 가능)  
그럼 이제 object의 키값이 숫자로 들어오는 경우 value로 string을 가져야한다는 타입입니다.  
쉽게 말하면 { 모든숫자속성 : string } 이라는 뜻과 동일합니다.  
그래서 array처럼 쓰고싶은 object가 있으면 저렇게 타입지정도 가능하다는 소리입니다.  
숫자 key만 넣을거면 그냥 array + tuple 타입 쓰는게 더 직관적일 수 있습니다.

## Recursive Index Signatures

여러분 이런거 타입지정할 생각 해본 적 있습니까

```js
let obj = {
  "font-size": {
    "font-size": {
      "font-size": 14,
    },
  },
};
```

object 안에 object 안에 object가 들어있습니다.  
실제로는 별로 쓸모가 없어보이지만 아무튼 중첩된 object들을 한 번에 타입지정하려면 어떻게 해야할까요.  
직접 interface 안에 {} 이걸 3번 중첩되게 만드셔도 되긴 하지만

```js
interface MyType {
  "font-size": {
    "font-size": {
      "font-size": number,
    },
  };
}
```

귀찮을 경우 이런 테크닉을 사용할 수 있습니다.

```js
interface MyType {
  "font-size": MyType | number;
}

let obj: MyType = {
  "font-size": {
    "font-size": {
      "font-size": 14,
    },
  },
};
```

MyType을 만들었는데  
'font-size' 속성은 MyType 이거랑 똑같이 생겼다고 타입을 만들었습니다.  
그럼 이제 타입 귀찮게 길게 중첩해서 안써도 됩니다.  
그리고 object자료가 4중첩 5중첩 X중첩되어도 대응가능

# object 타입 변환기 만들기

가끔 object를 다른 타입으로 변환하고 싶을 때가 있습니다.  
모든 속성들에 문자가 들어오는 타입을 갑자기 숫자가 들어오도록 바꾸고 싶을 때요.  
그럴 땐 처음부터 타입을 다시 작성하는 것이 아니라 mapping을 이용하면 됩니다.

그 전에 간단히 keyof 연산자를 짚고 넘어가야합니다.  
keyof는 object 타입에 사용하면 object 타입이 가지고 있는 모든 key값을 union type으로 합쳐서 내보내줍니다.  
object의 key를 뽑아서 새로운 타입을 만들고 싶을 때 사용하는 연산자입니다.  

```js
interface Person {
  age: number;
  name: string;
}
type PersonKeys = keyof Person;   //"age" | "name" 타입됩니다
let a :PersonKeys = 'age'; //가능
let b :PersonKeys = 'ageeee'; //불가능
```

Person 타입은 age, name 이라는 key를 가지고 있었기 때문에   
이제 PersonKeys는 정말 'age' | 'name' 타입이 됩니다.  
literal type이네요  

```js
interface Person {
  [key :string]: number;
}
type PersonKeys = keyof Person;   //string | number 타입됩니다
let a :PersonKeys = 'age'; //가능
let b :PersonKeys = 'ageeee'; //가능
```

Person 타입은 모든 문자 key를 가질 수 있기 때문에  
keyof Person 이렇게 하면 string 타입이 됩니다.  
실은 string | number 타입이 됩니다. object key값에 숫자 넣어도 문자로 치환되어서 그렇습니다.  
[key :number] 이렇게 숫자만 들어올 수 있다고 해놓으면 keyof Person 이렇게 하면 number 타입이 됩니다.  

(참고) 쌩자바스크립트는 .keys() 이런거 붙이면 key값을 array자료로 담아줍니다.

## Mapped Types

가끔 object안에 있는 속성들을 다른 타입으로 한번에 싸그리 변환하고 싶을 때가 있습니다.  
그럴 때 유용한 타입변환기를 만들어봅시다.  

```js
type Car = {
  color: boolean,
  model : boolean,
  price : boolean | number,
}; 
```

팀원이 만든 쓰레기같은 Car 타입이 있다고 합시다.  
여기 있는 모든 속성을 string 타입으로 바꾸고 싶어진 것입니다.  
속성이 3개면 직접 다시 만들어도 되겠지만 100개면 어쩌죠? 매우 귀찮습니다.   

```js
type Car = {
  color: boolean,
  model : boolean,
  price : boolean | number,
};

type TypeChanger <MyType> = {
  [key in keyof MyType]: string;
};
```

그럴 땐 TypeChanger 처럼 생긴 타입을 만들어봅시다.  
그냥 쓰는 법이 정해져있는데  
[ 자유작명 in keyof 타입파라미터 ] : 원하는 타입  
이렇게 입력하시면 object 타입을 입력했을 때 속성명은 그대로지만 다른 타입으로 변환해주는 변환기를 만들 수 있습니다.  

in 키워드는 왼쪽이 오른쪽에 들어있냐라는 뜻이고  
keyof는 오브젝트 타입에서 key값만 union type으로 뽑아주는 역할이라 머리쓰면 이해는 될듯요  

```js
type Car = {
  color: boolean,
  model : boolean,
  price : boolean | number,
};

type TypeChanger <MyType> = {
  [key in keyof MyType]: string;
};

type 새로운타입 = TypeChanger<Car>;

let obj :새로운타입 = {
  color: 'red',
  model : 'kia',
  price : '300',
}
```

이렇게 하면 이제 새로운타입은 color, model, price 속성을 가지고 있으며 전부 string 타입이 됩니다.  
key 값이 100개 있는 object 타입을 변경할 일이 있으면 쓰도록 합시다.   

# 조건문으로 타입만들기 & infer

타입만들 때 초보처럼 type Age = string 이렇게 하드코딩하는 법만 배워봤습니다.  
근데 if 조건문처럼 "조건에 따라서 이럴 경우 string, 저럴 경우 number"이런 식으로 타입지정도 가능합니다.  
하지만 자주 쓰는 내용은 아니기 때문에 어짜피 다음날 까먹습니다.  
이런게 있다고 기억해두고 나중에 필요하면 찾아서 쓰는게 좋은 방법입니다.   

자바스크립트 기본 문법 중에 삼항연산자라는게 있습니다.  
if문 대용품인데 평소에 if가 들어갈 수 없는 곳들에 간략하게 if문을 넣을 수 있는 방법입니다.  

```
조건문 ? 참일때실행할코드 : 거짓일때실행할코드
3 > 1 ? console.log('맞아요') : console.log('아님')
```
이렇게 if문처럼 사용합니다.  
기본 문법 잠깐 짚어봤습니다.  

## 조건부로 타입만들기

예를 들면 이런 코드가 있다고 칩시다.  

```js
type Age<T> = T;
이러면 이제 Age<number> 이렇게 쓰면 그 자리에 number가 남습니다.
```

(타입변수에도 타입파라미터 넣기 가능)

근데 이걸 이렇게 바꿔봅시다.  
"타입파라미터 자리에 string 타입을 집어넣으면 string 부여해주시고 그게 아니면 전부 unknown 부여해주셈"   
if문을 쓰자는 겁니다. 만약 T가 string이면 string, 그게 아니면 unknown 를 남기도록요   

타입 조건식은 주로 extends 키워드와 삼항연산자를 이용합니다.  
"extends는 왼쪽이 오른쪽의 성질을 가지고 있냐" 라는 뜻으로 사용할 수 있기 때문에  
나름 조건식 용도로 사용가능합니다. 비유하자면 수학에서 쓰는 ⊂ 이런 기호 역할이겠군요  

```js
type Age<T> = T extends string ? string : unknown;
let age : Age<string> //age는 string 타입
let age2 : Age<number> //age는 unknown 타입
```

그래서 이렇게 썼습니다.  
"T라는 파라미터가 string 성질 가지고 있냐? 그러면 string 남기고 아니면 unknown 남겨라"  
그랬더니 정말 `<string>` 집어넣으면 string, `<number>` 이렇게 집어넣으면 unknown을 남겨줍니다.  
이게 if문 쓰는 방법입니다.  
아직 타입이 확실하지 않은 <타입파라미터> 다룰 때 많이 사용하겠죠?  

Q. 그럼 파라미터로 array 자료를 입력하면 array의 첫 자료의 타입을 그대로 남겨주고,  
array 자료가 아니라 다른걸 입력하면 any 타입을 남겨주는 타입은 어떻게 만들면 될까요?  

```js
let age1 :FirstItem<string[]>;
let age2 :FirstItem<number>; 
```

이러면 age1의 타입은 string, age2의 타입은 any가 되어야합니다.  
FirstItem이라는 타입을 알아서 만들어봅시다.  

```js
type FirstItem<T> = T extends any[] ? T[0] : any 

let age1 :FirstItem<string[]>;
let age2 :FirstItem<number>; 
```

이러면 정말 age1의 타입은 string, age2의 타입은 any가 됩니다.  

## infer 키워드

조건문에 사용할 수 있는 특별한 infer 키워드가 있습니다.  
infer 키워드는 지금 입력한 타입을 변수로 만들어주는 키워드입니다.  
평상시에 굳이 쓸 이유는 없는데 나오면 읽을 줄은 알아야하니 간단히 알아보도록 합시다.   

```js
type Person<T> = T extends infer R ? R : unknown; 
type 새타입 = Person<string> // 새타입은 string 타입입니다 
```

1. infer 키워드는 조건문 안에서만 사용가능합니다.  

2. infer 우측에 자유롭게 작명해주면 타입을 T에서 유추해서 R이라는 변수에 집어넣어라~ 라는 뜻입니다.  

그래서 위의 예제에서 `<string>` 이렇게 타입파라미터자리에 string 집어넣으면 R은 string이 됩니다.  

3. R을 조건식 안에서 맘대로 사용가능합니다.  

이런 식으로 타입파라미터에서 타입을 추출해서 쓰고싶을 때 쓰는 키워드라고 보시면 됩니다.   
근데 무슨 용도로 쓰는지 알아야 나중에 코드짤 때 활용이 가능하기 때문에 어디다 쓰냐면   

1. array 안에 있던 타입이 어떤 타입인지 뽑아서 변수로 만들어줄 수 있습니다.

```js
type 타입추출<T> = T extends (infer R)[] ? R : unknown; 
type NewType = 타입추출< boolean[] > // NewType 은 boolean 타입입니다 
```
이런 식으로도 사용할 수 있는데 
(infer R)[] 이렇게 하면 array가 가지고 있던 타입부분만 쏙 뽑아서 R 변수에 할당할 수 있습니다.  

2. 함수의 return 타입이 어떤 타입인지 뽑아서 변수로 만들어줄 수 있습니다.  

```js
type 타입추출<T> = T extends ( ()=> infer R ) ? R : unknown; 
type NewType = 타입추출< () => number > // NewType은 number 타입입니다 
```

이런 식으로도 사용할 수 있는데   
타입파라미터에 <함수>를 집어넣었습니다. 그 타입파라미터에 있는 return 타입을 쏙 뽑아서 R이라는 변수에 담는 코드입니다.  
일정한 규칙이 있다기 보다 그냥 타입을 추출하는 식으로 이해하면 되겠습니다.   

실은 이런 것도 직접 만들어쓸 필요는 없고  
ReturnType<> 이런 예약 타입이 있는데 여기에 함수타입 집어넣으면 return 타입만 뽑아서 알려줌   
