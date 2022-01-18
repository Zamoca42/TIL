# Git

## 새로 알게 된 점
- ### Revert와 reset의 차이

    revert와 reset의 차이는  
    명령어를 수행하고 난 뒤 되돌아 갈 수 있느냐 없느냐의 차이다  
    revert를 사용하면 history에 revert했던 기록이 남는다  
    reset을 사용하면 history조차 뜨지않고 이전 commit으로 돌아간다.

 - ### Issue 해결  
    - vscode에서의 터미널에서는 push가 가능하지만, Sourcetree에서는 push를 하면  
    토큰을 인증하라고하는 오류가 발생. 처음에는 자격증명의 문제인줄 알았으나  
    도구 -> 옵션 -> git 카테고리 -> 밑에 깃버전을 시스템으로 변경하고나서  
    push가 정상적으로 작동했다.  
    [도움 받은 블로그](https://itchbo.tistory.com/79)


## 도움되었던 글  
- [가장 쉬운 Git강좌-(상)](https://youtu.be/FXDjmsiv8fI)  
    
- [가장 쉬운 Git강좌-(하)](https://youtu.be/GaKjTjwcKQo)
    - 합쳐서 30분가량 짧은 강의이지만 터미널과 소스트리에서 커밋하고 깃헙 저장소를 원격으로 연결하는 것까지 빠르게 설명해준다.   
    속도는 엄청나게 빠르지만 일시정지하고 하나하나씩 따라하니 금방 원격저장소 연결할 수 있었다.  
    이 강의만큼 직관적으로 설명해주는건 없는 것 같다
- [원격저장소 변경된 인증 방식](https://www.yalco.kr/_02_github_token/)
    - 2021년 8월 13일부터 원격을 통해 깃헙 저장소에 push, pull 하기 위해서는 토큰 인증이나 ssh를 입력하여야한다. push할때 오류가 떠서 당황했지만, 이 글을 찾고나서 해결했다. 
- [누구나 쉽게 이해하는 git 입문](https://backlog.com/git-tutorial/kr/intro/intro1_1.html)

