# GraphQL

# REST API의 한계

## Case 1. 각 팀의 매니저와 오피스 호수만 필요할 때

```
[
  {
    "manager": "Mandy Warren",
    "office": "101A",
  },
  {
    "manager": "Stewart Grant",
    "office": "101B",
  },
  {
    "manager": "Smantha Wheatly",
    "office": "102A",
  },
  // ...
]
```

- Overfetching
  - 딱 필요한 정보들만 받아올 수는 없을까?

## Case 2. 특정 팀의 매니저와 팀원들 명단이 필요할 때

```
{
  "manager": "Mandy Warren",
  "members": [
    {
      "first_name": "Nathan",
      "last-name": "Jenkins"
    },
    {
      "first_name": "Isabella",
      "last-name": "Martin"
    },
    {
      "first_name": "Kate",
      "last_name": "Owen"
    },
    //...
  ]
}
```

- Underfetching
  - 필요한 정보들을 요청 한 번에 받아올 수는 없을까?

# GraphQL 사용해보기

## 팀 정보 받아오기

```
query {
  teams {
    id
    manager
    office
    extension_number
    mascot
    cleaning_duty
    project
  }
}
```

## 팀의 필요한 정보만 받아오기

```
query {
  teams {
    manager
    office
  }
}
```

```
query {
  team(id: 1) {
    manager
    office
  }
}
```

## 팀 정보와 해당 팀 멤버들의 정보들 받아오기

```
query {
  team(id: 1) {
    manager
    office
    members {
      first_name
      last_name
    }
  }
}
```

## 새 팀 추가

```
mutation {
  postTeam (input: {
    manager: "John Smith"
    office: "104B"
    extension_number: "#9982"
    mascot: "Dragon"
    cleaning_duty: "Monday"
    project: "Lordaeron"
  }) {
    manager
    office
    extension_number
    mascot
    cleaning_duty
    project
  }
}
```

## 특정 번호의 팀 정보 수정

```
mutation {
  editTeam(id: 2, input: {
    manager: "Maruchi Han"
    office: "105A"
    extension_number: "2315"
    mascot: "Direwolf"
    cleaning_duty: "Wednesday"
    project: "Haemosu"
  }) {
    id,
    manager,
    office,
    extension_number,
    mascot,
    cleaning_duty,
    project
  }
}
```

# GraphQL의 강점

1. 필요한 정보들만 선택하여 받아올 수 있음

   - Overfetching 문제 해결
   - 데이터 전송량 감소

2. 여러 계층의 정보들을 한 번에 받아 올 수 있음

   - Underfetching 문제 해결
   - 요청 횟수 감소

3. 하나의 endpoint에서 모든 요청을 처리
   - 하나의 URI에서 POST로 모든 요청 가능

# GraphQL로 서비스를 만들려면?

- GraphQL은 형식일 뿐

## GraphQL을 구현할 솔루션 필요

- 백엔드에서 정보를 제공 및 처리
- 프론트엔드에서 요청 전송
- GraphQL.js, GraphQL Yoga, AWS Amplify, Relay...
- [기타 솔루션들](https://graphql.org/code/)

## Apollo GraphQL

- 백엔드와 프론트엔드 모두 제공
- 간편하고 쉬운 설정
- 풍성한 기능들 제공

# 프로젝트 시작하기

> GraphQL을 사용하는 백엔드 서버

## a.프로젝트 생성

1. 프로젝트 폴더 생성 뒤 VS Code에서 열기

2. 프로젝트 폴더 터미널 창 열기

3. Node.js 프로젝트 생성

```
npm init
```

4. index.js 파일 생성

5. 실행명령 테스트

## b.목(mock)데이터베이스 모듈 삽입

1. `2-1-graphql-api-setup` 폴더 안 내용들을 프로젝트로 이동

2. index.js

```js
const database = require("./database");
console.log(database);
```

3. 필요 모듈 설치 뒤 테스트

```
npm i convert-csv-to-json
npm start
```

## c.Apollo Server 설치

1. 아폴로 서버 실행

```js
const database = require("./database");
const { ApolloServer, gql } = require("apollo-server");
const typeDefs = gql`
  type Query {
    teams: [Team]
  }
  type Team {
    id: Int
    manager: String
    office: String
    extension_number: String
    mascot: String
    cleaning_duty: String
    project: String
  }
`;
const resolvers = {
  Query: {
    teams: () => database.teams,
  },
};
const server = new ApolloServer({ typeDefs, resolvers });
server.listen().then(({ url }) => {
  console.log(`🚀  Server ready at ${url}`);
});
```

코드 설명

- typeDef와 resolver를 인자로 받아 서버생성
  - typeDef
    - GraphQL 명세에서 사용될 데이터, 요청의 타입 지정
    - gql(template literal tag)로 생성
  - resolver
    - 서비스의 액션들을 함수로 지정
    - 요청에 따라 데이터를 반환, 입력, 수정, 삭제
  - GraphQL Playground
    - 작성한 GraphQL type, resolver 명세 확인
    - 데이터 요청 및 전송 테스트

```
npm start
```

2. `localhost:4000`으로 접속해 쿼리 테스트

```
query {
  teams {
    id
    manager
    office
    extension_number
    mascot
    cleaning_duty
    project
  }
}
```

# Query 구현하기

## Query 루트 타입

```
type Query {
    teams: [Team]
}
```

- 자료요청에 사용될 쿼리들을 정의
- 쿼리 명령문마다 반환될 데이터 형태를 지정

## Type 살펴보기

```js
type Team {
    id: Int
    manager: String
    office: String
    extension_number: String
    mascot: String
    cleaning_duty: String
    project: String
}
```

- 반환될 데이터의 형태를 지정
- 자료형을 가진 필드들로 구성

## Resolver 살펴보기

```js
const resolvers = {
  Query: {
    teams: () => database.teams,
  },
};
```

- Query란 object의 항목들로 데이터를 반환하는 함수 선언
- 실제 프로젝트에서는 MySQL 조회 코드 등..

## equipments를 반환하는쿼리 만들어보기

- dbtester.js 생성

  ```js
  const database = require("./database");
  console.log(database.equipments);
  ```

- equipment의 데이터 자료형

  ```js
  type Equipment {
    id: String,
    used_by: String,
    count: Int,
    new_or_used: String
  }
  ```

- 다수의 equipment를 반환하는 쿼리

  ```js
  type Query {
    ...
    equipments: [Equipment]
  }
  ```

- 데이터베이스에서 equipments를 추출하여 반환하는 resolver

  ```js
  Query: {
    // ...
    equipments: () => database.equipments;
  }
  ```

## supplies 받아오기 추가

```js
query {
    ...
    type Supply {
        id: String,
        team: Int
    }
}
```

```js
type Query {
    ...
    supplies: [Supply]
}
```

```js
type Query {
    //...
    supplies: () => database.supplies
}
```

## 특정 team만 받아오기

- args로 주어진 id에 해당하는 team만 필터링하여 반환

  ```js
  Query: {
    //...
    team: (parent, args, context, info) => database.teams
        .filter((team) => {
            return team.id === args.id
        })[0],
  }
  ```

- id를 인자로 받아 하나의 Team 데이터를 반환

  ```js
  type Query {
    ...
    team(id: Int): Team
  }
  ```

  ```
  query {
    team(id: 1) {
      id
      manager
      office
      extension_number
      mascot
      cleaning_duty
      project
    }
  }
  ```

## team에 supplies 연결해서 받아오기

- Team 목록을 반환 시 해당하는 supplies를 supplies 항목에 추가

  ```js
  Query: {
    // ...
    teams: () => database.teams
    .map((team) => {
        team.supplies = database.supplies
        .filter((supply) => {
            return supply.team === team.id
        })
        return team
    }),
  }
  ```

- Team의 항목들 중 supplies: 다수의 Supply를 반환

  ```js
  type Team {
    id: Int
    manager: String
    office: String
    extension_number: String
    mascot: String
    cleaning_duty: String
    project: String
    supplies: [Supply]
  }
  ```

# Mutation 구현하기

## Equipment 데이터 삭제하기

- Mutation - 삭제 루트 타입

  ```js
  type Mutation {
    deleteEquipment(id: String): Equipment
  }
  ```

  - String 인자 id를 받는 deleteEquipment: 삭제된 Equipment를 반환

- 삭제 resolver

  ```js
  Mutation: {
    deleteEquipment: (parent, args, context, info) => {
      const deleted = database.equipments.filter((equipment) => {
        return equipment.id === args.id;
      })[0];
      database.equipments = database.equipments.filter((equipment) => {
        return equipment.id !== args.id;
      });
      return deleted;
    };
  }
  ```

  - 삭제 후 결과값으로 받아올 데이터를 deleted 변수에 저장
  - 데이터에서 해당 데이터 삭제 후 deleted 반환
  - 실제 프로젝트에서는 SQL의 DELETE 문 등으로 구현

  ```
  mutation {
    deleteEquipment(id: "notebook") {
      id
      used_by
      count
      new_or_used
    }
  }
  ```

## Equipment 데이터 추가하기

- Mutation - 추가 루트 타입

  ```js
  type Mutation {
    insertEquipment(
        id: String,
        used_by: String,
        count: Int,
        new_or_used: String
    ): Equipment
    ...
  }
  ```

  - 추가할 Equipment의 요소 값들을 인자로 받고 추가된 Equipment를 반환

- 추가 resolver

  ```
  Mutation: {
    insertEquipment: (parent, args, context, info) => {
        database.equipments.push(args)
        return args
    },
    //...
  }
  ```

  ```
  mutation {
    insertEquipment (
      id: "laptop",
      used_by: "developer",
      count: 17,
      new_or_used: "new"
    ) {
      id
      used_by
      count
      new_or_used
    }
  }
  ```

## Equipment 데이터 수정하기

- Mutation - 수정 루트 타입

  ```
  type Mutation {
    editEquipment(
        id: String,
        used_by: String,
        count: Int,
        new_or_used: String
    ): Equipment
    ...
  }
  ```

  - 수정할 Equipment의 요소 값들을 인자로 받고 추가된 Equipment를 반환

- 수정 resolver

  ```
  Mutation: {
    // ...
    editEquipment: (parent, args, context, info) => {
        return database.equipments.filter((equipment) => {
            return equipment.id === args.id
        }).map((equipment) => {
            Object.assign(equipment, args)
            return equipment
        })[0]
    },
    // ...
  }
  ```

  ```
  mutation {
    editEquipment (
      id: "pen tablet",
      new_or_used: "new",
      count: 30,
      used_by: "designer"
    ) {
      id
      new_or_used
      count
      used_by
    }
  }
  ```
