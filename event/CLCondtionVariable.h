#ifndef __CL_CONDTIONAL_VARIABLE_H___
#define __CL_CONDTIONAL_VARIABLE_H___

#include <pthread.h>
#include "../Status.h"
#include "CLMutex.h"
class CLCondtionVariable {
public:
	CLCondtionVariable();
	~CLCondtionVariable();
	CLStatus Wait(CLMutex* pMutex);
	CLStatus WakeUp();
	CLStatus WakeUpAll();
private:
	pthread_cond_t m_CondtionVariable;
};

#endif
