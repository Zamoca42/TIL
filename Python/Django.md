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

# 장고가 static 파일을 다루는 방법

## Media 파일

- FileField/ImageField를 통해 저장한 모든 파일
- DB필드에는 저장경로를 저장하며, 파일은 파일 스토리지에 저장
- 프로젝트 단위로 저장/서빙

## Static 파일

- 개발 리소스로서의 정적인 파일 (js, css, image 등)
- 앱 / 프로젝트 단위로 저장/서빙

## 장고 static 파일 경로

- 장고는 One Project, Multi App 구조
- 한 App을 위한 static 파일을 app/static/app경로에 둡니다.
- 프로젝트 전반적으로 사용되는 static 파일은 settings.STATICFILES_DIRS에 지정된 경로에 둡니다.
- 다수 디렉토리에 저장된 static 파일은 collectstatic 명령을 통해, settings.STATIC_ROOT에 지정한 경로로 모아서 (복사)해서 서비스에 사용

## Static 파일, 관련 settings 예시

- 각 설정의 디폴트 값

  - STATIC_URL = None
  - 각 static 파일에 대한 URL Prefix
    - 템플릿 태그 {% static “경로” %} 에 의해서 참조되는 설정
  - 항상 / 로 끝나도록 설정

- STATICFILES_DIRS = []

  - File System Loader에 의해 참조되는 설정

- STATIC_ROOT = None
  - python manage.py collectstatic 명령이 참조되는 설정
  - 여러 디렉토리로 나눠진 static파일들을 이 경로의 디렉토리로 복사하여, 서빙
  - 배포에서만 의미가 있는 설정

## 추천 settings

```py
STATIC_URL = '/static/'

STATIC_ROOT = os.path.join(BASE_DIR, 'static')

STATICFILES_DIRS = [
  os.path.join(BASE_DIR, 'askdjango', 'static'),
]
```

## Static Files Finders

- Template Loader와 유사

  - 설정된 Finders를 통해, static 템플릿이 있을 디렉토리 목록을 구성
    - 장고 서버 초기 시작 시에만 1회 작성
  - 디렉토리 목록에서 지정 상대경로를 가지는 static 파일 찾기.

- 대표적인 2가지 Static Files Finders
  - App Directories Finder
    - “장고앱/static/” 경로를 “디렉토리 목록”에 추가
  - File System Finder
    - settings.STATICFILES_DIRS 설정값을 “디렉토리 목록”에 추가

```py
STATICFILES_FINDERS = [
     'django.contrib.staticfiles.finders.FileSystemFinder’,
     'django.contrib.staticfiles.finders.AppDirectoriesFinder',
]
```

## 템플릿에서 static URL 처리 예시

- 방법1) settings.STATIC_URL, Prefix를 하드코딩하기

  - 하지만, settings.STATIC_URL 설정은 언제라도/프로젝트마다 변경될 수 있음. 하드코딩하는 것이 번거롭기도하고 변경이 되었을 때 하나하나 수정해줘야함.
  - 무엇보다, 배포 시에는 static_url 설정값이 변경됩니다.
    - 클라우드 정적 스토리지나 CDN 사용 시
    ```html
    <img src="/static/blog/title.png" />
    ```

- 방법2) Template Tag를 통한 처리

  - 프로젝트 설정에 따라, 유연하게 static url prefix가 할당됩니다.

  - ~~`<img src="/static/blog/title.png" />`~~

  ```html
  {% load static %} <img src="{% static "blog/title.png" %}" />
  ```

## 개발환경에서의 static 파일 서빙

- 개발서버를 쓰고, and settings.DEBUG = True 일 때에만, 지원

  - 프로젝트/urls.py에 Rule이 명시되어 있지 않아도, 자동 Rule 추가
  - 이는 순수 개발목적으로만 제공

- 개발서버를 쓰지 않거나, settings.DEBUG = False 일 때에는
  - 별도로 static 서빙 설정을 해줘야합니다.

```
myproj/static/main.css => http://localhost:8000/static/main.css 경로로 접근 가능

myproj/static/jquery/jquery-3.4.1.min.js => http://localhost:8000/static/jquery/jquery-3.4.1.min.js

myproj/static/bootstrap/4.3.1/css/bootstrap.min.css => http://localhost:8000/static/bootstrap/4.3.1/css/bootstrap.min.css

blog/static/blog/style.css => http://localhost:8000/static/blog/style.css 경로로 접근 가능

blog/static/blog/blog.js => http://localhost:8000/static/blog/blog.js 경로로 접근 가능

shop/static/shop/shop.js => http://localhost:8000/static/shop/shop.js 경로로 접근 가능
```

URL을 통해 파일시스템에 직접 접근하는 것이 아니라, 지정 이름의 STATIC 파일을 장고의 StaticFiles Finder에서 대신 찾아 그 내용을 읽어서 응답하는 것

## Static 서빙을 하는 여러가지 방법

1. 클라우드 정적 스토리지나 CDN 서비스를 활용

2. apache/nginx 웹서버 등을 통한 서빙

3. 장고를 통한 서빙
   - whitenoise 라이브러리를 활용해서 가능 -> http://whitenoise.evans.io -> Heroku 배포에 필요

## collectstatic 명령

- 실 서비스 배포 전에는 필히 본 명령을 통해, 여러 디렉토리에 나눠져있는 static 파일들을 한 곳으로 복사

  - 복사하는 대상 디렉토리 : settings.STATIC_ROOT

  - 왜냐하면, 여러 디렉토리에 나눠 저장된 static 파일들의 위치는 “현재 장고 프로젝트” 만이 알고 있음. 외부 웹서버는 전혀 알지 못함.

  - 외부 웹서버에서 Finder의 도움없이도 static 파일을 서빙하기 위함.

  - 한 디렉토리에 모두 모여있기에, Finder의 도움이 필요가 없음.

## 외부 웹서버에 의한 static/media 컨텐츠 서비스

- 정적인 컨텐츠는, 외부 웹서버를 통해 처리하면, 효율적인 처리

- 정적 컨텐츠만의 최적화 방법 사용
  - memcache/redis 캐시 등
  - CDN (Content Delivery Network)

## 배포 시에 static 처리 프로세스

1. “서비스용settings”에 배포 static 설정

2. 관련 클라우드 스토리지 설정, 혹은 아파치/nginx static 설정

3. 개발이 완료된 static파일을, 한 디렉토리로 복사

   - python manage.py collectstatic --settings=서비스용settings
     - Storage 설정에 따라, 한 번에 클라우드 스토리지로의 복사를 수행되기도 함.
   - settings.STATIC_ROOT 경로로 복사됨.

4. settings.STATIC_ROOT경로에 복사된 파일들을 배포서버로 복사

   - 대상 : 클라우드 스토리지, 혹은 아파치/nginx에서 참조할 경로

5. static 웹서버를 가리키토록 sesttings.STATIC_URL 수정

## 브라우저 캐싱

브라우저 캐시 기간을 설정해 주면 그 기간 동안은 웹브라우저가 해당 파일을 다시 다운받지 않고 캐싱된 내용을 사용하기 때문에 트래픽이 줄어들고, 속도도 빨라집니다.

- Expires 헤더 : 만료일시를 지정

  - Expires: Wed, 21 Oct 2015 07:28:00 GMT
  - 응답 내에 "max-age" 혹은 "s-maxage" directive를 지닌 Cache-Control 헤더가 존재할 경우, Expires 헤더는 무시

- Cache-Control : 보다 다양한 캐싱 정책 지정

## blog/style.css 조회 후에 변경된 파일이 반영되지 않을 경우

- 유저는 /blog/ 페이지에 방문하면서 브라우저에 /static/blog/style.css 파일이 다운로드되었습니다. 이때 이 파일이 24시간 동안 브라우저 캐싱이 되어있다고 생각해봅시다.

- 그런데, 개발하면서 CSS파일이 변경되었습니다. 파일경로는 바뀌지 않았습니다. 변경된 CSS파일이 유저페이지에 적용되길 원하지만 적용되지 않습니다. 캐싱된 이전 파일에 계속 접근하게 됩니다.

- 해결하기
  - 방법1) 해당 파일의 캐싱이 만료될 때까지 기다립니다.
  - 방법2) 브라우저 설정에서 캐싱된 내용을 삭제합니다. 크롬 브라우저에서는 "강력 새로고침"을 통해 수행 가능.
  - 방법3) 해당 STATIC 리소스의 URL을 변경합니다.

## 클라이언트측 캐싱과 빠른 업데이트를 할려면

리소스의 URL을 변경 -> 사용자가 새로이 다운로드

1. GET인자 붙이기 : 실제 파일명은 변경하지 않으면서, 브라우저가 인지하는 URL만 변경

   - 개발시에유용
   - 버전을 숫자로 붙이거나
   - http://localhost:8000/static/main.css?v=1
   - 버전을 날짜로 붙이거나
   - http://localhost:8000/static/main.css?v=20190503
   - 더미로 현재시각의 timestamp을 붙입니다.
   - http://localhost:8000/static/main.css?\_=1556908299

2. 파일명 변경하기
   - 서비스 배포 시에 유용

## 다양한 STATIC 리소스

- 직접 생성/등록한 CSS/JavaScript/Image 파일들

- 외부 CSS/JavaScript 라이브러리

  - CDN (Contents Delivery Network) 배포판 활용
  - 직접 다운로드&서빙
  - 자바스크립트 팩키지 관리자를 활용하여 다운로드&서빙

## CDN 배포판 활용

- 유명 라이브러리일 경우, 대개 CDN 배포판을 제공 개발 시에 빠른 적용을 위해서는 편리

```html
<link
  rel="stylesheet"
  href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
/>
<script src="https://code.jquery.com/jquery-3.4.1.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
```

- 안정적인 실서비스 제공을 위해서는 다운로드&서빙을 추천

  - 정적 파일 서빙을 "관리할 수 없는 외부 서비스"에 의존할 경우, 특정 유저의 해외망 접속이 원활하지 않거나, 해당 서비스 장애일 경우, 의도치않게 서비스 이용에 차질이 발생하게 됩니다.

- 직접 다운로드&서빙
  - 프로젝트 전반적으로 사용될 파일들이므로, filesystem static finder에서 접근하는 경로에 넣어두고, 버전관리 대상에도 추가
    - "프로젝트/static/" 경로
  - 수집된 파일들은 버전관리 대상에 넣지 않습니다.

# HTML Form

## 언제 쓰나요?

- HTML Form (클라이언트 측)

  - 클라이언트에서 사용자에게 입력폼을 제공하고, 이를 서버로 전송코자 할 때

- Django Form (서버 측)
  - 클라이언트로부터 전달받은 값들에 대한 유효성 검사를 수행하고, 이를 데이터베이스에 저장하는 등의 처리
  - HTML Form을 생성하는 기능을 제공합니다. 이를 활용하거나, 인터페이스만 맞춰 직접 HTML Form을 코딩해도 OK.

## HTML Form

- HTML 웹페이지에서는 `<form></form>` 태그를 통해, 입력폼을 구성하고, submit시에 지정 action URL로 데이터 전송을 시도

  - ex) 로그인 폼, 댓글 폼

- 하나의 `<form>`태그는 하나 이상의 Widget을 가집니다.

```html
<form action="" method="POST">
  <input type="text" />
  <textarea></textarea>
  <select></select>
  <input type="checkbox" />
  <input type="radio" />
  그 외 다수 위젯
</form>
```

## HTML <form> 태그 필수 속성

- action : 요청을 보낼 주소
- method : 전송 방식
  - "GET" : 주로 데이터 조회 요청 시에 사용
  - "POST" : 파괴적인 액션(생성/수정/삭제)에서 사용
- enctype : 인코딩 방식
  - POST 요청에서만 유효
  - GET 요청에서는 한 enctype으로 강제됨.

## `<form>`의 enctype

- "application/x-www-form-urlencoded" (디폴트)
  - GET 요청에서는 이 유형이 강제됨.
  - 인자들을 "URL 인코딩"을 수행하여, QueryString 형태로 전달
    - 파일 업로드 불가
- "multipart/form-data"

  - 파일 업로드 가능.

- "text/plain"
  - 실제로 사용되지는 않는 유형
  - 공백만 "+"로 변환

# Form Method

## Form 요청에서 인자 보내는 2가지 방법

1. 요청 URL 뒤에 ? 를 붙이고, 인자를 실어서 보내기.

   - x-www-form-urlencoded 인코딩의 값만 실을 수 있습니다.
   - 이 인자를 Query String 인자라고 부릅니다.
   - GET요청에서 주로 사용하기에 GET 인자라고도 합니다.
     - POST 요청에서도 요청 URL 뒤에 QueryString을 실을 수 있습니다.

2. 요청 Body에 모든 인코딩의 인자를 실어서 보냅니다.
   - x-www-form-urlencoded 인코딩의 값도 OK
   - multipart/form-data 인코딩의 값도 OK -> 파일 업로드 가능

## 2가지 Form Method

- GET 방식

  - 엽서에 비유. 물건을 보낼 수 없다.
  - application/x-www-form-urlencoded 만이 강제되며, 인코딩된 문자열을 QueryString으로 전달

- POST 방식
  - 택배에 비유. 다양한 물건을 보낼 수 있다.
  - 다양한 인코딩을 모두 사용 가능하며 (application/x-www-form-urlencoded 및 multipart/form-data), 인코딩된 데이터를 "요청 Body"에 담아서 전달

## 장고 뷰에서의 인자 접근

- request.GET

  - 모든 QueryString 인자 목록
    - QueryString을 파싱한 QueryDict 객체
  - GET/POST 요청에서 모두 가능

- request.POST

  - POST 요청에서만 가능.
  - 파일 내역은 제외한 모든 POST인자 목록
    - "요청 BODY"를 파싱한 QueryDict 객체

- request.FILES
  - POST 요청에서만 가능.
  - "요청 BODY"에서 파일내역만 파싱한 MultiValueDict 객체

# HttpRequest와 HttpResponse

## HttpRequest 객체

- 클라이언트로부터의 모든 요청 내용을 담고 있으며

  - 함수 기반 뷰 : 매 요청 시마다 뷰 함수의 첫번째 인자 request로 전달
  - 클래스 기반 뷰 : 매 요청 시마다 self.request를 통해 접근

- Form 처리 관련 속성들
  - .method : 요청의 종류 "GET" 또는 "POST" 로서 모두 대문자
  - .GET : GET 인자 목록 (QueryDict타입)
  - .POST : POST 인자 목록 (QueryDict타입)
  - .FILES : POST 인자 중에서 파일 목록 (MultiValueDict 타입)

## MultiValueDict (1)

- dict을 상속받은 클래스
- 동일 key의 다수 value를 지원하는 사전
  - http 요청에서는 하나의 key에 대해서 여러 값을 전달받을 수 있어야만 합니다.
  - URL의 QueryString은 같은 Key로서 다수 Value지정을 지원 ex) name=Tom&name=Steve&name=Tomi

## MultiValueDict (2)

- 동일 Key의 다수 Value를 지원하는 사전

```
>>> from django.utils.datastructures import MultiValueDict

>>> d = MultiValueDict({'name': ['Adrian', 'Simon'], 'position': ['Developer']})

>>> d['name'] # dict과 동일하게 동작. 단일값을 획득
'Simon'

>>> d.getlist('name') # 다수값 획득을 시도. 리스트를 반환
['Adrian', 'Simon']
>>> d.getlist('doesnotexist') # 없는 Key에 접근하면 빈 리스트를 반환
[]

>>> d['name'] = 'changed'
>>> d
<MultiValueDict: {'name': ['changed'], 'position': ['Developer']}>
```

## MultiValueDict (3)

수정 불가능한 (Immutable) 특성

```
# 아래 코드는 Django Shell을 통해서 실행이 가능

>>> from django.http import QueryDict

>>> qd = QueryDict('name=Adrian&name=Simon&position=Developer', encoding='utf8')

>>> qd['name']
'Simon'

>>> qd.getlist('name')
['Adrian', 'Simon']

>>> qd['name'] = 'changed'
AttributeError: This QueryDict instance is immutable
```

## QueryDict

- 수정불가능한 MultiValueDict

```py
class QueryDict(MultiValueDict):
    _mutable = True
    _encoding = None

    def __init__(self, query_string=None, mutable=False, encoding=None):
        # ...
        self._mutable = mutable

    def _assert_mutable(self):
        if not self._mutable:
            raise AttributeError("This QueryDict instance is immutable")

    def __setitem__(self, key, value):
        self._assert_mutable()
        # ...

    def __delitem__(self, key):
        self._assert_mutable()
        # ...
  # ...
```

## django.http.HttpResponse (1)

- 다양한 응답을 Wrapping : HTML문자열, 이미지 등등
- View에서는 반환값으로서 HttpResponse 객체를 기대
  - Middleware에서 HttpResponse 객체를 기대

```py
# 프로젝트/settings
MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
]
```

# Form

- 장고를 더욱 장고스럽게 만들어주는 주옥같은 Feature
- 주요 역할
  - 입력폼 HTML 생성
  - 입력폼 값에 대한 유효성 검증 (Validation) 및 값 변환
  - 검증을 통과한 값들을 dict형태로 제공

```py
# myapp/forms.py
from django import forms

class PostForm(forms.Form):
    title = forms.CharField()
    content = forms.CharField(widget=form.Textarea)
```

## Django Style의 Form 처리 (1)

- 하나의 URL (하나의 View)에서 2가지 역할을 모두 수행
  1. 빈 폼을 보여주는 역할과
  2. 폼을 통해 입력된 값을 검증하고 저장하는 역할

## Django Style의 Form 처리 (2)

- GET 방식으로 요청받았을 때

  - New/Edit 입력폼을 보여줍니다.

- POST 방식으로 요청받았을 때
  - 데이터를 입력받아 (request.POST, request.FILES) 유효성 검증 수행
  - 검증 성공 시 : 해당 데이터를 저장하고 SUCCESS URL로 이동
  - 검증 실패 시 : 오류메세지와 함께 입력폼을 다시 보여줍니다.

```py
def post_new(request):
 if request.method == 'POST':
     form = PostForm(request.POST, request.FILES)
     if form.is_valid():
         post = Post(**self.cleaned_data)
         post.save()
         return redirect(post)
 else:
     form = PostForm()
 return render(request, 'blog/post_form.html', {
     'form': form,
})
```

## 1) Form/ModelForm 클래스 정의

```py
# myapp/forms.py
from django import forms
class PostForm(forms.Form):
    title = forms.CharField()
    content = forms.CharField(widget=form.Textarea)
```

## 2) 필드 별로 유효성 검사 함수 추가 적용

- Form의 경우

```py
# myapp/forms.py
from django import forms

def min_length_3_validator(value):
    if len(value) < 3:
      raise forms.ValidationError('3글자 이상 입력해주세요.')

class PostForm(forms.Form):
    title = forms.CharField(validators=[min_length_3_validator])
    content = forms.CharField(widget=form.Textarea)
```

- ModelForm의 경우

```py
# myapp/models.py
from django import forms
from django import models

def min_length_3_validator(value):
    if len(value) < 3:
      raise forms.ValidationError('3글자 이상 입력해주세요.')

class Post(forms.Model):
    title = models.CharField(max_length=100, validators=[min_length_3_validator])
    content = models.TextField()

# myapp/forms.py
from django import forms
from .models import Post

class PostForm(forms.ModelForm):
    class Meta:
        model = Post
        fields = '__all__'
```

## 3) View 함수 내에서 method에 따라 Form 객체 생성

- if 조건체크를 POST에 대해 먼저 체크하는 것은 장고 스타일. GET요청은 Form 인스턴스 생성 이외에 특별한 루틴이 없어서인듯.

```py
# myapp/views.py
from .forms import PostForm

if request.method == 'POST':
  #POST요청일때
  form = PostForm(request.POST, request.FILES)
else: #GET요청일때
     form = PostForm()
```

## 4) POST 요청에 한해 입력값 유효성 검증

```py
if request.method == 'POST':
  # POST인자는 request.POST와 request.FILES를 제공받음.
  form = PostForm(request.POST, request.FILES)

  #인자로받은값에대해서,유효성검증수행
  if form.is_valid(): # 검증이 성공하면, True 리턴
    # 검증에 성공한 값들을 사전타입으로 제공받음.
    # 검증에 성공한 값을 제공받으면, Django Form의 역할은 여기까지 !!! #필요에따라,이값을DB에저장하기
    form.cleaned_data

    post = Post(**form.cleaned_data) # DB에 저장하기
    post.save()

    return redirect('/success_url/')
  else: # 검증에 실패하면, form.errors와 form.각필드.errors 에 오류정보를 저장
      form.errors
else: # GET 요청일 때
  form = PostForm()
  return render(request, 'myapp/form.html', {'form': form})
```

## 5) 템플릿을 통해 HTML 폼 노출

1. GET요청일 때

   - 유저가 Form을 채우고 Submit -> POST 요청

2. POST요청이지만 유효성 검증에서 실패했을 때
   - Form 인스턴스를 통해 HTML폼 출력
   - 오류메세지도 있다면 같이 출력
     - 유저가 Form을 채우고 Submit -> POST 재요청

```html
<table>
  <form action="" method="post">
    {% csrf_token %}
    <table>
      {{ form.as_table }}
    </table>
    <input type="submit" />
  </form>
</table>
```

## Form Fields

- Model Fields 와 유사

  - Model Fields : Database Field 들을 파이썬 클래스화
  - Form Fields : HTML Form Field 들을 파이썬 클래스화

- 필드 종류
  - BooleanField, CharField, ChoiceField, DateField, DateTimeField, EmailField, FileField, ImageField, FloatField, IntegerField, RegexField 등

# 사이트 간 요청 위조 공격 (Cross Site Request Forgery)

- 사용자가 의도하지 않게 게시판에 글을 작성하거나, 쇼핑을 하게 하는 등의 공격
  - 특정 웹사이트가 유저의 웹브라우저를 신용하는 상태를 노린 것

```html
<!-- 공격자 사이트의 웹페이지에 접속하면, 그 즉시 site-victim.com로의 POST 요청이 사용자 모르게 전달됩니다. -->
<body onload="document.attack_form.submit();">
  <form name="attack_form" method="post" action="http://site-victim.com/new/">
    <input type="hidden" name="title" value="스팸 제목" />
    <input type="hidden" name="content" value="스팸 내용" />
  </form>
</body>

<img src="http://site-victim.com/travel/102/update/?src=Bali&dest=Korea" />
```

## 공격를 막기 위해 Token을 통한 체크

- 요청을 받는 서버 입장에서, POST 요청에 한해 CsrfViewMiddleware를 통한 체크

  - POST 요청을 받을 때 Token값이 없거나 유효하지 않다면, 403 Forbidden 응답

- 처리 순서

  1.  입력 Form을 보여줄 때, CSRF Token값도 값이 할당

      - CSRF Token은 User마다 다르며, 계속 변경됩니다.

  2.  그 입력 Form을 통해 Token값이 전달이 되면, Token 유효성 검증

## 이를 적용하기 위한 단 1줄의 코드

- 장고 프로젝트 기본 세팅으로 CsrfViewMiddleware가 적용되어있습니다.

```html
<form action="" method="post">
  {% csrf_token %}
  <input type="text" name="title" />
  <textarea name="content"></textarea> <input type="submit" />
</form>

<input type="hidden" name="csrfmiddlewaretoken" value="......" />
```

## 주의사항

- CSRF Token != 유저인증 Token
- CSRF Token != JWT (JSON Web Token)
- CSRF Token == 현재 요청이 유효한지 체크하는 토큰

## CSRF Token 체크 기능을 끈다 ???

- 가급적이면 끄지 마세요.

  - 기본 제공되는 보안기능이며,
  - 이를 유지하는 데에 비용이 거의 들지 않는다.

- 특정 View에 한해, CSRF Token 체크에서 배제할려면?
  - 해당 뷰에 @csrf_exempt 장식자를 적용

```py
from django.views.decorators.csrf import csrf_exempt

 @csrf_exempt
def post_new_for_api(request):
# blah blah blah ...
```

## 앱 API에서는 꺼주세요.

- django-rest-framework의 APIView에서는 csrf_exempt가 적용되어있습니다.

```py
 class APIView(View):
     # ...
    @classmethod
    def as_view(cls, **initkwargs):
      # ...
      view = super().as_view(**initkwargs)
      view.cls = cls
      view.initkwargs = initkwargs

      # Note: session based authentication is explicitly CSRF validated,
      # all other authentication is CSRF exempt.
      return csrf_exempt(view)
```

## ModelForm

- 장고 Form을 상속

- 지정된 Model로부터 필드정보를 읽어들여, Form Fields를 세팅

- 내부적으로 Model Instance를 유지

- 유효성 검증에 통과한 값들로, 지정 Model Instance로의 저장(save) 지원 (Create 또는 Update)

```py
class PostForm(forms.ModelForm):
     class Meta:
        model = Post
        #전체필드지정.혹은list로읽어올필드명지정
        fields = '__all__'
```

## Form/ModelForm

```py
from django import forms
from .models import Post

class PostForm(forms.Form):
    title = forms.CharField()
    content = forms.CharField(widget=forms.Textarea)

# 생성되는 Form Field는 PostForm과 거의 동일
class PostModelForm(forms.ModelForm):
    class Meta:
        model = Post
        fields = ['title', 'content']
```

## ModelForm.save(commit=True)

- Form의 cleaned_data를 Model Instance 생성에 사용하고, 그 Instance를 리턴

- commit=True

  - model instance의 save() 및 form.save_m2m()을 호출
  - form.save() != instance.save()

- commit=False
  - instance.save() 함수 호출을 지연시키고자할 때 사용

## ModelForm.save 컨셉 구현

```py
from django import forms
from .models import Post

class PostForm(forms.Form):
    title = forms.CharField()
    content = forms.CharField(widget=forms.Textarea)

    def save(self, commit=True):
        post = Post(**self.cleaned_data)
        if commit:
           post.save()
        return post
```

## View에서의 ModelForm 처리 (New)

```py
from django.shortcuts import render
from .forms import PostModelForm
from .models import Post

def post_new(request):
    if request.method == 'POST':
        form = PostModelForm(request.POST, request.FILES)
        if form.is_valid():
            post = form.save()
            return redirect(post)
    else:
        form = PostModelForm()
    return render(request, 'myapp/post_form.html', {
        'form': form,
    })
```

## View에서의 ModelForm 처리 (Edit)

```py
from django.shortcuts import get_object_or_404, render
from .forms import PostModelForm
from .models import Post

def post_edit(request, pk):
    post = get_object_or_404(Post, pk=pk)

    if request.method == 'POST':
        form = PostModelForm(request.POST, request.FILES, instance=post)
        if form.is_valid():
            post = form.save()
            return redirect(post)
    else:
        form = PostModelForm(instance=post)
    return render(request, 'myapp/post_form.html', {
        'form': form,
    })
```

## ModelForm.save(commit=False) 예시 (1)

```py
from django.db import models

class Comment(models.Model):
    author = models.CharField(max_length=20)
    message = models.TextField()
    ip = models.CharField(max_length=15)

# myapp/forms.py
class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        # ip필드는 유저로부터 입력받지 않고, 프로그램으로 채워넣을 것이기에 제외
        fields = ['author', 'message']
```

## ModelForm.save(commit=False) 예시 (2)

```py
def comment_new(request):
    if request.method == 'POST':
        form = CommentForm(request.POST, request.FILES)
        if form.is_valid():
          comment = form.save(commit=False)
          comment.ip = request.META['REMOTE_ADDR'] # IP를 기록하고 comment.save() # save() return redirect('/')
    else:
      form = CommentForm()

    return render(request, 'myapp/comment_form.html', {'form': form})
```

## ModelForm.save(commit=False) 예시 (3)

```py
def comment_edit(request, pk):
    comment = get_object_or_404(Comment, pk=pk)

    if request.method == 'POST':
        form = CommentForm(request.POST, request.FILES, instance=comment)
        if form.is_valid():
            comment = form.save()
            return redirect('/')
    else:
        form = CommentForm(instance=comment)
    return render(request, 'myapp/comment_form.html', {'form': form})
```

## 당부: Form을 끝까지 써주세요.

```py
form = CommentForm(request.POST)
if form.is_valid():
    # request.POST : 폼 인스턴스 초기 데이터
    message = request.POST['message'] # request.POST를 통한 접근 : BAD !!!
    comment = Comment(message=message)
    comment.save()
return redirect(post)

              form = CommentForm(request.POST)
              if form.is_valid():
                  # form.cleaned_data : 폼 인스턴스 내에서 clean함수를 통해 변환되었을 수도 있을 데이터
                  message = form.cleaned_data['message'] # form.cleaned_data를 통한 접근 : GOOD !!!
                  comment = Comment(message=message)
                  comment.save()
              return redirect(post)
```

# Form Validation

## Form 유효성 검사가 수행되는 시점

```py
# myapp/views.py
def post_new(request):
    if request.method == 'POST':
      form = PostForm(request.POST, request.FILES)
      if form.is_valid(): # 유효성 검사가 수행됩니다.
        form.save()
        # SUCCESS 후 처리
      else:
        form = PostForm()
      # ...
```

## 유효성 검사 호출 로직

- form.is_valid() 호출 당시

1. form.full_clean() 호출

   1. 각필드객체별로

   - 각 필드객체.clean() 호출을 통해 각 필드 Type에 맞춰 유효성 검사

   2. Form 객체 내에서

   - 필드 이름 별로 Form객체.clean\_필드명() 함수가 있다면 호출해서 유효성 검사
   - Form객체.clean() 함수가 있다면 호출해서 유효성 검사

2. 에러 유무에 따른 True/False 리턴

## Form에서 수행하는 2가지 유효성 검사

1. Validator 함수를 통한 유효성 검사

   - 값이 원하는 조건에 맞지 않을 때, ValidationError 예외를 발생
     - 주의: 리턴값은 사용되지 않습니다.

2. Form 클래스 내 clean, clean\_ 멤버함수를 통한 유효성 검사 및 값 변경
   - 값이 원하는 조건에 맞지 않을 때, ValidationError 예외를 발생
   - 리턴값을 통해 값 반환

## ValidationError 예외가 발생되면 ...

```py
@html_safe
class BaseForm:
  # 중략
  def _clean_fields(self):
    for name, field in self.fields.items():
      if field.disabled:
        value = self.get_initial_for_field(field, name)
      else:
        value = field.widget.value_from_datadict(self.data, self.files, self.add_prefix(name))
      try:
        if isinstance(field, FileField):
          initial = self.get_initial_for_field(field, name)
          value = field.clean(value, initial)
        else:
            value = field.clean(value)
        self.cleaned_data[name] = value
        if hasattr(self, 'clean_%s' % name):
          value = getattr(self, 'clean_%s' % name)()
          self.cleaned_data[name] = value
      except ValidationError as e:
        self.add_error(name, e)
```

## 함수형/클래스형 Validator (1)

- 함수형
  - 유효성 검사를 수행할 값 인자를 1개 받은 Callable Object
- 클래스형
  - 클래스의 인스턴스가 Callable Object

## 함수형/클래스형 Validator (2)

```py
@deconstructible
class RegexValidator:
  regex = ''
  # 중략

  def __call__(self, value):
    regex_matches = self.regex.search(str(value))
    invalid_input = regex_matches if self.inverse_match else not regex_matches
    if invalid_input:
      raise ValidationError(self.message, code=self.code)

integer_validator = RegexValidator(
  _lazy_re_compile(r'^-?\d+\Z'),
  message=_('Enter a valid integer.'),
  code='invalid',
)

def validate_integer(value):
  return integer_validator(value)

```

## 모델 필드 정의 시에 지정

```py
import re
from django.db import models
from django.forms import ValidationError

def phone_number_validator(value):
  if not re.match(r'^010[1-9]\d{7}$'):
    raise ValidationError('{} is not an phone number'.format(value))

class Profile(models.Model):
  phone_number = models.CharField(max_length=11,
                                  validators=[phone_number_validator])

class ProfileForm(forms.ModelForm):
  class Meta:
        model = Profile
        fields = '__all__'
```

## Form 필드 정의 시에 지정

```py
import re
from django import forms
from django.forms import ValidationError

def phone_number_validator(value):
  if not re.match(r'^010[1-9]\d{7}$'):
    raise ValidationError('{} is not an phone number'.format(value))

class ProfileForm(forms.Form):
  phone_number = forms.CharField(validators=[phone_number_validator])
```

## ModelForm이지만, Form Field 직접 지정

```py

import re
from django.db import models
from django.forms import ValidationError

def phone_number_validator(value):
  if not re.match(r'^010[1-9]\d{7}$'):
    raise ValidationError('{} is not an phone number'.format(value))

class Profile(models.Model):
  phone_number = models.CharField(max_length=11)

class (forms.ModelForm):
    phone_number = forms.CharField(validators=[phone_number_validator])
    class Meta:
        model = Profile
        fields = '__all__'
```

## 빌트인 Validators (1)

- RegexValidator
- EmaiValidator
- URLValidator
- valiate_email
- validate_slug
- validate_unicode_slug
- validate_ipv4_address, validate_ipv6_address, validate_ipv46_address validate_comma_separated_integer_list
- int_list_validator

## 빌트인 Validators (2)

- MaxValueValidator
- MinValueValidator
- MaxLengthValidator
- MinLengthValidator
- DecimalValidator
- FileExtensionValidator : 파일 확장자 허용 여부
  - 주의 : 확장자만으로 정확히 그 포맷 임을 확정할 수는 없습니다.
- validate_image_file_extension
  - 이미지 확장자 여부. Pillow 설치 필수
- ProhibitNullCharactersValidator : 문자열에 '\x00' 포함여부

## 모델 필드에 디폴트 적용된 validators

- models.EmailField (CharField)
  - validators.validate_email 적용
- models.URLField
  - validators.URLValidator() 적용
- models.GenericIPAddressField
  - validators.ip_address_validators 적용
- models.SlugField
  - validators.validate_slug 적용

## Form clean 멤버함수

- 기대하는 것

1. "필드별 Error 기록" 혹은 "Non 필드 Error 기록"

   - 값이 조건에 안 맞으면 ValidationError 예외를 통해 오류 기록
   - 혹은 add_error(필드명, 오류내용) 직접 호출을 통해 오류 기록

2. 원하는 포맷으로 값 변경

   - 리턴값을 통해 값 변경하기

## 멤버 함수별, 검사/변경의 책임

- `clean_필드명()` 멤버함수

  - 특정 필드별 검사/변경의 책임
  - ValidationError 예외 발생 시, 해당 필드 Error로 분류

- clean() 멤버함수
  - 다수 필드에 대한 검사/변경의 책임
  - ValidationError 예외 발생 시, non_field_errors로 분류
  - add_error(...) 함수를 통해 필드별 Error 기록도 가능

## 언제 validators를 쓰고, 언제 clean을?

- 가급적이면 모든 validators는 모델에 정의하고, ModelForm을 통해 모델의 validators 정보도 같이 가져오세요.

- clean이 필요할 때
- 특정 Form에서 1회성 유효성 검사 루틴이 필요할 때
- 다수 필드값에 걸쳐서, 유효성 검사가 필요할 때
- 필드 값을 변경할 필요가 있을 때
  - validator는 값만 체크할 뿐, 값을 변경할 수는 없습니다.

## 샘플 코드

```py
# myapp/models.py
class GameUser(models.Model):
  server = models.CharField(max_length=10)
  username = models.CharField(max_length=20)

# myapp/forms.py
class GameUserSignupForm(forms.ModelForm):
  class Meta:
    model = GameUser
    fields = ['server', 'username']

  def clean_username(self):
    'username 필드값의 좌/우 공백을 제거하고, 최소 3글자 이상 입력되었는 지 체크'
    username = self.cleaned_data.get('username', '').strip()
    if len(username) < 3:
      raise forms.ValidationError('3글자 이상 입력해주세요.')
    # 이 리턴값으로 self.cleaned_data['username'] 값이 변경됩니다.
    # 좌/우 공백이 제거된 (strip) username으로 변경됩니다.
    return username

  def clean(self):
    cleaned_data = super().clean()
    if self.check_exist(cleaned_data['server'], cleaned_data['username']):
      # clean내 ValidationError는 non_field_errors 로서 노출
      raise forms.ValidationError('서버에 이미 등록된 username입니다.')
    return cleaned_data

def check_exist(self, server, username):
  return GameUser.objects.filter(server=server, username=username).exists()
```

## 개선된 코드

```py
from django.core.validators import MinLengthValidator

class GameUser(models.Model):
  server = models.CharField(max_length=10)
  username = models.CharField(max_length=20, validators=[MinLengthValidator(3)])

  class Meta:
      unique_together = [
          ('server', 'username'),
      ]

class GameUserSignupForm(forms.ModelForm):
  class Meta:
    model = GameUser
    fields = ['server', 'username']

  def clean_username(self):
  '''값 변환은 clean함수에서만 가능합니다.
  validator에서는 지원하지 않습니다.'''
  return self.cleaned_data.get('username', '').strip()
```

# Messages Framework

> https://docs.djangoproject.com/en/3.0/ref/contrib/messages/

- 현재 User를 위한 1회성 메시지를 담는 용도
  - ex) "저장했습니다.", "로그인되었습니다."
- HttpRequest 인스턴스를 통해 메시지를 남깁니다.
  - 즉, View에서만 사용 가능
- 메시지를 1회 노출이 되고 사라집니다.
- View를 통한 템플릿 시스템을 통해 노출을 하며, 템플릿 내에서 JavaScript를 통한 노출도 가능

## Message Levels를 통한 메시지 분류

- 파이썬 로깅 모듈의 Level을 차용
- 레벨에 따라 로깅 여부 판단
  - 혹은 템플릿에서 다른 스타일로 노출
- 레벨 종류
  - DEBUG : 디폴트 설정으로 무시되는 레벨
    - 개발관련된 메세지이며, 실서비스에서는 무시
- INFO : 해당 유저에 대한 정보성 메세지
- SUCCESS : 액션이 성공적으로 수행되었음을 알림.
- WARNING : 실패가 아직 발생하진 않았지만, 임박했다.
- ERROR : 액션이 수행되지 않았거나, 다른 Failure가 발생했다.

## messages 등록 코드

```py
# blog/views.py
from django.contrib import messages

def post_new(request):
  # 중략
    if form.is_valid():
        post = form.save()
        messages.add_message(request, messages.SUCCESS, '새 글이 등록되었습니다.')
        messages.success(request, '새 글이 등록되었습니다.') # 혹은 shortcut 형태
        return redirect(post)
    # 생략
```

## messages 소비

- 주로 템플릿을 통해서 소비

- messages context_processors를 통해 messages 목록에 접근
  - .tags 속성을 통해 레벨을 제공
  - .message 속성을 통해 내용을 제공 (= str(message))

```html
{% if messages %}
<ul class="messages">
  {% for message in messages %}
  <li>{{ message.tags }}] {{ message.message }}</li>
  {% endfor %}
</ul>
{% endif %}
```

## 참고) Context Processors

> https://github.com/django/django/blob/2.1/django/template/context.py#L246

- 템플릿 기본 로딩 변수목록을 생성해주는 함수 목록

```py
# 프로젝트/settings.py
TEMPLATES = [{
    'BACKEND': 'django.template.backends.django.DjangoTemplates',
    'DIRS': [],
    'APP_DIRS': True,
    'OPTIONS': {
        'context_processors': [
           'django.template.context_processors.debug',
           'django.template.context_processors.request',
           'django.contrib.auth.context_processors.auth',
           'django.contrib.messages.context_processors.messages',
           ],
    },
}]
```

```py
from django.contrib.messages.api import get_messages
from django.contrib.messages.constants import DEFAULT_LEVELS

def messages(request):
    return {
      'messages': get_messages(request),
      'DEFAULT_MESSAGE_LEVELS': DEFAULT_LEVELS,
    }
```

## 출력 tags 변경하기

- 프로젝트/settings.py

```py
from django.contrib.messages import constants as messages_constants

MESSAGE_TAGS = {
  messages_constants.DEBUG: 'secondary',
  messages_constants.ERROR: 'danger',
}
```

## MESSAGE_LEVEL 변경하기

- 메세지 노출 최소 레벨 (프로젝트/settings.py)

```py
from django.contrib.messages import constants as messages_constants

# MESSAGE_LEVEL = messages_constants.INFO # 디폴트 설정
MESSAGE_LEVEL = messages_constants.DEBUG
```

## 기본 Form/Messages 템플릿

```html
{# Load the tag library #} {% load bootstrap4 %} {# Load CSS and JavaScript #}
{% bootstrap_css %} {% bootstrap_javascript jquery='full' %} {# Display
django.contrib.messages as Bootstrap alerts #} {% bootstrap_messages %} {#
Display a form #}
<form action="/url/to/submit/" method="post" class="form">
  {% csrf_token %} {% bootstrap_form form %} {% buttons %}
  <button type="submit" class="btn btn-primary">Submit</button>
  {% endbuttons %}
</form>
```

# built-in CBV를 통한 Form 처리

<img src="https://user-images.githubusercontent.com/96982072/170999366-9ea69466-129a-45f0-b0f4-7143bd217b35.png">

## ProcessFormView

```py
class ProcessFormView(View):
  """Render a form on GET and processes it on POST."""
  def get(self, request, *args, **kwargs):
    """Handle GET requests: instantiate a blank version of the form."""
    return self.render_to_response(self.get_context_data())

def post(self, request, *args, **kwargs):
  """ Handle POST requests: instantiate a form instance with the passed POST variables and then check if it's valid."""
  form = self.get_form()
  if form.is_valid():
    return self.form_valid(form)
  else:
    return self.form_invalid(form)
# PUT is a valid HTTP verb for creating (with a known URL) or editing an
# object, note that browsers only support POST for now.

def put(self, *args, **kwargs):
  return self.post(*args, **kwargs)

class FormMixin(ContextMixin):
  # 생략 ...
  def get_context_data(self, **kwargs):
     if 'form' not in kwargs:
      kwargs['form'] = self.get_form()
      return super().get_context_data(**kwargs)
```

## Create 구현의 다양한 예 #1

```py
def post_new(request):
    if request.method == 'POST':
      form = PostForm(request.POST, request.FILES)
      if form.is_valid():
            object = form.save()
            return redirect(object)
    else:
      form = PostForm()
    return render(request, "myapp/post_form.html", {
        "form": form,
    })
```

```html
<form action="" method="post">
  {% csrf_token %}
  <table>
    {{ form }}
  </table>
  <input type="submit" />
</form>
```

## Create 구현의 다양한 예 #2

```py
from django.shortcuts import resolve_url
from django.views.generic import FormView
from .forms import PostForm

class PostCreateView(FormView):
  form_class = PostForm
  template_name = 'myapp/post_form.html'

def form_valid(self, form):
  self.object = form.save() # CBV ModelFormMixin에서 구현된 부분
  return super().form_valid(form)

def get_success_url(self):
  # 주의: Post모델에 get_absolute_url() 멤버함수 구현 필요
  return resolve_url(self.object)
  # return self.post.get_absolute_url() # 대안 1
  # return reverse('blog:post_detail', args=[self.post.id]) # 대안 2

post_new = PostCreateView.as_view()
```

## Create 구현의 다양한 예 #3/#4

```py

#3

from django.views.generic import CreateView
from .forms import PostForm

class PostCreateView(CreateView):
  form_class = PostForm

post_new = PostCreateView.as_view()
```

```py

#4

from django.views.generic import CreateView
from .models import Post

class PostCreateView(CreateView):
  model = Post

post_new = PostCreateView.as_view()
```

## CreateView와 UpdateView (1)

```py
class CreateView(SingleObjectTemplateResponseMixin, BaseCreateView):
  """
  View for creating a new object, with a response rendered by a template.
  """
  template_name_suffix = '_form'

class BaseCreateView(ModelFormMixin, ProcessFormView):
  """
  Base view for creating a new object instance.
  Using this base class requires subclassing to provide a response mixin.
  """
  def get(self, request, *args, **kwargs):
    self.object = None
    return super().get(request, *args, **kwargs)

  def post(self, request, *args, **kwargs):
    self.object = None
    return super().post(request, *args, **kwargs)
```

## CreateView와 UpdateView (2)

```py
class UpdateView(SingleObjectTemplateResponseMixin, BaseUpdateView):
  """View for updating an object, with a response rendered by a template."""
  template_name_suffix = '_form'

class BaseUpdateView(ModelFormMixin, ProcessFormView):
  """
  Base view for updating an existing object.
  Using this base class requires subclassing to provide a response mixin.
  """
  def get(self, request, *args, **kwargs):
    self.object = self.get_object()
    return super().get(request, *args, **kwargs)

  def post(self, request, *args, **kwargs):
    self.object = self.get_object()
    return super().post(request, *args, **kwargs)
```

## ModelFormMixin

> https://github.com/django/django/blob/2.1/django/views/generic/edit.py#L70

```py
class ModelFormMixin(FormMixin, SingleObjectMixin):
    """Provide a way to show and handle a ModelForm in a request."""
    fields = None

    def get_form_class(self):
        """Return the form class to use in this view."""
        if self.fields is not None and self.form_class:
            raise ImproperlyConfigured(
                "Specifying both 'fields' and 'form_class' is not permitted."
            )
        if self.form_class:
            return self.form_class
        else:
            if self.model is not None:
                # If a model has been explicitly provided, use it
                model = self.model
            elif getattr(self, 'object', None) is not None:
                # If this view is operating on a single object, use
                # the class of that object
                model = self.object.__class__
            else:
                # Try to get a queryset and extract the model class
                # from that
                model = self.get_queryset().model

            if self.fields is None:
                raise ImproperlyConfigured(
                    "Using ModelFormMixin (base class of %s) without "
                    "the 'fields' attribute is prohibited." % self.__class__.__name__
                )

            return model_forms.modelform_factory(model, fields=self.fields)

    def get_form_kwargs(self):
        """Return the keyword arguments for instantiating the form."""
        kwargs = super().get_form_kwargs()
        if hasattr(self, 'object'):
            kwargs.update({'instance': self.object})
        return kwargs

    def get_success_url(self):
        """Return the URL to redirect to after processing a valid form."""
        if self.success_url:
            url = self.success_url.format(**self.object.__dict__)
        else:
            try:
                url = self.object.get_absolute_url()
            except AttributeError:
                raise ImproperlyConfigured(
                    "No URL to redirect to.  Either provide a url or define"
                    " a get_absolute_url method on the Model.")
        return url

    def form_valid(self, form):
        """If the form is valid, save the associated model."""
        self.object = form.save()
        return super().form_valid(form)

```

## FormMixin

> https://github.com/django/django/blob/2.1/django/views/generic/edit.py#L10

```py
class FormMixin(ContextMixin):
    """Provide a way to show and handle a form in a request."""
    initial = {}
    form_class = None
    success_url = None
    prefix = None

    def get_initial(self):
        """Return the initial data to use for forms on this view."""
        return self.initial.copy()

    def get_prefix(self):
        """Return the prefix to use for forms."""
        return self.prefix

    def get_form_class(self):
        """Return the form class to use."""
        return self.form_class

    def get_form(self, form_class=None):
        """Return an instance of the form to be used in this view."""
        if form_class is None:
            form_class = self.get_form_class()
        return form_class(**self.get_form_kwargs())

    def get_form_kwargs(self):
        """Return the keyword arguments for instantiating the form."""
        kwargs = {
            'initial': self.get_initial(),
            'prefix': self.get_prefix(),
        }

        if self.request.method in ('POST', 'PUT'):
            kwargs.update({
                'data': self.request.POST,
                'files': self.request.FILES,
            })
        return kwargs

    def get_success_url(self):
        """Return the URL to redirect to after processing a valid form."""
        if not self.success_url:
            raise ImproperlyConfigured("No URL to redirect to. Provide a success_url.")
        return str(self.success_url)  # success_url may be lazy

    def form_valid(self, form):
        """If the form is valid, redirect to the supplied URL."""
        return HttpResponseRedirect(self.get_success_url())

    def form_invalid(self, form):
        """If the form is invalid, render the invalid form."""
        return self.render_to_response(self.get_context_data(form=form))

    def get_context_data(self, **kwargs):
        """Insert the form into the context dict."""
        if 'form' not in kwargs:
            kwargs['form'] = self.get_form()
        return super().get_context_data(**kwargs)


```

## DeleteView

> https://github.com/django/django/blob/2.1/django/views/generic/edit.py#L202

```py
class BaseDeleteView(DeletionMixin, BaseDetailView):
    """
    Base view for deleting an object.
    Using this base class requires subclassing to provide a response mixin.
    """


class DeleteView(SingleObjectTemplateResponseMixin, BaseDeleteView):
    """
    View for deleting an object retrieved with self.get_object(), with a
    response rendered by a template.
    """
    template_name_suffix = '_confirm_delete'
```

```py
class DeletionMixin:
    """Provide the ability to delete objects."""
    success_url = None

    def delete(self, request, *args, **kwargs):
        """
        Call the delete() method on the fetched object and then redirect to the
        success URL.
        """
        self.object = self.get_object()
        success_url = self.get_success_url()
        self.object.delete()
        return HttpResponseRedirect(success_url)

    # Add support for browsers which only accept GET and POST for now.
    def post(self, request, *args, **kwargs):
        return self.delete(request, *args, **kwargs)

    def get_success_url(self):
        if self.success_url:
            return self.success_url.format(**self.object.__dict__)
        else:
            raise ImproperlyConfigured(
                "No URL to redirect to. Provide a success_url.")
```

```html
<form action="" method="post">
  {% csrf_token %}
  <input type="submit" value="삭제하겠습니다." />
</form>
```
