#ifndef __CL_COORDINATOR_H_
#define __CL_COORDINATOR_H_

#include "CLCoordinator.h"

class CLRegularCoordinator: public CLCoordinator  {
	public:
		virtual CLStatus Run(void *pContext);
		virtual CLStatus ReturnControlRights();
		virtual CLStatus WaitForDeath();
	private:
		void *m_pContext;
};


#endif
