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
    - `git config --global core.autocrlf` (윈도우: true / 맥: input)
  - pull 기본 전략 merge 또는 rebase로 설정
    - `git config pull.rebase false`
    - `git config pull.rebase true`
  - 기본 브랜치명
    - `git config --global init.defaultBranch main`
  - push시 로컬과 동일한 브랜치명으로
    - `git config --global push.default current`

- 단축키 설정

  - [Git Alias](https://git-scm.com/book/ko/v2/Git%EC%9D%98-%EA%B8%B0%EC%B4%88-Git-Alias)
  - git config --global alias.(단축키) "명령어"
    - 예시: `git config --global alias.cam "commit -am"`

- ### 커밋할 때 권장 사항

  1.  하나의 커밋에는 한 단위의 작업을 넣도록 합니다.

  - 한 작업을 여러 버전에 걸쳐 커밋하지 않습니다.
  - 여러 작업을 한 버전에 커밋하지 않습니다.

  2.  커밋 메시지는 어떤 작업이 이뤄졌는지 알아볼 수 있도록 작성합니다.

- ### 커밋 메세지 컨벤션

  - 널리 사용되는 방식

    ```
    type: subject

    body (optional)
    ...
    ...
    ...

    footer (optional)
    ```

  - 예시

    ```
    feat: 압축파일 미리보기 기능 추가

    사용자의 편의를 위해 압축을 풀기 전에
    다음과 같이 압축파일 미리보기를 할 수 있도록 함
    - 마우스 오른쪽 클릭
    - 윈도우 탐색기 또는 맥 파인더의 미리보기 창

    Closes #125
    ```

  - Type

    | 타입     | 설명                          |
    | -------- | ----------------------------- |
    | feat     | 새로운 기능 추가              |
    | fix      | 버그 수정                     |
    | docs     | 문서 수정                     |
    | style    | 공백, 세미콜론 등 스타일 수정 |
    | refactor | 코드 리팩토링                 |
    | perf     | 성능 개선                     |
    | test     | 테스트 추가                   |
    | chore    | 빌드 과정 또는 보조 기능 수정 |

  - Footer
    - Breaking Point 가 있을 때
    - 특정 이슈에 대한 해결 작업일 때

- ### 내용 확인하며 hunk별로 스테이징하기 (내가 원하는 내용만 스테이징)

  - 아래 명령어로 hunk별 스테이징 진행  
    `git add -p` - 옵션 설명을 보려면 `?`입력 후 엔터 - y 또는 n로 각 헝크 선택 - 일부만 스테이징하고 진행해보기 - git status와 소스트리로 확인
  - 변경사항을 확인하고 커밋하기  
    `git commit -v`
    - `j`, `k`로 스크롤하며 내용 확인
    - `git diff --staged`와 비교
    - 커밋 후 남은 헝크를 다른 버전으로 커밋해보기

- ### 커밋하기 애매한 변화 치워두기(임시 저장)

  1.  변경 사항 만들기

      - Tigers의 members에 Stash 추가
      - tomcats.yaml 추가 후 add

        ```
        team: Tomcats

        coach: Apache
        ```

  2.  아래 명령어로 치워두기  
      `git stash`
      - git stash save와 같음
  3.  원하는 시점, 브랜치에서 다시 적용  
      `git stash pop`
  4.  원하는 것만 stash 해보기
      - Leopards의 members에 `Stash2` 추가
      - Jaguars의 members에 `Stash3` 추가
      - 아래 명령어로 `Stash2`만 선택하여 스태시  
        `git stash -p`
  5.  메시지와 함께 스태시  
      `git stash -m 'Add Stash3'`
      - 커밋처럼 메세지로 구분 가능
  6.  스태시 목록 보기  
      `git stash list`
      - 리스트상의 번호로 apply, drop, pop 가능
      - ex) git stash apply stash@{1}

- ### Stash 사용법 정리

  | 명령어                             | 설명                                          | 비고                           |
  | ---------------------------------- | --------------------------------------------- | ------------------------------ |
  | git stash                          | 현 작업들 치워두기                            | 끝에 save 생략                 |
  | git stash apply                    | 치워둔 마지막 항목(번호 없을 시) 적용         | 끝에 번호로 항목 지정 가능     |
  | git stash drop                     | 치워둔 마지막 항목(번호 없을 시) 삭제         | 끝에 번호로 항목 지정 가능     |
  | git stash pop                      | 치워둔 마지막 항목(번호 없을 시) 적용 및 삭제 | apply + drop                   |
  | :bulb: git stash branch (브랜치명) | 새 브랜치를 생성하여 pop                      | 충돌사항이 있는 상황 등에 유용 |
  | git stash clear                    | 치워둔 모든 항목들 비우기                     |

- ### 커밋 수정하기 (마지막 커밋 수정)

  - 커밋 메시지 변경

    ```
    git commit --amend
    ```

  - 커밋에 변화 추가

    - 파일을 수정하고 스테이지
    - `git commit --amend`로 마지막 커밋에 포함
    - 커밋 메시지 아무렇게나 변경

  - 커밋 메시지 한 줄로 변경
    ```
    git commit --amend -m 'Add members to Panthers and Pumas'
    ```

- ### 과거의 커밋들을 수정, 삭제, 병합, 분할

  - git rebase -i

    - 과거의 커밋 내역을 다양한 방법으로 수정 가능
    - 수정하고 싶은 커밋의 이전 시점 커밋의 해시를 사용
    - 명령어

      | 명령어    | 설명               |
      | --------- | ------------------ |
      | p, pick   | 커밋 그대로 두기   |
      | r, reword | 커밋 메시지 변경   |
      | e, edit   | 수정을 위해 정지   |
      | d, drop   | 커밋 삭제          |
      | s, squash | 이전 커밋에 합치기 |

  - rebase를 사용하는 이유는 수정 과정에서 브랜치로 분리되었다가 수정 완료 후 다시 합쳐짐

- ### 관리되지 않는 파일들 삭제하기

  - git에서 추적하지 않는 파일들 삭제

    ```
    git clean
    ```

    | 옵션 | 설명                              |
    | ---- | --------------------------------- |
    | -n   | 삭제될 파일들 보여주기            |
    | -i   | 인터렉티브 모드 시작              |
    | -d   | 폴더 포함                         |
    | -f   | 강제로 바로 지워버리기            |
    | -x   | .gitignore에 등록된 파일들도 삭제 |

  - 위의 옵션들을 조합하여 사용

- ### 변경 사항 되돌리기

  - 특정 파일을 지정된 상태로 복구

  - 파일을 여러 개를 수정하고 아래 명령어들 사용해보기

    ```
    git restore (파일명)
    ```

    - 워킹 디렉토리의 특정 파일 복구
    - 파일명 자리에 `.`: 모든 파일 복구

  - 변경상태를 스테이지에서 워킹디렉토리로 돌려놓기

    ```
    git restore --staged (파일명)
    ```

  - 파일을 특정 커밋의 상태로 되돌리기
    ```
    git restore --source=(헤드 또는 커밋 해시) 파일명
    ```

- ### reset했어도 희망은 있다!

  - reset으로 사라진 커밋을 복구할 수 있는 명령어
    ```
    git reflog
    ```
  - `reflog`는 프로젝트가 위치한 커밋이 바뀔 때마다 기록되는 내역을 보여주고  
    이를 사용하여 `reset`하기 이전 시점으로 프로젝트를 복구할 수 있습니다.

- ### 커밋에 :label:태그 달기

  - 특정 시점을 키워드로 저장하고 싶을 때
  - 커밋에 버전 정보를 붙이고자 할 때
  - 태그 달아보기

    | 태그 종류   | 설명                                           |
    | ----------- | ---------------------------------------------- |
    | lightweight | 특정 커밋을 가리키는 용도                      |
    | annotated   | 작성자 정보와 날짜, 메시지, GPG 서명 포함 가능 |

  - 마지막 커밋에 태그 달기 (lightweight)
     ```
     git tag v2.0.0
     ```
  - 현존하는 태그 확인
     ```
     git tag
     ```
  - 원하는 태그의 내용 확인
     ```
     git show v2.0.0
     ```
  - 태그 삭제
     ```
     git tag -d v2.0.0
     ```
  - 마지막 커밋에 태그 달기 (annotated)
     ```
     git tag -a v2.0.0
     ```
     입력 후 메시지 작성 또는
     ```
     git tag v2.0. -m '메시지'
     ```
     - `-m` 태그가 `-a`태그 암시
     - `git show v2.0.0`으로 확인

  - 원하는 커밋에 태그 달기 
     ```
     git tag (태그명) (커밋 해시) -m (메시지)
     ```
  - 원하는 패턴으로 필터링
     ```
     git tag -l 'v1.*'
     ```
  - 원하는 버전으로 이동
     ```
     git checkout v1.2.1
     ```
      - `switch`로 이전 브랜치로 복귀

 - ### 원격에 태그 동기화
   - 특정 태그 원격에 올리기
     ```
     git push (원격명) (태그명)
     ```
       - GitHub에서 확인
   - 특정 태그 원격에서 삭제
     ```
     git push --delete (원격명) (태그명)
     ```
   - 로컬의 모든 태그 원격에 올리기
     ```
     git push --tags
     ```

 - ### 다른 브랜치의 원하는 커밋 가져오기
   - `cherry-pick` 명령어 사용
     ```
     git cherry-pick (가져올 커밋의 해시)
     ```

 - ### 다른 브랜치에서 파생된 브랜치 옮겨 붙이기
   - `rebase --onto` 옵션 사용
     ```
     git rebase --onto (목표 브랜치) (출발 브랜치) (이동할 브랜치)
     ```

 - ### 다른 커밋들을 하나로 묶어 가져오기
   - `merge --squash` 옵션 사용
     ```
     git merge --squash (대상 브랜치)
     ```
       - 변경사항들 스테이지 되어 있음
       - `git commit`후 메시지 입력

- ### Issue 해결

  - vscode에서의 터미널에서는 push가 가능하지만, Sourcetree에서는 push를 하면  
    토큰을 인증하라고하는 오류가 발생. 처음에는 자격증명의 문제인줄 알았으나  
    도구 -> 옵션 -> git 카테고리 -> 밑에 깃버전을 시스템으로 변경하고나서  
    push가 정상적으로 작동했다.  
    [도움 받은 블로그](https://itchbo.tistory.com/79)

</br>

## 도움되었던 링크

- [Gitflow 협업을 위한 브랜칭 전략](https://nvie.com/posts/a-successful-git-branching-model/)

- [:bulb: Semantic Versioning 정보](https://semver.org/lang/ko/)

- [:pushpin: Gitmoji](https://gitmoji.dev/)

- [가장 쉬운 Git강좌-(상)](https://youtu.be/FXDjmsiv8fI)

- [가장 쉬운 Git강좌-(하)](https://youtu.be/GaKjTjwcKQo)

  - 합쳐서 30분가량 짧은 강의이지만 터미널과 소스트리에서 커밋하고 깃헙 저장소를 원격으로 연결하는 것까지 빠르게 설명해준다.  
    속도는 엄청나게 빠르지만 일시정지하고 하나하나씩 따라하니 금방 원격저장소 연결할 수 있었다.  
    이 강의만큼 직관적으로 설명해주는건 없는 것 같다

- [원격저장소 변경된 인증 방식](https://www.yalco.kr/_02_github_token/)

  - 2021년 8월 13일부터 원격을 통해 깃헙 저장소에 push, pull 하기 위해서는 토큰 인증이나 ssh를 입력하여야한다. push할때 오류가 떠서 당황했지만, 이 글을 찾고나서 해결했다.

- [누구나 쉽게 이해하는 git 입문](https://backlog.com/git-tutorial/kr/intro/intro1_1.html)
