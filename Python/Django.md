# 기본 생성된 파일/디렉터리 목록

mysite : 프로젝트명으로 생성된 디렉토리. 다른 이름으로 변경해도 문제없음

manage.py : 명령행을 통해 각종 장고 명령을 수행

mysite : 프로젝트명으로 생성된 디렉토리. 이 이름을 참조하고 있는 코드가 몇개 있기에 함부로 수정하면 안됨

`__init__.py` : 모든 파이썬 패키지에는 init.py를 둔다. 패키지를 임포트할 때의 임포트 대상

settings.py : 현재 프로젝트에서 장고 기본설정을 덮어쓰고, 새롭게 지정할 설정들

urls.py : 최상위 URL 설정

wsgi.py : 실서비스에서의 웹서비스 진입점

# 프로젝트 초기화 작업 및 개발서버구동

프로젝트를 만들고자하는 디렉터리에서
```
django-admin startproject [projectname]
python manage.py migrate //초기 install_apps를 탐색하여 settingps.py의 데이터베이스 설정과 app과 함께 제공되는 database migrations에 따라, 필요한 데이터베이스 테이블 생성
python manage.py createsuperuser // 어드민페이지 생성
python manage.py runserver //서버 구동
```