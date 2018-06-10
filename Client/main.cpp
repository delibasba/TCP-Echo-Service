/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: delibasba
 *
 * Created on June 5, 2018, 1:21 PM
 */

#include "main_h.h"

using namespace std;
int main() {
    int sendedBytes;
    int readedBytes;
    char input[2];
    bool flag_sendandrcv=true;
    int max_data_size= 100; //inBytes
    char senddata [max_data_size];
    char receiveddata [max_data_size];
    const char* ip_addr="127.0.0.1";
    int port_nr=8000;
    
    int sockfd= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;  
    
    if(sockfd>=0)
    {
        cout<< "Client-Socket wurde angelegt." <<endl;
    
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(port_nr);
        inet_aton(ip_addr,&(serveraddr.sin_addr)); 
        int connected= connect(sockfd,(struct sockaddr *) &serveraddr,sizeof(serveraddr));
        if(connected!=-1)
        {
            
            cout<<"Die Verbindung zum Server wurde hergestellt"<<endl;
            
            while(flag_sendandrcv)
                
            {
                cout<<"Nachricht an den Server: "<<endl;
                //Zur sendende Daten werden aus der Konsole gelesen inkl. term. Zeichen
                fgets(senddata,max_data_size,stdin);
                                                                         
                sendedBytes=write(sockfd,senddata,strlen(senddata)+1);             
                
               // cout<<sendedBytes<<endl;
               readedBytes= read(sockfd,receiveddata,sizeof(receiveddata));
               // cout<<readedBytes<<endl;
                
               if(readedBytes>0)
               {
                printf("Nachricht vom Server:\n%s",receiveddata);              
               }               
                                                 
                cout<<"Eine weitere Nachricht an den Server senden (J/N): "<<endl;
                fgets(input,4,stdin);
                                                          
                while(input[0] !='J')
                {                   
                     if(input[0]=='N')
                     {
                        close(sockfd);                       
                        cout<<"Die Verbindung zum Server wurde geschlossen"<<endl;
                        flag_sendandrcv=false;
                        break;                                                                                    
                     }  
                     
                      fgets(input,4,stdin);                    
                }                                                                                        
            }             
        }   
    }      
    return 0;
}

