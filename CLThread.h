#ifndef __CLTHRAED_H__
#define __CLTHRAED_H__

#include "CLStatus.h"
#include "CLExecutive.h"
#include <pthread.h>

class CLThread : public CLExecutive{
public:
        CLThread();
        virtual ~CLThread(){
		delete *m_pContext;
	}
        virtual CLStatus Run(void* m_pContext = 0);
        virtual CLStatus WaitForDeath();
        
private:
        static void* StartFunctionOfThread (void *pContext);

protected:
        pthread_t m_ThreadID;
        void *m_pContext;
};

#endif
