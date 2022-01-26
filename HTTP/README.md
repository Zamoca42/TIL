# Intro.

> HTTP는  
> 인프런 김영한님의 '모든 개발자를 위한 HTTP 웹 기본 지식'을 수강하고  
> http 완벽 가이드를 공부하고 정리한 내용을 업로드를 지속할 예정입니다.

---

</br>

# 네트워크

 ## 인터넷 프로토콜 스택의 4계층
  - 애플리케이션 계층 - HTTP, FTP
  - 전송 계층 - TCP, UDP
  - 인터넷 계층 - IP
  - 네트워크 인터페이스 계층 - LAN 카드, 드라이버

 ## IP (Internet Protocol)
  - 지정한 IP 주소에 데이터 전달
  - 패킷(Packet)이라는 통신 단위로 데이터 전달
    - IP 패킷에는 출발지 IP, 목적지 IP 포함
  - 프로토콜의 한계
    - 비연결성 : 패킷을 받을 대상이 없거나 서비스 불능 상태여도 전송
    - 비신뢰성 : 패킷이 소실되거나 순서대로 오지 않아도 알 수 없음
    - 프로그램 구분 : 같은 IP에 통신하는 어플리케이션이 둘 이상이여도 구분 불가능

 ## TCP (Transmission Control Protocol)
  - 전송 제어 프로토콜
  - 연결지향 - TCP 3 way handshake (가상연결)
    - TCP 3 way handshake 연결과정
        1. 클라이언트에서 서버로 접속 요청
        2. 서버는 클라이언트로 접속 요청 + 수락
        3. 다시 클라이언트에서 서버로 수락
        4. 데이터 전송
        - 참고 : 과정 3에서 수락과 함께 데이터 전송 가능
  - 데이터 전달 보증 (누락 확인)
  - 순서 보장
    - 패킷 순서가 바뀌었더라도 바뀐 순서부터 다시 전송 요청
  - 신뢰할 수 있는 프로토콜 - 현재는 대부분 TCP 사용
  - TCP 패킷 정보
    - 전송 제어, 순서, 검증 정보

 ## UDP (User Datagram Protocol)
  - 사용자 데이터그램 프로토콜
  - 하얀 도화지에 비유 (기능이 거의 없음)
  - 연결 지향, 전달 보증, 순서 보장 없음
  - 단순하고 빠름
  - IP와 거의 같지만 PORT와 체크섬 정도만 추가
    - 내부에서 어플리케이션 구분용으로 사용

 ## PORT
  - 같은 IP내에서 프로세스 구분
    - IP가 아파트라면 PORT는 호수에 비유
  - TCP/UDP 패킷에 포함
  - 0 ~ 65536 할당 가능
  - 0 ~ 1023 : 잘 알려진 포트, 사용하지 않는 것을 권장
    - FTP - 20,21
    - TELNET - 23
    - HTTP - 80
    - HTTPS - 443

 ## DNS (Domain Name System)
  - IP는 기억하기 어렵고, 변경 될 수 있다
  - 도메인명을 IP주소로 변환
  - DNS 서버에서 google.com같은 도메인을 입력받으면  
  도메인과 연결되어있는 서버 IP와 클라이언트를 연결해준다.

  </br>

# URI (Uniform Resource Identifier)
> URI는 로케이터(locator), 이름(name) 또는 둘다 추가로 분류될 수 있다.  
> [RFC3986 - 1.1.3. URI, URL, and URN](https://www.ietf.org/rfc/rfc3986.txt)

 ## URI
  - Uniform : 리소스를 식별하는 통일된 방식
  - Resource : 자원, URI로 식별할 수 있는 모든것(제한 없음)
  - Identifier : 다른 항목과 구분하는데 필요한 정보
  - 위치는 변할 수 있지만, 이름은 변하지 않는다

 ## URL (Uniform Resource Locator)
  - Locator : 리소스가 있는 위치를 지정
  - 예시 : https://www.google.com:443/search?q=hello&hl=ko  
    - 프로토콜 (https) : 약속 규칙
    - 호스트명 (www.google.com)
        - 도메인명 또는 IP 주소 사용가능
    - 포트 번호 (443)
        - 접속 포트, 일반적으로 생략
    - 패스 (/search)
        - 리소스 경로(path), 계층적 구조
    - 쿼리 파라미터 (q=hello&hl=ko)
        - key=value 형태, ?로 시작, &로 추가 가능
    - URN는 사용하지 않아 사실상 URI = URL

 ## URN (Uniform Resource Name)
  - Name : 리소스에 이름을 부여
  - URN 이름만으로 실제 리소소를 찾을 수 있는 방법이 보편화 되지 않음
  - 사용 거의 안함

  </br>

# HTTP (HyperText Transfer Protocol)
> 모든 것이 HTTP  
> HTML, TEXT, 음성, 영상, 파일 등 거의 모든 형태의 데이터 전송 가능  
> 서버간의 데이터를 주고 받을 때도 대부분 HTTP 사용

</br>

 ## HTTP 역사
   - HTTP/0.9 1991년 : GET 메서드만 지원, HTTP 헤더X
   - HTTP/1.0 1996년 : 메서드, 헤더 추가
   - HTTP/1.1 1997년 : 가장 많이 사용, 우리에게 가장 중요한 버전
      - RFC2068 (1997) -> RFC2616 (1999) -> RFC7230~7235 (2014)
   - HTTP/2 2015년 : 성능개선
   - HTTP/3 진행중 : TCP 대신에 UDP 사용, 성능 개선
 ## HTTP 특징
   - 클라이언트 서버 구조
     - 독립적인 성장을 위해 클라이언트, 서버 분리
        - 클라이언트는 UI, 사용성을 서버는 비즈니스 로직
     - Request Response 구조
     - 클라이언트는 서버에 요청을 보내고, 응답을 대기
     - 서버가 요청에 대한 결과를 만들어서 응답
   - 무상태 프로토콜
     - 무상태(stateless)와 상태 유지(stateful) 차이
        - 점원(서버)와 고객(클라이언트)로 비유
        - 상태 유지(stateful)  
          중간에 다른 점원으로 바뀌면 안된다
          한 점원이 계속 응대, 이전 상태에 대한 정보 있음  
          상태 유지일때 장애가 나면 처음부터 다시해야함
        - 무상태(stateless)  
          중간에 다른 점원으로 바뀌어도 상관없음  
          이전 상태에 대한 정보가 없어도 상관 없음
          갑자기 클라이언트 요청이 증가해도 서버를 대거 투입할 수 있다.  
          중간에 장애가 발생해도 다른 서버에게 요청 가능
        - stateless의 실무 한계  
          무상태로는 로그인상태 유지 불가능  
          일반적으로 브라우저 쿠기와 서버세션을 사용해 로그인했다는 상태를 서버에 유지
   - 비연결성
      - 연결을 유지하지 않는 모델
      - 초 단위 이하의 빠른 속도로 응답
      - 서버 자원을 매우 효율적으로 사용
      - 한계
        - TCP/IP 연결을 새로 맺어야함 - 연결, 종료 낭비
        - 지금은 HTTP 지속연결로 문제해결
        - HTTP/2, HTTP/3에서 더많은 최적화
   - HTTP 메세지
   - 단순함, 확장 가능
      - HTTP는 단순하다. 스펙도 읽어볼만
      - HTTP 메세지도 매우 단순
      - 크게 성공하는 표준 기술은 단순하지만 확장 가능한 기술
 ## HTTP 메세지
   - 메세지 구조  
    <img src = "https://user-images.githubusercontent.com/96982072/150739603-32232c84-5bd4-4ff8-8aff-ba09561f4e84.png" width="70%">
     - start-line 시작라인
       - 요청 메세지 예시 : Get /serach?q=hello&hl=ko HTTP/1.1
          1. HTTP 메서드 (GET : 조회)
          2. 요청 대상 (/search?q=hello&hl=ko)
          3. HTTP version / 1.1 
       - 응답 메세지 예시 : HTTP/1.1 200 OK
          1. HTTP 버전
          2. HTTP 상태 코드 : 요청 성공, 실패를 나타냄
          3. 이유 문구 : 사람이 이해할 수 있는 짧은 상태 코드 설명 글
     - [header 헤더](#http-헤더)
        - HTTP 전송에 필요한 모든 부가정보
        - 표준 헤더가 너무 많음
          - [표준 헤더 - 위키피디아](https://en.wikipedia.org/wiki/List_of_HTTP_header_fields)
        - 필요시 임의의 헤더 추가 가능
     - empty line 공백 라인 (CRLF) -> 반드시 있어야함
     - message body 메세지 바디
        - 실제 전송할 데이터
        - HTML 문서, 이미지, 영상, JSON 등등 byte로 표현할 수 있는 모든 데이터 전송 가능
 ## HTTP 메서드
  - HTTP API
    - 요구사항 예시  
      회원 정보 관리 API를 만들어라   
      <details>
      <summary> 리소스를 고려하지 않은 예 </summary>
      <div markdown="1">       

      - 회원 목록 조회 /read-member-list
      - 회원 조회 /read-member-by-id
      - 회원 등록 /create-member
      - 회원 수정 /update-member
      - 회원 삭제 /delete-member  

      </div>
      </details>  

      </br>

      회원이라는 개념 자체가 바로 리소스이기 때문에 회원이라는 리소스만 식별하면 된다  
      - 회원 목록 조회 /members -> GET
      - 회원 조회 /members/{id} -> POST
      - 회원 등록 /members/{id} -> GET
      - 회원 수정 /members/{id} -> PATCH, PUT, POST
      - 회원 삭제 /members/{id} -> DELETE  
    - **리소스**와 해당 리소스를 대상으로 하는 **행위**를 분리  
      - 리소스 : 회원
      - 행위 : 조회, 등록, 삭제, 변경  
    - 행위(메서드)는 GET, POST, PATCH, DELETE 등으로 구분
    - 회원 관리 시스템
      - 컨트롤 URI (190p)
    
  - 메서드 종류  
    - GET
      - 리소스 조회
    - POST
      - 메세지 바디를 통해 서버로 요청 데이터 전달
      - 주로 전달된 데이터로 서버가 신규 리소스 등록, 프로세스 처리에 사용
      - 조회, 상태 변경, 새로 등록 모두 가능
      - 모두 가능하기 때문에 애매하면 POST
    - PUT
      - 리소스를 완전 대체, 해당 리소스가 없으면 생성, 덮어쓰기
      - 클라이언트가 리소스를 식별
      - 리소스 위치를 알고 있어야한다 -> POST와의 차이점
    - PATCH
      - PUT의 완전 대체의 불편함을 대신해 리소스를 부분 변경
    - DELETE
      - 리소스 삭제
  - 메서드의 속성
    - 안전(Safe Methods)
      - 호출해도 리소스를 변경하지 않는다
      - 해당 리소스만 고려하고, 로그 장애까지는 고려하지 않는다
    - 멱등(Idempotent Methods)
      - 한 번 호출하든 두 번 호출하든 100번 호출하든 결과가 똑같다.
      - 멱등 메서드
        - GET : 몇 번을 조회하든 같은 결과가 조회
        - PUT : 결과를 대체, 여러번 해도 최종 결과는 같다.
        - DELETE : 같은 요청을 여러번 해도 삭제된 결과는 똑같다.
      - 클라이언트가 같은 요청을 해도 되는가? -> 판단 근거
    - 캐시가능(Cacheable Methods)
      - 응답 결과 리소스를 캐시해서 사용해도 되는가?
      - GET, HEAD 정도만 캐시로 사용
    
 ## HTTP 상태코드
   - 클라이언트가 보낸 요청의 처리 상태를 응답에서 알려주는 기능
     - 1xx (Informational) : 요청이 수신되어 처리 중
       - 거의 사용하지 않음
     - 2xx (Successful) : 요청 성공적으로 처리
       - 200 OK : 요청 성공
       - 201 Created : 새로운 리소스 생성 (Location 헤더 필드로 식별)
       - 202 Accepted : 접수되었으나 처리가 완료되지 않았음
       - 204 No content : 요청을 성공적으로 수행했지만, 본문에 보낼 데이터가 없음
     - 3xx (Redirection) : 리다이렉션, 요청을 완료하려면 추가 행동이 필요
       - 300 Multiple Choices
       - 301 Moved Permanently
       - 302 Found
       - 303 See Other
       - 304 Not Modified
       - 307 Temporary Redirect
       - 308 Permanent Redirect
     - 4xx (Client Error) : 클라이언트 오류, 잘못된 문법등으로 서버가 요청을 수행할 수 없음
       - 400 Bad Request : 클라이언트의 잘못된 요청으로 서버가 처리할 수 없음
       - 401 Unauthorized : 인증 되지 않음
       - 403 Forbidden : 서버가 요청을 이해했지만 승인을 거부 - 접근 권한이 불충분
       - 404 Not Found : 요청 리소스가 서버에 없거나, 숨기고 싶을 때
     - 5xx (Server Error) : 서버 오류, 서버가 정상 요청을 처리하지 못함
       - 500 Internal Server Error : 서버 내부문제
       - 503 Service Unavailable : 서버가 일시적인 과부하
   - 만약 모르는 상태 코드가 나타나면?
     - 클라이언트는 상위 상태코드로 해석
     - 미래에 새로운 상태코드가 추가되어도 상위코드만 알고 있으면 대략적으로 알 수 있음
       - 299 ??? -> 2xx (Successful)
       - 451 ??? -> 4xx (Client Error)
   - 리다이렉션 이해
     - 3xx (Redirection) : 요청을 완료하기 위해 유저 에이전트의 추가 조치 필요  
     - 자동 리다이렉션 흐름  
      <img src = "https://user-images.githubusercontent.com/96982072/150898156-cde8331c-84ff-41ea-9225-f50270d90d74.png" width="70%">  
     - 영구 리다이렉션 - 특정 리소스의 URI가 영구적으로 이동
       - 301 Moved Permanently - 리다이렉트 요청 메서드가 GET으로 변하고, 본문이 제거될 수 있음
       - 308 Permanent Redirect - 301과 기능은 같음, 리다이렉트시 요청 메서드와 본문 유지
     - 일시 리다이렉션 - 리소스의 URI가 일시적인 변경
       - 302 Found - 리다이렉트 요청 메서드가 GET으로 변하고, 본문이 제거될 수 있음
       - 307 Temporary Redirect - 302와 기능은 같음, 리다이렉트시 요청 메서드와 본문 유지
       - 303 See Other - 리다이렉트시 요청 메서드가 GET으로 변경
       - PRG : Post/Redirect/Get  
         1. POST로 주문후에 새로 고침으로 인한 중복 주문 방지
         2. POST로 주문 후에 주문 결과 화면을 GET 메서드로 리다이렉트
         3. 새로고침해도 결과 화면을 GET으로 조회
         4. 결과 화면만 GET으로 다시 요청   
     - 특수 리다이렉션
       - 300 Multiple Choices : 안쓴다
       - 304 Not Modified
         - 캐시를 목적으로 사용
         - 클라이언트에게 리소스가 수정되지 않았음을 알려준다, 저장된 캐시를 재사용
         - 조건부 GET, HEAD 요청시 사용  
 ## HTTP 헤더
 > 요청 : 클라이언트 -> 서버  
 > 응답 : 서버 -> 클라이언트
   - 개요
     - HTTP 전송에 필요한 모든 부가정보
     - RFC 2616(과거 - 폐기)
       - General 헤더 : 메시지 전체에 적용되는 정보 - 예) connection: close
       - Request 헤더 : 요청 정보 - 예) User-Agent: Mozila/5.0
       - Responcse 헤더 : 응답정보 - 예) Server: Apache
       - Entity 헤더 : 엔티티 바디 정보 - 예) Content-Type: text/html, Content-Length: 3423  
       - message body : 엔티티 바디를 전달하는데 사용, 전달할 실제 데이터
     - RFC 7230 ~ 7235 (2014년 등장 - 최신)
       - 엔티티(Entity) -> 표현(Representation)
       - 표현 = 표현 메타데이터 + 표현 데이터
       - message body : 표현 데이터 전달, 전달할 실제 데이터
         1. Content-Type : 표현 데이터의 형식 - 예) charset = utf-8
         2. Content-Encoding : 표현 데이터의 압축 방식 - 예) gzip
         3. Content-Language : 표현 데이터의 자연 언어 - 예) ko, en, en-US
         4. Content-Encoding : 표현 데이터의 길이 - 예) 5 byte
   - 협상(콘텐츠 네고시에이션) : 클라이언트가 선호하는 표현 요청, 요청 시 사용
     - Accept : 클라이언트가 선호하는 미디어 타입 전달
     - Accept-Charset : 선호하는 문자 인코딩
     - Accept-Encoding : 선호하는 압축 인코딩
     - Accept-Language : 클라이언트가 선호하는 자연 언어
     - Accept-Language 적용 후  
       <img src = "https://user-images.githubusercontent.com/96982072/150902244-5dae3b71-42f5-460e-b288-abfb35ba3153.png" width="70%"> 
     - 우선 순위 : Quality Values(q) 값 사용
        - 0~1, 클수록 높은 우선 순위
        - 생략하면 1
        - Accept-Language : ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7
          1. ko-KR;q=1 (생략)
          2. ko;q=0.9
          3. en-US;q=0.8
          4. en;q=0.7
   - 전송 방식
     - 단순 전송 - Content-Length
     - 압축 전송 - Content-Encoding
     - 분할 전송 - Transfer-Encoding 
     - 범위 전송 - Range, Content-Range
   - 일반 정보
     - From : 유저 에이전트의 이메일 정보
       - 일반적으로 잘 사용되지 않음
       - 검색 엔진 같은 곳에서 주로 사용
       - 요청에서 사용
     - Referer : 이전 웹 페이지 주소
       - 현재 페이지의 이전 웹 페이지 주소
       - 유입경로 분석 가능
       - 참고 : referer는 단어 referrer의 오타
       - 요청에서 사용
     - User-Agent : 유저 에이전트 애플리케이션 정보
       - 애플리케이션 정보 (웹 브라우저 정보 등등)
       - 통계 정보
       - 어떤 종류의 브라우저에서 장애가 발생하는지 파악 가능
       - 요청에서 사용
     - Server : 요청을 처리하는 오리진 서버의 소프트웨어 정보
       - Server: Apache/2.2.22(Debian)
       - server: nginx
       - 응답에서 사용
     - Date : 메시지가 생성된 날짜
       - 응답에서 사용
   - 특별한 정보
     - Host : 요청한 호스트 정보(도메인)
       - 하나의 IP 주소에 여러 도메인이 적용되어 있을 때
       - 하나의 서버가 여러 도메인을 처리해야 할 때
     - Location : 페이지 리다이렉션
       - 웹 브라우저는 3xx 응답의 결과에 Location 헤더가 있으면, Location 위치로 자동 이동
       - 응답코드 3xx에서 설명
       - 201 (Created) : Location 값은 요청에 의해 생성된 리소스 URI
       - 3xx (Redirection) : Location 값은 요청을 자동을 리디렉션하기 위한 대상 리소스를 가리킴
     - Allow : 허용 가능한 HTTP 메서드
       - 405 (Method Not Allowed) 에서 응답에 포함해야함
       - Allow : GET, HEAD, PUT
     - Retry-After : 유저 에이전트가 다음 요청을 하기까지 기다려야 하는 시간
       - 503 (Service Unavailable) : 서비스가 언제까지 불능인지 알려 줄 수 있음
       - Retry-After: Fri, 31 Dec 1999 23:59:59 GMT (날짜 표기)
       - Retry-After: 120 (초단위 표기)
   - 인증
     - Authorization: 클라이언트 인증 정보를 서버에 전달
     - WWW-Authenticate: 리소스 접근시 필요한 인증 방법 정의
       - 401 Unauthorized 응답과 함께 사용
       - WWW-Authenticate: Newauth realm ="apps", type=1, title="Login to \"apps\"", Basic realm="simple"
   - 쿠키
     - HTTP는 무상태 프로토콜이기 때문에 이전 상태를 기억하기 어려움
        - 쿠키에 데이터를 저장해 이전 상태를 기억할 수 있음
        - 쿠키를 사용하면 모든 요청에 쿠키 정보 자동 포함
        - 주의! : 보안에 민감한 데이터는 저장하지 않는다(주민번호, 신용카드 번호 등등) 
     - Set-Cookie: 서버에서 클라이언트로 쿠키 전달(응답)
     - Cookie: 클라이언트가 서버에서 받은 쿠키를 저장하고, HTTP 요청시 서버로 전달
     - 사용처
       - 사용자 로그인 세션 관리
       - 광고 정보 트래킹
     - 쿠기 정보는 항상 서버에 전송됨
       - 네트워크 트래픽 추가 유발
       - 최소한의 정보만 사용(세션 id, 인증 토큰)
       - 서버에 전송하지 않고, 웹 브라우저 내부에 저장하고 싶으면 웹 스토리지 참고
     - 생명주기 (Expires, max-age)
       - Set-Cookie: **expires**=Sat, 26-Dec-2020 04:39:21 GMT
         - 만료일이 되면 쿠키 삭제
       - Set-Cookie: **max-age**=3600 (3600초)
       - 세션 쿠키 : 만료 날짜를 생략하면 브라우저 종료시 까지만 유지
       - 영속 쿠키 : 만료 날짜를 입력하면 해당 날짜까지 유지
     - 도메인 (Domain)
       - 명시 : 명시한 무서 기준 도메인 + 서브도메인 포함
       - 생략 : 현재 문서 기준 도메인만 적용
     - 경로 (path)
       - 예) path=/home
       - 이 경로를 포함한 하위 경로 페이지만 쿠키 접근
       - 일반적으로 path=/ 루트로 지정
     - 보안 (Secure, HttpOnly, SameSite)
       - Secure
         - 쿠키는 http, https를 구분하지 않고 전송
         - Secure를 적용하면 https인 경우에만 전송
     - HttpOnly
         - XSS 공격방지
         - 자바스크립트에서 접근 불가(document.cookie)
         - HTTP 전송에만 사용
     - SameSite
         - XSRF 공격방지
         - 요청 도메인과 쿠키에 설정된 도메인이 같은 경우만 쿠키 전송

 ## HTTP 헤더 - 캐시
   - 캐시 기본 동작
     - 캐시가 없을 때
       - 데이터가 변경되지 않아도 계속 네트워크를 통해 데이터를 다운로드
       - 인터넷 네트워크는 매우 느리고 비싸다
       - 브라우저 로딩 속도가 느리다
       - 느린 사용자 경험
     - 캐시가 있을 때
       - 캐시 덕분에 캐시 가능 시간 동안 네트워크를 사용하지 않는다
       - 비싼 네트워크 사용량을 줄인다
       - 브라우저 로딩 속도가 빠르다
       - 빠른 사용자 경험
     - 캐시 시간 초과
       - 캐시 유효 시간이 초과하면, 서버를 통해 데이터를 다시 조회하고, 캐시를 갱신한다.
         1. 서버에서 기존 데이터를 변경한다
         2. 서버에서 기존 데이터를 변경하지 않는다
       - 이때 다시 네트워크 다운로드가 발생한다
   - 검증 헤더 추가
     - 캐시 시간 초과 후 갱신 할 때 클라이언트와 서버의 데이터가 같다는 사실을 확인하면  
       캐시를 재사용 할 수 있다. 이 때 확인하는 방법으로 검증 헤더를 추가한다
     - Last-Modified, ETag
   - 조건부 요청 헤더
     - 검증 헤더로 조건에 따른 분기
     - If-Modified-Since: 이후에 데이터가 수정 되었으면?
       - 데이터 미변경 예시
         - 캐시: 2020년 11월 10일 10:00:00 vs 서버: 2020년 11월 10일 10:00:00
         - **304 Not Modified** (리디렉션), 헤더 데이터만 전송 (BODY 미포함)
         - 전송 용량 0.1M (헤더 0.1M)
       - 데이터 변경 예시
         - 캐시: 2020년 11월 10일 10:00:00 vs 서버: 2020년 11월 10일 **11**:00:00
         - **200 OK**, 모든 데이터 전송 (BODY 포함)
         - 전송 용량 1.1M (헤더 0.1M, 바디 1.0M)
       - 단점
         - 1초 미만(0.x초) 단위로 캐시 조정 불가능
         - 날짜 기반의 로직 사용
         - 데이터를 수정해서 날짜가 다르지만, 같은 데이터를 수정해서 결과가 똑같은 경우
         - 서버에서 별도의 캐시 로직을 관리하고 싶을 경우
     - If-None-Match: ETag(Entity Tag) 사용
         - 캐시용 데이터에 임의의 고유한 버전 이름을 달아둠
         - 데이터가 변경되면 이 이름을 바꾸어서 변경(Hash를 다시 생성)
         - 단순하게 ETag만 보내서 같으면 유지, 다르면 다시 받기
         - 캐시 제어 로직을 서버에서 완전 관리
   - 캐시 제어 헤더
     - Cache-Control: 캐시 제어
       - max-age: 캐시 유효 시간, 초 단위
       - no-cache: 데이터는 캐시해도 되지만, 항상 origin 서버에 검증하고 사용
       - no-store: 민감한 정보가 있으므로 저장하지 않는다 (사용하고 최대한 빨리 삭제)
     - Pragma: 캐시 제어(하위 호환)
       - 거의 사용 안함
     - Expires: 캐시 유효 기간(하위 호환)
       - 캐시 만료일을 정확한 날짜로 지정
       - HTTP 1.0 부터 사용
       - 더 유연한 Cache-Control: max-age 권장
       - Cache-Control: max-age와 함께 사용하면 Expires는 무시
   - 프록시 캐시
       - CDN, 클라우드 프론트  
         <img src = "https://user-images.githubusercontent.com/96982072/151139651-6274759c-e787-46fa-b032-a80892edbdfa.png" width = "70%">
       - Cache-Control: 
         - public: 응답이 public 캐시에 저장 되어도 됨
         - private: 응답이 해당 사용자 만을 위한 것임, private 캐시에 저장해야 함
         - s-maxage: 프록시 캐시에만 적용되는 max-age
         - Age: 60(HTTP 헤더): 오리진 서버에서 응답 후 프록시 캐시 내에 머문 시간(초)
   - 캐시 무효화
     - Cache-Control:
       - no-cache: 데이터는 캐시해도 되지만, 항상 origin 서버에 검증하고 사용
       - no-store: 데이터에 민감한 정보가 있으므로 저장하지 않는다
       - must-revalidate
         - 캐시 만료 후 최초 조회시 origin 서버에 검증
         - origin 서버 접근 실패시 반드시 오류가 발생해야함 - 504(Gateway Timeout)
         - must-revalidate는 캐시 유효 시간이라면 캐시를 사용함
     - no-cache vs must-revalidate
       - no-cache  
         <img src = "https://user-images.githubusercontent.com/96982072/151141278-458f0d05-95e4-4ffa-9f5f-7f35025878ef.png" width = "70%">
       - must-revalidate  
         <img src = "https://user-images.githubusercontent.com/96982072/151141142-f20883d7-1553-40f4-94fd-95292a34415a.png" width = "70%">
         


