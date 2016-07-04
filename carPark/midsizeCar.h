#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class midsizeCar :public carPark
{
public:
	midsizeCar(string, string);
	~midsizeCar();
	int getCharge(); //요금
	void showInfoCar(); //차량정보
	void carOut(); //출차
};
