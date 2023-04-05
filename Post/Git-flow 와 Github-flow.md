제일 처음으로 git-flow를 알게 된 것은 [우아한형제들 기술 블로그](https://techblog.woowahan.com/2553/)에서 git-flow에 관한 글을 읽은 것이었다.

이번 블로그 프로젝트를 진행하면서 git-flow에 대해서만 알고 있었기 때문에, 혼자 프로젝트를 진행하는 것이 브랜치 관리가 많아 부담스러웠다. 그런데 얼마 전에 github-flow를 알게 되어 이후 늦게라도 github-flow를 적용해보려고 한다. git-flow와 github-flow 중에 자신의 상황에 맞는 전략을 적용하는 것이 좋을 것 같다. 아래에서는 git-flow와 github-flow를 비교해 보았다.

## Git-flow

> master -> main으로 변경합니다

![pasted image 0](https://user-images.githubusercontent.com/96982072/227922966-e7f04bb8-7943-434b-8a8a-cbb4097a0339.png)


git-flow는 브랜치를 5가지 종류로 구분하여 개발하는 전략이다.

git-flow 전략의 특징은 다음과 같다:

-   주기적으로 배포를 진행해야 하는 프로젝트에 적합하다.
-   개발자가 5명 이상일 때 효과적으로 사용할 수 있다.
-   다양한 상황에 유연하게 대응할 수 있다.
-   다만, 많아진 브랜치를 관리해야 하는 부담이 있다.

이렇게 요약해볼 수 있다.

## Git-flow의 흐름

![pasted image 1](https://user-images.githubusercontent.com/96982072/227924759-0e4dc474-667a-477e-8aca-33b936a2dc77.png)

**main**

- 배포 가능한 상태만을 관리하는 브랜치

**develop**

- 다음 출시 버전을 개발하는 브랜치
- develop 브랜치는 통합 브랜치의 역할을 하며, 평소에는 이 브랜치를 기반으로 개발을 진행

**feature**

- 기능을 개발하는 브랜치로, develop 브랜치로부터 분기
- feature 브랜치는 해당 기능이 완성될 때까지 유지하며, 완성되면 develop 브랜치로 병합

**release**

- 이번 출시 버전을 준비하는 브랜치
- develop 브랜치에 이번 버전에 포함되는 기능이 병합되었다면, QA를 위해 develop 브랜치에서부터 release 브랜치를 생성
- 배포를 위한 최종적인 버그 수정 등의 개발을 수행
- 배포 가능한 상태가 되면 main 브랜치로 병합하고, 출시된 main 브랜치에 버전 태그를 추가

**hotfix**

- 배포한 버전에서 긴급하게 수정해야 할 필요가 있을 때, main 브랜치에서 분기하는 브랜치
- 버그를 수정하는 동안에도 다른 사람들은 develop 브랜치에서 일을 계속할 수 있다.
- 이때 만든 hotfix 브랜치에서의 변경 사항은 develop 브랜치에도 병합하여 문제가 되는 부분을 처리해야 한다.


## Github-flow

> master -> main으로 변경합니다

![스크린샷 2023-03-27 오후 8 44 23](https://user-images.githubusercontent.com/96982072/227937502-73a8e6cd-1c9d-4a9f-93b0-0141d95f06c6.png)

Github-flow의 브랜칭 전략은 다음과 같다:

-   수시로 배포가 일어나며, CI와 배포가 자동화된 프로젝트에 유용하다.
-   main branch에 대한 규칙만 정확하게 정립되어 있다면, 나머지 브랜치들에 대해서는 특별한 관리를 하지 않는다.
-   release branch가 명확하게 구분되지 않은 시스템에서의 사용이 유용하다.
-   pull request 기능을 사용하도록 권장한다. 우선 이 정도로 정리가 가능할 것 같다.

## Github-flow의 흐름

1.  main 브랜치는 언제든 배포 가능한 상태로 유지한다.
	- 다른 브랜치에서 병합되어 제품에 배포되는 브랜치로 둔다.

2.  개발 및 커밋 & 푸시  
    - 개발을 진행하며 커밋을 남긴다.
    - 브랜치와 같이 커밋 메시지에 의존해야 하므로, 커밋 메시지를 최대한 상세하게 적는 것이 중요하다.
    - 원격 브랜치로 수시로 푸시한다. 하드웨어 문제로 작업한 부분이 사라져도 원격 저장소의 소스를 받아 작업을 계속할 수 있도록 해준다.
	
3.  PR(Pull Request) 생성  
    - 피드백이나 도움이 필요할 때, 또는 병합 준비가 완료되었을 때는 pull request를 생성한다.
    - Pull-Request가 main 브랜치에 합쳐지면 곧바로 라이브 서버에 배포되므로, 상세한 리뷰와 토의가 필요하다.

4.  테스트  
    - 리뷰와 토의가 끝났다면 해당 내용을 라이브 서버(혹은 테스트 환경)에 배포해본다.
    - 배포 시 문제가 발생하면 즉시 main 브랜치의 내용을 다시 배포하여 초기화 시킨다.

5.  최종 병합  
    - 대부분의 Github-flow에서는 main 브랜치를 최신 브랜치로 가정하고, 배포 자동화 도구를 이용해 병합 즉시 배포를 진행한다.

## 참고 링크

- https://blog.programster.org/git-workflows
- https://github.com/nvie/gitflow
- http://scottchacon.com/2011/08/31/github-flow.html
- https://ujuc.github.io/2015/12/16/git-flow-github-flow-gitlab-flow/
- https://techblog.woowahan.com/2553/
- https://nvie.com/posts/a-successful-git-branching-model/
- https://inpa.tistory.com/entry/GIT-⚡%EF%B8%8F-github-flow-git-flow-📈-브랜치-전략#github-flow_전략