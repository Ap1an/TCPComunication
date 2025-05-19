#include "tcp.h"


int main(int argc, char **argv){
    SERVER server("192.168.1.1", "8888");
    try{
        server.CreatSocket();
        server.BindSocket();
        server.ListenSocket();
        server.Accept();
        
        std::fstream command("./command.txt", std::ios::in);
        server.ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}