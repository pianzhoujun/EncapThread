#ifndef __CL_EXECUTIVE_FUNCTIN_PROVIDER_H__
#define __CL_EXECUTIVE_FUNCTIN_PROVIDER_H__
#include "CLStatus.h"
class CLExecutiveFunctionProvider {
public:
	CLExecutiveFunctionProvider();
	virtual ~CLExecutiveFunctionProvider(){};
	virtual CLStatus RunExecutiveFunction(void *pContext) = 0;
};

#endif
