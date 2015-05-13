#include "CLMessageLoopManager.h"

CLStatus CLMessageLoopManager::EnterMessageLoop(void *pContext)
{
	Initialize();
	while (true) {
		CLMessage* pMsg = WaitForMessage();
		CLStatus s = DispatchMessage(pMsg);

		if (s.m_clReturnCode == QUIT_MESSAGE_LOOP)
			break;
	}
	UnInitialize();
	return CLStatus(0 , 0);
}
