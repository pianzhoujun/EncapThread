#ifndef __CL_EXECUTIVE_FUNCTION_PROVIDER__
#define __CL_EXECUTIVE_FUNCTION_PROVIDER__

#include "CLStatus.h"
class CLExecutiveFunctionProvider {
	public:
		CLExecutiveFunctionProvider();
		virtual ~CLExecutiveFunctionProvider();
		virtual CLStatus RunExecutiveFunction(void* pContext) = 0;
};

#endif
