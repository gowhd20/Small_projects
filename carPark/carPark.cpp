#include "carPark.h"
#include <iostream>
#include <string>
using namespace std;

carPark::carPark()
{}

carPark::carPark(string _name, string _num)
{
	name = _name;
	num = _num;
	inTime = time(NULL);
	outTime = time(NULL);
}

carPark::~carPark()
{}

void carPark::showInfoCar()
{
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
}