#include "CLCondtionVariable.h"

CLCondtionVariable::CLCondtionVariable()
{
	pthread_cond_init(&m_CondtionVariable , 0);
}

CLCondtionVariable::~CLCondtionVariable()
{
	pthread_cond_destroy(&m_CondtionVariable);
}

CLStatus CLCondtionVariable::Wait(CLMutex *pMutex)
{
	pthread_cond_wait(&m_CondtionVariable , &(pMutex->m_Mutex));
	return CLStatus(0 , 0);
}

CLStatus CLCondtionVariable::WakeUp()
{
	pthread_cond_signal(&m_CondtionVariable);
	return CLStatus(0 , 0);
}

CLStatus CLCondtionVariable::WakeUpAll()
{
	pthread_cond_broadcast(&m_CondtionVariable);
}
