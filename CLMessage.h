#ifndef __CL_MESSAGE_H__
#define __CL_MESSAGE_H__
class CLMessage {
	public:
		CLMessage(unsigned long lMsgID){
			m_lMsgID = lMsgID;
		}
		
		const unsigned long& m_clMsgID;

	private:
		unsigned long m_lMsgID;
};
#endif
