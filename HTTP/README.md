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
    <img src = "https://user-images.githubusercontent.com/96982072/150739603-32232c84-5bd4-4ff8-8aff-ba09561f4e84.png" width="50%" height="50%">
     - start-line 시작라인
       - 요청 메세지 예시 : Get /serach?q=hello&hl=ko HTTP/1.1
          1. HTTP 메서드 (GET : 조회)
          2. 요청 대상 (/search?q=hello&hl=ko)
          3. HTTP version / 1.1 
       - 응답 메세지 예시 : HTTP/1.1 200 OK
          1. HTTP 버전
          2. HTTP 상태 코드 : 요청 성공, 실패를 나타냄
          3. 이유 문구 : 사람이 이해할 수 있는 짧은 상태 코드 설명 글
     - header 헤더
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
   - 만약 모르는 상태 코드가 나타나면?
   - 리다이렉션 이해
 ## HTTP 헤더
   - 개요
   - 협상
   - 전송 방식
   - 일반 정보
   - 특별한 정보
   - 인증
   - 쿠키
 ## HTTP 헤더 - 캐시




