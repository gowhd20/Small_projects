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
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
}