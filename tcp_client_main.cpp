#include "tcp.h"


int main(int argc, char **argv){
    CLIENT client("192.168.1.1", "8888");
    TCPComunication *TCP = &client;
    try{
        if (argc < 2){
            throw std::runtime_error("Command is not enough");
        }
        TCP->CreatSocket();
        client.Connect();

        auto path = argv[1];
        std::fstream command(path, std::ios::app);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}