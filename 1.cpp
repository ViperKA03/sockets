#include<winsock2.h>
#include<iostream>
using namespace std;

struct sockaddr_in srv;
#define PORT 9909

int main()
{
    int nRet=0;
     WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "Winsock initialization failed" << endl;
       
    }

    int nSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(nSocket<0)
    { cout<<"Not Open\n";
        exit(EXIT_FAILURE);
    }
    else cout<<"SOcket Open "<<nSocket<<endl;

    //Initializing the enviorment for sockaddr structure 
    srv.sin_family=AF_INET;
    srv.sin_port=htons(PORT);
    srv.sin_addr.s_addr=INADDR_ANY;
    memset(&(srv.sin_zero),0,8);

    //Bind the socket to local port
    nRet=bind(nSocket,(sockaddr*)&srv, sizeof(sockaddr));
    if(nRet<0)
    {
        cout<<"Failed to bind to local port "<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout<<"Successfully bind to local port\n";
         
    }

     WSACleanup();
    return 0;

}
