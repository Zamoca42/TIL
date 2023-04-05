우연한 계기로 관리자 페이지를 만드는 프로젝트를 시작하게 되었다. 내가 사용할 목적이 아닌 실제 프로덕션에서 사용될 것이라 생각하고 시니어 개발자분과 사양 결정부터 인프라까지 어떻게 사용할지 논의하면서, 이 경험이 현업에서도 좋은 경험이 될 것이라 생각하여 프로젝트에 참여했다.

사양 결정에서 처음에는 이전의 블로그 프로젝트의 경험으로 Django admin 페이지를 이용해서 회원 관리 페이지를 만들려고 했는데, Django admin 페이지를 사용하기에는 효율적일 수는 있으나 제한되는 부분이 생길 것 같아서 node.js를 써보고 싶다고 말씀드렸는데, 마침 회사에서도 nest.js를 사용 중이셔서 nest.js를 사용해보기로 결정했다.

그래서 프로젝트의 사양은 백엔드 nest.js + TypeScript, 프론트엔드는 React + TypeScript로 겹치는 부분이 많이 생기게 되었고, 설정 과정에서 monorepo를 사용하기로 결정했다. 블로그 프로젝트에 관한 글도 써야 하지만, 프로젝트 초기 설정 과정에서부터 지금까지의 경험이 임팩트 있게 다가왔기 때문에 이를 기록으로 남겨서 경험을 공유하려고 한다.

## Monorepo란?

`Monorepo`는 `Monolithic Repositories`의 약자로, 하나의 리포지토리에서 여러 개의 프로젝트가 구성된 것을 의미한다. 
이번 프로젝트에서는 백엔드와 프론트엔드가 각각의 폴더로 나눠져 있었다. 각각의 폴더에는 package.json이 있었고, 중첩되는 패키지는 root 디렉터리에서 관리하기로 했다.
또한, husky가 monorepo를 지원하는 점, 일관된 커밋 스타일 유지와 코드 검사를 위해 커밋 전 lint를 실행하기 위해 monorepo를 사용하게 되었다.

## Lerna를 사용한 이유

Monorepo를 사용할 때 `yarn`, `npm`, `lerna` 중 어떤 것을 선택할지 고민하였다. 
그 중 `lerna`가  2015년에 업데이트가 잠시 중단되었다가 2023년 현재도 활발하게 업데이트되고 있다는 것을 확인하였다. 또한 현재 상황에 맞는 레퍼런스를 찾을 수 있어서, `lerna`를 선택하게 되었다.

- [Setup Lerna Monorepo with Husky - 유튜브 영상](https://www.youtube.com/watch?v=_JAP9gq8hpc)

- Lerna 시작하기

```
npx lerna init
```

lerna를 시작하면 root 디렉터리에 `lerna.json`, `package.json`이 생성된다

- lerna.json

```json
{
	"$schema": "node_modules/lerna/schemas/lerna-schema.json",
	"useWorkspaces": true,
	"npmClient": "npm",
	"version": "independent"
}
```

- package.json

```json
{
	"name": "ohoo-studio-admin",
	"private": true,
	"version": "1.0.0",
	"description": "React-admin 는 React를 사용합니다.",
	"main": "index.js",
	"scripts": {
		"test": "echo \"Error: no test specified\" && exit 1",
		"prepare": "husky install"
	},
	"keywords": [],
	"author": "",
	"license": "ISC",
	"workspaces": [
		"packages/*"
	],
	"devDependencies": {
	    "commitizen": "^4.3.0",
		"lerna": "^6.6.1",
	    "husky": "^8.0.3",
	    "cz-conventional-changelog": "^3.3.0",
	},
	"config": {
	"commitizen": {
		"path": "./node_modules/cz-conventional-changelog"
		}
	},
	"dependencies": {
		"frontend": "file:packages/frontend",
		"nest-typescript-starter": "file:packages/backend"
	}
}
```

위의 설정은 `husky`, `commitizen`까지 설정을 끝마친 후의 설정이다.
`husky`, `commitizen` 설정방법은 아래에서 설명하도록 하겠다.

## ESlint 설정

`nest.js`에서는 `typescript-starter`로 시작하면서 자동으로 `eslint`와 `prettier`가 설정되어있다. 자세한 내용은 [공식 문서](https://docs.nestjs.com/first-steps)에서 확인할 수 있다.

프론트엔드에서 `React`와 `TypeScript`를 사용하기 위해 `eslint`를 설정해주어야 했다. 
`eslint`와 `prettier`는 백엔드에서도 사용하는 모듈이기 때문에 공통적으로 겹치는 패키지였다. 
따라서, 나중에 모듈을 모아주기 위해 백엔드에서 사용한 `eslint`와 같은 버전을 설정해주었다.

- eslintrc.json (react)
```json
{
	"env": {
		"browser": true,
		"es2021": true
	},
	"extends": [
		"plugin:prettier/recommended",
		"eslint:recommended",
		"plugin:react/recommended",
		"plugin:react/jsx-runtime",
		"plugin:@typescript-eslint/eslint-recommended",
		"plugin:@typescript-eslint/recommended"
	],
	"overrides": [
	],
	"parser": "@typescript-eslint/parser",
	"parserOptions": {
		"ecmaFeatures": {
			"jsx": true
		},
		"ecmaVersion": "latest",
		"sourceType": "module"
	},
	"plugins": [
		"react", "@typescript-eslint"
	],
	"rules": {
		"react/jsx-uses-react": "error",
		"react/jsx-uses-vars": "error",
		"@typescript-eslint/interface-name-prefix": "off",
		"@typescript-eslint/explicit-function-return-type": "off",
		"@typescript-eslint/explicit-module-boundary-types": "off",
		"@typescript-eslint/no-explicit-any": "error"
	}
}	
```

`eslint` 버전에 따라서 에러가 발생할 수 있으니 공식문서를 참고해서 설정을 해줘야 한다.

- https://eslint.org/docs/latest/use/getting-started
- https://github.com/jsx-eslint/eslint-plugin-react#configuration

## Husky (Git Hook)

> [Husky 공식문서](https://typicode.github.io/husky/#/)

Husky는 간편하게 Git Hook을 설정할 수 있도록 도와주는 도구로, 프로젝트에서 지속적 통합(CI)을 위한 용도로 사용되고있다.
Git Hook은 Git에서 커밋하거나 푸시하는 이벤트가 발생할 때 자동으로 실행되는 스크립트로, 
이번 프로젝트에서는 Husky를 사용하여 일관된 커밋 스타일과 코드 검사를 위해 도입했다.
Git Hook과 Husky에 대한 설명은 [가비아 기술 블로그](https://library.gabia.com/contents/8492/)에서 많은 도움을 받았다.

- 허스키 시작하기 (root)

```bash
npm install husky --save-dev
```

- git hooks 설정

```bash
npx husky install
```

- root의 package.json에 script 추가

```json
// package.json 
{ 
	"scripts":  { 
		"prepare": "husky install" 
	} 
}
```

여기까지 설정하면 추후에 다른 사람과 프로젝트를 진행할 때, 
`npm run prepare` 명령어를 실행하면 Husky가 자동으로 설치되어 모두 동일한 커밋 스타일과 
코드 검사를 할 수 있게 된다. 

## Git Hook 만들기

Husky를 통한 Git Hook을 만들 때 두 가지 방법이 있다. 
`npx husky add` 명령어를 사용하거나 `.husky` 폴더 아래에 직접 만들어줄 수 있다. 
이번 프로젝트에서는 `.husky` 폴더 아래에 직접 만들어주었다.

### commit-msg

```bash
#commit-msg

#!/bin/sh

if ! head -1 "$1" | grep -qE "^(feat|fix|ci|chore|docs|test|style|refactor|perf|build|revert)(\(.+?\))?: .{1,}$"; then
	echo "Aborting commit. Your commit message is invalid." >&2
	exit 1
fi

if ! head -1 "$1" | grep -qE "^.{1,88}$"; then
	echo "Aborting commit. Your commit message is too long." >&2
	exit 1
fi
```

`commit-msg`에서 type을 넣지 않으면 커밋을 할 수 없게 만들었다. 
`commitizen`을 사용해서 `cz-conventional-changelog`로 설정한 후에 
`git cz`를 통해 커밋을 하면 일관된 커밋 스타일을 만들 수 있다.

### pre-commit

```bash
#!/usr/bin/env sh

. "$(dirname -- "$0")/_/husky.sh"

lerna run --concurrency 1 --stream precommit --since HEAD --exclude-dependents
```

`pre-commit`은 커밋을 하기 직전에 실행된다. `lerna` 명령어를 통해서 packages 하위 폴더의 프로젝트에서 커밋 변화가 있는지 체크하고 변화가 있다면 
각 프로젝트의 `package.json`에서 `precommit` script를 추가해 `npm run lint`를 실행하게 설정했다.

`package.json` script 예시

- myproject/packages/frontend/package.json

```json
{
	"name": "frontend",
	"private": true,
	"version": "1.0.0",
	"type": "module",
	"scripts": {
		"dev": "vite",
		"build": "tsc && vite build",
		"preview": "vite preview",
		"precommit": "npm run lint",
		"lint": "eslint \"{src,apps,libs,test}/**/*.{ts,tsx}\" --fix"
	},
	//...
```

`frontend` 폴더에서 `precommit`이 먼저 실행되고 밑의 `lint`가 실행된다. 
`lerna run --stream lint` 이런 식으로 바로 `lint`를 넣어줄 수도 있다.

## 기존 프로젝트 이동

기존에 있는 backend, frontend 폴더가 있었지만, monorepo로 전환하면서 packages/ 폴더 아래로 옮겨주었다. 그리고 `lerna link convert` 명령어를 사용하여 루트 package.json으로 devDependencies 패키지를 옮겨주었다. 이때 프로젝트에 따라 명령어를 사용하는 것을 신중하게 결정해야 하며, 공통으로 겹치는 패키지만 루트 package.json으로 옮겨주는 것을 추천한다.

그 다음, 각 프로젝트의 packages-lock.json은 작동하지 않고 root에서 패키지를 관리하기 때문에 삭제해주어야 한다. 이후, root 디렉터리에서 `lerna clean`을 실행하여 각 프로젝트의 node_modules를 지우고, `lerna bootstrap`을 실행하여 node_modules를 루트에 모아 설치하고 연결해준다.

## Monorepo 설정 시 주의할 점

Monorepo를 사용하면서 주의할 점 중 하나는 패키지 관리이다. `lerna link convert`를 사용하면 모든 패키지를 한 곳에 모아둘 수 있지만, 이렇게 하면 `npm update`를 실행할 때 프로젝트를 구분하지 않고 한꺼번에 업데이트가 될 수 있어 의존성 충돌이 발생할 수 있다.

따라서 공통으로 사용하는 패키지들만 root의 package.json에 모아서 관리하고, 나머지는 개별 프로젝트 폴더의 package.json에서 관리하는 것을 추천한다. 이렇게 하면 각 프로젝트마다 필요한 패키지를 개별적으로 관리할 수 있으며, 프로젝트 간 의존성 충돌을 예방할 수 있다.

## 마무리

이번 프로젝트를 통해 처음으로 Monorepo에 대해 접했고, 초기에는 구조를 파악하는 것이 쉽지 않았다. 하지만 프로젝트가 진행됨에 따라 Monorepo의 장점을 더 많이 느낄 수 있었다. 여러 개의 프로젝트를 하나의 repository에서 관리할 수 있어 코드 관리가 쉬워졌고, 공통으로 사용하는 패키지들을 한 곳에서 관리할 수 있어 편리했다.

또한 Git Hook을 통해 커밋 스타일과 코드 검사를 일관되게 유지할 수 있어서 커밋 및 PR이 편해졌다. 특히 commit-msg를 통해 일관된 커밋 메시지를 작성할 수 있다는 점에서 마음에 들었다. 이번 프로젝트를 통해 배운 내용을 블로그 프로젝트에도 적용해봐야겠다.

## 참고 링크

- monorepo 관련 링크
	- https://www.youtube.com/watch?v=_JAP9gq8hpc
	- https://github.com/leoroese/blog-tube
	- https://d2.naver.com/helloworld/7553804
	- https://lerna.js.org/docs/introduction
	- https://d2.naver.com/helloworld/0923884
	- https://jeonghwan-kim.github.io/2022/07/31/npm-workspace
	- https://techblog.woowahan.com/7976/
	- https://velog.io/@sms8377/DevOps-MonoRepo%EB%9E%80

- react eslint 설정 관련 링크
        - [eslint-plugin-react](https://github.com/jsx-eslint/eslint-plugin-react#configuration)
        - [ESlint 공식문서](https://eslint.org/docs/latest/use/getting-started)
        - [토큰 에러 해결방법](https://velog.io/@belisy/parsing-error-unexpected-token)
        - [Delete \`\` 에러](https://velog.io/@realsong/VS-Delete-prettierprettier-%ED%95%B4%EA%B2%B0-%EB%B0%A9%EB%B2%95)

