#include "smallCar.h"
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

smallCar::smallCar(string _name, string _num)
:carPark(_name, _num)
{}

smallCar::~smallCar()
{}

int smallCar::getCharge()//�⺻��� 4,000��,������ 50%����
{
	int thisTime=difftime(outTime, inTime);
	if(thisTime < 1800)
		return 4000*0.50;
	else{
		charge = 4000+((thisTime-1800)/600)*500;
		return charge*0.50;
	}
}

void smallCar::showInfoCar()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
//	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}

void smallCar::carOut()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
	cout<<"����ð� : "<<get_outTime()<<endl;
	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}