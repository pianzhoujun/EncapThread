#ifndef __CL_CORRDINATOR_H__
#define __CL_CORRDINATOR_H__

#include "CLStatus.h"
#include "CLExecutive.h"
#include "CLExecutiveFunctionProvider.h"

class CLExecutive;

class CLCoordinator {
	public:
		void SetExecObjects(CLExecutive *pExecutive , CLExecutiveFunctionProvider *pProvider)
		{
			m_pExecutive = pExecutive;
			m_pExecutiveFunctionProvider = pProvider;
		}

		virtual CLStatus Run(void *pContext) = 0;
		virtual CLStatus ReturnControlRights() = 0;
		virtual CLStatus WaitForDeath() = 0;
	protected:
		CLExecutive *m_pExecutive;
		CLExecutiveFunctionProvider *m_pExecutiveFunctionProvider;
};

#endif
