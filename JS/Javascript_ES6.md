
# this 키워드

1. 그냥 쓰거나 일반 함수 안에서 쓰면 window 객체를 가리킴
```js
console.log(this); //출력 : {Window}
```

2. 오브젝트 내 함수안에서 쓰면 그 함수를 가지고 있는 오브젝트를 뜻함
```js
var 오브젝트 = {
        data : 'Kim',
        함수 : function(){
            console.log(this)
        }
    }

오브젝트.함수(); // 출력 : {data: "Kim", 함수 : f}
```

1,2번째는 같은 이야기입니다.  
자바스크립트는 항상 window오브젝트를 상위로 가지고있기때문에 window는 생략되어있습니다.  
그래서 1번에서 가리키는 this의 오브젝트는 window가 됩니다.  

3. 오브젝트 생성기계 안에서 쓰면 새로 생성되는 오브젝트를 뜻함

```js
function 기계(){ // constrctor
        this.이름 = 'Kim' // instance
    }
```

자바 스크립트에서 오브젝트를 여러개 만들고 싶은 경우  
오브젝트를 복사하는게 아니라 constructor라는걸 만들어서 사용합니다.  
constructor는 오브젝트를 복사해서 생성해주는 기계입니다.  
여기서 `this.이름`은 기계로부터 새로 생설될 오브젝트를 의미합니다.  
```js
function 기계(){
  this.이름 = 'Kim'
}
var 오브젝트 = new 기계();

```
이렇게 new키워드를 이용하면 새로운 오브젝트를 꺼낼 수 있습니다.  

4. 이벤트리스너내에서 사용하면 this는 e.currentTarget을 의미

```js
document.getElementById('버튼').addEventListener('click', function(e){
  console.log(this)
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
function 더해주세요(x){
  return x + 2
}
```
이렇게 일반 함수로 입출력 기능을 표현할 수 있지만
```js
var 두배만들기 = (x) => { return x * 2 }
```
Arrow Function은 직관적으로 표현가능합니다.  

또한 파라미터가 하나라면 소괄호를 생략 가능합니다

```js
var 두배만들기 = x => { return x * 2 }
```

여기서 중괄호 안에 코드가 한줄이라면 중괄호도 생략가능하고 return도 생략 가능합니다.  

```js
var 두배만들기 = x => x * 2 ;
```

추가로 arrow function을 쓰면 내부에서 this값을 쓸 때 밖에 있던 this값을 그대로 사용합니다.

일반 함수에서의 this는 오브젝트 내 함수안에서 쓰면 그 함수를 가지고 있는 오브젝트를 뜻한다고 했었습니다.  

```js
var 오브젝트1 = {
  함수 : function(){ console.log(this) }
}

오브젝트1.함수()
```
여기서는 오브젝트1이 콘솔창에 출력됩니다.  

Arrow Function에서 this는 외부에 있는 this를 가져옵니다

```js
var 오브젝트1 = {
  함수 : () => { console.log(this) }
}

오브젝트1.함수()
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
function 함수(){
  
  console.log('hello');
  var 이름 = 'Kim';
  
}
```

이렇게 함수 내에서 변수를 만들었다고 칩시다.  
근데 자바스크립트가 이 코드를 해석하는 순서는 이렇게 됩니다.  

```js
function 함수(){

  var 이름; 
  console.log('hello');
  이름 = 'Kim';
  
}
```

변수의 선언 부분을 강제로 변수의 범위 맨 위로 끌고가서 해석하고 지나갑니다.   
우리 눈에 보이진 않지만 자바스크립트는 코드 동작 순서가 이렇습니다.  
암튼 이게 Hoisting 현상입니다.   
함수를 만들어도 똑같고, 변수를 let, const로 만들어도 똑같습니다.   
