CLStatus.o: CLStatus.cpp CLStatus.h
	g++ -c CLStatus.cpp -o CLStatus.o

CLLogger.o: CLLogger.cpp CLLogger.h	
	g++ -c CLLogger.cpp -o CLLogger.o

CLThread.o: CLThread.cpp CLThread.h  
	g++ -c CLThread.cpp -o CLThread.o -lpthread
