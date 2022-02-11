# Git

> 2022/02/08 - 제대로 파는 Git & GitHub by 얄코 수강

## 새로 알게 된 점

- ### Git에게 맡기지 않을 것들

  - 포함할 필요가 없을 때
    - 자동으로 생성 또는 다운로드되는 파일들 (빌드 결과물, 라이브러리)
  - 포함하지 말아야 할 때
    - 보안상 민감한 정보를 담은 파일
  - .gitignore 파일을 사용해서 배제할 요소들을 지정
    - [gitignore 형식](https://git-scm.com/docs/gitignore)

- ### init

  현재폴더에 .git을 생성하고 관리내역들을 저장, 삭제하면 다시 되돌릴 수 없음

- ### status

  현재의 폴더에서 현재의 상황을 현재의 관점으로 보여주는 것

- ### Revert와 reset의 차이

  - revert: 원하는 시점으로 돌아가고 revert했던 내역을 커밋으로 추가한다.
  - reset: 과거로 돌아간 다음 돌아간 시점 이후 커밋은 히스토리에서 지워진다.

- ### reset의 세 가지 옵션

  - soft: repository에서 staging area로 이동
  - mixed (default): repository에서 working directory로 이동
  - hard: 수정사항 완전히 삭제

- ### Branch: 분기된 가지 (다른 차원)

  - 프로젝트를 하나 이상의 모습으로 관리해야 할 때  
    예) 실배포용, 테스트서버용, 새로운 시도용
  - 여러 작업들이 각각 독립되어 진행될 때  
    예) 신기능 1, 신기능 2, 코드개선, 긴급수정...
    각각의 차원에서 작업한 뒤 확정된 것을 메인 차원에 통합

- ### Rebase와 Merge의 차이

  - Rebase: 브랜치의 가지들을 메인으로 옮겨 붙인다. 깔끔하게 한줄로 이어 붙인다.
    - rebase로 합치기
      1. 예시) new-teams 브랜치를 main 브랜치로 rebase
      2. new-teams 브랜치로 이동
         - merge때와는 반대!
      3. git rebase main 명령어로 병합
      4. 소스트리에서 상태 확인
         - main 브랜치는 뒤쳐져 있는 상황
      5. main 브랜치로 이동 후 아래 명령어로 new-teams의 시점으로 fast-forward
         - git merge new-teams
      6. new-teams 브랜치 삭제
  - Merge: 브랜치의 가지들을 특정 시점으로 합류 시킨다. 브랜치의 흔적을 남긴다
    - merge로 합치기
      1. 예시) add-coach 브랜치를 main 브랜치로 merge
      2. main 브랜치로 이동
      3. git merge add-coach 명령어로 병합
      4. :wq로 자동입력된 커밋 메시지 저장하여 마무리
      5. 소스트리에서 확인

- ### 브랜치 병합시 충돌 해결하기

  - 브랜치 간 충돌
    - 파일의 같은 위치에 다른 내용이 입력된 상황

  1. Merge로 충돌 해결하기
     - 브랜치에서 병합을 시도하면 충돌 발생
     - 오류메시지와 git status 확인
     - VSC에서 해당 부분 확인
     - 해결이 어려울 땐 git merge --abort로 중단
     - 충돌 부분 수정한 뒤 git add 와 git commit으로 병합 완료
  2. Rebase로 충돌 해결하기
     - 해결 불가능
       1. 브랜치에서 main으로 rebase 시도하면 충돌 발생
       2. 오류 메시지와 git status 확인
       3. VSC에서 확인
       4. 해결이 어려울 경우 git rebase --abort로 중단
     - 해결 가능
       1. 충돌 부분 수정한 뒤 git add .
       2. git rebase --continue로 계속
       3. 이슈가 더 있을 경우 해결될 때까지 반복
       4. main이 뒤쳐져 있으므로 main에서 브랜치 merge로 마무리
       5. 브랜치 삭제

- ### pull 할 것이 있을 때 push를 하면?

  1. 로컬에서 Leopards의 manager를 Dooli로 수정
     - 커밋 메시지: Edit Leopards manager
  2. GitHub에서 Leopards의 coach를 Lupi로 수정
     - 커밋 메시지: Edit Leopards coach
  3. push 해보기
     - 원격에 먼저 적용된 새 버전이 있으므로 적용 불가
     - pull 해서 원격의 버전을 받아온 다음 push 가능
  4. push 할 것이 있을 시 pull 하는 두 가지 방법
     - git pull --no-rebase(merge 방식)
       - 소스트리에서 확인해보기
       - reset으로 되돌린 다음 아래 방식도 해보기
     - git pull --rebase - rebase 방식
     - pull 상의 rebase는 다름 (협업시 사용 OK)
  5. push하기

- ### Git의 HEAD

  - 현재 속한 브랜치의 가장 최신 커밋
  - checkout으로 앞뒤 이동해보기
    - ^ 또는 ~: 갯수만큼 이전으로 이동
    - git checkout HEAD^^^, git checkout HEAD~5
    - 커밋 해시를 사용해서도 이동 가능
      - git checkout (커밋해시)
    - git checkout - : (이동을) 한 단계 되돌리기
  - HEAD를 이동시키면 익명의 브랜치에 위치함을 알 수 있음

- ### Fetch와 Pull의 차이

   - fetch: 원격 저장소의 최신 커밋을 로컬로 가져오기만 함
     - 적용 전 checkout으로 확인
   - pull: 원격 저장소의 최신 커밋을 로컬로 가져와 merge 또는 rebase

- ### 유용한 설정들

   - 줄바꿈 호환 문제 해결
     - git config --global core.autocrlf (윈도우: true / 맥: input)
   - pull 기본 전략 merge 또는 rebase로 설정
     - git config pull.rebase false
     - git config pull.rebase true
   - 기본 브랜치명
     - git config --global init.defaultBranch main
   - push시 로컬과 동일한 브랜치명으로
     - git config --global push.default current

- 단축키 설정
   - [Git Alias](https://git-scm.com/book/ko/v2/Git%EC%9D%98-%EA%B8%B0%EC%B4%88-Git-Alias)
   - git config --global alias.(단축키) "명령어"
     - 예시: git config --global alias.cam "commit -am"


- ### Issue 해결

  - vscode에서의 터미널에서는 push가 가능하지만, Sourcetree에서는 push를 하면  
    토큰을 인증하라고하는 오류가 발생. 처음에는 자격증명의 문제인줄 알았으나  
    도구 -> 옵션 -> git 카테고리 -> 밑에 깃버전을 시스템으로 변경하고나서  
    push가 정상적으로 작동했다.  
    [도움 받은 블로그](https://itchbo.tistory.com/79)

</br>

## 도움되었던 링크

- [가장 쉬운 Git강좌-(상)](https://youtu.be/FXDjmsiv8fI)

- [가장 쉬운 Git강좌-(하)](https://youtu.be/GaKjTjwcKQo)
  - 합쳐서 30분가량 짧은 강의이지만 터미널과 소스트리에서 커밋하고 깃헙 저장소를 원격으로 연결하는 것까지 빠르게 설명해준다.  
    속도는 엄청나게 빠르지만 일시정지하고 하나하나씩 따라하니 금방 원격저장소 연결할 수 있었다.  
    이 강의만큼 직관적으로 설명해주는건 없는 것 같다
- [원격저장소 변경된 인증 방식](https://www.yalco.kr/_02_github_token/)
  - 2021년 8월 13일부터 원격을 통해 깃헙 저장소에 push, pull 하기 위해서는 토큰 인증이나 ssh를 입력하여야한다. push할때 오류가 떠서 당황했지만, 이 글을 찾고나서 해결했다.
- [누구나 쉽게 이해하는 git 입문](https://backlog.com/git-tutorial/kr/intro/intro1_1.html)
