<img src="https://user-images.githubusercontent.com/96982072/154977336-bc7ba4aa-e3e9-488c-b68d-0ca9fb80c4dd.png" width=600 />

> JQuery부분은 제외했다.

> [오픈튜토리얼 - 생활코딩](https://opentutorials.org/module/904/6682)
> 강의를 듣고 어디까지 들었는지 확인하기 위해 강의 내용을 스크랩하였습니다.

# Object Model - 객체화란 무엇인가?

웹브라우저의 구성요소들은 하나하나가 객체화되어 있다.  
자바스크립트로 이 객체를 제어해서 웹브라우저, 웹페이지를 제어할 수 있게 된다.  
이 객체들은 서로 계층적인 관계로 구조화되어 있다.  
BOM과 DOM은 이 구조를 구성하고 있는 가장 큰 틀의 분류라고 할 수 있다.

# BOM

BOM(Browser Object Model)이란 웹브라우저의 창이나 프래임을 추상화해서  
프로그래밍적으로 제어할 수 있도록 제공하는 수단이다.  
BOM은 전역객체인 Window의 프로퍼티와 메소드들을 통해서 제어할 수 있다.  
따라서 BOM에 대한 수업은 Window 객체의 프로퍼티와 메소드의 사용법을  
배우는 것이라고 해도 과언이 아닐 것이다.  
본 토픽의 하위 수업에서는 Window 객체의 사용법을 알아볼 것이다.

## 전역객체 Window

Window 객체는 모든 객체가 소속된 객체이고, 전역객체이면서, 창이나 프레임을 의미한다.

## 전역객체

Window 객체는 식별자 window를 통해서 얻을 수 있다.  
또한 생략 가능하다. Window 객체의 메소드인 alert을 호출하는 방법은 아래와 같다.

```
<!DOCTYPE html>
<html>
<script>
    alert('Hello world');
    window.alert('Hello world');
</script>
<body>

</body>
</html>
```

아래는 전역변수 a에 접근하는 방법이다.

```
<!DOCTYPE html>
<html>
<script>
    var a = 1;
    alert(a);
    alert(window.a);
</script>
<body>

</body>
</html>
```

객체를 만든다는 것은 결국 window 객체의 프로퍼티를 만드는 것과 같다.

```
<!DOCTYPE html>
<html>
<script>
    var a = {id:1};
    alert(a.id);
    alert(window.a.id);
</script>
<body>

</body>
</html>
```

예제를 통해서 알 수 있는 것은 전역변수와 함수가 사실은  
window 객체의 프로퍼티와 메소드라는 것이다.  
또한 모든 객체는 사실 window의 자식이라는 것도 알 수 있다.  
이러한 특성을 ECMAScript에서는 Global 객체라고 부른다.  
ECMAScript의 Global 객체는 호스트 환경에 따라서 이름이 다르고 하는 역할이 조금씩 다르다.  
웹브라우저 자바스크립트에서 Window 객체는 ECMAScript의 전역객체이면서  
동시에 웹브라우저의 창이나 프레임을 제어하는 역할을 한다.

## 사용자와 커뮤니케이션 하기

HTML은 form을 통해서 사용자와 커뮤니케이션할 수 있는 기능을 제공한다. 자바스크립트에는 사용자와 정보를 주고 받을 수 있는 간편한 수단을 제공한다.

- alert
  경고창이라고 부른다.  
   사용자에게 정보를 제공하거나 디버깅등의 용도로 많이 사용한다.
  ```
  <!DOCTYPE html>
  <html>
      <body>
          <input type="button" value="alert" onclick="alert('hello world');" />
      </body>
  </html>
  ```
- confirm

  확인을 누르면 true, 취소를 누르면 false를 리턴한다.

  ```
  <!DOCTYPE html>
  <html>
      <body>
          <input type="button" value="confirm" onclick="func_confirm()" />
          <script>
              function func_confirm(){
                  if(confirm('ok?')){
                      alert('ok');
                  } else {
                      alert('cancel');
                  }
              }
          </script>
      </body>
  </html>
  ```

- prompt

  사용자로부터 값을 입력받고, 입력받은 값으로 애플리케이션을 동작할 수 있게한다.

  ```
  <!DOCTYPE html>
  <html>
      <body>
          <input type="button" value="prompt" onclick="func_prompt()" />
          <script>
              function func_prompt(){
                  if(prompt('id?') === 'egoing'){
                      alert('welcome');
                  } else {
                      alert('fail');
                  }
              }
          </script>
      </body>
  </html>
  ```

## Location 객체

Location 객체는 문서의 주소와 관련된 객체로 Window 객체의 프로퍼티다.  
이 객체를 이용해서 윈도우의 문서 URL을 변경할 수 있고,  
문서의 위치와 관련해서 다양한 정보를 얻을 수 있다.

- 현재 윈도우의 URL 알아내기

  아래는 현재 윈도우의 문서가 위치하는 URL을 알아내는 방법이다.

  ```
  console.log(location.toString(), location.href);
  ```

- URL Parsing

  location 객체는 URL을 의미에 따라서 별도의 프로퍼티로 제공하고 있다.

  ```
  console.log(location.protocol, location.host, location.port, location.pathname, location.search, location.hash)
  ```

- URL 변경하기

  아래 코드는 현재 문서를 `http://egoing.net`으로 이동한다.

  ```
  location.href = 'http://egoing.net';
  ```

  아래와 같은 방법도 같은 효과를 낸다.

  ```
  location = 'http://egoing.net';
  ```

  아래는 현재 문서를 리로드하는 간편한 방법을 제공한다.

  ```
  location.reload();
  ```

## 창 제어

window.open 메소드는 새 창을 생성한다.  
현대의 브라우저는 대부분 탭을 지원하기 때문에 window.open은 새 창을 만든다.  
아래는 메소드의 사용법이다.

```
<!DOCTYPE html>
<html>
<style>li {padding:10px; list-style: none}</style>
<body>
<ul>
    <li>
        첫번째 인자는 새 창에 로드할 문서의 URL이다. 인자를 생략하면 이름이 붙지 않은 새 창이 만들어진다.<br />
        <input type="button" onclick="open1()" value="window.open('demo2.html');" />
    </li>
    <li>
        두번째 인자는 새 창의 이름이다. _self는 스크립트가 실행되는 창을 의미한다.<br />
        <input type="button" onclick="open2()" value="window.open('demo2.html', '_self');" />
    </li>
    <li>
        _blank는 새 창을 의미한다. <br />
        <input type="button" onclick="open3()" value="window.open('demo2.html', '_blank');" />
    </li>
    <li>
        창에 이름을 붙일 수 있다. open을 재실행 했을 때 동일한 이름의 창이 있다면 그곳으로 문서가 로드된다.<br />
        <input type="button" onclick="open4()" value="window.open('demo2.html', 'ot');" />
    </li>
    <li>
        세번재 인자는 새 창의 모양과 관련된 속성이 온다.<br />
        <input type="button" onclick="open5()" value="window.open('demo2.html', '_blank', 'width=200, height=200, resizable=yes');" />
    </li>
</ul>

<script>
function open1(){
    window.open('demo2.html');
}
function open2(){
    window.open('demo2.html', '_self');
}
function open3(){
    window.open('demo2.html', '_blank');
}
function open4(){
    window.open('demo2.html', 'ot');
}
function open5(){
    window.open('demo2.html', '_blank', 'width=200, height=200, resizable=no');
}
</script>
</body>
</html>
```

# DOM

Document Object Model로 웹페이지를 자바스크립트로 제어하기 위한 객체 모델을 의미한다.  
window 객체의 document 프로퍼티를 통해서 사용할 수 있다.  
Window 객체가 창을 의미한다면 Document 객체는 윈도우에 로드된 문서를 의미한다고 할 수 있다.  
DOM의 하위 수업에서는 문서를 제어하는 방법에 대한 내용을 다룬다.

## 제어 대상을 찾기

문서를 자바스크립트로 제어하려면 제어의 대상에 해당되는 객체를 찾는 것이 제일 먼저 할 일이다.  
문서 내에서 객체를 찾는 방법은 document 객체의 메소드를 이용한다.

- document.getElementsByTagName

  문서 내에서 특정 태그에 해당되는 객체를 찾는 방법은 여러가지가 있다.  
   `getElementsByTagName`은 인자로 전달된 태그명에 해당하는 객체들을 찾아서  
   그 리스트를 NodeList라는 유사 배열에 담아서 반환한다.  
   NodeList는 배열은 아니지만 length와 배열접근연산자를 사용해서 엘리먼트를 조회할 수 있다.

  ```
  <!DOCTYPE html>
  <html>
  <body>
  <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li>JavaScript</li>
  </ul>
  <script>
      var lis = document.getElementsByTagName('li');
      for(var i=0; i < lis.length; i++){
          lis[i].style.color='red';
      }
  </script>
  </body>
  </html>
  ```

  만약 조회의 대상을 좁히려면 아래와 같이 특정 객체를 지정하면 된다.  
   이러한 원칙은 다른 메소드에도 적용된다.

  ```
  <!DOCTYPE html>
  <html>
  <body>
  <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li>JavaScript</li>
  </ul>
  <ol>
      <li>HTML</li>
      <li>CSS</li>
      <li>JavaScript</li>
  </ol>
  <script>
      var ul = document.getElementsByTagName('ul')[0];
      var lis = ul.getElementsByTagName('li');
      for(var i=0; lis.length; i++){
          lis[i].style.color='red';
      }
  </script>
  </body>
  </html>
  ```

- document.getElementsByClassName

  class 속성의 값을 기준으로 객체를 조회할수도 있다.

  ```
  <!DOCTYPE html>
  <html>
  <body>
  <ul>
      <li>HTML</li>
      <li class="active">CSS</li>
      <li class="active">JavaScript</li>
  </ul>
  <script>
      var lis = document.getElementsByClassName('active');
      for(var i=0; i < lis.length; i++){
          lis[i].style.color='red';
      }
  </script>
  </body>
  </html>
  ```

- document.getElementById

  id 값을 기준으로 객체를 조회한다. 성능면에서 가장 우수하다.

  ```
  <!DOCTYPE html>
  <html>
  <body>
  <ul>
      <li>HTML</li>
      <li id="active">CSS</li>
      <li>JavaScript</li>
  </ul>
  <script>
      var li = document.getElementById('active');
      li.style.color='red';
  </script>
  </body>
  </html>
  ```

- document.querySelector

  css 선택자의 문법을 이용해서 객체를 조회할수도 있다.

  ```
  <!DOCTYPE html>
  <html>
  <body>
  <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li>JavaScript</li>
  </ul>
  <ol>
      <li>HTML</li>
      <li class="active">CSS</li>
      <li>JavaScript</li>
  </ol>

  <script>
      var li = document.querySelector('li');
      li.style.color='red';
      var li = document.querySelector('.active');
      li.style.color='blue';
  </script>
  </body>
  </html>
  ```

## :pushpin: 궁금한점

queryselector와 getElementsByTagName의 차이

[스택오버플로우 링크](https://stackoverflow.com/questions/18247289/what-is-the-difference-between-queryselectorall-and-getelementsbytagname)

getElementsByTagName는 태그네임들만 가져온다.
queryselector는 클래스, ID, 태그네임 등 어떤 선택자든 가능하다.

## HTMLElement

getElement\* 메소드를 통해서 원하는 객체를 조회했다면 이 객체들을 대상으로  
구체적인 작업을 처리해야 한다. 이를 위해서는 획득한 객체가 무엇인지 알아야 한다.  
그래야 적절한 메소드나 프로퍼티를 사용할 수 있다.

아래 코드는 getElement\*의 리턴 값을 보여준다.

```
<ul>
    <li>HTML</li>
    <li>CSS</li>
    <li id="active">JavaScript</li>
</ul>
<script>
    var li = document.getElementById('active');
    console.log(li.constructor.name);
    var lis = document.getElementsByTagName('li');
    console.log(lis.constructor.name);
</script>
```

실행결과

```
HTMLLIElement
HTMLCollection
```

이것을 통해서 알 수 있는 것은 아래와 같다.

- document.getElementById : 리턴 데이터 타입은 HTMLLIELement
- document.getElementsByTagName : 리턴 데이터 타입은 HTMLCollection

즉 실행결과가 하나인 경우 HTMLLIELement, 복수인 경우 HTMLCollection을 리턴하고 있다.

실행결과가 하나인 엘리먼트들을 좀 더 살펴보자.

```
<a id="anchor" href="http://opentutorials.org">opentutorials</a>
<ul>
    <li>HTML</li>
    <li>CSS</li>
    <li id="list">JavaScript</li>
</ul>
<input type="button" id="button" value="button" />
<script>
    var target = document.getElementById('list');
    console.log(target.constructor.name);

    var target = document.getElementById('anchor');
    console.log(target.constructor.name);

    var target = document.getElementById('button');
    console.log(target.constructor.name);

</script>
```

결과

```
HTMLLIElement
HTMLAnchorElement
HTMLInputElement
```

이를 통해서 알 수 있는 것은 엘리먼트의 종류에 따라서 리턴되는 객체가 조금씩 다르다는 것이다. 각각의 객체의 차이점을 알아보자. 링크는 DOM의 스펙이다.

- [HTMLLIElement](https://www.w3.org/TR/2003/REC-DOM-Level-2-HTML-20030109/html.html#ID-74680021)
- [HTMLAnchroElement](https://www.w3.org/TR/DOM-Level-2-HTML/html.html#ID-48250443)
- [HTMLInputElement](https://www.w3.org/TR/DOM-Level-2-HTML/html.html#ID-6043025)

`HTMLLIElement`를 보자.

```
interface HTMLLIElement : HTMLElement {
           attribute DOMString       type;
           attribute long            value;
};
```

다음은 `HTMLAnchroElement`이다.

```
interface HTMLAnchorElement : HTMLElement {
           attribute DOMString       accessKey;
           attribute DOMString       charset;
           attribute DOMString       coords;
           attribute DOMString       href;
           attribute DOMString       hreflang;
           attribute DOMString       name;
           attribute DOMString       rel;
           attribute DOMString       rev;
           attribute DOMString       shape;
           attribute long            tabIndex;
           attribute DOMString       target;
           attribute DOMString       type;
  void               blur();
  void               focus();
};
```

즉 엘리먼트 객체에 따라서 프로퍼티가 다르다는 것을 알 수 있다.  
하지만 모든 엘리먼트들은 HTMLElement를 상속 받고 있다.

interface HTMLLIElement : **HTMLElement** {
interface HTMLAnchorElement : **HTMLElement** {

`HTMLElement`는 아래와 같다.

```
interface HTMLElement : Element {
           attribute DOMString       id;
           attribute DOMString       title;
           attribute DOMString       lang;
           attribute DOMString       dir;
           attribute DOMString       className;
};
```

- DOM Tree

  모든 엘리먼트는 HTMLElement의 자식이다.  
   따라서 HTMLElement의 프로퍼티를 똑같이 가지고 있다.  
   동시에 엘리먼트의 성격에 따라서 자신만의 프로퍼티를 가지고 있는데  
   이것은 엘리먼트의 성격에 따라서 달라진다.  
   HTMLElement는 Element의 자식이고 Element는 Node의 자식이다.  
   Node는 Object의 자식이다. 이러한 관계를 DOM Tree라고 한다.

  이 관계를 그림으로 나타내면 아래와 같다.

    <img src="https://user-images.githubusercontent.com/96982072/154845674-e5c60088-0042-4b01-88d0-f5143ec61fff.png"/>

  이러한 관계를 이해하지 못하면 필요한 API를 찾아내는 것이 어렵거나 몹시 혼란스러울 것이다.  
   다행인 것은 jQuery와 같은 라이브러리를 이용한다면 이러한 관계를 몰라도 된다.  
   혹시 이해가 안된다고 너무 상심하지 말자.

## HTMLCollection

HTMLCollection은 리턴 결과가 복수인 경우에 사용하게 되는 객체다.  
유사배열로 배열과 비슷한 사용방법을 가지고 있지만 배열은 아니다.

HTMLCollection의 목록은 실시간으로 변경된다. 아래 코드를 보자.

```
<!DOCTYPE html>
<html>
<body>
<ul>
    <li>HTML</li>
    <li>CSS</li>
    <li id="active">JavaScript</li>
</ul>
<script>
console.group('before');
var lis = document.getElementsByTagName('li');
for(var i = 0; i < lis.length; i++){
    console.log(lis[i]);
}
console.groupEnd();
console.group('after');
lis[1].parentNode.removeChild(lis[1]);
for(var i = 0; i < lis.length; i++){
    console.log(lis[i]);
}
console.groupEnd();
</script>
</body>
</html>
```

# Element 객체

Element 객체는 엘리먼트를 추상화한 객체다.  
HTMLElement 객체와의 관계를 이해하기 위해서는 DOM의 취지에 대한 이해가 선행되야 한다.  
DOM은 HTML만을 제어하기 위한 모델이 아니다.  
HTML이나 XML, SVG, XUL과 같이 마크업 형태의 언어를 제어하기 위한 규격이기 때문에  
Element는 마크업 언어의 일반적인 규격에 대한 속성을 정의하고 있고,  
각각의 구체적인 언어(HTML,XML,SVG)를 위한 기능은  
HTMLElement, SVGElement, XULElement와 같은 객체를 통해서 추가해서 사용하고 있다.

## 다른 객체들과의 관계

DOM의 계층구조에서 Element 객체의 위치는 아래와 같다.

<img src="https://user-images.githubusercontent.com/96982072/154846635-3079da7a-1dfa-4a9d-a147-66eaaec1b574.png"/>

## 주요 기능

- 식별자

  문서내에서 특정한 엘리먼트를 식별하기 위한 용도로 사용되는 API

  - Element.classList
  - Element.className
  - Element.id
  - Element.tagName

- 조회

  엘리먼트의 하위 엘리먼트를 조회하는 API

  - Element.getElementsByClassName
  - Element.getElementsByTagName
  - Element.querySelector
  - Element.querySelectorAll

- 속성

  엘리먼트의 속성을 알아내고 변경하는 API

  - Element.getAttribute(name)
  - Element.setAttribute(name, value)
  - Element.hasAttribute(name);
  - Element.removeAttribute(name);

## 식별자 API

엘리먼트를 제어하기 위해서는 그 엘리먼트를 조회하기 위한 식별자가 필요하다.  
본 수업에서는 식별자 API들에 대해서 알아보자.

HTML에서 엘리먼트의 이름과 id 그리고 class는 식별자로 사용된다.  
식별자 API는 이 식별자를 가져오고 변경하는 역할을 한다.

- Element.tagName (Read Only)

  해당 엘리먼트의 태그 이름을 알아낸다. 태그 이름을 변경하지는 못한다.

  ```
  <ul>
      <li>html</li>
      <li>css</li>
      <li id="active" class="important current">JavaScript</li>
  </ul>
  <script>
  console.log(document.getElementById('active').tagName)
  </script>
  ```

- Element.id

  문서에서 id는 단 하나만 등장할 수 있는 식별자다.  
   아래 예제는 id의 값을 읽고 변경하는 방법을 보여준다.

  ```
  <ul>
      <li>html</li>
      <li>css</li>
      <li id="active">JavaScript</li>
  </ul>
  <script>
  var active = document.getElementById('active');
  console.log(active.id);
  active.id = 'deactive';
  console.log(active.id);
  </script>
  ```

- Element.className

  클래스는 여러개의 엘리먼트를 그룹핑할 때 사용한다.

  ```
  <ul>
      <li>html</li>
      <li>css</li>
      <li id="active">JavaScript</li>
  </ul>
  <script>
  var active = document.getElementById('active');
  // class 값을 변경할 때는 프로퍼티의 이름으로 className을 사용한다.
  active.className = "important current";
  console.log(active.className);
  // 클래스를 추가할 때는 아래와 같이 문자열의 더한다.
  active.className += " readed"
  </script>
  ```

- Element.classList

      className에 비해서 훨씬 편리한 사용성을 제공한다.

      ```
      <ul>
          <li>html</li>
          <li>css</li>
          <li id="active" class="important current">JavaScript</li>
      </ul>
      <script>
      function loop(){
          for(var i=0; i<active.classList.length; i++){
              console.log(i, active.classList[i]);
          }
      }
      // 클래스를 추가
      </script>
      <input type="button" value="DOMTokenList" onclick="console.log(active.classList);" />
      <input type="button" value="조회" onclick="loop();" />
      <input type="button" value="추가" onclick="active.classList.add('marked');" />
      <input type="button" value="제거" onclick="active.classList.remove('important');" />
      <input type="button" value="토글" onclick="active.classList.toggle('current');" />
      ```

  :pushpin: 다크모드를 만드는데 class를 제어하면 편하지않을까?

## 조회 API

조회 API는 엘리먼트를 조회하는 기능이다.  
조회 방법에 대해서는 이미 여러차례 살펴봤기 때문에 이번 시간에 알아볼 내용은  
조회 대상을 제한하는 방법에 대한 것이다.

지금까지 document.getElementsBy* 메소드를 통해서 엘리먼트를 조회했다.  
document 객체는 문서 전체를 의미하는 엘리먼트이기 때문에  
document의 조회 메소드는 문서 전체를 대상으로 엘리먼트를 조회한다.  
Element 객체 역시도 getElementsBy* 엘리먼트를 가지고 있는데  
Element 객체의 조회 메소드는 해당 엘리먼트의 하위 엘리먼트를 대상으로 조회를 수행한다.

## 속성 API

속성은 HTML에서 태그명만으로는 부족한 부가적인 정보라고 할 수 있다. 이 속성을 어떻게 제어하는가 알아보자.

속성을 제어하는 API는 아래와 같다. 각각의 기능은 이름을 통해서 충분히 유추할 수 있을 것이다.

- Element.getAttribute(name)
- Element.setAttribute(name, value)
- Element.hasAttribute(name);
- Element.removeAttribute(name);

```
<a id="target" href="http://opentutorials.org">opentutorials</a>
<script>
var t = document.getElementById('target');
console.log(t.getAttribute('href')); //http://opentutorials.org
t.setAttribute('title', 'opentutorials.org'); // title 속성의 값을 설정한다.
console.log(t.hasAttribute('title')); // true, title 속성의 존재여부를 확인한다.
t.removeAttribute('title'); // title 속성을 제거한다.
console.log(t.hasAttribute('title')); // false, title 속성의 존재여부를 확인한다.
</script>
```

- 속성과 프로퍼티

모든 엘리먼트의 (HTML)속성은 (JavaScript 객체의) 속성과 프로퍼티로 제어가 가능하다.  
예제를 보자.

```
<p id="target">
    Hello world
</p>
<script>
    var target = document.getElementById('target');
    // attribute 방식
    target.setAttribute('class', 'important');
    // property 방식
    target.className = 'important';
</script>
```

`setAttribute('class', 'important')와 className = 'important'`는 같은 결과를 만든다.  
하지만 전자는 attribute 방식(속성이라고 부르겠다)이고 후자는 property 방식이다.  
property 방식은 좀 더 간편하고 속도도 빠르지만  
실제 html 속성의 이름과 다른 이름을 갖는 경우가 있다.  
그것은 자바스크립트의 이름 규칙 때문이다.

| class       | className   |
| ----------- | ----------- |
| readonly    | readOnly    |
| rowspan     | rowSpan     |
| colspan     | colSpan     |
| usemap      | userMap     |
| frameborder | frameBorder |
| for         | htmlFor     |
| maxlength   | maxLength   |

심지어 속성과 프로퍼티는 값이 다를수도 있다.  
아래 코드를 실행한 결과는 속성과 프로퍼티의 값이 꼭 같은 것은 아니라는 것을 보여준다.

```
<a id="target" href="./demo1.html">ot</a>
<script>
//현재 웹페이지가 http://localhost/webjs/Element/attribute_api/demo3.html 일 때
var target = document.getElementById('target');
// http://localhost/webjs/Element/attribute_api/demo1.html
console.log('target.href', target.href);
// ./demo1.html
console.log('target.getAttribute("href")', target.getAttribute("href"));
</script>
```

# Node 객체

Node 객체는 DOM에서 시조와 같은 역할을 한다.  
다시 말해서 모든 DOM 객체는 Node 객체를 상속 받는다.

## 주요기능

Node 객체의 주요한 임무는 아래와 같다.

- 관계

  엘리먼트는 서로 부모, 자식, 혹은 형제자매 관계로 연결되어 있다.  
   각각의 Node가 다른 Node와 연결된 정보를 보여주는 API를 통해서 문서를 프로그래밍적으로 탐색할 수 있다.

  - Node.childNodes
  - Node.firstChild
  - Node.lastChild
  - Node.nextSibling
  - Node.previousSibling
  - Node.contains()
  - Node.hasChildNodes()

- 노드의 종류

  Node 객체는 모든 구성요소를 대표하는 객체이기 때문에  
   각각의 구성요소가 어떤 카테고리에 속하는 것인지를 알려주는 식별자를 제공한다.

  - Node.nodeType
  - Node.nodeName

- 값

  Node 객체의 값을 제공하는 API

  - Node.nodeValue
  - Node.textContent

- 자식관리

  Node 객체의 자식을 추가하는 방법에 대한 API

  - Node.appendChild()
  - Node.removeChild()

## Node 관계 API

Node 객체는 Node 간의 관계 정보를 담고 있는 일련의 API를 가지고 있다.  
다음은 관계와 관련된 프로퍼티들이다.

- Node.childNodes  
  자식노드들을 유사배열에 담아서 리턴한다.
- Node.firstChild  
  첫번째 자식노드
- Node.lastChild  
  마지막 자식노드
- Node.nextSibling  
  다음 형제 노드
- Node.previousSibling  
  이전 형제 노드

아래는 위의 API를 이용해서 문서를 탐색하는 모습을 보여준다.

```js
<body id="start">
  <ul>
    <li>
      <a href="./532">html</a>
    </li>
    <li>
      <a href="./533">css</a>
    </li>
    <li>
      <a href="./534">JavaScript</a>
      <ul>
        <li>
          <a href="./535">JavaScript Core</a>
        </li>
        <li>
          <a href="./536">DOM</a>
        </li>
        <li>
          <a href="./537">BOM</a>
        </li>
      </ul>
    </li>
  </ul>
  <script>
    var s = document.getElementById('start'); console.log(1, s.firstChild); //
    #text var ul = s.firstChild.nextSibling console.log(2, ul); // ul
    console.log(3, ul.nextSibling); // #text console.log(4,
    ul.nextSibling.nextSibling); // script console.log(5, ul.childNodes);
    //text, li, text, li, text, li, text console.log(6, ul.childNodes[1]); //
    li(html) console.log(7, ul.parentNode); // body
  </script>
</body>
```

## Node 종류 API

노드 작업을 하게 되면 현재 선택된 노드가 어떤 타입인지를 판단해야 하는 경우가 있다.  
이런 경우에 사용할 수 있는 API가 nodeType, nodeName이다.

- Node.nodeType  
  node의 타입을 의미한다.
- Node.nodeName  
  node의 이름 (태그명을 의미한다.)

### Node Type

노드의 종류에 따라서 정해진 상수가 존재한다.  
 아래는 모든 노드의 종류와 종류에 따른 값을 출력하는 예제다.

```js
for (var name in Node) {
  console.log(name, Node[name]);
}
```

결과

```
ELEMENT_NODE 1
ATTRIBUTE_NODE 2
TEXT_NODE 3
CDATA_SECTION_NODE 4
ENTITY_REFERENCE_NODE 5
ENTITY_NODE 6
PROCESSING_INSTRUCTION_NODE 7
COMMENT_NODE 8
DOCUMENT_NODE 9
DOCUMENT_TYPE_NODE 10
DOCUMENT_FRAGMENT_NODE 11
NOTATION_NODE 12
DOCUMENT_POSITION_DISCONNECTED 1
DOCUMENT_POSITION_PRECEDING 2
DOCUMENT_POSITION_FOLLOWING 4
DOCUMENT_POSITION_CONTAINS 8
DOCUMENT_POSITION_CONTAINED_BY 16
DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC 32
```

아래 예제는 노드 종류 API를 이용해서 노드를 처리하는 예제다.  
함수가 자기 자신을 호출하는 것을 재귀함수라고 하는데 본 예제는 재귀 함수의 예를 보여준다.

```js
<!DOCTYPE html>
<html>
<body id="start">
<ul>
    <li><a href="./532">html</a></li>
    <li><a href="./533">css</a></li>
    <li><a href="./534">JavaScript</a>
        <ul>
            <li><a href="./535">JavaScript Core</a></li>
            <li><a href="./536">DOM</a></li>
            <li><a href="./537">BOM</a></li>
        </ul>
    </li>
</ul>
<script>
function traverse(target, callback){
    if(target.nodeType === 1){
        //if(target.nodeName === 'A')
        callback(target);
        var c = target.childNodes;
        for(var i=0; i<c.length; i++){
            traverse(c[i], callback);
        }
    }
}
traverse(document.getElementById('start'), function(elem){
    console.log(elem);
});
</script>
</body>
</html>
```

## Node 변경 API

노드를 추가, 제거, 변경하는 방법을 알아보자.

### 노드 추가

노드의 추가와 관련된 API들은 아래와 같다.

- appendChild(child)  
  노드의 마지막 자식으로 주어진 엘리먼트 추가
- insertBefore(newElement, referenceElement)  
  appendChild와 동작방법은 같으나 두번째 인자로 엘리먼트를 전달 했을 때 이것 앞에 엘리먼트가 추가된다.

노드를 추가하기 위해서는 추가할 엘리먼트를 생성해야 하는데 이것은 document 객체의 기능이다.  
아래 API는 노드를 생성하는 API이다.

- document.createElement(tagname)  
   엘리먼트 노드를 추가한다.
- document.createTextNode(data)  
   텍스트 노드를 추가한다.

```js
<ul id="target">
    <li>HTML</li>
    <li>CSS</li>
</ul>
<input type="button" onclick="callAppendChild();" value="appendChild()" />
<input type="button" onclick="callInsertBefore();" value="insertBefore()" />
<script>
    function callAppendChild(){
        var target = document.getElementById('target');
        var li = document.createElement('li');
        var text = document.createTextNode('JavaScript');
        li.appendChild(text);
        target.appendChild(li);
    }

    function callInsertBefore(){
        var target = document.getElementById('target');
        var li = document.createElement('li');
        var text = document.createTextNode('jQuery');
        li.appendChild(text);
        target.insertBefore(li, target.firstChild);
    }
</script>
```

### 노드 제거

노드 제거를 위해서는 아래 API를 사용한다.  
이 때 메소드는 삭제 대상의 부모 노드 객체의 것을 실행해야 한다는 점에 유의하자.

- removeChild(child)
  ```js
  <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li id="target">JavaScript</li>
  </ul>
  <input type="button" onclick="callRemoveChild();" value="removeChild()" />
  <script>
      function callRemoveChild(){
          var target = document.getElementById('target');
          target.parentNode.removeChild(target);
      }
  </script>
  ```

### 노드 바꾸기

노드 바꾸기에는 아래 API가 사용된다.

- replaceChild(newChild, oldChild)

  ```js
  <ul>
      <li>HTML</li>
      <li>CSS</li>
      <li id="target">JavaScript</li>
  </ul>
  <input type="button" onclick="callReplaceChild();" value="replaceChild()" />
  <script>
      function callReplaceChild(){
          var a = document.createElement('a');
          a.setAttribute('href', 'http://opentutorials.org/module/904/6701');
          a.appendChild(document.createTextNode('Web browser JavaScript'));

          var target = document.getElementById('target');
          target.replaceChild(a,target.firstChild);
      }
  </script>
  ```

## 문자열로 노드 제어

노드 변경 API에서는 여러 메소드를 이용해서 노드를 제어하는 방법에 대해서 알아봤다. 그런데 이 방식은 복잡하고 장황하다. 좀 더 편리하게 노드를 조작하는 방법을 알아보자.

### innerHTML

innerHTML는 문자열로 자식 노드를 만들 수 있는 기능을 제공한다. 또한 자식 노드의 값을 읽어올 수도 있다.

```js
<ul id="target">
    <li>HTML</li>
    <li>CSS</li>
</ul>
<input type="button" onclick="get();" value="get" />
<input type="button" onclick="set();" value="set" />
<script>
    function get(){
        var target = document.getElementById('target');
        alert(target.innerHTML);
    }
    function set(){
        var target = document.getElementById('target');
        target.innerHTML = "<li>JavaScript Core</li><li>BOM</li><li>DOM</li>";
    }
</script>
```

### outerHTML

outerHTML은 선택한 엘리먼트를 포함해서 처리된다.

```js
<ul id="target">
    <li>HTML</li>
    <li>CSS</li>
</ul>
<input type="button" onclick="get();" value="get" />
<input type="button" onclick="set();" value="set" />
<script>
    function get(){
        var target = document.getElementById('target');
        alert(target.outerHTML);
    }
    function set(){
        var target = document.getElementById('target');
        target.outerHTML = "<ol><li>JavaScript Core</li><li>BOM</li><li>DOM</li></ol>";
    }
</script>
```

### innerText, outerText

innerHtml, outerHTML과 다르게 이 API들은 값을 읽을 때는 HTML 코드를 제외한 문자열을 리턴하고,  
값을 변경할 때는 HTML의 코드를 그대로 추가한다.

```js
<ul id="target">
    <li>HTML</li>
    <li>CSS</li>
</ul>
<input type="button" onclick="get();" value="get" />
<input type="button" onclick="set();" value="set" />
<script>
    function get(){
        var target = document.getElementById('target');
        alert(target.innerText);
    }
    function set(){
        var target = document.getElementById('target');
        target.innerText = "<li>JavaScript Core</li><li>BOM</li><li>DOM</li>";
    }
</script>
```

### insertAdjacentHTML()

좀 더 정교하게 문자열을 이용해서 노드를 변경하고 싶을 때 사용한다.

```js
<ul id="target">
    <li>CSS</li>
</ul>
<input type="button" onclick="beforebegin();" value="beforebegin" />
<input type="button" onclick="afterbegin();" value="afterbegin" />
<input type="button" onclick="beforeend();" value="beforeend" />
<input type="button" onclick="afterend();" value="afterend" />
<script>
    function beforebegin(){
        var target = document.getElementById('target');
        target.insertAdjacentHTML('beforebegin','<h1>Client Side</h1>');
    }
    function afterbegin(){
        var target = document.getElementById('target');
        target.insertAdjacentHTML('afterbegin','<li>HTML</li>');
    }
    function beforeend(){
        var target = document.getElementById('target');
        target.insertAdjacentHTML('beforeend','<li>JavaScript</li>');
    }
    function afterend(){
        var target = document.getElementById('target');
        target.insertAdjacentHTML('afterend','<h1>Server Side</h1>');
    }
</script>
```

# Document 객체

Document 객체는 DOM의 스펙이고 이것이 웹브라우저에서는 HTMLDocument 객체로 사용된다.  
HTMLDocument 객체는 문서 전체를 대표하는 객체라고 할 수 있다.  
아래 코드는 이를 보여준다.

```js
<script>
  //document 객체는 window 객체의 소속이다. console.log(window.document);
  //document 객체의 자식으로는 Doctype과 html이 있다.
  console.log(window.document.childNodes[0]);
  console.log(window.document.childNodes[1]);
</script>
```

## 주요 API

### 노드 생성 API

document 객체의 주요 임무는 새로운 노드를 생성해주는 역할이다.  
이에 대한 내용은 노드 변경 API에서 학습했기 때문에 여기서는 언급하지 않는다.

- createElement()
- createTextNode()

### 문서 정보 API

- title
- URL
- referrer
- lastModified

# TEXT 객체

텍스트 객체는 텍스트 노드에 대한 DOM 객체로 CharcterData를 상속 받는다.  
아래는 텍스트 노드를 찾는 예제다.  
주목할 것은 DOM에서는 공백이나 줄바꿈도 텍스트 노드라는 점이다.

```js
<p id="target1"><span>Hello world</span></p>
<p id="target2">
    <span>Hello world</span>
</p>
<script>
var t1 = document.getElementById('target1').firstChild;
var t2 = document.getElementById('target2').firstChild;

console.log(t1.firstChild.nodeValue);
try{
    console.log(t2.firstChild.nodeValue);
} catch(e){
    console.log(e);
}
console.log(t2.nextSibling.firstChild.nodeValue);

</script>
```

실행결과

```
Hello world
TypeError {stack: (...), message: "Cannot read property 'nodeValue' of null"}
Hello world
```

## 주요기능

### 값

텍스트 노드의 값을 가져오는 API

- data
- nodeValue

### 조작

- appendData()
- deleteData()
- insertData()
- replaceData()
- subStringData()

### 생성

- docuemnt.createTextNode()

## 값 API

텍스트 노드는 DOM에서 실질적인 데이터가 저장되는 객체이다.  
따라서 텍스트 노드에는 값과 관련된 여러 기능들이 있는데 이번 시간에는 값을 가져오는 두개의 API를 알아본다.

- nodeValue
- data

```js
<ul>
    <li id="target">html</li>
    <li>css</li>
    <li>JavaScript</li>
</ul>
<script>
    var t = document.getElementById('target').firstChild;
    console.log(t.nodeValue);
    console.log(t.data);
</script>
```

## 조작 API

텍스트 노드가 상속 받은 CharacterData 객체는 문자를 제어할 수 있는 다양한 API를 제공한다.  
아래는 조작과 관련된 API들의 목록이다.

- appendData()
- deleteData()
- insertData()
- replaceData()
- substringData()

```js
<!DOCTYPE html>
<html>
<head>
    <style>
    #target{
        font-size:77px;
        font-family: georgia;
        border-bottom:1px solid black;
        padding-bottom:10px;
    }
    p{
        margin:5px;
    }
    </style>
</head>
<body>
<p id="target">Cording everybody!</p>
<p> data : <input type="text" id="datasource" value="JavaScript" /></p>
<p>   start :<input type="text" id="start" value="5" /></p>
<p> end : <input type="text" id="end" value="5" /></p>
<p><input type="button" value="appendData(data)" onclick="callAppendData()" />
<input type="button" value="deleteData(start,end)" onclick="callDeleteData()" />
<input type="button" value="insertData(start,data)" onclick="callInsertData()" />
<input type="button" value="replaceData(start,end,data)" onclick="callReplaceData()" />
<input type="button" value="substringData(start,end)" onclick="callSubstringData()" /></p>
<script>
    var target = document.getElementById('target').firstChild;
    var data = document.getElementById('datasource');
    var start = document.getElementById('start');
    var end = document.getElementById('end');
    function callAppendData(){
        target.appendData(data.value);
    }
    function callDeleteData(){
        target.deleteData(start.value, end.value);
    }
    function callInsertData(){
        target.insertData(start.value, data.value);
    }
    function callReplaceData(){
        target.replaceData(start.value, end.value, data.value);
    }
    function callSubstringData(){
        alert(target.substringData(start.value, end.value));
    }
</script>
</body>
</html>
```

# 이벤트

이벤트(event)는 어떤 사건을 의미한다. 브라우저에서의 사건이란 사용자가 클릭을 했을 '때',  
스크롤을 했을 '때', 필드의 내용을 바꾸었을 '때'와 같은 것을 의미한다.

```js
<!DOCTYPE html>
<html>
<body>
    <input type="button" onclick="alert(window.location)" value="alert(window.href)" />
    <input type="button" onclick="window.open('bom.html')" value="window.open('bom.html')" />
</body>
</html>
```

onclick 속성의 자바스크립트 코드(alert(window.location))는  
사용자가 이 버튼을 클릭 했을 '때' 실행된다.  
즉 js 개발자는 어떤 일이 발생했을 때 실행 되어야 하는 코드를 등록하고,  
브라우저는 그 일이 발생했을 때 등록된 코드를 실행하게 된다.  
이러한 방식을 이벤트 프로그래밍이라고 한다.

### event target

target은 이벤트가 일어날 객체를 의미한다. 아래 코드에서 타겟은 버튼 태그에 대한 객체가 된다.

```
<input type="button" onclick="alert(window.location)" value="alert(window.href)" />
```

### event type

이벤트의 종류를 의미한다. 위의 예제에서는 click이 이벤트 타입이다.  
그 외에도 scroll은 사용자가 스크롤을 움직였다는 이벤트이고,  
mousemove는 마우스가 움직였을 때 발생하는 이벤트이다.

이벤트의 종류는 이미 약속되어 있다.  
아래 링크는 브라우저에서 지원하는 이벤트의 종류를 보여준다.

https://developer.mozilla.org/en-US/docs/Web/Reference/Events

### event handler

이벤트가 발생했을 때 동작하는 코드를 의미한다.  
위의 예제에서는 alert(window.location)이 여기에 해당한다.

## inline

인라인(inline) 방식으로 이벤트를 등록하는 방법을 알아보자.  
인라인 방식은 이벤트를 이벤트 대상의 태그 속성으로 지정하는 것이다.  
다음은 버튼을 클릭했을 때 Hello world를 경고창으로 출력한다.

```js
<input type="button" onclick="alert('Hello world');" value="button" />
```

이벤트가 발생한 대상을 필요로하는 경우 this를 통해서 참조할 수 있다.

```js
<!--자기 자신을 참조하는 불편한 방법-->
<input type="button" id="target" onclick="alert('Hello world, '+document.getElementById('target').value);" value="button" />
<!--this를 통해서 간편하게 참조할 수 있다-->
<input type="button" onclick="alert('Hello world, '+this.value);" value="button" />
```

인라인 방식은 태그에 이벤트가 포함되기 때문에 이벤트의 소재를 파악하는 것이 편리하다.  
하지만 정보인 HTML과 제어인 JavaScript가 **혼재된 형태**이기 때문에  
바람직한 방법이라고 할수는 없다.

## 프로퍼티 리스너

프로퍼티 리스너 방식은 이벤트 대상에 해당하는 객체의 프로퍼티로 이벤트를 등록하는 방식이다. 인라인 방식에 비해서 HTML과 JavaScript를 분리할 수 있다는 점에서 선호되는 방식이지만  
뒤에서 배울 addEventListener 방식을 추천한다.

```js
<input type="button" id="target" value="button" />
<script>
    var t = document.getElementById('target');
    t.onclick = function(){
        alert('Hello world');
    }
</script>
```

### 이벤트 객체

이벤트가 실행된 맥락의 정보가 필요할 때는 이벤트 객체를 사용한다.  
이벤트 객체는 이벤트가 실행될 때 이벤트 핸들러의 인자로 전달된다.

```js
<body>
    <input type="button" id="target" value="button" />
<script>
    var t = document.getElementById('target');
    t.onclick = function(event){
        alert('Hello world, '+event.target.value)
    }
</script>
```

## addEventListner()

addEventListener은 이벤트를 등록하는 가장 권장되는 방식이다.  
이 방식을 이용하면 여러개의 이벤트 핸들러를 등록할 수 있다.

```js
<input type="button" id="target" value="button" />
<script>
    var t = document.getElementById('target');
    t.addEventListener('click', function(event){
        alert('Hello world, '+event.target.value);
    });
</script>
```

이 방식의 중요한 장점은 하나의 이벤트 대상에 복수의 동일 이벤트 타입 리스너를  
등록할 수 있다는 점이다.

```js
<input type="button" id="target" value="button" />
<script>
    var t = document.getElementById('target');
    t.addEventListener('click', function(event){
        alert(1);
    });
    t.addEventListener('click', function(event){
        alert(2);
    });
</script>
```

이벤트 객체를 이용하면 복수의 엘리먼트에 하나의 리스너를 등록해서 재사용할 수 있다.

```js
<input type="button" id="target1" value="button1" />
<input type="button" id="target2" value="button2" />
<script>
    var t1 = document.getElementById('target1');
    var t2 = document.getElementById('target2');
    function btn_listener(event){
        switch(event.target.id){
            case 'target1':
                alert(1);
                break;
            case 'target2':
                alert(2);
                break;
        }
    }
    t1.addEventListener('click', btn_listener);
    t2.addEventListener('click', btn_listener);
</script>
```

## 이벤트 전파

HTML 태그는 중첩되어 있다.  
따라서 특정한 태그에서 발생하는 이벤트는 중첩되어 있는 태그들 모두가 대상이 될 수 있다.  
이런 경우 중첩된 태그들에 이벤트가 등록 되어 있다면 어떻게 처리 될까?

```js
<html>
    <head>
        <style>
            html{border:5px solid red;padding:30px;}
            body{border:5px solid green;padding:30px;}
            fieldset{border:5px solid blue;padding:30px;}
            input{border:5px solid black;padding:30px;}
        </style>
    </head>
    <body>
        <fieldset>
            <legend>event propagation</legend>
            <input type="button" id="target" value="target">
        </fieldset>
        <script>
        function handler(event){
            var phases = ['capturing', 'target', 'bubbling']
            console.log(event.target.nodeName, this.nodeName, phases[event.eventPhase-1]);
        }
        document.getElementById('target').addEventListener('click', handler, true);
        document.querySelector('fieldset').addEventListener('click', handler, true);
        document.querySelector('body').addEventListener('click', handler, true);
        document.querySelector('html').addEventListener('click', handler, true);
        </script>
    </body>
</html>
```

실행결과

```
INPUT HTML capturing
INPUT BODY capturing
INPUT FIELDSET capturing
INPUT INPUT target
```

이벤트가 부모에서부터 발생해서 자식으로 전파되고 있다.  
이러한 방식을 capturing이라고 한다.

코드를 아래와 같이 변경해보자.

```js
document.getElementById("target").addEventListener("click", handler, false);
document.querySelector("fieldset").addEventListener("click", handler, false);
document.querySelector("body").addEventListener("click", handler, false);
document.querySelector("html").addEventListener("click", handler, false);
```

차이점은 addEventListener의 3번째 인자가 false로 변경 되었다.  
실행결과

```
INPUT INPUT target
INPUT FIELDSET bubbling
INPUT BODY bubbling
INPUT HTML bubbling
```

이번에는 순서가 반대로 되었다.  
자식부터 부모로 이벤트가 전파되는 것을 버블링(bubbling)이라고 한다.

이벤트 전파를 중간에 가로막을 수도 있다.

아래처럼 코드를 변경해보자.

```js
function handler(event) {
  var phases = ["capturing", "target", "bubbling"];
  console.log(
    event.target.nodeName,
    this.nodeName,
    phases[event.eventPhase - 1]
  );
}
function stophandler(event) {
  var phases = ["capturing", "target", "bubbling"];
  console.log(
    event.target.nodeName,
    this.nodeName,
    phases[event.eventPhase - 1]
  );
  event.stopPropagation();
}
document.getElementById("target").addEventListener("click", handler, false);
document.querySelector("fieldset").addEventListener("click", handler, false);
document.querySelector("body").addEventListener("click", stophandler, false);
document.querySelector("html").addEventListener("click", handler, false);
```

실행결과

```
INPUT INPUT target
INPUT FIELDSET bubbling
INPUT BODY bubbling
```

## 기본동작의 취소

웹브라우저의 구성요소들은 각각 기본적인 동작 방법을 가지고 있다.

텍스트 필드에 포커스를 준 상태에서 키보드를 입력하면 텍스트가 입력된다.  
폼에서 submit 버튼을 누르면 데이터가 전송된다.  
a 태그를 클릭하면 href 속성의 URL로 이동한다.  
이러한 기본적인 동작들을 기본 이벤트라고 하는데 사용자가 만든 이벤트를 이용해서  
이러한 기본 동작을 취소할 수 있다.

### inline

이벤트의 리턴값이 false이면 기본 동작이 취소된다.

```js
<p>
    <label>prevent event on</label><input id="prevent" type="checkbox" name="eventprevent" value="on" />
</p>
<p>
    <a href="http://opentutorials.org" onclick="if(document.getElementById('prevent').checked) return false;">opentutorials</a>
</p>
<p>
    <form action="http://opentutorials.org" onsubmit="if(document.getElementById('prevent').checked) return false;">
            <input type="submit" />
    </form>
</p>
```

### property 방식

리턴 값이 false이면 기본동작이 취소된다.

```js
<p>
    <label>prevent event on</label><input id="prevent" type="checkbox" name="eventprevent" value="on" />
</p>
<p>
    <a href="http://opentutorials.org">opentutorials</a>
</p>
<p>
    <form action="http://opentutorials.org">
            <input type="submit" />
    </form>
</p>
<script>
    document.querySelector('a').onclick = function(event){
        if(document.getElementById('prevent').checked)
            return false;
    };

    document.querySelector('form').onclick = function(event){
        if(document.getElementById('prevent').checked)
            return false;
    };

</script>
```

### addEventListener 방식

이 방식에서는 이벤트 객체의 preventDefault 메소드를 실행하면 기본 동작이 취소된다.

```js
<p>
            <label>prevent event on</label><input id="prevent" type="checkbox" name="eventprevent" value="on" />
        </p>
        <p>
            <a href="http://opentutorials.org">opentutorials</a>
        </p>
        <p>
            <form action="http://opentutorials.org">
                    <input type="submit" />
            </form>
        </p>
        <script>
            document.querySelector('a').addEventListener('click', function(event){
                if(document.getElementById('prevent').checked)
                    event.preventDefault();
            });

            document.querySelector('form').addEventListener('submit', function(event){
                if(document.getElementById('prevent').checked)
                    event.preventDefault();
            });

        </script>
```

## 이벤트 타입

아래는 onclick 이벤트 타입의 예제다. 이벤트 타입이라는 것은 이벤트의 종류라고 할 수 있다.

```js
<input type="button" onclick="alert(1);" />
```

웹브라우저는 많은 종류의 이벤트 타입을 제공한다.  
하위 토픽에서는 주요한 이벤트 타입을 중심으로 어떤 이벤트 타입이 있는지 알아보겠다.

### 폼

폼과 관련된 이벤트 타입을 알아보자.

#### submit

submit은 폼의 정보를 서버로 전송하는 명령인 submit시에 일어난다.

form 태그에 적용된다.

아래 예제는 전송 전에 텍스트 필드에 값이 입력 되었는지를 확인한다.  
만약 값이 입력되지 않았다면 전송을 중단한다.

```js
<form id="target" action="result.html">
    <label for="name">name</label> <input id="name" type="name" />
    <input type="submit" />
</form>
<script>
var t = document.getElementById('target');
t.addEventListener('submit', function(event){
    if(document.getElementById('name').value.length === 0){
        alert('Name 필드의 값이 누락 되었습니다');
        event.preventDefault();
    }
});
</script>
```

아래 구문은 전송을 취소하는 명령이다.  
이에 대해서는 기본 동작의 취소에서 자세히 알아본다.

```
event.preventDefault();
```

#### change

change는 폼 컨트롤의 값이 변경 되었을 때 발생하는 이벤트다.

input(text,radio,checkbox), textarea, select 태그에 적용된다.

```js
<p id="result"></p>
<input id="target" type="name" />
<script>
var t = document.getElementById('target');
t.addEventListener('change', function(event){
    document.getElementById('result').innerHTML=event.target.value;
});
</script>
```

#### blur, focus

focus는 엘리먼트에 포커스가 생겼을 때, blur은 포커스가 사라졌을 때 발생하는 이벤트다.

다음 태그를 제외한 모든 태그에서 발생한다.  
`<base>`, `<bdo>`, `<br>`, `<head>`, `<html>`, `<iframe>`, `<meta>`, `<param>`, `<script>`, `<style>`, `<title>`

```js
<input id="target" type="name" />
<script>
var t = document.getElementById('target');
t.addEventListener('blur', function(event){
    alert('blur');
});
t.addEventListener('focus', function(event){
    alert('focus');
});
</script>
```

### 문서 로딩

웹페이지를 프로그래밍적으로 제어하기 위해서는 웹페이지의 모든 요소에 대한 처리가 끝나야 한다.  
이것을 알려주는 이벤트가 load, DOMContentLoaded이다.

아래 코드의 실행결과는 null이다.
`<p id="target">Hello</p>`가 로딩되기 전에 자바스크립트가 실행되었기 때문이다.

```js
<html>
  <head>
    <script>var t = document.getElementById('target'); console.log(t);</script>
  </head>
  <body>
    <p id="target">Hello</p>
  </body>
</html>
```

이를 해결하기 위한 방법은 아래와 같이 스크립트를 문서 끝에 위치시키는 것이다.

```js
<p id="target">Hello</p>
<script>
    var t = document.getElementById('target');
    console.log(t);
</script>
```

또 다른 방법은 load 이벤트를 이용하는 것이다.

```js
<head>
    <script>
        window.addEventListener('load', function(){
            var t = document.getElementById('target');
            console.log(t);
        })
    </script>
</head>
<body>
    <p id="target">Hello</p>
</body>
```

그런데 load 이벤트는 문서내의 모든 리소스(이미지, 스크립트)의 다운로드가 끝난 후에 실행된다. 이것을 에플리케이션의 구동이 너무 지연되는 부작용을 초래할 수 있다.

DOMContentLoaded는 문서에서 스크립트 작업을 할 수 있을 때 실행되기 때문에  
이미지 다운로드를 기다릴 필요가 없다.

```js
<html>
    <head>
        <script>
            window.addEventListener('load', function(){
                console.log('load');
            })
            window.addEventListener('DOMContentLoaded', function(){
                console.log('DOMContentLoaded');
            })
        </script>
    </head>
    <body>
        <p id="target">Hello</p>
    </body>
</html>
```

DOMContentLoaded 이벤트는 모든 브라우저에서 지원하고 있다.

### 마우스

#### 이벤트 타입

웹브라우저는 마우스와 관련해서 다양한 이벤트 타입을 지원한다.

- click  
  클릭했을 때 발생하는 이벤트.
- dblclick  
  더블클릭을 했을 때 발생하는 이벤트
- mousedown  
  마우스를 누를 때 발생
- mouseup  
  마우스버튼을 땔 때 발생
- mousemove  
  마우스를 움직일 때
- mouseover  
  마우스가 엘리먼트에 진입할 때 발생
- mouseout  
  마우스가 엘리먼트에서 빠져나갈 때 발생
- contextmenu  
  컨텍스트 메뉴가 실행될 때 발생

#### 키보드 조합

마우스 이벤트가 호출될 때 특수키(alt, ctrl, shift)가 눌려진 상태를  
감지해야 한다면 이벤트 객체의 프로퍼티를 사용한다.  
이 때 사용하는 프로퍼티는 아래와 같다.

- event.shiftKey
- event.altKey
- event.ctrlKey

#### 마우스 포인터 위치

마우스 이벤트와 관련한 작업에서는 마우스 포인터의 위치를 알아내는 것이  
중요할 때가 있는데 이런 경우 이벤트 객체의 clientX와 clientY를 사용한다.

# 참고

[Object Model](http://learn.javascript.ru/browser-environment)
