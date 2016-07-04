#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class smallCar :public carPark
{
public:
	smallCar(string, string);
	~smallCar();
	int getCharge(); //요금
	void showInfoCar(); //차량정보
	void carOut(); //출차
};
