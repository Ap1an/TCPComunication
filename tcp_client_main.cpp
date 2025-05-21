#include "tcp.h"


int main(int argc, char **argv){
    CLIENT client("192.168.1.1", "8888");
    TCPComunication *TCP = &client;
    try{
        TCP->CreatSocket();
        client.Connect();

        std::fstream command("./command.txt", std::ios::app);
        TCP->ComunicationThread(command);
    }catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}