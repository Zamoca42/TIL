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
 ## HTTP 특징
 ## HTTP 메세지
 ## HTTP 메서드
 ## HTTP 상태코드
 ## HTTP 헤더



