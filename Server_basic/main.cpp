/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: delibasba
 *
 * Created on June 5, 2018, 4:28 PM
 */

#include "main_h.h"

using namespace std;

/*
 * 
 */
int main() {

    int sendedBytes;
    int readedBytes;
    int max_data_size=100;
    char data[max_data_size];
    int sockfd, sockfd2;
    int port_nr=8000;
       
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;
    
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
    serveraddr.sin_port=htons(port_nr);
    
    bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    listen(sockfd,2);
    sockfd2=accept(sockfd,(struct sockaddr *) NULL,NULL);
    
    while(1)
    {
        readedBytes=read(sockfd2,data,sizeof(data));
       // cout<<readedBytes <<endl;
        if(readedBytes>0)
        {
        printf("Echoing back:\n%s",data);
        }
        sendedBytes=write(sockfd2,data,strlen(data)+1);
        
       // cout<<sendedBytes <<endl;
    }
    
    
    return 0;
}

