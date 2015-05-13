#include "CLMessageLoopManagerForSTLquene.h"

CLStatus CLMessageLoopManagerForSTLquene::Initialize()
{
	return CLStatus(0 , 0);
}

CLStatus CLMessageLoopManagerForSTLquene::UnInitialize()
{
	return CLStatus(0 , 0);
}

CLMessage* CLMessageLoopManagerForSTLquene::WaitForMessage()
{
	return m_pMessageQuene.GetMessage();
}

