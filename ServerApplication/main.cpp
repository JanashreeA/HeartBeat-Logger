#include <iostream>
#include "CServer.h"

using namespace std;

void threadFun()
{
    //int * ptr = (int *) data;
    std::cout << "New Thread For Client Created" << std::endl;
    std::cout << std::this_thread::get_id() << std::endl;
}

void ClientSession(CSocket m_Socket)
{
    CLogger *pLogger;
    pLogger = CLogger::getLoggerInstance();
    std::string sExit = "exit";
    bool bEndThread = true;
    std::cout << "Thread For New Client Created : " << std::this_thread::get_id() << std::endl;
    while ( m_Socket.ClientSocket != INVALID_SOCKET )
    {
        std::vector<std::string> vRecvMsgBuff = m_Socket.msgReceive<std::string>(false);
        for (int i = 0; i < vRecvMsgBuff.size();i ++)
        {
            std::cout << vRecvMsgBuff[i] << std::endl;
            pLogger->Log(vRecvMsgBuff[i]);
            if ( sExit.compare(vRecvMsgBuff[i]) == 0)
            {

            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}

int main()
{
    CSocket m_Socket;
    m_Socket.setAddrInfoForServer();
    CSocket::initializeWinsock();
    std::vector<std::thread> threads;
    int i = 0;
    while(i<50)
    {
        m_Socket.getClietSocket();
        while ( !m_Socket.isValidClientSocket() )
        {

        }
        threads.emplace_back(ClientSession,m_Socket);
    }
    for (std::thread & t : threads) {
    t.join();
    }
    while(1){}
    cout << "EOP!" << endl;
    return 0;
}
