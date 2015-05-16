#ifndef __CL_EXECUTIVE_FUNCTION_FOR_MSG_LOOP_H__
#define __CL_EXECUTIVE_FUNCTION_FOR_MSG_LOOP_H__
#include "CLStatus.h"
#include "CLMessageLoopManager.h"
#include "CLExecutiveFunctionProvider.h"

class CLExecutiveFunctionForMsgLoop :public CLExecutiveFunctionProvider{
	public:
		explicit CLExecutiveFunctionForMsgLoop(CLMessageLoopManager* pMsgLoopManager)
			:m_pMsgLoopManager(pMsgLoopManager){}
		virtual CLExecutiveFunctionForMsgLoop(){
			if (m_pMsgLoopManager)
				delete m_pMsgLoopManager;
		}
		virtual CLStatus RunExecutiveFunction(void *pContext){
			return m_pMsgLoopManager->EnterMessageLoop(pContext);
		}

	private:
		CLMessageLoopManager *m_pMsgLoopManager;
};

#endif
