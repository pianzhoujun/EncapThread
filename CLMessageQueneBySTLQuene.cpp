#include "CLMessageQueneBySTLQuene.h"
#include "CLCriticalSection.h"

CLMessage* CLMessageQueneBySTLQuene::GetMessage()
{
	m_Event.Wait();
	return Pop();
}


CLStatus CLMessageQueneBySTLQuene::PushMessage(CLMessage* pMessage)
{
	Push(pMessage);
	m_Event.Set();
}

CLMessage* CLMessageQueneBySTLQuene::Pop()
{	
	CLCriticalSection cs(&m_Mutex);	
	if (m_MessageQuene.empty())
		return 0;
	CLMessage* p = m_MessageQuene.front();
	m_MessageQuene.pop();
	return p;
}
