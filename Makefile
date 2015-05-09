main: CLStatus.o CLLogger.o CLThread.o CLRegularCoordinator.o main.o
	g++ main.o CLStatus.o CLLogger.o CLThread.o CLRegularCoordinator.o -o Thread -lpthread

main.o: main.cpp  CLCoordinator.h CLThread.o CLExecutiveFunctionProvider.h CLMyPrint.h
	g++ -c main.cpp	

CLStatus.o: CLStatus.cpp CLStatus.h
	g++ -c CLStatus.cpp 

CLLogger.o: CLLogger.cpp CLLogger.h	
	g++ -c CLLogger.cpp -std=gnu++11

CLThread.o: CLThread.cpp CLThread.h  CLExecutive.h  CLLogger.o
	g++ -c CLThread.cpp -std=c++11
	
CLRegularCoordinator.o: CLRegularCoordinator.cpp CLRegularCoordinator.h CLCoordinator.h
	g++ -c CLRegularCoordinator.cpp 

clean:
	rm *.o
