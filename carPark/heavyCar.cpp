#include "heavyCar.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

heavyCar::heavyCar(string _name, string _num)
:carPark(_name, _num)
{}

heavyCar::~heavyCar()
{}

int heavyCar::getCharge()//�⺻��� 4,000�� ������ 10%����
{
	int thisTime=difftime(outTime, inTime);
	if(thisTime < 1800)
		return 4000+(4000*0.10);
	else{
		charge = 4000+((thisTime-1800)/600)*500;
		return charge+(charge*0.10);
	}
}

void heavyCar::showInfoCar()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
//	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}

void heavyCar::carOut()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
	cout<<"����ð� : "<<get_outTime()<<endl;
	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}