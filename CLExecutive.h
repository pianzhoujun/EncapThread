#ifndef __CL_EXECUTIVE_H__
#define __CL_EXECUTIVE_H__
#include "CLStatus.h"
#include "CLExecutiveFunctionProvider.h"

class CLExecutive {
public:
	explicit CLExecutive(CLExecutiveFunctionProvider *pExecutiveFunctionProvider)
		:m_pExecutiveFunctionProvider(pExecutiveFunctionProvider){}
	virtual ~CLExecutive(){
		delete m_pExecutiveFunctionProvider;
	}
	
public:
	virtual CLStatus Run(void *pContext = 0) = 0;
	virtual CLStatus WaitForDeath() = 0;
	
protected:
	CLExecutiveFunctionProvider* m_pExecutiveFunctionProvider;
};

#endif
