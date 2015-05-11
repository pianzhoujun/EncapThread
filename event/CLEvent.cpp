#include "CLEvent.h"

CLStatus CLEvent::Set()
{
	try {
		CLCriticalSection cs(&m_Cond);
		m_flag = 1;
	}
	catch (const char *s){
		return CLStatus(-1 , 0);
	}
	CLStatus s = m_Cond.WakeUp();
	return s;
}

CLStatus CLEvent::Wait(CLMutex *pMutex)
{
	try {
		CLCriticalSection cs(&m_Mutex);
		while (m_flag == 0) {
			Cond.Wait(&m_Mutex);
		}
	}
	catch (const char *s) {
		return CLStatus(-1 , 0);	
	}
	return CLStatus(0 , 0);
	
}
