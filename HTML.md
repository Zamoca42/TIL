HTML / CSS

# 2.0~3

폴더명, 파일명은 항상 소문자로 한다

브라우저는 HTML 파일에 에러가 있다고 알려주지 않는다
브라우저는 늘 컨텐츠를 보여주는 역할

HTML는 브라우저에게 이 것이 뭔지 알려주는 역할
HTML 태그
예시 <food>김치</food>
<open tag>content</close tag>

<h1>Hello this is my website!</h1>
큰 제목
태그를 닫지 않으면 끝나지 않고 지속되는 상태
열린 순서대로 닫아줘야함

<ul></ul> unordered list 순서가 없는 리스트
<ul>
    <li>beer</li>
    <li>김치</li>
    <li>meat</li>
    <li>milk</li>
</ul>

# 2.4

<ol></ol> ordered list 순서가 있는 리스트
a = anchor를 뜻함 (link를 떠올리면 됨) (추가적인 정보가 필요함)
attributes = 태그에 추가하는 정보 <tag attributes="value"></tag>
href = http reference라고 함 (anchor 태그에만 추가 가능)
target = 기본값은 _self이고, _blank 입력 시 새 탭에서 링크가 열림
img = 다른 태그와 다르게 /로 닫는 태그가 없다 (자체 닫기 태그이기 때문)
이미지는 텍스트가 아니기 때문에 자체 닫기 태그를 씀
<img></img> X 
<img /> O slef-closing tag
 
src = img 안에 사진을 집어넣음 (img에서 작동)
<img src="" /> 이미지 넣기

# 2.5

같은 폴더에 이미지가 있을 경우 이미지 이름.jpg
다른 경로일 경우 path/img.jpg
모든 HTML 문서는 <!DOCTYPE html>로 시작
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
og태그(open graph)는 프런트엔드를 이 과정보다 심화적으로 공부하시면 아실테지만, 콘텐츠의 요약내용이 SNS에 게시되는데 최적화된 데이터로 가지고 갈 수 있도록 설정하는 것 정도로 아시면 이해가 편할 것 같습니다.

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
      font-size:20px;
      }
</style>
```
h1태그와 연결된 색상과 글자크기가 바뀐다.
```html
<style>
  tagname {
    property : value;
  }
</style>
```
처럼 나타낼 수 있다. 속성 이름에는 밑줄(_) 또는 슬래쉬(/)를 사용할 수는 없다.

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
body {
      margin-left: 0px;
      margin-right: 5px;
      margin-top: 0px;
      margin-bottom: 10px;
      background-color: thistle;
     }
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
  body{
      margin: 20px 50px 12px 9px;
      }
</style>
```
시계방향으로 위 오른쪽 아래 왼쪽 순이다.
상하에서는 margin을 사용할 경우 Collapsing margins 현상이 발생한다
div와 body가 경계가 만날 때 body와 div의 경계가 하나로 취급된다.

