#ifndef __CL_EXECTIVE_H__
#define __CL_EXECTIVE_H__

#include "CLStatus.h"
#include "CLCoordinator.h"
class CLCoordinator;

class CLExecutive {
	public:
		explicit CLExecutive(CLCoordinator* pCoordinator):m_pCoordinator(pCoordinator) {};
		virtual ~CLExecutive(){};
		virtual CLStatus Run(void *pContext = 0) = 0;
		virtual CLStatus WaitForDeath() = 0;
		
	protected:
		CLCoordinator *m_pCoordinator;
};

#endif
