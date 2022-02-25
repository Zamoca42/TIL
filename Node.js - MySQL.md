<img src="https://user-images.githubusercontent.com/96982072/155693520-d53693b0-2559-4139-9eda-9221cc5c40ed.png" width = 800px/>

# 소개

Node.js는 구글 크롬의 자바스크립트 V8엔진으로 빌드된 자바스크립트 런타임이다.  
브라우저에만 자바스크립트를 쓰는 것이 아닌 브라우저 밖으로 확장하기 위해 만들어 진 것이 Node.js다.  
Node.js를 이용하면 자바스크립트 언어로 서버를 만들 수 있는데,  
이번에는 MySQL을 이용해 서버에서 정보를 가져오고 수정하는 법을 배울 예정이다.

# 준비 및 사용방법

소스코드와 셋팅은 생활코딩의 [WEB2 Node.js-MySQL](https://opentutorials.org/course/3347)수업을 따라간다.

# MySQL로 구현

## 홈페이지 구현

Nodejs를 처음 배웠을 때는 파일을 대상으로 데이터를 가져왔었는데,  
이번에는 어플리케이션을 데이터베이스로 가져와보는 방법이다.

먼저 main.js에 mysql모듈을 불러오고, 접속하는 것까지 해보자.

```js
var mysql = require("mysql");

var db = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "password",
  database: "opentutorials",
});

db.connect();
```

이렇게 접속하는 것 까지 완료했다면 앞의 WEB2-nodejs수업에서 파일을 읽어서 데이터를 가져왔었던 코드 대신

```js
fs.readdir("./data", function (error, filelist) {
  var title = "Welcome";
  var description = "Hello, Node.js";
  var list = template.list(filelist);
  var html = template.HTML(
    title,
    list,
    `<h2>${title}</h2>${description}`,
    `<a href="/create">create</a>`
  );
  response.writeHead(200);
  response.end(html);
});
```

MySQL을 불러오는 코드를 입력한다.

```js
db.query("SELECT * FROM topic", function (error, topics) {
  console.log(topics);
  response.writeHead(200);
  response.end("Success");
});
```

크롬에서 localhost:3000로 접속해보면 success를 출력하면 정상이다.

이제 더 나가서 success를 출력하는 대신 홈페이지를 불러오도록 작성을 해보자.  
파일을 불러올 때와 데이터베이스를 불러올 때는 차이가 존재 한다.  
WEB2-Node.js 수업작성한 template.js에 list객체를 보면

```js
module.exports = {
  HTML: function (title, list, body, control) {
    return `
    <!doctype html>
    <html>
    <head>
      <title>WEB1 - ${title}</title>
      <meta charset="utf-8">
    </head>
    <body>
      <h1><a href="/">WEB</a></h1>
      ${list}
      ${control}
      ${body}
    </body>
    </html>
    `;
  },
  list: function (filelist) {
    var list = "<ul>";
    var i = 0;
    while (i < filelist.length) {
      list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
      i = i + 1;
    }
    list = list + "</ul>";
    return list;
  },
};
```

data폴더에 있는 파일을 반복문으로 자동으로 불러와서 리스트를 만들었다.  
하지만 MySQL을 살펴보면 배열 안에 객체로 존재하기 때문에  
querystring과 제목에 filelist대신에 메소드를 넣어주어야 한다.

```js
module.exports = {
  HTML: function (title, list, body, control) {
    return `
    <!doctype html>
    <html>
    <head>
      <title>WEB1 - ${title}</title>
      <meta charset="utf-8">
    </head>
    <body>
      <h1><a href="/">WEB</a></h1>
      ${list}
      ${control}
      ${body}
    </body>
    </html>
    `;
  },
  list: function (topics) {
    var list = "<ul>";
    var i = 0;
    while (i < topics.length) {
      list =
        list + `<li><a href="/?id=${topics[i].id}">${topics[i].title}</a></li>`;
      i = i + 1;
    }
    list = list + "</ul>";
    return list;
  },
};
```

파일을 불러올 때와는 조금 차이가 있다.  
이 후 main.js에서 MySQL을 불러오는 코드에서

```js
db.query("SELECT * FROM topic", function (error, topics) {
  var title = "Welcome";
  var description = "Hello, Node.js";
  var list = template.list(topics);
  var html = template.HTML(
    title,
    list,
    `<h2>${title}</h2>${description}`,
    `<a href="/create">create</a>`
  );
  response.writeHead(200);
  response.end(html);
});
```

수정해주면 메인페이지에서 리스트까지 완성이다.

## 상세보기 구현

파일을 불러왔던 상세보기를 MySQL로 바꿔보자.  

```js
fs.readdir('./data', function(error, filelist){
      var filteredId = path.parse(queryData.id).base;
      fs.readFile(`data/${filteredId}`, 'utf8', function(err, description){
        var title = queryData.id;
        var sanitizedTitle = sanitizeHtml(title);
        var sanitizedDescription = sanitizeHtml(description, {
          allowedTags:['h1']
        });
        var list = template.list(filelist);
        var html = template.HTML(sanitizedTitle, list,
          `<h2>${sanitizedTitle}</h2>${sanitizedDescription}`,
          ` <a href="/create">create</a>
            <a href="/update?id=${sanitizedTitle}">update</a>
            <form action="delete_process" method="post">
              <input type="hidden" name="id" value="${sanitizedTitle}">
              <input type="submit" value="delete">
            </form>`
        );
        response.writeHead(200);
        response.end(html);
      });
    });
```
먼저 파일을 불러왔을 때의 코드다. 기본적으로 파일시스템과 readdir이라는 메소드를 사용하기 때문에  
이 부분부터 `db.query`로 바꿔주어야한다.  
```js
db.query('SELECT * FROM topic', function(error,topics){
      var title = 'Welcome';
      var description = 'Hello, Node.js';
      var list = template.list(topics);
      var html = template.HTML(title, list,
        `<h2>${title}</h2>${description}`,
        `<a href="/create">create</a>`
      );
```
전 시간에서 사용했던 DB를 불러오는 코드에서 URL의 querystring에 있는 id에 따라 title과 description을 불러와야 한다.  
그 전에 어떤 SQL을 쓸지 고민해보면  
```sql
SELECT SELECT * FROM topic WHERE id=3
```
`WHERE id = number`하면 원하는 행의 값을 불러 올 수 있다.  
이 것을 main.js에 불러오도록 작성하면  
```js
db.query(`SELECT * FROM topic`, function(error,topics){
      if(error){
        throw error;
      }
      db.query(`SELECT * FROM topic WHERE id=?`,[queryData.id], function(error2, topic){
         if(error2){
           throw error2;
         }
```
여기서 `if(error){throw error;}`는 오류가 나면 작동을 멈추는 코드이다.  
그 밑에서 `db.query`에 두번째 인자를 보면 `[queryData.id]`로 작성된 것을 볼 수 있는데  
Template literal로 작성할 때와 다르게 이렇게 작성하면 사용자 입력에 대한 공격에 대응할 수 있다.  

```js
db.query(`SELECT * FROM topic`, function(error,topics){
  if(error){
    throw error;
  }
  db.query(`SELECT * FROM topic WHERE id=?`,[queryData.id], function(error2, topic){
     if(error2){
       throw error2;
     }
    var title = topic[0].title;
    var description = topic[0].description;
    var list = template.list(topics);
    var html = template.HTML(title, list,
    `<h2>${title}</h2>${description}`,
    `<a href="/create">create</a>
    <a href="/update?id=${queryData.id}">update</a>
        <form action="delete_process" method="post">
          <input type="hidden" name="id" value="${queryData.id}">
          <input type="submit" value="delete">
        </form>`
  );
  response.writeHead(200);
  response.end(html);
  });
});
```
`var title`과 `var description`에 sql값을 대입할 때 `topic[0]`처럼 배열을 사용하는 이유는  
데이터가 배열에 담겨서 들어오기 때문에 배열을 사용해야한다.  
