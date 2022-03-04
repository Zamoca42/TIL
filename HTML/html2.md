# 셀렉터의 우선순위

class, id를 동시에 가지는 html 요소라면 스타일이 겹칠 수 있습니다.  
그럴 경우 우선순위가 존재합니다.

```
style="" (1000점)
#id (100점)
.class (10점)
p (1점)
```

정확한 카운트법은 아니지만 아무튼 이런 식입니다.  
점수가 높을 수록 더 우선적으로 적용됩니다.

# 일부 스타일은 inherit 됩니다

font-size, color, font-family, text-align 이런 속성들은  
부모 태그에 쥐어주면 거기 안에 있던 태그들까지 전부 상속됩니다.  
영어로 inherit 된다고합니다.  
안에 글자들이나 태그들이 많을 경우 전부 font-size를 작성안해도  
부모태그에 한번에 작성하고 끝낼 수 있으니 편리합니다.  
다 inherit되는건 아니고 글자와 관련된 스타일들이 주로 inherit 됩니다.

# 셀럭터 사용법

## 공백

```
.navbar li {
  display : inline-block;
}
```

위 처럼 공백을 이용해 안에 있는 li 태그인 모든 자손을 선택할 수 있습니다.

- 당연히 스페이스바 다음에 tag 셀렉터 말고 class 셀렉터 id 셀렉터 자유롭게 사용가능합니다.
- .class .class .class 이런 식으로 무한히 연달아 사용가능합니다.

## 꺾쇠괄호

```
.navbar>li {
  display : inline-block;
}
```

기호를 이용해 .li-inline 바로 밑에있는 자식만 선택할 수 있습니다.

## 더욱 상세히

```
.navbar li>span {
  color : red;
}
```

셀렉터를 그냥 연달아 사용하시면 됩니다.  
위의 예제는  
.navbar 안에 있는 모든 li, 그리고 그 안에 있는 모든 직계 자손 span 태그를 선택하고 있습니다.

# 주의해야할 margin 버그

```
<div class="배경">
  <p>안에 글씨</p>
</div>
```

div 박스 안에 p 태그를 사용했습니다.  
p 태그에 상단 margin을 주기 위해 margin-top을 주게 되면  
div와 p가 동시에 margin-top이 생기게 됩니다. 뭔가 이상합니다.

이 현상은 margin collapse effect 라고 부르는 일종의 버그입니다.  
원래 박스들의 테두리가 만나면 margin이 합쳐집니다.  
(박스가 내부에서 만나든 외부에서 만나든 상관없습니다.)  
정확히 말하면

1. 마진을 하나로 합쳐주고

2. 혹여나 둘 다 마진이 있으면 둘 중에 더 큰 마진을 하나만 적용하게 됩니다.

그래서 두 박스의 테두리가 겹치지 않도록 해주시면 보다 더 정확한 마진 노가다를 하실 수 있습니다.  
강의 예제에선 부모 박스에 padding을 1px 이렇게 조금 주는 것으로 쉽게 해결 가능합니다.

# Position - 좌표속성

## position을 사용하면

1. 좌표기준으로 움직임

2. 공중에뜸

## 속성값

position속성값은 기준점을 지정해주는 역할

```css
.box {
  position: static; /* 고정 */
  position: relative; /* 현재위치 */
  position: absolute; /* 부모 기준 */
  position: fixed; /* 화면기준 (viewport) */
}
```

# CSS nomalize

브라우저간 통일된 스타일을 주기 위해 특정 스타일을 맨 위에 적고  
CSS 코드짜기 시작하는 경우도 있습니다.  
왜냐면 브라우저마다 `<button>`의 스타일이 다르고, 가끔 line-height 이런 줄간격같은 것도 다르고  
`<input>` 사이즈도 다르기 때문입니다.  
그래서 같은 코드를 짜도 다른 브라우저에선 이상하게 보일 수 있습니다.

CSS Normalize 링크 : https://github.com/necolas/normalize.css/blob/master/normalize.css

여기있는 스타일 붙여넣으시면 브라우저간 다르게 보이는 문제들을 미리 해결할 수 있습니다.  
그래서 여기 있는 스타일을 그대로 여러분의 CSS 파일에 복붙하시거나  
아니면 다운받아서 `<link>` 태그로 첨부하시면 됩니다.

# inline 요소 간 상하정렬할 땐 vertical-align

```
<p>
  <span style="font-size : 50px">Greetings</span>   <span style="font-size : 20px">안녕</span>
</p>
```

inline은 항상 옆으로 채워지는 폭과 너비가 없는 요소입니다.  
display : inline 혹은 inline-block 요소들을 나란히 배치하면 상하정렬이 이상한 경우가 있습니다.

특히 큰 이미지와 글,  
또는 큰 글씨옆에 있는 작은 글씨  
이런걸 나란히 배치했을 때 서로 높이가 맞지 않는 경우가 많은데  
이럴 때 margin-top 이런거 대신 쓰는 속성입니다.  
top, middle, bottom 말고도 super, sub, px 단위로 사용가능합니다.  
(table 안에선 top, middle, bottom만 사용가능합니다)

# nth-child 셀렉터

```
.cart-table td:nth-child(2) {
  color: red;
}
```

여러 요소를 찾은 다음  
원하는 n번째 요소만 스타일을 주고 싶으면 `:nth-child(n)` 이걸 뒤에 붙여주면 됩니다.  
위의 코드는 그래서 .cart-table 안에 있는 모든 td를 찾은 다음  
2번째 나오는 td에만 color를 줄 수 있습니다.  
테이블에서 원하는 순서의 셀에 스타일줄 때 가끔 유용하게 사용합니다.

# 상태에 따라서 스타일을 줄 수 있는 Pseudo-class 셀렉터

```
.btn:hover {
  background : chocolate; /*마우스를 올려놓을 때*/
}
.btn:focus {
  background : red; /*클릭 후 계속 포커스 상태일 때*/
}
.btn:active {
  background : brown; /*클릭 중일 때*/
}
```

pseudo-class 셀렉터를 붙이시면 여러 상태에 따른 스타일을 지정해줄 수 있습니다.  
hover, focus, active 스타일 넣을 때 순서는 꼭 이렇게 선언해야 잘 동작합니다.

1. hover

2. focus

3. active

입니다. hofa로 외우면 잘외워지겠군요  
이거 말고도 수많은 pseudo-class가 있기 때문에 필요하면 찾아쓰도록 합시다.

```
:any-link /*방문 전, 방문 후 링크 한번에 선택할 때*/
:playing /*동영상, 음성이 재생중일 때*/
:paused /*동영상, 음성이 정지시*/
:autofill /*input의 자동채우기 스타일*/
:disabled /*disabled된 요소 스타일*/
:checked /*체크박스나 라디오버튼 체크되었을 때*/
:blank /*input이 비었을 때*/
:valid /*이메일 input 등에 이메일 형식이 맞을 경우*/
:invalid /*이메일 input 등에 이메일 형식이 맞지 않을 경우*/
:required /*필수로 입력해야할 input의 스타일*/
:nth-child(n) /*n번째 자식 선택*/
:first-child /*첫째 자식 선택*/
:last-child /*마지막 자식 선택*/
```

이거 말고도 매우 많습니다.

https://developer.mozilla.org/en-US/docs/Web/CSS/Pseudo-classes

# 폰트 Anti-aliasing 에 대해

여러분 맥으로 웹개발하시면 폰트 뭘 쓰든 이쁘게 보일겁니다.  
심지어 굴림, 돋움 같은 기본 폰트도 앤티앨리어싱이 되어서 부드럽게 나옵니다.  
앤티앨리어싱이 뭐냐면 그 픽셀의 각진 부분을 스무스하게 바꿔주는건데  

맥 OS쓰시면 알아서 해주지만 윈도우는 전혀 아닙니다.  
윈도우에서 돋움, 굴림 폰트를 매우 작게 축소하거나 아니면 매우 크게 확대했을 때 매우 각져보입니다.   
돋움, 굴림 뿐만 아니라 대부분의 폰트가 저런 현상이 일어납니다.   
디자인 잘하는 사람 입장에선 매우 거슬리는 문제인데  
이 문제를 해결하고 싶다면 웹상의 글자를 살짝 돌려보십시오.   

`transform : rotate(0.04deg); `
CSS파일에다가 이거 쓰라는겁니다.   
transform 어쩌구는 나중에 배울텐데 요소를 살짝 회전시키는 스타일입니다.   
글자를 정말 매우 살짝 회전시키면 윈도우에선 안티앨리어싱 된 듯한 느낌을 줍니다.  

# Emmet
```
 div.container>div
 ```
이렇게 입력하시자마자 tab키를 한번 눌러보시면  
```
<div class="container">
  <div></div>
</div>
```
HTML이 뿅 하고 생성됩니다.  
훨씬 빠르게 레이아웃을 만들어낼 수 있습니다.  
생각한 HTML 레이아웃을 CSS 셀렉터처럼 작성해주신 후에 tab키만 누르시면 됩니다.  
(> 표시는 내 바로밑의 자식요소라는 뜻이라 저렇게 생성된 것입니다.)  
이런 것도 가능합니다.  
```
 div#header>p.title*3
 ```
이렇게 쓰고 탭키 누르면  
 
```
<div id="header">
  <p class="title"></p>
  <p class="title"></p>
  <p class="title"></p>
</div></div>
```
p.title 이건 p태그인데 class명이 title이라는 CSS 셀렉터 문법이고  
div#header 이건 div태그인데 id명이 header라는 CSS 셀렉터 문법입니다.  
그렇게 작성하고 tab 누르면 진짜 그렇게 html을 생성해줍니다.  
참고로 *3 이건 3개씩 생성하라는 뜻입니다.   

# 조건부로 익스플로러 버전용 CSS파일 첨부하기

익스플로러 X 버전 이하에서만 적용할 수 있는 CSS파일을 첨부할 수 있습니다.  

```
<!--[if lt IE 9]>
  <link rel="stylesheet" type="text/css" href="css/ie8.css" />
<![endif]-->
 ```

이렇게 첨부해주시면 css폴더내의 ie8.css 라는 파일은 인터넷 익스플로러 9 미만에서만 적용됩니다.  
저걸 [if lt IE 10] 이렇게 바꾸면 익스플로러 10 미만에서만 적용됩니다.  
이렇게 첨부하신 후 ie8.css에 여러분이 수정하고 싶은 코드를 담고 head태그 내에 다른 CSS 파일들과 함께 첨부해주시면 됩니다.  

참고로 ie8.css 파일은 다른 브라우저에선 전혀 읽지 않습니다.  
(link 태그 첨부 순서는 가장 마지막이 좋습니다. 중요한 덮어쓰기 파일일 수록 밑으로 보내시면 됩니다.)  

# transition 속성
```
.box {
  opacity : 0;
  transition : all 1s;
}
``` 
transition을 부여하면  
여기에 적용된 CSS가 변할 때 서서히 변경해줍니다.  
all은 모든 스타일이 변할 때 서서히 변경하라는 뜻이고 (all 대신 opacity 이렇게 하나만 줄 수도 있음)  
1s 이건 1초에 걸쳐서 서서히 변경해달라는 뜻입니다.  

## transition 세부 속성 살펴보기 
```
.box {
  transition-delay: 1s; /* 시작 전 딜레이 */
  transition-duration: 0.5s; /* transition 작동 속도 */
  transition-property: opacity; /* 어떤 속성에 transition 입힐건지 */
  transition-timing-function: ease-in; /* 동작 속도 그래프조정 */
}
```
이런 식으로 세부설정도 가능합니다.  

애니메이션 종류도 수십가지일텐데  
그거 전부 하나하나 설명하려면 100강도 모자르기 때문에 귀찮으니  
여러분은 그냥 애니메이션 만드는 법칙을 외워가시길 바랍니다.  
이거 외우면 앞으로 혼자 알아서 만들 수 있음  

one-way 애니메이션 혼자 알아서 만드는 법 :  

one-way 애니메이션은 A에서 B로 정지없이 쭉 이동하는 애니메이션을 뜻합니다.   

1. 시작스타일 정하기

2. 최종스타일 정하기

3. 언제 최종스타일로 변할지 트리거 주기 (대부분 마우스 올렸을 때임)

4. transition 으로 서서히 동작하게 만들기 

이런 스텝으로 CSS 코드 짜면 끝입니다.  

# Bootstrap

Boostrap은 프론트엔드 Component Library라고 하여  

웹페이지에 필요한 버튼, 메뉴, 탭, 모달, 카드 등 필수 요소들을 모아놓은 일종의 CSS 파일입니다.  

이걸 우리 HTML 파일에 설치하시면 보다  빠른 복붙식 HTML CSS개발이 가능합니다.  

## Utility Class 사용가능

```
<div class="container">이쁜 여백가진 박스</div>
<div class="mt-5">margin-top 쉽게 주기</div>
<div class="pb-5">padding-bottom 쉽게 주기</div>
<div class="fs-3">font-size 쉽게 주기</div>
<div class="text-center">text-align 쉽게 주기</div>
<div class="fw-bold">font-weight 쉽게 주기</div>
 ```

Bootstrap을 설치하면 저런 class 들을 이용가능합니다.  
여러분이 직접 CSS 에다가 padding-bottom 기록할 필요 없이  
그냥 pb-5 이렇게 주면 끝인 것입니다.  
(pb1~5 까지 있습니다.)  

몇개 외워놓으면 개발 시간이 매우 빨라지겠죠?  
padding-left 는 ps-5 (start의 약자)  
padding-right 는 pe-5 (end의 약자)  
등 수백개가 있어서 더 찾고 싶으면 Bootstrap 홈페이지의 Utility class 메뉴를 살펴봅시다.  

 ## 박스 분배  

 박스를 균일하게 쪼개고 싶을 때 Bootstrap grid 레이아웃을 사용하면 쉽고 빠르게 구현이 가능합니다.  
```
<div class="row">
  <div class="col"> 안녕 </div>
  <div class="col"> 안녕 </div>
  <div class="col"> 안녕 </div>
</div>
```
동일한 영역으로 쪼개고 싶을 때 각각 박스에 col, 그리고 부모에는 row라는 클래스를 부여하면 됩니다.   
하지만 정확히 하려면 col 이것만 달랑 쓰는게 아니라 col-4 이렇게 숫자도 뒤에 적어주셔야합니다.   
```
<div class="row">
  <div class="col-4"> 안녕 </div>
  <div class="col-4"> 안녕 </div>
  <div class="col-4"> 안녕 </div>
</div>
```
이래야 가로폭을 정확히 3등분할 수 있는데 왜 대체 4를 적어야하냐면  

Bootstrap은 웹디자인의 대 원칙 12 column 디자인을 사용하고 있습니다.  

웹사이트를 디자인할 때 12개의 세로 선으로 쪼개면 사이트를 안정감있고 균형있게 편리하게 디자인할 수 있다는 소리인데  
그래서 포토샵 켜서 웹디자인할 때   

이런 12개의 가이드 라인을 그리고 디자인하는 경우가 많습니다.  
왜 12라는 숫자를 선택했냐면 균일하게 6등분, 4등분, 3등분, 2등분하기 매우 쉬워지니까요.   

그래서 Bootstrap을 사용할 때 `<div class="row">` 이걸 사용하면  
div 안쪽을 정확히 12등분하게 되며  
그 안에 있는 박스들은 `<div class="col-4">` 이렇게 사용해서  
몇개의 column을 차지할지 명시해줘야 정확한 가로폭 사이즈 재단이 가능합니다.  

```
<div class="row">
  <div class="col-6"> 안녕 </div>
  <div class="col-6"> 안녕 </div>
</div>
```

그럼 이렇게 하면 화면을 반반 정확히 쪼갤 수 있겠군요.  

# Pseudo-element

내가 특정 HTML 요소의 안쪽 일부만 스타일을 주고 싶을 때  
Pseudo-element 셀렉터를 이용해서 스타일을 줄 수 있습니다.  
예를 들면 이런 것들이 가능합니다.  

## Pseudo-element로 HTML 특정부분에 스타일링하기/글씨넣기

```
.text::first-letter {
  color : red;
}

.text::first-line {
  color : red;
}

.text::after {
  content : '뻥이지롱';
  color : red;
}

.text::before {
  content : '뻥이지롱';
  color : red;
}
```

1. pseudo-element를 선택하려면 콜론 2개 :: 를 사용하면 됩니다. 

2. ::first-letter라고 붙이면 안에 있는 글자 중 첫 글자만 스타일을 줄 수 있습니다.

3. ::first-line이라고 붙이면 안에 있는 글자 중 첫 줄만 스타일을 줄 수 있습니다.

4. ::after라고 붙이면 내부의 맨 마지막 부분에 특정 글자같은걸 추가해줄 수 있습니다.

5. ::before라고 붙이면 내부의 맨 앞 부분에 특정 글자같은걸 추가해줄 수 있습니다.

"first-letter 대신 그냥 첫 글자를 span태그로 감싸면 되지않나요?"  

그래도 되겠지만 서버와 데이터베이스로 인해 글자가 항상 다이나믹하게 변하는 경우 항상 span태그를 넣기 불가능합니다.  
그럴 때 사용하시면 되겠습니다.  

## Pseudo-element로 clear : both 박스 편하게 만들기

```
.box::after {
  content : '';
  display : block;
  clear : both;
}
```

갑자기 어떤 요소 뒤에 clear : both 속성을 가진 div박스가 필요하다면  
일부러 div를 하나 만들 필요 없이 이렇게 div를 흉내내서 사용하시면 되겠습니다.  
content 안에 아무것도 안적은 후 display : block을 주면 div 비슷한게 하나 생성되니까요.  

# Shadow DOM

HTML 개발시 코드가 너무 복잡해지지 않기 위해 숨겨놓은 HTML 요소들이 있습니다.  
이걸 Shadow DOM이라고 부릅니다.  
하지만 아무나 볼 수는 없습니다.  

'어둠을 보는 눈'이 필요한데 이걸 얻는 법을 설명해드리겠습니다.   
일단 크롬 개발자도구 셋팅 변경이 필요합니다.  

1. 개발자도구를 켠 상태에서 F1 (혹은 Settings 메뉴)를 누르면 나오는 곳에서

2. Show user agent shadow DOM을 체크하시면 됩니다. 

이제 여러분은 숨겨진 HTML요소까지 몰래 구경가능합니다.  

## Shadow DOM 활용법

shadow DOM을 잘 활용하면 내가 전에 커스터마이징 할 수 없었던 요소도 커스터마이징이 가능합니다.  
예를 들어 `<input placeholder="안녕하세요">` 이러면  
회색글씨가 input 안에 생성이 되는데  
이 회색 글씨의 스타일을 바꾸고 싶다면 shadow DOM을 까보시면 됩니다.  

찾을 때 pseudo라는 속성이 부여되어있다면 저번시간에 했던 pseudo-element 처럼 찾을 수 있습니다.   

```
input::-webkit-input-placeholder {
  color : red; 
}
```

이렇게 쓰면 기존에 보이지 않았던 shadow DOM 요소들도 스타일을 줄 수 있습니다.  
 - 스크롤바
 - 드래그시 하이라이트되는 파란색 색상
 - 파일 업로드 버튼

등 많은걸 커스터마이징 가능합니다.  
솔직히 저렇게 직접 안뒤져봐도 그냥 구글 검색 잘하면 누구나 적용할 수 있긴 한데  
위와 같은 원리 같은걸 이해하면 이제 혼자 알아서 코드짤 수 있습니다.  

 
## -webkit- 수식어

```
input::-webkit-input-placeholder {
  color : red; 
}
```

크롬, 오페라, 사파리, Edge 브라우저에서만 동작하는 스타일을 만들고 싶을 때 사용합니다.  
 - 파이어폭스는 -moz-
 - 익스플로러는 -ms-
이렇게 붙여주면 됩니다.  

그럼 `input::-moz-input-placeholder`  이렇게 하면 파이어폭스용 스타일을 줄 수 있는 것이구나라고 생각할 수 있겠지만  
훌륭한 생각이지만 shadow DOM 스타일 예측은 틀릴 때가 많습니다.  
여러분이 파이어폭스 브라우저로 똑같이 shadow DOM을 까봐야 제대로된 스타일을 줄 수 있습니다.  
아니면 구글을 찾아보도록 합시다.  

 