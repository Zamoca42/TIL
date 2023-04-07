처음에는 이론으로만 REST API에 대해 들어보았지만 이해하기 어려웠습니다. 블로그를 만들어보면서 CRUD를 구현해보니 이론보다는 실제로 구현해보는 것이 더 빠른 이해를 가져온 것 같습니다. 
이 글에서는 Django에서 클래스 기반 뷰와 REST framework를 이용한 블로그 API를 RESTful하게 구현해보는 과정에 대해 소개하려고 합니다.

## Django란?

Django는 웹사이트 개발을 쉽고 빠르게 할 수 있도록 도와주는 웹 프레임워크입니다. Django는 기본적인 보안 기능과 어드민 페이지를 제공하며, 이를 통해 CRUD 기능도 지원하기 때문에 백엔드로 사용하게 되었습니다.
기본 설정하는 방법은 상황에 따라 다르겠지만, 저에게는 [점프 투 장고](https://wikidocs.net/book/4223)가 큰 도움이 되었습니다.

Django에서는 일반적으로 models.py를 사용하여 ORM을 작성해 데이터베이스 스키마를 정의하고, urls.py를 이용하여 URL과 매핑하는 View 함수를 관리합니다. 그리고 템플릿을 사용하여 웹페이지를 사용자에게 보여줄 수 있지만, 저의 경우에는 Vue를 사용했기 때문에 템플릿 대신 Vue로 데이터를 전달하였습니다.

이 글에서는 Django REST framework를 사용하여 기존의 CRUD 구현을 REST하게 변경해보는 과정을 소개하려고 합니다. 여기서는 Model 작성은 생략하고, urls.py를 이용하여 URL과 매핑하는 과정에서 views.py를 비교해볼 것입니다. 이 블로그에서 사용된 Django 버전은 4.1입니다.

## 변경 전 (클래스 기반 뷰 사용)

블로그 포스팅을 위해 포스트의 목록을 보여주는 list와 내용을 보여줄 detail API를 만들고, CRUD를 구성해 보았습니다. 이 과정에서 [클래스 기반 뷰](https://ccbv.co.uk/)를 사용하였습니다. 클래스 기반 뷰를 사용하면 Django에서 기본으로 제공되는 클래스 기반 뷰를 활용할 수 있어 추가적인 프레임워크나 라이브러리가 필요하지 않습니다. 또한 클래스를 사용함으로써 코드의 재사용성이 좋아집니다.

그러나 클래스 기반 뷰를 사용하여 API를 RESTful하게 구현하는 데에는 많은 코드 작성이 필요하고, 각 API 엔드포인트에 대해 별도의 클래스를 작성해야 합니다. 더불어 인증, 권한 관리, 페이지네이션 등과 같은 공통 기능들을 직접 구현해야 하는 단점이 있습니다.

클래스 기반 뷰로 작성한 urls.py와 views.py를 살펴보겠습니다.

- urls.py

```python
from django.urls import path
from api import views

app_name = 'api'

urlpatterns = [
	path('post/list/', views.ApiPostLV.as_view(), name='post_list'),
	path('post/create/', views.ApiPostCV.as_view(), name='post_create'),
	path('post/<int:pk>/', views.ApiPostDV.as_view(), name='post_detail'),
	path('post/<int:pk>/update/', views.ApiPostUV.as_view(), name='post_update'),
	path('post/<int:pk>/delete/', views.ApiPostDelV.as_view(), name='post_delete'),
]
```

포스트의 목록을 보여줄 때는 `post/list`로, 포스트의 내용을 보여줄 때는 `post/1`과 같이 포스트의 번호로 URL을 매핑한 것을 알 수 있습니다. 또한 포스트를 생성할 때는 `post/create`를 사용하고, 수정이나 삭제할 때는 해당하는 포스트의 번호를 사용했습니다.
예를 들어 `post/1/update`, `post/1/delete`에서 수정과 삭제가 이루어집니다.

다음은 urls.py에 매핑된 views를 살펴보겠습니다.

- views.py

```python
class ApiPostLV(BaseListView):
	def get_queryset(self):
		tagname = self.request.GET.get('tagname')
		if tagname:
			qs = Post.objects.filter(tags__name=tagname)
		else:
			qs = Post.objects.all()
		return qs

	def render_to_response(self, context, **response_kwargs):
		qs = context['object_list']
		postList = [obj_to_post(obj) for obj in qs]
		return JsonResponse(data=postList, safe=False, status=200)

class ApiPostDV(BaseDetailView):
	model = Post
	def render_to_response(self, context, **response_kwargs):
		obj = context['object']
		post = obj_to_post(obj)
		post['prev'], post['next'] = prev_next_post(obj)
		return JsonResponse(data=post, safe=True, status=200)

class ApiPostCV(MyLoginRequiredMixin, BaseCreateView):
	model = Post
	fields = '__all__'

	def form_valid(self, form):
		form.instance.owner = self.request.user
		self.object = form.save()
		post = obj_to_post(self.object)
		return JsonResponse(data=post, safe=True, status=201)

	def form_invalid(self, form):
		return JsonResponse(data=form.errors, safe=True, status=400)

class ApiPostUV(OwnerOnlyMixin, BaseUpdateView):
	model = Post
	fields = '__all__'

	def form_valid(self, form):
		self.object = form.save()
		post = obj_to_post(self.object)
		return JsonResponse(data=post, safe=True, status=200)

	def form_invalid(self, form):
		return JsonResponse(data=form.errors, safe=True, status=400)

class ApiPostDelV(OwnerOnlyMixin, BaseDeleteView):
	model = Post

	def delete(self, request, *args, **kwargs):
		self.object = self.get_object()
		self.object.delete()
		return JsonResponse(data={}, safe=True, status=204)
```

views.py를 작성하면서 불러온 모듈과 인증 과정은 빼고 포스트 기능만 가져왔습니다. 
사용된 모듈은 [클래스 뷰](https://ccbv.co.uk/)에서 확인 가능합니다. views.py에서 볼 수 있듯이 한 개의 URL에 한 개의 View가 사용된 것을 알 수 있습니다.

`BaseListView`를 오버라이드하여 포스트의 목록을 불러오고 태그 이름으로 검색할 수 있는 기능을 추가했습니다. 그 다음으로 `BaseDetailView`를 사용하여 모델을 불러와 내용을 보여주고, 나머지 `BaseCreateView`, `BaseUpdateView`, `BaseDeleteView`를 오버라이드하여 create, update, delete 기능을 구현하였습니다.

기능적으로는 각각의 역할이 명확하여 문제가 없어보이지만, 인증 과정까지 추가하면 view와 URI는 계속 길어질 것입니다. 이를 고려하면 좋지 않아 보입니다.

## 변경 후 (Django REST 프레임워크 사용)

그래서 Django가 지원하는 REST framework를 사용하여 REST하게 바꿔봤습니다. REST framework는 RESTful API 설계 원칙을 쉽게 따르도록 도와주며, API 엔드포인트를 효율적으로 작성할 수 있습니다. Serializer와 인증, 권한 관리, 페이지네이션 등과 같은 다양한 기능을 제공합니다. HTTP 메서드를 사용하여 각 엔드포인트에서 여러 기능을 구현할 수 있어 코드가 더 간결해집니다.

다만, 별도의 프레임워크를 사용하므로 Django REST 프레임워크에 대한 이해와 학습이 필요합니다. REST framework 설정은 [공식 문서](https://www.django-rest-framework.org/)나 [CDRF](https://www.cdrf.co/)를 참고하면 좋습니다.

이제 변경된 urls.py와 views.py를 살펴보겠습니다.

- urls.py

```python
from django.urls import path
from apiv2 import views

app_name = 'api2'

urlpatterns = [
	path('post/', views.PostListAPIView.as_view(), name='post-list'),
	path('post/<int:pk>/', views.PostRetrieveAPIView.as_view(), name='post-detail'),
]
```

포스트 목록은 `post/`로, 포스트 내용은 `post/1`과 같은 형태로 표시됩니다. 
그러나 포스트 생성, 수정, 삭제를 위한 URL은 어디에 있는지 보이지 않습니다. 
이는 views.py에서 확인할 수 있습니다.

- views.py

```python
class PostFilter(django_filters.FilterSet):
	category = django_filters.CharFilter(field_name='category__name')
	tagname = django_filters.CharFilter(field_name='tags__name')
	
	class Meta:
		model = Post
		fields = ['category', 'tagname']

class PostPageNumberPagination(pagination.PageNumberPagination):
	page_size = 12

	def get_paginated_response(self, data):
		return Response(OrderedDict([
			('postList', data),
			('pageCnt', self.page.paginator.num_pages),
			('curPage', self.page.number),
		]))

class PostListAPIView(generics.ListCreateAPIView):
	queryset = Post.objects.all()
	serializer_class = PostListSerializer
	pagination_class = PostPageNumberPagination
	filter_backends = (filters.DjangoFilterBackend,)
	filterset_class = PostFilter

class PostRetrieveAPIView(generics.RetrieveUpdateDestroyAPIView):
	queryset = Post.objects.all()
	serializer_class = PostRetrieveSerializer
	
	def retrieve(self, request, *args, **kwargs):
		instance = self.get_object()
		serializer = self.get_serializer(instance)
		try:
			prev_post = instance.get_prev()
			prev_post_serializer = PostSerializerSub(prev_post)
		except Post.DoesNotExist:
			prev_post_serializer = None
		try:
			next_post = instance.get_next()
			next_post_serializer = PostSerializerSub(next_post)
		except Post.DoesNotExist:
			next_post_serializer = None
  
	return Response({
		'post': serializer.data,
		'prevPost': prev_post_serializer.data if prev_post_serializer else None,
		'nextPost': next_post_serializer.data if next_post_serializer else None,
	})

	def put(self, request, *args, **kwargs):
		return self.partial_update(request, *args, **kwargs)
```

여기서 모듈 import나 인증기능, Serializer부분이 생략되었습니다.
`PostListAPIView`에서는 [ListCreateAPIView](https://www.cdrf.co/3.13/rest_framework.generics/ListCreateAPIView.html)를 오버라이드하여 `post/` 부분을 처리합니다. ListCreateAPIView는 REST 프레임워크에서 지원하는 뷰 기능 중 하나로, 여기서는 포스트 목록을 표시하고 생성하는 기능까지 담당합니다. GET 요청을 보내면 목록을 표시하고, POST 요청을 보내면 포스트를 생성하는 방식으로 하나의 URL에서 HTTP 메서드에 따라 기능이 나뉩니다.

비슷한 방식으로 `post/1`로 이동할 경우, `PostRetrieveAPIView`는 [RetrieveUpdateDestroyAPIView](https://www.cdrf.co/3.13/rest_framework.generics/RetrieveUpdateDestroyAPIView.html)를 오버라이드하여 내용을 표시하고 수정 및 삭제 기능까지 담당합니다. 해당 뷰에서는 GET 요청으로 내용을 조회하고, PATCH 요청으로 부분적으로 수정하며, DELETE 요청으로 삭제할 수 있도록 기능이 나뉩니다.

## 결론

REST framework를 사용하기 전과 후를 비교해 보면, 작성해야 하는 코드의 양이 줄어든 것을 확인할 수 있습니다. 이는 REST framework가 다양한 기능을 지원하기 때문이며, 결과적으로 코드가 더 간결해진건 사실입니다.

이렇게 블로그 백엔드를 만들어보면서 REST API의 기본 원칙을 알아볼 수 있었습니다. 복잡한 기능들을 HTTP 메서드를 통해 간결하게 구현하는 방법을 배웠고, 이를 통해 코드의 가독성이 높아지고 유지 보수가 쉬워질 거 같습니다. 

특히, Django REST framework의 다양한 기능을 활용하여 Serializer와 인증, 권한 관리, 페이지네이션 등과 같은 기능을 구현하는 경험이 가치있었습니다. 앞으로는 Serializer의 기능과 원리에 대해 좀 더 자세하게 알아보고 글을 작성해보려고 합니다.

## 참고 도서

- Do it! 장고+부트스트랩 파이썬 웹 개발의 정석

## 참고 링크

- https://wikidocs.net/book/4223
- https://meetup.nhncloud.com/posts/92
- https://ccbv.co.uk/
- https://www.django-rest-framework.org/
- https://www.cdrf.co/
- https://wikidocs.net/78004
- https://www.inflearn.com/roadmaps/368





