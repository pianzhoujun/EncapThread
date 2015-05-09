#ifndef __CL_MYPRINT_H__
#define __CL_MYPRINT_H__

#include "CLStatus.h"
#include "CLExecutiveFunctionProvider.h"

using namespace std;

class CLMyPrint: public CLExecutiveFunctionProvider {
	public:
		virtual CLStatus RunExecutiveFunction(void *pContext) {
			long i = (long)pContext;
			cout << i << "\n";
			return CLStatus(0 , 0);
		}
};
#endif
