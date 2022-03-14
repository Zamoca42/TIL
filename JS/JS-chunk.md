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

# Node.js

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

## form 데이터를 서버로 전송해보자

### 태그 셋팅

HTML의 form 내의 input들에 입력한 데이터들을 서버로 전송할 수 있습니다.  
전송하고 싶다면 여러분이 form 태그에 여러가지 전송 방법들을 명시해주시면 되겠습니다.  

 
```js
<form action="/add" method="POST">
  <div class="form-group">
    <label>오늘의 할일</label>
    <input type="text" class="form-control" name="title">
  </div>
  <div class="form-group">
    <label>날짜</label>
    <input type="text" class="form-control" name="date">
  </div>
  <button type="submit" class="btn btn-outline-secondary">Submit</button>
</form> 
```

폼 전송버튼을 누를 시 `/add` 라는 경로로 `POST` 요청을 하는 폼이 완성되었습니다.    
form 태그의 method 속성은 `GET`/`POST` 중 어떤 요청을 할 건지 정해주는 부분,  
`action`은 어떤 경로로 요청할건지를 정해주는 부분입니다.   
알아서 잘 채워넣으시면 이제 전송버튼을 누를 때마다 서버에 input에 담긴 데이터들을 전송하게 됩니다.  
화룡점정으로 input마다 name 속성을 이용해 각각의 input에 이름을 써주었습니다.  
폼 전송할 때 input에 이름이 없으면 서버에서 이게 어떤 input에 적혔던 데이터인지 알 수 없으니깐요!  

### body-parser 설치

1번까지만 해도 데이터가 잘 전송되긴 하는데, body-parser라는 라이브러리가 있어야  
보낸 데이터들 처리가 쉽게 가능합니다.  
2021년 이후로는 body-parser 라이브러리가 express에 기본 포함되어있어  
따로 npm으로 설치할 필요가 없습니다.  
server.js에서 위쪽에 다음 코드를 추가합니다.  
```js
app.use(bodyParser.urlencoded({extended: true})) 
```
body-parser 설치 끝입니다.  

### POST 요청 처리하는 코드 짜기

app.get 하던 것과 매우 비슷하게 post 요청을 처리.  
이렇게 하면 끝입니다.  

```js
app.post('/add', function(요청, 응답){
  console.log(요청.body);
  응답.send('전송완료')
});
```

그럼 누군가가 `/add` 경로로 `post` 요청을 할 때   
터미널 콘솔창에 `요청.body`를 출력해볼 수 있습니다.  
`요청.body`는 폼에 입력한 제목과 날짜 데이터가 들어가있을 것입니다.  
(그리고 응답.send() 라는 함수로 성공했다는 메세지를 브라우저에 전달가능합니다.)  
이것으로 폼에서 서버로 데이터보내기 끝입니다.  
 
## REST API 원칙

1. Uniform interface  
    인터페이스는 일관성이 있어야한다.  
    - 하나의 URL로는 하나의 데이터를 가져와야함  
    - 간결하고 예측가능하게  
    - URL 이름짓기 관습을 따르자  

2. Client-server 역할 구분하기
    클라이언트에게 서버역할을 맡기거나  
    클라이언트에서 DB에 있는 자료를 직접 꺼내는식으로 코드를 작성하지말자.

3. Stateless
    요청들은 각각 독립적으로 처리.  
    요청1과 요청2가 의존성이 존재하도록 작성하지말자.  
    요청하나만으로 자료를 가져오기 충분하도록 작성.  

4. Cacheable
    요청을 통해 보내는 자료들은 캐싱이 가능해야함.  
    캐싱이 가능하다고 표시하거나 캐싱 기간 설정.  
    (주로 브라우저에서 알아서 처리함)  

## URL 이름짓기 관습

```
instagram.com/explore/tags/kpop
instagram.com/explore/tags/food
facebook.com/natgeo/photos
facebook.com/bbc/photos
```
이 URL들은 페이스북이 매우 잘 만든 API입니다.  
`facebook.com/bbc/photos` 무엇을 지칭하는지 한눈에 들어온다.  

- 단어들을 동사보다는 명사 위주로 구성함  

- 응용해서 다른 정보들을 쉽게 가져올 수 있을 정도로 일관성 있음   

- 대충 봐도 어떤 정보가 들어올지 예측이 가능함   

이외에도 이름을 잘 지을 수 있는 방법은  

- 띄어쓰기는 언더바_대신 대시-기호-사용  

- 파일 확장자 쓰지 말기 (.html 이런거)  

- 하위 문서들을 뜻할 땐 / 기호를 사용함 (하위폴더같은 느낌)  

여러가지가 있습니다. 이것만 잘 지켜주시면 예쁜 서버 API들이 완성됩니다.   

 


