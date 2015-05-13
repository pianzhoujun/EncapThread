#ifndef __CL_ADD_MESSAGE_H__
#define __CL_ADD_MESSAGE_H__

#include "CLMessage.h"
#define ADD_MSG 0
class CLAddMessage :public CLMessage{
	public:
		CLAddMessage(int Op1 , int Op2):CLMessage(ADD_MSG) {}

	private:
		int m_Op1;
		int m_Op2;
};

#endif
