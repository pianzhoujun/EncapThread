#ifndef __CL_ADDER_H__
#define __CL_ADDER_H__
#include "CLExecutiveFuncitonProvider.h"
#include "CLStatus.h"
#include "CLMessageLoopManager.h"
class CLAdder : public CLExecutiveFuncitonProvider {
public:
	CLAdder(CLMessageLoopManager* pMsgLoopManager) :
		m_pMsgLoopManager(pMsgLoopManager) {}
	virtual ~CLAdder() {
		if (m_pMsgLoopManager)
			delete m_pMsgLoopManager;
	}
	virtual CLStatus RunExecutiveFunction(void* pContext)	{
		return m_pMsgLoopManager->EnterMessageLoop(pContext);	
	}

private:
	CLMessageLoopManager* m_pMsgLoopManager;
	
};

#endif
