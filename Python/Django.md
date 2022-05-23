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

# Queryset을 통한 간단 검색구현

## 실전예제) Item 목록/간단검색 페이지

instagram/views.py

```py
from django.shortcuts import render
from .models import Post

# Create your views here.

def post_list(request):
    qs = Post.objects.all()
    q = request.GET.get('q', '') # 검색어 q를 요청해서 있으면 q를 반환하고 없으면 빈문자열 반환
    if q:
        qs = qs.filter(message__icontains=q) # 검색어가 있으면 검색어가 포함된 단어 출력
    # instagram/templates/instagram/post_list.html
    return render(request, 'instagram/post_list.html',{
        'post_list': qs,
    })
    # request.POST
    # request.FILES
```

instagram/templates/instagram/post_list.html

```html
{{ post_list }}
```

instagram/urls.py

```py
from django.urls import path

from . import views

urlpatterns = [
    path('', views.post_list),
]
```

localhost:8000/instagram

결과물
<img src="https://user-images.githubusercontent.com/96982072/168571524-1a4ba635-aee9-4940-8137-00a21065152b.png">

검색기능 + 템플릿 추가

post_list.html

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
      crossorigin="anonymous"
    />
    <title>Instagram / Post List</title>
  </head>
  <body>
    <form action="" method="get">
      <input type="text" name="q" />
      <input type="submit" value="검색" />
    </form>
    <table class="table table-bordered table-hover">
      <tbody>
        {% for post in post_list %}
        <tr>
          <td>
            {% if post.photo %}
            <img src="{{ post.photo.url }}" width="25%" />
            {% else %} No Photo {% endif %}
          </td>
          <td>{{ post.message }}</td>
        </tr>
        {% endfor %}
      </tbody>
    </table>
  </body>
</html>
```

결과물

검색어 없을 때

<img src="https://user-images.githubusercontent.com/96982072/168575440-380bbe0c-3f53-4409-96c4-ceec7bc0faf5.png">

검색어 입력 후

<img src="https://user-images.githubusercontent.com/96982072/168575483-a3916ea5-a4af-42cc-8b8b-994cc60105a1.png">

url에 ?q=두번째가 추가되었다  
QuerySet을 직접 써보고, 외부 인자에 의해서 적절한 조건을 걸어서 보기 원하는 포스팅만 볼 수 있는 기능을 구현

# Queryset의 정렬 및 범위 조건

## 정렬 조건 추가

- SELECT 쿼리에 "OREDER BY" 추가

- 정렬 조건을 추가하지 않으면 일관된 순서를 보장받을 수 없음

- DB에서 다수 필드에 대한 정렬을 지원

  - 하지만, 가급적 단일 필드로 하는 것이 성능에 이익
  - 시간순/역순 정렬이 필요할 경우, id 필드를 활용해볼 수 있음

- 정렬 조건을 지정하는 2가지 방법
  1. (추천) 모델 클래스의 Meta 속성으로 ordering 설정 : list로 지정
  2. 모든 queryset에 order_by(...)에 지정

## 정렬 지정하기 #1

instagram/models.py

```py
class Post(models.Model):
  #...

  class Meta:
        ordering = ['-id']
```

메타 속성으로 id순으로 정렬됨
여기서 다시 order_by로 조건을 입력하면 조건이 바뀌어서 조회

```
# 생성 순서대로 조회

Post.objects.all().order_by('created_at')

# id정렬은 사라지고 생성순 정렬로 조회
```

## 슬라이싱을 통한 범위 조건 추가

- SELECT 쿼리에 "OFFSET/LIMIT" 추가

- str/list/tuple에서의 슬라이싱과 거의 유사하나, 역순 슬라이싱은 지원하지 않음

  - 데이터베이스에서 지원하지 않기 때문

- 객체`[start:stop:step]`
  - OFFSET -> start
  - LIMIT -> stop - start
  - (주의) step은 쿼리에 대응되지 않습니다. 사용을 비추천

```
# 처음에서 2개만 보여주기

Post.objects.all()[:2]

# step을 넣으면 반환 값이 list가 됨

Post.objects.all()[1:3:1]

# 역순 슬라이싱은 지원하지 않음

Post.objects.all()[-2:]
```

# django-debug-toolbar를 이용한 SQL디버깅

설치 공식문서

https://django-debug-toolbar.readthedocs.io/en/latest/installation.html

주의사항

웹페이지의 템플릿에 필히 "`<body>`" 태그가 있어야만, django-debug-toolbar가 동작합니다.

이유 : dbt의 html/script 디폴트 주입 타겟이 `</body>` 태그 (INSERT_BEFORE 설정 디폴트: "`</body>`")

## django-debug-toolbar

- 현재 request/response에 대한 다양한 디버깅 정보를 보여줌.
- 다양한 Panel 지원
  - SQLPanel을 통해, 각 요청 처리 시에 발생한 SQL 내역 확인 가능
  - Javascript Ajax 요청에 대한 지원은 불가합니다.

그 외 : django-querycount

https://github.com/bradmontgomery/django-querycount/

- SQL 실행내역을 개발서버 콘솔 표준출력
- Ajax 내역도 출력 가능

# 관계를 표현하는 모델 필드

- ORM은 어디까지나, SQL 생성을 도와주는 라이브러리
- ORM이 DB에 대한 모든 것을 알아서 처리해주진 않습니다
- 보다 성능높은 어플리케이션을 만들고자 한다면, 사용할 DB엔진과 SQL에 대한 높은 이해 필요

## RDBMS에서의 관계예시

- 1 : N 관계 -> models.ForeignKey로 표현

  - 1명의 유저가 쓰는 다수의 포스팅(Post)
  - 1명의 유저가 쓰는 다수의 댓글(Comment)
  - 1명의 포스팅(Post)에 다수의 댓글(Comment)

- 1 : 1 관계 -> models.OneToOneField로 표현

  - 1명의 유저는 1개의 프로필(Profile)

- M : N 관계 -> models.ManyToManyField로 표현

  - 1개의 포스팅(Post)에는 다수의 태그(Tag)
    - 1개의 태그(Tag)에는 다수의 포스팅(Post)

## ForeignKey

https://docs.djangoproject.com/en/2.1/ref/models/fields/#django.db.models.ForeignKey

- 1:N 관계에서 N측에 명시

  - ex) Post:**Comment**, User:**Post**, User:**Comment**

- ForeignKey(to, on_delete)
  - to : 대상모델
    - 클래스를 직접 지정하거나, 클래스명을 문자열로지정. 자기 참조는 "self"지정
  - on_delete : Record 삭제 시 Rule
    - CASCADE : FK로 참조하는 다른 모델의 Record도 삭제 (장고 1.X에서의 디폴트값)
      - ex) 만약에 포스트와 댓글에서 포스트가 삭제 시 댓글도 같이 삭제
    - PROTECT : ProtectedError (IntegrityError 상속)를 발생시키며, 삭제 방지
    - SET_NULL : null로 대체. 필드에 null=True 옵션 필수.
    - SET_DEFAULT : 디폴트 값으로 대체. 필드에 디폴트값 지정 필수
    - SET : 대체할 값이나 함수 지정. 함수의 경우 호출하여 리턴값을 사용.
    - DO_NOTHING : 어떠한 액션 X. DB에 따라 오류가 발생할 수도 있습니다.

instagram/models.py

```py
# ForeignKey로 댓글 모델 만들기

class Comment(models.Model):
    post = models.ForeignKey('Post', on_delete=models.CASCADE) # post_id 필드가 생성이 됩니다.
    mssage = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)
    update_at = models.DateTimeField(auto_now=True)
```

### 올바른 User 모델 지정

instagram/models.py

```py
class Post(models.Model):
    author = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    message = models.TextField()
    # ...
```

### ForeignKey에서의 reverse_name

- reverse 접근 시의 속성명 : 디폴트 -> "모델명소문자\_set"

<img src="https://user-images.githubusercontent.com/96982072/168609227-753b81c2-279d-4dde-93d1-f851c64ea474.png">

post.comment_set.all() <-> Comment.objects.filter(post=post)

여기서 사용된 1측의 Post에서 N측의 comment를 참조할 때의 post.comment_set.all()을 reverse_name이라 부른다

### reverse_name의 이름 충돌이 발생한다면?

- reverse_name 디폴트 명은 앱이름 고려 X, 모델명만 고려

- 다음의 경우, user.post_set 이름에 대한 충돌

  - blog앱 Post모델, author = FK(User)
  - shop앱 Post모델, author = FK(User)

- 이름이 충돌이 날 때, makemigrations 명령이 실패

- 이름 충돌 피하기

  1. 어느 한 쪽의 FK에 대해, reverse_name을 포기 -> related_name='+'
  2. 어느 한 쪽의 (혹은 모두) FK의 reverse_name을 변경

  - ex) FK(User, …, related_name="blog_post_set")
  - ex) FK(User, …, related_name="shop_post_set")

### ForeignKey.limit_choices_to 옵션

- Form을 통한 Choice 위젯에서 선택항목 제한 가능.
  - dict/Q 객체를 통한 지정 : 일괄 지정
  - dict/Q 객체를 리턴하는 함수 지정 : 매번 다른 조건 지정 가능
- ManyToManyField에서도 지원

  ```py
  staff_member = models.ForeignKey(
  User,
  on_delete=models.CASCADE,
  limit_choices_to={'is_staff': True},
  )
  ```

## OneToOneField

- 1 : 1 관계에서 어느 쪽이라도 가능
  - User:Profile
- ForeignKey(unique=True)와 유사하지만, reverse 차이
  - User:Profile를 FK로 지정한다면 -> profile.user_set.first() -> user
  - User:Profile를 O2O로 지정한다면 -> profile.user -> user
    - user.profile -> profile 사용가능.
    - user.profile 시에 user와 관계에 있는 Profile이 없는 경우, Profile.DoesNotExist 예외가 발생합니다.
- OneToOneField(to, on_delete)
  ```py
  # accounts/models.py
   class Profile(models.Model):
   author = models.OneToOneField(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
  ```

### O2O에서의 related_name

- reverse 접근 시의 속성명 : 디폴트 -> 모델명소문자

app/models.py

```py
 # accounts/models.py

 class Profile(models.Model):
  author = models.OneToOneField(settings.AUTH_USER_MODEL,on_delete=models.CASCADE)
  phone = models.CharField(max_length=11, blank=True)
  birth = models.DateField(null=True)

 >>> profile.author
 >>> user.profile
```

## ManyToManyField

- M : N 관계에서 어느 쪽이라도 필드 지정 가능

- ManyToManyField(to, blank=False)

app/models.py

```py
# 방법 1)
class Post(models.Model):
  tag_set = models.ManyToManyField('Tag', blank=True) class Article(models.Model):
  tag_set = models.ManyToManyField('Tag', blank=True) class Tag(models.Model):
  name = models.CharField(max_length=100, unique=True)

# 방법 2)
class Post(models.Model):
  ...
class Article(models.Model):
  ...
class Tag(models.Model):
  name = models.CharField(max_length=100, unique=True)
  post_set = models.ManyToManyField('Post', blank=True)
  article_set = models.ManyToManyField('Article', blank=True)
```

## RDBMS지만, DB따라 NoSQL기능도 지원

- ex)하나의 Post안에 다수의 댓글 저장 가능

- djkoch/jsonfield

  - 대개의 DB엔진에서 사용 가능
  - TextField/CharField를 래핑
  - dict 등의 타입에 대한 저장을 직렬화하여 문자열로 저장
    - 내부 필드에 대해 쿼리 불가

- django.contrib.postgres.fields.JSONField

  - 내부적으로 PostgreSQL의 jsonb 타입
  - 내부 필드에 대해 쿼리 지원

- adamchainz/django-mysql

  - MySQL 5.7 이상에서 json 필드 지원

# 마이그레이션을 통한 데이터베이스 스키마 관리

## Migrations

- 모델의 변경내역을 “데이터베이스 스키마"로 반영시키는 효율적인 방법을 제공

- 관련 명령

  - 마이그레이션 파일 생성 ... (1) DB가 만들어진 것이지 변경된 것은 아님

    - 쉘> python manage.py makemigrations <앱이름>

  - 지정 데이터베이스에 마이그레이션 적용 ... (3) 실제로 적용

    - 쉘> python manage.py migrate <앱이름>

  - 마이그레이션 적용 현황 출력

    - 쉘> python manage.py showmigrations <앱이름>

  - 지정 마이그레이션의 SQL 내역 출력 ... (2) sql형태로 어떻게 될 것인지 확인
    - 쉘> python manage.py sqlmigrate <앱이름> <마이그레이션-이름>

## Migration 파일

- 데이터베이스에 어떤 변화를 가하는 Operation들을 나열

  - 테이블 생성/삭제, 필드 추가/삭제 등

  - 커스텀 파이썬/SQL Operation
    - 데이터 마이그레이션 등

- 대개 모델로부터 자동 생성 -> makemigrations 명령

  - 모델 참조없이 빈 마이그레이션 파일 만들어서 직접 채워넣기도.

- 주의) 같은 Migration 파일이라 할지라도, DB종류에 따라 다른 SQL이 생성됩니다.

  - 모든 데이터베이스 엔진들이 같은 기능을 제공하진 않아요.

  - 예) SQLite DB에서는 기존 테이블에 컬럼 추가가 지원되지 않습니다.

## 마이그레이션 파일 생성 및 적용

<img src="https://user-images.githubusercontent.com/96982072/169072631-6b0af075-9e1b-4f74-8cc7-7ab9046f12a5.png">

## 언제 makemigrations를 하는 가?

- 모델 필드 관련된 어떠한 변경이라도 발생 시에 마이그레이션 파일 생성

  - 실제로 DB Scheme에 가해지는 변화가 없더라도 수행.

- 마이그레이션 파일은 모델의 변경내역을 누적하는 역할

  - 적용된 마이그레이션 파일은 절대 삭제하시면 안 됩니다.

  - 마이그레이션 파일이 너무 많아질 경우, squashmigrations 명령으로 다수의 마이그레이션 파일을 통합할 수 있습니다.

## 마이그레이션 Migrate (정/역 방향)

- python manage.py migrate <앱이름>

  - 미적용 <마이그레이션-파일>부터 <최근-마이그레이션-파일>까지 정방향으로 순차적으로 수행

- python manage.py migrate <앱이름> <마이그레이션-이름>

  - 지정된 <마이그레이션-이름>이 현재 적용된 마이그레이션보다
    - 이후라면, 정방향으로 순차적으로 지정 마이그레이션까지 forward 수행
    - 이전이라면, 역방향으로 순차적으로 지정 마이그레이션 이전까지 backward 수행

## id필드는 왜 생기나요?

- 모든 DB 테이블에는 각 Row의 식별기준인 “기본키 (Primary Key)”가 필요
  - 장고에서는 기본키로서 id (AutoField) 필드를 디폴트 생성
  - 다른 필드를 기본키로 지정하고 싶다면 primary_key=True 옵션 적용

## 새로운 필드가 필수필드라면?

- 필수필드 여부 : blank/null 옵션이 모두 False 일 때 (디폴트)

- makemigrations 명령을 수행할 때, 기존 Record들에 어떤 값을 채워넣을 지 묻습니다.
  - 선택1) 지금 그 값을 입력하겠다.
  - 선택2) 명령 수행을 중단.

## 협업 Tip

- 절대 하지 말아야할 일
  - 팀원 각자가 마이그레이션 파일을 생성 -> 충돌 발생
- 추천) 마이그레이션 파일 생성은 1명이 전담해서 생성.
  - 생성한 마이그레이션 파일을 버전관리에 넣고, 다른 팀원들은 이를 받아서 migrate만 수행

# 다양한 응답의 함수 기반 뷰

## View

- 1개의 HTTP 요청에 대해 -> 1개의 뷰가 호출

- urls.py/urlpatterns 리스트에 매핑된 호출 가능한 객체

  - 함수도 "호출 가능한 객체" 중의 하나

- 웹 클라이언트로부터의 HTTP 요청을 처리

- 크게 2가지 형태의 뷰
  - 함수 기반 뷰 (Function Based View) : 장고 뷰의 기본.
    - 호출 가능한 객체. 그 자체
  - 클래스 기반 뷰 (Class Based View)
    - 클래스.as_view() 를 통해 호출가능한 객체를 생성/리턴

## View 호출 시, 인자

- HttpRequest 객체 및 URL Captured Values

- 1번째 인자 : HttpRequest 객체

  - 현재 요청에 대한 모든 내역을 담고 있습니다.

- 2번째~ 인자 : 현재 요청의 URL로부터 Capture된 문자열들
  - url/re_path 를 통한 처리에서는 -> 모든 인자는 str 타입으로 전달
  - path 를 통한 처리에서는 -> 매핑된 Converter의 to_python에 맞게 변환된 값이 인자로 전달
    - 지난 에피소드의 4자리 년도를 위한 FourDigitYearConverter에서는 int 변환 -> 뷰의 인자로 int 타입의 년도가 전달

## View 호출에 대한 리턴값

- HttpResponse 객체

- 필히 HttpResponse 객체를 리턴해야 합니다

  - 장고 Middleware에서는 뷰에서 HttpResponse 객체를 리턴하기를 기대합니다. -> 다른 타입을 리턴하면 Middleware에서 처리 오류.
  - django.shortcuts.render 함수는 템플릿 응답을 위한 shortcut 함수

- 파일like객체 혹은 str/bytes 타입의 응답 지원

  - str 문자열을 직접 utf8로 인코딩할 필요가 없습니다.
    - 장고 디폴트 설정에서 str 문자열을 utf8로 인코딩해줍니다.
  - response = HttpResponse( 파일like객체 또는 str객체 또는 bytes객체 )

- 파일 like 객체
  - response.write( str객체 또는 bytes객체 )

## HttpRequest와 HttpResponse 예시

```py
from django.http import HttpRequest, HttpResponse

def index(request: HttpRequest) -> HttpResponse: # View 함수
  # 주요 request 속성
  request.method # 'GET', 'POST', etc.
  request.META
  request.GET, request.POST, request.FILES, request.body

content = '''
  <html>...</html>
''' #문자열혹은이미지,각종파일등

response = HttpResponse(content)
response.write(content) #response -> file-likeobject
response['Custom-Header'] = 'Custom Header Value'
return response
```

## FBV의 예

- Item 목록 보기

```py
# myapp/views.py
from django.shortcuts import render
from shop.models import Item

def item_list(request):
  qs = Item.objects.all()
  return render(request, 'shop/item_list.html', {
      'item_list': qs,
    })

# myapp/urls.py
from django.urls import path

urlpatterns = [
path('items/', item_list, name='item_list'),
]
```

## CBV의 예

- Item 목록 보기

- 간단하게 한줄로 끝낼 수 있지만, 기본 원리를 모르면 커스텀하고자 할 때 건들 수 없게됨.

```py
# myapp/views.py
from django.views.generic import ListView
from shop.models import Item

item_list = ListView.as_view(model=Item)

# myapp/urls.py
from django.urls import path
urlpatterns = [
    path('items/', item_list, name='item_list'),
]
```

# 다양한 타입의 HttpResponse

## Excel 파일 다운로드 응답

```py
from django.http import HttpResponse
from urllib.parse import quote

def response_excel(request):
    filepath = '/other/path/excel.xls'
    filename = os.path.basename(filepath)

    with open(filepath, 'rb') as f:
        response = HttpResponse(f, content_type='application/vnd.ms-excel')

        # 브라우저에 따라 다른 처리가 필요합니다.
        encoded_filename = quote(filename)
        response['Content-Disposition'] = "attachment; filename*=utf-8''{}".format(encoded_filename)

    return response

# ref) django.http.FileResponse 를 통해 첨부 헤더 지원
```

## Pandas를 통한 CSV 응답 생성

```py
import pandas as pd
from io import StringIO
from django.http import HttpResponse
def response_csv(request):
    df = pd.DataFrame([
        [100, 110, 120],
        [200, 210, 220],
        [300, 310, 320],
])

io = StringIO()
df.to_csv(io)
io.seek(0) # 끝에 있는 file cursor를 처음으로 이동

response = HttpResponse(io, content_type='text/csv')
response['Content-Disposition'] = "attachment; filename*=utf-8''{}".format(encoded_filename)
return response
```

## Pillow를 통한 이미지 응답 생성 - 기본

```py
import requests
from io import BytesIO
from PIL import Image, ImageDraw, ImageFont

ttf_path = 'C:/Windows/Fonts/malgun.ttf' # 윈도우의 맑은고딕 폰트 경로, 맥에서는 애플고딕 경로 à '/Library/Fonts/AppleGothic.ttf'

image_url = 'http://www.flowermeaning.com/flower-pics/Calla-Lily-Meaning.jpg'

res = requests.get(image_url) # 서버로 HTTP GET 요청하여, 응답 획득
io = BytesIO(res.content) # 응답의 Raw Body. 메모리 파일 객체 BytesIO 인스턴스 생성
io.seek(0) # 파일의 처음으로 커서를 이동

canvas = Image.open(io).convert('RGBA' ) # 이미지 파일을 열고, RGBA모드로 변환

font = ImageFont.truetype(ttf_path, 40) # 지정 경로의 TrueType 폰트, 폰트크기 40
draw = ImageDraw.Draw(canvas) # canvas에 대한 ImageDraw 객체 획득

text = 'Ask Company'
left, top = 10, 10
margin = 10
width, height = font.getsize(text)
right = left + width + margin
bottom = top + height + margin

draw.rectangle((left, top, right, bottom), (255, 255, 224))
draw.text((15,15), text, font=font, fill=(20, 20, 20))

canvas.show()
```

# URL Dispatcher와 정규 표현식

## URL Dispatcher

- "특정 URL 패턴 -> View"의 List

- 프로젝트/settings.py에서 최상위 URLConf 모듈을 지정

  - 최초의 urlpatterns로부터 include를 통해, TREE구조로 확장

- HTTP 요청이 들어올 때마다, 등록된 urlpatterns 상의 매핑 리스트를 처음부터 순차적으로 훑으며 URL 매칭을 시도
  - 매칭이 되는 URL Rule이 다수 존재하더라도, 처음 Rule만을 사용
  - 매칭되는 URL Rule이 없을 경우, 404 Page Not Found 응답을 발생

## urlpatterns 예시

shop/urls.py

```py
from django.urls import path, re_path
from shop import views

urlpatterns = [
    path('', views.item_list, name='item_list'), # Item 목록
    path('new/', views.item_new, name='item_new'), # 새 Item

    path('<int:id>/', views.item_detail, name='item_detail'), # Item 보기
    re_path(r'^(?P<id>\d+)/$', views.item_detail, name='item_detail'), # 혹은 re_path 활용

    path('<int:id>/edit/', views.item_edit, name='item_edit'), # Item 수정
    path('<int:id>/delete/', views.item_delete, name='item_delete'), # Item 삭제

    path('<int:id>/reviews/', views.review_list, name='review_list'), # 리뷰목록
    path('<int:item_id>/reviews/<int:id>/edit/$', views.review_edit, # 리뷰수정
         name='review_edit'),
    path('<int:item_id>/reviews/<int:id>/delete/$',views.review_delete, # 리뷰삭제
         name='review_delete'),
]
```

## path()와 re_path()의 등장

- 장고 1.x에서의 Django.conf.urls.url() 사용이 2가지로 분리

- django.urls.re_path()

  - django.conf.urls.url()과 동일

- django.urls.path()
  - 기본 지원되는 Path converters를 통해 정규표현식 기입이 간소화 -> 만능은 아닙니다.
  - 자주 사용하는 패턴을 Converter로 등록하면, 재활용면에서 편리

```py
from django.conf.urls import url # django 1.x 스타일
from django.urls import path, re_path # django 2.x ~ 스타일

 urlpatterns = [
# 장고 1.x에서의 다음 코드를
url(r'^articles/(?P<year>[0-9]{4})/$', views.year_archive),

# 다음과같이간소화가능
     path('articles/<int:year>/', views.year_archive),

#물론다음과같이동일하게쓸수있습니다.
     re_path(r'^articles/(?P<year>[0-9]{4})/$', views.year_archive),
]
```

## 기본 제공되는 Path Converters

- IntConverter -> `r"[0-9]+"`
- StringConverter -> `r"[^/]+"`
- UUIDConverter -> `r"[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}"`
- SlugConverter (StringConverter 상속) -> `r"[-a-zA-Z0-9_]+"`
- PathConverter (StringConverter 상속) -> `r".+"`

# 클래스 기반 뷰 시작하기

https://docs.djangoproject.com/en/3.0/topics/class-based-views/

## Class Based View(CBV)

- View 함수를 만들어주는 클래스

  - as_view() 클래스 함수를 통해, View 함수를 생성
  - 상속을 통해, 여러 기능들을 믹스인.

- 장고 기본 CBV 팩키지

  - django.views.generic -> 소스코드 참고
  - https://github.com/django/django/tree/3.0.2/django/views/generic

- 써드파티 CBV
  - django-braces
  - https://django-braces.readthedocs.io

## CBV 컨셉 구현해보기

## 1. FBV

```py
from django.shortcuts import get_object_or_404, render

def post_detail(request, id):
  post = get_object_or_404(Post, id=id)
  return render(request, 'blog/post_detail.html', {
      'post': post,
  })

def article_detail(request, id):
  article = get_object_or_404(Article, id=id)
  return render(request, 'blog/article_detail.html', {
    'article': article,
  })

urlpatterns = [
    path('post/<int:id>/', post_detail),
    path('article/<int:id>/', article_detail),
]
```

## 3. Class로 동일한 View 함수 구현

```py
class DetailView:
    def __init__(self, model):
        self.model = model

    def get_object(self, *args, **kwargs):
        return get_object_or_404(self.model, id=kwargs['id'])

    def get_template_name(self):
        return '{}/{}_detail.html'.format(
            self.model._meta.app_label,
            self.model._meta.model_name)

    def dispatch(self, request, *args, **kwargs):
        object = self.get_object(*args, **kwargs)
        return render(request, self.get_template_name(), {
            self.model._meta.model_name: object,
        })

    @classmethod
    def as_view(cls, model):
        def view(request, *args, **kwargs):
            self = cls(model)
            return self.dispatch(request, *args, **kwargs)
return view

post_detail = DetailView.as_view(Post)
article_detail = DetailView.as_view(Article)
```

## 4. 장고 기본 제공 CBV 활용

```py
from django.views.generic import DetailView

post_detail = DetailView.as_view(model=Post, pk_url_kwarg='id')
article_detail = DetailView.as_view(model=Article, pk_url_kwarg='id')

# pk_url_kwarg 인자를 "pk"로 지정했다면

post_detail = DetailView.as_view(model=Post)
article_detail = DetailView.as_view(model=Article)

urlpatterns = [
    path('post/<int:pk>/', post_detail),
    path('article/<int:pk>/', article_detail),
]

# 상속을 통한 CBV 속성 정의

from django.views.generic import DetailView

class PostDetailView(DetailView):
    model = Post
    pk_url_kwarg = 'id'

post_detail = PostDetailView.as_view()
```

## CBV는 ~

- CBV가 정한 관례대로 개발할 경우, 아주 적은 양의 코드로 구현

  - 그 관례에 대한 이해가 필요 -> FBV를 통한 개발경험이 큰 도움.
    - 필요한 설정값을 제공하거나, 특정 함수를 재정의하는 방식으로 커스텀 가능
    - 하지만, 그 관례를 잘 이해하지 못하고 사용하거나, 그 관례에서 벗어난 구현을 하고자 할 때에는 복잡해지는 경향이 있습니다.

- CBV를 제대로 이해할려면 ~
  - 코드를 통한 이해가 지름길
    - 파이썬 클래스에 대한 이해가 필요 (특히 상속, 인자 packing/unpacking)
  - https://github.com/django/django/tree/2.1/django/views/generic
- CBV 코드를 동일하게 동작하는 FBV로 구현해보는 연습을 추천

# 장고 기본 CBV API (Base Views)

https://docs.djangoproject.com/en/2.1/ref/class-based-views/

## Built-in CBV API

- Base views

  - View, TemplateView, RedirectView

- Generic display views

  - DetailView, ListView

- Generic date views

  - ArchiveIndexView, YearArchiveView, MonthArchiveView, WeekArchiveView, DayArchiveView, TodayArchiveView, DateDetailView

- Generic editing views

  - FormView, CreateView, UpdateView, DeleteView

## Base Views

- django/views/generic/base.py

- View

- TemplateView  
  <- TemplateResponseMixin  
  <- ContextMixin  
  <- View

- RedirectView  
  <- View

## View

- 모든 CBV의 모체

  - 이 CBV를 직접 쓸 일은 거의 X

- http method별로 지정 이름의 멤버함수를 호출토록 구현

- CBV.as_view(\*\*initkwargs)

  - initkwargs인자는 그대로 CBV 생성자로 전달

    ```py
    def __init__(self, **kwargs):
      for key, value in kwargs.items():
        setattr(self, key, value)
    ```

## RedirectView

- permanent (디폴트: False)

  - True : 301 응답 (영구적인 이동) – 검색엔진에 영향
  - False : 302 응답 (임시 이동)

- url = None

  - URL 문자열

- pattern_name = None

  - URL Reverse를 수행할 문자열

- query_string = False
  - QueryString을 그대로 넘길 것인지 여부

```py
 class RedirectView(View):
    permanent = False
    url = None
    pattern_name = None
    query_string = False

    def get_redirect_url(self, *args, **kwargs):
        if self.url:
            url = self.url % kwargs
        elif self.pattern_name:
            url = reverse(self.pattern_name, args=args, kwargs=kwargs)
        else:
            return None

        args = self.request.META.get('QUERY_STRING', '')
        if args and self.query_string:
            url = "%s?%s" % (url, args)
        return url

    def get(self, request, *args, **kwargs):
        url = self.get_redirect_url(*args, **kwargs)
        if url:
            if self.permanent:
                return HttpResponsePermanentRedirect(url)
            else:
                return HttpResponseRedirect(url)
        else:
            logger.warning(
                'Gone: %s', request.path,
                extra={'status_code': 410, 'request': request}
            )
            return HttpResponseGone()
# head, post, options, delete, put, patch 모두 같은 구현
    def head(self, request, *args, **kwargs):
        return self.get(request, *args, **kwargs)
```

# 장고 기본 CBV API (Generic display views)

https://docs.djangoproject.com/en/2.1/ref/class-based-views/generic-display/

## DetailView

- 1개 모델의 1개 Object에 대한 템플릿 처리
  - 모델명소문자 이름의 Model Instance를 템플릿에 전달
    - 지정 pk 혹은 slug에 대응하는 Model Instance

```py
from django.views.generic import DetailView
from .models import Post

post_detail1 = DetailView.as_view(model=Post)

class PostDetailtView(DetailView):
  model = Post

post_detail2 = PostDetailtView.as_view()
```

## DetailView 상속관계

- django.views.generic.detail.DetailView

- SingleObjectTemplateResponseMixin

  - template_name이 지정되지 않았다면, 모델명으로 템플릿 경로 유추
  - TemplateResponseMixin

- BaseDetailView

  - SingleObjectMixin : url_kwarg로 지정된 Model Instance 획득
    - ContextView
  - View

- https://github.com/django/django/blob/3.0.2/django/views/generic/detail.py

## ListView

- 1개 모델에 대한 List 템플릿 처리

  - 모델명소문자\_list 이름의 QuerySet을 템플릿에 전달

- 페이징 처리 지원

```py
from django.views.generic import ListView
from .models import Post

post_list1 = ListView.as_view(model=Post)

post_list2 = ListView.as_view(model=Post, paginate_by=10)

# 상속

class PostListView(ListView):
    model = Post
    paginate_by = 10

post_list3 = PostListView.as_view()

# Queryset 재정의

class PostListView(ListView):
    model = Post
    paginate_by = 10

    def get_queryset(self):
        qs = super().get_queryset()
        qs = qs.filter(...)
        return qs

post_list4 = PostListView.as_view()
```

## ListView 상속관계

- django.views.generic.list.ListView

- MultipleObjectTemplateResponseMixin

  - template_name이 지정되지 않았다면, 모델명으로 템플릿 경로 유추
    - TemplateResponseMixin

- BaseListView

  - MultipleObjectMixin : Paginator가 적용된 QuerySet 획득
    - ContextMixin
  - View

- https://github.com/django/django/blob/3.0.2/django/views/generic/list.py

# 뷰 장식자

https://docs.djangoproject.com/en/3.0/topics/http/decorators/

## 장식자 (Decorators)

- 어떤 함수를 감싸는 (Wrapping) 함수

```py
from django.contrib.auth.decorators import login_required
from django.shortcuts import render

@login_required
def protected_view1(request):
  return render(request, 'myapp/secret.html')

def protected_view2(request):
  return render(request, 'myapp/secret.html')

protected_view2 = login_required(protected_view2)
```

## 몇 가지 장고 기본 Decorators

- django.views.decorators.http

  - require_http_methods, require_GET, require_POST, require_safe
    - 지정 method가 아닐 경우, HttpResponseNotAllowed 응답 (상태코드 405) 반환

- django.contrib.auth.decorators

  - user_passes_test : 지정 함수가 False를 반환하면 login_url로 redirect
  - login_required : 로그아웃 상황에서 login_url로 redirect
  - permission_required : 지정 퍼미션이 없을 때 login_url로 redirect

- django.contrib.admin.views.decorators
  - staff_member_required : staff member가 아닐 경우 login_url로 이동

## CBV에 장식자 입히기 #1

- 가독성이 좋지 않아요.

- 요청을 처리하는 함수를 Wrapping하기

```py
from django.contrib.auth.decorators import login_required
from django.views.generic import TempalteView

class SecretView(TemplateView):
  template_name = 'myapp/secret.html'
v
iew_fn = SecretView.as_view()

secret_view = login_required(view_fn) # 이미 생성된 함수에 장식자 입힐 수도 있어요.
```

## CBV에 장식자 입히기 #2

- 괜히 dispatch 재정의

```py
from django.contrib.auth.decorators import login_required
from django.utils.decorators import method_decorator
from django.views.generic import TempalteView

class SecretView(TemplateView):
  template_name = 'myapp/secret.html'

  # 클래스 멤버함수에는 method_decorator를 활용
  @method_decorator(login_required)
  def dispatch(self, *args, **kwargs):
    return super().dispatch(*args, **kwargs)

secret_view = SecretView.as_view()
```

# 장고 기본 CBV API (Generic date views)

https://docs.djangoproject.com/en/3.0/ref/class-based-views/generic-date-based/

## Generic Date Views

- ArchiveIndexView : 지정 날짜필드 역순으로 정렬된 목록

- YearArchiveView : 지정 year년도의 목록

- MonthArchiveView : 지정 year/month 월의 목록

- WeekArchiveView : 지정 year/week 주의 목록

- DayArchiveView : 지정 year/month/day 일의 목록

- TodayArchiveView : 오늘 날짜의 목록

- DateDetailView : 지정 year/month/day 목록 중에서 특정 pk의 detail
  - DetailView와 비교 : URL에 year/month/day를 쓰고자 할 경우에 유용

## 공통 옵션

- allow_future (디폴트: False)
  - False : 현재시간 이후의 Record는 제외

## ArchiveIndexView

- 지정 날짜필드 역순으로 정렬된 목록 -> 최신 목록을 보고자 할 때

- 필요한 URL 인자 : 없음.

- 옵션

  - model
  - date_field : 정렬 기준 필드
  - date_list_period (디폴트: "year")

- 디폴트 template_name_suffix : "\_archive.html"

- Context
  - latest : QuerySet
  - date_list : 등록된 Record의 년도 목록

```py
from django.views.generic import ArchiveIndexView
from .models import Post

post_archive = ArchiveIndexView.as_view( model=Post, date_field='created_at')
```

# 적절한 HTTP 상태코드로 응답하기

## HTTP 상태코드

- 웹서버는 적절한 상태코드로서 응답해야 합니다.
- 각 HttpResponse 클래스마다 고유한 status_code가 할당 (코드) REST API를 만들 때, 특히 유용

```py
# django/http/response.py
class HttpResponseRedirect(HttpResponseRedirectBase):
  status_code = 302

from django.http import HttpResponse

def test_view(request):
  # Return a "created" (201) response code.
  return HttpResponse(status=201)
```

## 200 응답하는 몇 가지 예

```py
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render

def view1(request):
  return HttpResponse('Hello, Ask Company')

def view2(request):
  return render(request, 'template.html')

def view3(request):
  return JsonResponse({'hello': 'Ask Company'})
```

## 302 응답하는 몇 가지 예

```py
from django.http import HttpResponseRedirect
from django.shortcuts import redirect, resolve_url

def view1(request):
  return HttpResponseRedirect('/shop/')

def view2(request):
  url = resolve_url('shop:item_list') # 후에 배울 URL Reverse 적용
  return HttpResponseRedirect(url)

def view3(request):
  # 내부적으로 resolve_url 사용
  # 인자로 지정된 문자열이 url reverse에 실패할 경우,
  # 그 문자열을 그대로 URL로 사용하여, redirect 시도
  return redirect('shop:item_list')
```

## 404 응답하는 몇 가지 예

```py
from django.http import Http404, HttpResponseNotFound
from django.shortcuts import get_object_or_404
from shop.models import Item

def view1(request):
try:
item = Item.objects.get(pk=100)
    except Item.DoesNotExist:
        raise Http404
    # 생략

def view2(request):
  item = get_object_or_404(Item, pk=100) # 내부에서 raise Http404
  # 생략

def view3(request):
    try:
        item = Item.objects.get(pk=100)
    except Item.DoesNotExist:
        return HttpResponseNotFound()
        # 생략
    # 잘 쓰지 않는 방법
```

## 500 응답하는 몇 가지 예

- 뷰에서 요청 처리 중에, 뷰에서 미처 잡지못한 오류가 발생했을 경우
  - IndexError, KeyError, django.db.models.ObjectDoesNotExist 등

```py
from shop.models import Item

def view1(request):
  # IndexError
  name = ['Tom', 'Steve'][100]

  # 지정 조건의 Item 레코드가 없을 때, Item.DoesNotExist 예외
  # 지정 조건의 Item 레코드가 2개 이상 있을 때, Item.MultipleObjectsReturned 예외
  item = Item.objects.get(pk=100)
```

## 다양한 HttpResponse 서브 클래스

- 지정 상태코드의 응답이 필요할 때

- HttpResponseRedirect : 상태코드 302
- HttpResponsePermanentRedirect : 상태코드 301 (영구 이동)
- HttpResponseNotModified : 상태코드 304
- HttpResponseBadRequest : 상태코드 400
- HttpResponseNotFound : 상태코드 404
- HttpResponseForbidden : 상태코드 403
- HttpResponseNotAllowed : 상태코드 405
- HttpResponseGone : 상태코드 410
- HttpResponseServerError : 상태코드 500

# URL Reverse를 통해 유연하게 URL 생성하기

## URL Dispatcher

- urls.py 변경만으로 “각 뷰에 대한 URL”이 변경되는 유연한 URL 시스템

```py
# "/blog/", "/blog/1/" 주소로 서비스하다가
urlpatterns = [
  path('blog/', blog_views.post_list, name='post_list’),
  path('blog/<int:pk>/', blog_views.post_detail, name='post_detail'),
]

# 다음과 같이 변경을 하면,
# 이제 "/weblog/", "/weblog/1/" 주소로 서비스하게 됩니다.
urlpatterns = [
  path('weblog/', blog_views.post_list, name='post_list’),
  path('weblog/<int:pk>/', blog_views.post_detail, name='post_detail'),
]
```

## URL Reverse의 혜택

- 개발자가 일일이 URL을 계산하지 않아도 됩니다

- URL이 변경되더라도, URL Reverse가 변경된 URL을 추적 누락될 일이 없어요

## 직접 URL을 계산한다면

1. blog앱 Post목록을 볼려면, post_list 뷰를 호출해야하니깐,

2. urls.py 를 뒤적뒤적거리며, URL계산계산

3. 계산완료 ! -> /blog/ 주소를 쓰면 되겠네.

   ```html
   <!-- blog/templates/blog/layout.html 내에서의 링크 -->
   <a href="/blog/">블로그 글 목록</a>
   <!-- blog/templates/blog/post_form.html 내에서의 링크 -->
   <a href="/blog/">블로그 글 목록</a>
   <!-- blog/templates/blog/comment_form.html 내에서의 링크 -->
   <a href="/blog/">블로그 글 목록</a>
   ```

   그런데, 이 blog앱을 다른 프로젝트에도 쓸려고 옮겼는 데, URL Prefix를 weblog로 쓰고 싶어요.  
   하나하나 수정할 것인가? 그냥 안된다고 할 것인가?

   /blog/api/post/1001/comments/100/ 과 같은 URL을 외워서 쓸 것인가?

## URL 계산은 장고에게 양보하세요.

1. blog앱 Post목록을 볼려면, post_list 뷰를 호출해야하니깐,

2. ~~urls.py 를 뒤적뒤적거리며, URL계산계산~~

3. ~~계산완료 -> /blog/ 주소를 쓰면 되겠네.~~

그런데, 이 blog앱을 다른 프로젝트에도 쓸려고 옮겼는데, URL Prefix를 weblog로 쓰고 싶어요.  
하나하나 수정할 것인가? 그냥 안된다고 할 것인가?  
-> 코드 변경 거의 없이 가능합니다.

## URL Reverse를 수행하는 4가지 함수 (1)

- url 템플릿태그

  - 내부적으로 reverse 함수를 사용

- reverse 함수

  - 매칭 URL이 없으면 NoReverseMatch 예외 발생

- resolve_url 함수

  - 매핑 URL이 없으면 "인자 문자열"을 그대로 리턴
  - 내부적으로 reverse 함수를 사용

- redirect 함수
  - 매칭 URL이 없으면 "인자 문자열"을 그대로 URL로 사용
  - 내부적으로 resolve_url 함수를 사용

## URL Reverse를 수행하는 4가지 함수 (2)

```
{% url "blog:post_detail" 100 %} -> 문자열 URL
{% url "blog:post_detail" pk=100 %}
```

```
reverse('blog:post_detail', args=[100]) -> 문자열 URL
reverse('blog:post_detail', kwargs={'pk': 100})
```

```
resolve_url('blog:post_detail', 100) -> 문자열 URL
resolve_url('blog:post_detail', pk=100)
resolve_url('/blog/100/')
```

```
redirect('blog:post_detail', 100) -> HttpResponse 응답 (301 or 302)
redirect('blog:post_detail', pk=100)
redirect('/blog/100/')
```

## 모델 객체에 대한 detail 주소 계산

- 매번 다음과 같은 코드로 하실 수도 있겠지만,

  ```
  resolve_url('blog:post_detail', pk=post.pk)
  redirect('blog:post_detail', pk=post.pk)
  {% url 'blog:post_detail' post.pk %}
  ```

- 다음과 같이 사용하실 수도 있습니다. 어떻게?

  ```
   resolve_url(post)
   redirect(post)
   {{ post.get_absolute_url }}
  ```

## 모델 클래스에 get_absolute_url() 구현

- resolve_url 함수는 가장 먼저 get_absolute_url() 함수의 존재여부를 체크하고, 존재할 경우 reverse를 수행하지 않고 그 리턴값을 즉시 리턴

```py
 # django/shortcuts.py
def resolve_url(to, *args, **kwargs):
  if hasattr(to, 'get_absolute_url'):
    return to.get_absolute_url()
  # 중략
  try:
      return reverse(to, args=args, kwargs=kwargs)
  except NoReverseMatch:
        # 나머지 코드 생략
```

## resolve_url/redirect를 위한 모델 클래스 추가 구현

```py
from django.urls import reverse

class Post(models.Model):
  # 중략
  def get_absolute_url(self):
  return reverse('blog:post_detail', args=[self.pk])
```

## 그 외 활용

- CreateView / UpdateView
  - success_url을 제공하지 않을 경우, 해당 model instance 의 get_absolute_url 주소로 이동이 가능한지 체크하고, 이동이 가능할 경우 이동
  - 생성/수정하고나서 Detail화면으로 이동하는 것은 자연스러운 시나리오

- 특정 모델에 대한 Detail뷰를 작성할 경우
  - Detail뷰에 대한 URLConf설정을 하자마자, 필히 get_absolute_url설정을 해주세요. 코드가 보다 간결해집니다.