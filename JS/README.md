![javascript](https://user-images.githubusercontent.com/96982072/153997073-fa41822c-60eb-4f3e-b2b4-f257f073f2f4.png)


>자바스크립트를 선택 한 이유는 프론트 부분에서 JS를 배우고 백엔드 부분인  
>Node를 배우는데 상대적으로 수월할거라고 생각했다.

> 2022/02/11 자바스크립트 시작

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
i의 값이 0이기 때문에 ```'coding everybody0<br />'```이라는 텍스트가 출력된다.  
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
     ```
     var pattern = new RegExp('a');
     ```
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

JavaScript에서는 함수도 객체다. 다시 말해서 일종의 값이다. 거의 모든 언어가 함수를 가지고 있다.   JavaScript의 함수가 다른 언어의 함수와 다른 점은 함수가 값이 될 수 있다는 점이다.  
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
     ```
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

</br>

## 참고

[생활코딩 정규표현식 수업](https://opentutorials.org/course/909/5142)

[정규표현식을 시각화](https://regexper.com/)

[UI와 API 그리고 문서보는 법](https://opentutorials.org/course/743/6533)