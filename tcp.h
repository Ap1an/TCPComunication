#ifndef TCP_H
#define TCP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <thread>

//base class
class TCPComunication{
public:
    TCPComunication(std::string ip, std::string port): ip_(ip), port_(port){};

    virtual void CreatSocket();

    virtual void ComunicationThread(std::fstream &file);

    ~TCPComunication(){};
protected:
    std::string ip_;
    std::string port_;
};

//server class
class SERVER: public TCPComunication{
public:
    SERVER(std::string ip, std::string port): TCPComunication(ip, port){};
    void CreatSocket(); 
    void BindSocket();
    void ListenSocket();
    void Accept();

    void ComunicationThread(std::fstream &file);
private: 
    struct sockaddr_in server_addr_;
    struct sockaddr_in client_addr_;
    int server_listen_sockfd_;
    int server_connect_sockfd_;
};

//client class
class CLIENT: public TCPComunication{
public:
    CLIENT(std::string ip, std::string port): TCPComunication(ip, port){};
    void CreatSocket();
    void Connect();

    void ComunicationThread(std::fstream &file);
private:
    struct sockaddr_in server_addr_;
    int client_sockfd_;
};

#endif