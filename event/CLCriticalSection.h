#ifndef __CL_CRITICAL_SECTION_H__
#define __CL_CRITICAL_SECTION_H__

#include "CLMutex.h"
#include "../CLLogger.h"
class CLCriticalSection {
public:
	CLCriticalSection(CLMutex *pMutex) {
		if (pMutex == NULL) {
			CLLogger::WriteMsgLog("In CLCriticalSection::CLCriticalSection() , pMutex == NULL" , 0);
			throw "In CLCriticalSection::CLCriticalSection() , pMutex == NULL";
		}
		
		m_pMutex = pMutex;
		CLStatus s = m_pMutex->Lock();
		if (!s.IsSuccess()) {
			CLLogger::WriteMsgLog("In CLCriticalSection::CLCriticalSection() , pMutex->Lock error" , 0);
			throw "In CLCriticalSection::CLCriticalSection() , pMutex->Lock error";
		}
	}
	~CLCriticalSection() {
		CLStatus s = m_pMutex->UnLock();
		if (!s.IsSuccess()) {
			CLLogger::WriteMsgLog("In CLCriticalSection::CLCriticalSection() , pMutex->Lock error" , 0);
			throw "In CLCriticalSection::CLCriticalSection() , pMutex->Lock error";
		}
	}
private:
	CLMutex *m_pMutex;	
};

#endif
