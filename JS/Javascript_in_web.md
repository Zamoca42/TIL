# 웹브라우저에서의 자바스크립트

> JQuery부분은 나중에 배우기 위해 후순위로 미루어뒀다.

> [오픈튜토리얼 - 생활코딩](https://opentutorials.org/module/904/6682)
> 강의를 듣고 어디까지 들었는지 확인하기 위해 강의 내용을 스크랩하였습니다.

## Object Model - 객체화란 무엇인가?

웹브라우저의 구성요소들은 하나하나가 객체화되어 있다.  
자바스크립트로 이 객체를 제어해서 웹브라우저, 웹페이지를 제어할 수 있게 된다.  
이 객체들은 서로 계층적인 관계로 구조화되어 있다.  
BOM과 DOM은 이 구조를 구성하고 있는 가장 큰 틀의 분류라고 할 수 있다. 

## BOM

BOM(Browser Object Model)이란 웹브라우저의 창이나 프래임을 추상화해서  
프로그래밍적으로 제어할 수 있도록 제공하는 수단이다.  
BOM은 전역객체인 Window의 프로퍼티와 메소드들을 통해서 제어할 수 있다.  
따라서 BOM에 대한 수업은 Window 객체의 프로퍼티와 메소드의 사용법을  
배우는 것이라고 해도 과언이 아닐 것이다.   
본 토픽의 하위 수업에서는 Window 객체의 사용법을 알아볼 것이다.  

### 전역객체 Window

Window 객체는 모든 객체가 소속된 객체이고, 전역객체이면서, 창이나 프레임을 의미한다.  

### 전역객체

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

### 사용자와 커뮤니케이션 하기

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

### Location 객체

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

### 창 제어

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

## DOM

Document Object Model로 웹페이지를 자바스크립트로 제어하기 위한 객체 모델을 의미한다.  
window 객체의 document 프로퍼티를 통해서 사용할 수 있다.  
Window 객체가 창을 의미한다면 Document 객체는 윈도우에 로드된 문서를 의미한다고 할 수 있다.  
DOM의 하위 수업에서는 문서를 제어하는 방법에 대한 내용을 다룬다.  

### 제어 대상을 찾기

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

### HTMLElement

getElement* 메소드를 통해서 원하는 객체를 조회했다면 이 객체들을 대상으로   
구체적인 작업을 처리해야 한다. 이를 위해서는 획득한 객체가 무엇인지 알아야 한다.   
그래야 적절한 메소드나 프로퍼티를 사용할 수 있다.  

아래 코드는 getElement*의 리턴 값을 보여준다.   

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
이를 통해서 알 수 있는 것은 엘리먼트의 종류에 따라서 리턴되는 객체가 조금씩 다르다는 것이다.   각각의 객체의 차이점을 알아보자. 링크는 DOM의 스펙이다.  

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

### HTMLCollection

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

## Element 객체

Element 객체는 엘리먼트를 추상화한 객체다.  
HTMLElement 객체와의 관계를 이해하기 위해서는 DOM의 취지에 대한 이해가 선행되야 한다.  
DOM은 HTML만을 제어하기 위한 모델이 아니다.  
HTML이나 XML, SVG, XUL과 같이 마크업 형태의 언어를 제어하기 위한 규격이기 때문에  
Element는 마크업 언어의 일반적인 규격에 대한 속성을 정의하고 있고,  
각각의 구체적인 언어(HTML,XML,SVG)를 위한 기능은  
HTMLElement, SVGElement, XULElement와 같은 객체를 통해서 추가해서 사용하고 있다.  

### 다른 객체들과의 관계

DOM의 계층구조에서 Element 객체의 위치는 아래와 같다.

<img src="https://user-images.githubusercontent.com/96982072/154846635-3079da7a-1dfa-4a9d-a147-66eaaec1b574.png"/>

### 주요 기능

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

### 식별자 API

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

### 조회 API

조회 API는 엘리먼트를 조회하는 기능이다.  
조회 방법에 대해서는 이미 여러차례 살펴봤기 때문에 이번 시간에 알아볼 내용은  
조회 대상을 제한하는 방법에 대한 것이다.  

지금까지 document.getElementsBy* 메소드를 통해서 엘리먼트를 조회했다.  
document 객체는 문서 전체를 의미하는 엘리먼트이기 때문에  
document의 조회 메소드는 문서 전체를 대상으로 엘리먼트를 조회한다.  
Element 객체 역시도 getElementsBy* 엘리먼트를 가지고 있는데  
Element 객체의 조회 메소드는 해당 엘리먼트의 하위 엘리먼트를 대상으로 조회를 수행한다.  

### 속성 API

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

class      |className
-----------|----------
readonly   |readOnly
rowspan    |rowSpan
colspan    |colSpan
usemap     |userMap
frameborder|frameBorder
for        |htmlFor
maxlength  |maxLength

## 참고

[Object Model](http://learn.javascript.ru/browser-environment)