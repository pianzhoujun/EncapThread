#ifndef __CL_MY_PROCESSOR_H__
#define __CL_MY_PROCESSOR_H__

//#include "CLMessageLoopManagerForSTLquene"
#include "CLAddMessage.h"
#include "CLMessageOberver.h"
class CLMyMsgProcessor : public CLMessageOberver {
	public:
#if 0
		virtual CLStatus DispatchMessage(CLMessage* pMessage){
			CLAddMessage* pAddMsg;
			switch (pMessage->m_clMsgID) {
				case ADD_MSG:
					break;
				case QUIT_MSG:
					break;
				default:
					break;
			}
		}
#endif
		virtual CLStatus Initialize(void *pContext) {
			return CLStatus(0 , 0);
		}
		virtual CLStatus Notify(CLMessage *pMsg){
			return CLStatus(0 , 0);
		}
};

#endif
