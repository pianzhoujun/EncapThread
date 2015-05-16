#include "CLMessageLoopManager.h"
#if 0
CLMessageLoopManager::CLMessageLoopManager(CLMessageOberver* pMsgOberver)
	:m_pMessageObserver(pMsgOberver){}
#endif

CLMessageLoopManager::~CLMessageLoopManager()
{
	if (m_pMessageObserver)
		delete m_pMessageObserver;
}

CLStatus CLMessageLoopManager::Register(unsigned long lMsgID , CLMessageOberver* pMsgOberver)
{
	m_MsgMappingTable[lMsgID] = pMsgOberver;
	return CLStatus(0 , 0);
}

CLStatus CLMessageLoopManager::EnterMessageLoop(void *pContext)
{
	Initialize();
	std::map<unsigned long , CLMessageOberver*>::iterator iter;
	for (iter = m_MsgMappingTable.begin(); iter != m_MsgMappingTable.end() ; ++iter){
		iter->second->Initialize(pContext);
	}
	while (true) {
		CLMessage* pMsg = WaitForMessage();
		CLStatus s = DispatchMessage(pMsg);
//		CLStatus s = m_pMessageObserver->DispatchMessage(pMsg);
		delete pMsg;	
		if (s.m_clReturnCode == QUIT_MESSAGE_LOOP)
			break;
	}
	UnInitialize();
	return CLStatus(0 , 0);
}

CLStatus CLMessageLoopManager::DispatchMessage(CLMessage* pMessage)
{	
	std::map<unsigned long , CLMessageOberver*>::iterator iter;
	iter = m_MsgMappingTable.find(pMessage->m_clMsgID);
	if (iter->second)
		return it->second->Notify(pMessage);
}
