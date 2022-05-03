# Webpack

---

# 소개

여러개의 리소스 파일(js, css, jpg)을 하나의 js 파일로 묶어주는 도구인 웹팩의 사용법을 소개해드리는 수업입니다. 웹팩은 이런 점에서 좋습니다.

1. 여러개의 파일을 하나로 묶어주기 때문에 네트워크 접속의 부담을 줄 일 수 있습니다. 더 빠른 서비스를 제공할 수 있습니다.
2. 여러개의 서로 다른 패키지들이 서로 같은 이름의 전역 변수를 사용하면 프로그램은 오동작하게 됩니다. 이런 문제를 극복하기 위해서 등장한 것이 모듈입니다.
3. 웹팩에는 매우 많은 플러그인들이 존재합니다. 이런 플러그인을 이용하면 웹개발시에 필요한 다양한 작업을 자동화 할 수 있습니다.

아래와 같은 내용을 다루고 있습니다.

- webpack 설치, 설정, 실행
- loader 개념
- plugin 개념

# 설치

1. node.js 설치

2. `npm init`으로 프로젝트 시작

3. `npm install -D webpack webpack-cli` 로 webpack 설치
   - -D옵션으로 애플리케이션 기능이아니라 개발을 위한 기능으로 설치

# 사용방법

번들링할 파일을 하나 선택한 후

`npx webpack --entry 만들 파일 경로 --output 모듈을 넣을 파일`

index.js

```js
import hello_word from "./hello.js";
import world_word from "./world.js";
document.querySelector("#root").innerHTML = hello_word + "" + world_word;
```

이런 index.js를 만들고 이 파일을 public폴더에 번들링을 하고싶다면

`npx webpack --entry ./source/index.js --output ./source/index_bundle.js`

이렇게 해주면

public 폴더에 번들링된 파일이 들어간다.
만약 파일을 100개를 만들고 번들링을 했다면 웹페이지에서는 모듈이 된 한개의 파일만 로딩하므로
리소스를 많이 줄일 수 있다
