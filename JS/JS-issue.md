# 유용한 팁들

## var와 let의 차이
```js
for (var i = 0; i < tab_num; i++) {
    button[i].addEventListener('click', function(){
        for (var j = 0; j < tab_num; j++){
            button[j].classList.remove('orange');
        };
        button[i].classList.add('orange');
        for (var k = 0; k < tab_num; k++){
            content[k].classList.remove('show');
        };
        content[i].classList.add('show');
    });
}
```

탭 기능을 만들어보다가 for문에서 var를 사용하면 작동을 하지 않았다.  
let을 쓰면 잘 작동했는데  
var와 let의 변수 범위 차이인 것을 알 수 있었다.  

이벤트리스너는 클릭시 실행되는 코드인데  
var를 사용하면 전역변수로 사용된다.  
여기서 변수 `i`는 반복문이 끝나면 `0`으로 돌아가지않고  
`3`이 남아있게된다. 그래서 에러가 발생한다.  

let을 사용하면 for문 안쪽으로 반복문을 돌고 다시 `0`으로 돌아가기 때문에  
let을 사용해야 한다.  

var가 만능인줄 알았는데, 범위가 중요하다는 것을 알게 되었다.  

```js
for (let i = 0; i < tab_num; i++) {
    button[i].addEventListener('click', function(){
        for (let j = 0; j < tab_num; j++){
            button[j].classList.remove('orange');
        };
        button[i].classList.add('orange');
        for (let k = 0; k < tab_num; k++){
            content[k].classList.remove('show');
        };
        content[i].classList.add('show');
    });
}
```

# Node.js의 특징

## non-blocking.io

일반적인 서버는 요청을 오는 순서대로 차례대로 처리하지만, nodejs는 모든 요청을 받고   
빨리 처리할 수 있는 것부터 결과를 낸다.  

수학적 연산을 요구하지 않는 채팅서비스나 SNS에 Nodejs를 많이 사용한다.  

스타트업, 프로토타입 만들기에도 많이 사용  
 - 초보자에게 쉽고
 - 템플릿으로 간편하게
 - 갑자기 사용자가 늘어도 감당가능
 - 자바스크립트 문법만으로 프론트, 백엔드 공부가능  

단점으로 보안 취약, 처리속도 떨어짐, 수학적연산이나 이미지처리같은 라이브러리 부족,   
non-blocking 처리방식은 다른 언어에서도 비슷하게 구현 가능.  




