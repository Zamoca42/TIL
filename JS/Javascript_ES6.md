# this 키워드

1. 그냥 쓰거나 일반 함수 안에서 쓰면 window 객체를 가리킴

```js
console.log(this); //출력 : {Window}
```

2. 오브젝트 내 함수안에서 쓰면 그 함수를 가지고 있는 오브젝트를 뜻함

```js
var 오브젝트 = {
  data: "Kim",
  함수: function () {
    console.log(this);
  },
};

오브젝트.함수(); // 출력 : {data: "Kim", 함수 : f}
```

1,2번째는 같은 이야기입니다.  
자바스크립트는 항상 window오브젝트를 상위로 가지고있기때문에 window는 생략되어있습니다.  
그래서 1번에서 가리키는 this의 오브젝트는 window가 됩니다.

3. 오브젝트 생성기계 안에서 쓰면 새로 생성되는 오브젝트를 뜻함

```js
function 기계() {
  // constrctor
  this.이름 = "Kim"; // instance
}
```

자바 스크립트에서 오브젝트를 여러개 만들고 싶은 경우  
오브젝트를 복사하는게 아니라 constructor라는걸 만들어서 사용합니다.  
constructor는 오브젝트를 복사해서 생성해주는 기계입니다.  
여기서 `this.이름`은 기계로부터 새로 생설될 오브젝트를 의미합니다.

```js
function 기계() {
  this.이름 = "Kim";
}
var 오브젝트 = new 기계();
```

이렇게 new키워드를 이용하면 새로운 오브젝트를 꺼낼 수 있습니다.

4. 이벤트리스너내에서 사용하면 this는 e.currentTarget을 의미

```js
document.getElementById("버튼").addEventListener("click", function (e) {
  console.log(this);
});
```

여기서 this를 입력하면 e.currnetTarget라는 의미입니다.  
e.currentTarget은 지금 이벤트가 동작하는 곳을 뜻합니다.

```js
<button id="버튼">버튼</button>
```

위에서 `getElementById('버튼')`을 입력했으니 현재의 e.currentTarget은 html의 버튼을 의미합니다.

# Arrow function 문법

함수 본연의 기능으로는

1. 코드들을 기능으로 묶을 때 사용
2. 입출력 기계를 만들고 싶을 때 사용

여기서 Arrow Function은 함수 본연의 입출력기능을 직관적으로 표현해줍니다.

```js
function 더해주세요(x) {
  return x + 2;
}
```

이렇게 일반 함수로 입출력 기능을 표현할 수 있지만

```js
var 두배만들기 = (x) => {
  return x * 2;
};
```

Arrow Function은 직관적으로 표현가능합니다.

또한 파라미터가 하나라면 소괄호를 생략 가능합니다

```js
var 두배만들기 = (x) => {
  return x * 2;
};
```

여기서 중괄호 안에 코드가 한줄이라면 중괄호도 생략가능하고 return도 생략 가능합니다.

```js
var 두배만들기 = (x) => x * 2;
```

추가로 arrow function을 쓰면 내부에서 this값을 쓸 때 밖에 있던 this값을 그대로 사용합니다.

일반 함수에서의 this는 오브젝트 내 함수안에서 쓰면 그 함수를 가지고 있는 오브젝트를 뜻한다고 했었습니다.

```js
var 오브젝트1 = {
  함수: function () {
    console.log(this);
  },
};

오브젝트1.함수();
```

여기서는 오브젝트1이 콘솔창에 출력됩니다.

Arrow Function에서 this는 외부에 있는 this를 가져옵니다

```js
var 오브젝트1 = {
  함수: () => {
    console.log(this);
  },
};

오브젝트1.함수();
```

여기서 오브젝트1 위의 코드에서 this가 없으므로 window오브젝트를 출력합니다.  
Arrow Function을 사용하는 것이 항상 장점은 아닙니다.  
내가 예측하던 this값과 달라질 수도 있으니 단점이 될 수 있습니다.  
this의 뜻이 달라지는 것 처럼 일반 function과 용도가 완전 같지 않기 때문에  
일반 function을 항상 대체할 수 있는 문법이 아닙니다. 그것만 주의합시다.

# 변수의 Hoisting 현상

자바스크립트는 변수나 함수를 선언하면 Hoisting이라는 현상이 일어납니다.  
자바스크립트는 변수나 함수의 선언부분을 변수의 범위 맨 위로 강제로 끌고가서 가장 먼저 해석합니다.  
그게 Hoisting입니다.

예를 들어봅시다.

```js
function 함수() {
  console.log("hello");
  var 이름 = "Kim";
}
```

이렇게 함수 내에서 변수를 만들었다고 칩시다.  
근데 자바스크립트가 이 코드를 해석하는 순서는 이렇게 됩니다.

```js
function 함수() {
  var 이름;
  console.log("hello");
  이름 = "Kim";
}
```

변수의 선언 부분을 강제로 변수의 범위 맨 위로 끌고가서 해석하고 지나갑니다.  
우리 눈에 보이진 않지만 자바스크립트는 코드 동작 순서가 이렇습니다.  
암튼 이게 Hoisting 현상입니다.  
함수를 만들어도 똑같고, 변수를 let, const로 만들어도 똑같습니다.

# 문자를 다루는 Template literals

기존 자바스크립트에서는 문자열을 다룰 때 따옴표를 주로 사용했었습니다.  
ES6에서는 따옴표 대신 backquote혹은 backtick(`)이라는 기호를 사용해서 문자를 만드는데  
여러 장점이 있습니다.

1. 문자 중간 엔터키 입력이 가능합니다.

자바스크립트 문자열은 문자 중간에 엔터키치시면 안됩니다.  
하지만 백틱으로 문자를 만드시면 엔터키가 자유롭게 가능합니다.

```js
var 문자 = `안녕  
하세요`;
```

2. 문자 중간에 변수를 집어넣을 때 편리합니다.

자바스크립트 문자열은 문자 중간에 변수를 넣고 싶은 경우 문자를 쪼개서 + 기호로 넣어야합니다.  
하지만 백틱으로 문자를 만드시면 문자 중간에 ${변수명} 이렇게 쉽게 넣을 수 있습니다.

```js
var 이름 = "손흥민";
var 문자 = `안녕하세요 ${이름} 입니다`;
```

그래서 자바스크립트 문자로 HTML을 작성할 때도 유용합니다.

```js
var 문자 = `
<div>
  <div>
    ${변수명}
  </div>
</div>`;
```

## tagged literal

ES6는 tagged literals라고 해서 함수로 문자 해체분석기능을 만들어줄 수도 있습니다.  
문자 중간중간에 있는 단어 순서를 바꾸거나 변수를 제거하거나 할 때 유용합니다.

```js
var 변수 = "손흥민";

function 해체분석기() {
  return 10;
}

해체분석기`안녕하세요 ${변수} 입니다`;
```

맨 마지막줄에서 함수를 실행시킬 때 소괄호가 아니라 문자를 이용해서 함수를 실행시킬 수 있습니다.  
실행할 함수이름을 쓰시고 소괄호 대신 `백틱` 문자를 붙여주시면 됩니다.  
그럼 함수가 실행됩니다. 위의 예제코드에선 해체분석기()라는 함수가 실행되고 있습니다.

왜 이렇게 사용하냐면  
함수뒤에 `문자`를 붙여 실행하면 그 `문자열`을 해체분석할 수 있기 때문입니다.  
해체분석용 함수를 한번 만들어봅시다.

```js
var 변수 = "손흥민";

function 해체분석기(문자들, 변수들) {
  console.log(문자들);
  console.log(변수들);
}

해체분석기`안녕하세요 ${변수} 입니다`;
```

함수의 파라미터 두개를 추가해줍니다.  
이제 이 함수는 막줄처럼 `문자열`을 이용해서 실행시키면 그 `문자열` 해체분석역할을 할 수 있습니다.  
첫째 파라미터 문자들은 `백틱` 내의 순수 문자만 골라서 Array로 만들어놓은 파라미터이고,  
둘째 파라미터 변수들은 `백틱` 내의 ${} 변수를 담는 파라미터입니다.  
(백틱 내에 변수가 2개 3개다 그러면 파라미터를 뒤에 더 추가해주시면 됩니다)  
이제 이 파라미터들로 `문자열`을 재조합하거나 분석할 수 있습니다.

```js
var 변수 = "손흥민";

function 해체분석기(문자들, 변수들) {
  console.log(문자들[1] + 변수들);
}

해체분석기`안녕하세요 ${변수} 입니다`;
```

그럼 이 코드는 실행하면 콘솔창에 뭐가 출력될까요?  
문자들을 모아놓은 Array중 1번째 문자 + 변수를 출력해줄 겁니다.  
그래서 '입니다손흥민' 이라는 문자가 출력됩니다.  
이렇게 ``백틱 내의 문자들을 해체해서 내 맘대로 다시 나열할 수 있게 도와주는 함수를 제작한 것입니다.

# Spread Operator(...)

마침표를 연달아서 3개... 찍으시면 그게 spread operator라는 문법입니다.  
한글로는 펼침연산자이렇게 번역가능한데  
무슨 역할을 하냐면
"괄호제거 해주는 연산자" 입니다.  
Array에 붙여보도록 합시다.

```js
var 어레이 = ["hello", "world"];
console.log(어레이);
console.log(...어레이);
```

그럼 어레이라는 array에 붙어있던 괄호를 제거해줍니다.  
3번줄처럼 spread operator를 붙여서 출력해보시면  
괄호가 제거된 'hello', 'world'만 콘솔창에 출력됩니다.  
이게 spread operator의 기능입니다.

그렇다면 array 두개를 합치고 싶으면 어떻게 할까요?

```js
var a = [1,2,3];
var b = [4,5];
var c = [여기엔 1,2,3,4,5 가 들어오게 만들려면?];
```

spread operator를 사용하시면 매우 쉽습니다.

```js
var a = [1, 2, 3];
var b = [4, 5];
var c = [...a, ...b];
```

이렇게 한 뒤에 c라는 어레이를 출력해보면 `[1,2,3,4,5]`가 되어있습니다.  
`...` 연산자를 이용해서 괄호를 없앤 a와 b를 집어넣는다는 소리입니다.  
어레이 합치기 완성입니다.

그럼 어레이 복사의 경우도 알아봅시다.

```js
var a = [1, 2, 3];
var b = a;

console.log(a);
console.log(b);
```

등호 `=` 를 이용하시면 쉽게 a에 있던 값을 b에 집어넣을 수 있습니다.  
그런데 자바스크립트에선 복사를 이렇게 하시면 큰일납니다.  
등호로 복사를 하시면 a와 b 변수는 `[1,2,3]`을 각각 따로 하나씩 가진게 아니라
`값 공유`가 일어납니다.  
그래서 a라는 array를 수정하면 b도 똑같이 바뀌는 신기한 버그가 일어납니다.

(나중에 자료형배울 때 다룰 것이지만 왜 그러냐면 등호쓰시면 값을 복사한게 아니라 `[1,2,3]` 값이 저기있어요~ 라고 가리키는 화살표를 복사하신 것입니다.)

그래서 값을 공유하지 않고 각각 독립적인 값을 저장하도록  
array를 복사하시려면 옛날엔 이상한 방법을 많이 썼는데  
요즘은 spread를 이용하시면 되겠습니다.

```js
var a = [1, 2, 3];
var b = [...a];

console.log(a);
console.log(b);
```

spread를 이용해서 a값의 괄호를 제거해준 다음에 다시 괄호를 씌우는 겁니다.  
그렇게 하시면 아까처럼 a와 b 변수의 값 공유가 일어나지 않습니다.

spread operator로 object 합치기/복사도 할 수 있습니다.

```js
var o1 = { a : 1, b : 2 };
var o2 = { c : 3, 그리고 o1에 있는거 전부.. }
```

o2를 만들고 싶은데 o1에 있던 내용들을 그대로 가져다가 추가하고 싶습니다.  
그럼 어떻게 해야되냐면 고민하지말고 spread operator를 떠올리시면 됩니다.  
이 연산자는 대괄호 뿐만아니라 중괄호도 제거해줍니다.  
그래서 이렇게 쓰시면

```js
var o1 = { a: 1, b: 2 };
var o2 = { c: 3, ...o1 };
console.log(o2);
```

o2라는 오브젝트를 출력해보면 a, b, c키값이 다 들어있습니다.  
왜냐면 o1오브젝트를 spread 연산자를 이용해 괄호를 벗겨서 추가했기 때문입니다.  
오브젝트 shallow copy도 비슷한 방식으로 합니다.  
(강의에선 deep copy라고 한거같은데 deep copy는 오브젝트 안의 오브젝트까지도 엮임현상없이 카피하는걸 뜻합니다. shallow는 그냥 맨 위의 오브젝트하나만 카피하는걸 뜻합니다)

오브젝트의 key값 중복이 발생하면 어떻게될까요?

```js
var o1 = { a: 1, b: 2 };
var o2 = { a: 3, ...o1 };
console.log(o2);
```

o2를 o1항목을 추가해서 만들고 싶은데 a라는 키값이 이미 있는겁니다.  
이렇게 a라는 값이 중복이 발생하면 무조건 뒤에 오는 a가 이깁니다.  
그래서 출력해보면 a : 1 이라는 자료가 담겨져있습니다.

Spread operator 나머지 활용방법을 알아봅시다.

array를 파라미터 형태로 집어넣을 때 씁니다.

일단 예시를 들기 위해 함수를 하나 만들어봅시다.

```js
function 더하기(a, b, c) {
  console.log(a + b + c);
}
더하기(1, 2, 3);
```

파라미터를 3개 받아와서 전부 더해주는 더하기라는 함수를 만들어봤습니다.  
그런데 여기 파라미터를 집어넣을 때  
직접 1,2,3이라고 작성해서 넣는게 아니라  
이미 존재하는 array에 있던 내부 자료들을 쏙 집어넣고 싶으면 어떻게하나요?  
그니까 예를 들면...

```js
function 더하기(a, b, c) {
  console.log(a + b + c);
}
```

```js
var 어레이 = [10, 20, 30];
```

어레이라는 자료 안에 있는 모든 숫자 10,20,30을 더하기() 함수의 파라미터로 집어넣으려면 어떻게 해야합니까.

```js
더하기(10, 20, 30);
```

이렇게 직접 손으로 적거나

```js
더하기(어레이[0], 어레이[1], 어레이[2]);
```

이렇게 하거나 해야겠죠?
근데 그게 귀찮으시면 spread 연산자를 쓰시면 됩니다.

```js
function 더하기(a, b, c) {
  console.log(a + b + c);
}

var 어레이 = [10, 20, 30];
더하기(...어레이);
```

그러면 출력했을 때 10, 20, 30을 더해준 결과가 잘 출력됩니다.

spread 연산자가 없던 시절엔 이런 식으로 작성했었습니다.

```js
function 더하기(a, b, c) {
  console.log(a + b + c);
}

var 어레이 = [10, 20, 30];
더하기(...어레이); //요즘방식
더하기.apply(undefined, 어레이); //옛날방식
```

apply라는 이상한 함수를 뒤에 붙여서 실행을 했었는데 이게 뭔지 자세히 알아보도록 합시다.  
나중에 객체지향 문법같은거 배우실 때 가끔 등장하는 함수들이니까요.

## apply, call 함수가 뭔지 알아보자

일단 예시를 들기 위해 오브젝트를 두개 만들어봅시다.

```js
var person = {
  인사: function () {
    console.log(this.name + "안녕");
  },
};

var person2 = {
  name: "손흥민",
};
```

person이라는 오브젝트에는 인사라는 함수를 만들어 넣었고  
person2는 보잘것없이 그냥 name : '손흥민' 이라는 자료만 넣었습니다.  
그런데 person에 만들어놓은 멋진 person.인사()라는 함수를 person2에서도 쓰고 싶습니다.  
그럼 어떻게 해야할까요?

person2에다가 직접 인사()라는 함수를 코딩해서 집어넣으면 되겠죠?  
근데 그게 불가능한 경우가 가끔 있습니다.  
그럴 때 apply를 쓰시면 됩니다.  
apply는 이 함수를 실행하는데.. 저기 오브젝트에다가 적용해서 실행해주세요~ 라는 뜻입니다.

그래서 한번 시도해봅시다.

```js
var person = {
  인사: function () {
    console.log(this.name + "안녕");
  },
};

var person2 = {
  name: "손흥민",
};

person.인사.apply(person2);
```

맨 마지막줄에 적은 코드가 뭔 의미냐면  
person.인사()라는 함수를 쓰는데 person2라는 오브젝트에 적용해서 실행해라
또는 person.인사()라는 함수를 쓰는데 person2라는 오브젝트에 있는 함수처럼 실행해라~ 라는 뜻입니다.

apply 함수의 사용법은

```js
실행할함수.apply(적용할곳);
```

이라고 보시면 됩니다.
이제 apply만 기억해주시면 여러가지 유용한 함수들을 내가 원하는 곳에 붙여서 쉽게 실행가능합니다.  
근데 이거랑 아주 똑같은 기능을 하는 함수가 하나 더 있습니다.

```js
var person = {
  인사: function () {
    console.log(this.name + "안녕");
  },
};

var person2 = {
  name: "손흥민",
};

person.인사.apply(person2);
person.인사.call(person2);
```

apply와 call은 실행 결과도 똑같고 사용법도 똑같습니다.  
하지만 차이점이 하나 있는데, 내가 person.인사()에 파라미터를 넣어서 실행하고 싶은 경우에는

```js
person.인사.apply(person2, 파라미터);
person.인사.call(person2, 파라미터);
```

이렇게 실행하셔야하는데  
이 때 apply는 파라미터를 `[array]`로 한꺼번에 집어넣을 수 있고
call은 그냥 1,2,3 이렇게 일반 함수처럼 만 집어넣을 수 있습니다.

```js
var person = {
  인사: function () {
    console.log(this.name + "안녕");
  },
};

var person2 = {
  name: "손흥민",
};

person.인사.apply(person2, [1, 2, 3]);
person.인사.call(person2, 1, 2, 3);
```

파라미터 집어넣는 방법만 좀 차이가 있지 아무튼 call, apply의 실행내용은 똑같습니다.
apply함수는 저렇게 어레이 내의 데이터를 파라미터로 한꺼번에 집어넣을 수 있다는 유용한 기능을 제공하기 때문에  
옛날 고대의 개발자들이 파라미터가 많은 함수를 만들 때 자주 사용했습니다.

그럼 이제 아까 함수에 array 집어넣는 예제가 이해가 가기 시작합니다.

```js
function 더하기(a, b, c) {
  console.log(a + b + c);
}

var 어레이 = [10, 20, 30];
더하기(...어레이); //요즘방식 넣기
더하기.apply(undefined, 어레이); //옛날방식 넣기
```

더하기.apply(undefined, 어레이)
무슨 뜻이냐면
더하기() 함수를 실행하는데 undefined에 적용해서 실행해주시고요 파라미터로 어레이를 집어넣어주세요~ 라는 뜻입니다.
이러면 편법같은 느낌이 들지만 array를 풀어헤쳐서 파라미터로 집어넣으실 수 있습니다.

# 함수 업그레이드하기 (default parameter/arguments)

함수를 만들 때 파라미터값을 실수로 안적었을 경우  
파라미터에 기본값(default 값)을 줄 수 있습니다.  
이렇게 사용하시면 됩니다.

```js
function 더하기(a, b = 10) {
  console.log(a + b);
}

더하기(1);
```

위 코드를 실행하면 11이 뜹니다.  
지금 더하기() 함수는 파라미터를 두개 입력할 수 있습니다.  
하지만 1이라는 파라미터 하나밖에 쓰지 않았습니다.  
그럴 때 저렇게 b = 10 선언해뒀던 default 파라미터값인 10이 b에 할당되게 됩니다.  
그래서 콘솔창에 a + b가 11이 출력되게 되는 것입니다.

default 파라미터를 주고 싶으면 저렇게 파라미터 선언하실 때 등호로 입력해주시면 됩니다.  
그럼 파라미터가 정의되지 않았을 때 등호 오른쪽 값이 발동됩니다.  
default 파라미터로 별게 다 들어갈 수 있습니다.

```js
function 더하기(a, b = 2 * 5) {
  console.log(a + b);
}

더하기(1);
```

수학 연산자도 사용가능합니다. b 자리에 파라미터가 없으면 2 \* 5라는 값을 할당해줍니다.

```js
function 더하기(a, b = 2 * a) {
  console.log(a + b);
}

더하기(3);
```

심지어 default 파라미터엔 함수입력도 가능합니다.

```js
function 임시함수() {
  return 10;
}

function 더하기(a, b = 임시함수()) {
  console.log(a + b);
}

더하기(3);
```

위 코드는 실행하면 13이 출력됩니다.  
b자리에 파라미터가 들어오지 않으면 임시함수()를 실행한 값을 b 파라미터에 할당해줍니다.  
임시함수()를 실행하면 그 자리에 10이 남습니다.  
(return 10이 그 뜻입니다)  
그래서 console.log(3 + 10)을 실행해줍니다.

## 함수의 arguments

함수의 모든 파라미터들을 전부 한꺼번에 싸잡아서 다루고 싶은 경우가 있습니다.  
그럴 땐 arguments라는 키워드를 활용하시면 됩니다.  
함수 안에서 쓸 수 있는 미리 정의된 키워드 혹은 변수인데  
한번 써보도록 합시다.

```js
function 함수(a, b, c) {
  console.log(arguments);
}

함수(2, 3, 4);
```

그러면 콘솔창에 `[2,3,4]`를 담은 array 비슷한 자료가 출력됩니다.  
arguments는 즉, 모든 입력된 파라미터를 [ ] 안에 싸매주는 고마운 키워드였던 것이었습니다.  
이제 여러분이 파라미터들을 한꺼번에 다루고 싶을 때 자주 활용해주시면 됩니다.  
예를 들면 이런 경우가 있겠군요.

콘솔창에 모든 파라미터를 하나씩 출력해주고 싶은 경우

```js
function 함수(a, b, c) {
  console.log(arguments[0]);
  console.log(arguments[1]);
  console.log(arguments[2]);
}

함수(2, 3, 4);
```

그런데 조금 더 확장성있게 반복문을 쓴다면

```js
function 함수(a, b, c) {
  for (var i = 0; i < arguments.length; i++) {
    console.log(arguments[i]);
  }
}

함수(2, 3, 4);
```

이러면 되겠군요.  
약간 편리하게 파라미터들을 다룰 수 있는 문법이었습니다.  
하지만 ES6문법 부터는 파라미터를 더 쉽게 다룰 수 있는 rest 파라미터라는 문법이 등장합니다.

# Rest parameter

함수를 만들 때 ...이라는 기호를 파라미터 왼쪽에 추가가능합니다.

```js
function 함수2(...파라미터들) {
  console.log(파라미터들);
}

함수2(1, 2, 3, 4, 5, 6, 7);
```

위 코드를 실행해보면 파라미터들이라는 변수를 출력해줍니다.  
파라미터들이라는 변수는 모든 파라미터를 [] array 안에 담고 있습니다.  
이게 바로 ES6 환경에서 쓸 수 있는 rest 파라미터입니다.  
원하는 파라미터 왼쪽에 ... 기호를 붙여주시면  
"이 자리에 오는 모든 파라미터를 [] 중괄호로 감싸준 파라미터" 라는 뜻입니다.

그래서 출력해보면 저렇게 `[1,2,3,4,5,6,7]`이 나오는 것이고요.  
그 자리에 입력한 모든 파라미터(1,2,3,4,5,6,7)를 중괄호에 감싸주는게 rest 파라미터입니다.

`...`을 다른 자리에 사용한다면

그 자리에 있는 파라미터를 [] 안에 감싸준다고 했으면  
다른 자리에 쓰면 어떻게 될까요?

```js
function 함수2(a, b, ...파라미터들) {
  console.log(파라미터들);
}

함수2(1, 2, 3, 4, 5, 6, 7);
```

위 코드를 실행해보면 `[3,4,5,6,7]`이 출력됩니다.  
첫 두개의 파라미터는 a, b로 쓰는데  
a,b 그 뒤에 나오는 모든 파라미터는 중괄호에 감싸서 파라미터들이라는 array가 됩니다.  
파라미터 종류가 많을 경우 arguments 문법보다 다루기 쉽고 간단해서 자주 사용합니다.

### 쓰기 전 주의사항

rest(나머지) 파라미터라는 뜻대로 나머지 부분에만 사용가능합니다.  
그니까 항상 파라미터가 여러개면 rest는 항상 마지막 파라미터로 넣으셔야합니다.

```js
function 함수2(a, ...파라미터들, b){
  console.log(파라미터들)
}
```

이렇게 사용하시면 에러난다는 소리입니다.

```js
function 함수2(a, ...파라미터들, ...파라미터들2){
  console.log(파라미터들)
}
```

이것도 안됩니다. 2개 이상 사용할 수 없습니다.

### 간단한 연습문제

모든 파라미터를 전부 하나씩 콘솔창에 출력해주는 함수를 만들고 싶습니다.

어떻게 해야할까요?

```js
function 함수(a, b, c) {
  console.log(a);
  console.log(b);
  console.log(c);
}

함수(1, 2, 3);
```

근데 파라미터를 4개 5개 오바해서 입력한 경우엔 제대로 실행이 되지 않는 멍청한 함수가 완성되었을 뿐입니다.  
파라미터 갯수 제한없이 똑같은 기능을 실행해주는 함수를 만들려면 어떻게 해야할까요?

```js
function 함수(...rest){
  console.log(rest[0]);
  console.log(rest[1]);
  console.log(rest[2]);
  (...이하 쭉쭉쭉)
}

함수(1,2,3);
```

이렇게 하면 되는거 아닙니까. 근데 파라미터가 몇개 들어갈지 모르기 때문에

console.log()부분을 반복문을 이용하면 만들 수 있습니다.

```js
function 함수(...rest) {
  for (var i = 0; i < rest.length; i++) {
    console.log(rest[i]);
  }
}

함수(1, 2, 3, 4, 5, 6, 7, 8);
```

rest라는게 모든 파라미터를 `[]` 안에 담아서 array처럼 만들어주는 고마운 변수기 때문에  
반복문을 저렇게 돌릴 수 있습니다.  
그럼 이제 함수에 파라미터를 몇개를 넣든 간에 콘솔창에 계속 출력을 해줄 수 있습니다.

영단어 rest가 뜻이 쉬다가 아니라 여분, 나머지 이런 뜻이잖아요.  
그러니 나머지 파라미터라고 외우시면 그나마 머릿속에 기억이 잘 될 것 같습니다.

# Reference data type

객체지향 문법 시작 전 반드시 알아야할 reference, primitive data type을 알아봅시다.

## Primitive/Reference data type

자바스크립트의 자료형 (문자, 숫자, array, object 등)은 자료형을 크게 2개로 분류합니다.  
Primitive & reference라고 분류하는데  
Primitive data type들은 그냥 별건 없고 자료 자체가 변수에 저장되는 자료들입니다.  
문자, 숫자 자료형들이 대표적인 primitive data type들입니다.

```js
var name = "john";
var age = 20;
```

이렇게 문자나 숫자 자료형은 문자나 숫자가 변수에 직접 저장된다는 얘기입니다.  
반면에 Array, Object 자료형은 reference data type에 속합니다.  
reference data type은 자료를 변수에 직접 저장하는게 아닌,  
자료가 저쪽에 있습니다 라는 화살표 (레퍼런스)를 변수에 저장합니다.  
말이 어려우니 예를 들어봅시다.

```js
var 사람 = { name: "Kim" };
```

여러분 방금 { name : 'Kim' } 이라는 자료를 변수에 저장했습니다.  
하지만 변수에 저장된건 { name : 'Kim' } 이게 아닙니다.  
"{ name : 'Kim' }이 저기 저장되어있습니다"라는  
{ name : 'Kim' } 값을 가리키는 화살표가 저장이 되어있을 뿐입니다.  
Kim이라는 데이터가 변수에 저장된게 아닙니다. Kim이라는게 저기 있습니다~
라는 **정보만 저장**할 뿐입니다.

그래서 이런 reference만 저장되는 array, object 자료형을 reference data type이라고 합니다.

## 함수를 이용해 object를 변경하면 어떻게 될까

object를 = 등호를 이용해 조작하면 뭔가 일이 일어나는거 같으니까  
이번엔 한번 함수를 이용해서 object 조작 기계를 만들어보겠습니다.

```js
var 이름1 = { name: "김" };

function 변경(obj) {
  obj = { name: "park" };
}

변경(이름1);
```

말되죠? 변경() 이라는 함수를 만들었는데,  
이 함수는 뭔가 오브젝트를 입력하면 오브젝트 내용을 { name : 'park' } 으로 재할당해주는 함수입니다.  
그래서 이름1을 집어넣어서 실행해봤습니다.  
근데 실행해봐도 이름1은 바뀌지 않습니다. 왜 그럴까요?  
왜그러냐면 여러분 함수 만들 때 파라미터라는거 만들잖아요.  
파라미터는 일종의 변수처럼 생성되고 사라지는 존재라고 보시면 됩니다.

그냥 쉽게말하면 var 변수에요 변수

```js
(인간의 시점)

var 이름1 = { name : '김' };
function 변경(obj){
  obj = { name : 'park' };
}
변경(이름1);



(자바스크립트의 시점)

var 이름1 = { name : '김' };
function 변경(obj){
  obj = { name : 'park' };
}
변경(var obj = 이름1);
```

자바스크립트가 파라미터를 만들고 사용할 땐 대충 맨 밑줄처럼 만든다고 생각하시면 됩니다.  
(실제 이런 문법이 있는건 아니지만요)  
obj라는 파라미터자리에 이름1이라는 변수를 집어넣으시면  
var obj = 이름1 이렇게 파라미터형 변수를 만든겁니다.

```js
var 이름1 = { name: "김" };

function 변경(obj) {
  obj = { name: "park" };
}

변경(이름1);
```

위와 같은 예제지만 다른 패턴입니다.

obj 라는 변수에 이름1이라는 { object } 를 등호로 복사해서 넣으면 어떻게 되나요?  
obj, 이름1 이 두개 변수는 서로 같은 화살표를 갖게 되며 { name : '김' } 값을 공유합니다.  
그런데 함수 내부를 잘 보시면 obj라는 변수는 obj = { name : 'Park' } 이렇게 재할당을 해주고 있죠?

이것은 obj라는 변수에 새로운 화살표를 재할당을 한 것이지  
실제 이름1이라는 변수는 전혀 건드리지 않고 있습니다.  
그래서 결국 이름1은 바뀌지 않는 것입니다.

저렇게 만들면 안되겠군요.

그럼 밑의 예제코드는 실행하면 콘솔창에 무엇이 출력될까요??

```js
var 이름1 = { name: "김" };

function 변경(obj) {
  obj.name = "park";
}

변경(이름1);
console.log(이름1);
```

등호로 복사해서 값 공유를 하는 것이 아닌 직접 obj.name을 이름1로 지정해주는 것이기 때문에 이름1이 김에서 park으로 바뀌게 됩니다.

# Object 생성기계인 constructor를 만들어 써보자

저번에 object 그냥 복사하면 큰일난다고 배웠는데  
이번엔 object를 안전하게 많이 복사해 만들 수 있는 constructor라는 문법을 배워봅시다.

자바스크립트로 학생 리스트를 만들어야합니다.

```js
var 학생1 = { name : 'Kim', age : 15 };
var 학생2 = { name : 'Park', age : 15 };
...
```

이렇게 쭉 30명을 만들어야합니다. 어떻게 하는게 가장 빠른 방법일까요?  
당연히 오브젝트를 직접 중괄호쳐서 하드코딩 30개 하는 것 보다는  
비슷한 오브젝트들이니 복사를 하는게 좋을 것 같습니다.  
근데 = 등호를 이용해서 var 학생2 = 학생1 복사하면 큰일나니  
오브젝트를 복사해서 찍어낼 수 있는 새로운 문법을 이용해보도록 합시다.

```js
//var 학생1 = { name : 'Kim', age : 15 };

function 기계() {
  this.name = "Kim";
  this.age = 15;
}
```

object 자료 복사 기계만들 땐 function이라는 함수만드는 키워드를 빌려서 이용하시면 됩니다.  
function을 하나 만드시고 거기 안에 this.name과 this.age를 집어넣어주시면 됩니다.  
이게 바로 오브젝트 생성 기계입니다.  
this는 새로생성되는 오브젝트를 뜻합니다. (그걸 멋진 개발용어로 인스턴스라고 합니다)

그렇다면 this.name = 'Kim'이 무엇일까요?

그냥 간단한 object 자료 추가/수정문법 아닙니까.  
새로생성되는 오브젝트.name은 'Kim'을 넣어주세요~ 라는 뜻이었습니다.  
this를 이용해서 새로 복사될 object가 가질 값들을 디자인해놓으시면 됩니다.

이제 기계에서 새로운 오브젝트를 뽑고 싶으시면 이렇게 따라하시면 됩니다.

```js
//var 학생1 = { name : 'Kim', age : 15 };

function 기계() {
  this.name = "Kim";
  this.age = 15;
}

var 학생1 = new 기계();
var 학생2 = new 기계();
```

new라는 키워드를 쓰신 다음 오른쪽에 기계(constructor) 이름을 쓴다면  
기계로부터 새로운 오브젝트를 하나를 뽑아낼 수 있습니다.  
그리고 그걸 변수에 저장하시면 이제 자유롭게 오브젝트를 뽑아 쓰실 수 있는겁니다.

비슷한 + 독립적인 object 자료를 여러개 만들 때 코드의 양이 줄어듭니다.  
그래서 사용하는 문법입니다.  
특히 오브젝트안에 들어갈 내용이 복잡하고 많을 때 쌩코딩 하지말고 써보십시오.

오브젝트에 함수가 들어가야한다면  
예를 들면 모든 학생 오브젝트 안에 sayHi() 라는 함수를 추가해야한다면  
학생1.sayHi()라고 사용하시면 콘솔창에 "안녕하세요 'Kim'입니다"라고 이름이 포함된 인삿말을 출력해주어야합니다.  
어떻게 코드를 짜면 될까요?

```js
var 학생1 = {
    name : 'Kim',
    age : 15
    sayHi : function(){
        console.log('안녕하세요' + this.name + ' 입니다');
    }
};

학생1.sayHi();
```

이렇게 하면 되겠군요. (함수 안의 this.name이 뭔지 궁금하다면 this에 관한 이전 강의를 살펴봅시다)  
근데 학생1이라는 곳에다가만 하드코딩하는게 아니라  
앞으로 모든 학생들이 sayHi()를 쓸 수 있게 만들고 싶으면 어떻게 해야할까요?  
당연히 오브젝트 생성 기계에 추가하시면 되겠죠?

기계에 sayHi()를 추가해봅시다.

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
  this.sayHi = function () {
    console.log("안녕하세요" + this.name + " 입니다");
  };
}
var 학생1 = new 기계();
var 학생2 = new 기계();

학생2.sayHi();
```

기계에 저렇게 this.sayHi 를 추가하시면 이제 기계로부터 생성되는 모든 학생들이 sayHi()를 가지고 있게 됩니다.  
그럼 학생1, 학생2 전부 sayHi()를 쓸 수 있게됩니다.  
object 자료 안엔 함수도 넣을 수 있으니 그냥 당연한 소리입니다.

학생 오브젝트를 뽑을 때 각각 다른 name, age 값을 부여하고 싶다면  
함수엔 파라미터를 추가할 수 있음을 떠올리면 됩니다.

```js
function 기계(이름) {
  this.name = 이름;
  this.age = 15;
  this.sayHi = function () {
    console.log("안녕하세요" + this.name + " 입니다");
  };
}
var 학생1 = new 기계("Park");
var 학생2 = new 기계("Kim");
```

함수에 파라미터를 추가한다면 앞으로 기계라는 함수를 쓸 때마다  
파라미터자리에 뭔가 데이터를 넣어서 실행할 수 있는 것입니다.  
그래서 마지막줄 보시면 기계()를 쓸 때 데이터를 넣어봤습니다.

그 'Park' 이라는 데이터는 파라미터자리에 쏙 들어가서 함수가 실행되게 되며  
그럼 새로 생성되는 오브젝트의 name속성은 'Park'이 됩니다. (this.name = 'Park')  
그럼 이제

학생1은 { name : 'Park', age : 15 }  
학생2는 { name : 'Kim', age : 15 }

이렇게 출력되겠네요.  
생성되는 오브젝트마다 각각 다른 값을 부여하고 싶다면 저렇게 함수의 파라미터를 이용하시길 바랍니다.  
age도 바꾸고 싶다면 파라미터를 한개 더 추가하면 되겠군요.

간단 연습문제 : 쇼핑몰에 쓸 상품데이터를 오브젝트로 여러개 만들고 싶습니다.

```js
var product1 = { name: "shirts", price: 50000 };
var product2 = { name: "pants", price: 60000 };
```

위처럼 생긴 상품오브젝트들을 뽑아낼 수 있는 constructor를 제작해보세요.  
그리고 실제 상품 두개를 뽑아보십시오.

```js
function products(상품명, 가격) {
  this.name : 상품명,
  this.price : 가격
}

var product1 = new products('shirts', 50000)
var product2 = new products('pants', 60000)
```

Q2. 상품마다 부가세() 라는 내부 함수를 실행하면 콘솔창에 상품가격 \* 10% 만큼의 부가세금액이 출력되도록 하고 싶으면  
constructor를 어떻게 수정해야할까요?  
예를 들면 product1.부가세() 이렇게 쓰면 콘솔창에 5000이 출력되어야합니다.

```js
function products(상품명, 가격) {
  this.name : 상품명,
  this.price : 가격
  this.부가세 = function() {
    console.log(this.price * 0.1)
  }
}

var product1 = new products('shirts', 50000)
var product2 = new products('pants', 60000)
```

# Prototype

위에서 constructor로 생성해준 객체들을 객체지향 용어로 상속(inheritance)이라고 합니다.  
기계라는 constructor가 가진 name, age 속성들을 그대로 물려받아서 오브젝트를 하나 뽑아주는게  
뭐 재산 물려주는 상속과 비슷하다고 해서 상속이라고 부릅니다.

(그래서 상속해주는 것은 부모, 상속받는 오브젝트들은 자식이라고 많이 비유해서 불러요)

근데 자바스크립트엔 constructor 말고도 상속기능을 구현할 수 있는 장치가 하나 더 있습니다.  
prototype이라는 것인데 알아보도록 합시다.  
기계를 만드시면 prototype이라는 항목이 기계 안에 몰래 생성됩니다.

여러분이 만든 기계는 전부 prototype이라는 항목을 내부에 몰래 생성합니다.

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
}
var 학생1 = new 기계();
var 학생2 = new 기계();

console.log(기계.prototype);
```

자기 알게된 prototype이라는 비밀 공간은 왜 존재하고 어디에 쓰는 거냐면..  
이것이 바로 부모의 유전자역할을 해주는 일종의 비밀 공간이라고 보시면 됩니다.  
prototype은 자식들이 물려받을 수 있는 유전자라고 생각하시면 됩니다.  
기계.prototype은 기계의 유전자입니다.  
기계.prototype 에 뭔가 변수나 함수가 들어가있다면  
기계로부터 생성되는 새로운 오브젝트들(자식들)은 전부 그걸 그대로 물려받아 쓸 수 있습니다.

예를 들면 이렇게 됩니다.  
저번 시간 예제 코드에 prototype 어쩌구 한줄을 추가해보겠습니다.

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
}

기계.prototype.gender = "남";
var 학생1 = new 기계();
var 학생2 = new 기계();

console.log(학생1.gender); //'남'이 출력됩니다
```

제가 기계의 prototype이라는 곳에 { gender : '남' } 이라는 key/value 한쌍을 저장했습니다.  
(prototype은 저렇게 오브젝트 자료형 다루듯이 하면 됩니다)  
기계의 prototype, 즉 유전자에 gender : '남'이라는 데이터를 추가한 것입니다.

이제 학생1, 학생2 같은 기계로부터 생성되는 모든 자식들은 gender라는 속성을 사용할 수 있습니다.  
결론은 prototype 이라는 비밀 공간을 이용하시면 똑같이 상속기능을 만들 수 있습니다.

(참고)

- prototype에는 값을 여러개 부여할 수도 있고 심지어 함수도 집어넣으실 수 있습니다. object 자료처럼 다뤄주시면 됩니다.
- prototype에 추가된 데이터들은 자식들이 직접 가지는게 아니라 부모만 가지고 있습니다.

## Prototype 작동원리

왜 prototype에 추가한 데이터는 자식들이 자유롭게 가져다 쓸 수 있을까요?

자바스크립트는 오브젝트에서 데이터를 뽑을 때 확인하는 순서가 있습니다.
예를 들면

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
}
기계.prototype.gender = "남";
var 학생1 = new 기계();

console.log(학생1.gentder);
```

학생1.gender라고 사용하면 '남'이 출력되죠? 그 이유는..  
자바스크립트는 오브젝트에서 값을 출력할 때 이런 순서로 물어봅니다.

1.  학생1에 직접 gender라는 값이 있는가?
2.  그럼 부모 유전자에 gender라는 값이 있는가?
3.  그럼 부모의 부모 유전자에 gender라는 값이 있는가?
4.  그럼 부모의 부모의 부모의 유전자에 .. 그게 있는가?

자바스크립트는 이런 알고리즘으로 작동합니다.
그냥 쉽게말하자면 오브젝트에서 값을 뽑을 때

1. 내가 직접 가지고 있는지 검사
2. 내가 가지고 있지 않으면 부모 유전자들을 차례로 검사하는구나

라고 잘 기억해주시면 됩니다.  
그래서 학생1이라는 오브젝트가 gender라는 값을 가지고 있지 않지만  
부모의 유전자(기계.prototype) 에 있는 gender라는 걸 출력할 수 있는 이유입니다.

## Prototype 작동원리2

자바스크립트 array, object 들에는 붙일 수 있는 내장함수들이 많습니다.

sort, push, toString, map, forEach 등 이런 것들을 array에 붙여서 사용가능한데 혹시 그 이유가 궁금하지 않으셨습니까.

결론부터 말하자면 매우 쉽습니다.

```js
var arr = [1, 2, 3];
console.log(arr.toString()); //가능
```

내가 만든 array에 arr.toString() 이렇게 붙일 수 있는 이유는  
내가 만든 array의 부모 유전자가 toString()을 가지고 있기 때문입니다. (혹은 부모의 부모요)  
내가 만든 array는 부모 기계로 부터 뽑은게 아닌데 뭔소리하는 거냐고요?  
여러분 실은 array나 object 자료형 만드실 때 부모가 있긴 있습니다.

```js
var arr = [1, 2, 3];
var arr = new Array(1, 2, 3);
```

위 코드 두줄은 같은 완전 똑같은 의미입니다.  
위는 인간이 array 만드는 방식, 밑은 컴퓨터가 array 만드는 방식입니다.  
사람은 귀찮아서 [] 그냥 대괄호쳐서 만드는데 내부적으로는 저렇게 new 키워드를 항상 이용해서 array/object를 만들어줍니다.

그럼 new Array() 이게 뭔뜻일까요?

Array라는 기계로부터 자식을 하나 새로 뽑아주세요 라는 뜻 아닌가요?  
맞습니다.

그래서 Array로부터 생성된 자식들은 Array의 유전자에 부여되어있는 함수, 데이터들을 자유롭게 사용하실 수 있습니다.  
Array라는 기계의 유전자가 진짜 있는지 확인은 콘솔창에 출력해보시면 됩니다.

```js
console.log(Array.prototype);
```

이렇게 하면 뭐나옵니까. 여러분이 평소에 쓰던 sort, map, push, forEach 이런 것들이 등장합니다.  
그래서 Array의 자식들은 전부 이런 함수들을 쉽게 가져다 쓸 수 있었던 것입니다.  
Object 자료형도 똑같이 new Object() 이런 식으로 만들어주기 때문에 부모의 prototype에 있던 함수들을 자유롭게 사용가능합니다.  
이것이 내장함수들의 비밀이었습니다.

## Prototype의 특징

1. prototype은 constructor 함수에만 몰래 생성됩니다.

여러분이 일반 object, array 이런거 만들어도 거기엔 prototype이 없습니다.  
끝입니다.  
그럼 일반 object 같은걸 상속하고 싶으면 어떻게 하냐고요?  
constructor 함수를 만들던가.. 아니면 다음 시간에 알려주는 Object.create()를 쓰거나 class를 쓰거나 셋 중 하나 하시면 됩니다.

2. 내 부모님 유전자를 찾고 싶다면 **proto**를 출력해보시면 됩니다.

부모로부터 생성된 자식 object들은 **proto**라는 속성이 있습니다.  
이걸 출력해보시면 부모의 prototype이 출력됩니다.  
그래서 **proto**는 부모의 prototype과 같은 의미입니다.

진짜 그런지 한번 출력해봅시다.

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
}
var 학생1 = new 기계();
console.log(학생1.__proto__);
console.log(기계.prototype);
학생1.__proto__;

기계.prototype;
```

각각 출력해보시면 똑같은게 나오죠?  
아무튼 그래서 "**proto**는 부모 prototype을 의미한다" 라고 알아두시면 되겠습니다.  
그냥 **proto**는 내 부모 유전자가 뭔지 유전자 검사하고 싶을 때 쓸 수 있는 그런 값이라고 생각하시면 되겠습니다.

3. **proto**를 직접 등록하면 object끼리 상속기능을 구현가능합니다.

**proto**는 부모의 prototype을 의미한다 라고 했습니다.  
그럼 어떤 object에다가 **proto**를 강제로 하나 설정해버리면 어떻게 될까요?  
오 이런 부모님이 생겨버립니다.  
일종의 유전자 공학인데 한번 실험해봅시다.

```js
var 부모 = { name: "Kim" };
var 자식 = {};

자식.__proto__ = 부모;
console.log(자식.name);
```

지금 부모와 자식 object를 하나씩 만들었습니다.  
그리고 셋째줄에서 자식의 **proto**에 부모를 집어넣었습니다.  
그럼 자식의 부모 유전자는 { name : 'Kim' } 이라는 오브젝트가 되는 것입니다.  
그렇게 되면 자식은 이제 자식.name 속성을 자유롭게 사용할 수 있습니다.

상속기능 구현을 이렇게도 할 수 있군요.

4. 실은 콘솔창에 prototype 정보들이 항상 출력됩니다.

이거 여기 예제코드 적어놓으신 다음에  
콘솔창에서 학생1 한번 출력해보십시오.

```js
function 기계() {
  this.name = "Kim";
  this.age = 15;
}
기계.prototype.gender = "남";

var 학생1 = new 기계();
```

그럼 콘솔창에 name도 나오고 age도 나올 텐데  
이상한 `__proto__` 이런 것도 나옵니다.
**proto**가 뭐랬습니까. 부모의 유전자라고 했죠?  
그래서 이걸 항상 까보실 수 있습니다. 아마 기계.prototype이랑 똑같은 내용이 출력되겠죠.  
그리고 기계.prototype의 **proto**도 조회가능합니다. (기계.prototype의 부모 유전자요)

이렇게 쭉 내 부모의 부모까지 탐색할 수도 있습니다.  
탐색해보시면 모든 object 자료형의 조상은 Object() 라는 기계이며 (일명 Object.prototype)

모든 array 자료형의 조상도 Object()입니다. (중간에 Array()라는 부모도 있고요)  
모든 함수 자료형의 조상도 Object() 입니다.

(그래서 자바스크립트는 모든게 다 Object라고 말하는 것입니다.)

# ES5방식으로 쉽게 구현하는 상속기능(create)

prototype이니 this니 class니 뭐니 어렵다면 그냥 ES5 방식으로 하셔도 됩니다.  
ES5 출시 때 나온 Object.create()라는 신기한 문법이 하나 있는데  
내가 상속을 이용해서 오브젝트를 만들고 싶다면 이거보다 더 쉬운 문법이 없습니다.  
하지만 class문법에 밀려 인지도는 낮습니다.

```js
Object.create(부모object);
```

이렇게 사용하시면 이 자리에 오브젝트 자료형 하나가 남습니다.  
그리고 소괄호 안에 적은 부모object가 유전자(prototype)가 되는 것이고요.  
한번 예를 들어봅시다.

```js
var 부모 = { name: "Kim", age: 50 };
var 자식 = Object.create(부모);

console.log(자식.age); //50나옴
```

이렇게 쓴다는 소리입니다.  
그럼 자식이라는 object는 부모를 prototype으로 두게 됩니다.  
그럼 자식.name 해도 'Kim'이 출력되고요, 자식.age 해도 50이 출력됩니다.

자식이 성공적으로 부모 속성들을 상속했죠?  
상속기능 만들기 끝입니다. 매우 간단하고 쉽습니다.

그럼 자식이 age를 바꾸고 싶으면 어떻게 하죠?

자식놈은 50살이 아닌데 자꾸 age가 50이라고 하네요.  
이걸 20살로 바꿔봅시다.

```js
var 부모 = { name: "Kim", age: 50 };
var 자식 = Object.create(부모);
자식.age = 20;

console.log(자식.age); //20 나옴
```

그냥 자식이라는 object에 age : 20 이라는 값을 부여했을 뿐입니다.  
그럼 이제 자식.age 할 때마다 20이 출력됩니다.  
부모로부터 상속받은 50이라는 age가 출력되지 않는 이유는 뭐죠?

왜냐하면 오브젝트 자료형에서 특정 자료를 꺼낼 때 묻는 순서가 있다고 배웠습니다.

1. 자식이라는 object가 직접 age를 가지고 있으면 출력
2. 없으면 자식의 부모 prototype에 age가 있으면 출력
3. 거기도 없으면 부모의 부모 prototype을 뒤져서..
   이런 순서로 age를 출력합니다

그래서 지금 자식놈은 20이 나옵니다.

# ES6방식으로 구현하는 상속기능(class)

class 라는 문법이 있습니다.  
constructor, prototype 을 이용한 상속기능을 간지나게 만들 수 있게 도와주는 문법입니다.  
기존 function부터 시작하던 문법과 기능상 차이는 크게 없고 약간 더 보기쉽게 표현해줄 뿐입니다.  
어떻게 하는지 자세히 알아봅시다.

constructor 라는건 저번시간에 했기 때문에 다들 아시죠?  
오브젝트 뽑는 기계였습니다.  
ES6 class라는 신문법으로 constructor를 만드시려면 이렇게 따라치시면 됩니다.

```js
class 부모 {
  constructor() {
    this.name = "Kim";
  }
}

var 자식 = new 부모();
```

끝입니다. 예전 function 부모(){} 어쩌구 이렇게 기계를 만드는 문법과 똑같은 문법입니다.  
이제 new 키워드를 이용해서 방금 만든 부모라는 기계에서 오브젝트를 새로 생성할 수 있는 것이고요.  
constructor()라고 쓴 부분에 예전처럼 this.name 어쩌구 하시면 새로 생성되는 오브젝트들에 값을 부여할 수 있습니다.

상속가능한 함수를 추가하려면 어떻게 해야할까요?

예전에 sayHi 이런거 하면서 배웠던 두가지 방법이 있습니다.

1. 함수를 this.sayHi 이렇게 constructor 안에 추가하는 방법과

2. 기계의 prototype에 추가하는 방법이 있었죠?

1번은 똑같이 이렇게 하시면 되겠죠?

```js
class 부모 {
  constructor() {
    this.name = "Kim";
    this.sayHi = function () {
      console.log("hello");
    };
  }
}

var 자식 = new 부모();
```

그럼 새로생성되는 자식은 sayHi() 함수를 직접 가지게 되며 자유롭게 쓸 수 있습니다.

2번처럼 prototype에 추가하시려면

```js
class 부모 {
  constructor() {
    this.name = "Kim";
  }
  sayHi() {
    console.log("hello");
  }
}

var 자식 = new 부모();
```

이런 식으로 하시면 됩니다.  
오브젝트에 함수추가하듯 하시면 됩니다요.  
그럼 자식은 sayHi()라고 썼을 때 부모의 prototype에 있던 sayHi() 함수를 쓸 수 있습니다.  
(혹은 그냥 부모.prototype.sayHi = function(){} 이렇게 하셔도 되고요)

## 참고로 알아두는 Object.getPrototypeOf()

이 함수 안에 오브젝트를 넣으시면 부모 prototype을 출력해줍니다.
이 오브젝트가 대체 누구로부터 prototype을 상속받고 있는지를 알려주는 함수죠.  
**proto**라는 키워드와 비슷한 역할을 한다고 보시면 됩니다.

## constructor안에 파라미터 추가하기

ES6 방식으로 constructor 만들 때 파라미터를 추가하려면 이렇게 하시면 됩니다.

```js
class 부모 {
  constructor(이름, 나이) {
    this.name = 이름;
    this.age = 나이;
  }
}

var 자식 = new 부모("Park", 30);
```

이런 식으로 하시면 파라미터를 넣어서 constructor를 만들 수 있습니다.  
자식을 생성할 때 이제 파라미터 두개를 입력할 수 있겠군요.

prototype 내에 함수 여러개 추가할 때는 이렇게 하면 됩니다.

```js
class 부모 {
  constructor(이름, 나이) {
    this.name = 이름;
    this.age = 나이;
  }
  sayHi() {
    console.log("안녕");
  }
  sayHello() {
    console.log("안녕하세요");
  }
}

var 자식 = new 부모("Park");
```

이렇게 쭉 써주시면 prototype에 sayHi, sayHello 등 여러개 함수를 동시에 넣을 수 있겠군요.

# class를 상속한 class를 만들고 싶을 때 쓰는 extends

할아버지 class를 하나 만들었다고 칩시다.  
할아버지 class는 성과 이름이라는 속성을 가지고 있습니다.

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
}
```

그럼 이제 new 할아버지() 뭐 이런식으로 하면 새로운 object를 쉽게 생성할 수 있겠죠?  
그런데 이 class가 너무나도 유용한 나머지 이것과 유사한 class를 하나 더 만들고 싶습니다.  
그러면 직접 class를 하나 더 만들어서 내용을 복붙하면 되겠죠?  
하지만 class안에 복사할 내용이 너무나도 많으면 코드가 너무나도 길어집니다.

그래서 고대의 개발자들이 extends라는 문법을 만들었는데  
이걸 이용해서 class를 만드시면 기존에 있던 class의 내용을 그대로 복붙해서 만들어낼 수 잇습니다.

있어보이게 말하면 "다른 class를 상속해서 만들 수 있게 도와주는 문법"이죠.

그래서 할아버지 class를 상속하는 아버지 class를 만들어보겠습니다. 따라하세요.

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
}

class 아버지 extends 할아버지 {}
```

extends는 이렇게 쓰면 됩니다.  
그럼 이제 할아버지라는 class를 그대로 복붙한 아버지라는 class가 생성됩니다.  
진짜 class가 생겼는지 확인해보고 싶으면 new 아버지(); 이렇게 테스트 해보면 되겠죠?

new 아버지('만수'); 이렇게 하시면 성과 이름을 가진 object 자료가 하나 생성됩니다.  
할아버지랑 똑같은 class가 생겼죠?

이제 아버지라는 class에는 새로운 속성을 추가하고 싶으면  
당연히 아버지 constructor안에 내용을 추가하시면 됩니다.

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
}

class 아버지 extends 할아버지 {
  constructor() {
    this.나이 = 50;
  }
}
```

이렇게 하면 new 아버지() 했을 때 생성된 오브젝트들은 {성, 이름, 나이} 속성들을 가지겠군요.  
하지만 이러면 에러가 납니다.  
super를 써야된다고 에러가 나네요.  
그럼 super를 써주시면 됩니다.

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
}

class 아버지 extends 할아버지 {
  constructor() {
    super();
    this.나이 = 50;
  }
}
```

super()라는 이상한 함수는  
"extends로 상속중인 부모 class의 constructor()"를 의미합니다.  
쉽게 말하면 할아버지 class의 constructor() 이거랑 똑같다는 소리입니다.  
그래야 이제 에러없이 this.나이 이런걸 추가하실 수 있습니다.

근데 할아버지 class의 constructor()에는 name 파라미터를 입력할 수 있었죠?
그것도 똑같이 따라서 명시해주셔야 할아버지가 가진 모든 속성들을 정확히 상속받을 수 있습니다.

```js
class 할아버지{
  constructor(name){
    this.성 = 'Kim';
    this.이름 = name;
  }
}

class 아버지 extends 할아버지{
  constructor(name){
    super(name);
    this.나이 = 50;
  }
```

할아버지 constructor()에 name이라는 파라미터가 있던걸 그대로 아버지 constructor()에도 따라했습니다.  
(파라미터 작명은 자유롭게 가능합니다)  
이제 그럼 new 아버지(); 할 때 파라미터를 입력하면 this.이름 속성에 들어가게 되겠네요.  
그럼 예상해봅시다.  
위 코드 하단에 var a = new 아버지('만수'); 이렇게 적으면 a라는 변수는 어떤 내용을 가지고 있을까요?

1. a라는 변수는 아버지라는 class로부터 새로 생성된 오브젝트입니다.

2. 그래서 할아버지가 가지고 있던 성, 이름 그리고 아버지가 가지고 있던 나이를 전부 물려받았습니다.

3. 그리고 this.이름 자리에는 '만수'를 넣어 실행했습니다.

그래서 { 성 : 'Kim', 이름 : '만수', 나이 : 50 } 이라는 오브젝트가 됩니다.

할아버지 class 안에 함수를 추가한다면 아버지 class의 자식들도 물려받아 쓸 수 있을까요?

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
  sayHi() {
    console.log("안녕 나는 할아버지");
  }
}

class 아버지 extends 할아버지 {
  constructor(name) {
    super(name);
    this.나이 = 50;
  }
}

var a = new 아버지("만수");
```

그럼 이제 a라는 오브젝트는 sayHi()라는 함수를 쓸 수 있을까요?

- 쓸 수 있습니다.

a라는 오브젝트가 a.sayHi() 이렇게 사용한다면

1. a라는 오브젝트에 sayHi가 있는지 물어보고

2. 없으면 아버지.prototype에 sayHi가 있는지 물어보고

3. 없으면 할아버지.prototype에 sayHi가 있는지 물어보고

이런 식으로 sayHi를 실행하기 위해 부모님을 뒤져봅니다.  
근데 sayHi()라는건 할아버지.prototype에 추가된 함수이기 때문에  
a라는 오브젝트는 sayHi() 함수를 실행할 수 있습니다.

근데 sayHi()라는건 할아버지.prototype에 추가된 함수이기 때문에  
a라는 오브젝트는 sayHi() 함수를 실행할 수 있습니다.

근데 class간에 함수를 상속하고 싶으면 어떻게 할까요?

아버지라는 class에 함수를 만들고 싶습니다.  
근데 할아버지 class에 있던 sayHi()라는 함수가 너무나도 유용한 나머지  
이걸 그대로 아버지 class에 가져와서 활용하고 싶은 것입니다.  
그럴 때 어떻게 합니까?

이 때도 super를 쓰시면 됩니다.

```js
class 할아버지 {
  constructor(name) {
    this.성 = "Kim";
    this.이름 = name;
  }
  sayHi() {
    console.log("안녕 나는 할아버지");
  }
}

class 아버지 extends 할아버지 {
  constructor(name) {
    super(name);
    this.나이 = 50;
  }
  sayHi2() {
    console.log("안녕 나는 아버지");
    super.sayHi();
  }
}

var a = new 아버지("만수");
```

super라는걸 저렇게 prototype 함수 안에서 쓰시면 아까의 super와 약간 다른 의미가 됩니다.  
여기서의 super는 부모 class의 prototype을 의미합니다.  
super는 뜻이 두개입니다.

1. constructor 안에서 쓰면 부모 class의 constructor

2. prototype 함수 안에서 쓰면 부모 class의 prototype

2번은 참고로만 알아둡시다.

# getter, setter

많은 분들이 왜 쓰는지 궁금해하는 자바스크립트 getter, setter 문법을 알아봅시다.  
얕게 말하자면 오브젝트 내의 함수들을 괄호없이 쓸 수 있게 만들어주는 키워드인데  
깊숙히 들어가면 데이터의 무결성을 보존하기 위해 쓰는 키워드라고 보시면 됩니다.

요즘 원본 데이터는 immutable 해야한다 이런말 들어보셨습니까.

데이터를 수정하거나 출력할 때 직접 원본 데이터를 만지는게 아니라 함수로 간접적으로 다루는게 대세를 이루고 있는데  
거기에 합치되는 일종의 코딩 테크닉이라고 보시면 됩니다.

이걸 이해하려면 일단 object 데이터를 다루는 방법론에 대해 알아야합니다.

## 함수로 object 데이터를 꺼내는 방법

object 데이터를 하나 만들어봅시다. 여러분의 이름과 나이를 한번 저장해보십시오.

```js
var 사람 = {
  name: "Kim",
  age: 30,
};
```

그 다음에 여러분의 내년 나이를 출력해보고 싶으면 어떻게 할까요?  
사람.age + 1 이렇게 하면 될까요?  
맞습니다. 그런데 미래를 생각하는 개발자들은 내년 나이를 출력해주는 함수를 만들어 사용합니다.

```js
var 사람 = {
  name: "Kim",
  age: 30,
  nextAge() {
    return this.age + 1;
  },
};
```

이렇게 함수를 만들어놓으면  
사람.nextAge() 이렇게 사용하면 내년 나이가 출력되겠죠? 31이라고 출력되겠네요.  
이렇게 데이터를 끄집어내서 사용하는 방법이 요즘 유행입니다.

굳이 왜 이렇게 하냐면

- object 안의 데이터가 복잡할 수록 함수 만들어놓는게 데이터 꺼내기 쉽습니다.

- 내부에 있는 name, age 변수를 건드리지 않아서 실수를 방지할 수 있어서 안전합니다.

특히 매우 긴 object 안에 원하는 자료 몇개만 뽑고 싶을 때  
미리 저렇게 함수를 만들어놓으면 매번 기능개발해줄 필요가 없습니다.

(참고)

다른 언어에선 코드가 class 단위로 동작하는데  
class 안에 가끔 외부로 부터 보호하고 싶은 변수들이 있습니다.  
그럴 때 저런 함수를 많이 만들어 사용합니다. 그런 코딩스타일을 자바스크립트에 그대로 적용하고 있다고 보면 됩니다.  
(보호라는 뜻은 그냥 실수로 수정하는거 방지입니다)

## 함수로 object 데이터를 수정하는 방법

이번엔 object에 있는 age 데이터를 수정하고 싶습니다.  
40으로 변경하고 싶습니다. 어떻게 할까요?  
사람.age = 40 이렇게 등호를 이용하면 수정되긴하죠?  
하지만 미래를 생각하는 개발자들은 데이터 수정을 위한 함수를 만들어 사용합니다.

```js
var 사람 = {
  name: "Kim",
  age: 30,
  setAge(나이) {
    this.age = 나이;
  },
};
```

setAge()라는 함수를 오브젝트 내에 추가했습니다.

그리고 이 함수는 파라미터를 한개 입력할 수 있는데 그 파라미터를 그대로 this.age에 집어넣어주는 역할을 합니다.

그럼 이제 사람.setAge(40) 이렇게 쓰시면 자유롭게 나이 변경이 가능합니다.

사람.age = 40 이렇게 쉽게 안하고
사람.setAge(40) 굳이 이렇게 하는 이유는

- 내부에 있는 name, age 변수를 직접 건드리지 않아서 실수를 방지할 수 있습니다.

한 겹의 안전장치를 만든다고 보면 됩니다.

안전장치가 뭐냐면 예를 들면

```js
사람.setAge("40");
```

나이에 숫자를 집어넣어야하는데 이렇게 실수로 '40' 이라는 문자를 집어넣으면 어떻게 될까요?  
그냥 잘 저장됩니다. 데이터가 오염됩니다.  
나중에 나이에 1을 더하고 싶을 때 에러도 유발할 수 있겠죠.

근데 데이터 수정하는 함수를 사용하시면 살짝 안전장치를 더해줄 수 있습니다.

```js
var 사람 = {
  name: "Kim",
  age: 30,
  setAge(나이) {
    this.age = parseInt(나이);
  },
};

사람.setAge("200"); //문자 넣었는데도 숫자 200으로 저장됨
```

setAge()라는 함수안에 기능을 하나 추가했죠?  
parseInt()라는 함수는 '40'같은 문자를 숫자 40으로 바꿔주는 고마운 자바스크립트 내장함수입니다.  
이렇게 문자를 집어넣어도 숫자로 바꿔주는 안전장치도 이렇게 쉽게 개발이 가능한 것입니다.

## 함수 쓰기 복잡하다면 get/set 키워드를 붙이자

함수를 만들어쓴다면 단점이 있죠?  
setAge(40) 이렇게 소괄호까지 써야되고 뭔가 데이터 집어넣기 너무 복잡해집니다.  
그렇다면 get/set 키워드를 함수 옆에 추가하시면 됩니다.

```js
var 사람 = {
  name: "Kim",
  age: 30,
  set setAge(나이) {
    this.age = parseInt(나이);
  },
};

사람.setAge = 40; //set 키워드를 추가하면 이렇게 함수를 사용가능
```

setAge() 함수 만들 때 왼쪽에 set이라는 키워드를 추가하시면  
이제 등호로 데이터를 입력하거나 하실 수 있습니다.  
보기도 쉽고 직관적이고 그렇죠?  
그래서 set을 사용합니다. 그리고 set 붙은 함수들은 setter라고 부릅니다.  
(데이터를 set 하는 (수정하는) 함수라는 뜻)

```js
var 사람 = {
  name: "Kim",
  age: 30,
  get nextAge() {
    return this.age + 1;
  },
};

console.log(사람.nextAge); //get 키워드를 추가하면 이렇게 함수를 사용가능
```

nextAge()라는 함수를 만들 때는 get 키워드를 사용가능합니다.  
그러면 이제 소괄호 없이 nextAge를 사용해서 데이터를 꺼낼 수 있습니다.

보기도 쉽고 직관적이고 그렇죠?

그래서 get을 사용합니다. 그리고 get 붙은 함수들은 getter라고 부릅니다.  
(데이터를 get하는 (가져오는) 함수라는 뜻)

get/set 사용하는 기준은

그냥 데이터를 뽑아주는, 가져와주는, get 해주는 함수들은 get 쓰시면 되고  
데이터를 입력해주는, 수정해주는, set 해주는 함수들은 set 쓰시면 됩니다.

그리고 규칙도 있습니다.

set 함수는 데이터를 입력해서 수정해주는 함수니까 파라미터가 한개 꼭 존재해야하고  
get 함수는 파라미터가 있으면 안되고 함수 내에 return을 가져야합니다.  
잘못 쓰면 에러를 알려주니까 외울 건 없고  
보통 그냥 get 느낌나는 함수들은 get 붙이면 별일 없으니 그닥 어렵진 않습니다.

## class에서 사용하는 get/set

class 안에서 함수 만들 때 get/set 키워드를 이용해서 getter/setter 식으로 함수를 만들 수 있습니다.

```js
class 사람 {
  constructor() {
    this.name = "Park";
    this.age = 20;
  }
  get nextAge() {
    return this.age + 1;
  }
  set setAge(나이) {
    this.age = 나이;
  }
}

var 사람1 = new 사람();
```

class 안의 함수들을 getter/setter로 만들어 쓰고 싶으면 이렇게 하시면 됩니다.  
이제 새로 뽑인 object인 사람1은

사람1.nextAge;

사람1.setAge = 50;

이렇게 사용하실 수 있겠군요.

class에서의 getter/setter 용도는 위에서 설명한 내용과 똑같습니다.  
새로 뽑힌 오브젝트들 내용을 편리하게 수정할 때 사용합니다.  
굳이 get/set 키워드가 없어도 상관없습니다.

# Destructuring

Array, Object 자료형에 있는 중요한 자료들을 변수로 꺼내고 싶으면 어떻게 합니까.  
한두개면 모르겠는데 여러개의 자료를 뽑아서 변수 만들려면 코드가 매우 길어지겠죠?  
그럴 때 destructuring 문법을 사용하면 변수를 쉽게 만들 수 있습니다.  
맨날 쉽다 별거아니다 그러는데 이번엔 진짜 쉽습니다.

## Array 안에 있는 데이터를 변수에 담는 방법

`[2,3,4]`라는 array가 있는데,

여기안에 있는 3개의 데이터들을 전부 밖으로 꺼내서 변수에 담고 싶으면 어떻게 합니까.

```js
var array = [2, 3, 4];
var a = array[0];
var b = array[1];
```

뭐 이런식 아닐까요?  
근데 더 쉽게할 수 있는 방법이 있습니다.

```js
var [a, b, c] = [2, 3, 4];
```

`[2,3,4]`라는 자료랑 비슷한 모양으로 변수를 선언해주시면 됩니다.

변수 이름은 아무렇게나 해주시면 되고요.  
그럼 a,b,c 변수가 세개 생성되는데 각각 2,3,4라는 자료를 가집니다.

array에서 데이터 끄집어내서 변수 생성 끝입니다.  
여기서 디폴트 값도 줄 수 있습니다.

왼쪽 오른쪽 갯수가 다르면 변수가 제대로 만들어지지 않습니다.

```js
var [a, b, c] = [2, 3];
```

위처럼 쓰시면 c라는 변수는 값이 할당이 안되어서 undefined가 할당되어있습니다.

이걸 방지하고 싶으면  
값이 아무것도 안들어오는 변수들은 기본값을 가질 수 있게 만들 수 있습니다.

```js
var [a, b, c = 5] = [2, 3];
```

그럼 c는 아무 값도 안들어오는 경우 5라는 기본값을 할당해줍니다.  
함수 배웠을 때 쓰던 default 파라미터 문법과 똑같이 쓰시면 됩니다.

## Object 안에 있는 데이터를 변수에 담는 방법

object도 좌우를 똑같이 맞춰주시면 변수가 생성됩니다.

```js
var { name: a, age: b } = { name: "Kim", age: 30 };
```

이렇게 하시면 됩니다.  
그럼 a, b라는 변수가 생성되고 Kim과 30이라는 자료를 각각 할당해줍니다.

이렇게 쓰시면 조금 더 쉽게 변수를 뽑을 수 있는데  
변수 이름을 오브젝트 안의 key 이름과 똑같이 맞춰줄 때는 이렇게만 쓰셔도 됩니다.

```js
var { name, age } = { name: "Kim", age: 30 };
```

name : name을 name 이렇게 하나로 생략이 가능합니다.  
이렇게 하시면 name, age라는 변수가 생성되고  
각각 Kim, 30이라는 값을 할당해줍니다.  
object에서 변수꺼내기 끝입니다.

+) array랑 똑같이 등호로 디폴트값도 적용가능합니다.

이번엔 변수를 object로 집어넣고 싶은 경우

```js
var name = "Kim";
var age = 30;

var obj = { name: name, age: age };
```

변수를 object 자료형에 집어넣고 싶은 경우 이런 식으로 쓰면 되겠죠?

하지만 destructuring 문법을 이용하시면 이런 것도 가능합니다.

```js
var name = "Kim";
var age = 30;

var obj = { name, age };
```

name : name 이렇게 key값과 value값이 동일하면
name 이렇게 하나로 생략이 가능합니다.

함수 파라미터 변수 만들 때도 똑같이 적용가능합니다.  
함수가 하나 있는데 이 함수는 두개의 파라미터를 입력할 수 있습니다.  
여기에 object 내의 Kim, 그리고 age 자료들을 입력하고 싶으면 어떻게 할까요?

```js
function 함수(name, age) {
  console.log(name);
  console.log(age);
}

var obj = { name: "Kim", age: 20 };
함수(obj.name, obj.age);
```

아마 obj.name 이걸 직접 집어넣고 그러면 되겠죠?

혹은 destructuring 문법을 쓰시면 됩니다.

```js
function 함수({ name, age }) {
  console.log(name);
  console.log(age);
}

var obj = { name: "Kim", age: 20 };
함수(obj);
```

아마 obj.name, obj.name 이걸 두개 뽑지 않고도 넣을 수 있습니다.  
왜냐면 파라미터는 실은 변수만드는 거랑 똑같은 행위기 때문에  
변수만드는 문법을 그대로 적용할 수 있는 것이지요.

파라미터를 입력할 때

{name, age} = { name : 'Kim', age : 20 }

이거 한거랑 똑같습니다.

(솔직히 많이 쓰진 않습니다)

이해가 안되면 조금 더 쉬운 array를 보도록 합시다.

함수 파라미터로 array 내의 데이터들을 집어넣고 싶으면 어떻게 하죠?

```js
function 함수(name, age) {
  console.log(name);
  console.log(age);
}

var array = ["Kim", 30];
함수(array[0], array[1]);
```

위처럼 해도 되지만  
destructuring 문법을 이용하시면

```js
function 함수([name, age]) {
  console.log(name);
  console.log(age);
}

var array = ["Kim", 30];
함수(["Kim", 30]);
```

이렇게 하셔도 됩니다.  
파라미터인 [name, age] 를 만들 때 ['Kim', 30] 이걸 그대로 대입해서 만드는 것이죠.  
그럼 각각 name과 age에는 Kim과 30이라는 데이터가 들어갑니다.

데이터가 얼마나 복잡하든간에 좌우 형태를 똑같이 맞추시면 destructuring 문법으로 변수를 만들 수 있습니다.

# import / export를 이용한 파일간 모듈식 개발

자바스크립트 코드가 길어지면 다른 파일로 쪼개는게 좋은 관습입니다.  
다른 파일로 쪼개놓고 그걸 첨부해서 사용하는 방법을 알아보도록 합시다.  
ES6 import/export를 쓰시면 내가 원하는 변수, 함수, class만 다른 파일로 보낼 수 있습니다.  
어떻게 하는지 알아봅시다.  
(참고) import 해온 변수, 함수는 사용은 가능하지만 수정은 불가능합니다. read-only 입니다.

파일 두개를 만들어봅시다.

저는 index.html과 library.js를 만들어서  
library.js 파일에 있는 내용을 index.html `<script>`태그 내에서 가져다 쓰도록 하겠습니다.  
(이거 말고도 당연히 .js 파일 간에도 가능합니다.)

```js
(index.html)

<script type="module">

</script>
```

HTML 파일 안에서 ES6 import 문법을 쓰시려면 저렇게 script 태그 안에 type을 module로 설정해주셔야합니다.

## export default / import 를 쓰면

다른 파일에 있는 변수 등을 가져다쓸 수 있습니다.  
변수 함수 class 전부 가능합니다.

```js
(library.js)

var a = 10;
export default a;

------------------------
(index.html)

<script type="module">
  import a from 'library.js';
  console.log(a);
</script>
```

JS 파일에서는 특정 변수를 다른 파일에서 이용할 수 있게 내보내고 싶으면  
export default **변수명** 이라고 하시면 됩니다.

그리고 그 변수를 가져다쓰고 싶다면  
다른 파일에서 import 어쩌구 from '경로'  
해주시면 됩니다.

## 여러개를 export 할 수도 있습니다

JS파일에서 변수를 여러개 만들고 그걸 다 내보내고싶으면  
export 라는 키워드를 여러번 쓰시면 됩니다.

```js
(library.js)

var a = 10;
var b = 20;
export {a, b};

------------------------
(index.html)

<script type="module">
  import {a,b} from 'library.js';
  console.log(a);
</script>
```

근데 export 라고 쓰실 땐  
export {변수명1, 변수명2 ...} 이렇게 담아주셔야합니다.  
혹은 export var a = 10; 이렇게 쓰셔도 됩니다.

export 키워드로 내보낸 것들을 import 하실 땐  
import {변수명1, 변수명2 ...} from '경로' 이렇게 가져오셔야합니다.

export default와 차이점은

- export default는 한번만 쓸 수 있고 import시엔 변수명을 새롭게 작명가능하다

- export는 {변수명1, 변수명2 ...} 이렇게 담아야하고 import 할 때도 정확히 변수명을 써줘야한다

라는 특징이 있습니다.

## 그럼 export와 export default를 동시에 사용하면?

그래도 잘 됩니다.  
근데 import할 때 어떻게 해야할지 감이 안오죠?

```js
(library.js)

var a = 10;
var b = 20;
var c = 30;
export {a, b};
export default c;

------------------------
(index.html)

<script type="module">
  import c, {a,b} from 'library.js';
  console.log(c);
</script>
```

이렇게 import 해오시면 됩니다.  
export default 한건 맨 왼쪽에 써주시면 되고  
그 다음부터 이제 {} 중괄호 안에 export 했던 변수들을 적어주시면 됩니다.

## 변수명이 마음에 안들면 as로 새로 짓자

import를 쓰실 때 변수명 오른쪽에 as라는 키워드를 붙일 수 있습니다.  
변수명 as 새변수명 이렇게 하시면 import하는 변수의 변수명을 멋있는걸로 바꿀 수 있습니다.

```js
(library.js)

var a = 10;
var c = 30;
export {a};
export default c;

------------------------
(index.html)

<script type="module">
  import c as 간지, {a as 폭발} from 'library.js';
  console.log(간지);
  console.log(폭발);
</script>
```

c라는 것은 간지라고 이름을 바꿨고  
a라는 것은 폭발로 이름을 바꿨습니다.  
아무튼 저렇게 변수명 오른쪽에 그대로 붙이시면 됩니다.

## import할 때 변수들이 너무 많으면 \* 기호를 씁시다

export 했던 변수들이 100개면  
import 오른쪽에 변수를 100개나 쭉 써줘야합니까?  
맞습니다.  
근데 그러기 싫으시면 변수들을 한꺼번에 object에 담아서 import 해올 수 있습니다.

```js
(library.js)

var a = 10;
var b = 20;
var c = 30;
export {a,b};
export default c;

------------------------
(index.html)

<script type="module">
  import c, {* as 변수모음} from 'library.js';
  console.log(변수모음.a);
  console.log(c);
</script>
```

`*` 이라는 기호는 export 했던 애들을 그냥 다 import 해주세요~ 라는 뜻입니다.  
근데 그냥 쓰면 안되고 as로 별명을 꼭 지어주셔야합니다.  
그럼 이제 별명에 export 했던 변수들이 다 들어갑니다.

(export default 했던건 그냥 원래대로 import 하시면 되고요)

## 옛날엔 require, module.exports 라는게 있었습니다.

옛날에 Require.js 이상한 라이브러리를 쓰거나 nodejs 개발시  
자바스크립트를 모듈식으로 개발이 가능했었습니다.  
이렇게 씁니다.

```js
(export 하는 js파일)

module.exports.a = 10 ;

------------------------
(import 하는 js파일)

var 가져온거 = require('/library.js');
```

이러면 a를 쓸 수 있었습니다.  
근데 이제는 ES6 import/export를 쓰면 되기 때문에  
아 그냥 저런게 있었구나 라고 이해만 하셔도 되겠습니다.  
나중에 저런 옛날 코드를 해석할 일이 있으면 그 때 찾아보셔도 충분하니까요.

그리고 import/export는 당연 IE 호환성이 없기 때문에  
단순한 html css js 프론트엔드 개발시 JS파일을 HTML에 첨부하시려면  
`<script src="경로"></script>` 이걸 쓰도록 합시다. 이것이 원조 import 문법 아니겠습니까.

혹은 모던 브라우저에선 `<script type="module" src="경로"></script>` 이렇게 하면 import export 문법이 사용가능해지는데  
대부분은 리액트 뷰 nodejs 이런거할 때 많이 사용하게 됩니다.

# 브라우저 동작원리

[![브라우저_동작원리](http://img.youtube.com/vi/v67LloZ1ieI/0.jpg))](https://youtu.be/v67LloZ1ieI)

## 처리가 오래걸리는 코드를 만나면

가끔가다가 특별한 코드를 실행해야할 경우가 있습니다.  
서버로의 ajax 요청, 이벤트리스너, setTimeout 이런 코드들입니다.  
이런 코드는 처리하기까지 시간이 오래걸립니다.  
ajax 요청은 서버에서 응답을 받기까지 시간이 오래걸리고  
버튼 이벤트리스너는 사용자가 버튼을 누르기까지 시간이 오래걸립니다.  
그래서 그런건 Stack에 쌓아서 실행하지 않고  
잠깐 보류해놨다가 완료가 되는 시점에 Stack으로 보냅니다.

근데 Stack은 항상 바쁘기 때문에 Stack이 텅 빈 시점에 집어넣게 되어있습니다.  
아무튼 ajax 요청, 이벤트리스너, setTimeout 이런 코드가 실행준비가 되면  
Queue라는 곳에 집어넣고 Queue에 있던 코드는 Stack으로 옮겨서 실행해주는데  
Stack에 넣어서 실행하는데 Stack이 비어있을 때만 차례로 집어넣어서 실행해줍니다.

(참고로 Queue는 들어온 순서대로 차례차례 Stack으로 옮겨줍니다.)

## 코드짤 때 이렇게 코드짜면 안됩니다

Stack을 바쁘게 만들면 여러분이 ajax 요청, 이벤트리스너, setTimeout 이런 코드 실행이 불가능한 것입니다.  
반복문을 1억번 돌리면 시간이 걸리겠죠?  
10초걸린다고 합시다.  
그럼 10초 동안 ajax 요청, 이벤트리스너, setTimeout 이런 코드는 실행이 불가능합니다.  
Stack이 10초동안 비지 않기 때문에 그렇습니다.  
그럼 브라우저가 멈추거나 하얗게 변하거나 그런 현상이 일어납니다.  
결론은 Stack을 바쁘게하면 웹사이트가 버벅이겠구나 라는 생각을 하며 코드짜도록 합시다.

# 동기 / 비동기 처리

## 자바스크립트는 항상 동기식 처리 (synchronous)

동기식 처리가 뭐냐면 한번에 코드 한줄씩 차례차례 실행된다는 소리입니다.  
자바스크립트를 실행하는 웹브라우저는 stack이라는 코드 실행 공간이 있는데  
거기서 코드를 한줄한줄 차례로 실행합니다.  
그럼 하단 코드는 어떤 순서대로 출력될까요?

```js
<script>console.log(1); console.log(2); console.log(3);</script>
```

예상하신 대로 1,2,3이 차례로 출력됩니다.  
왜냐면 자바스크립트는 한번에 코드 한줄씩 차례차례 실행하니까요.  
이걸 전문용어로 동기적이다~ (synchronous) 라고 합니다.  
그냥 거의 대부분의 프로그래밍 언어들은 이런 특징을 가지고 있습니다.

## 비동기처리 (asynchronous)라는 것도 가능합니다

특정 코드를 1초 후에 실행하고 싶으면 어떻게하죠?  
일반적인 프로그래밍 언어에서 이런 코드를 작성하려면...

```python
print(1)
time.sleep(1)
print(2)
```

파이썬으로 해보았습니다. 이렇게 작성합니다.  
time.sleep(1)이라는건 1초 쉬어주세요 라는 뜻입니다.  
그럼 1이라는게 출력되고 / 1초 쉬고 / 2라는게 출력됩니다.

자바스크립트에서 1초 쉬고 뭔가 출력하는 코드를 작성하려면

console.log(1);
setTimeout(function(){}, 1000);
console.log(2);
보통 프로그래밍 언어처럼 이렇게 작성하면 될까요?  
안됩니다. 1과 2가 콘솔창에 동시에 출력됩니다.  
여기서 자바스크립트의 이상한 점을 느끼시면 됩니다.

자바스크립트는 보통 프로그래밍 언어들과 생각하는 방식자체가 다릅니다.

왜그러냐면 setTimeout() 이라는 함수를 잘 보시면 이건 실행까지 시간이 조금 걸리는 함수죠?  
1초나 걸립니다.  
자바스크립트 실행머신인 웹브라우저는  
이런 특수한 코드들을 발견하면 약간 제쳐두고 다른 코드부터 실행하려고 합니다.  
그래서 setTimeout() 을 제껴두고 그 밑에 있는 console.log(2)라는 코드 부터 실행하는 것입니다.

이런 처리방식을 바로 비동기(asynchronous)라고 합니다.  
실행이 오래걸리는 그런 코드들은 잠깐 대기실에 제쳐두고,  
실행이 바로바로 가능한 코드들부터 처리하는 방식을 뜻합니다.  
이건 자바스크립트 언어 자체의 기능이 아니라  
자바스크립트 실행을 도와주는 웹브라우저 덕분에 해낼 수 있는 것입니다.

## 잠깐 코드를 제쳐두는 대기실

실행을 미루고 옆으로 잠깐 제껴둘 수 있는 코드들은 미리 정해져있습니다.
위에서 말했던 setTimeout, addEventListener, ajax 관련 함수들이 바로 그것입니다.  
setTimeout, addEventListener, ajax관련 함수들은 1초대기, 클릭대기 이런걸 하는 코드들인데  
이런 코드들의 특징은.. 읽는 시점과 동작 시점이 차이가 있습니다. (쉽게 말하면 동작까지 오래걸립니다.)

자바스크립트를 실행하고 해석하는 크롬은 이런 특별한 코드들을 만나면

1. 잠깐 대기실에 제껴두고

2. 준비가 완료되면 다시 실행시킵니다.

```js
console.log(1);
setTimeout(function () {}, 1000);
console.log(2);
```

크롬은 위의 코드를 읽다가 setTimeout~ 이런 코드를 만나면 잠시 Web API 대기실로 옮겨서 대기시킵니다.  
그리고 1초의 대기시간이 지나고 setTimeout이 완료가 되면 대기실에서 코드를 꺼내서 코드가 실행되게 만들어줍니다.

이것 덕분에 setTimeout같이 시간이 오래걸리는 코드들을 비동기식으로 처리할 수 있는 것입니다.  
그래서 자바스크립트는 평소에 별일 없으면 동기식으로 처리하는데  
비동기를 지원하는 setTimeout 같은 함수를 이용하면 비동기식으로 동작하게 만들 수 있는 언어입니다.

## 콜백함수를 이용한 순차적 실행

그럼 아까 예시로 돌아와서, 자바스크립트에서 1초 후에 코드를 실행하고 싶으면 어떻게 하죠?

```js
console.log(1);
setTimeout(function () {
  console.log(2);
}, 1000);
console.log(3);
```

저렇게 setTimeout 안에 콜백함수안에 코드를 짜면 된다고 배우지 않았습니까.  
맞습니다.  
그러면 콘솔창에 1과 3이 먼저 빠르게 출현하고  
그 다음 1초 후에 2라는 숫자가 출현합니다.

자바스크립트는 비동기상황 등에서 코드를 순차적으로 실행하고 싶을 때 콜백함수를 적극 활용합니다.

## 콜백함수 디자인하는 법

예를 들면 순차적으로 실행하고 싶은 함수가 두개 있다고 칩시다.  
그럼 이렇게 코드짜면 될까요?

```js
function 첫째함수() {
  console.log(1);
}

function 둘째함수() {
  console.log(2);
}

첫째함수();
둘째함수();
```

여러분이 파이썬으로 코드짜신다면 이게 맞습니다.  
하지만 자바스크립트는 비동기라는 특수성으로 인해 이렇게 쓴다고 순차적으로 실행하는걸 보장하진 않습니다.  
(첫째함수가 뭐 setTimeout이라든지 Web API 대기실로 보내는 코드라면 나중에 실행될 수 있으니까요)

그럼 우리도 이거랑 똑같이 개발하면 될 것 같습니다.  
콜백함수를 만들어서 첫째함수(둘째함수);  
이런 식으로 실행시킬 수 있게 만들어놓으면 순차적으로 실행할 수 있겠죠?  
그럼 어떻게 코드를 짜놔야 함수를 함수안에 집어넣을 수 있을까요?

```js
function 첫째함수(콜백) {
  console.log(1);
  콜백();
}

function 둘째함수() {
  console.log(2);
}

첫째함수(둘째함수);
```

함수에 파라미터를 하나 뚫어주시면 됩니다.  
그리고 그 파라미터에 소괄호를 붙여서 실행해주세요~ 라고 하면 함수안에 함수를 집어넣어서 실행이 가능합니다.  
이게 콜백함수 디자인하는 법입니다.

위처럼 미리 만들어놓은 함수를 집어넣을 수도 있고

```js
첫째함수(function(){
  console.log(2)
}):
```

이렇게 직접 함수선언문을 집어넣을 수도 있습니다.

순차적으로 실행하려고 콜백함수를 여러개 사용하면 단점이 조금 있습니다.  
코드가 옆으로 길어집니다.

```js
첫째함수(function(){
  둘째함수(function(){
    셋째함수(function(){
      어쩌구..
    });
  });
}):
```

첫째함수 둘째함수 셋째함수 이렇게 차례로 실행해주는 코드입니다.

특히 자바스크립트로 서버개발시 이런 패턴 흔합니다.  
이런거 보기싫으시면 ES6 신문법인 Promise라는 기계를 만들어 사용하시면 됩니다.

콜백대신 쓸 수 있는 Promise 디자인 패턴을 적용하면 어떻게 되냐면

```js
첫째함수().then(function(){
   그 담에 실행할거
}).then(function(){
   그 담에 실행할거
});
```

옆으로 길어지지 않고 then이라는 키워드 덕분에 그나마 뭘 하는지도 파악이 쉬워집니다.  
어떻게 하는지는 다음 시간에 알아봅시다.

# 콜백함수 패턴이 마음에 안들때는 ES6 Promise

콜백함수 디자인패턴이 마음에 안드는 분들은  
Promise 디자인패턴을 사용하시면 됩니다.  
이건 자바스크립트의 새로운 기능이라기보다는 코드/함수 디자인 패턴일 뿐입니다.  
이런거 안써도 코드잘짤 수 있긴 한데 나오면 알아야하니 아무튼  
그럼 일단 어떻게 하는지 알아봅시다.

## Promise 생김새

```js
var 프로미스 = new Promise();

프로미스.then(function () {}).catch(function () {});
```

이것이 끝입니다.  
new Promise() 문법으로 프로미스라는 변수 오브젝트를 하나 생성하시면 Promise 제작 끝입니다.  
그럼 이제 프로미스라는 변수에다가 then()을 붙여서 실행가능합니다.

프로미스 안의 코드가 실행이 완료가 되었을 때 then() 함수 내의 코드를 실행시켜줍니다.  
코드가 실행이 실패했을 경우엔 catch() 함수 내의 코드를 실행시켜줍니다.  
(지금은 프로미스 안에 코드가 암것도 없지만요)

이런 식으로 코드를 차례로 실행할 수 있게 도와주는 디자인 패턴이 바로 Promise입니다.

Promise가 콜백함수보다 좋다고 하는 이유는 두개가 있습니다.

1. 콜백함수와는 다르게 순차적으로 뭔가를 실행할 때 코드가 옆으로 길어지지 않습니다. then 함수를 붙여서 순차적으로 실행하니까요.

2. 콜백함수는 불가능한 '실패시 특정 코드를 실행해주세요~' 라고 코드를 짤 수 있습니다. (catch)

## Promise의 정확한 뜻과 사용법

성공하면 then(), 실패하면 catch()를 실행해주세요~  
라는 코드를 짤 수 있게 도와주는게 바로 Promise입니다.  
그럼 Promise는 성공과 실패 상황을 알려줘야겠죠?  
그래서 Promise를 를 쉽게 정의하자면 성공&실패 판정기계입니다.

Promise 기계 안에는 아무거나 다 집어넣을 수 있습니다  
1 + 1같은 어려운 연산이 끝나면 성공판정 내려주세요~  
페이지 내의 `<button>`을 누르면 성공으로 판정해주세요 ~  
Ajax 요청으로 서버의 데이터를 가져오면 성공판정, 에러나면 실패판정해주세요~  
아무거나 다 집어넣을 수 있습니다.

Promise 안에서 성공/실패를 판정하는 방법은 쉽습니다. 그대로 따라쓰시면 됩니다.

```js
var 프로미스 = new Promise(function (성공, 실패) {
  성공();
});

프로미스.then(function () {}).catch(function () {});
```

Promise()안에 콜백함수를 하나 추가해주시면 그 안에서 성공/실패 판정을 내릴 수 있습니다.  
성공()이라고 첫째 파라미터를 함수형태로 작성하면 성공판정이 됩니다.  
실패()라고 둘째 파라미터를 함수형태로 작성하면 실패판정이 됩니다.  
위의 코드는 무조건 성공()을 실행하게 되어있으니 무조건 성공을 판정내리며  
그 후엔 이제 then()안의 코드가 실행이 되겠죠?

실제로 사용하는 예시를 봅시다.

## 예시1. 힘든 수학연산 성공 후에 특정 코드를 실행하려면?

콜백함수로 디자인해놓아도 될 것 같죠? 그럼 그렇게 하시면 됩니다.

근데 저는 콜백보다는 .then()을 쓰고싶어서 Promise를 한번 활용해보겠습니다.

```js
var 프로미스 = new Promise(function (성공, 실패) {
  var 어려운연산 = 1 + 1;
  성공();
});

프로미스
  .then(function () {
    console.log("연산이 성공했습니다");
  })
  .catch(function () {});
```

Promise()안에 어려운 수학 연산을 해주는 기능을 추가했습니다.  
그리고 그 연산이 완료되면 성공() 코드를 실행하도록 코드를 추가했습니다.  
(일반 코드들은 저렇게 위아래로 나란히 적으면 그냥 차례로 실행됩니다)

기계를 잘 만들어놨으니 then 함수 안에는 프로미스가 성공판정을 내리면 실행할 코드를 담을 수 있습니다.  
그럼 디자인 끝입니다.

1. 이제 프로미스 내의 1+1 이라는 어려운 수학연산이 완료되면 성공() 판정을 내리며,

2. 성공시 then() 내의 코드를 실행해줍니다.

이렇게 Promise를 사용하시면 이상한 콜백함수패턴 대신 멋있는 then을 사용할 수 있군요.

Promise 내에선 특정상황시 실패판정을 내릴 수도 있습니다.  
이렇게 하시면 됩니다.

```js
var 프로미스 = new Promise(function (성공, 실패) {
  var 어려운연산 = 1 + 1;
  실패();
});

프로미스
  .then(function () {
    console.log("연산이 성공했습니다");
  })
  .catch(function () {
    console.log("실패했습니다");
  });
```

실패()라는 함수를 실행하는 순간 실패판정을 내립니다.  
그렇게 되면 catch() 내의 코드를 실행해줍니다.  
실패의 경우 다른 내용을 실행해줄 수도 있고하니 그냥 콜백함수 디자인보다 훨씬 뭔가 직관적이고 유용합니다.

참고로 연산결과같은걸 then 안에서 활용하고 싶으면  
성공(); 함수 구멍안에 넣어주시면 됩니다.

```js
var 프로미스 = new Promise(function (성공, 실패) {
  var 어려운연산 = 1 + 1;
  성공(어려운연산);
});

프로미스
  .then(function (결과) {
    console.log("연산이 성공했습니다" + 결과);
  })
  .catch(function () {
    console.log("실패했습니다");
  });
```

그럼 then 함수 안에서 파라미터의 형태로 그 결과를 사용하실 수 있습니다.

실제로 사용하는 예시를 하나 더 봅시다.

## 예시2. 1초 대기 성공 후에 특정 코드를 실행하려면?

역시 콜백함수로 디자인해놓아도 될 것 같죠? 그럼 그렇게 하시면 됩니다.

하지만 저는 간지나게 then을 사용해보기 위해 Promise를 디자인해보겠습니다.

```js
var 프로미스 = new Promise(function (성공, 실패) {
  setTimeout(function () {
    성공();
  }, 1000);
});

프로미스
  .then(function () {
    console.log("1초 대기 성공했습니다");
  })
  .catch(function () {
    console.log("실패했습니다");
  });
```

이러면 되겠죠?  
아마 실패하는 경우는 없을 것 같아서 실패()는 안썼습니다.

## Promise의 몇가지 특징

1. 일단 new Promise()로 생성된 변수를 콘솔창에 출력해보시면 현재 상태를 알 수 있습니다.  
   성공/실패 판정 전에는 `<pending>` 이라고 나오며
   성공 후엔 `<resolved>`
   실패 후엔 `<rejected>` 이런 식으로 나옵니다.  
   이렇게 프로미스 오브젝트들은 3개 상태가 있습니다.  
   그리고 성공을 실패나 대기상태로 다시 되돌릴 순 없습니다. 참고로 알아둡시다.

2. Promise는 동기를 비동기로 만들어주는 코드가 아닙니다.  
   Promise는 비동기적 실행과 전혀 상관이 없습니다.  
   그냥 코딩을 예쁘게 할 수 있는 일종의 디자인 패턴입니다.  
   예를 들면.. Promise 안에 10초 걸리는 어려운 연산을 시키면 10초동안 브라우저가 멈춥니다.  
   10초 걸리는 연산을 해결될 때 까지 대기실에 제껴두고 그런거 아닙니다.

(그냥 원래 자바스크립트는 평상시엔 동기적으로 실행이 되며 비동기 실행을 지원하는 특수한 함수들 덕분에 가끔 비동기적 실행이 될 뿐입니다.)

# Promise 어려워서 싫으면 async/await (ES8)

Promise가 어렵다면 그보다 훨씬 쉽게 쓸 수 있는 ES8 문법이 있습니다.  
async, await이라는 키워드인데 각각 Promise와 then을 매우 쉽게 만들어주는 문법입니다.

## async 키워드를 쓰면 Promise 오브젝트가 절로 생성됩니다

말그대로입니다. new Promise() 어쩌구 하실 필요가 없습니다.  
근데 이 키워드는 function 선언 앞에만 붙일 수 있습니다.

```js
async function 어려운연산() {
  1 + 1;
}
```

그럼 이 함수 자체가 Promise가 되어버립니다.  
그래서 이 함수를 실행할 때 뒤에 then을 붙일 수 있습니다. Promise니까요.  
(함수를 실행하면 그 자리에 Promise 인스턴스 (new Promise() 로 만든 오브젝트)가 남습니다. )

```js
async function 더하기() {
  1 + 1;
}

더하기().then(function () {
  console.log("더하기 성공했어요");
});
```

그럼 이제 Promise 만들 때 했던거 처럼 then을 붙여서 더하기() 함수가 성공한 뒤에 뭔가를 실행시킬 수 있습니다.  
(훨씬 쉽네요 진작에 이렇게 만들것이지)

함수안에서 연산한 결과를 then 안에서 사용하고 싶다면

```js
async function 더하기() {
  return 1 + 1;
}

더하기().then(function (결과) {
  console.log(결과);
});
```

이렇게하시면 됩니다.  
return 오른쪽에 결과를 적어주시면 됩니다. 그럼 then함수까지 전해집니다.

## then() 함수가 귀찮다면 await 키워드를 쓸 수 있습니다.

async 키워드를 쓴 함수 안에서는 await을 사용가능합니다.  
await은 그냥 프로미스.then() 대체품으로 생각하시면 됩니다.  
하지만 then보다 훨씬 문법이 간단합니다.

새로운 예제를 만들어봅시다.  
어떤 function 안에서 어려운 연산을 실행한 뒤에 성공/실패를 판정해주는 Promise를 만들고 싶습니다.  
그럼 어떻게 합니까.

```js
async function 더하기() {
  var 어려운연산 = new Promise((성공, 실패) => {
    var 결과 = 1 + 1;
    성공();
  });
  어려운연산.then();
}
더하기();
```

많이 했던 패턴대로 이렇게하시면 됩니다.  
(혹은 Promise 만들기 귀찮으면 어려운연산을 함수로 만든 후 async를 쓰시면 됩니다)

그럼 이제 어려운연산.then() 이렇게 성공시 특정 코드를 실행할 수 있습니다.  
근데 .then()이게 너무 복잡해서 보기 싫으시면  
await이라는 키워드를 이용가능합니다.

```js
async function 더하기() {
  var 어려운연산 = new Promise((성공, 실패) => {
    var 결과 = 1 + 1;
    성공();
  });
  var 결과 = await 어려운연산;
}
더하기();
```

어려운연산.then() 과 매우 유사한 문법입니다.  
정확한 뜻은 어려운연산 Promise를 기다린 다음에 완료되면 결과를 변수에 담아주세요~ 입니다.

연산 결과를 출력하거나 그러고 싶다면  
성공 함수에 파라미터를 담아주시면 된다고 했죠?

```js
async function 더하기() {
  var 어려운연산 = new Promise((성공, 실패) => {
    var 결과 = 1 + 1;
    성공(결과);
  });
  var 결과 = await 어려운연산;
  console.log(결과);
}
더하기();
```

성공()함수 안에 있던 2라는 파라미터는  
var 결과라는 변수에 저장됩니다.  
그럼 Promise의 연산 결과를 출력해볼 수도 있겠네요.

(주의) 비동기식처리되는 코드를 담는다면 await 기다리는 동안 브라우저가 잠깐 멈출 수 있습니다.

await은 실패하면 에러가 나고 코드가 멈춥니다  
Promise가 실패하는 하단 코드를 실행해봅시다.

```js
async function 더하기() {
  var 어려운연산 = new Promise((성공, 실패) => {
    실패();
  });
  var 결과 = await 어려운연산;
  console.log(결과);
}
더하기();
```

어려운연산이라는 Promise가 실패할 경우  
await 어려운연산이라는 코드는 에러가 나고 코드실행을 멈춥니다.  
그럼 await 하단에 있는 코드들은 더 이상 실행이 되지 않겠죠.

그래서 Promise가 실패할 경우  
코드실행을 멈추고 싶지 않으면 약간 특별한 방법이 필요합니다.

```js
async function 더하기(){
  var 어려운연산 = new Promise((성공, 실패)=>{
    실패();
  });
  try {  var 결과 = await 어려운연산 }
  catch { 어려운연산 Promise가 실패할 경우 실행할 코드 }
}
```

try catch라는 자바스크립트 문법인데,  
try {} 안의 코드가 에러가 나고 멈출 경우  
대신 catch {} 내부의 코드를 실행해줍니다.

이렇게 에러처리를 하실 수 있습니다. 더 복잡하니까 그냥 then() 이런거 쓰셈  
어려운연산이라는 Promise가 실패()가 안날거라고 자신하면 try/catch를 굳이 쓸 필요는 없으니 코드가 더 간단해질 수도 있습니다.

# for in / for of 반복문과 enumerable, iterable 속성

이번기회에 반복문들 총정리를 해봅시다.
for, forEach는 기초강의에서 했으니 for in, for of 반복문을 알아봅시다.

그리고 함께 enumerable, iterable 이라는 속성도 알아봅시다.  
반복문은 용도가 2개라고 보시면 됩니다.

1. 코드 단순 반복

2. 자료형에 담긴 자료들을 하나씩 꺼내고 싶을 때

그 중 for in 반복문을 먼저 알아봅시다.

## for in 반복문은 Object에 사용합니다.

Object 자료형에 저장된 자료들을 하나씩 꺼내고 싶을 때 사용합니다.

```js
var 오브젝트 = { name: "Kim", age: 30 };

for (var key in 오브젝트) {
  console.log(오브젝트[key]);
}
```

이렇게 사용합니다.  
(key라는건 변수명입니다. 여러분이 마음대로 작명하시면 됩니다.)  
그럼 반복문은 오브젝트라는 자료 내부 데이터 갯수만큼 반복하게 되며  
반복할 때마다 key라는 변수는 name, age 이렇게 데이터의 key값이 됩니다.

그럼 반복시마다 변경되는 key 값을 이용하면 오브젝트 내의 자료를 모두 출력할 수 있습니다.  
단순하게 오브젝트.key를 콘솔창에 출력하면 되는데, 변수명을 저렇게 쩜찍고 쓸 수는 없으니  
오브젝트`[key]` 라고 사용하시면 됩니다.

오브젝트에서 자료 꺼내기 끝입니다.

## for in 반복문의 특징

1. enumerable한 것만 출력해줍니다

여러분이 object 자료형을 만들 때  
{ name : 'Kim' } 이걸 저장하면 Kim 이라는 자료만 달랑 저장되는게 아닙니다.
Kim과 함께 비밀스러운 속성들 3개가 저장됩니다.

```js
var 오브젝트 = { name: "Kim", age: 30 };

console.log(Object.getOwnPropertyDescriptor(오브젝트, "name"));
```

비밀스런 속성 3개를 출력해보고 싶으면 위처럼 쓰시면 됩니다.  
그럼 콘솔창에 뭐 이런게 나오죠?

```js
{value: "Kim", writable: true, enumerable: true, configurable: true}
```

이것이 Kim과 함께 몰래 저장되는 속성들입니다.  
(그래서 Object 자료형이 좀 무겁습니다)  
여기서 enumerable이라는게 있는데, 이게 true인 자료들만 for in 반복문이 출력할 수 있습니다.  
이걸 강제로 false로 만들면 for in 반복문이 거릅니다.  
아무튼 이런 동작원리를 가진게 바로 for in 반복문입니다.

\*) enumerable을 번역하면 '셀수있는' 이라는 뜻입니다.

2. 부모의 prototype에 저장된 것도 출력해줍니다.

object의 부모의 유전자에 있는 속성도 반복문으로 출력해줍니다.  
진짜인지 한번 실험해봅시다.

```js
class 부모 {}
부모.prototype.name = "Park";

var 오브젝트 = new 부모();

for (var key in 오브젝트) {
  console.log(오브젝트[key]);
}
```

Park이라는 자료는 부모가 가지고 있는 것인데도 출력해줍니다.  
이게 단점입니다.  
이런게 싫으시다면 if문을 추가해주셔야합니다.

```js
class 부모 {}
부모.prototype.name = "Park";

var 오브젝트 = new 부모();

for (var key in 오브젝트) {
  if (오브젝트.hasOwnProperty(key)) {
    console.log(오브젝트[key]);
  }
}
```

`오브젝트.hasOwnProperty()`라는 함수는  
오브젝트가 이 key값을 직접 가지고 있냐라고 물어보는 함수입니다.  
갖고 있으면 true, 없으면 false를 뱉어줍니다.  
그래서 내가 가진 것만 반복시키고 싶으면 이걸 꼭 쓰셔야합니다.

## for of 반복문

사용해봅시다. for in 반복문과 매우 유사합니다.

```js
var 어레이 = [2, 3, 4, 5];
for (var 자료 of 어레이) {
  console.log(자료);
}
```

이러면 어레이 안에 있던 모든 자료를 하나씩 콘솔창에 출력할 수 있군요.  
array 자료형 뿐만 아니라  
array, 문자, arguments, NodeList, Map, Set 이라는 자료형에 적용할 수 있는 반복문입니다.

근데 정확히 말하면 iterable인 자료형들에만 적용가능한 반복문입니다.  
iterable한 자료형이 뭐냐면  
`[Symbol.iterator]()` 이라는 일종의 메소드를 가지고 있는 자료형들을 뜻합니다.  
진짜 이런 괴상한게 있는지 출력만 해보도록 합시다.

```js
var 어레이 = [2, 3, 4, 5];
console.log(어레이[Symbol.iterator]());
```

array 자료형 뒤에 붙이면 뭔가 출력되긴 하죠?  
문자도 그렇습니다.  
실은 반복문 출력을 도와주는 일종의 함수인데 실용성은 없어서 깊게 이해할 필요는 없고  
이걸 가지고 있으면 for of 반복문을 쓸 수 있구나~라고만 아시면 됩니다.

for of는 NodeList라는 곳에도 사용할 수 있는데  
우리가 흔히 document.getElementsByClassName()이나 document.querySelectorAll() 이런 셀렉터로 찾은 요소들이  
[] 대괄호안에 담겨오는데 array는 아니고 NodeList라는 자료형이라고 부릅니다.  
NodeList에 있는 HTML요소들을 하나씩 꺼내서 처리할 때  
매우 자주 쓸 수 있는 반복문이라고 보시면 됩니다.

(하지만 for of의 호환성 주의)

# Symbol 자료형

ES6부터 Symbol 이라는 Primitive 자료형이 하나 추가되었습니다.  
이걸 어디에 사용하는지 알아보도록 합시다.

## Symbol 자료형 만드는 법

간단하게 만들 수 있습니다.

```js
var 심볼 = Symbol("설명아무거나적기");
```

Symbol() 함수를 이용하시면 되고 안에 아무 설명이나 적으시면 됩니다.  
그냥 주석(설명)하나만 달랑 저장할 수 있는 자료형입니다.

## Symbol은 Object자료형에 비밀스런 key값을 부여하고싶을 때 씁니다.

원래 Object 자료형에는 문자로만 key값을 입력할 수 있습니다.  
문자 아닌걸 입력해도 문자로 자동으로 치환되고요.  
근데 ES6부터는 Symbol도 key값으로 입력할 수 있습니다.

```js
person[심볼명] = 넣을자료;
```

이렇게 쓰시면 Object자료형에 Symbol을 이름으로 가진 자료를 저장가능합니다.  

```js
var person = { name : 'Kim' };
person.weight = 100;

var weight = Symbol('내 진짜 몸무게');
person[weight] = 200;

console.log(person);
```

위의 예제코드는 Symbol을 key값, 200을 value값으로 오브젝트에 집어넣은 예제입니다.  
출력해보면 { Symbol(내 진짜 몸무게) : 200 } 이라는 자료가 들어가있을겁니다.  
이렇게 특이한 이름을 가진 자료를 Object안에 만들고 싶을 때 Symbol을 쓰시면 됩니다.  
이 자료는 특징이 있는데,  
for문에 등장하지 않는다는겁니다.  
보통 Object를 반복문을 돌릴 때 for in 이런걸 사용합니다.  
그런데 Symbol은 반복문에서 감지하지 못합니다.  
그래서 시크릿한 내용을 저장하고 싶을 때 Symbol을 이용해서 자료를 저장하시면 됩니다.  
심볼을 직접 입력하려면  
심볼을 오브젝트 만들 때 직접 입력할 수도 있습니다.  

```js
var height = Symbol('내 키임');

var person = { name : 'Kim', [height] : 160 };
```

Object 자료형에 직접 입력하실 때는 저렇게 대괄호안에 심볼명을 담아주시면 됩니다.  

## 특징1. 설명은 설명일 뿐

Symbol() 안에는 간단한 설명을 저장할 수 있다고 했습니다.  
근데 같은 설명을 가졌다고 해서 같은 Symbol이 아닙니다.  
각각 다른겁니다.  

```js
var a = Symbol('설명1');
var b = Symbol('설명1');
console.log(a === b);
```

위의 예제에서 a와 b 심볼은 설명이 같음에도 불구하고  
두개를 같다고 비교해보면 false가 남습니다. 
Symbol은 Symbol()이라고 사용할 때마다 각각 유니크한 Symbol이 생성되서 그렇습니다.  

## 특징2. Symbol.for()로 만드는 전역심볼  

변수처럼 뭔가 같은값을 가지면 같은 변수로 취급해주는  
전역 심볼을 만들어쓸 수 있습니다.  
그러고 싶으면 Symbol() 대신에 Symbol.for() 로 만드시면 됩니다.  

```js
var a = Symbol.for('설명1');
var b = Symbol.for('설명1');
console.log(a === b);
```

위의 예제를 출력해보면 true라는 값이 남습니다.  
왜냐면 Symbol.for()로 새로운 Symbol을 만들 때  
설명이 같으면 이미 그 설명을 가지고 있는 Symbol을 그 자리에 집어넣기 때문입니다.  
그래서 a와 b의 심볼은 각각 다른 곳에서 만들었음에도 불구하고 같은 Symbol이 됩니다.  

## 특징3. 기본 내장 Symbol들

Array, Object 자료형을 만들 때 몰래 붙어있는 기본 Symbol 들도 있습니다.  
예를 들면 모든 array 자료형은 `[Symbol.iterator]`라는 이름을 가진 심볼이 안에 있습니다.
궁금하면 아무 array나 만들고 한번 저걸 출력해보십시오.  
(Symbol을 출력하고 싶으면 `오브젝트[심볼명]` 이렇게 하시면 됩니다)

```js
var array = [2,3,4];
console.log(array[Symbol.iterator]);
```

# Map, Set 자료형

ES6부터 Map, Set 자료형도 추가되었습니다.  
역시 매일 만나는 자료형은 아니기 때문에 간단하게 어디다쓰는지만 알아보도록 합시다.  

## 매핑을 할 수 있는 Map 자료형

Object자료형과 똑같이 key, value 형태로 자료를 저장할 수 있는 자료형입니다.   
어떻게 만드냐면  

```js
var person = new Map();
person.set('name', 'Kim');
person.set('age', 20);
```

이렇게 만들고 자료를 저장할 수 있습니다.  
그럼 name은 Kim  
age는 20이라는 자료가 저장됩니다.  
근데 출력해보시면 Object와는 약간 다릅니다.  

```
Map(2) {"name" => "Kim, "age" => 20}
```

화살표로 나타내줍니다.   
왜냐면 Map 자료형은 자료의 연관성을 표현하기 위해 쓰기 때문입니다.  
그냥 key, value형식으로 저장하려면 Object 쓰시면 되고, 
name이 Kim과 연관되어있다~ 라고 저장하고 싶으면 Map을 쓰시면 됩니다.  
다시한번 강조하면 자료들 간의 연관성을 표현하기 위해 쓰는 자료형이 바로 Map입니다  

## 그래서 Map 자료형은 key, value값에 모든 자료를 집어넣을 수 있습니다. 

key값란에 별걸 다 집어넣을 수 있다는 소리입니다.  

```js
var person = new Map();
person.set([1,2,3], 'Kim');
person.set('age', 20);
```

자료의 이름으로 array도 되고 object도 됩니다.   
단순하게 자료의 이름이라기보다는  
Map은 이 값이 저 값과 연관되어있다~ 라는걸 표현하기 위함이니까요.  

## Map 다루는 법 

```js
var person = new Map();
person.set('age', 20);

person.get('age'); //자료 꺼내는 법
person.delete('age'); //자료 삭제하는 법
person.size; //자료 몇갠지 알려줌

//Map자료 반복문 돌리기
for (var key of person.keys() ){
  console.log(key)
}

//자료를 직접 집어넣고 싶으면

var person = new Map([
  ['age', 20],
  ['name', 'Kim']
]); 
```

이렇게 다룰 수 있습니다.  
때에 따라 평생 쓸일이 없을 수도 있습니다.  

평소에 개발할 땐 여기까지만 알고계시면 되는데   
실은 알고리즘 공부를 하게 된다면 Map 자료형을 다시 만나게 될 겁니다.  
array 같은 곳에 자료를 저장할 때 자료가 천만개 1억개 이상으로 많으면 Hash Map, Hash Table 이라는걸 사용합니다.  
왜냐면 1억개 자료가 저장된 array에서 원하는 것만 쏙 뽑고 싶으면 반복문을 돌리든가 해서 1억개를 전부 들춰봐야하니까요.   

```js
var array = [1,5,34,67,43,2,213,8] 
```

이런 자료에서 2라는 자료가 어딨는지 찾고싶으면 어떻게합니까.  
몇번째인지 모르니까 반복문 돌려서 하나하나 출력해봐야하는 것입니다. 그래서 느리다는 겁니다.   

근데 Hash Table 이런걸 쓰면 자료를 미리 abc 순으로 정돈이 가능한데   
abc 순으로 정돈된 자료는 매우 찾기 빠릅니다.  
왜 빠르냐고요? 여러분 종이 영어사전에서 단어 찾을 때도 abc 알파벳 순으로 정렬되어있어서 빠르게 찾을 수 있잖아요.   
그래서 자료가 1억개고 거기서 원하는걸 찾을 일이 많으면 Hash Table을 사용합니다.  
자료에 key값을 부여해놓고 정렬하면 그게 Hash Table 만들기 끝입니다.   
실은 여태까지 잘 쓰던 object 자료형이 Hash Table이랑 비슷합니다.   

근데 Hash Table을 만들기 위해선 쌩 자바스크립트 object 자료 쓰면 되긴 하는데  

1. object 자료형은 hasOwnProperty, toString 이런 키들도 집어넣을 수 있어서 너무 유연하고  

2. key값으로 들어올 수 있는게 문자형태로 제한되어있어서  

Map 자료형을 사용합니다. 그냥 new Map() 쓰면 끝임   
가끔 Map 이라는 클래스를 직접 똑같이 만들어보는 것도 좋은 연습문제로 등장합니다.  

## Set 자료형

간단한 Array 자료형과 똑같이 생겼습니다.  
자료를 일렬로 쭉 저장할 수 있습니다.  
이렇게 만들 수 있습니다.  

```js
var 출석부2 = new Set([ 'john' , 'tom', 'andy', 'tom' ]);

console.log(출석부2);
```

출력해보면 아시겠지만 중괄호로 표현이 되죠?  
중괄호지만 Array와 유사하게 생겼습니다.   
또 다른 특징은 이 자료형은 중복자료를 절대 허용하지 않습니다.  
실수로 tom이라는걸 두개 집어넣었었는데, tom은 하나만 출력됩니다.   
이렇게 중복 데이터를 방지하고 싶을 때 쓰시면 유용한 자료형입니다.  

## Set 자료형 다루기

```js
var 출석부2 = new Set([ 'john' , 'tom', 'andy', 'tom' ]);

출석부2.add('sally'); //자료더하기 
출석부2.has('tom'); //자료있는지 확인
출석부2.size;  //자료 몇갠지 세기
```

물론 반복문도 돌릴 수 있습니다. forEach 혹은 for of 반복문을 씁니다.  
Set은 Map보다는 그나마 많이 씁니다.  

특히 Array의 데이터 중복제거할 때 많이 씁니다.  

왜냐면 Array를 Set으로 바꾸는게 매우 쉽기 때문입니다.  
한번 Array에 있는 중복데이터를 제거해봅시다.   

```js
var 출석부 = [ 'john' , 'tom', 'andy', 'tom' ];

var 출석부2 = new Set(출석부); //Array를 Set으로 바꾸기

출석부 = [...출석부2]  //Set을 Array로 바꾸기
```

이런 패턴으로 많이 합니다.  
위의 예제는 출석부라는 Array자료형을 Set으로 바꿨다가 다시 바로 Array로 바꾸는 예제입니다.  
그럼 이제 출석부에 있던 중복자료들이 자동으로 제거가 됩니다.  
