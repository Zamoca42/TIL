# 유용한 팁들

## var와 let의 차이

```js
for (var i = 0; i < tab_num; i++) {
  button[i].addEventListener("click", function () {
    for (var j = 0; j < tab_num; j++) {
      button[j].classList.remove("orange");
    }
    button[i].classList.add("orange");
    for (var k = 0; k < tab_num; k++) {
      content[k].classList.remove("show");
    }
    content[i].classList.add("show");
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
  button[i].addEventListener("click", function () {
    for (let j = 0; j < tab_num; j++) {
      button[j].classList.remove("orange");
    }
    button[i].classList.add("orange");
    for (let k = 0; k < tab_num; k++) {
      content[k].classList.remove("show");
    }
    content[i].classList.add("show");
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
app.use(bodyParser.urlencoded({ extended: true }));
```

body-parser 설치 끝입니다.

### POST 요청 처리하는 코드 짜기

app.get 하던 것과 매우 비슷하게 post 요청을 처리.  
이렇게 하면 끝입니다.

```js
app.post("/add", function (요청, 응답) {
  console.log(요청.body);
  응답.send("전송완료");
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

- 띄어쓰기는 언더바\_대신 대시-기호-사용

- 파일 확장자 쓰지 말기 (.html 이런거)

- 하위 문서들을 뜻할 땐 / 기호를 사용함 (하위폴더같은 느낌)

여러가지가 있습니다. 이것만 잘 지켜주시면 예쁜 서버 API들이 완성됩니다.

## MongoDB 비밀번호 가리기

Nodejs + MongoDB를 사용하는 강의를 듣던 중 MongoDB를 server.js에 연결해보는 시간이었다.

```js
const MongoClient = require("mongodb").MongoClient;
MongoClient.connect(
  "mongodb+srv://Zamoca:<password>@cluster0.ds7ie.mongodb.net/myFirstDatabase?retryWrites=true&w=majority",
  function (error, client) {
    //listen(서버를 오픈할 포트번호, function(){서버 오픈시 실행할 코드})
    app.listen(8080, function () {
      console.log("listening on 8080");
    });
  }
);
```

`<password>` 부분에 비밀번호를 입력하고 따라만하면 되는 거였지만 중요한 문제는 내가 작성하는 파일들은 깃허브에 올리는 중이라는 것이다.  
비밀번호 때문에 server.js를 repo에서 지울 수는 없고, 보안은 걱정되던 와중에 검색해서 해결방법을 찾아보기로 하였다.

https://poiemaweb.com/nodejs-keeping-secrets

이 링크를 발견하게 되었다!  
여러 가지 해결방법이 있었는데

1. 코드 내에 하드 코딩하기

2. 설정파일 사용하기

3. 환경변수 사용하기

4. command-line에서 argument 요구하기

5. js파일 만들어서 import하기

등이 있었다.

이 중에서 2번인 json파일로 설정파일을 만들어서 넣어주는게 간단해보여서 시도해보았다.  
링크에서 예시는 mysql을 이용한 예시였지만, 나는 mongoDB였기 때문에 콜백함수 이전 인수만  
백틱(`)을 사용하여 바꿔주었다.

```js
onst db_config = require('./db_config.json');

const MongoClient = require('mongodb').MongoClient;
MongoClient.connect(db_config.database, function(error, client){
    //listen(서버를 오픈할 포트번호, function(){서버 오픈시 실행할 코드})
    app.listen(8080, function() {
        console.log('listening on 8080')
    });
})
```

솔직히 될 줄은 몰랐는데 코드를 넣고 서버를 돌려보니 잘돌아간다... 신기하다.  
작성한 json파일은 .gitignore에 추가해 깃헙에 올라가지 않게 설정해줬다.

## NoSQL 데이터베이스

SQL문없이도 사용할 수 있는 데이터베이스.
MySQL처럼 테이블에 국한되지 않고 자유로운 형식으로 데이터를 쉽게 분산저장할 수 있다.

### 종류

- Key-value 모델 : Object, JSON 자료형 형식으로 데이터를 쉽게쉽게 저장, 출력이 가능합니다. 가장 심플함

- Document 모델 : 테이블 대신 Collection이라는 문서 기반으로 데이터를 분류하고 저장합니다. 테이블보다는 훨씬 유연합니다.

- Graph 모델 : 데이터를 노드의 형태로 저장하고 노드간의 흐름 또는 관계를 저장할 수 있습니다.

- Wide-column 모델 : 한 행마다 각각 다른 수, 다른 종류의 열을 가질 수 있습니다. (스키마가 자유로움)

우리가 사용하고 있는 MongoDB도 Key-value, Document 모델 저장방식을 차용하고 있습니다.

### 특징

1. Scaling이 쉽다는 장점이 있습니다.

찰나의 순간에 대량의 데이터를 저장해야한다면 어떻게할까요?  
기존 올드한 관계형 데이터베이스는 확장이 매우 어렵습니다. 보통 scale up 이라는 방법으로 서버의 성능을 키워야합니다.  
하지만 대부분의 NoSQL 데이터베이스는 scale out이라는 방법으로 데이터를 분산저장하는 걸 기본적으로 지원합니다.  
확정 걱정할 필요없이 쉽게 쉽게 데이터 입출력에만 신경쓸 수 있는 것이죠.  
그래서 대량의 데이터를 빠르게 입출력해야한다면 NoSQL이 제격입니다.

2. 대부분 다루기가 쉽습니다.

SQL 이라는 언어를 새로 배우지 않아도 데이터를 쉽게 입출력할 수 있습니다.  
자바스크립트 object{} 자료형 다루듯이 데이터를 입출력할 수 있으니 사용자에게 매우 편리하죠.  
그리고 여러분이 서버에서 쓰던 프로그래밍 언어로 DB를 다룰 수 있다는 장점이 있습니다. MongoDB도 그러고 있죠?

3. 대부분 스키마 정의 없이도 쉽게 쓸 수 있습니다.

장점이자 단점일 수 있습니다. 그래서 MongoDB에선 스키마를 미리 정의하기 위한 Mongoose같은 라이브러리를 추가해서 사용하기도 합니다.

4.  NoSQL 데이터베이스는 기본적으로 SQL에서의 JOIN 연산을 적용하는게 기본적으로 어렵습니다.

서버 단에서 JOIN 연산을 쉽게 처리해주는 라이브러리를 이용합니다.

# express.js

## 세션,JWT,OAuth 등 회원인증 방법론 쉽게 이해하기

### Session-based

사용자의 세션정보를 저장해서 로그인 기능을 구현하는 방법입니다.

- 이 사람이 로그인 했었다는 정보를 서버의 메모리에다가 기록해놓습니다. (세션을 저장합니다)

- 그리고 고객이 로그인이 필요한 페이지(Mypage 등)를 요청을 하면

- 세션을 들춰봐서 이 사람이 로그인했다는 정보가 나오면 통과

좀 더 자세히 보면

1. 로그인시 제출한 아이디, 비번이 DB 저장된 회원정보와 맞다면

이 사람이 언제 어디서 로그인 했는지 이런 정보를 담은 자료 하나를 만들어서 저장합니다.

"Kim 이라는 사람이 7시에 로그인했습니다."

이런 정보를 서버 메모리에 저장해둡니다.

2. 그리고 로그인한 유저마다 각각 유니크한 세션아이디라는걸 발급합니다.

당연히 로그인한 사람이 여러명일 수 있으니 유니크한 세션아이디를 발급해서 구분지어주는게 좋겠죠.

그래서 abc123 이라고 세션아이디를 하나 예쁘게 발급해줬습니다.

3. 발급한 세션아이디는 쿠키에 담아서 고객 브라우저에 전송해줍니다.

세션아이디는 고객과 서버 둘다 보관합니다. 그래서 쿠키에 담아서 고객에게 보내줍니다.

클라이언트에서 로그인이 필요한 페이지를 요청한 경우,

이 사람이 적법하게 로그인 했던 사람인지 검사해보도록 합시다.

1. 고객이 로그인합니다.

아이디 / 비번을 서버로 전송하면

서버는 기존에 있던 DB에 아이디/비번 세트가 존재하면 옳다구나 하고 세션아이디를 만들어줍니다.

그리고 세션아이디들을 담을 변수나 뭐 DB 공간을 마련해서 거기 저장해둡니다. 그걸 세션데이터라고 부릅시다.

(저장은 DB에 할 수도 있고 서버 메모리(그냥 변수)에 저장할 수 있습니다. )

그리고 세션 아이디를 쿠키라는 것에 이쁘게 포장해서 고객의 브라우저에 쿠키를 강제로 저장시킵니다.

2. 고객이 마이페이지를 요청합니다.

/mypage를 달라고 요청하면 서버는 응답.render() 해주기 전 일단 가로막습니다.

"님 로그인 했었음?" 이라고 물어봐야하니까요.

물어보는 과정은 심플합니다.

3. 쿠키에 세션아이디가 포함되어있는지 검사합니다.

원래 고객이 페이지를 요청할 때 마다 자동으로 쿠키가 서버로 전송됩니다.

그럼 서버는 쿠키에 기록된 세션아이디를 서버메모리 or DB에 저장되어있던 세션아이디와 비교해서

있으면 통과시켜줍니다.

4. 서버는 마이페이지를 보내줍니다.

그 전에 이 회원의 이름, 나이, 성별 등의 DB 정보가 필요하다면

세션데이터를 참고해서 이 사람의 이름, 나이 등의 정보를 DB에서 꺼내옵니다.

### Json Web Token(JWT)

토큰 방식은 세션데이터를 서버에 저장하지 않고

마이페이지를 열람할 수 있는 열쇠(토큰)를 사용자에게 쥐어주는 것입니다.

그래서 그 열쇠에는 session방식보다 약간 더 많은 정보들이 들어갑니다.

요즘 토큰토큰 거리면 JSON Web Token을 말하는 것인데, 아무튼 어떤 방식인지 자세히 알아보도록 합시다.

1. 로그인시 제출한 아이디, 비번이 DB 저장된 회원정보와 맞다면

서버는 옳다구나 하고 Token 하나를 만들어서 고객 브라우저로 보내줍니다.

Token은 그냥 긴 암호화된 문자열일 뿐이고, 사용자가 로그인 했었는지, 아이디는 무엇인지 이런 정보들을 넣을 수 있습니다.

물론 위조가 불가능하도록 특별한 서명이 추가됩니다.

토큰은 쿠키나 로컬스토리지라는 곳에 저장됩니다.

(+ 코드를 잘 짜서 고객이 페이지 방문시마다 Token이 서버로 보내지도록 미리 장치를 추가합니다)

2. 고객이 마이페이지를 요청하면

/mypage를 달라고 요청하면 서버는 응답.render() 해주기 전 일단 가로막습니다.

"님 로그인 했었음?" 이라고 물어봐야하니까요.

물어보는 과정은 그냥 토큰 검사입니다.

3. 서버는 토큰을 검사합니다

고객이 마이페이지 요청시 함께 보낸 Token이 적법한지 검사합니다.

유통기한이 지나지 않았는지, 서명이 잘 되어있는지, 블랙리스트에 등록된 토큰인지 이런 검사를 거친 후

이상이 없으면 마이페이지로 통과시켜줍니다.

서버는 세션데이터 등을 메모리/DB에 저장해둘 필요가 없으니 나중에 서버 스케일링시 큰 문제가 없다는 장점도 있습니다.

하지만 단점이나 보안상 취약점이 존재할 수 있습니다.

이 사람이 로그인 했는지에 대한 정보 전체를 서버는 가지고 있지 않고 사용자가 가지고 있게 하는 것 자체가 보안상 좋은 방법은 아닙니다.

JWT 정보를 다른 사람이 훔치면 어쩔 것임? 이제 훔친 사람은 자유롭게 로그인이 가능하겠는데요?

그래서 stateful JWT 라고 부르는 '어떤 사람이 언제 로그인했는지'를 서버에 저장해두는 방식이 좋은 관습이긴 한데

그 중 하나가 refresh token 이런 방식입니다.

그러면 위에서 말했던 세션 방식이랑 기능 상 다를바가 없습니다.

### Open Authentication(OAuth)

이 방법은 쉽게말하면 페이스북, 구글 로그인입니다.

다른 사이트의 계정정보를 불러와서 가입을 승인시키고 로그인하는 방식입니다.

1. 어떤 사람이 '페이스북으로 로그인' 버튼을 눌렀다고 칩시다.

그럼 페이스북 팝업이 뜹니다.

"코딩애플 앱에 본인의 페이스북 이름, 아이디 제공을 승인하시겠습니까?"

승인을 눌러봅니다.

2. 그럼 페이스북은 우리 server.js에게 이 유저의 이름, 아이디 정보를 보내줍니다.

3. 이 사람 페이스북 정보를 바탕으로 세션이나 토큰을 만들어줍니다.

DB에 이름, 아이디를 저장해서 회원 목록을 하나 만들어주든가,

그와 동시에 세션 데이터를 만들어주든가 하시면 됩니다.

4. 고객이 마이페이지를 요청하면

/mypage를 달라고 요청하면 서버는 응답.render() 해주기 전 일단 가로막습니다.

"님 로그인 했었음?" 이라고 물어봐야하니까요.

5. 서버는 토큰이나 세션을 검사합니다

위에서 세션을 만들어 줬다면 세션이 있는지 검사하면 되고,

위에서 토큰을 만들어 줬다면 토큰이 적법한지 검사하면 되겠죠?

통과되면 마이페이지를 응답.render() 해줍니다.

비밀번호를 취급안해도 된다는 장점 때문에 관리도 편리하고 유저도 편리함을 느낍니다.

페이스북 등에서 제공하는 공식 개발문서가 많기 때문에 따라하기만 하면 일사천리로 개발이 가능합니다.

하지만 단점은 구글이나 페이스북이 1. OAuth를 중단하거나 2. 방법을 수정하거나 3. 페이스북 API 서버 다운으로 접속이 불가능하다면

우리 사이트 로그인도 불가능합니다.

### 회원 기능이 있다면

- 로그인 했을 때만 글쓰기 가능
- 누가 글 발행했는지 글쓴이 저장
- 내 글만 모아보기

# React

## 리액트를 사용하는 이유

HTML과 비슷하게 생긴 JSX라는 문법을 사용합니다.  
그러면 그냥 HTML로 짜면 될텐데 왜 굳이 리액트를 사용하냐면  
서버에서 가져온 데이터 같은 것을 쉽게 바인딩 할 수 있기 때문입니다.  
`<div>`태그 안에 데이터를 하나 넣고싶으면 자바스크립트 문법을 사용하면  
document.getElementById().innerHTML = ??식으로 넣어줘야 했지만  
리액트는

```js
function App() {
  var data = "안녕하세요";
  return (
    <div className="App">
      <div className="black-nav">
        <div>개발 blog</div>
        <div>{data}</div>
      </div>
    </div>
  );
}
```

이렇게 `{}`안에 데이터바인딩하고싶은 변수명만 넣어주면 됩니다.  
미리보기 해보면 `<div>안녕하세요</div>`가 출력됩니다.  
변수명 뿐만아니라 href,id,className,src같은 HTML 속성값에도 넣을 수 있습니다.

```js
function App() {
  var data = "nav";
  return (
    <div className="App">
      <div className="black-nav">
        <div>개발 blog</div>
        <div className={data}>안녕하세요</div>
      </div>
    </div>
  );
}
```

따로 css스타일을 적용해주고싶을 때는

```js
<div style={{ color: "blue", fontSize: "30px" }}> 글씨 </div>
```

이렇게 오브젝트 자료형처럼 `{속성명:'속성값}`으로 만들어 줄 수 있고,  
변수를 넣어서 만들어줘도 됩니다.

## 자주 바뀌고, 중요한 데이터는 state에 넣자

리액트에서는 변수대신에 state를 만들어서 데이터를 저장할 수 있습니다.  
`let posts = '강남우동맛집'`처럼 일반 변수에 데이터를 저장할 수 있지만  
state를 사용하는 이유는 웹앱처럼 보여주기 위해서 입니다.  
일반 변수를 사용하면 변수의 데이터가 바뀔 때 새로고침을 해야 바뀐 부분이 보여지는데,  
state를 사용한 데이터를 수정하면 HTML을 자동으로 재렌더링 해줍니다.

예를들어 `<h3> 남자 코트 추천</h3>` 이런 태그는

```js
let [a, b] = useState(["남자 코트 추천", "여자 코트 추천"]);
```

이렇게 하면

```js
<h3>{a[0]}</h3>
```

`<h3> 남자 코트 추천</h3>`로 나오고

```js
<h3>{a[1]}</h3>
```

이렇게 바꾸면 `<h3> 여자 코트 추천</h3>` 으로 새로고침 없이 재렌더링해줍니다.

## useState 데이터를 변경하는법

좋아요버튼을 만들어보면서 state 데이터를 변경하는법을 알아보겠습니다.

```js
<h3>'남자 코트 추천' <span onClick={}>👍</span> {} </h3>
```

여기서 이모지를 클릭하면 숫자가 올라가게 만들고 싶다면
state를 만들어서 onclick 속성에 넣어준다면 새로고침없이 카운트가 올라갈겁니다.

```js
function App(){

  let [ thumb, thumbChange ] = useState(0);
  return (
    <HTML 많은 곳>
      <h3> '남자 코트 추천' <span onClick={()=>{thumb++}}>👍</span> {thumb} </h3>
    </HTML 많은 곳>
  )
}
```

`()=>{thumb + 1}`이렇게 Arrow function을 해주면 카운트가 올라갈거 같았는데 실행안됩니다.  
그 이유는 state는 변수와 다르게 값을 변경할 때 지정된 변경함수를 사용해야합니다.  
변경함수는 useState를 destructuring해준 thumb뒤에 오는 thumbChange가 변경함수 입니다.  
변경함수는`()=>{thumbChange(thumb + 1)}` 이렇게 쓰고 onclick속성에 넣어보면 작동합니다.

## useState안에 있는 배열 바꿔보기

```js
function App(){

  let [title, titleChange] = useState(['남자코트 추천', '강남 우동 맛집', '리액트 state 사용법']);

  function 제목바꾸기() {
    titleChange(['여자코트 추천', 강남 우동맛집', '파이썬 독학']);
  }
  return (
    <div className="list">
        <h3>{title[0]} <span onClick={ ()=>{thumbChange(thumb + 1)} }>👍</span> {thumb} </h3>
        <p>2월 17일 발행</p>
        <button onClick={제목바꾸기}>변경</button>
        <hr/>
    </div>
  )
}
```

변경 버튼을 누르면 '남자코트 추천'에서 '여자코트 추천'으로 바뀔 수 있게 함수를 작성해봤습니다.  
state함수는 직접 값을 바꿀 수 없기 때문에 변경함수를 써서 배열 갯수만큼 다시 입력해야합니다.  
제목하나 바꾸는데 배열의 갯수만큼 작성을 해줘야해서 복사본을 만들어서 바꿔보면

```js
function 제목바꾸기() {
  var newArray = title;
  newArray[0] = "여자코트 추천";
  titleChange(newArray);
}
```

이렇게 새로운 배열을 만들어서 title 배열을 집어넣게되면 각각의 자료형이 생성되는게 아니라 값을 공유합니다.  
reference자료형인 object와 array에서 적용되는 call by sharing이다.
그래서 완전히 새로운 복사본을 만들어 주려면

```js
var newArray = [...title];
```

이렇게 `...`을 사용해서 deep copy해주셔야 합니다.  
`...`기호는 중괄호를 없애주세요라는 뜻입니다.  
`...[1,2,3]`이렇게 배열앞에 사용하면  
`1,2,3` 이 남습니다.

## div박스를 줄이는 Component 문법

리액트는 긴 HTML을 한 단어로 깔끔하게 치환해서 넣을 수 있는 문법인 Component가 있습니다.  
원하는 곳에 HTML태그 한 단어로 치환할 수 있습니다.

줄이는 법은

1. function을 이용해서 함수를 하나 만들어서

2. 그 함수 안에 return () 안에 원하는 HTML을 담고

3. 그럼 원하는 곳에서 `<Modal></Modal>` 이라고 사용했을 때 아까 축약한 HTML이 등장합니다.

```js
function App() {
  return (
    <div>
      HTML 잔뜩있는 곳 ...
      <Modal></Modal>
    </div>
  );
}

function Modal() {
  return (
    <div className="modal">
      <h2>제목</h2>
      <p>날짜</p>
      <p>상세내용</p>
    </div>
  );
}
```

Component 문법을 사용하면 `<div>`보다는 깔끔하게 `<Modal>` 이렇게 되어있으니
뭐가 뭔지 바로 파악이 가능합니다

### Component의 특징

1. Component 이름은 영어대문자로 보통 시작합니다.

2. return () 안엔 태그들이 평행하게 여러개 들어갈 수 없습니다.

평행하게 여러개의 태그를 쓰고 싶으면 `<div>`로 묶으셔야합니다.
아니면 의미없는 div를 쓰기 싫으시면 `<> </>` 이걸로 묶으셔도 됩니다.

```js
function 예시컴포넌트() {
  return (
    <>
      <div>안녕</div>
      <div>안녕</div>
      <div>안녕</div>
    </>
  );
}
```

`<> </>`는 fragments라는 문법입니다. 의미없는 `<div>`쓰기 싫을 때 사용가능합니다.

3. component 위치는.. function App(){} 이것과 보통 나란히 만들어줍니다.

function App(){} 이것도 다시보니 컴포넌트 문법입니다.

보통 컴포넌트용 function 안에다가 컴포넌트용 function을 만들진 않습니다.

4. 강의에서 언급은 안했는데, component 안에 미리 만들어둔 component 집어넣기도 가능합니다.

```js
function Modal() {
  return (
    <div className="modal">
      <h2>제목</h2>
      <p>날짜</p>
      <p>상세내용</p>
      <다른컴포넌트></다른컴포넌트>
    </div>
  );
}
function 다른컴포넌트() {
  return <div> 안녕 </div>;
}
```

앞서 만든 Modal 컴포넌트의 `<div>` 안에 다른 컴포넌트를 만들어서 집어넣을 수도 있습니다.

컴포넌트 이름은 한글로 작성시 작동하지 않을 수 있습니다.

### 어떤 HTML들을 Component 만드는게 좋을까

기준은 없습니다만 관습적으로 어떤 부분을 주로 Component화 하냐면

- 사이트에 반복해서 출현하는 HTML 덩어리들은 Component로 만들면 좋습니다.

- 내용이 매우 자주 변경될 것 같은 HTML 부분을 잘라서 Component로 만들면 좋습니다.

- 다른 페이지를 만들고 싶다면 그 페이지의 HTML 내용을 하나의 컴포넌트로 만드시는게 좋습니다. (그냥 좋을 뿐 필수는 아님)

- 또는 다른 팀원과 협업할 때 웹페이지를 컴포넌트 단위로 나눠서 작업을 분배하기도 합니다.

님들 함수문법 언제씁니까 긴 코드 축약할 때, 다른 곳에서 코드 재사용할 때, 기능별로 나눌 때 쓰지 않습니까

그냥 함수 문법이랑 똑같이 여겨주면 됩니다.

### Component의 단점

일단 HTML 깔끔하게 쓰려고 함수 자체를 많이 만들면 그것 만으로도 관리가 힘듭니다.

하지만 가장 큰 단점은 `<Modal>`이라는 컴포넌트가 App(){} 안에 있는 state를 사용하고 싶을 때 그냥 바로 쓸 수 없다는 것입니다.

props라는 문법을 이용해 state를 `<Modal>`까지 전해줘야 비로소 사용가능합니다.

## props

다른 컴포넌트에 있는 state를 가지고 오고싶을 땐 props를 사용한다.  
예를들어 App(){}안에 있는 글제목 state를 Modal(){}안에서 쓰고싶다.  
먼저 컴포넌트의 관계를 한번 보면 App이라는 컴포넌트 안에 Modal 컴포넌트를 사용했다면  
App은 부모컴포넌트, Modal은 자식컴포넌트가 된다. HTML에서 레이아웃과 비슷한거 같다.  
이 때 App에서 사용된 state는 Modal에서 사용할 수 없다. 그럴 땐 props로 자식에게 state를 전달해주면 된다.

```js
{
  modal === true ? <Modal 작명={전송할state}></Modal> : null;
}
```

이렇게 태그 안에 넣고싶은 state를 넣어주고

```js
function Modal(props) {
  return (
    <div className="modal">
      <h2>제목 {props.title}</h2>
      <p>날짜</p>
      <p>상세내용</p>
    </div>
  );
}
```

컴포넌트 안의 파라미터에 props를 넣어준다. 부모에게 전달받은 state는 다 props로 들어간다.
이 후 app.js에서 `<Modal/>` 태그에 넣고싶은 state를 속성으로 넣어주면 전달된다.

```js
<Modal title={title} clickTitle={clickTitle} />
```

## React Router로 라우팅하기

React Router를 사용하면 웹앱에서 index.html 한개로 라우팅만 해주면 여러 페이지를 보여줄 수 있다.  
react-router-dom이라는 공식 라이브러리를 설치해서 이용하면 된다.  
강의에서는 5.2.0버전을 사용했는데 최신버전인 6.2.2를 사용해서 강의와 같이 설정하면 에러가 뜬다.  
사용방법이 많이 바뀐걸로 봐서 기본 원리만 익히고 최신버전으로 다시 공부해야할 것 같다.

### 세팅

터미널에서

```js
npm install react-router-dom@5.2.0

yarn add react-router-dom@5.2.0
```

둘 중 하나를 입력해서 설치하면 된다. yarn이 있으면 yarn으로 설치하는게 좀 더 빠르다.  
react 프로젝트에서 index.js에

```js
import { BrowserRouter } from "react-router-dom";

ReactDOM.render(
  <React.StrictMode>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </React.StrictMode>,
  document.getElementById("root")
);
```

기존코드에서 import BrowserRouter를 해주고 `<BrowserRouter>`태그를 추가한다.  
그럼 이제 App.js로 이동해 라우팅을 해주면 된다.

### BrowserRouter vs HashRouter

위의 index.js에서 세팅할 때 BrowserRouter말고 HashRouter라는 태그도 이용할 수 있다.  
BrowserRouter를 HashRouter로 교체하면 되는데

- HashRouter를 복붙하시면 사이트 방문시 URL 맨 뒤에 /#/이 붙은채로 시작한다

- BrowserRouter를 복붙하시면 사이트 방문시 # 그런거 없이 깔끔해진다.

이게 차이점이다.  
HashRouter를 사용하는 이유는 보통 라우팅을 하게 되면 서버에 페이지를 요청하는데  
서버에 요청하지 않고 리액트가 전부 라우팅하게 할 수 있다.  
서버가 있을 때 BrowserRouter를 사용하면 서버에 요청하지않고 리액트 메인페이지로 보내는 API를 설정해야한다.

### 기본 라우팅

이번 목표는

1. "/"로 접속하면 메인페이지를 보여준다.
2. "/detail"로 접속하면 상세페이지로 연결한다.

App.js

```js
import 많은 곳;
import { Link, Route, Switch } from 'react-router-dom';

function App(){
  return (
    <div>
      HTML 잔뜩있는 곳

    </div>
  )
}
```

상단에 Link, Route, Switch를 import해온다. 오늘 사용할 것은 Route지만  
다음에 Link, Switch를 사용할거라 미리가져왔다.

```js
import 많은 곳;
import { Link, Route, Switch } from 'react-router-dom';

function App(){
  return (
    <div>
      HTML 잔뜩있는 곳
      <Route path="/">
        <div>메인페이지인데요</div>
      </Route>
      <Route path="/detail">
        <div>상세페이지인데요</div>
      </Route>
    </div>
  )
}
```

이렇게 `<Route>`태그로 한페이지에서 경로를 나눠줄 수 있다. 웹페이지에서는 `/`로 접속하면 메인페이지를  
`/detail`로 접속하면 상세페이지로 연결할 수 있다.  
`<Route>`태그안에 div박스로 페이지를 만들 수도 있지만, 만들어놓은 component를 가져오는게 더 간단하다.

```js
<Route path="/어쩌구" component={Card} ></Route>

<Route path="/어쩌구"> <Card/> </Route>
```

둘 다 같은 방식이고 밑에 컴포넌트를 불러오는게 더 간단해보인다.  
위의 Route방식으로 페이지를 나누면 한페이지에 메인페이지와 상세페이지가 나온다.  
/detail에 /도 포함되어있기 때문인데, 여기서

```js
<Route exact path="/">
  <div>메인페이지에요</div>
</Route>
```

exact라는 속성을 붙여주면 `/`경로와 정확히 일치할 때만 메인페이지를 보여준다.

### Link 태그로 페이지 이동버튼 만들기

이전에 reac-router-dom에서 import해온 컴포넌트 중에 Link가 있었다.

```js
function App() {
  return (
    <div>
      <Navbar>
        <Nav.Link>
          {" "}
          <Link to="/">Home</Link>{" "}
        </Nav.Link>
        <Nav.Link>
          {" "}
          <Link to="/detail">Detail</Link>{" "}
        </Nav.Link>
      </Navbar>
      <나머지HTML />
    </div>
  );
}
```

App.js의 navbar에서 버튼들을 Link태그로 감싸주고 to라는 속성을 이용해서 경로를 적어주면  
페이지 이동버튼이 완성된다. 나머지 마음에 들지않는 스타일은 css나 부트스트랩으로 스타일링해주면 된다.  
이제 Detail을 누르면 `/detail`경로로 Home을 누르면 `/`경로로 이동한다.

### 상세페이지에서 뒤로가기 버튼을 만들어 보자

```js
import React from "react";
import { useHistory } from "react-router-dom";

function Detail() {
  let history = useHistory();
  return (
    <div className="container">
      <div className="row">
        <div className="col-md-6">
          <img
            src="https://codingapple1.github.io/shop/shoes1.jpg"
            width="100%"
          />
        </div>
        <div className="col-md-6 mt-4">
          <h4 className="pt-5">상품명</h4>
          <p>상품설명</p>
          <p>120000원</p>
          <button className="btn btn-danger">주문하기</button>
          <button className="btn btn-danger">뒤로가기</button>
        </div>
      </div>
    </div>
  );
}

export default Detail;
```

detail.js라는 파일을 만들어서 상세페이지를 만들어주고 App.js에 import시켰다.  
여기서 주문하기버튼 옆에 뒤로가기버튼을 만들어주고, useHistory라는 함수를 react-router-dom에서 import해왔다.  
useHistory는 일종의 Hook으로 사용자가 열어본 페이지 이동내역 + 유용한 함수가 object로 저장되어 있다.

```js
<button
  onClick={() => {
    history.goBack();
  }}
  className="btn btn-danger"
>
  뒤로가기
</button>
```

여기서 뒤로가기 버튼만 onClick속성으로 `history.goBack()`이라는 함수를 적용해주면 페이지가 뒤로간다.  
이런 라이브러리 사용법은 찾아서 읽거나 검색해봐야 알 수 있다.

뒤로가기 기능 말고 그냥 어떤 페이지로 이동하는 기능을 만들고 싶으면  
라이브러리 사용법에 따라 push() 함수를 꺼내쓰시면 된다.  
뒤로가기 버튼을 눌렀을 때 홈화면으로 이동하려면

```js
<button
  onClick={() => {
    history.push("/");
  }}
  className="btn btn-danger"
>
  뒤로가기
</button>
```

이렇게 써주면 된다.

### Switch 컴포넌트에 대해 알아보자

맨 처음에 라우터에서 Link, Route, Switch를 import 해왔는데, 그 중 Switch라는 건  
Route태그들을 전부 보여주지말고, 한번에 하나만 보여주는 기능이다.  
사용법도 나누고싶은 Route태그들을 감싸면 된다.

```js
function App() {
  return (
    <div>
      <나머지HTML />
      <Switch>
        <Route exact path="/">
          어쩌구
        </Route>
        <Route path="/detail">
          <Detail />
        </Route>
        <Route path="/:id">
          <div>새로 만든 route입니다</div>
        </Route>
      </Switch>
    </div>
  );
}
```

이렇게 한페이지에 다보여주던 Route들을 다 감싸면 여러개의 Route가 매칭되어도 맨 위의 Route 하나만 보여준다.  
이걸 응용하면 exact속성을 사용하지 않아도 해결 가능하다.

## useEffect

리액트에서 컴포넌트는 Lifecycle개념이 존재합니다.  
컴포넌트는 생성, 삭제가 가능하고 관련 state가 변경되면 재렌더링이 일어납니다.  
여기서 Hook을 사용하면 생성되거나 삭제될 때 조건을 걸 수 있습니다.  
이 Hook의 정확한 명칭을 Lifecycle Hook이라고 합니다.

useEffect는 Lifecycle Hook으로 function 컴포넌트 안에서 사용할 수 있습니다.

```js
import React, { useState, useEffect } from "react";

function Detail() {
  useEffect(() => {
    //코드를 적습니다 여기
  });

  return <HTML많은곳 />;
}
```

1. 미리 페이지 상단에서 useEffect를 import하고
2. useEffect()를 사용하고 안에 콜백함수를 넣습니다.
3. 콜백함수 안에는 컴포넌트가 나타나고나서 실행하고싶은 코드를 적어줍니다.

좀 더 자세하게 useEffect() 내의 코드 실행 조건은

- 컴포넌트가 첫 등장해서 로딩이 끝난후(Mount가 끝났을 때)
- 컴포넌트가 재렌더링 되고난 후(Update가 되고난 후)

### 컴포넌트가 사라질 때 useEffect실행

```js
import React, {useState, useEffect} from 'react';

function Detail(){

  useEffect(()=>{
    return function 어쩌구(){ 실행할 코드 }
  });

  return (
    <HTML많은곳/>
  )
}
```

useEffect() 안에는 return이라는걸 넣을 수 있습니다.  
그리고 여기 넣은 함수는 컴포넌트가 사라질 때 실행됩니다.

- 당연히 다른 곳에서 만들어 놓은 함수명을 입력하셔도 됩니다.
- arrow function 집어넣으셔도 가능합니다.

추가로 useEffect기능을 여러개 사용하고싶다면 useEffect를 여러개 적어주어도 가능합니다.

### 페이지 방문 후 2초 후에 사라지는 alert박스

```js
function Detail(){

  let [ alert, alert변경 ] = useState(true);
  useEffect(()=>{
    let 타이머 = setTimeout(()=>{ alert변경(false) }, 2000);
  });

  return (
    <HTML많은곳/>
    {
      alert === true
      ? (<div className="my-alert2">
          <p>재고가 얼마 남지 않았습니다</p>
        </div>)
      : null
    }
  )
}
```

useEffect안에 setTimeout을 사용해서 2초 후에 alert를 false로 변경  
이 때 만약 페이지에서 input태그 같은 것이 있어서 input에 문자를 입력하면 문자가 입력될 때 마다 재렌더링이 일어납니다.  
그럴때 useEffect에 조건을 걸어서 업데이트 될 때는 useEffect를 실행안하게 할 수 있습니다.

```js
useEffect(() => {
  let 타이머 = setTimeout(() => {
    alert변경(false);
  }, 2000);
}, []);
```

useEffect() 함수 끝부분에 대괄호[] 를 집어넣을 수 있습니다.  
여기에는 state를 넣을 수 있습니다.

```js
useEffect(() => {
  let 타이머 = setTimeout(() => {
    alert변경(false);
  }, 2000);
}, [alert]);
```

이런 식입니다. 이렇게 사용하면 alert라는 이름의 state가 변경이 될 때만 업데이트로 치고 실행해줍니다.

마지막으로 setTimeout 타이머를 쓰셨으면 타이머해제도 해야합니다.

방금 Detail 방문시 2초 후에 UI 사라지게 해주세요~ 라고 코드를 짰습니다.  
근데 2초가 되기도 전에 Detail을 벗어나면 어떻게 될까요?

지금은 별 문제없는 것 같지만 코드가 길어지거나 꼬이면  
남아있는 타이머 때문에 이상한 현상이 일어날 수 있습니다.  
그래서 컴포넌트가 사라질 때 타이머를 없애는 코드도 추가해주는게 좋습니다.

```js
useEffect(() => {
  let 타이머 = setTimeout(() => {
    alert변경(false);
  }, 2000);

  return () => {
    clearTimeout(타이머);
  };
}, []);
```

useEffect안에는 return + 함수를 추가하면
컴포넌트가 사라질 때 특정 코드를 실행할 수 있습니다

거기에 clearTimeout을 추가한겁니다.  
clearTimeout(타이머이름)  
이렇게 쓰시면 타이머를 바로 해제할 수 있습니다.

## Context 문법으로 props 없이 state 공유하기

컴포넌트안의 컴포넌트까지 state를 전달하려면 props를 연속으로 사용해야 합니다.  
컴포넌트가 5개 6개 중첩해 있으면 매우 복잡하겠죠.  
props를 연속사용하기 싫다면 컴포넌트의 수를 줄이던지, 아니면 Redux나 context를 쓰면 됩니다.  
Redux보다는 약간 더 간단하게 쓸 수 있는 Context API 사용법에 대해 알아봅시다.  

```js
let 재고context = React.createContext();

function App(){
  let [재고, 재고변경] = useState([10,11,12]);

  return (
    <HTML많은곳/>
  )
}
```

state값을 공유하고싶으면 createContext()라는 함수를 이용해 변수를 만듭니다.  

```js
let 재고context = React.createContext();

function App(){
  let [재고, 재고변경] = useState([10,11,12]);

  return (
    <HTML많은곳/>
    <재고context.Provider value={재고}>
      <어떤 레이아웃/>
    </재고context.Provider>
    
  )
}

```
state값 공유를 원하는 컴포넌트들을 `<context.Provider>`태그로 감쌉니다.
여기에 value속성으로 공유하고싶은 state를 집어넣습니다.  

그럼 이제 Provider안에 있는 모든 HTML&컴포넌트는 재고state를 이용가능합니다.  

```js
import React, {useState, useContext} from 'react';

function Card(){
  let 재고 = useContext(재고context);

  return (
    <HTML많은곳/>
    <div>{재고[0]}</div>
  )
}

```

state를 사용하고싶으면 useContext()라는 훅을 이용해서 사용을 원하는 context를 불러와야합니다.  
useContext 훅을 쓰려면 상단에 있는 react로 부터 import해와야 합니다.  
재고context에 들어있는 state를 변수로 저장해 쓰겠습니다라는 문법입니다.

contextAPI는 중첩된 컴포넌트가 많을 때 유용합니다.  

추가로 컴포넌트가 다른 파일에 있다면?

```js
export let 재고context = React.createContext();

function App(){
  let [재고, 재고변경] = useState([10,11,12]);

  return (
    <HTML많은곳/>
    <재고context.Provider value={재고}>
      <Detail/>
    </재고context.Provider>
  )
}

```
export를 해줘서 내보낼 수 있습니다.

```js
import {재고context} from './App.js';

function Detail(){
  let 재고 = useContext(재고context);  //근데 여기서 에러남 ㅅㄱ

  return (
    <HTML많은곳/>
  )
}
```
다른 파일에서 import {변수명,함수명}으로 가져와주면 됩니다.  
