#ifndef __CLTHRAED_H__
#define __CLTHRAED_H__

#include "CLStatus.h"
#include "CLExecutive.h"
#include "CLExecutiveFunctionProvider.h"
#include <pthread.h>

class CLThread :public CLExecutive {
        public:
                explicit CLThread(CLExecutiveFunctionProvider* pExecutiveFunctionProvider);
                virtual ~CLThread();
                CLStatus Run(void* m_pContext = 0);
                CLStatus WaitForDeath();
                
        private:
                static void* StartFunctionOfThread (void *pContext);
                
        protected:
                virtual CLStatus RunThreadFunction() = 0;

        protected:
                pthread_t m_ThreadID;
                void *m_pContext;
};

#endif
