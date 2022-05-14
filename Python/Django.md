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

# 장고 주요 기능들

1. Function Based Views : 함수로 HTTP 요청 처리

2. Models : 데이터베이스와의 인터페이스

3. Templates : 복잡한 문자열 조합을 보다 용이하게. 주로 HTML 문자열 조합 목적으로 사용하지만, 푸쉬 메시지나 이메일 내용을 만들 때에도 쓰면 편리

4. Admin 기초 : 심플한 데이터베이스 레코드 관리UI

5. Logging : 다양한 경로로 메시지 로깅

6. Static files : 개발 목적으로의 정적인 파일 관리

7. Message framework : 유저에게 1회성 메시지 노출 목적

8. Forms : 입력폼 생성, 입력값 유효성 검사 및 DB로의 저장

9. 테스팅

10. 캐싱

# Django Model

장고 내장 ORM(Object-relational mapping)

> ORM을 쓰더라도, 내가 작성된 ORM코드를 통해 어떤 SQL이 실행되고 있는지, 파악을 하고 이를 최적화할 수 있어야 합니다 -> django-debug-toolbar 적극 활용

<데이터베이스 테이블>과 <파이썬 클래스>를 1:1로 매칭

모델 클래스명은 단수형으로 지정 ex) Posts(X), Post(O)  
클래스이기에 필히 "첫 글자가 대문자인 PascalCase 네이밍"  
매핑되는 모델 클래스는 DB 테이블 필드 내역이 일치해야합니다.  
모델을 만들기 전에, 서비스에 맞게 데이터베이스 설계가 필수.  
이는 데이터베이스의 영역 -> 관계형 데이터베이스 학습도 필요

```py
from django.db import models

class Post(models.Model):   # models.Model 상속
    title = models.CharField(max_length=100) # 타입 = 타입명
    content = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)
    update_at = models.DateTimeField(auto_now=True)
```

## 모델 활용 순서 (개발 순서)

### 장고 모델을 통해, 데이터베이스 형상을 관리할 경우

1. 모델 클래스 작성

2. 모델 클래스로부터 마이그레이션 파일 생성 -> `makemigrations` 명령

3. 마이그레이션 파일을 데이터베이스에 적용 -> `migrate` 명령

4. 모델 활용

### 장고 외부에서, 데이터베이스 형상을 관리할 경우

- 데이터베이스로부터 모델 클래스 소스 생성 -> `inspectdb` 명령

- 모델 활용

## 모델명과 DB테이블명

DB 테이블명 : 디폴트 "앱이름\_모델명"

### 예시

blog 앱

- Post 모델 -> "blog_post"
- Comment 모델 -> "blog_comment"

shop 앱

- Item 모델 -> "shop_item"
- Review 모델 -> "shop_review"

### 커스텀 지정

모델 Meta 클래스의 db_table속성

https://docs.djangoproject.com/ko/3.0/ref/models/options/#db-table

## 데이터베이스 확인

DB 종류에 따라 다양한 방법

sqlite 기준

```
python manage.py dbshell

.tables

.quit
```

# 장고 모델 필드

> https://docs.djangoproject.com/ko/4.0/ref/models/fields/#field-types

## 기본 지원되는 모델필드 타입 - 1

Primary Key : AutoField, BigAutoField  
문자열 : CharField. TextField, SlugField  
날짜/시간 : DateField, TimeField, DateTimeField, DurationField  
참/거짓 : BolleanField, NullBooleanField
숫자 : IntegerField, SmallIntegerField, PositiveIntegerField, BigIntegerField, DecimalField, FloatField  
파일 : BinaryField, FileField, ImageField, FilePathField

## 기본 지원되는 모델필드 타입 - 2

이메일 : EmailField  
URL : URLField  
UUID : UUIDField  
아이피 : GenericIPAddressField  
Relationship Types

- ForeignKey
- ManyToManyField
- OneToOneField  
  그리고 다양한 커스텀 필드들
- django-model-utils : https://django-model-utils.readthedocs.io/en/latest/

## 모델필드들은 DB 필드타입을 반영

DB에서 지원하는 필드들을 반영

- Varchar 필드타입 -> CharField, SlugField, URLField, EmailField 등

파이썬 데이터타입과 데이터베이스 데이터타입을 매핑

- AutoField -> int
- BinaryField -> bytes
- BooleanField -> bool
- CharField/SlugField/URLField/EmailField -> str

같은 모델필드라 할지라도, DB에 따라 다른 타입이 될 수도 있습니다.

# django admin

> https://docs.djangoproject.com/en/4.0/ref/contrib/admin/

django.contrb.admin 앱을 통해 제공

디폴트 경로 : /admin/ -> 실제 서비스에서는 다른 주소로 변경 권장
혹은 django-admin-honeypot 앱을 통해, 가짜 admin 페이지 노출

모델 클래스 등록을 통해, 조회/추가/수정/삭제 웹 UI를 제공

- 서비스 초기에, 관리도구로서 사용하기에 제격
- 관리 도구 만들 시간을 줄이고, End-User 서비스에 집중!
  내부적으로 Django Form을 적극적으로 사용

## 모델 클래스를 admin에 등록하기

app/admin.py

```py
from django.contrib import admin
from .models import Item

# 등록법 1
admin.site.register(Item) # 기본 ModelAdmin으로 동작

# 등록법 2
class ItemAdmin(admin.ModelAdmin):
    pass

admin.site.register(Item, ItemAdmin) # 지정한 ModelAdmin으로 동작

# 등록법 3
@admin.register(Item) # Wrapping
class ItemAdmin(admin.ModelAdmin):
    pass
```

## 모델 클래스에 `__str__` 구현

admin 모델 리스트에서 "모델명 object"를 원하는대로 변경하기 위해

객체를 출력할 때, `객체.__str__()`의 리턴값을 활용

app/models.py

```py
from django.db improt models

class Item(models.Model):
    name - models.CharField(max_length=100)
    desc = models.TextField(blank=True)
    price = models.PositiveIntegerField()
    is_publish = models.BooleanField(default=False)

    # Java의 toString
    def __str__(self):
        # return f'<{self.pk}> {self.name}'
        # return "Custom Post object({}).format(self.id)"
    # 혹은 이렇게도 가능
        return self.message
```

## list_display 속성 정의

모델 리스트에 출력할 컬럼 지정

app/admin.py

```py
from django.contrib import admin
from .models import Item

@admin.register(Item)
class ItemAdmin(admin.ModelAdmin):
    list_display = ['id', 'message', 'message_length', 'created_at', 'update_at']
    list_display_links = ['message']

    def short_desc(self, item):
        return item.desc[:20]
```

app/models.py

```py
class Post(models.Model):
    # ...
    def __str__(self):
        # return f"Custom Post object ({self.id})"
        # return "Custom Post object({}).format(self.id)"
        return self.message

    # 글자수 정의 가능
    def message_length(self):
        return len(self.message)
```

## search_fields 속성 정의

admin내 검색UI를 통해, DB를 통한 where 쿼리 대상 필드 리스트

app/admin.py

```py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ['id', 'message',
                    'message_length', 'created_at', 'update_at']
    list_display_links = ['message']
    # admin내에 검색, DB의 where쿼리 대상 필드
    search_fields = ['message']


admin.site.register(Post, PostAdmin)
```

## list_filter 속성 정의

지정 필드값으로 필터링 옵션 제공

app/admin.py

```py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ['id', 'message',
                    'message_length', 'created_at', 'update_at']
    list_display_links = ['message']
    # admin내에 검색, DB의 where쿼리 대상 필드
    search_fields = ['message']
    # 지정 필드값으로 필터링 옵션 제공
    list_filter = ['created_at', 'is_public']


admin.site.register(Post, PostAdmin)
```

app/models.py

```py
class Post(models.Model):
    message = models.TextField()
    is_public = models.BooleanField(default=False, verbose_name='공개여부')
    # ...
```

- 추후에 좀 더 능숙해지면 admin기능 대신에 별도의 페이지를 만들어서 관리해보기

