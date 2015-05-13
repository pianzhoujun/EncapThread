#ifndef __CL_MUTEX_H__
#define __CL_MUTEX_H__

#include "CLMutex.h"
#include "CLCriticalSection.h"
#include "CLCondtionVariable.h"

class CLEvent {
public:
	CLEvent(bool bSemaphore = false){
		m_flag = 0;
		m_bSemaphore = bSemaphore;
	}
	CLStatus Set();
	CLStatus Wait();
	
private:
	CLMutex m_Mutex;
	CLCondtionVariable m_Cond;
	int m_flag;
	bool m_bSemaphore;
};

#endif
