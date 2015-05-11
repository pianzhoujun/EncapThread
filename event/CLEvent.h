#ifndef __CL_MUTEX_H__
#define __CL_MUTEX_H__

#include "CLMutex.h"
#include "CLCriticalSection.h"
#include "CLCondtionVariable.h"

class CLEvent {
public:
	CLEvent(){
		m_flag = 0;
	}
	CLStatus Set();
	CLStatus Wait();
	
private:
	CLMutex m_Mutex;
	CLCondtionVariable m_Cond;
	int m_flag;
};

#endif
