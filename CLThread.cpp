#include "CLThread.h"
#include "CLLogger.h"

CLStatus CLThread::Run(void* pContext)
{
        m_pContext = pContext;
        int  r = pthread_create (&m_ThreadID , NULL , StartFunctionOfThread , this);
        if (r != 0) {
                CLLogger::WriteLogMsg("In CLTread::Run() , pthread_create error" , r);        
                return CLStatus(-1 , 0);
        }
        return CLStatus(0 , 0);
}

CLStatus CLThread::WaitForDeath()
{
        int r = pthread_join (m_ThreadID , 0);
        if (r != 0) {
                CLLogger::WriteLogMsg("In CLTread::WaitForDeath(),pthread_join error",r);
                return CLStatus(-1 , 0);
        }
}

void* CLThread::StartFunctionOfThread(void* pThis)
{
        CLThread *pThreadThis = (CLThread*)pThis;
        CLStatus s = pThreadThis->RunThreadFunction();
        return (void*)s.m_clReturnCode;
}
