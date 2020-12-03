#include <iostream>
#include "CClient.h"

using namespace std;

int main()
{
    CLogger *pLogger;
    pLogger = CLogger::getLoggerInstance();
    CSocket::initializeWinsock();
    CClient objClient;
    objClient.connectionHandler();
    std::string strClientName;
    std::cout << "Enter Client Name : ";
    std::cin >> strClientName;
    objClient.msgSend(strClientName);
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        objClient.msgSend(strClientName);
        pLogger->Log(" Send Heartbeat Message to server");
    }
    return 0;
}
