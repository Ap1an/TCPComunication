#include "tcp.h" 

void SERVER::CreatSocket(){
    memset(&server_addr_, 0, sizeof(server_addr_));
    server_addr_.sin_family = AF_INET;
    if (inet_aton(ip_.c_str(), &server_addr_.sin_addr) == 0){
        throw std::runtime_error("IP address invail");
    }
    server_addr_.sin_port = atoi(port_.c_str());

    server_listen_sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_listen_sockfd_ < 0){
        throw std::runtime_error("Failed to create the server socket");
    }
}

void SERVER::BindSocket(){
    if (bind(server_listen_sockfd_, (struct sockaddr *)&server_addr_, sizeof(server_addr_)) < 0){
        throw std::runtime_error("Failed to bind socket");
    }
}

void SERVER::ListenSocket(){
    if (listen(server_listen_sockfd_, 20) < 0){
        throw std::runtime_error("Failed to listen port");
    }
}

void SERVER::Accept(){
    socklen_t len = sizeof(client_addr_);
    if ((server_connect_sockfd_ = accept(server_listen_sockfd_, (struct sockaddr *)(&client_addr_), &len)) < 0){
        throw std::runtime_error("Failed to accpet the requestion of client");
    }
}

void SERVER::ComunicationThread(std::fstream &file){
    if (!file.is_open()){
        throw std::runtime_error("Failed to open file");
    }

    std::vector<std::string> command;
    std::string buffer;
    while (file >> buffer){
        command.push_back(buffer);
    }

    //send 
    for (auto i = command.begin(); i != command.end(); ++i){
        if ((write(server_connect_sockfd_, &i, sizeof(i))) < 0){
            throw std::runtime_error("Failed to send data");
        }
    }

    std::cout << "Sent successfully" << std::endl;
}