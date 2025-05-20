#include "tcp.h"


int main(int argc, char **argv){
    TCPComunication *TCP;
    CLIENT client("192.168.1.1", "8888");
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