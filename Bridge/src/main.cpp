#include<iostream>
#include<boost/asio.hpp>
#include"InsoleWrapper.h"

int main() {

	InsoleWrapper::tx = new InsoleWrapper();
//	printf("Connecting Sensor1\n");
//	Tactilus* t = new Tactilus();
//	t->connect(true);
//	printf("Sensor1 Connected\n");
//	printf("Connecting Sensor2\n");
//	Tactilus* t2 = new Tactilus();
//	t2->connect(true);
//	printf("Sensor2 Connected\n");
//
//	printf("FRAME BEGIN\n");
//	int i=0;
//	float* value;
//	float* value2;
//	while (true)
//	{
//		t->scan();
//		t2->scan();
//		value = t->matrix();
//		value2 = t2->matrix();
//		printf("##########FRAME %i#############\n", i);
//		//for (int r = 0; r < t->rowCount(); r++) {
//		//	for (int c = 0; c < t->columnCount(); c++) {
//		//		printf("%f %f  ", *value,*value2);
//		//		value++;
//		//		value2++;
//		//	}
//		//	printf("\n");
//		//}
//		//i++;
//	}
//	printf("FRAME END");
//	return 0;
///*	std::cout << "Hello World!" << std::endl;
//	std::cin.get();
//	return 0;*/
}