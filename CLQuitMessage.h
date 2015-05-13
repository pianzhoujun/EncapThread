#ifndef __CL_QUIT_MESSAGE_H__
#define __CL_QUIT_MESSAGE_H__
#define QUIT_MSG 1
#include "CLMessage"
class CLQuitMessage: public CLMessage {
	public:
		CLQuitMessage():CLMessage(QUIT_MSG){};
};
#endif
