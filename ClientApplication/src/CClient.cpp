#include "CClient.h"

CClient::CClient()
{
}

void CClient::connectionHandler()
{
    m_Socket.setAddrInfoForClient();
    m_Socket.getConnectSocket();
}

void CClient::msgSend(std::string sMessage)
{
    m_Socket.msgSend(sMessage);
}

void CClient::msgReceive()
{
    std::vector<std::string> vRecvMsgBuff = m_Socket.msgReceive<std::string>();
    for (auto itr : vRecvMsgBuff)
    {
        std::cout << itr << std::endl;
    }
}

CClient::~CClient()
{
    //dtor
}
