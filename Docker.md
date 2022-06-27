# Docker

## Docker Registry

- “Docker 이미지 저장소”를 뜻하는 말
  - 공식 저장소로서 Docker Hub (Docker계의 GitHub)
  - 컨테이너 생성 시에 지정 이름의 이미지가 로컬에 없다면, Docker Registry로부터 이미지를 즉시 다운받습니다.
  - 혹은 다운받는 명령 (docker pull)으로 미리 받아두어도 OK.
- 이 외에 각 클라우드 벤더에서 저장소 지원
  - Azure Container Registry
  - AWS Elastic Container Registry
  - Google Container Registry
  - 혹은 사설 저장소 : Nexus 3, GitLab을 활용하거나, 도커 서비스로도 가능.

## docker image name

- python:3.7
  - repository:tag 형식
- repository hostname/accountname/name 구조
  - 저장소 서버의 주소를 포함한 이미지의 이름
  - name 으로 쓸 경우 : Docker Hub에 공개된 공식 이미지 → nginx
  - accountname/name 으로 쓸 경우 : Docker Hub에 공개된 일반 유저의 이미지 → askcompany/nginx
  - hostname/accountname/name : 다른 Docker Registry에 공개된 이미지 → myregistry.azurecr.io/samples/nginx
- tag
  - 대개 도커 이미지의 버전을 지정하는 용도로 사용합니다.
  - 문자열 타입. 숫자로서 쓰더라도 정렬의 개념은 존재하지 않습니다.
  - tag를 생략하면 latest → 단순히 디폴트 이름일 뿐, 최근 버전을 자동으로 지정하는 기능이 아닙니다

## Container Orchestration

- 컨테이너 관리 툴의 필요성
  - 툴이 다수의 서버에 컨테이너를 배포하고 운영하면서 Service Discovery 등의 기능을 통해, 서비스간 연결을 쉽게 해주기
  - 사람이 일일이 서버마다 이름을 붙여주고, 하나하나 접속하여 관리하는 개념이 X
  - 컨테이너 자동 배치 및 복제, 컨테이너 그룹에 대한 로드 밸런싱, 컨테이너 장애 복구, 클러스터 외부에 서비스 노출, 컨테이너
  - 추가 또는 제거로 확장 및 축소, 컨테이너 서비스 간의 인터페이스를 통한 연결 및 네트워크 포트 노출 제어
- 패러다임의 변화
  - 물리머신, VM 기반 ➔ 컨테이너 기반
  - 애지중지 OS 설치, 라이브러리 업데이트, 소스 업데이트 ➔ 컨테이너 단위로 배포

## AWS 에서의 Docker Container Orchestation

- Elastic Container Registry : Docker Registry 관리형 서비스
- Fargate : ECS/EKS에서 구동. 리소스 제어권을 AWS에 위임
- Elastic Container Service : AWS만의 EC2 컨테이너 서비스
- Elastic Kubernetes Service : k8s 관리형 서비스
- Elastic Beanstalk : PaaS 플랫폼이라고 이야기하지만, 저는 동의 X. 자동화된 IaaS.
- AWS Lambda : Serverless 플랫폼. AWS에서 직접 운영하는 VM에서 구동. Docker 지원 X.

## Dockerfile

- Docker 이미지를 만들 때, 수행할 명령과 설정들을 시간 순으로 기술한 파일
  - 아래는 개발 서버를 구동시켰습니다. 실서비스에서는 gunicorn이나 uwsgi를 사용합니다.

```
FROM ubuntu:18.04

RUN apt-get update && apt-get install -y python3-pip python3-dev && apt-get clean

WORKDIR /code
ADD ./backend/requirements.txt /code/
RUN pip3 install -r requirements.txt
ADD ./backend /code/
------------------------------------- # 빌드 시 실행할 명령어
EXPOSE 8000
CMD ["python3", "/code/manage.py", "runserver", "0.0.0.0:8000"]
------------------------------------- # run명령어 실행 시에 실행
```
