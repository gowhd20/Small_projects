#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class midsizeCar :public carPark
{
public:
	midsizeCar(string, string);
	~midsizeCar();
	int getCharge(); //���
	void showInfoCar(); //��������
	void carOut(); //����
};
