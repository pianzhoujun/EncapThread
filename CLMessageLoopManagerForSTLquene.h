#ifndef __CL_MESSAGE_LOOP_MANAGER_FOR_STL_QUENE_H__
#define __CL_MESSAGE_LOOP_MANAGER_FOR_STL_QUENE_H__
#include "CLMessageQueneBySTLqQuene.h"
class CLMessageLoopManagerForSTLquene: public CLMessageLoopManagerF {
	public:
		CLMessageQueneBySTLqQuene(CLMessageQueneBySTLqQuene* pMessageQuene):
			m_pMessageQuene(pMessageQuene){}
		~CLMessageQueneBySTLqQuene(){
			while (true) {
				CLMessage* pMsg = Pop();
				if (pMsg == NULL)
					break;
				delete pMsg;
			}
			if (m_pMessageQuene)
				delete m_pMessageQuene;
		}

		virtual CLStatus Initialize();
		virtual CLStatus UnInitialize() ;
		virtual CLMessage* WaitForMessage() ;
		virtual CLStatus DispatchMessage(CLMessage* pMessage) ;
		
	private:
		CLMessageQueneBySTLqQuene *m_pMessageQuene;
};

#endif
