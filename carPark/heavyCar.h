#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class heavyCar :public carPark
{
public:
	heavyCar(string, string);
	~heavyCar();
	int getCharge(); //���
	void showInfoCar(); //��������
	void carOut(); //����
};
