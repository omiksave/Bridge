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

void TCPCOM_Client::sendPacket()
{
	blockClient.lock();
	sock->send(packet);//Send Latest Packet
	blockClient.unlock();
}

void TCPCOM_Client::threadClientFunc()
{
	std::cout << "Actively Sending Packets..." << std::endl;
	while (runClient) {
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		sendPacket();//Send Packet
		std::this_thread::sleep_for(std::chrono::milliseconds(4));
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	}
	std::cout << "No Longer Sending Packets" << std::endl;
}

void TCPCOM_Client::startClientThread()
{
	runSensor();//Start all sensor threads
	std::this_thread::sleep_for(std::chrono::seconds(1));
	runClient = true;//Start thread
	threadClient = std::thread(&TCPCOM_Client::threadClientFunc, this);//Create object specific thread for sending data to external computer
}

void TCPCOM_Client::stopClientThread()
{
	stopSensor();//Stop all sensor threads
	runClient = false;//Exit infinite while loop
	threadClient.join();//Kill thread
}
