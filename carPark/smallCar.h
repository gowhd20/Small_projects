#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class smallCar :public carPark
{
public:
	smallCar(string, string);
	~smallCar();
	int getCharge(); //���
	void showInfoCar(); //��������
	void carOut(); //����
};
