#pragma once
#include "carpark.h"
#include <string>
using namespace std;

class heavyCar :public carPark
{
public:
	heavyCar(string, string);
	~heavyCar();
	int getCharge(); //요금
	void showInfoCar(); //차량정보
	void carOut(); //출차
};
