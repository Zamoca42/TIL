![javascript](https://user-images.githubusercontent.com/96982072/153997073-fa41822c-60eb-4f3e-b2b4-f257f073f2f4.png)

> 자바스크립트를 선택 한 이유는 프론트 부분에서 JS를 배우고 백엔드 부분인  
> Node를 배우는데 상대적으로 수월할거라고 생각했다.

> 2022/02/11 생활코딩 - 자바스크립트 시작

> 내용을 정리한 것보다 스크랩에 가까움

## 소개

기본적으로 자바스크립트는 HTML 위에서 동작하기 때문에HTML에 대한 이해가 조금 필요하다.

```
<script>alert('hello world');</script>
```

코드 `<script>`는 웹브라우저에게 지금부터는 자바스크립트 코드이기 때문에 이 코드를 해석 할 때는 자바스크립트의 문법에 따라서 해석해서 실행하라고 알려주는 구문(태그)다. alert('Hello world')는 경고창에 Hello world라는 문구를 출력하라는 일종의 명령이다. `</script>`는 자바스크립트 구간이 끝났기 때문에 이 후부터 나타나는 코드는 HTML의 문법으로 해석하라고 브라우저에게 알려주는 것이다.

## 숫자와 문자

### 수의 표현

자바스크립트에서는 큰따옴표나 작은따옴표가 붙지 않은 숫자는 숫자로 인식한다.

```
alert(1+1);
결과 2
alert(1.2 + 1.3);
결과 2.5
```

### 수의 연산

```
Math.pow(3,2);       // 9,   3의 2승
Math.round(10.6);    // 11,  10.6을 반올림
Math.ceil(10.2);     // 11,  10.2를 올림
Math.floor(10.6);    // 10,  10.6을 내림
Math.sqrt(9);        // 3,   3의 제곱근
Math.random();       // 0부터 1.0 사이의 랜덤한 숫자
```

### 문자

문자는 "(큰 따옴표) 혹은 '(작은 따옴표) 중의 하나로 감싸야 한다. 큰 따옴표로 시작하면 큰 따옴표로 끝나야하고, 작은 따옴표로 시작하면 작은 따옴표로 끝나야 한다. String이라고 한다.

```
alert("coding everybody");
alert('coding everybody');
```

숫자를 따옴표로 감싸면 문자가 된다. 아래는 문자다. typeof는 값의 데이터 형을 알려주는 기능이다.

```
alert(typeof "1")
```

결과 : string
아래와 같이 따옴표 없는 숫자는 number가 출력된다.

```
alert(typeof 1)
```

결과 : number

문자의 길이를 구할 때는 문자 뒤에 .length를 붙인다.

```
alert("coding everybody".length)
```

결과 : 16

## 변수

### 변수의 사용법

JavaScript에서 변수는 `var`로 시작한다. var은 변수를 선언하겠다는 것을 의미한다.  
var을 생략 할수도 있지만 이것은 유효범위라는 것에 영향을 미친다.  
그렇기 때문에 var의 의미를 명확하게 이해하기 전까지는 var를 사용하는 것이 권장된다.  
유효범위에 대해서는 뒤에서 살펴볼 것이다.  
변수의 이름은 `$`, `_`, 혹은 특수 문자를 제외한 모든 문자로 시작할 수 있다.

다음 예제는 변수에 값을 대입한 예제다.

```
var a = 1;
alert(a+1);  //2

var a = 2;
alert(a+1);  //3
```

## 비교 연산자

### ==

동등 연산자로 좌항과 우항을 비교해서 서로 값이 같다면 true 다르다면 false가 된다.
'='가 두개인 것을 주의하자.  
'='가 하나인 것은 대입 연산자로 우항의 값을 좌항의 변수에 대입할 때 사용하는 것으로 의미가 완전히 다르다.

```
alert(1==2)             //false
alert(1==1)             //true
alert("one"=="two")     //false
alert("one"=="one")     //true
```

### ===

일치 연산자로 `===` 좌항과 우항이 '정확'하게 같을 때 true 다르면 false가 된다.  
여기서 정확하다는 말의 의미에 집중하자. 아래 예를보자.

```
alert(1=='1');              //true
alert(1==='1');             //false
```

위의 결과는 이상하다. '==='는 숫자 1과 문자 1을 다르게 인식한다.  
반면에 '=='는 양쪽의 값을 같다고 판단한다. 바로 이것이 '정확'의 의미다.  
즉 ===는 서로 같은 수를 표현하고 있더라도 **데이터 형이 같은 경우**에만 같다고 판단하기 때문이다.  
결론부터 말하면 == 연산자 대신 === 연산자를 쓰는 것을 강력하게 권한다.  
몇가지 사례를 더 살펴보자.

```
alert(null == undefined);       //true
alert(null === undefined);      //false
alert(true == 1);               //true
alert(true === 1);              //false
alert(true == '1');             //true
alert(true === '1');            //false

alert(0 === -0);                //true
alert(NaN === NaN);             //false
```

null과 undefined는 값이 없다는 의미의 데이터 형이다.  
null은 값이 없음을 명시적으로 표시한 것이고, undefined는 그냥 값이 없는 상태라고 생각하자.  
NaN은 0/0과 같은 연산의 결과로 만들어지는 특수한 데이터 형인데 숫자가 아니라는 뜻이다.

### !=

'!'는 부정을 의미한다. '같다'의 부정은 '같지 않다'이다.  
이것을 기호로는 '!='로 표시한다. 아래의 결과는 !=의 결과인데 ==와 정반대의 결과를 보여준다.

```
alert(1!=2);            //true
alert(1!=1);            //false
alert("one"!="two");    //true
alert("one"!="one");    //false
```

### >

좌항이 우항보다 크다면 참, 그렇지 않다면 거짓임을 알려주는 연산자다. '<'는 반대의 의미로 언급은 생략하겠다.

```
alert(10>20);   //false
alert(10>1);    //true
alert(10>10);   //false
```

### >=

좌항이 우항보다 크거나 같다. '<='는 반대의 의미로 언급은 생략하겠다.

```
alert(10>=20);      //false
alert(10>=1);       //true
alert(10>=10);      //true
```

## 조건문

조건문이란 주어진 조건에 따라서 에플리케이션을 다르게 동작하도록 하는 것이다.

### if

조건문은 if로 시작한다. if 뒤의 괄호에 조건이 오고, 조건이 될 수 있는 값는 Boolean이다.  
Boolean의 값이 true라면 조건이 담겨진 괄호 다음의 중괄호 구문이 실행된다.  
아래 예제의 실행결과는 'result : true'다. if 뒤에 true가 왔기 때문이다.

```
if(true){
    alert('result : true');
}
```

다음 예제는 아무것도 출력하지 않을 것이다. if 뒤에 false가 왔기 때문이다.

```
if(false){
    alert('result : true');
}
```

### else

if만으로는 좀 더 복잡한 상황을 처리하는데 부족하다. 아래 예제를 보자. 결과는 1이다.

```
if(true){
    alert(1);
} else {
    alert(2);
}
```

다음 예제의 결과는 2다.

```
if(false){
    alert(1);
} else {
    alert(2);
}
```

if문의 조건이 true라면 if의 중괄호 구간이 실행되고, false라면 else 이후의 중괄호 구간이 실행된다.  
즉 else는 주어진 조건이 거짓일 때 실행할 구간을 정의하는 것이다.

### else if

else if를 이용하면 조건문을 좀 더 풍부하게 할 수 있다. 아래 예제를 보자. 결과는 2다.

```
if(false){
    alert(1);
} else if(true){
    alert(2);
} else if(true){
    alert(3);
} else {
    alert(4);
}
```

다음 예제의 결과는 3이다.

```
if(false){
    alert(1);
} else if(false){
    alert(2);
} else if(true){
    alert(3);
} else {
    alert(4);
}
```

다음 예제의 결과는 4다.

```
if(false){
    alert(1);
} else if(false){
    alert(2);
} else if(false){
    alert(3);
} else {
    alert(4);
}
```

else if는 좀 더 다양한 케이스의 조건을 검사할 수 있는 기회를 제공한다.  
else if의 특징은 if나 else와는 다르게 여러개가 올 수 있다는 점이다.  
else if의 모든 조건이 false라면 else가 실행된다. else는 생략 가능하다.

### 변수와 비교연산자

앞서 배운 변수와 비교연산자 그리고 조건문을 결합해보자.  
ID의 값으로 egoing을 입력해보고, 다른 값도 입력해보자.  
아래의 예제는 브라우저에서 실행해야 한다.  
다른 환경에서는 원하는데로 동작하지 않을 것이다.

```
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
</head>
<body>
    <script>
        id = prompt('아이디를 입력해주세요.')
        if(id=='egoing'){
            alert('아이디가 일치 합니다.')
        } else {
            alert('아이디가 일치하지 않습니다.')
        }
    </script>
</body>
</html>
```

위의 내용에서 prompt() 구문은 사용자가 입력한 값을 가져와서 id 변수의 값으로 대입한다.  
이러한 것을 API 또는 함수라고 부르는데, 이에 대한 내용은 곧 배운다.  
사용자가 입력한 값이 egoing이라면 '아이디가 일치 합니다'를 출력하고  
그렇지 않다면 '아이디가 일치하지 않습니다'를 출력한다.

### 기타 false로 간주되는 데이터형

다음은 false와 0 외에 false로 간주되는 데이터형의 리스트다.  
if문의 조건으로 !(부정) 연산자를 사용했기 때문에 각 조건문의 첫번째 블록이 실행되는 것은  
주어진 값이 false이기 때문이다.

```
if(!''){
    alert('빈 문자열')
}
if(!undefined){
    alert('undefined');
}
var a;
if(!a){
    alert('값이 할당되지 않은 변수');
}
if(!null){
    alert('null');
}
if(!NaN){
    alert('NaN');
}
```

## 반복문

### While

```
while(true){
    document.write('coding everybody <br />');
}
```

이번에는 true를 false로 바꾼 아래의 예제를 실행해보자. 아무런 결과도 출력하지 않을 것이다.

```
while(false){
    document.write('coding everybody <br />');
}
```

while문은 while문 뒤에 따라오는 괄호 안의 조건이 참(true)면 중괄호 안의 코드 구간을 반복적으로 실행한다.  
조건이 false면 반복문이 실행되지 않는다. 여기서 true와 false는 종료조건이 되는데,  
이 값을 변경하는 것을 통해서 반복문을 종료시킬 수 있다.
반복문에서 종료조건을 잘못 지정하면 무한반복이 되거나, 반복문이 실행되지 않는다.

### for

```
for(초기화; 반복조건; 반복이 될 때마다 실행되는 코드){
    반복해서 실행될 코드
}
```

다음 예제를 보자.

```
for(var i = 0; i < 10; i++){
    document.write('coding everybody'+i+'<br />');
}
```

for문은 제일 먼저 '초기화'를 한다. 위의 예제에서 초기화는 var i = 0;이다.  
즉 변수 i의 값을 0으로 설정한 것이다. 그 다음에는 '반복조건'인 i < 10이 실행된다.  
현재 i의 값은 0이다. 그렇기 때문에 이 조건은 참이다. 반복조건이 참이면 중괄호 안의 내용이 실행된다.  
i의 값이 0이기 때문에 `'coding everybody0<br />'`이라는 텍스트가 출력된다.  
 '반복해서 실행될 코드'의 실행이 끝나면 '반복이 될 때마다 실행되는 코드'가 실행된다.  
 i++는 현재 i의 값에 1을 더하라는 의미다. 현재 i의 값은 0이다. 따라서 i++의 결과로 i는 1이 되었다.  
 그리고 '반복조건'이 실행된다. 현재 i의 값은 1이기 때문에 i < 10은 참이다.
다시 '반복해서 실행될 코드'가 실행된다. 그렇게 반복해서 작업이 실행된다.  
 이 과정에서 i의 값은 반복 할 때마다 1씩 증가한다.  
 결국 i의 값이 10이 되는 순간 i < 10을 충족시키지 못하게 되고 반복문은 종료된다.

## 함수

함수(function)란 하나의 로직을 재실행 할 수 있도록 하는 것으로 코드의 **재사용성**을 높여준다.

### 함수의 형식

형식은 아래와 같다.

```
function 함수명( [인자...[,인자]] ){
   코드
   return 반환값
}
```

함수의 정의와 호출  
함수는 function 뒤에 함수의 이름이 오고, 소괄호가 따라온다.  
소괄호에 인자라는 값이 차례로 들어오는데 이 값은 함수를 호출할 때 함수의 로직으로 전달될 변수다.  
인자는 생략 할 수 있다. 함수를 호출 했을 때 실행하게 될 부분이 중괄호 안쪽에 온다.  
다음 예제를 보자. 이 함수의 이름은 numbering이고, 내용은 0부터 9까지를 화면에 출력한다.

```
function numbering(){
    i = 0;
    while(i < 10){
        document.write(i);
        i += 1;
    }
}
numbering();
```

위의 예제 제일 하단에 아래 구문에 의해서 numbering이라는 이름의 함수가 호출되고 있는 것이다.

```
numbering();
```

결과는 아래와 같다.

```
0123456789
```

numbering();을 여러번 실행하면서 그 결과를 살펴보자.

### 함수를 정의 하는 다른 방법

자바스크립트는 함수를 정의하는 또 다른 방법을 제공한다.  
다음 예제를 보자. 아래 방법은 함수를 정의 하는 또 다른 방법이다.

```
var numbering = function (){
    i = 0;
    while(i < 10){
        document.write(i);
        i += 1;
    }
}
numbering();
```

위의 내용은 이전 예제와 동일 하지만 함수를 정의 하는 방법을 달리한 것이다.

## 배열

### 배열의 생성

그렇다면 여러 개의 데이터를 하나의 변수에 담아서 관리할 수 있는 방법은 없을까?  
있다. 배열을 쓰면 된다. 변수 member에 회원정보를 담아보자.  
대괄호([])는 배열을 만드는 기호다. 대괄호 안에 데이터를 콤마(,)로 구분해서 나열하면 배열이 된다.

```
var member = ['egoing', 'k8805', 'sorialgi']
```

하나의 변수에 3개의 데이터를 담았다. 각각의 데이터를 원소(Element)이라고 부른다.  
자 그럼 이 데이터를 꺼내오려면 어떻게 해야 할까? 아래의 예제를 보자.

```
var member = ['egoing', 'k8805', 'sorialgi']
alert(member[0]);
alert(member[1]);
alert(member[2]);
```

결과는 아래의 문자열을 차례로 경고창으로 출력 할 것이다.

```
egoing
k8805
sorialgi
```

즉 배열에 담겨있는 값을 가져올 때는 대괄호 안에 숫자를 넣는다. 이 숫자를 색인(index)라고 부르고 0부터 시작한다.  
즉 첫번째 원소(egoing)를 가져오려면 대괄호 안에 0을 넣어주어야 한다는 것이다.
두번째는 1, 세번째는 2를 입력한다. 이 값을 이용해서 배열에 저정된 값을 가져올 수 있다.

### 배열의 조작

- 추가

  배열의 끝에 원소를 추가하는 방법이다.  
   `push`는 인자로 전달된 값을 배열(li)에 추가하는 명령이다. 배열 li의 값은 a, b, c, d, e, f가 됐다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li.push('f');
  alert(li);
  ```

  다음은 복수의 원소를 배열에 추가하는 방법이다. `concat`은 인자로 전달된 값을 추가하는 명령이다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li = li.concat(['f', 'g']);
  alert(li);
  ```

  다음은 배열의 시작점에 원소를 추가하는 방법이다. 배열 li는 z, a, b, c, d, e가 됐다.  
   `unshift`는 인자로 전달한 값을 배열의 첫번째 원소로 추가하고 배열의 기존 값들의 색인을 1씩 증가시킨다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li.unshift('z');
  alert(li);
  ```

  만약 두번째 인덱스 뒤에 대문자 B를 넣고 싶다면 아래와 같이한다.  
   `splice`는 첫번째 인자에 해당하는 원소부터 두번째 인자에 해당하는 원소의 숫자만큼의 값을 배열로부터 제거한 후에 리턴한다.  
   그리고 세번째 인자부터 전달된 인자들을 첫번째 인자의 원소 뒤에 추가한다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li.splice(2, 0, 'B');
  alert(li);
  ```

- 제거

  다음은 배열의 첫번째 원소를 제거하는 방법이다. `shift`를 사용하면 된다. 아래 결과는 b, c, d, e 다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li.shift();
  alert(li);
  ```

  다음은 배열 끝점의 원소를 배열 li에서 제거한다. 이때는 `pop`를 사용한다. 결과는 a, b, c, d 다.

  ```
  var li = ['a', 'b', 'c', 'd', 'e'];
  li.pop();
  alert(li);
  ```

- 정렬

  다음은 정렬하는 방법이다. 결과는 a, b, c, d, e 다.

  ```
  var li = ['c', 'e', 'a', 'b', 'd'];
  li.sort();
  alert(li);
  ```

  역순으로 정렬하고 싶을 때는 아래와 같이 한다.

  ```
  var li = ['c', 'e', 'a', 'b', 'd'];
  li.reverse();
  alert(li);
  ```

## 객체

지금까지 살펴본 배열은 아이템에 대한 식별자로 숫자를 사용했다.  
데이터가 추가되면 배열 전체에서 중복되지 않는 인덱스가 자동으로 만들어져서 추가된 데이터에 대한 식별자가 된다.  
이 인덱스를 이용해서 데이터를 가져오게 되는 것이다. 만약 인덱스로 문자를 사용하고 싶다면 객체(dictionary)를 사용해야 한다.  
다른 언어에서는 **연관배열(associative array)** 또는 **맵(map)**, **딕셔너리(Dictionary)**라는 데이터 타입이 객체에 해당한다.

### 객체의 생성

다음은 객체를 만드는 법이다.

```
var grades = {'egoing': 10, 'k8805': 6, 'sorialgi': 80};
```

위의 예제에서 egoing은 key가 되고, 10은 value가 된다. 아래는 객체를 만드는 다른 방법이다.

```
var grades = {};
grades['egoing'] = 10;
grades['k8805'] = 6;
grades['sorialgi'] = 80;
```

아래와 같은 방법으로 객체를 만들수도 있다.

```
var grades = new Object();
grades['egoing'] = 10;
grades['k8805'] = 6;
grades['sorialgi'] = 80;
```

객체를 만들었으니 이제는 객체에서 필요한 값을 가져와보자. 다음은 sorialgi라는 이름(key)으로 저장된 값을 가져오는 법이다. 결과는 80이다.

```
var grades = {'egoing': 10, 'k8805': 6, 'sorialgi': 80};
alert(grades['sorialgi']);
```

다음 방법으로도 객체의 속성에 접근 할 수 있다.

```
alert(grades.sorialgi);
```

다음은 객체에 저장된 데이터를 기준으로 반복작업을 하는 방법이다.

```
var grades = {'egoing': 10, 'k8805': 6, 'sorialgi': 80};
for(key in grades) {
    document.write("key : "+key+" value : "+grades[key]+"<br />");
}
```

결과는 아래와 같다.

```
key :   egoing value : 10
key :   k8805 value : 6
key :   sorialgi value : 80
```

for 문은 in 뒤에 따라오는 배열의 key 값을 in 앞의 변수 name에 담아서 반복문을 실행한다.  
반복문이 실행될 때 변수 key의 값으로 egoing, k8805, sorialgi가 순차적으로 할당되기 때문에  
`grades[key]`를 통해서 객체의 값을 알아낼 수 있다.

객체에는 객체를 담을수도 있고, 함수도 담을 수 있다.

```
var grades = {
    'list': {'egoing': 10, 'k8805': 6, 'sorialgi': 80},
    'show' : function(){
        for(var name in this.list){
            document.write(name+':'+this.list[name]+"<br />");
        }
    }
};
grades.show();
```

이것은 자바스크립트를 이용한 **객체 지향 프로그래밍 기법**의 핵심이 되는 성질로 취지에 따라서 로직을  
객체에 그룹핑해서 객체라는 부품을 조립해서 소프트웨어라는 완제품을 만들 수 있게 해준다.  
객체 지향에 대해서는 뒤에서 자세히 살펴본다.

### :pushpin: 궁금한점

```
var grades = {'egoing': 10, 'k8805': 6, 'sorialgi': 80};
for(key in grades) {
    console.log(grades.key)
}
```

객체의 속성을 불러올 때 점(.)을 사용해 불러 올 수 있는가?

- 점 표기법은 식별자로 동작한다는 한계가 있다.  
   변수로 접근 할 때에는 대괄호 표기법을 사용.
- [객체 속성 접근 방법](https://developer-talk.tistory.com/155)

## 모듈

프로그램은 작고 단순한 것에서 크고 복잡한 것으로 진화한다.  
그 과정에서 코드의 재활용성을 높이고, 유지보수를 쉽게 할 수 있는 다양한 기법들이 사용된다.  
그 중의 하나가 코드를 여러개의 파일로 분리하는 것이다. 이를 통해서 얻을 수 있는 효과는 아래와 같다.

- 자주 사용되는 코드를 별도의 파일로 만들어서 필요할 때마다 재활용할 수 있다.
- 코드를 개선하면 이를 사용하고 있는 모든 애플리케이션의 동작이 개선된다.
- 코드 수정 시에 필요한 로직을 빠르게 찾을 수 있다.
- 필요한 로직만을 로드해서 메모리의 낭비를 줄일 수 있다.
- 한번 다운로드된 모듈은 웹브라우저에 의해서 저장되기 때문에 동일한 로직을 로드 할 때
  시간과 네트워크 트래픽을 절약 할 수 있다. (브라우저에서만 해당)

### 모듈이란

순수한 자바스크립트에서는 모듈(module)이라는 개념이 분명하게 존재하지는 않는다.  
하지만 자바스크립트가 구동되는 호스트 환경에 따라서 서로 다른 모듈화 방법이 제공되고 있다.  
이 수업에서는 자바스크립트의 대표적인 호스트 환경인 웹브라우저에서 로직을 모듈화하는 방법에 대해서 알아볼 것이다.

### 모듈의 사용

새로운 파일을 만든다. 이름은 greeting.js 다. 자바스크립트 파일은 확장자로 js를 사용한다.

greeting.js

```
function welcome(){
    return 'Hello world';
}
```

main.html의 내용을 다음과 같이 변경한다.

main.html

```
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <script src="greeting.js"></script>
</head>
<body>
    <script>
        alert(welcome());
    </script>
</body>
</html>
```

이전 예제와 비교했을 때 결과는 같다. 하지만 함수 welcome을 main.html의 외부 파일로 분리했다. 다음은 위의 코드에 대한 분석이다.

```
<script src="greeting.js"></script>
```

JavaScript와 HTML은 완전히 다른 문법을 가진 언어다.  
그런데 HTML 문서 안에는 JavaScript와 HTML이 동시에 표현된다.  
따라서 브라우저에게 어디서부터 어디까지가 JavaScript이고, HTML인지를 구분해서 알려줘야 한다.  
이 역할을 하는 HTML 태그가 script 태그다.  
script 태그 안쪽에 위치하는 컨텐츠는 브라우저에 의해서 JavaScript로 인식된다.  
그런데 위의 코드는 컨텐츠 대신에 src 속성이 있다. 브라우저는 src 속성에 있는 파일을 다운로드해서 실행시킨다.  
greeting.js에는 함수 welcome가 정의되어 있기 때문에 main.html 안에 이 함수가 정의 되어 있지 않음에도 실행할 수 있는 것이다.

## 정규표현식

정규표현식은 문자열을 처리하기 위한 방법 중의 하나로 특정한 조건의 문자를 '검색'하거나 '치환'하는 과정을  
매우 간편하게 처리할 수 있도록 하는 수단이다.

### 정규표현식 패턴들

- 정규표현식은 기본적으로 대소문자를 구분한다.
- 캐럿(`^`)을 소스 앞에 오고 앞에 오는 문자열을 찾는다.
- 달러(`$`)는 소스 뒤에 오고 뒤에 오는 문자열을 찾는다.
- 백슬래시(`\`)는 정규표현식 문법이 아니라 문자로 취급할 수 있도록 바꿔준다.
- 점(`.`)은 모든 문자를 가리키는 표현식이다.
- 대괄호(`[]`)사이에 문자열을 사용하면 그 문자 하나를 소스에서 찾아준다.
- 대쉬(`-`)를 문자 사이에 사용하게 되면 해당 범위의 문자를 찾아준다
- 중괄호(`{}`)안에 숫자가 오면 숫자만큼의 문자를 찾는다

### 컴파일

컴파일은 검출하고자 하는 패턴을 만드는 일이다. 우선 정규표현식 객체를 만들어야 한다.  
객체를 만드는 방법은 두가지가 있다. a라는 텍스트를 찾아내는 정규표현식을 만들어보자.

- 정규표현식 리터럴
  ```
  var pattern = /a/;
  ```
- 정규표현식 객체 생성자
  ` var pattern = new RegExp('a'); `
  두가지 모두 같은 결과를 만들지만 각자가 장단점이 있다.

### 정규표현식 메소드 실행

정규표현식을 컴파일해서 객체를 만들었다면 이제 문자열에서 원하는 문자를 찾아내야 한다.

- RegExp.exec()

  ```
  console.log(pattern.exec('abcdef')); // ["a"]
  ```

  실행결과는 문자열 a를 값으로 하는 **배열**을 리턴한다.

  ```
  console.log(pattern.exec('bcdefg')); // null
  ```

  인자 'bcdef'에는 a가 없기 때문에 null을 리턴한다.

- RegExp.test()  
   test는 인자 안에 패턴에 해당되는 문자열이 있으면 true, 없으면 false를 리턴한다.
  ```
  console.log(pattern.test('abcdef')); // true
  cnosole.log(pattern.test('bcdefg')); // false
  ```

### 문자열 메소드 실행

문자열 객체의 몇몇 메소드는 정규표현식을 사용할 수 있다.

- String.match()  
   RegExp.exec()와 비슷하다.

  ```
  console.log('abcdef'.match(pattern)); // ["a"]
  console.log('bcdefg'.match(pattern)); // null
  ```

- String.replace()  
   문자열에서 패턴을 검색해서 이를 변경한 후에 변경된 값을 리턴한다.

  ```
  console.log('abcdef'.replace(pattern, 'A'));  // Abcdef
  ```

### 옵션

정규표현식 패턴을 만들 때 옵션을 설정할 수 있다. 옵션에 따라서 검출되는 데이터가 달라진다.

- i  
   i를 붙이면 대소문자를 구분하지 않는다.

  ```
  var xi = /a/;
  console.log("Abcde".match(xi)); // null
  var oi = /a/i;
  console.log("Abcde".match(oi)); // ["A"];
  ```

- g  
   g를 붙이면 검색된 모든 결과를 리턴한다.

  ```
  var xg = /a/;
  console.log("abcdea".match(xg));
  var og = /a/g;
  console.log("abcdea".match(og));
  ```

### 캡쳐

패턴 `(\w+)` 에서 괄호안의 `w`는 문자 `A~Z`, `a~z`, `0~9`의 모든 문자를 말하고  
`+`는 수량자로 w의 문자 범위에 포함된 문자 한개 이상을 의미한다.  
`\s`는 공백(space)을 의미한다.  
전체적인 구조는

<img src="https://user-images.githubusercontent.com/96982072/154000139-fb074d74-9275-4490-b538-df4882c7bda3.png" />

```
var pattern = /(\w+)\s(\w+)/;
var str = "coding everybody";
var result = str.replace(pattern, "$2, $1");
console.log(result);
```

괄호안의 패턴은 마치 변수처럼 재사용할 수 있다.  
이 때 기호 $를 사용하는데 아래 코드는 coding과 everybody의 순서를 역전시킨다.

### 치환

아래 코드는 본문 중의 URL을 링크 html 태그로 교체한다.

```
var urlPattern = /\b(?:https?):\/\/[a-z0-9-+&@#\/%?=~_|!:,.;]*/gim;
var content = '생활코딩 : http://opentutorials.org/course/1 입니다. 네이버 : http://naver.com 입니다. ';
var result = content.replace(urlPattern, function(url){
    return '<a href="'+url+'">'+url+'</a>';
});
console.log(result);
```

결과는 아래와 같다.

```
생활코딩 : <a href="http://opentutorials.org/course/1">http://opentutorials.org/course/1</a> 입니다.
네이버 : <a href="http://naver.com">http://naver.com</a> 입니다.

```

## 함수지향

### 전역변수와 지역변수

유효범위(Scope)는 변수의 수명을 의미한다. 아래의 예제를 보자. 결과는 global이다.

```
var vscope = 'global';
function fscope(){
    alert(vscope);
}
fscope();
```

함수 밖에서 변수를 선언하면 그 변수는 전역변수가 된다.  
전역변수는 에플리케이션 전역에서 접근이 가능한 변수다.  
다시 말해서 어떤 함수 안에서도 그 변수에 접근 할 수 있다.  
그렇기 때문에 함수 fscope 내에서 vscope를 호출 했을 때  
함수 밖에서 선언된 vscope의 값 global이 반환된 것이다.  
아래 예제를 보자. 결과는 '함수안 local'과 '함수밖 global'이 출력된다.

```
var vscope = 'global';
function fscope(){
    var vscope = 'local';
    alert('함수안 '+vscope);
}
fscope();
alert('함수밖 '+vscope);
```

즉 함수 안에서 변수 vscope을 조회(4행) 했을 때  
함수 내에서 선언한 지역변수 vscope(3행)의 값인 local이 사용되었다.  
하지만 함수 밖에서 vscope를 호출(7행) 했을 때는 전역변수 vscope(1행)의 값인 global이 사용된 것이다.  
즉 지역변수의 유효범위는 함수 안이고, 전역변수의 유효범위는 에플리케이션 전역인데,  
같은 이름의 지역변수와 전역변수가 동시에 정의되어 있다면 지역변수가 우선한다는 것을 알 수 있다.  
아래 예제를 보자. 결과는 모두 local이다.

```
var vscope = 'global';
function fscope(){
    vscope = 'local';
    alert('함수안'+vscope);
}
fscope();
alert('함수밖'+vscope);
```

함수밖에서도 vscope의 값이 local인 이유는 무엇일까?  
그것은 함수 fscope의 지역변수를 선언할 때 var를 사용하지 않았기 때문이다.  
var를 사용하지 않은 지역변수는 전역변수가 된다. 따라서 3행은 전역변수의 값을 local로 변경하게 된 것이다.  
var을 쓰는 것과 쓰지 않는 것의 차이를 이해해야 한다.

</br>

전역변수는 사용하지 않는 것이 좋다. 여러가지 이유로 그 값이 변경될 수 있기 때문이다.  
함수 안에서 전역변수를 사용하고 있는데, 누군가에 의해서 전역변수의 값이 달라졌다면 어떻게 될까?  
함수의 동작도 달라지게 된다. 이것은 버그의 원인이 된다.  
또한 함수를 다른 에플리케이션에 이식하는데도 어려움을 초래한다.  
함수의 핵심은 로직의 재활용이라는 점을 상기하자. 변수를 선언할 때는 꼭 var을 붙이는 것을 습관화해야 한다.  
<U> 전역변수를 사용해야 하는 경우라면 그것을 사용하는 이유를 명확히 알고 있을 때 사용하도록 하자. </U>

### 전역변수를 사용하는 법

불가피하게 전역변수를 사용해야 하는 경우는 하나의 객체를 전역변수로 만들고 객체의 속성으로 변수를 관리하는 방법을 사용한다.

```
var MYAPP = {}
MYAPP.calculator = {
    'left' : null,
    'right' : null
}
MYAPP.coordinate = {
    'left' : null,
    'right' : null
}

MYAPP.calculator.left = 10;
MYAPP.calculator.right = 20;
function sum(){
    return MYAPP.calculator.left + MYAPP.calculator.right;
}
document.write(sum());
```

전역변수를 사용하고 싶지 않다면 아래와 같이 익명함수를 호출함으로서 이러한 목적을 달성할 수 있다.

```
(function(){
    var MYAPP = {}
    MYAPP.calculator = {
        'left' : null,
        'right' : null
    }
    MYAPP.coordinate = {
        'left' : null,
        'right' : null
    }
    MYAPP.calculator.left = 10;
    MYAPP.calculator.right = 20;
    function sum(){
        return MYAPP.calculator.left + MYAPP.calculator.right;
    }
    document.write(sum());
}())
```

위와 같은 방법은 자바스크립트에서 로직을 모듈화하는 일반적인 방법이다.

### 유효범위의 대상

자바스크립트는 함수에 대한 유효범위만을 제공한다. 많은 언어들이 블록(대체로 {,})에 대한 유효범위를 제공하는 것과 다른 점이다. 아래 예제의 결과는 coding everybody이다.

```
for(var i = 0; i < 1; i++){
    var name = 'coding everybody';
}
alert(name);
```

자바에서는 아래의 코드는 허용되지 않는다. name은 지역변수로 for 문 안에서 선언 되었는데 이를 for문 밖에서 호출하고 있기 때문이다.

```
for(int i = 0; i < 10; i++){
    String name = "egoing";
}
System.out.println(name);
```

자바스크립트의 지역변수는 함수에서만 유효하다.

### 정적(Static) 유효범위

자바스크립트는 함수가 **선언된 시점**에서의 유효범위를 갖는다.  
이러한 유효범위의 방식을 정적 유효범위(static scoping), 혹은 렉시컬(lexical scoping)이라고 한다.

```
var i = 5;

function a(){
    var i = 10;
    b();
}

function b(){
    document.write(i);
}

a();
```

함수 b()가 사용된 시점이 아니라 선언된 시점에 전역변수 i가 들어간다.
실행 결과는 5이다.

### 값으로서의 함수

JavaScript에서는 함수도 객체다. 다시 말해서 일종의 값이다. 거의 모든 언어가 함수를 가지고 있다. JavaScript의 함수가 다른 언어의 함수와 다른 점은 함수가 값이 될 수 있다는 점이다.  
다음 예제를 통해서 그 의미를 알아보자.

```
function a(){} // var a = function(){}
```

위의 예제에서 함수 a는 변수 a에 담겨진 값이다. 또한 함수는 객체의 값으로 포함될 수 있다.  
이렇게 객체의 속성 값으로 담겨진 함수를 메소드(method)라고 부른다.

```
a = {
    b:function(){
    }
};
```

함수는 값이기 때문에 다른 함수의 인자로 전달 될수도 있다.  
아래 예제를 보자.

```
function cal(func, num){
    return func(num)
}
function increase(num){
    return num+1
}
function decrease(num){
    return num-1
}
alert(cal(increase, 1));
alert(cal(decrease, 1));
```

10행을 실행하면 함수 increase와 값 1이 함수 cal의 인자로 전달된다.  
함수 cal은 첫번째 인자로 전달된 increase를 실행하는데 이 때 두번째 인자의 값이 1을 인자로 전달한다.  
함수 increase은 계산된 결과를 리턴하고 cal은 다시 그 값을 리턴한다.

### 콜백

- 처리의 위임  
   값으로 사용될 수 있는 특성을 이용하면 함수의 인자를 함수로 전달할 수 있다.  
   값으로 전달된 함수는 호출될 수 있기 때문에 이를 이용하면 함수의 동작을 완전히 바꿀 수 있다.  
   인자로 전달된 함수 sortNumber의 구현에 따라서 sort의 동작방법이 완전히 바뀌게 된다.

  ```
  var numbers = [20, 10, 9,8,7,6,5,4,3,2,1];
  function sortNumber(a,b){
      // 위의 예제와 비교해서 a와 b의 순서를 바꾸면 정렬순서가 반대가 된다.
      return b-a;
  }
  alert(numbers.sort(sortNumber)); // array, [20,10,9,8,7,6,5,4,3,2,1]
  ```

- 비동기처리  
   콜백은 비동기처리에서도 유용하게 사용된다.  
   시간이 오래걸리는 작업이 있을 때 이 작업이 완료된 후에 처리해야 할 일을  
   콜백으로 지정하면 해당 작업이 끝났을 때 미리 등록한 작업을 실행하도록 할 수 있다.  
   다음 코드는 일반적인 환경에서는 작동하지 않고 서버 환경에서만 동작한다.
  datasource.json.js
  ```
  {"title":"JavaScript","author":"egoing"}
  ```
  demo1.html
  ````
  <!DOCTYPE html>
  <html>
  <head>
  <script src="//code.jquery.com/jquery-1.11.0.min.js"></script>
  </head>
  <body>
  <script type="text/javascript">
      $.get('./datasource.json.js', function(result){
          console.log(result);
      }, 'json');
  </script>
  </body>
  </html>
   ```
  ````

### 내부함수

자바스크립트는 함수 안에서 또 다른 함수를 선언할 수 있다.  
아래의 예제를 보자. 결과는 경고창에 coding everybody가 출력될 것이다.

```
function outter(){
    function inner(){
        var title = 'coding everybody';
        alert(title);
    }
    inner();
}
outter();
```

위의 예제에서 함수 outter의 내부에는 함수 inner가 정의 되어 있다.  
함수 inner를 내부 함수라고 한다.  
내부함수는 외부함수의 지역변수에 접근할 수 있다.
아래의 예제를 보자. 결과는 coding everybody이다.

```
function outter(){
    var title = 'coding everybody';
    function inner(){
        alert(title);
    }
    inner();
}
outter();
```

위의 예제는 내부함수 inner에서 title을 호출(4행)했을 때  
외부함수인 outter의 지역변수에 접근할 수 있음을 보여준다.

### 클로저란?

클로저(closure)는 내부함수와 밀접한 관계를 가지고 있는 주제다.  
내부함수는 외부함수의 지역변수에 접근 할 수 있는데  
외부함수의 실행이 끝나서 외부함수가 소멸된 이후에도 내부함수가 외부함수의 변수에 접근 할 수 있다.  
이러한 메커니즘을 클로저라고 한다. 아래 예제는 이전의 예제를 조금 변형한 것이다.  
결과는 경고창으로 coding everybody를 출력할 것이다.

```
function outter(){
    var title = 'coding everybody';
    return function(){
        alert(title);
    }
}
var inner = outter();
inner();
```

예제의 실행순서를 주의깊게 살펴보자. 7행에서 함수 outter를 호출하고 있다.  
그 결과가 변수 inner에 담긴다. 그 결과는 이름이 없는 함수다.  
실행이 8행으로 넘어오면 outter 함수는 실행이 끝났기 때문에  
이 함수의 지역변수는 소멸되는 것이 자연스럽다.  
하지만 8행에서 함수 inner를 실행했을 때 coding everybody가 출력된 것은  
외부함수의 지역변수 title이 소멸되지 않았다는 것을 의미한다.  
클로저란 내부함수가 외부함수의 지역변수에 접근 할 수 있고,  
외부함수는 외부함수의 지역변수를 사용하는 내부함수가 소멸될 때까지 소멸되지 않는 특성을 의미한다.

### private variable

조금 더 복잡한 아래 예제를 살펴보자.  
아래 예제는 클로저를 이용해서 영화의 제목을 저장하고 있는 객체를 정의하고 있다.

```
function factory_movie(title){
    return {
        get_title : function (){
            return title;
        },
        set_title : function(_title){
            title = _title
        }
    }
}
ghost = factory_movie('Ghost in the shell');
matrix = factory_movie('Matrix');

alert(ghost.get_title());
alert(matrix.get_title());

ghost.set_title('공각기동대');

alert(ghost.get_title());
alert(matrix.get_title());
```

위의 예제를 통해서 알 수 있는 것들을 정리해보면 아래와 같다.

1.  클로저는 객체의 메소드에서도 사용할 수 있다. 위의 예제는 함수의 리턴값으로 객체를 반환하고 있다.  
    이 객체는 메소드 get_title과 set_title을 가지고 있다.  
    이 메소드들은 외부함수인 factory_movie의 인자값으로 전달된 지역변수 title을 사용하고 있다.

2.  동일한 외부함수 안에서 만들어진 내부함수나 메소드는 외부함수의 지역변수를 공유한다.  
    17행에서 실행된 set_title은 외부함수 factory_movie의 지역변수 title의 값을 '공각기동대'로 변경했다.  
    19행에서 ghost.get_title();의 값이 '공각기동대'인 것은 set_title와 get_title 함수가 title의 값을 공유하고 있다는 의미다.

3.  그런데 똑같은 외부함수 factory_movie를 공유하고 있는 ghost와 matrix의 get_title의 결과는 서로 각각 다르다. 그것은 외부함수가 실행될 때마다 새로운 지역변수를 포함하는 클로저가 생성되기 때문에  
    ghost와 matrix는 **서로 완전히 독립된 객체**가 된다.

4.  factory_movie의 지역변수 title은 2행에서 정의된 객체의 메소드에서만 접근 할 수 있는 값이다.  
    이 말은 title의 값을 읽고 수정 할 수 있는 것은 factory_movie 메소드를 통해서 만들어진 객체 뿐이라는 의미다.  
    JavaScript는 기본적으로 Private한 속성을 지원하지 않는데, 클로저의 이러한 특성을 이용해서 Private한 속성을 사용할 수 있게된다.

        ```
        참고 Private 속성은 객체의 외부에서는 접근 할 수 없는 외부에 감춰진 속성이나 메소드를 의미한다.
        이를 통해서 객체의 내부에서만 사용해야 하는 값이 노출됨으로서 생길 수 있는 오류를 줄일 수 있다.
        자바와 같은 언어에서는 이러한 특성을 언어 문법 차원에서 지원하고 있다.
        ```

### arguments

함수에는 arguments라는 변수에 담긴 숨겨진 유사 배열이 있다.  
이 배열에는 함수를 호출할 때 입력한 인자가 담겨있다.  
아래 예제를 보자. 결과는 10이다.

```
function sum(){
    var i, _sum = 0;
    for(i = 0; i < arguments.length; i++){
        document.write(i+' : '+arguments[i]+'<br />');
        _sum += arguments[i];
    }
    return _sum;
}
document.write('result : ' + sum(1,2,3,4));
```

함수 sum은 인자로 전달된 값을 모두 더해서 리턴하는 함수다.  
그런데 1행처럼 함수 sum은 인자에 대한 정의가 없다.  
하지만 마지막 라인에서는 4개의 인자를 함수 sum으로 전달하고 있다.  
함수의 정의부분에서 인자에 대한 구현이 없음에도 인자를 전달 할 수 있는 것은 왜 그럴까?  
그것은 arguments라는 특수한 배열이 있기 때문이다.

arguments는 함수안에서 사용할 수 있도록 그 이름이나 특성이 약속되어 있는 일종의 배열이다.  
`arguments[0]`은 함수로 전달된 첫번째 인자를 알아낼 수 있다.  
또 arguments.length를 이용해서 함수로 전달된 인자의 개수를 알아낼 수도 있다.  
이러한 특성에 반복문을 결합하면 함수로 전달된 인자의 값을 순차적으로 가져올 수 있다.  
그 값을 더해서 리턴하면 인자로 전달된 값에 대한 총합을 구하는 함수를 만들 수 있다.

### 매개변수의 수

매개변수와 관련된 두가지 수가 있다.  
하나는 function.length, 다른 하나는 arguments.length이다.  
arguments.length는 함수로 전달된 **실제 인자의 수**를 의미하고,  
함수.length는 함수에 **정의된 인자의 수**를 의미한다. 아래의 코드를 보자.

```
function zero(){
    console.log(
        'zero.length', zero.length,
        'arguments', arguments.length
    );
}
function one(arg1){
    console.log(
        'one.length', one.length,
        'arguments', arguments.length
    );
}
function two(arg1, arg2){
    console.log(
        'two.length', two.length,
        'arguments', arguments.length
    );
}
zero(); // zero.length 0 arguments 0
one('val1', 'val2');  // one.length 1 arguments 2
two('val1');  // two.length 2 arguments 1
```

### 함수의 호출

JavaScript는 함수를 호출하는 특별한 방법을 제공한다. 본 토픽의 시작에서 함수를 객체라고 했다.  
함수는 객체 Function이 가지고 있는 메소드들을 상속하고 있다.  
지금 이야기하려는 메소드는 Function.apply과 Function.call이다.  
이 메소드들을 이용해서 함수를 호출해보자. 결과는 3이다.

```
function sum(arg1, arg2){
    return arg1+arg2;
}
alert(sum.apply(null, [1,2]))
```

함수 sum은 Function 객체의 인스턴스다. 그렇기 때문에 객체 Function 의 메소드 apply를 호출 할 수 있다.  
apply 메소드는 두개의 인자를 가질 수 있는데, 첫번째 인자는 함수(sum)가 실행될 맥락이다.  
맥락의 의미는 다음 예제를 통해서 살펴보자.  
두번째 인자는 배열인데, 이 배열의 담겨있는 원소가 함수(sum)의 인자로 순차적으로 대입된다.  
Function.call은 사용법이 거의 비슷하다 여기서는 언급하지 않는다.

좀 더 흥미로운 예제를 살펴보자. 결과는 6과 185이다.

```
o1 = {val1:1, val2:2, val3:3}
o2 = {v1:10, v2:50, v3:100, v4:25}
function sum(){
    var _sum = 0;
    for(name in this){
        _sum += this[name];
    }
    return _sum;
}
alert(sum.apply(o1)) // 6
alert(sum.apply(o2)) // 185
```

예제가 복잡해보이지만 한나씩 분해해서 생각해보면 어렵지 않다.

우선 두개의 객체를 만들었다. o1는 3개의 속성을 가지고 있다.  
각각의 이름은 val1, val2,val3이다.  
o2는 4개의 속성을 가지고 있고 o1과는 다른 속성 이름을 가지고 있고 속성의 수도 다르다.

그 다음엔 함수 sum을 만들었다.  
이 함수는 객체의 속성을 열거할 때 사용하는 for in 문을 이용해서
객체 자신(this)의 값을 열거한 후에 각 속성의 값을 지역변수 \_sum에 저장한 후에 이를 리턴하고 있다.

객체 Function의 메소드 apply의 첫번째 인자는 함수가 실행될 맥락이다.  
`sum.apply(o1)`은 함수 sum을 객체 o1의 메소드로 만들고 sum을 호출한 후에 sum을 삭제한다.  
아래와 비슷하다.

```
o1.sum = sum;
alert(o1.sum());
delete o1.sum();
```

sum의 o1 소속의 메소드가 된다는 것은 이렇게 바꿔 말할 수 있다.  
함수 sum에서 this의 값이 전역객체가 아니라 o1이 된다는 의미다.  
일반적인 객체지향 언어에서는 하나의 객체에 소속된 함수는 그 객체의 소유물이 된다.  
하지만 JavaScript에서 함수는 독립적인 객체로서 존재하고,  
apply나 call 메소드를 통해서 다른 객체의 소유물인 것처럼 실행할 수 있다.

## 객체 지향 프로그래밍

객체지향 프로그래밍(Object-Oriented Programming)은 좀 더 나은 프로그램을 만들기 위한 프로그래밍 패러다임으로 로직을 상태(state)와 행위(behave)로 이루어진 객체로 만드는 것이다.  
이 객체들을 마치 레고 블럭처럼 조립해서 하나의 프로그램을 만드는 것이 객체지향 프로그래밍이라고 할 수 있다.  
다시 말해서 객체지향 프로그래밍은 객체를 만드는 것이다.  
따라서 객체지향 프로그래밍의 시작은 객체란 무엇인가를 이해하는 것이라고 할 수 있다.  
말이 어렵게 느껴지지 않는가? 그것은 아직 객체 지향에 대한 체험이 없기 때문이다.  
본 수업에서는 객체 지향에 대해서 코드 없이 이야기 할 수 있는 것들에 대해서만 이야기 할 생각이다.  
객체 지향에 대한 오리엔테이션이라고 생각하고 가벼운 마음으로 나머지 내용을 읽어보자.

```md
객체지향 프로그래밍을 학습하는데 장애 중의 하나는 번역이다.  
Object를 번역한 객체는 현실에서는 거의 쓰지 않는 말이고, 철학적인 느낌을 자아낸다.  
그래서 객체지향 프로그래밍을 처음 접하는 입문자들은  
객체지향 프로그래밍을 철학적인 탐구의 대상으로 파악하는 경향을 보이는데,  
이것은 공부를 어렵게 할 뿐 도움이 되지 않는다.  
쉽게 생각하자. 객체는 변수와 **메소드를 그룹핑**한 것이다.
```

### 추상화 (Abstract)

- 문법과 설계

  객체지향 프로그래밍 교육은 크게 두 가지로 구분된다.

- 문법

  하나는 객체지향을 편하게 할 수 있도록 언어가 제공하는 기능을 익히는 것이다.  
   이러한 기능들은 if, for문처럼 문법적인 구성을 가지고 있다.  
   이 문법을 이해하고, 숙지해야 객체를 만들 수 있다.  
   객체를 만드는 법에 대한 학습이라고 할 수 있다.

- 설계

  두번째는 좋은 객체를 만드는 법이다. 이것을 다른 말로는 설계를 잘하는 법이라고 할 수 있다.  
   좋은 설계는 현실을 잘 반영해야 한다. 현실은 복잡하다.  
   하지만 그 복잡함 전체가 필요한 것은 아니다. 아래의 그림을 보자.
  <img src="https://user-images.githubusercontent.com/96982072/154267790-3b733ee9-1469-4c3d-8c63-92ba38353020.gif"/>

  위의 그림은 런던의 지도다. 여러분이 지하철을 이용한다면 어떤 지도를 선호할까?  
   오른쪽 하단의 지도를 선호할 것이다. 왼쪽 상단의 지도는 현실의 복잡함을 나타낸다.  
   오른쪽 하단의 지도는 지하철 탑승자의 관심사만을 반영하고 있다.  
   역 간의 거리나 실제 위치와 같은 요소들은 모두 배제하고 있다.  
   복잡함 속에서 필요한 관점만을 추출하는 행위를 **추상화**라고 한다.

  지하철 노선도가 디자인의 추상화라고 한다면 프로그램을 만든다는 것은 소프트웨어의 추상화라고 할 수 있다.  
   객체 지향 프로그래밍은 좀 더 현실을 잘 반영하기 위한 노력의 산물이다.  
   이것은 단순히 객체 지향의 문법을 이용해서 객체를 만든다고 달성되는 것이 아니다.  
   고도의 추상화 능력이 필요하다. 좋은 설계는 문법을 배우는 것보다 훨씬 어려운 일이다.  
   심지어 이것은 지식을 넘어서 지혜의 영역이다.  
   좋은 설계를 위한 조언들은 많지만 이러한 조언들은 조언자의 입을 떠나는 순간 생명력을 잃어버린다.  
   지식은 전수되지만 지혜는 전수되지 않기 때문이다. 스스로 경험하고 깨우쳐서 자기화시켜야 한다.

  객체지향의 설계 원칙이나 객체 지향의 철학적인 의미는 대단히 중요하다.  
   하지만 이러한 것들을 지금 언급한다면 여러분은 미궁 속에 빠지게 될 것이다.  
   그래서 필자가 제안하는 것은 일단은 지식부터 익히자는 것이다.  
   언어가 지원하는 객체지향 문법을 배우고, 이것들이 어떻게 동작하는지를 충분히 이해한 다음에  
   비로소 설계 원칙도 이야기할 수 있고, 객체와 사물의 비유도 시도해 볼 수 있을 것이다.  
   여기서는 몇 가지 객체지향이 추구하는 지향점을 가볍게 이야기하고 다음 토픽부터 구체적인 문법을 알아볼 것이다.

### 부품화

객체 지향은 부품화의 정점이라고 할 수 있다. 하지만 우리는 아직 객체 지향을 배우지 않았다.  
그래서 우리가 배운 것 중에서 부품화의 특성을 보여줄 수 있는 기능을 생각해보면 좋을 것 같다.  
메소드는 부품화의 예라고 할 수 있다.  
메소드를 사용하는 기본 취지는 연관되어 있는 로직들을 결합해서 메소드라는 완제품을 만드는 것이다.  
그리고 이 메소드들을 부품으로 해서 하나의 완제품인 독립된 프로그램을 만드는 것이다.  
메소드를 사용하면 코드의 양을 극적으로 줄일 수 있고, 메소드 별로 기능이 분류되어 있기 때문에  
필요한 코드를 찾기도 쉽고 문제의 진단도 빨라진다.

그런데 프로그램이 커지면 엄청나게 많은 메소드들이 생겨나게 된다.  
메소드와 변수를 관리하는 것은 점점 어려운 일이 되기 시작한다.  
급기야는 메소드가 없을 때와 같은 상황에 봉착하게 된다.  
메소드는 프로그래밍의 역사에서 중요한 도약이었지만,  
이 도약이 성숙하면서 새로운 도약지점이 보이기 시작한 것이다.

그 도약 중의 하나가 객체 지향 프로그래밍이다.  
이것의 핵심은 연관된 메소드와 그 메소드가 사용하는 변수들을 분류하고 그룹핑하는 것이다.  
바로 그렇게 그룹핑 한 대상이 객체(Object)다.  
비유하자면 파일과 디렉토리가 있을 때 메소드나 변수가 파일이라면  
이 파일을 그룹핑하는 디렉토리가 객체라고 할 수 있다.  
이를 통해서 더 큰 단위의 부품을 만들 수 있게 되었다.  
객체를 만드는 법에 대해서 호기심이 생기지 않는가?  
이런 호기심을 유발시키는 것이 이번 토픽의 목적이다.  
객체를 만드는 법은 다음 토픽에서 알아보고 지금은 부품화에 대해서 조금 더 생각해보자.

### 은닉화, 캡슐화

그런데 부품화라고 하는 목표는 단순히 동일한 기능을 하는 메소드와 변수를 그룹핑한다고 달성되는 것은 아니다.  
제대로된 부품이라면 그것이 어떻게 만들어졌는지 모르는 사람도 그 부품을 사용하는 방법만 알면 쓸 수 있어야 한다.  
이를테면 모니터가 어떻게 동작하는지 몰라도 컴퓨터와 모니터를 연결하는 방법만 알면
화면을 표시 할 수 있는 것과 같은 이치다.  
즉 내부의 동작 방법을 단단한 케이스 안으로 숨기고 사용자에게는 그 부품의 사용방법만을 노출하고 있는 것이다.  
이러한 컨셉을 정보의 은닉화(Information Hiding), 또는 캡슐화(Encapsulation)라고 부른다.  
자연스럽게 사용자에게는 그 부품을 사용하는 방법이 중요한 것이 된다.

### 자바스크립트의 객체 지향

- 객체

  객체란 서로 연관된 변수와 함수를 그룹핑한 그릇이라고 할 수 있다.  
   객체 내의 변수를 프로퍼티(property) 함수를 메소드(method)라고 부른다.  
   객체를 만들어보자.

  ```
  var person = {}
  person.name = 'egoing';
  person.introduce = function(){
      return 'My name is '+this.name;
  }
  document.write(person.introduce());
  ```

  객체를 만드는 과정에 분산되어 있다. 객체를 정의 할 때 값을 셋팅하도록 코드를 바꿔보자.

  ```
  var person = {
      'name' : 'egoing',
      'introduce' : function(){
          return 'My name is '+this.name;
      }
  }
  document.write(person.introduce());
  ```

  만약 다른 사람의 이름을 담을 객체가 필요하다면 객체의 정의를 반복해야 할 것이다.  
   객체의 구조를 재활용할 수 있는 방법이 필요하다.
  이 때 사용하는 것이 생성자다.

- 생성자

  생성자(constructor)는 객체를 만드는 역할을 하는 함수다.  
   자바스크립트에서 함수는 재사용 가능한 로직의 묶음이 아니라 객체를 만드는 창조자라고 할 수 있다.

  ```
  function Person(){}
  var p = new Person();
  p.name = 'egoing';
  p.introduce = function(){
      return 'My name is '+this.name;
  }
  document.write(p.introduce());
  ```

  함수를 호출할 때 new을 붙이면 새로운 객체를 만든 후에 이를 리턴한다.  
   위의 코드는 새로운 객체를 변수 p에 담았다.  
   여러사람을 위한 객체를 만든다면 아래와 같이 코드를 작성해야 할 것이다.

  ```
  function Person(){}
  var p1 = new Person();
  p1.name = 'egoing';
  p1.introduce = function(){
      return 'My name is '+this.name;
  }
  document.write(p1.introduce()+"<br />");

  var p2 = new Person();
  p2.name = 'leezche';
  p2.introduce = function(){
      return 'My name is '+this.name;
  }
  document.write(p2.introduce());
  ```

  별로 개선된 것이 없다.

  ```
  function Person(name){
      this.name = name;
      this.introduce = function(){
          return 'My name is '+this.name;
      }
  }
  var p1 = new Person('egoing');
  document.write(p1.introduce()+"<br />");

  var p2 = new Person('leezche');
  document.write(p2.introduce());
  ```

  생성자 내에서 이 객체의 프로퍼티를 정의하고 있다.  
   이러한 작업을 초기화라고 한다. 이를 통해서 코드의 재사용성이 대폭 높아졌다.  
   코드를 통해서 알 수 있듯이 생성자 함수는 일반함수와 구분하기 위해서 **첫글자를 대문자**로 표시한다.  


### 전역객체

전역객체(Global object)는 특수한 객체다. 모든 객체는 이 전역객체의 프로퍼티다.

```
function func(){
    alert('Hello?');
}
func();
window.func();
```

`func();`와 `window.func();`는 모두 실행이 된다.  
모든 전역변수와 함수는 사실 window 객체의 프로퍼티다.  
객체를 명시하지 않으면 암시적으로 window의 프로퍼티로 간주된다.

```
var o = {'func':function(){
    alert('Hello?');
}}
o.func();
window.o.func();
```

자바스크립트에서 모든 객체는 기본적으로 전역객체의 프로퍼티임을 알 수 있다.

### 함수와 this

this는 함수 내에서 함수 호출 맥락(context)를 의미한다.  
맥락이라는 것은 상황에 따라서 달라진다는 의미인데  
즉 함수를 어떻게 호출하느냐에 따라서 this가 가리키는 대상이 달라진다는 뜻이다.  
함수와 객체의 관계가 느슨한 자바스크립트에서 this는  
이 둘을 연결시켜주는 실질적인 연결점의 역할을 한다.

- 함수호출

  함수를 호출했을 때 this는 무엇을 가르키는지 살펴보자. this는 전역객체인 window와 같다.

  ```
  function func(){
      if(window === this){
          document.write("window === this");
      }
  }
  func();
  ```

  결과

  ```
  window === this
  ```

### 메소드와 this

객체의 소속인 메소드의 this는 그 객체를 가르킨다.

```
var o = {
    func : function(){
        if(o === this){
            document.write("o === this");
        }
    }
}
o.func();
```

결과

```
o === this
```

### 생성자와 this

아래 코드는 함수를 호출했을 때와 new를 이용해서 생성자를 호출했을 때의 차이를 보여준다.

```
var funcThis = null;

function Func(){
    funcThis = this;
}
var o1 = Func();
if(funcThis === window){
    document.write('window <br />');
}

var o2 = new Func();
if(funcThis === o2){
    document.write('o2 <br />');
}
```

결과

```
window
o2
```

생성자는 빈 객체를 만든다. 그리고 이 객체내에서 this는 만들어진 객체를 가르킨다.  
이것은 매우 중요한 사실이다.  
생성자가 실행되기 전까지는 객체는 변수에도 할당될 수 없기 때문에  
this가 아니면 객체에 대한 어떠한 작업을 할 수 없기 때문이다.

```
function Func(){
    document.write(o);
}
var o = new Func();
```

결과는 아래와 같다.

```
undefined
```

위에서 여러가지 this의 사용법을 알아보았지만, this의 메커니즘은 모두 비슷하다.

### apply와 this

함수의 메소드인 apply, call을 이용하면 this의 값을 제어할 수 있다.

```
var o = {}
var p = {}
function func(){
    switch(this){
        case o:
            document.write('o<br />');
            break;
        case p:
            document.write('p<br />');
            break;
        case window:
            document.write('window<br />');
            break;
    }
}
func();
func.apply(o);
func.apply(p);
```

결과

```
window
o
p
```

### 상속(inheritance)

객체는 연관된 로직들로 이루어진 작은 프로그램이라고 할 수 있다.  
상속은 객체의 로직을 그대로 물려 받는 또 다른 객체를 만들 수 있는 기능을 의미한다.  
단순히 물려받는 것이라면 의미가 없을 것이다.  
기존의 로직을 수정하고 변경해서 파생된 새로운 객체를 만들 수 있게 해준다.

아래 코드는 이전 시간에 살펴본 코드다.

```
function Person(name){
    this.name = name;
    this.introduce = function(){
        return 'My name is '+this.name;
    }
}
var p1 = new Person('egoing');
document.write(p1.introduce()+"<br />");
```

결과

```
My name is egoing
```

위의 코드를 아래와 같이 바꿔보자.

```
function Person(name){
    this.name = name;
}
Person.prototype.name=null;
Person.prototype.introduce = function(){
    return 'My name is '+this.name;
}
var p1 = new Person('egoing');
document.write(p1.introduce()+"<br />");
```

결과는 같다. 하지만 상속을 위한 기본적인 준비를 마쳤다. 이제 상속을 해보자.

```
function Person(name){
    this.name = name;
}
Person.prototype.name=null;
Person.prototype.introduce = function(){
    return 'My name is '+this.name;
}

function Programmer(name){
    this.name = name;
}
Programmer.prototype = new Person();

var p1 = new Programmer('egoing');
document.write(p1.introduce()+"<br />");
```

Programmer이라는 생성자를 만들었다.  
그리고 이 생성자의 prototype과 Person의 객체를 연결했더니  
Programmer 객체도 메소드 introduce를 사용할 수 있게 되었다.

Programmer가 Person의 기능을 상속하고 있는 것이다.  
단순히 똑같은 기능을 갖게 되는 것이라면 상속의 의의는 사라질 것이다.  
부모의 기능을 계승 발전할 수 있는 것이 상속의 가치다.

```
function Person(name){
    this.name = name;
}
Person.prototype.name=null;
Person.prototype.introduce = function(){
    return 'My name is '+this.name;
}

function Programmer(name){
    this.name = name;
}
Programmer.prototype = new Person();
Programmer.prototype.coding = function(){
    return "hello world";
}

var p1 = new Programmer('egoing');
document.write(p1.introduce()+"<br />");
document.write(p1.coding()+"<br />");
```

결과

```
My name is egoing
hello world
```

Programmer는 Person의 기능을 가지고 있으면서  
Person이 가지고 있지 않은 기능인 메소드 coding을 가지고 있다.

### Prototype

그럼 prototype이란 무엇인가?  
한국어로는 원형정도로 번역되는 prototype은 말 그대로 객체의 원형이라고 할 수 있다.  
함수는 객체다. 그러므로 생성자로 사용될 함수도 객체다.  
객체는 프로퍼티를 가질 수 있는데 prototype이라는 프로퍼티는  
그 용도가 약속되어 있는 특수한 프로퍼티다.  
prototype에 저장된 속성들은 생성자를 통해서 객체가 만들어질 때 그 객체에 연결된다.

```
function Ultra(){}
Ultra.prototype.ultraProp = true;

function Super(){}
Super.prototype = new Ultra();

function Sub(){}
Sub.prototype = new Super();

var o = new Sub();
console.log(o.ultraProp);
```

결과는 true다.

### Prototype Chain

생성자 Sub를 통해서 만들어진 객체 o가  
Ultra의 프로퍼티 ultraProp에 접근 가능한 것은  
prototype 체인으로 Sub와 Ultra가 연결되어 있기 때문이다.  
내부적으로는 아래와 같은 일이 일어난다.

1. 객체 o에서 ultraProp를 찾는다.
2. 없다면 Sub.prototype.ultraProp를 찾는다.
3. 없다면 Super.prototype.ultraProp를 찾는다.
4. 없다면 Ultra.prototype.ultraProp를 찾는다.

prototype는 객체와 객체를 연결하는 체인의 역할을 하는 것이다.  
이러한 관계를 prototype chain이라고 한다.

### 표준 내장 객체

표준 내장 객체(Standard Built-in Object)는  
자바스크립트가 기본적으로 가지고 있는 객체들을 의미한다.  
내장 객체가 중요한 이유는 프로그래밍을 하는데 기본적으로 필요한 도구들이기 때문에다.  
결국 프로그래밍이라는 것은 언어와 호스트 환경에 제공하는 기능들을 통해서  
새로운 소프트웨어를 만들어내는 것이기 때문에 내장 객체에 대한 이해는  
프로그래밍의 기본이라고 할 수 있다.  
자바스크립트는 아래와 같은 내장 객체를 가지고 있다.

- Object
- Function
- Array
- String
- Boolean
- Number
- Math
- Date
- RegExp

이제 우리는 내장객체가 무엇인지를 보다 잘 이해할 수 있게 되었다.  
new가 무엇인지, 함수가 객체를 어떻게 만드는지도 알았다.  
또 원한다면 자바스크립트의 내장 객체와 같은 것을 우리도 만들 수 있다는 것도 알았다.

### 배열의 확장

배열을 확장해보자. 아래 코드는 배열에서 특정한 값을 랜덤하게 추출하는 코드다.

```
var arr = new Array('seoul','new york','ladarkh','pusan', 'Tsukuba');
function getRandomValueFromArray(arr){
    var index = Math.floor(arr.length*Math.random());
    return arr[index];
}
console.log(getRandomValueFromArray(arr));
```

이렇게 작성해도 된다! 잘못한 것이 아니다.  
하지만 조금 더 세련된 방법은 이 함수를 배열 객체에 포함시키는 것이다.  
그렇게하면 마치 배열에 내장된 메소드인 것처럼 위의 기능을 사용할 수 있다.

```
//위의 예제에 이어서

Array.prototype.rand = function(){
    var index = Math.floor(this.length*Math.random());
    return this[index];
}
var arr = new Array('seoul','new york','ladarkh','pusan', 'Tsukuba');
console.log(arr.rand());
```

### Object

Object 객체는 객체의 가장 기본적인 형태를 가지고 있는 객체이다.  
다시 말해서 아무것도 상속받지 않는 순수한 객체다.  
자바스크립트에서는 값을 저장하는 기본적인 단위로 Object를 사용한다.

```
var grades = {'egoing': 10, 'k8805': 6, 'sorialgi': 80};
```

동시에 자바스크립트의 모든 객체는 Object 객체를 상속 받는데,  
그런 이유로 모든 객체는 Object 객체의 프로퍼티를 가지고 있다.

[MDN Javascript 문서 - Object](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object)

또한 Object 객체를 확장하면 모든 객체가 접근할 수 있는 API를 만들 수 있다.  
아래는 Object 객체를 확장한 사례다.

```
Object.prototype.contain = function(neddle) {
    for(var name in this){
        if(this[name] === neddle){
            return true;
        }
    }
    return false;
}
var o = {'name':'egoing', 'city':'seoul'}
console.log(o.contain('egoing'));
var a = ['egoing','leezche','grapittie'];
console.log(a.contain('leezche'));
```

그런데 Object 객체는 확장하지 않는 것이 바람직하다.  
왜냐하면 모든 객체에 영향을 주기 때문이다.

확장 후에 아래 코드를 실행해보자.

```
for(var name in o){
    console.log(name);
}
```

결과

```
name
contain
```

확장한 프로퍼티인 contain이 포함되어 있다.  
객체가 기본적으로 가지고 있을 것으로 예상하고 있는 객체 외에  
다른 객체를 가지고 있는 것은 개발자들에게 혼란을 준다. 이 문제를 회피하기 위해서는  
프로퍼티의 해당 객체의 소속인지를 체크해볼 수 있는 hasOwnProperty를 사용하면 된다.

```
for(var name in o){
    if(o.hasOwnProperty(name))
        console.log(name);
}
```

hasOwnProperty는 인자로 전달된 속성의 이름이 객체의 속성인지 여부를 판단한다.  
만약 prototype으로 상속 받은 객체라면 false가 된다.

### 데이터 타입

이제 데이터 타입에 대해서 조금 더 심도 있는 이야기를 할 수 있게 되었다.  
데이터 타입이란 데이터의 형태를 의미한다.  
데이터 타입은 크게 두가지로 구분할 수 있다.  
객체와 객체가 아닌 것. 그럼 객체가 아닌 것은 무엇일까?

- 숫자 -> number
- 문자열 -> string
- 불리언(true/false) -> Boolean
- null -> X
- undefined -> X

객체가 아닌 데이터 타입을 원시 데이터 타입(primitive type)이라고 한다.  
그 외의 모든 데이터 타입들은 객체다.

### 레퍼 객체(Wrapper Object)

아래 코드를 보자.

```
var str = 'coding';             // '' -> Object access Operator
console.log(str.length);        // 6
console.log(str.charAt(0));     // "C"
```

문자열은 분명히 프로퍼티와 메소드가 있다. 그렇다면 객체다.  
그런데 왜 문자열이 객체가 아니라고 할까?  
그것은 내부적으로 문자열이 원시 데이터 타입이고  
문자열과 관련된 어떤 작업을 하려고 할 때  
자바스크립트는 임시로 문자열 객체를 만들고 사용이 끝나면 제거하기 때문이다.  
이러한 처리는 내부적으로 일어난다. 그렇기 때문에 몰라도 된다.  
하지만 원시 데이터 타입과 객체는 좀 다른 동작 방법을 가지고 있기 때문에  
이들을 분별하는 것은 결국엔 필요하다.

```
var str = 'coding';
str.prop = 'everybody';
console.log(str.prop);      // undefined
```

`str.prop`를 하는 순간에 자바스크립트 내부적으로 String 객체가 만들어진다.  
prop 프로퍼티는 이 객체에 저장되고 이 객체는 곧 제거 된다.  
그렇기 때문에 prop라는 속성이 저장된 객체는 존재하지 않게된다.  
이러한 특징은 일반적인 객체의 동작 방법과는 다르다.

하지만 문자열과 관련해서 필요한 기능성을 객체지향적으로 제공해야 하는 필요 또한 있기 때문에  
원시 데이터 형을 객체처럼 다룰 수 있도록 하기 위한 객체를  
자바스크립트는 제공하고 있는데 그것이 레퍼객체(wrapper object)다.

레퍼객체로는 String, Number, Boolean이 있다.  
null과 undefined는 레퍼 객체가 존재하지 않는다.

### 참조

- 복제  
   전자화된 시스템의 가장 중요한 특징은 복제다.  
   현실의 사물과 다르게 전자화된 시스템 위의 데이터를 복제 하는데는 비용이 거의 들지 않는다. 바로 이러한 특징이 소프트웨어를 기존의 산업과 구분하는 가장 큰 특징일 것이다.  
   프로그래밍에서 복제가 무엇인가를 살펴보자.

  ```
  var a = 1;
  var b = a;
  b = 2;
  console.log(a); // 1
  ```

  결과

  ```
  1
  ```

  결과는 당연하다.  
   값을 변경한 것은 변수 b이기 때문에 변수 a에 담겨있는 값은 그대로이다.  
   변수 b의 값에 변수 a의 값이 복제된 것이다.

- 참조

  그런데 자연의 산물이 아니라 거대한 약속의 집합인 소프트웨어의 세계에서 당연한 것은 없다.  
   이것이 당연하지 않은 이유는 다음 예제를 통해서 좀 더 분명하게 드러난다.

  ```
  var a = {'id':1};
  var b = a;
  b.id = 2;
  console.log(a.id);  // 2
  ```

  결과

  ```
  2
  ```

  이 코드의 주인공은 아래와 같다.

  ```
  b.id = 2;
  System.out.println(a.id);
  ```

  놀라운 차이점이 있다.  
   변수 b에 담긴 객체의 id 값을 2로 변경했을 뿐인데 a.id의 값도 2가 된 것이다.  
   이것은 변수 b와 변수 a에 담긴 객체가 서로 같다는 것을 의미하다.  
   참조(reference)의 세계에 온 것을 환영한다.

  앞서 필자는 전자화된 세계에서 가장 중요한 특징으로 복제를 들었다.  
   그런데 복제만으로 전자화된 시스템을 설명하는 것은 조금 부족하다.  
   비유하자면 복제는 파일을 복사하는 것이고  
   참조는 심볼릭 링크(symbolic link) 혹은 바로가기(윈도우)를 만드는 것과 비슷하다.  
   원본 파일에 대해서 심볼릭 링크를 만들면 원본이 수정되면  
   심볼릭 링크에도 그 내용이 실시간으로 반영되는 것과 같은 효과다.  
   심볼릭 링크를 통해서 만든 파일은 원본 파일에 대한 주소 값이 담겨 있다.  
   누군가 심볼릭 링크에 접근하면 컴퓨터는 심볼릭 링크에 저장된 원본의 주소를 참조해서  
   원본의 위치를 알아내고 원본에 대한 작업을 하게 된다.  
   다시 말해서 원본을 복제한 것이 아니라 원본 파일을 참조(reference)하고 있는 것이다.  
   덕분에 저장 장치의 용량을 절약할 수 있고,  
   원본 파일을 사용하고 있는 모든 복제본이 동일한 내용을 유지할 수 있게 된다.  
   참조는 전자화된 세계의 극치라고 할 수 있다.

  프로그래밍에서 광범위하게 사용하는 라이브러리라는 개념도 일종의 참조라고 할 수 있다.  
   공용 라이브러리를 사용하게 되면  
   하나의 라이브러리를 여러 애플리케이션에서 공유해서 사용하게 된다.  
   라이브러리의 내용이 변경되면 이를 참조하고 있는 애플리케이션에도 내용이 반영되게 된다.  
   또 우리가 변수를 사용하는 이유도 말하자면 참조를 위해서라고 할 수 있을 것이다.  
   본질을 파악하면 이해력도 높아지고 암기할 것도 줄어든다.

  아래 두 개의 구문의 차이점을 생각해보자.

  ```
  a = 1;
  ```

  ```
  a = {'id':1};
  ```

  무엇일까? 전자는 데이터형이 숫자이고 후자는 객체다.  
   숫자는 원시 데이터형(기본 데이터형, Primitive Data Types)이다.  
   자바스크립트에서는 원시 데이터형을 제외한 모든 데이터 타입은 객체이다.  
   객체를 다른 말로는 참조 데이터 형(참조 자료형)이라고도 부른다.  
   기본 데이터형은 위와 같이 복제 되지만 참조 데이터형은 참조된다.  
   모든 객체는 참조 데이터형이다.

</br>

## 참고

[생활코딩 정규표현식 수업](https://opentutorials.org/course/909/5142)

[정규표현식을 시각화](https://regexper.com/)

[UI와 API 그리고 문서보는 법](https://opentutorials.org/course/743/6533)
