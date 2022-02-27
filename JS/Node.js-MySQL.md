<img src="https://user-images.githubusercontent.com/96982072/155693520-d53693b0-2559-4139-9eda-9221cc5c40ed.png" width = 800px/>

# 소개

Node.js는 구글 크롬의 자바스크립트 V8엔진으로 빌드된 자바스크립트 런타임이다.  
브라우저에만 자바스크립트를 쓰는 것이 아닌 브라우저 밖으로 확장하기 위해 만들어 진 것이 Node.js다.  
Node.js를 이용하면 자바스크립트 언어로 서버를 만들 수 있는데,  
이번에는 MySQL을 이용해 서버에서 정보를 가져오고 수정하는 법을 배울 예정이다.

# 준비 및 사용방법

소스코드와 셋팅은 생활코딩의 [WEB2 Node.js-MySQL](https://opentutorials.org/course/3347)수업을 따라간다.

# MySQL로 구현

## 웹페이지 구현

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

이제 더 나가서 success를 출력하는 대신 웹페이지를 불러오도록 작성을 해보자.  
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

## 생성 기능 구현

```js
db.query(`SELECT * FROM topic`, function(error,topics){
  var title = 'Create';
  var list = template.list(topics);
  var html = template.HTML(title, list, `
     <form action="/create_process" method="post">
       <p><input type="text" name="title" placeholder="title"></p>
       <p>
         <textarea name="description" placeholder="description"></textarea>
       </p>
       <p>
         <input type="submit">
       </p>
     </form>
   `, 
   `<a href="/create">create</a>`);
   response.writeHead(200);
   response.end(html);
});
```
db.query를 이용해서 Create 버튼을 생성하고 클릭하면 현재 글 목록과 폼을 보여주는 코드다.  
```js
 var body = '';
  request.on('data', function(data){
      body = body + data;
  });
  request.on('end', function(){
    var post = new URLSearchParams(body)
    db.query(`
    INSERT INTO topic (title, description, created, author_id)
      Value(?, ?, NOW(), ?)`, 
      [post.get('title'), post.get('description'), 1],
      function(error, result){
        if(error){
          throw error;
        }
        response.writeHead(302, {Location: `/?id=${result.insertId}`});
        response.end();
      }
    )
  });    
```
그 이후 글 제목과 내용을 입력하고 `submit`을 누르면 MySQL topic에 row를 생성하고 
웹페이지 글 목록을 추가된 항목과 함께 보여준다.  

## 수정 기능 구현

수정도 생성과 마찬가지로 `/update`에서 목록과 폼을 생성하는 것까지는 비슷하다.  
```js
 db.query(`SELECT * FROM topic`, function(error,topics){
  if(error){
    throw error;
  }
  db.query(`SELECT * FROM topic WHERE id=?`,[queryData.id], function(error2,topic){
    if(error2){
      throw error2;
    }
     var list = template.list(topics);
     var html = template.HTML(topic[0].title, list,
       `
       <form action="/update_process" method="post">
         <input type="hidden" name="id" value="${topic[0].id}">
         <p><input type="text" name="title" placeholder="title" value="${topic[0].title}"></p>
         <p>
           <textarea name="description" placeholder="description">${topic[0].description}</textarea>
         </p>
         <p>
           <input type="submit">
         </p>
       </form>
       `,
       `<a href="/create">create</a> <a href="/update?id=${topic[0].id}">update</a>`
     );
     response.writeHead(200);
     response.end(html);
   });
 });
```
다음은 `/update_process`에서 SQL의 `UPDATE topic SET`을 이용해서 수정 기능을 사용하고  
`submit`을 누르면 그 수정한 페이지를 보여주는 것이다.  
```js
var body = '';
  request.on('data', function(data){
      body = body + data;
  });
  request.on('end', function(){
      var post = qs.parse(body);
      db.query(`UPDATE topic SET title=?, description=?, author_id=1 WHERE id=?`, 
      [post.title, post.description, post.id], 
      function(error, result){
        response.writeHead(302, {Location: `/?id=${post.id}`});
        response.end();
      })
  });
```

## 삭제 기능 구현  

SQL의 `DELETE`를 이용해서 삭제기능을 구현할 수 있지만, 반드시 `WHERE`을 같이 사용해야 한다.
`WEHRE`을 사용하지 않으면 테이블 전체가 삭제되기 때문에 반드시 입력하자.  
삭제를 누르고나면 그 행을 사라지므로 페이지를 최상위로 이동한다.  

```js
var body = '';
  request.on('data', function(data){
      body = body + data;
  });
  request.on('end', function(){
      var post = qs.parse(body);
      var id = post.id;
      var filteredId = path.parse(id).base;
      db.query(`DELETE FROM topic WHERE id=?`, [post.id], function(error, result){
        if(error){
          throw error;
        }
        response.writeHead(302, {Location: `/`});
        response.end();
      })
  });
```  

# JOIN을 이용하기  

지금까지는 topic 테이블을 이용하여 SQL과 Nodejs의 관계를 알아보았는데  
지금부터는 author테이블을 이용해서 topic과의 관계를 통해  
관계형 데이터베이스를 어떻게 활용할 수 있는지 구현해본다.  

## 글 상세보기 구현  

위에서 작성한 상세보기에서 `SELECT * FROM topic WHERE id=?`부분이 상세보기를  
SQL로 구현하는 부분이였다.  여기서 JOIN을 사용해서 topic과 author를 연결해주면  
```js
db.query(`SELECT * FROM topic LEFT JOIN author ON topic.author_id=author.id WHERE topic.id=?`,[queryData.id], function(error2, topic){
     if(error2){
       throw error2;
     }
    var title = topic[0].title;
    var description = topic[0].description;
    var list = template.list(topics);
    var html = template.HTML(title, list,
    `
    <h2>${title}</h2>
    ${description}
    by ${topic[0].name}
    `,
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
topic의 author_id와 author의 id가 연결되었다.  
`template.HTML`에서 `by ${topic[0].name}`을 해주고 웹페이지에서 새로고침 해보면  
저자가지 뜨는 것을 볼 수 있다.  

## 글 생성 구현 

생성에서는 SQL명령어에서
```js
db.query(`SELECT * FROM topic`, function(error,topics){
  db.query(`SELECT *FROM author`, function(error2, authors){
   var title = 'Create';
   var list = template.list(topics);
   var html = template.HTML(title, list, `
```
author테이블을 조회하고
```js
db.query(`
  INSERT INTO topic (title, description, created, author_id)
    Value(?, ?, NOW(), ?)`, 
    [post.get('title'), post.get('description'), post.get('author')],
```
author_id가 1이였던 것을 author로 바꿀 수 있다.  
여기서 글을 생성할 때 저자를 추가해주는 코드를 추가하면  
template.js에서 객체를 추가하고
```js
authorSelect:function(authors){
  var tag = '';
   var i = 0;
   while(i < authors.length){
     tag += `<option value="${authors[i].id}">${authors[i].name}</option>`;
     i++;
   }
   return `
   <select name="author">
     ${tag}
   </select>
   `
}
```
main.js의 `/create`에 `template.HTML`에서
```js
var html = template.HTML(title, list, `
   <form action="/create_process" method="post">
     <p><input type="text" name="title" placeholder="title"></p>
     <p>
       <textarea name="description" placeholder="description"></textarea>
     </p>
     <p>
      ${template.authorSelect(authors)}
     </p>
     <p>
       <input type="submit">
     </p>
   </form>
 `, 
 `<a href="/create">create</a>`
 );
```
콤보박스를 만들어 글을 생성할 때 저자를 추가할 수 있다.

## 글 수정 구현

생성과 마찬가지로 `/update`에서 author를 조회하고 `template.authorSelect`로  
수정 시 콤보박스를 추가할 수 있다.  
```js
db.query(`SELECT * FROM topic`, function(error,topics){
 if(error){
   throw error;
 }
 db.query(`SELECT * FROM topic WHERE id=?`,[queryData.id], function(error2,topic){
   if(error2){
     throw error2;
   }
   db.query(`SELECT * FROM author`, function(error2, authors){
    var list = template.list(topics);
    var html = template.HTML(topic[0].title, list,
      `
      <form action="/update_process" method="post">
        <input type="hidden" name="id" value="${topic[0].id}">
        <p><input type="text" name="title" placeholder="title" value="${topic[0].title}"></p>
        <p>
          <textarea name="description" placeholder="description">${topic[0].description}</textarea>
        </p>
        <p>
          ${template.authorSelect(authors, topic[0].author_id)}
        </p>
        <p>
          <input type="submit">
        </p>
      </form>
      `,
      `<a href="/create">create</a> <a href="/update?id=${topic[0].id}">update</a>`
    );
    response.writeHead(200);
    response.end(html);
   });
  });
});
```
다른 점은 수정 과정에서 콤보박스가 현재 저자를 보여주도록 template.js를 바꿔준다.  
```js
authorSelect:function(authors, author_id){
  var tag = '';
   var i = 0;
   while(i < authors.length){
     var selected = ``;
     if(authors[i].id === author_id) {
       selected = ` selected`;
     }
     tag += `<option value="${authors[i].id}"${selected}>${authors[i].name}</option>`;
     i++;
   }
   return `
   <select name="author">
     ${tag}
   </select>
   `
}
```

# Nodejs 정리정돈  

여기까지가 Nodejs-MySQL 과정의 정상이라고 한다.  
이제껏 작성해온 코드를 보니 너무 어지럽다고 느꼈는데, 이 후부터는 작성했던 코드를 정리해보고  
좀 더 심화과정으로 넘어간다고 한다.  

## 정리정돈

### 메인페이지 정리

코드로 작성한 main.js파일의 읽기,생성,수정,삭제를 정리정돈 해보자.  

우선 메인웹페이지를 해당하는 부분을 분리해보자.  
한번만 모듈화를 하려면 `module.exports`를 하면 되지만
여러 곳에 사용 할 것이라면 `exports`를 한다.  

topic.js
```js
var template = require('./template.js');
var db = require('./db.js');
exports.home = function(request,response){
    db.query('SELECT * FROM topic', function(error,topics){
        var title = 'Welcome';
        var description = 'Hello, Node.js';
        var list = template.list(topics);
        var html = template.HTML(title, list,
          `<h2>${title}</h2>${description}`,
          `<a href="/create">create</a>`
        );
        response.writeHead(200);
        response.end(html);
      });
}
```
main.js
```js
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url, true).query;
    var pathname = url.parse(_url, true).pathname;
    if(pathname === '/'){
      if(queryData.id === undefined){
        topic.home(request,response);
      } else {
        db.query(`SELECT * FROM topic`, function(error,topics){
          if(error){
            throw error;
          }
          db.query(`SELECT * FROM topic LEFT JOIN author ON topic.author_id=author.id WHERE topic.id=?`,[queryData.id], function(error2, topic){
             if(error2){
               throw error2;
             }
            var title = topic[0].title;
            var description = topic[0].description;
            var list = template.list(topics);
            var html = template.HTML(title, list,
            `
            <h2>${title}</h2>
            ${description}
            <p>by ${topic[0].name}</p>
            `,
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
      }
```
topic.js를 작성하면  
main.js에서는 `topic.home()`로 대체한다.  
어떤 한 기능을 통째로 옮길때는 여러 오류들이 발생하므로 로그를 참고한다.  
`topic.home()`을 인자없이 사용할 경우, `reponse`가 없다는 오류가 발생하므로  
인자로 `request`,`response`를 넣어준다.  

### 상세보기, 생성, 수정, 삭제 정리

위와 마찬가지로 topic.js에 `exports`로 상세보기 부분과 생성 부분을 만들어 준다.  

상세보기
```js
exports.page = function(request, response){
    var _url = request.url;
    var queryData = url.parse(_url, true).query;
    db.query(`SELECT * FROM topic`, function(error,topics){
        if(error){
          throw error;
        }
        db.query(`SELECT * FROM topic LEFT JOIN author ON topic.author_id=author.id WHERE topic.id=?`,[queryData.id], function(error2, topic){
           if(error2){
             throw error2;
           }
          var title = topic[0].title;
          var description = topic[0].description;
          var list = template.list(topics);
          var html = template.HTML(title, list,
          `
          <h2>${title}</h2>
          ${description}
          <p>by ${topic[0].name}</p>
          `,
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
}
```
생성
```js
exports.create = function(request, response){
    db.query(`SELECT * FROM topic`, function(error,topics){
        db.query(`SELECT *FROM author`, function(error2, authors){
         var title = 'Create';
         var list = template.list(topics);
         var html = template.HTML(title, list, `
            <form action="/create_process" method="post">
              <p><input type="text" name="title" placeholder="title"></p>
              <p>
                <textarea name="description" placeholder="description"></textarea>
              </p>
              <p>
               ${template.authorSelect(authors)}
              </p>
              <p>
                <input type="submit">
              </p>
            </form>
          `, 
          `<a href="/create">create</a>`
          );
          response.writeHead(200);
          response.end(html);
        });
 
      });
}

exports.create_process = function(request, response){
    var body = '';
    request.on('data', function(data){
        body = body + data;
    });
    request.on('end', function(){
      var post = new URLSearchParams(body);
      db.query(`
      INSERT INTO topic (title, description, created, author_id)
        Value(?, ?, NOW(), ?)`, 
        [post.get('title'), post.get('description'), post.get('author')],
        function(error, result){
          if(error){
            throw error;
          }
          response.writeHead(302, {Location: `/?id=${result.insertId}`});
          response.end();
        }
      )
    });    
}
```
main.js에서 모듈화해준 자리에 각각 입력해준다.  

- `topic.page(request, response);`
- `topic.create(request, response);`
- `topic.create_process(request, response);` 

입력하고 에러가 없는지 확인해보자.  

마찬가지로 수정, 삭제도 똑같은 과정을 거치면  

```js
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url, true).query;
    var pathname = url.parse(_url, true).pathname;
    if(pathname === '/'){
      if(queryData.id === undefined){
        topic.home(request,response);
      } else {
        topic.page(request, response);
      }
    } else if(pathname === '/create'){
      topic.create(request, response);
    } else if(pathname === '/create_process'){
      topic.create_process(request, response);
    } else if(pathname === '/update'){
      topic.update(request, response);
    } else if(pathname === '/update_process'){
      topic.update_process(request, response);
    } else if(pathname === '/delete_process'){
      topic.delete_process(request, response);
    } else {
      response.writeHead(404);
      response.end('Not found');
    }
});
app.listen(3000);
```
이렇게 메인페이지를 정리할 수 있다.  
왜 코드를 정리해야하는지 알 수 있었던 수업이였다.  






