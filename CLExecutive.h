#ifndef __CL_EXECTIVE_H__
#define __CL_EXECTIVE_H__

#include "CLStatus.h"
#include "CLExecutiveFunctionProvider.h"

class CLExecutive {
	public:
		explicit CLExecutive(CLExecutiveFunctionProvider* pExecutiveFunctionProvider);
		virtual ~CLExecutive();
		
		virtual CLStatus Run(void *pContext = 0) = 0;
		virtual CLStatus WaitForDeath() = 0;
		
	protected:
		CLExecutiveFunctionProvider* m_pExecutiveFunctionProvider;
		
};

#endif
