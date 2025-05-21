#include "tcp.h"


int main(int argc, char **argv){
    if (argc < 3){
        std::cout << "Command is not enough" << std::endl;
        return 1;
    }
    std::string ip = argv[1];
    SERVER server(ip, "8888");
    TCPComunication *TCP = &server;
    try{
        TCP->CreatSocket();
        server.BindSocket();
        server.ListenSocket();
        server.Accept();
        
        auto path = argv[2];
        std::fstream command(path, std::ios::in);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}