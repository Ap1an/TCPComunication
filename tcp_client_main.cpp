#include "tcp.h"


int main(int argc, char **argv){
    if (argc < 3){
        std::cout << "Command is not enough" << std::endl;
        return 1;
    }
    std::string ip = argv[1];
    CLIENT client(ip, "8888");
    TCPComunication *TCP = &client;
    try{
        TCP->CreatSocket();
        client.Connect();

        auto path = argv[2];
        std::fstream command(path, std::ios::app);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}