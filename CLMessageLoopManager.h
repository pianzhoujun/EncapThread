#ifndef __CL_MESSAGE_LOOP_MANAGER_H__
#define __CL_MESSAGE_LOOP_MANAGER_H__
#include "CLStatus.h"
#include "CLMessage.h"
#include "CLMessageOberver.h"
#include <map>
class CLMessageLoopManager {
	public:
//		CLMessageLoopManager(CLMessageOberver* pMsgOberver);
		~CLMessageLoopManager();
		virtual CLStatus EnterMessageLoop(void* pContext);
		virtual CLStatus Register(unsigned long lMsgID , CLMessageOberver* pMsgOberver);
	protected:
		virtual CLStatus Initialize() = 0;
		virtual CLStatus UnInitialize() = 0;
//		virtual CLMessage* WaitForMessage() = 0;
		virtual CLStatus DispatchMessage(CLMessage* pMessage);

	protected:
	//	CLMessageOberver* m_pMessageObserver;
		std::map<unsigned long , CLMessageOberver*> m_MsgMappingTable;
};
#endif
