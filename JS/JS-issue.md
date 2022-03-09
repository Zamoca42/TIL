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


