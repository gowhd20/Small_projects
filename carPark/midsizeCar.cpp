#include "midsizeCar.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

midsizeCar::midsizeCar(string _name, string _num)
:carPark(_name, _num)
{}

midsizeCar::~midsizeCar()
{}

int midsizeCar::getCharge()//�⺻��� 4,000�� 30���� 10�д� 500�� �߰�
{
	int thisTime=difftime(outTime, inTime);
	if(thisTime < 1800)
		return 4000;
	else{
		charge = 4000+((thisTime-1800)/600)*500;
		return charge;
	}
}

void midsizeCar::showInfoCar()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
//	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}

void midsizeCar::carOut()
{
	cout<<"����������������������������������\n";
	cout<<"�����̸� : "<<name<<endl;
	cout<<"������ȣ : "<<num<<endl;
	cout<<"�����ð� : "<<get_inTime()<<endl;
	cout<<"����ð� : "<<get_outTime()<<endl;
	cout<<"��    �� : "<<getCharge()<<"��\n";
	cout<<"����������������������������������\n";
}