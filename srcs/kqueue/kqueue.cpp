#include "kqueue.hpp"

Kqueue::Kqueue(){}
Kqueue::~Kqueue(){}

void Kqueue::initServer(const Config& config)
{
    /* init server socket and listen */
    int     server_socket;
    struct  sockaddr_in server_addr;

    /*
    Event::setMimeType();
    FD_ZERO(&clientfd);
    FD_ZERO(&serverfd);

    MIME타입 설정 ,fd 초기화
    */
    for(/*config 시작부터 끝까지 반복 루프~~*/)
    {
if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        throw "socket() Error\n";

        /*중복 처리? 해야?하나?*/
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        // server_addr.sin_port = htons((*it)->getPort());

        if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
            throw "bind() Error\n";
        if (listen(server_socket, 3) == -1)
            throw "listen() Error\n";
        fcntl(server_socket, F_SETFL, O_NONBLOCK);
        
        /* init kqueue */
        if ((kqueue_fd = kqueue()) == -1)
            throw "kqueue() Error\n";
        
        /* add event for server socket */
        /* 서버 시작*/
    }
}
void Kqueue::connectClient(int server_fd)
{
    int     client_socket;
    struct  sockaddr_in client_addr;

    /* accept client */
    socklen_t client_addr_size = sizeof(client_addr);
    if ((client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_size)) == -1)
        throw "accept() Error\n";
    fcntl(client_socket, F_SETFL, O_NONBLOCK);

    /*소켓에서 클라이언트 ip 주소 문자열로 반환 버퍼 저장*/
    /* add event for client socket */
    /* 클라이언트 객체가 연결된 서버를 찾아서 해당 서버 객체에 대한 포인터 저장*/
}

void Kqueue::disconnectClient(const Client& client)
{
    /*클라이언트 객체 찾아서 해당 클라이언트 객체에 대한 포인터 저장*/
    /*클라이언트 객체 연결 종료*/
}
 void Kqueue::runServer()
 {
    int             new_events;
    struct kevent*  current_event;
    struct kevent   event_list[8];

    while (1)
    {
        new_events = kevent(kqueue_fd, &change_list[0], change_list.size(), event_list, 8, NULL);
        if (new_events == -1)
            throw "kevent() Error\n";
        change_list.clear();
        for (int i = 0; i < new_events; i++)
        {
            if (current_event->flags & EV_ERROR){
                if (/*서버 소켓 오류*/)
                    throw "Server Socket Error\n";
            }
            else if(/*클라이언트 EOF나 타이머 event 시 연결종료 */)
                disconnectClient();
            else if (/*앍가 아밴트*/)
            {
                if(/*서버 읽기 감지*/){
                    connectClient(current_event->ident);
                }
                else if (/*클라이언트 읽기 감지*/){
                    /*
                        클라이언트 객체 찾아서 해당 클라이언트 객체에 대한 포인터 저장

                        클라이언트가 요청 받는 상태인 경우
                        {  => 읽어서 메소드 확인
                            break;
                        }
                        (파일읽는 중인 경우)
                        {
                            => 파일 읽기
                            break;
                        }
                        (파이프로 데이터 읽는 중인 경우)
                        {
                            => 파이프로 데이터 읽기
                            break;
                        }
                    */
                }
                else if (/*쓰기 이벤트*/){
                /*
                        클라이언트 객체 찾아서 해당 클라이언트 객체에 대한 포인터 저장
                        (응답전송인 경우)
                        {  => 전송
                            break;
                        }
                        (파일읽는 중인 경우)
                        {
                            => 파일 읽기
                            break;
                        }
                        (파이프로 데이터 전송 중인 경우)
                        {
                            => 파이프로 데이터 쓰기
                            break;
                        }
                        (데이터 종료의 경우)
                        disconnectClient();
                        break
                    */
                }
            }
        }
    }
 }