#ifndef __CL_MESSAGE_LOOP_MANAGER_H__
#define __CL_MESSAGE_LOOP_MANAGER_H__
#include "CLStatus.h"
#include "CLMessage.h"
class CLMessageLoopManager {
	public:
		virtual CLStatus EnterMessageLoop(void* pContext);
		
	protected:
		virtual CLStatus Initialize() = 0;
		virtual CLStatus UnInitialize() = 0;
		virtual CLMessage* WaitForMessage() = 0;
		virtual CLStatus DispatchMessage(CLMessage* pMessage) = 0;
};
#endif
