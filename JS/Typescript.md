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
이런 메세지를 보면 1. 타입을 하나로 Narrowing 해주거나 2. Assert 해주거나 둘 중 하나 해주면 됩니다.

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


