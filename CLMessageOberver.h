#ifndef __CL_MESSAGE_OBERVER_H__
#define __CL_MESSAGE_OBERVER_H__
#include "CLStatus.h"
#include "CLMessage.h"
class CLMessageOberver {
	public:
		CLMessageOberver();
		virtual ~CLMessageOberver();
		
		virtual CLStatus Initialize(void *pContext) = 0;
//		virtual CLStatus DispatchMessage(CLMessage *pMsg) = 0;
		virtual CLStatus Notify(CLMessage *pMsg) = 0;
};
#endif
