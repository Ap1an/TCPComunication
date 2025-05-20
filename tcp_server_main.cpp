#include "tcp.h"


int main(int argc, char **argv){
    TCPComunication *TCP;
    SERVER server("192.168.1.1116", "8888");
    try{
        TCP->CreatSocket();
        server.BindSocket();
        server.ListenSocket();
        server.Accept();
        
        std::fstream command("./command.txt", std::ios::in);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}