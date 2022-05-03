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

# 서버 구성요소 모듈화

## apoolo-server 생성자 인자 모듈화

- [apoolo-server](https://www.apollographql.com/docs/apollo-server/api/apollo-server/) 문서 참조
- typeDefs: 단일 변수 또는 배열로 지정 가능
- resolvers: 단일 Object 또는 Merge 된 배열로 가능

typedefs-resolvers/\_queries.js

```js
// ...
const typeDefs = gql`
  type Query {
    equipments: [Equipment]
  }
`;
// ...
```

typedefs-resolvers/\_mutations.js

```js
// ...
const typeDefs = gql`
  type Mutation {
    deleteEquipment(id: String): Equipment
  }
`;
// ...
```

typedefs-resolvers/equipments.js

```js
// ...
const typeDefs = gql`
  type Equipment {
    id: String
    used_by: String
    count: Int
    new_or_used: String
  }
`;
const resolvers = {
  Query: {
    equipments: (parent, args) => dbWorks.getEquipments(args),
  },
  Mutation: {
    deleteEquipment: (parent, args) => dbWorks.deleteItem("equipments", args),
  },
};
// ...
```

typedefs-resolvers/index.js

```js
// ...
const queries = require('./typedefs-resolvers/_queries')
const mutations = require('./typedefs-resolvers/_mutations')
const equipments = require('./typedefs-resolvers/equipments'
// ...
const typeDefs = [
    queries,
    mutations,
    equipments.typeDefs,
]
const resolvers = [
    equipments.resolvers
]
// ...
```

## dbWorks.js 살펴보기

- Resolver에 사용할 기능들 모듈화

## Supply 모듈 추가해보기

typedefs-resolvers/supplies.js

```js
const typeDefs = gql`
  type Supply {
    id: String
    team: Int
  }
`;
const resolvers = {
  Query: {
    supplies: (parent, args) => dbWorks.getSupplies(args),
  },
  Mutation: {
    deleteSupply: (parent, args) => dbWorks.deleteItem("supplies", args),
  },
};
```

typedefs-resolvers/\_queries.js

```js
// ...
const typeDefs = gql`
    type Query {
        ...
        supplies: [Supply]
    }
`;
// ...
```

typedefs-resolvers/\_mutations.js

```js
// ...
const typeDefs = gql`
    type Mutation {
        ...
        deleteSupply: [Supply]
    }
`;
// ...
```

typedefs-resolvers/index.js

```js
// ...
const supplies = require("./typedefs-resolvers/supplies");
// ...
const typeDefs = [
  // ...
  supplies.typeDefs,
];
const resolvers = [
  // ...
  supplies.resolvers,
];
// ...
```

# GraphQL의 기본 타입들

## 스칼라 타입

- GraphQL 내장 자료형

```js
type EquipmentAdv {
    id: ID!
    used_by: String!
    count: Int!
    use_rate: Float
    is_new: Boolean!
}
```

| 타입      | 설명                                                 |
| --------- | ---------------------------------------------------- |
| ID        | 기본적으로는 String이나, 고유 식별자 역할임을 나타냄 |
| String    | UTF-8 문자열                                         |
| Int       | 부호가 있는 32비트 정수                              |
| Float     | 부호가 있는 부동소수점 값                            |
| Boolean   | 참/거짓                                              |
| !(느낌표) | null을 반환할 수 없음                                |

equipments.js

```js
const resolvers = {
  Query: {
    // ...
    equipmentAdvs: (parent, args) =>
      dbWorks.getEquipments(args).map((equipment) => {
        if (equipment.used_by === "developer") {
          equipment.use_rate = Math.random().toFixed(2);
        }
        equipment.is_new = equipment.new_or_used === "new";
        return equipment;
      }),
  },
  // ...
};
```

\_queries.js

```js
type Query {
    ...
    equipmentAdvs: [EquipmentAdv]
    ...
}
```

```
query {
    equipmentAdvs {
        id
        used_by
        count
        use_rate
        is_new
    }
}
```

## 열거 타입

- 미리 지정된 값들 중에서만 반환

\_enums.js

```js
const { gql } = require("apollo-server");
const typeDefs = gql`
  enum Role {
    developer
    designer
    planner
  }
  enum NewOrUsed {
    new
    used
  }
`;
module.exports = typeDefs;
```

index.js

```js
// ...
const enums = require("./typedefs-resolvers/_enums");
// ...
const typeDefs = [
  // ...
  enums,
  // ...
];
```

equipments.js

```js
const typeDefs = gql`
  type Equipment {
    id: ID!
    used_by: Role!
    count: Int!
    new_or_used: NewOrUsed!
  }
  type EquipmentAdv {
    id: ID!
    used_by: Role!
    count: Int!
    use_rate: Float
    is_new: Boolean!
  }
`;
```

```
query {
  equipments {
    id
    used_by
    count
    new_or_used
  }
	equipmentAdvs {
    id
    used_by
    count
    use_rate
    is_new
  }
}
```

## 리스트 타입

- 특정 타입의 배열을 반환

equipments.js

```js
const typeDefs = gql`
    // ...
    type EquipmentAdv {
        id: ID!
        used_by: Role!
        count: Int!
        use_rate: Float
        is_new: Boolean!,
        users: [String!]
    }
`;
// ...
const resolvers = {
  Query: {
    // ...
    equipmentAdvs: (parent, args) =>
      dbWorks.getEquipments(args).map((equipment) => {
        if (equipment.used_by === "developer") {
          equipment.use_rate = Math.random().toFixed(2);
        }
        equipment.is_new = equipment.new_or_used === "new";
        if (Math.random() > 0.5) {
          equipment.users = [];
          dbWorks.getPeople(args).forEach((person) => {
            if (person.role === equipment.used_by && Math.random() < 0.2) {
              equipment.users.push(person.last_name);
            }
          });
        }
        return equipment;
      }),
  },
  // ...
};
```

```
query {
	equipmentAdvs {
    id
    used_by
    count
    use_rate
    is_new
    users
  }
}
```

| 선언부     | users: null | users: [ ] | users: [..., null] |
| ---------- | ----------- | ---------- | ------------------ |
| [String]   | ✔           | ✔          | ✔                  |
| [String!]  | ✔           | ✔          | ❌                 |
| [String]!  | ❌          | ✔          | ✔                  |
| [String!]! | ❌          | ✔          | ❌                 |

# 유니언과 스페이스

## Union

- 타입 여럿을 한 배열에 반환하고자 할 때 사용

## Equipment와 Supply를 함께 반환하기

givens.js

```js
const { gql } = require("apollo-server");
const dbWorks = require("../dbWorks.js");
const typeDefs = gql`
  union Given = Equipment | Supply
`;
const resolvers = {
  Query: {
    givens: (parent, args) => {
      return [...dbWorks.getEquipments(args), ...dbWorks.getSupplies(args)];
    },
  },
  Given: {
    __resolveType(given, context, info) {
      if (given.used_by) {
        return "Equipment";
      }
      if (given.team) {
        return "Supply";
      }
      return null;
    },
  },
};
module.exports = {
  typeDefs: typeDefs,
  resolvers: resolvers,
};
```

\_queries.js

```js
const typeDefs = gql`
    type Query {
        // ...
        givens: [Given]
    }
`;
```

index.js

```js
// ...
const givens = require("./typedefs-resolvers/givens");
// ...
const typeDefs = [
  // ...
  givens.typeDefs,
];
// ...
const resolvers = [
  // ...
  givens.resolvers,
];
// ...
```

```
query {
  givens {
    __typename
    ... on Equipment {
      id
      used_by
      count
      new_or_used
    }
    ... on Supply {
      id
      team
    }
  }
}
```

## interface

- 유사한 객체 타입을 만들기 위한 공통 필드 타입
- 추상 타입 - 다른 타입에 implement 되기 위한 타입

```
type Equipment {
    id: ID!
    used_by: Role!
    count: Int
    new_or_used: NewOrUsed!
}
...
type Software {
    id: ID!
    used_by: Role!
    developed_by: String!
    description: String
}
```

- 공통적으로 가진 필드: id, used_by

tools.js

```js
const { gql } = require("apollo-server");
const typeDefs = gql`
  interface Tool {
    id: ID!
    used_by: Role!
  }
`;
const resolvers = {
  Tool: {
    __resolveType(tool, context, info) {
      if (tool.developed_by) {
        return "Software";
      }
      if (tool.new_or_used) {
        return "Equipment";
      }
      return null;
    },
  },
};
module.exports = {
  typeDefs: typeDefs,
  resolvers: resolvers,
};
```

equipments.js

```js
type Equipment implements Tool {
    id: ID!
    used_by: Role!
    count: Int
    new_or_used: NewOrUsed!
}
```

equipments.js

```js
type Software implements Tool {
    id: ID!
    used_by: Role!
    developed_by: String!
    description: String
}
```

index.js

```js
// ...
const tools = require("./typedefs-resolvers/tools");
// ...
const typeDefs = [
  // ...
  tools.typeDefs,
];
// ...
const resolvers = [
  // ...
  tools.resolvers,
];
// ...
```

```
query {
  equipments {
    id
    used_by
    count
    new_or_used
  }
  softwares {
    id
    used_by
    description
    developed_by
  }
}
```

### People 쿼리에 적용

people.js

```js
const { gql } = require("apollo-server");
const dbWorks = require("../dbWorks.js");
const typeDefs = gql`
  type People {
    id: ID!
    first_name: String!
    last_name: String!
    sex: Sex!
    blood_type: BloodType!
    serve_years: Int!
    role: Role!
    team: ID!
    from: String!
    tools: [Tool]
    givens: [Given]
  }
`;
const resolvers = {
  Query: {
    people: (parent, args) => dbWorks.getPeople(args),
    person: (parent, args) => dbWorks.getPeople(args)[0],
  },
};
module.exports = {
  typeDefs: typeDefs,
  resolvers: resolvers,
};
```

\_queries.js

```js
const typeDefs = gql`
    type Query {
        people: [People],
        // ...
    }
`;
```

index.js

```js
// ...
const people = require("./typedefs-resolvers/people");
// ...
const typeDefs = [
  // ...
  people.typeDefs,
];
// ...
const resolvers = [
  // ...
  people.resolvers,
];
// ...
```

```
query {
  people {
    id
    first_name
    last_name
    givens {
        __typename
    	... on Equipment {
      	id
      	used_by
      	count
      	new_or_used
    	}
    	... on Supply {
      	id
      	team
    	}
  	}
    tools {
      __typename
      ... on Equipment {
        id
        used_by
        count
        new_or_used
      }
      ... on Software {
        id
        used_by
        description
        developed_by
      }
    }
  }
}
```

# 인자와 인풋 타입

## People 데이터 조건들로 필터 넣어 받아오기

\_queries.js

```js
type Query {
    ...
    peopleFiltered(
        team: Int,
        sex: Sex,
        blood_type: BloodType,
        from: String
    ): [People]
    ...
}
```

people.js

```js
Query: {
  // ...
  peopleFiltered: (parent, args) => dbWorks.getPeople(args),
}
```

```
query {
  peopleFiltered (
    team: 1
    blood_type: B
    from: "Texas"
  ) {
    id
    first_name
    last_name
    sex
    blood_type
    serve_years
    role
    team
    from
  }
}
```

## 페이지로 나누어 받아오기

\_queries.js

```js
type Query {
    ...
    peoplePaginated(
        page: Int!,
        per_page: Int!
    ): [People]
    ...
}
```

people.js

```js
Query: {
    // ...
    peoplePaginated: (parent, args) => dbWorks.getPeople(args),
    // ...
}
```

```
query {
	peoplePaginated(page: 1, per_page: 7) {
    id
    first_name
    last_name
    sex
    blood_type
    serve_years
    role
    team
    from
  }
}
```

## 별칭으로 받아오기

```js
query {
  badGuys: peopleFiltered(sex: male, blood_type: B) {
    first_name
    last_name
    sex
    blood_type
  }
  newYorkers: peopleFiltered(from: "New York") {
    first_name
    last_name
    from
  }
}
```

## 인풋 타입

people.js

```
const typeDefs = gql`
    ....
    input PostPersonInput {
        first_name: String!
        last_name: String!
        sex: Sex!
        blood_type: BloodType!
        serve_years: Int!
        role: Role!
        team: ID!
        from: String!
    }
`
const resolvers = {
    // ...
    Mutation: {
        postPerson: (parent, args) => dbWorks.postPerson(args),
    }
}
```

\_mutation.js

```js
type Mutation {
    postPerson(input: PostPersonInput): People!
    ...
}
```

```
mutation {
  postPerson(input: {
    first_name: "Hanna"
    last_name: "Kim"
    sex: female
    blood_type: O
    serve_years: 3
    role: developer
    team: 1
    from: "Pusan"
  }) {
    id
    first_name
    last_name
    sex
    blood_type
    role
    team
    from
  }
}
```

# React와 Apollo Client

App.js

| 코드     | 설명                                                 |
| -------- | ---------------------------------------------------- |
| NavMenus | menu값에 따라 상단 App-header의 버튼을 표시하는 함수 |
| mainComp | App-header 아래 메인 화면에 나타날 컴포넌트 매핑     |

roles.js, teams.js, people.js

| 코드         | 설명                        | 비고                                |
| ------------ | --------------------------- | ----------------------------------- |
| AsideItems   | 메인화면 왼쪽의 사이드 섹션 | 리스트가 나타날 곳                  |
| MainContents | 메인화면                    | 리스트 각 항목의 내용부가 표시될 곳 |

## Apollo Client 사용하기

- [아폴로 클라이언트 문서](https://www.apollographql.com/docs/react/get-started/)

아폴로 클라이언트 모듈 적용

```
npm install @apollo/client graphql
```

App.js

```js
// ...
import { ApolloProvider } from "@apollo/client";
import { ApolloClient, InMemoryCache } from "@apollo/client";
// ...
```

- ApolloClient 모듈 임포트

App.js

```js
// ...
const client = new ApolloClient({
  uri: "http://localhost:4000",
  cache: new InMemoryCache(),
});
// ...
```

| 코드   | 설명                                               |
| ------ | -------------------------------------------------- |
| client | GraphQL 서버로와 정보를 주고받을 ApolloClient 객체 |
| uri    | GraphQL 서버의 주소                                |
| cache  | InMemoryCache를 통한 캐시 관리                     |

```js
//   ...
return (
  <div className="App">
    <ApolloProvider client={client}>
      <header className="App-header">
        <h1>Company Management</h1>
        <nav>
          <ul>{NavMenus()}</ul>
        </nav>
      </header>
      <main>{mainComp[menu]}</main>
    </ApolloProvider>
  </div>
);
//   ...
```

- 내부 요소들을 ApolloProvider 로 감싸준다.

## GraphQL 서버로부터 목록 받아와 표시하기

roles.js

```js
// ...
import { useState } from "react";
import { useQuery, gql } from "@apollo/client";
// ...
```

- 필요한 모듈들 임포트

roles.js

```js
// ...
const GET_ROLES = gql`
  query GetRoles {
    roles {
      id
    }
  }
`;
// ...
```

- 쿼리 작성

roles.js

```js
// ...
const [contentId, setContentId] = useState("");
// ...
```

- 렌더링될 컨텐츠 id를 저장할 state 지정

roles.js

```js
// ...
function AsideItems() {
  const roleIcons = {
    developer: "💻",
    designer: "🎨",
    planner: "📝",
  };
  const { loading, error, data } = useQuery(GET_ROLES);
  if (loading) return <p className="loading">Loading...</p>;
  if (error) return <p className="error">Error :(</p>;
  return (
    <ul>
      {data.roles.map(({ id }) => {
        return (
          <li
            key={id}
            className={"roleItem " + (contentId === "id" ? "on" : "")}
            onClick={() => {
              setContentId(id);
            }}
          >
            <span>{contentId === id ? "🔲" : "⬛"}</span>
            {roleIcons[id]} {id}
          </li>
        );
      })}
    </ul>
  );
}
// ...
```

- AsideItems 함수에서, GraphQL로부터 데이터를 받아와 목록을 렌더링하도록 작성

| 코드    | 설명                                       |
| ------- | ------------------------------------------ |
| loading | GraphQL 서버에서 정보를 받아오는 동안 표시 |
| error   | 요청에 오류가 발생할 시 반환               |
| data    | GraphQL 요청대로 받아진 정보               |

## GraphQL 서버로부터 id로 컨텐츠 받아와 표시하기

roles.js

```js
// ...
const GET_ROLE = gql`
  query GetRole($id: ID!) {
    role(id: $id) {
      id
      requirement
      members {
        id
        last_name
        serve_years
      }
      equipments {
        id
      }
      softwares {
        id
      }
    }
  }
`;
// ...
```

- 쿼리 작성

roles.js

```js
function MainContents() {
  const { loading, error, data } = useQuery(GET_ROLE, {
    variables: { id: contentId },
  });

  if (loading) return <p className="loading">Loading...</p>;
  if (error) return <p className="error">Error :(</p>;
  if (contentId === "") return <div className="roleWrapper">Select Role</div>;

  return (
    <div className="roleWrapper">
      <h2>{data.role.id}</h2>
      <div className="requirement">
        <span>{data.role.requirement}</span> required
      </div>
      <h3>Members</h3>
      <ul>
        {data.role.members.map((member) => {
          return <li>{member.last_name}</li>;
        })}
      </ul>
      <h3>Equipments</h3>
      <ul>
        {data.role.equipments.map((equipment) => {
          return <li>{equipment.id}</li>;
        })}
      </ul>
      <h3>Softwares</h3>
      {data.role.softwares.map((software) => {
        return <li>{software.id}</li>;
      })}
      <ul></ul>
    </div>
  );
}
```

# Query와 Mutation을 사용하여 웹페이지 만들기

모듈 로드

```js
// ...
import { useState } from "react";
import { useQuery, useMutation, gql } from "@apollo/client";
// ...
```

state 준비

```js
// ...
const [contentId, setContentId] = useState(0);
const [inputs, setInputs] = useState({
  manager: "",
  office: "",
  extension_number: "",
  mascot: "",
  cleaning_duty: "",
  project: "",
});
// ...
```

## 팀 목록 받아오기

쿼리 작성

```js
// ...
const GET_TEAMS = gql`
  query GetTeams {
    teams {
      id
      manager
      members {
        id
        first_name
        last_name
        role
      }
    }
  }
`;
// ...
```

목록 받아와 보여주기 함수

```js
// ...
function AsideItems() {
  const roleIcons = {
    developer: "💻",
    designer: "🎨",
    planner: "📝",
  };

  const { loading, error, data, refetch } = useQuery(GET_TEAMS);

  if (loading) return <p className="loading">Loading...</p>;
  if (error) return <p className="error">Error :(</p>;

  return (
    <ul>
      {data.teams.map(({ id, manager, members }) => {
        return (
          <li key={id}>
            <span
              className="teamItemTitle"
              onClick={() => {
                setContentId(id);
              }}
            >
              Team {id} : {manager}'s
            </span>
            <ul className="teamMembers">
              {members.map(({ id, first_name, last_name, role }) => {
                return (
                  <li key={id}>
                    {roleIcons[role]} {first_name} {last_name}
                  </li>
                );
              })}
            </ul>
          </li>
        );
      })}
    </ul>
  );
}
// ...
```

## 항목 받아오기

쿼리 작성

```js
// ...
const GET_TEAM = gql`
  query GetTeam($id: ID!) {
    team(id: $id) {
      id
      manager
      office
      extension_number
      mascot
      cleaning_duty
      project
    }
  }
`;
// ...
```

항목 받아와 보여주기 함수

```js
// ...
function MainContents() {
  const { loading, error } = useQuery(GET_TEAM, {
    variables: { id: contentId },
    onCompleted: (data) => {
      if (contentId === 0) {
        setInputs({
          manager: "",
          office: "",
          extension_number: "",
          mascot: "",
          cleaning_duty: "",
          project: "",
        });
      } else {
        setInputs({
          manager: data.team.manager,
          office: data.team.office,
          extension_number: data.team.extension_number,
          mascot: data.team.mascot,
          cleaning_duty: data.team.cleaning_duty,
          project: data.team.project,
        });
      }
    },
  });

  if (loading) return <p className="loading">Loading...</p>;
  if (error) return <p className="error">Error :(</p>;

  function handleChange(e) {
    const { name, value } = e.target;
    setInputs({
      ...inputs,
      [name]: value,
    });
  }

  return (
    <div className="inputContainer">
      <table>
        <tbody>
          {contentId !== 0 && (
            <tr>
              <td>Id</td>
              <td>{contentId}</td>
            </tr>
          )}
          <tr>
            <td>Manager</td>
            <td>
              <input
                type="text"
                name="manager"
                value={inputs.manager}
                onChange={handleChange}
              />
            </td>
          </tr>
          <tr>
            <td>Office</td>
            <td>
              <input
                type="text"
                name="office"
                value={inputs.office}
                onChange={handleChange}
              />
            </td>
          </tr>
          <tr>
            <td>Extension Number</td>
            <td>
              <input
                type="text"
                name="extension_number"
                value={inputs.extension_number}
                onChange={handleChange}
              />
            </td>
          </tr>
          <tr>
            <td>Mascot</td>
            <td>
              <input
                type="text"
                name="mascot"
                value={inputs.mascot}
                onChange={handleChange}
              />
            </td>
          </tr>
          <tr>
            <td>Cleaning Duty</td>
            <td>
              <input
                type="text"
                name="cleaning_duty"
                value={inputs.cleaning_duty}
                onChange={handleChange}
              />
            </td>
          </tr>
          <tr>
            <td>Project</td>
            <td>
              <input
                type="text"
                name="project"
                value={inputs.project}
                onChange={handleChange}
              />
            </td>
          </tr>
        </tbody>
      </table>
      {contentId === 0 ? (
        <div className="buttons">
          <button onClick={() => {}}>Submit</button>
        </div>
      ) : (
        <div className="buttons">
          <button onClick={() => {}}>Modify</button>
          <button onClick={() => {}}>Delete</button>
          <button
            onClick={() => {
              setContentId(0);
            }}
          >
            New
          </button>
        </div>
      )}
    </div>
  );
}
//   ...
```

## 항목 삭제하기

쿼리 & 함수 작성

```js
// ...
const DELETE_TEAM = gql`
  mutation DeleteTeam($id: ID!) {
    deleteTeam(id: $id) {
      id
    }
  }
`;
// ...
function execDeleteTeam() {
  if (window.confirm("이 항목을 삭제하시겠습니까?")) {
    deleteTeam({ variables: { id: contentId } });
  }
}
const [deleteTeam] = useMutation(DELETE_TEAM, {
  onCompleted: deleteTeamCompleted,
});
function deleteTeamCompleted(data) {
  console.log(data.deleteTeam);
  alert(`${data.deleteTeam.id} 항목이 삭제되었습니다.`);
  setContentId(0);
}
// ...
```

버튼에 적용

```js
// ...
<button onClick={execDeleteTeam}>Delete</button>
// ...
```

수정된 데이터 다시 로드

```js
// ...
let refetchTeams;
// ...
refetchTeams = refetch;
// ...
alert(`${data.deleteTeam.id} 항목이 삭제되었습니다.`);
refetchTeams();
// ...
```

## 항목 수정하기

```js
// ...
const EDIT_TEAM = gql`
  mutation EditTeam($id: ID!, $input: PostTeamInput!) {
    editTeam(id: $id, input: $input) {
      id
      manager
      office
      extension_number
      mascot
      cleaning_duty
      project
    }
  }
`;
// ...
function execEditTeam() {
  editTeam({
    variables: {
      id: contentId,
      input: inputs,
    },
  });
}
const [editTeam] = useMutation(EDIT_TEAM, { onCompleted: editTeamCompleted });
function editTeamCompleted(data) {
  console.log(data.editTeam);
  alert(`${data.editTeam.id} 항목이 수정되었습니다.`);
  refetchTeams();
}
//   ...
<button onClick={execEditTeam}>Modify</button>;
//   ...
```

## 항목 추가하기

```js
// ...
const POST_TEAM = gql`
  mutation PostTeam($input: PostTeamInput!) {
    postTeam(input: $input) {
      id
      manager
      office
      extension_number
      mascot
      cleaning_duty
      project
    }
  }
`;
// ...
function execPostTeam() {
  postTeam({
    variables: { input: inputs },
  });
}

const [postTeam] = useMutation(POST_TEAM, { onCompleted: postTeamCompleted });
j;
function postTeamCompleted(data) {
  console.log(data.postTeam);
  alert(`${data.postTeam.id} 항목이 생성되었습니다.`);
  refetchTeams();
  setContentId(0);
}
//   ...
<button onClick={execPostTeam}>Submit</button>;
// ...
```

# Fragment 사용하기

- 여러 쿼리에 사용될 수 있는, 재사용 가능한 필드셋
- 중복을 줄임으로써 전체 코드를 간소화

재사용되는 요소들 fragment로 분리

```js
const Names = gql`
  fragment names on People {
    first_name
    last_name
  }
`;
const HealthInfo = gql`
  fragment healthInfo on People {
    sex
    blood_type
  }
`;
const WorkInfo = gql`
  fragment workInfo on People {
    serve_years
    role
    team
    from
  }
`;
```

쿼리들에 적용

```js
const GET_PEOPLE = gql`
  query GetPeople {
    people {
      id
      ...names
      ...healthInfo
    }
  }
  ${Names}
  ${HealthInfo}
`;
```

```js
const GET_PERSON = gql`
  query GetPerson($id: ID!) {
    person(id: $id) {
      id
      ...names
      ...healthInfo
      ...workInfo
      tools {
        __typename
        ... on Software {
          id
        }
        ... on Equipment {
          id
          count
        }
      }
    }
  }
  ${Names}
  ${HealthInfo}
  ${WorkInfo}
`;
```
