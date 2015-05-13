#ifndef __CL_MESSAGEQUENE_BY_STL_QUENE_H__
#define __CL_MESSAGEQUENE_BY_STL_QUENE_H__
#include "CLMessage.h"
#include "CLMutex.h"
#include "event/CLEvent.h"
#include "CLStatus.h"
#include <quene>

class CLMessageQueneBySTLQuene {
	public:
		CLMessageQueneBySTLQuene(const CLMutex &mutex , const CLEvent &event) {
			m_Mutex = mutex;
			m_Event = event;
		}

		CLMessage* GetMessage();
		CLStatus   PushMessage(CLMessage* pMessage);

	private:
		CLMessage* Pop();
		CLStatus   Push(CLMessage* pMessage);

	private:
		std::quene<CLMessage*> m_MessageQuene;
		CLMutex m_Mutex;
		CLEvent m_Event;
		
};

#endif
