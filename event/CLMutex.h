#ifndef __CL_MUTEX_H__
#define __CL_MUTEX_H__

#include <phtread.h>
#include "../CLStatus.h"
class CLMutex {
public:
	CLMutex() {
		pthread_mutex_init (&m_Mutex , 0);
	}
	~CLMutex(){
		pthread_mutex_destroy(&m_Mutex);
	}
	CLStatus Lock() {
		pthread_mutex_lock(&m_Mutex);
		return CLStatus (0 , 0);
	}
	CLStatus UnLock(){
		pthread_mutex_unlock(&m_Mutex);
		return CLStatus (0 , 0);
	}
	
private:
	pthread_mutex_t m_Mutex;
};

#endif
