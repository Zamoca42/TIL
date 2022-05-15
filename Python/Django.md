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

# Static & Media 파일

## Static 파일

- 개발 리소스로서의 정적인 파일(js,css,image 등)
- 앱 / 프로젝트 단위로 저장 / 서빙

## Media 파일

- django에만 있는 용어
- FileField / ImageField를 통해 저장한 모든 파일
  - models.py 통해 관리
- DB필드에는 저장경로를 저장하며, 파일은 파일 스토리지에 저장
  - 실제로 문자열을 저장하는 필드(중요)
- 프로젝트 단위로 저장 / 서빙

이미지 라이브러리 설치

```
pip3 install pillow
```

app/models.py

```py
class Post(models.Model):
    message = models.TextField()
    # 사진을 저장할 수 있는 필드 추가
    photo = models.ImageField(blank=True)
    #...
```

## Media 파일 처리 순서

1. HttpRequest.Files를 통해 파일이 전달

2. 뷰 로직이나 폼 로직을 통해, 유효성 검증을 수행

3. FileField/ImageField 필드에 "경로(문자열)"을 저장하고

4. settings.MEDIA_ROOT 경로에 파일을 저장

## Media 파일 관련 settings 예시

각 설정의 디폴트 값

settings.py

- MEDIA_URL = ""
  - 각 media 파일에 대한 URL Prefix
  - 필드명.url 속성에 의해서 참조되는 설정
- MEDIA_ROOT = ""
  - 파일필드를 통한 저장 시, 실제 파일을 저장할 ROOT 경로

```py
MEDIA_URL = '/media/'
# MEDIA_ROOT = os.path.join(BASE_DIR, 'media')
MEDIA_ROOT = BASE_DIR / 'media'
```

## 개발환경에서의 media 파일 서빙

- static 파일과 다르게, 장고 개발서버에서 서빙 미지원
- 개발 편의성 목적으로 직접 서빙 Rule 추가 가능

urls.py

```py
from django.conf.urls.static import static
# ...
# media url요청 시 이미지 파일 보여줌
if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

```

app/admin.py

```py
#...
from django.utils.safestring import mark_safe

class PostAdmin(admin.ModelAdmin):
    list_display = ['id', 'photo_tag', 'message',
                    'message_length', 'is_public', 'created_at', 'update_at']
                    # ...
                    def photo_tag(self, post):
                        if post.photo:
                            return mark_safe(f'<img src="{post.photo.url}" style="width: 100px" />')
                        return None
```

## 사용할 만한 필드 옵션

- blank 옵션
  - 업로드 옵션처리 여부
  - 디폴트 : False
- upload_to 옵션
  - settings.MEDIA_ROOT 하위에서 저장한 파일명/경로명 결정
  - 디폴트 : 파일명 그대로 settings.MEDIA_ROOT에 저장
    - 추천) 성능을 위해, 한 디렉토리에 너무 많은 파일들이 저장되지 않도록 조정하기
  - 동일 파일명으로 저장 시에, 파일명에 더미 문자열을 붙여 파일 덮어쓰기 방지

models.py

```py
class Post(models.Model):
    message = models.TextField()
    photo = models.ImageField(blank=True, upload_to='instagram/post/%Y/%m/%d')
    # upload_to 경로를 지정해주면 이미지파일을 저장할때 경로를 나눠줌
    # 보통 연/월/일로 나누고 폴더를 나눌수록 찾는데 한 폴더에 있을 때 보다 적게걸림
    # ...
```

- 참조하지 않는 이미지파일은 삭제되지 않기 때문에 삭제하고싶으면 배치명령을 작성해서 삭제

# 모델을 통한 조회 (기초)

https://docs.djangoproject.com/en/4.0/topics/db/managers/

## Model Manager

- 데이터베이스 질의 인터페이스를 제공
- 디폴트 manager로서 ModelCls.objects가 제공

```
# 생성되는 대강의 SQL 윤곽 -> SELECT * FROM app_model;
ModelCls.objects.all()

# 생성되는 대강의 SQL 윤곽 -> SELECT * FROM app_model ORDER BY id DESC LIMIT 10;
ModelCls.objects.all().order_by('-id')[:10]

# 생성되는 대강의 SQL 윤곽 -> SELECT * FROM app_model (title) VALUES ("New Title");
ModelCls.objects.create(title="New Title")

```
<img src="https://user-images.githubusercontent.com/96982072/168478198-bfd83c89-ea1d-4598-837d-033c236e7a11.png">

## QuerySet

- SQL을 생성해주는 인터페이스
- 순회가능한 객체
- Model Manager를 통해, 해당 Model에 대한 QuerySet을 획득
  - Post.objects.all() 코드는 "SELECT \* FROM post ...;"
  - Post.objects.create(...) 코드는 "INSERT INTO ...;"

## QuerySet은 Chaining을 지원

- Post.objects.all().filter(...).exclude(...).filter(...) -> QuerySet
- QuerySet은 Lazy한 특성
  - QuerySet을 만드는 동안에는 DB접근을 하지 않습니다.
  - 실제로 데이터가 필요한 시점에 접근을 합니다.
- 데이터가 필요한 시점은 언제인가?
  1. queryset
  2. print(queryset)
  3. list(queryset)
  4. for instance in queryset: print(instance)

<img src="https://user-images.githubusercontent.com/96982072/168478308-799eb68e-0496-4ecc-9247-7f4386e5a26e.png">

## 다양한 조회요청 방법

- 조건을 추가한 Queryset, 획득할 준비
    - queryset.filter(...) -> queryset
    - queryset.exclude(...) -> queryset
- 특정 모델객체 1개 획득을 시도
    - queryset`[숫자인덱스]`
     - 모델객체 혹은 예외발생 (IndexError)
    - queryset.get(...)
     - 모델객체 혹은 예외발생 (DoesNotExist, MultipleObjectsReturned)
    - queryset.first() -> 모델객체 혹은 None
    - queryset.last() -> 모델객체 혹은 None 

## filter <-> exclude

- 인자로 "필드명 = 조건값" 지정
- 1개 이상의 인자 지정 -> 모두 AND 조건으로 묶임
- OR 조건을 묶으려면, django.db.models.Q 활용

<img src="https://user-images.githubusercontent.com/96982072/168478369-fca50045-e2ad-4ff6-8665-0552e8292843.png">
