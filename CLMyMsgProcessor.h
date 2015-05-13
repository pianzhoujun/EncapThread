#ifndef __CL_MY_PROCESSOR_H__
#define __CL_MY_PROCESSOR_H__

#include "CLMessageLoopManagerForSTLquene"
#include "CLAddMessage.h"
class CLMyMsgProcessor : public CLMessageLoopManagerForSTLquene {
	public:
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
};

#endif
