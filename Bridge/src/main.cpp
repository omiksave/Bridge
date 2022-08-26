#include<iostream>
#include<boost/asio.hpp>
#include"InsoleWrapper.h"

using namespace boost::asio;
using ip::tcp;


int main() {

	InsoleWrapper* I1 = new InsoleWrapper();
	//InsoleWrapper I2;
	I1->StartThread();
	//I2.UpdateInsole();
	boost::asio::io_service io_service;
	//socket creation
	tcp::socket socket(io_service);
	//connection
	//socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("192.168.7.1"), 5001));

	 //request/message from client
	boost::system::error_code error;

	std::atomic<bool> runner = true;

	//std::thread tthr(sendPacket, pointrunner, I1, error, socket);
	std::cin.get();
	runner = false;
	//while(1) {
	//	boost::asio::write(socket, boost::asio::buffer(I1.p, 128 * 4), error);
	//	std::this_thread::sleep_for(std::chrono::microseconds(100));
	//}

	std::cin.get();


}