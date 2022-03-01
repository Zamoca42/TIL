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
