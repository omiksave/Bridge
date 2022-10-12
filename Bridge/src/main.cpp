
#include"TCPCOM_Client.h"//TCP Client Function
#include<timeapi.h>//Access system granularity

int main() {
	timeBeginPeriod(1);//Change system granularity to 1 ms, default 10ms
	TCPCOM_Client MyClient("192.168.7.1", 5001);//Initialize communication with Speedgoat
	std::cout << "Finished Setup" << std::endl;
	std::cin.get();
	MyClient.startClientThread();//Start Client thread
	std::cin.get();//Press Enter to safely interrupt
	MyClient.stopClientThread();//Stop Client Thread
	timeEndPeriod(1);//Return system granularity to default
	std::cin.get();
	return 0;
}
