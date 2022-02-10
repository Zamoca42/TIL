HTML / CSS

# 2.0~3

폴더명, 파일명은 항상 소문자로 한다

브라우저는 HTML 파일에 에러가 있다고 알려주지 않는다
브라우저는 늘 컨텐츠를 보여주는 역할

HTML는 브라우저에게 이 것이 뭔지 알려주는 역할
HTML 태그

```html
예시 <food>김치</food>
<open tag> content </close tag>

<h1>Hello this is my website!</h1>
```

태그를 닫지 않으면 끝나지 않고 지속되는 상태
열린 순서대로 닫아줘야함

```html
<ul></ul>
unordered list 순서가 없는 리스트
<ul>
  <li>beer</li>
  <li>김치</li>
  <li>meat</li>
  <li>milk</li>
</ul>
```

# 2.4

```html
<ol></ol>
```
ordered list 순서가 있는 리스트
a = anchor를 뜻함 (link를 떠올리면 됨) (추가적인 정보가 필요함)  
attributes = 태그에 추가하는 정보 

```html
<tag attributes="value"></tag>  
```

href = http reference라고 함 (anchor 태그에만 추가 가능)  
target = 기본값은 _self이고, _blank 입력 시 새 탭에서 링크가 열림  
img = 다른 태그와 다르게 /로 닫는 태그가 없다 (자체 닫기 태그이기 때문)  
이미지는 텍스트가 아니기 때문에 자체 닫기 태그를 씀 

```html
<img></img> X 
<img /> O slef-closing tag
 
src = img 안에 사진을 집어넣음 (img에서 작동)
<img src="" /> 이미지 넣기
```

# 2.5

같은 폴더에 이미지가 있을 경우 이미지 이름.jpg
다른 경로일 경우 path/img.jpg
모든 HTML 문서는

```html
 <!DOCTYPE html> 로 시작
 ```

HTML 문서는 HEAD와 BODY로 이루어짐
HEAD - 웹사이트의 환경 설정, 외부적으로 보여지지 않음
BODY - 사용자가 볼 수 있는 content로 구성됨
브라우저 화면상에 보여질 내용들은 body에 있어야 함.
title - 제목 설정 Head 태그 안에 들어감

```html
<html>
  <head>
    <title>Home - My first website.</title>
  </head>
  <body>
    <h1>Hello!</h1>
    <a href="https://google.com">Go to google.com</a>
    <img
      src="https://a.cdn-hotels.com/gdcs/production101/d154/ee893f00-c31d-11e8-9739-0242ac110006.jpg?impolicy=fcrop&w=800&h=533&q=medium"
    />
  </body>
</html>
```

# 2.6

head에 들어가는 다른 태그들  
meta tag = 부가적인 요소 라는 뜻, 표현할 수 없는 다양한 종류의 메타데이터를 내보냄  
(content, name attribute를 가짐)  
charset = 한글 등 문자 표시하게 해줌  
language = 사이트에 사용되는 언어 표기 (검색엔진에게 알려줌)  
다른 수많은 meta tag들이 있음  
HEAD 태그는 보이지 않는 사이트 설정들을 바꿔준다!! (중요)  
og태그(open graph)는 프런트엔드를 이 과정보다 심화적으로 공부하시면 아실테지만,  
콘텐츠의 요약내용이 SNS에 게시되는데 최적화된   데이터로 가지고 갈 수 있도록 설정하는 것 정도로 아시면 이해가 편할 것 같습니다.  

# 2.7

https://developer.mozilla.org/ko/docs/Learn/Forms

VSC 간편 단축키

7. 반복되는 단어 한방에 수정  
   ⌘ + D or Ctrl + D(한번씩 일일이 눌러줘야함 / 귀찮으면 Ctrl + F2)

8. 클릭하는 곳마다 커서 생성  
   ⌥ + Click or Alt + Click

9. 코드 위/아래로 움직이기  
   ⌥ + ↑ / ↓ or Alt + ↑ / ↓

10. 코드 복사해서 위/아래로 움직이기  
    ⌥ + ⇧ + ↑ / ↓ or Alt + ⇧ + ↑ / ↓

11. 코드 블록 한방에 코멘트 처리하기  
    ⌘ + / or Ctrl + /

12. 선택된 영역에 커서 만들기  
    ⌥ + ⇧ + i or Alt + ⇧ + i

13. 마우스가 가는 곳 마다 커서 만들기  
    ⌥ + ⇧ + Mouse Drag or Alt + ⇧ + Mouse Drag

Bonus:
파일 맨 위-아래로 한번에 이동하기  
Top / Bottom of File: ⌘ + ↑ / ↓ or Ctrl + Home / End

사이드바 숨기기  
Hide / Show Sidebar: ⌘ + B or Ctrl + B

+[Ctrl + Shift + Enter]  
커서가 있는 줄부터 그 아래의 줄들을 아래로 내리기

+Alt + ←/→  
커서가 이전에 위치한 곳으로 되돌아가는 기능이고 알트 오른쪽은 그 반대 효과

# 2.8 form 태그

```hmtl
<input placeholder="Name" type="text" />
<input placeholder="Last Name" type="text" />
<input placeholder="Username" type="text" />
<input placeholder="password" type="password" />
<input type="submit" value="Create Account" />
```

required이라는 원하지 않는 값을 거부하는  
attribute를 통해서 간편하게 validate 할 수 있다  
모든 html태그와 속성을 기억할 필요없다 사용방법과 규칙만 알면 된다.  

# 2.9

label 태그는 input과 함께 작동한다.  
label에는 for을 input에는 id를 같은 값을 적으면 연결가능하다.  
for 과 id는 attribute처럼 작성한다.  
id는 고유식별자로 태그당 하나의 id만 가질 수 있는게 규칙이다.  
하지만 id를 여러 곳에 입력했다고 해서 에러는 뜨지 않는다.  
다만 이상하게 작동한다.  
CSS와 HTML을 연결할 수 있는 것은 id가 있기 때문이다.  

```html
<label for="Profile">Profile Photo</label>
<input id="Profile" type="file" accept=".pdf" />
```

# 2.10

div태그는 division 구분을 말한다  
문서를 보기만해도 그 의미를 짐작할 수 있는걸 Semantic  
header, main, footer 는 div를 대체할 수 있다.  
하지만 div는 구분만 될 뿐 무엇을 의미하는지는 알 수 없다.  
header는 머리(위), main은 몸(중간), footer 다리(아래)에 온다는 것을 이해할 수 있다.  
이것을 semantic 태그라고 부른다  
HTML 문서에 content sectioning에 해당하는 태그들이 Semantic 태그들이다.  

```html
<div>
  <label for="website">Website</label>
  <input id="website" required placeholder="Name" type="email" />
</div>
```

# 3.0

CSS와 HTML을 같은 파일에 두는 것을 이해  

style태그를 작성하면 HTML파일에 CSS코드를 작성  
CSS는 뭔가를 가리킨다 (pointer)  
link 태그를 통해서 css파일과 연결하고 rel을 통해 관계를 적어주면  
보기 좋고 더 많은 HTML태그 작성 가능  
  
```html
<link href="styles.css" rel="stylesheet" />  
```

# 3.1

```html
<style>
  h1 {
    color: blue;
    text-decoration: underline;
    font-size: 20px;
  }
</style>
```

h1태그와 연결된 색상과 글자크기가 바뀐다.

```html
<style>
  tagname {
    property: value;
  }
</style>
```

처럼 나타낼 수 있다. 속성 이름에는 밑줄(\_) 또는 슬래쉬(/)를 사용할 수는 없다.

# 3.2

CSS(Cascading Style Sheet)인 이유는 브라우저가 CSS코드를 읽을 때  
위에서부터 아래로 읽어 내려간다.  
스타일 태그를 이용해서 속성을 써주는 것을 inline CSS라 하고  
CSS 파일을 include하는 걸 external CSS라고 한다  
같은 태그에 있는 스타일을 적용시키면 CSS가 위에서 아래로 적용 시켜나가다가  
맨 아래에서 만난 스타일을 최종적으로 적용시킨다.  

```html
<style>
  h1 {
    color: yellowgreen;
  }
  h1 {
    color: red;
  }
  h1 {
    color: tomato;
  }
</style>
```

이렇게 스타일을 적용하면 결국에는 최종 변경된 tomato로 적용한다.

# 3.3

box옆에 또 다른 box는 오지 않는다. 옆에 다른 요소가 못 오는 것을 block이라 부르고  
link, img, span, code, a같이 다른 요소가 올 수 있는 것을 inline으로 부른다.  
inline의 종류는 많지않고 대부분 block에 해당한다.  

# 3.4

block과 inline은 display 속성으로 inline과 block 서로 바꿀 수 있다.  
어떤 요소가 inline 이면, 높이와 너비를 가질 수 없다.  
block는 높이와 너비가 있다.  
block의 특징 margin, padding, border  
브라우저는 기본적으로 style 속성을 준다.  
margin - 경계의 바깥에 있는 공간 (여백)  
border - 경계  

```html
body { margin-left: 0px; margin-right: 5px; margin-top: 0px; margin-bottom:
10px; background-color: thistle; }
```

이렇게 margin은 위, 아래, 오른쪽, 왼쪽 나눠서 설정 해줄 수 있다  

# 3.5

```html
<style>
  body {
    margin: 50px 0px;
    background-color: thistle;
  }
</style>
```

방향을 넣지않고 margin만 사용한다면 첫번째는 상하값 두번째는 좌우값이다.
만약 값을 4개로 나눈다면

```html
<style>
  body {
    margin: 20px 50px 12px 9px;
  }
</style>
```

시계방향으로 위 오른쪽 아래 왼쪽 순이다.  
상하에서는 margin을 사용할 경우 Collapsing margins 현상이 발생한다  
div와 body가 경계가 만날 때 body와 div의 경계가 하나로 취급된다.  

# 3.6   

padding에 관해서 배워보자  
padding은 margin과 반대 개념  
padding도 공간인데 box의 경계로부터 '안쪽'에 있는 공간  
```html
<div id = "first"></div>
```
div를 사용해서 경계를 나눌 때 경계를 명확하게 알아보기 위해 id를 사용한다.  
CSS에 적용시키려면 style 태그안에 #id를 사용하면 id별로 스타일을 적용할 수 있다. 
```html
<style>
            body {
                margin: 20px;     
                padding:20px;           
                background-color: thistle;
            }
            html {
                background-color: tomato;
            }
            div {
                height: 150px;
                width: 150px;
            }
            #first {
               background-color: whitesmoke;
                height: 150px;
                width: 150px;
              }    
</style>      
```
element에는 하나의 id만 적용할 수 있다.

# 3.7
border스타일은 여러가지가 있지만, 대부분 한 가지만 사용한다.
```html
border: 2px solid black;
```
스타일 태그에서 '*' 태그를 사용하면 모든 태그에 스타일이 적용 된다.
```html
<style>
  * {
    border: 2px solid black;
  }
</style>
```

# 3.8  

padding은 span에 적용 된다.  
margin은 inline 속성이므로(높이와 너비가 없다) 좌, 우에만 적용된다.  
class는 여러개의 속성들이 공용으로 사용할 수 있는 스타일 형식이고,  
여러 개의 속성에 같은 스타일을 적용하고 싶을 때 사용한다.  
class는 .속성 으로 사용한다.  
class는 여러 개를 가질 수 있다.  
```html
<style>
  #tomato = id="tomato"
  .tomato = class="tomato hello honey"
</style>
```

# 3.9

inline을 통해 box들을 옆으로 나열할 수 있지만  
inline은 반응형 디자인을 지원하지 않기 때문에  
모니터마다 보이는 형태가 다르다. 따라서 여백이나 간격을 원하는대로 맞출 수 없다.

# 3.10

inline의 단점을 보완하려고 만든 것이 flexbox?  
flexbox는 box를 원하는 곳에 둘 수 있고, 유연하게 사용 가능하다.  
2차원 레이아웃에서 아주 잘 작동한다.  
flexbox를 사용하는 것은 쉽지만, 사용할 때 지켜야할 규칙들이 정말 중요하다.  
1. 자식 엘리먼트에는 어떤 것도 적지 않아야하고, 부모 엘리먼트에만 적는다.  
  자식 엘리먼트를 움직이게 하려면 부모 엘리먼트를 flex로 만들고
  부모 엘리먼트에 형식을 적는다.
```html
<style>           
   body {
      margin: 20px;         
      display: flex;           
        }            
    div {
      display: inline-block;
      width: 50px;
      height: 50px;
      background-color: teal;
       }
</style>
```
2. flexbox는 주축과 교차축 모두 적용 된다.  
  주축은 기본적으로 수평축이다. justify-content로 좌우 정렬을 설정하고,  
  창을 좌우로 조절했을 때 알아서 크기조절하기 때문에 수평축만 반응할 것 같지만  
  주축이 수직으로 적용될 수 있도록 바꿀 수 있기 때문에 수평축만 반응한다고 하지 않고  
  주축이라고 부른다. align-items로 설정하면 교차축으로 반응하도록 설정할 수 있다.  

# 3.11

flex-direction을 통해 주축을 변경할 수 있다.  
flex-direction을 column으로 설정하면 주축은 수직이되고  
교차축은 수평이 된다.  
그렇게 되면 수평이 주축이었던 justify-content가 주축이 수직으로 바뀐다. 
자식이었던 엘리먼트에 flex를 설정하면  
자식 엘리먼트는 부모가 되고 그 안의 content들이 자식이 되어 작동한다.  
  
flex에 대한 개념을 쉽게 배우는 링크 https://flexboxfroggy.com/#ko  

# 3.12

position fixed를 이용하면 스크롤해도 항상 제자리에 머무른다.
처음 만들어진 자리에 고정 되어있다. 하지만 top, left, right, bottom 중 하나만 수정해도 서로 다른 레이어에 위치하게되어 원래 위치가 무시된다.
positon fixed를 이용하면 가장 위에 위치하게 된다. (맨 앞)

# 3.13

1. positon: static (default)
2. position: fixed
  - element가 처음 생성된 자리에 고정.
3. position: relative;
  - element가 '처음 생성된 위치'를 기준점으로, top bottom left right으로 위치를 조금씩 수정할 수 있다.
4. position: absolute;
  - 가장 가까운 relative 부모를 기준으로 이동 position:relative;를 해주면 부모가 된다.  
    없으면 body를 기준으로 움직인다.

# 3.14

pseudo selector  
좀더 세부적으로 엘리먼트를 선택해 주는 것!  
(기존 방법 : 태그, id w/#, class w/.)  

선택의 복잡한 과정을 pseudo selector로 가능함  

```html
div:first-child {  
background-color: tomato;  
}  

/* pseudo selector */
div:last-child {
background-color: teal;
}
```
id나 class를 따로 만드는것보다 이렇게 지정하는게 훨씬 좋은 방법이다.  
css에서만 선택을 하면 되니까! html코드를 고칠 필요가 없기 때문이다  

n번째 태그 수정하기 nth-child(n)
```html
span:nth-child(2) {
background-color: teal;
}
span:nth-child(even) { //or odd ( 홀수 )
background-color: teal;
}
```
even은 짝수! 짝수번째를 모두 바꿀 수 있다.  
```html
span:nth-child(5n + 1) {  
background-color: silver;  
}  
```
n을 사용하면 매우 편하다  

# 3.15

div의 바로 밑 자식에서 span을 찾아서 그것만 효과를 주는 방법  
```html
div span {
text-decoration : underline;
}
```  
이렇게하면 div밑에 있는 모든 span이 효과를 가진다  
직접적인 부모가 아니어도 밑에있는 것들을 모두 css가 찾는다  
```html
div > span {
text-decoration : underline;
}
```
이렇게하면 바로 밑을 찾게 되므로 바로 밑의 자식만 건들일 수 있게 된다.  
형제에게 효과를 주는방법  
```html
p + span {
color: black;

}
```
+를 사용하면 형제에게 영향을 끼칠 수 있다.  

※ > 를 사용하면 direct child를 찾고, + 를 사용하면 바로 코드상 밑에 있는 sibling을 찾게된다.

# 3.16

- "~"는 span이 p의 형제인데, 바로 뒤에 오지 않을 때 쓸 수 있다.
- Attribute selectors 특성 선택자
- 그냥 input과 required input이 있다면, input:required{}를 통해서, required input에만 속성을 적용시킬 수 있다.  
- input{} 을 통해, [input 이름]에 해당하는 input 속성을 따로 줄 수 있다.  
- 여기서, input[placeholder="First name"]은 First name에만 속성을 주지만, input[placeholder~="name"]은 name이 들어가는 모든 input에 속성을 부여할 수 있다.  
- "~="은 name을 포함하고 있다는 의미가 되는 것이다.  
- a[href$=".org"] → "$="는 ".org"로 끝나는 모든 anchor를 선택할 수 있다.  
- attribute selectors를 이용하면, class를 지정할 필요 없이 CSS만으로 각각의 속성을 부여해줄 수 있다.  

# 3.17

Active, hover, focus, focus-within, visited  

- active: 해당 요소를 마우스로 클릭했을 때 효과를 적용  

- hover: 마우스가 해당 요소 위를 지나갈 때 효과를 적용

- focus: 키보드로 선택되었을 때 효과를 적용

- focus-within: 부모 요소에게 적용. 자신의 자식 요소 중 하나가 focused되었을 때 효과를 적용

- visited: 방문한 사이트일 경우에 효과를 적용

조건을 나열해 여러 상황을 설정할 수 있음.  
예 high-tag:hover low-tag:focus{}  
인 경우, 상위 요소위에 마우스 커서가 있고, 하위 요소가 focused되었을 때 효과를 적용하게 된다.  
and 의 개념으로 받아드리면 될 것 같다.  

