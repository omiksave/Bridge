#include "TCPCOM_Client.h"

TCPCOM_Client::TCPCOM_Client(std::string add,int portx)
{
	address = add;//Assign address to class instance from main
	port = portx;//Assign port to class instance from main
	Connect();//Initialize socket
}

void TCPCOM_Client::Connect()
{
	io_service = std::make_unique<boost::asio::io_service>();
	sock = std::make_unique<boost::asio::ip::tcp::socket>(*io_service);
	error = std::make_unique<boost::system::error_code>();
	std::cout << "Connecting to Client...." << std::endl;
	sock->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address), port));
	std::cout << "Connected to Client!" << std::endl;
}

void TCPCOM_Client::getSensor()
{
	I1 = new InsoleWrapper(104);
	I2 = new InsoleWrapper(105);
	packet = { boost::asio::buffer(I1->p,128 * 4),
			   boost::asio::buffer(I1->p,128 * 4) };
}

void TCPCOM_Client::runSensor()
{
	I1->StartThread();//Start Insole 1 thread
	I2->StartThread();//Start Insole 2 thread
}

void TCPCOM_Client::stopSensor()
{
	I1->StopThread();//Stop Insole 1 thread
	I2->StopThread();//Stop Insole 2 thread
}