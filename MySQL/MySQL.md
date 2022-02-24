<img src="https://user-images.githubusercontent.com/96982072/155348732-dacac186-1fb6-4d11-bf43-f22cc5393ab5.jpg" width=800px/>

# 소개  

RDBMS(Relational Database Management System), 관계형 데이터베이스 관리 시스템이다.  
데이터베이스는 특정 소프트웨어나 프로그램에 종속되지 않고 독립된 정보의 집합, 저장소이다.  
데이터베이스만 있다면 그저 창고, 저장소 역할만 할 뿐이지만  
SQL(Structed Query Language)인 구조화 질의 언어를 사용하여 표 형태의 데이터베이스에서  
정보를 넣고, 빼고, 조작할 수 있다.  

현재 많이 사용하고 있는 데이터베이스들을 보여주는 페이지가 있다.  
[DB-engines](https://db-engines.com/en/ranking)   

# CRUD

데이터베이스를 다룰 때의 핵심은 CRUD이다.  
CRUD는 Create, Read, Update, Delete 첫글자의 약자이다.  
정보를 입력하고 출력하는 과정에서 CRUD를 어떻게 다루르냐에 따라  
여러가지 툴을 배울 필요없이 데이터베이스의 본질을 파악하고 자유롭게 사용할 수 있다.  

# File vs Database

단순하게 데이터를 파일을 사용해서 쉽고 편리하게 보관, 관리, 전송할 수 있지만  
파일이 수 없이 많아질 경우 원하는 정보만 찾아 꺼내쓰기 힘들어진다.  
데이터를 잘 정리정돈해서 꺼내쓰기 쉽게하기 위해 데이터베이스가 개발되었다.  
데이터베이스를 사용하면 프로그래밍 언어를 통해  
사람이 일일히 작성하지않고도 자동으로 CRUD가 가능해진다.  

# MySQL - 기본

## MySQL의 구조

MySQL에서 스키마(Schema)는 연관된 데이터를 그룹핑할때 사용하는 용어이다.  
표 형태의 데이터를 그룹화한 데이터베이스 형태이다. 
데이터베이스가 스키마라고 볼 수 있다.  
또 스키마가 많아지면 스키마들을 모아서 저장해야하는데 이것을 데이터베이스 서버라고 부른다.  
우리는 데이터베이스 서버로 MySQL을 설치한 것이고  
MySQL이 가지고 있는 여러가지 기능을 이용해서 작업을 할 예정이다.  

## MySQL 서버 접속

데이터베이스를 사용해서 얻을 수 있는 첫번째 효용은 보안이다.  
자체적인 보안체계를 가지고 있어 안전하게 사용할 수 있다.  
그 외에도 권한기능이 있어 특정 사용자에게 차등적으로 권한을 배분해  
특정 데이터에만 접근하게 할 수 있다.  

```
mysql -uroot -p
```
루트계정의 관리자 비밀번호로 서버에 접속할 수 있다.  

## mySQL 스키마의 사용  

서버에 접속한 후 새로운 데이터베이스를 생성하려면
```
CREATE DATABASE (db이름);
```
끝에 세미콜론(;)을 사용해 데이터베이스를 생성할 수 있다.  

반대로 데이터베이스를 삭제하려면  
```
DROP DATABASE (db이름);
```
명령어를 이용해 데이터베이스를 삭제할 수 있다.  
만들어진 데이터베이스를 보려면
```
SHOW DATABASES;
```
사용해서 현재목록에 있는 데이터베이스를 확인할 수 있고
데이터베이스를 사용하고싶으면
```
USE (db이름);
```
해당 DB를 사용할 수 있다.  

명령어가 참 직관적이라 좋다!  

# MySQL 테이블 생성

SQL을 이용해서 테이블을 생성, 수정, 삭제하는 방법을 알아본다.  

## 테이블 생성

```
CREATE TABLE topic(
    column1 type [(NOT) NULL] [AUTO_INCREMENT],
    column2 type [(NOT) NULL] [AUTO_INCREMENT],
    ...
    PRIMARY KEY(id));
);
```
테이블 생성 예시이다. 프롬프트에서 `CREATE TABLE topic(`을 입력하고  
세미콜론(`;`)을 입력하지 않는 이상 엔터를 입력해 계속 행을 바꿔서 작성해 나갈 수 있다.  

`column`에는 열의 이름이 오고 `type`에는 자료형으로  
`varchar()`를 이용해 문자가 오게할 수 있고, `INT()`를 이용해 숫자가 오게할 수 있다.  
만약에 입력한 자료형외의 다른 형태가 입력되면 데이터베이스는 작동하지 않는다.  

`[(NOT) NULL]` 부분은 내용이 반드시 있어야한다면 `NOT NULL`을,  
비워져 있어도 괜찮다면 `NULL`을 입력한다.  

`[AUTO_INCREMENT]`에서 column의 값이 중복되지않게 자동으로 1씩 증가하게 해준다.  

이렇게 입력하고 `,`입력하고 엔터를 입력해 다음 열의 값과 옵션을 작성할 수 있다.  
옵션을 입력하고 마지막에 PRIMARY KEY를 지정해 열의 첫번째에 id를 지정해 중복이 없게 한다.  
아래는 예제를 통해 입력해 본 예시다.  

```
CREATE TABLE topic(
    -> id INT(11) NOT NULL AUTO_INCREMENT,
    -> title VARCHAR(100) NOT NULL,
    -> description TEXT NULL,
    -> created DATETIME NOT NULL,
    -> author VARCHAR(15) NULL,
    -> profile VARCHAR(200) NULL,
    -> PRIMARY KEY(id));
```
정상적으로 입력을 끝내면 `Query OK`를 출력한다.  
```
SHOW TABLES;
```
명령어를 통해서 테이블이 잘 만들어졌는지 확인 할 수 있다.  

# MySQL - CRUD  

## INSERT INTO - 생성

들어가기 앞서 열의 이름이 무엇인지 기억나지 않는다면
```
DESC (db이름);
```
명령어를 통해 작성했던 table의 column이름을 출력한다.  
그 다음 내용을 작성하기 위해서는 `INSERT INTO` 명령어를 사용한다.  
```
INSERT INTO topic (title,description,created,author,profile) 
VALUES('MySQL','MySQL is ...',NOW(),'egoing','developer');

```
전에 사용했던 topic의 테이블에서 내용을 추가해준 것이다.  
topic의 column에는 id, title, decription, created, author, profile이 있었는데  
id 값은 입력하지않아도 자동으로 1씩 증가하기 때문에 작성하지 않아도 된다.  
그 다음은 `VALUES()`를 적고 괄호 안에  
`VALUES(title, description, created, author, profile);` 의 값을 순서대로 작성하면  
`Query OK` 문구와 함께 작성이 완료된다.  

그 이후로 작성한 내용의 row값은
```
SELECT FROM topic;
```
명령어를 통해 추가된 내용을 확인할 수 있다.  

## SELECT - 조회

위에서 작성된 예제를 통해 여러 내용을 입력한 후 전체 작성된 내용을 보고 싶으면  
```
SELECT * FROM topic;
```
명령어를 입력하면 된다.  

결과
```
+----+-------------+-------------------+---------------------+--------+---------------------------+
| id | title       | description       | created             | author | profile                   |
+----+-------------+-------------------+---------------------+--------+---------------------------+
|  1 | MySQL       | MySQL is ...      | 2022-02-24 21:22:36 | egoing | developer                 |
|  2 | ORACLE      | ORACLE is         | 2022-02-24 21:28:20 | egoing | developer                 |
|  3 | SQL Server  | SQL Server is ... | 2022-02-24 21:29:51 | duru   | data administrator        |
|  4 | PostrgreSQL | PostgreSQL is ... | 2022-02-24 21:31:00 | taeho  | data scientist, developer |
|  5 | MongoDB     | MongoDB is ...    | 2022-02-24 21:31:59 | egoing | developer                 |
+----+-------------+-------------------+---------------------+--------+---------------------------+
```
위에서 작성한 `SELECT * FROM topic;` 에서
`SELECT`와 `FROM`사이의 `*`에서는 column의 이름을 넣어주면 특정 column을 조회할 수 있다.  
이 외의 다양한 `SELECT`에 관한 명령어는  
[MySQL 공식문서 SELECT](https://dev.mysql.com/doc/refman/8.0/en/select.html)에 들어가면 다양한 사용법이 존재한다.  
원하는 행을 조회하는 방법을 살펴보면
```
SELECT id,title,created,author FROM topic WHERE author='egoing';
```  
`FROM`뒤에 `WHERE`과 원하는 `column = 'value'`를 하면 `value`가 포함된 행들을 출력한다.  
그리고 `WHERE`뒤에 오는 명령어로 `ORDER BY`를 사용하면 오름차순, 내림차순등의 정렬이 가능하다.  
```
SELECT id,title,created,author FROM topic WHERE author='egoing' ORDER BY id DESC;
```
결과
```
+----+---------+---------------------+--------+
| id | title   | created             | author |
+----+---------+---------------------+--------+
|  5 | MongoDB | 2022-02-24 21:31:59 | egoing |
|  2 | ORACLE  | 2022-02-24 21:28:20 | egoing |
|  1 | MySQL   | 2022-02-24 21:22:36 | egoing |
+----+---------+---------------------+--------+
```
데이터, 행의 수가 엄청나게 많다면 내용을 전부 가져오면 조회를 하다가 컴퓨터가 멈출 수 있다.
그래서 가져오는 행의 수에 제한을 둘 수도 있다.
```
SELECT id,title,created,author FROM topic WHERE author='egoing' ORDER BY id DESC LIMIT 2;
```
결과
```
+----+--------+---------------------+--------+
| id | title  | created             | author |
+----+--------+---------------------+--------+
|  1 | MySQL  | 2022-02-24 21:22:36 | egoing |
|  2 | ORACLE | 2022-02-24 21:28:20 | egoing |
+----+--------+---------------------+--------+
2 rows in set (0.00 sec)
```

## Update - 수정

```
+----+-------------+-------------------+---------------------+--------+---------------------------+
| id | title       | description       | created             | author | profile                   |
+----+-------------+-------------------+---------------------+--------+---------------------------+
|  1 | MySQL       | MySQL is ...      | 2022-02-24 21:22:36 | egoing | developer                 |
|  2 | ORACLE      | ORACLE is         | 2022-02-24 21:28:20 | egoing | developer                 |
|  3 | SQL Server  | SQL Server is ... | 2022-02-24 21:29:51 | duru   | data administrator        |
|  4 | PostrgreSQL | PostgreSQL is ... | 2022-02-24 21:31:00 | taeho  | data scientist, developer |
|  5 | MongoDB     | MongoDB is ...    | 2022-02-24 21:31:59 | egoing | developer                 |
+----+-------------+-------------------+---------------------+--------+---------------------------+
```
description에 2번째 행의 ORACLE is 에서 `...`을 추가하려면 어떻게 해야 할까?  
`UPDATE`와 `SET`을 이용하면 된다.  
```
UPDATE topic SET description='Oracle is ...' WHERE id = 2;
```
여기서 `WHERE`을 적어주지않으면 모든 행들이 `Oracle is ...` 으로 바뀌게 된다.  
`WHERE`을 꼭 적어주자.  
결과
```
+----+------------+-------------------+---------------------+--------+---------------------------+
| id | title      | description       | created             | author | profile                   |
+----+------------+-------------------+---------------------+--------+---------------------------+
|  1 | MySQL      | MySQL is ...      | 2022-02-24 21:22:36 | egoing | developer                 |
|  2 | Oracle     | Oracle is ...     | 2022-02-24 21:28:20 | egoing | developer                 |
|  3 | SQL Server | SQL Server is ... | 2022-02-24 21:29:51 | duru   | data administrator        |
|  4 | PostgreSQL | PostgreSQL is ... | 2022-02-24 21:31:00 | taeho  | data scientist, developer |
|  5 | MongoDB    | MongoDB is ...    | 2022-02-24 21:31:59 | egoing | developer                 |
+----+------------+-------------------+---------------------+--------+---------------------------+
```

## Delete - 삭제

삭제의 경우는 자주 사용할 일이 없지만 마지막으로 알아보자
```
DELETE FROM topic WHERE id=5;
```
`DELETE`를 사용할 때에도 `WHERE`을 적지 않으면 전체 테이블이 삭제된다.  
삭제할 일이 있다면 `WHERE`을 꼭 적어주자.  

# 관계형 데이터베이스

위의 CRUD까지가 기본적인 데이터베이스가 사용하는 공통적인 명령어였다.
이 후부터는 관계형 데이터베이스는 왜 필요한지에 대해 더 학습해본다.  

## 관계형 데이터베이스의 필요성

```
+----+------------+-------------------+---------------------+--------+---------------------------+
| id | title      | description       | created             | author | profile                   |
+----+------------+-------------------+---------------------+--------+---------------------------+
|  1 | MySQL      | MySQL is ...      | 2022-02-24 21:22:36 | egoing | developer                 |
|  2 | Oracle     | Oracle is ...     | 2022-02-24 21:28:20 | egoing | developer                 |
|  3 | SQL Server | SQL Server is ... | 2022-02-24 21:29:51 | duru   | data administrator        |
|  4 | PostgreSQL | PostgreSQL is ... | 2022-02-24 21:31:00 | taeho  | data scientist, developer |
|  5 | MongoDB    | MongoDB is ...    | 2022-02-24 21:31:59 | egoing | developer                 |
+----+------------+-------------------+---------------------+--------+---------------------------+
```

위의 예제에서 작성한 topic 테이블에서 author와 profile부분에서 분명한 중복이 있다.  
이런 중복들이 셀 수 없이 많아진다면 경제적 낭비와 손해를 불러 일으킨다.  
이러한 문제를 해결하기 위해 id, author, profile을 가지는 테이블을 한개 더 만들어서  
테이블을 분리하면 유지보수가 쉬워지고 내용을 더 명확하게 확인할 수 있다.  
그러나 단점으로는 테이블을 나누게되면 테이블이 분리되기 전 보다 직관적일 수는 없다.  
여기서 관계형 데이터베이스를 이용하면 테이블은 나눠져도 조회할 때는 하나의 테이블로 확인할 수 있다.  

## 테이블 분리하기

전에 사용한 예제는 테이블의 이름을 topic에서 topic_backup으로 변경해주었다.  
```
RENAME TABLE topic TO topic_backup;
```
이 후 테이블을 아래와 같이 만들어 준다.  
```
structure for table `author`
--
 
 
CREATE TABLE `author` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `profile` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`id`)
) 
 
--
-- Dumping data for table `author`
--
 
INSERT INTO `author` VALUES (1,'egoing','developer');
INSERT INTO `author` VALUES (2,'duru','database administrator');
INSERT INTO `author` VALUES (3,'taeho','data scientist, developer');
 
--
-- Table structure for table `topic`
--
 
CREATE TABLE `topic` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(30) NOT NULL,
  `description` text,
  `created` datetime NOT NULL,
  `author_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
)
 
--
-- Dumping data for table `topic`
--
 
INSERT INTO `topic` VALUES (1,'MySQL','MySQL is...','2018-01-01 12:10:11',1);
INSERT INTO `topic` VALUES (2,'Oracle','Oracle is ...','2018-01-03 13:01:10',1);
INSERT INTO `topic` VALUES (3,'SQL Server','SQL Server is ...','2018-01-20 11:01:10',2);
INSERT INTO `topic` VALUES (4,'PostgreSQL','PostgreSQL is ...','2018-01-23 01:03:03',3);
INSERT INTO `topic` VALUES (5,'MongoDB','MongoDB is ...','2018-01-30 12:31:03',1);
```
author와 topic 테이블을 각각 만들어줬다.  
author 테이블  
```
+----+--------+---------------------------+
| id | name   | profile                   |
+----+--------+---------------------------+
|  1 | egoing | developer                 |
|  2 | duru   | database administrator    |
|  3 | taeho  | data scientist, developer |
+----+--------+---------------------------+
```
topic 테이블  
```
+----+------------+-------------------+---------------------+-----------+
| id | title      | description       | created             | author_id |
+----+------------+-------------------+---------------------+-----------+
|  1 | MySQL      | MySQL is...       | 2018-01-01 12:10:11 |         1 |
|  2 | Oracle     | Oracle is ...     | 2018-01-03 13:01:10 |         1 |
|  3 | SQL Server | SQL Server is ... | 2018-01-20 11:01:10 |         2 |
|  4 | PostgreSQL | PostgreSQL is ... | 2018-01-23 01:03:03 |         3 |
|  5 | MongoDB    | MongoDB is ...    | 2018-01-30 12:31:03 |         1 |
+----+------------+-------------------+---------------------+-----------+
```

## JOIN - 관계형 데이터베이스의 핵심

분리된 테이블을 읽을 때 마치 하나의 테이블로 저장되어 있었던 것처럼 읽어올 수 있는  
JOIN에 대해 알아보자.  

이번에 배워볼 예제는 topic 테이블에 있는 author_id와 author 테이블의 id를 연결하는 것이다.
```
SELECT * FROM topic LEFT JOIN author;
```
이렇게 끝날거 같지만 명확한 기준이 없기 때문에 에러가 뜬다.  
```
SELECT * FROM topic LEFT JOIN author ON topic.author_id = author.id;
```
결과
```
+----+------------+-------------------+---------------------+-----------+------+--------+---------------------------+
| id | title      | description       | created             | author_id | id   | name   | profile                   |
+----+------------+-------------------+---------------------+-----------+------+--------+---------------------------+
|  1 | MySQL      | MySQL is...       | 2018-01-01 12:10:11 |         1 |    1 | egoing | developer                 |
|  2 | Oracle     | Oracle is ...     | 2018-01-03 13:01:10 |         1 |    1 | egoing | developer                 |
|  3 | SQL Server | SQL Server is ... | 2018-01-20 11:01:10 |         2 |    2 | duru   | database administrator    |
|  4 | PostgreSQL | PostgreSQL is ... | 2018-01-23 01:03:03 |         3 |    3 | taeho  | data scientist, developer |
|  5 | MongoDB    | MongoDB is ...    | 2018-01-30 12:31:03 |         1 |    1 | egoing | developer                 |
+----+------------+-------------------+---------------------+-----------+------+--------+---------------------------+
```
author_id와 id 값이 연결 되었다. 여기서 더 보기좋게 만드려면 author_id와 id를 빼고 SELECT을 해주면  
```
SELECT id,title,description,created,name,profile FROM topic LEFT JOIN author ON topic.author_id = author.id;
```
이렇게 하면 되겠지만 ambiguous하다는 에러가 뜬다.  
이런 에러가 뜨는 이유는 `SELECT` 이후에 id가 author의 id와 topic의 첫번째열 id가 겹치기 때문에  
모호하다는 에러가 뜨는 것이다.  
```
SELECT topic.id,title,description,created,name,profile FROM topic LEFT JOIN author ON topic.author_id = author.id;
```
이렇게 `id`앞에 `topic.id`를 해주면 출력되는 것을 알 수 있다.  
결과  
```
+----+------------+-------------------+---------------------+--------+---------------------------+
| id | title      | description       | created             | name   | profile                   |
+----+------------+-------------------+---------------------+--------+---------------------------+
|  1 | MySQL      | MySQL is...       | 2018-01-01 12:10:11 | egoing | developer                 |
|  2 | Oracle     | Oracle is ...     | 2018-01-03 13:01:10 | egoing | developer                 |
|  3 | SQL Server | SQL Server is ... | 2018-01-20 11:01:10 | duru   | database administrator    |
|  4 | PostgreSQL | PostgreSQL is ... | 2018-01-23 01:03:03 | taeho  | data scientist, developer |
|  5 | MongoDB    | MongoDB is ...    | 2018-01-30 12:31:03 | egoing | developer                 |
+----+------------+-------------------+---------------------+--------+---------------------------+
```
id값이 어디서 가져온 값인지 정확히 알아보기 위해  
`AS topic_id`를 추가해서 column이름을 바꿔줄 수 있다.
```
SELECT topic.id AS topic_id,title,description,created,name,profile FROM topic LEFT JOIN author ON topic.author_id = author.id;
```
결과 topic_id로 변경했다.  
```
+----------+------------+-------------------+---------------------+--------+---------------------------+
| topic_id | title      | description       | created             | name   | profile                   |
+----------+------------+-------------------+---------------------+--------+---------------------------+
|        1 | MySQL      | MySQL is...       | 2018-01-01 12:10:11 | egoing | developer                 |
|        2 | Oracle     | Oracle is ...     | 2018-01-03 13:01:10 | egoing | developer                 |
|        3 | SQL Server | SQL Server is ... | 2018-01-20 11:01:10 | duru   | database administrator    |
|        4 | PostgreSQL | PostgreSQL is ... | 2018-01-23 01:03:03 | taeho  | data scientist, developer |
|        5 | MongoDB    | MongoDB is ...    | 2018-01-30 12:31:03 | egoing | developer                 |
+----------+------------+-------------------+---------------------+--------+---------------------------+
```  
이렇게 테이블을 분리한다는 것은 다른 테이블로 1:1로 연결하는 것이 아닌  
여러 테이블에서 author_id 값만 존재한다면 1:다수로 연결할 수 있다는 것이 핵심이다.  
















