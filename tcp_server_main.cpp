#include "tcp.h"


int main(int argc, char **argv){
    SERVER server("192.168.1.116", "8888");
    TCPComunication *TCP = &server;
    try{
        if (argc < 2){
            throw std::runtime_error("Command is not enough");
        }
        TCP->CreatSocket();
        server.BindSocket();
        server.ListenSocket();
        server.Accept();
        
        auto path = argv[1];
        std::fstream command(path, std::ios::in);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}