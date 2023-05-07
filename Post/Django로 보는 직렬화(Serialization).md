[이전 글](https://www.zamoca.space/blog/post_detail.html?id=4)을 통해 Django REST framework을 사용하여 RESTful한 API를 만드는 것을 알아봤다면, 
이번에는 REST framwork에서 지원하는 Serializer에 대해 알아보려고 합니다.
먼저 직렬화(serialization)가 무엇인지 부터 알아보겠습니다

## 직렬화란?

객체의 상태를 저장하거나 전송 가능한 형태로 변환하는 과정을 의미합니다. 객체를 직렬화하면, 해당 객체의 데이터들이 일련의 바이트(byte) 형태로 변환되어 파일이나 네트워크 등에 저장하거나 전송할 수 있게 됩니다. 이 때, 직렬화된 데이터는 다른 시스템에서도 읽을 수 있어야 하므로, 일반적으로 JSON, XML, 바이너리 등의 형식으로 변환됩니다.

반대로 역직렬화(Deserialization)도 존재하는데 역직렬화란 직렬화된 데이터를 원래 객체로 변환하는 과정을 의미합니다. 직렬화된 데이터는 일련의 바이트 형태로 저장되어 있으므로, 이를 읽고, 해당 바이트를 원래 객체의 형태로 변환해야 합니다. 이 때, 역직렬화는 직렬화와 정확히 반대되는 과정입니다.

직렬화는 객체를 바이트,Json등의 형식으로 변환하는 것이고 역직렬화는 바이트,JSON 등의 형식을 객체로 변환하는 것을 의미합니다. 

Django에서는 REST framwork가 Serializer가 직렬화 및 역직렬화를 지원합니다.
클래스 기반 뷰와 REST framework를 사용했을 때의 Serialize를 비교해보겠습니다.

## 변경 전 (클래스 기반 뷰 사용)

RESTframwork를 사용하기 전 클래스 기반 뷰를 사용했을 때는 직접 데이터베이스에서 객체를 가져와서 JSON의 형태로 변경해줍니다. 

데이터 유효성 검사를 작성해야하고, 객체를 직렬화/ 역직렬화하는 과정을 직접 작성해야하기 때문에, 추가 작업이 필요합니다. 

만약에 변경사항이 생긴다면 포맷을 변경하기가 까다롭습니다.

직접 포스트를 JSON으로 변경화는 과정을 보겠습니다

```python
# view_util.py

def obj_to_post(obj):

	post = dict(vars(obj))

	if obj.modify_dt:
		post['modify_dt'] = obj.modify_dt.strftime('%Y-%m-%d %H:%M')
	else:
		post['modify_dt'] = ''
	
	if obj.tags:
		post['tags'] = [tag.name for tag in obj.tags.all()]
	else:
		post['tags'] = []

	if obj.owner:
		post['owner'] = obj.owner.username
	else:
		post['owner'] = 'Anonymous'
	
	del post['_state']

	return post
```

모델 인스턴스(obj)를 포스트(post)로 변환하는 함수입니다.

`vars()` 함수는 인스턴스의 속성(attribute)들을 딕셔너리 형태로 반환하는 파이썬 내장 함수입니다. 이 함수를 사용하여 모델 인스턴스(obj)의 속성들을 딕셔너리로 변환하고, 이를 post 변수에 할당합니다.

따라서, `post = dict(vars(obj))`는 모델 인스턴스(obj)의 속성들을 딕셔너리 형태로 변환하여 post 변수에 할당하는 코드입니다. 

이후, 수정 일시(modify_dt), 태그(tags), 소유자(owner) 등의 속성을 post 딕셔너리에 추가하고, 마지막으로 Django의 내부 속성인 `_state`를 삭제하고, post 딕셔너리를 반환합니다.

이대로 바로 View에 사용할 수있습니다. 그러나 여기서 더 기능을 추가하기는 어렵습니다. 다음은 클래스 기반 뷰에서 어떻게 사용하는지 확인해보겠습니다

```python
# views.py

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

```

views.py에서 포스트의 목록을 보여주는 `ApiPostLV`에서 querystring과  위에서 설명한 `obj_to_post`를 사용해서 object를 json으로 반환하고 있습니다.

포스트를 생성하는 `ApiPostCV`를 보시면 view에서 직접 form을 validation한다고 볼 수 있습니다.

다음은 REST framework을 사용한 Serializer와 view를 알아보도록 하겠습니다.

## 변경 후 (REST Framework 사용)

```python
# serializers.py

class PostListSerializer(TaggitSerializer, serializers.ModelSerializer):
	category = serializers.CharField(source='category.name', default='New')
	tags = TagListSerializerField()
	create_dt = serializers.DateTimeField(format='%B %d, %Y')

	class Meta:
		model = Post
		fields = '__all__'
  
	def create(self, validated_data):
		category_name = validated_data.pop('category')['name']
		category, _ = Category.objects.get_or_create(name=category_name)
		
		tags = validated_data.pop('tags', [])
		instance = super().create(validated_data)
		instance.tags.set(*tags)
		return instance

	def to_representation(self, instance):
		representation = super().to_representation(instance)
		request = self.context.get('request')
		if request and request.method == 'GET':
			fields_to_omit = ['content', 'owner','modify_dt']
			for field in fields_to_omit:
				representation.pop(field, None)
		return representation
```

Django REST framework를 사용하여 Post 모델의 목록을 보여주기 위한 Serializer를 구현한 것입니다. `serializers.ModelSerializer`는 데이터의 변환 및 유효성 검사를 담당하는데, 여기서는 Post 모델의 데이터를 JSON 형식으로 변환하는 역할을 합니다.

여기서는 태그 기능과 모델 인스턴스를 직렬화하는 기능을 포함하고 있습니다.

`create()` 에서는 입력 데이터를 검증한 후 새로운 Post 인스턴스를 생성합니다. 먼저 카테고리와 태그 정보를 추출한 다음, 부모 클래스의 `create()` 메서드를 호출하여 인스턴스를 생성합니다. 이후 생성된 인스턴스에 태그 정보를 설정하고 반환합니다.

그 다음 `to_representation()`에서 주어진 Post 인스턴스를 직렬화된 표현을 반환합니다. 이 메서드에서는 'GET' 요청이 있을 때 특정 필드를 제외한 결과를 반환합니다.

이 Serializer를 사용하게되면, Post 모델의 인스턴스를 JSON 형식으로 변환하고, 필요한 필드만 출력하여 API를 통해 데이터를 제공할 수 있습니다. 

```python
# views.py

class PostFilter(django_filters.FilterSet):
	category = django_filters.CharFilter(field_name='category__name')
	tagname = django_filters.CharFilter(field_name='tags__name')

	class Meta:
		model = Post
		fields = ['category', 'tagname']

class PostListAPIView(generics.ListCreateAPIView):
	queryset = Post.objects.all()
	serializer_class = PostListSerializer
	filter_backends = (filters.DjangoFilterBackend,)
	filterset_class = PostFilter

```

다음은 views에서 Serializer를 사용하여 API뷰를 살펴보겠습니다. Post 모델의 목록을 조회하고 생성하는 API 뷰를 구현한 것입니다. 해당 클래스는 `generics.ListCreateAPIView`를 상속하여 목록 조회와 생성 기능을 제공합니다. 이어서 작성한 `PostFilter`를 사용하여 tag와 category에 대한 쿼리 기능을 추가했습니다.

그리고 `PostListAPIView`의 `queryset`에서 Post 모델의 모든 인스턴스를 반환하는 쿼리셋을 설정합니다.
`serializer_class`에서  앞서 설명한 `PostListSerializer`를 사용하여 데이터를 직렬화합니다.
`filter_backends`에서 `filters.DjangoFilterBackend`를 사용합니다. 이를 통해 필터 클래스로`PostFilter`를 적용해서 tag와 category에 대한 쿼리 기능을 사용할 수 있습니다

`PostListAPIView`를 사용하면, 클라이언트는 API를 통해 Post 목록을 조회하고 필터링할 수 있으며, 새로운 Post를 생성할 수도 있습니다. 이러한 기능들은 작성한 `PostListSerializer`와 연결되어 유효성을 검사합니다.

## 정리

Django REST framework와 클래스 기반 뷰의 주요 차이점은 다음과 같습니다

1.  REST framework는 제네릭 뷰를 사용하여 기본 CRUD 기능을 제공하고, 클래스 기반 뷰에서는 수동으로 구현해야 합니다.
2.  REST framework는 Serializer를 통해 객체의 직렬화 및 역직렬화 과정을 자동화하며, 클래스 기반 뷰에서는 직접 구현해야 합니다.
3.  REST framework에서는 필터링 및 페이징 기능을 쉽게 구현할 수 있고, 클래스 기반 뷰에서는 직접 구현해야 합니다.
4.  REST framework를 사용하면 코드 재사용성과 모듈화가 용이하며, 클래스 기반 뷰에서는 상대적으로 어렵습니다.

최종적으로, Django REST framework를 사용하면 코드의 간결성, 재사용성, 유지보수 및 확장성이 향상되고, 추가적인 기능과 API 문서화를 쉽게 활용할 수 있습니다. 반면, 클래스 기반 뷰를 사용하면 이러한 이점을 얻기 어렵습니다.