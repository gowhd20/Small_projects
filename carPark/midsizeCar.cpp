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

int midsizeCar::getCharge()//기본요금 4,000원 30분후 10분당 500원 추가
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
	cout<<"━━━━━━━중형차━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
//	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}

void midsizeCar::carOut()
{
	cout<<"━━━━━━━━━━━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
	cout<<"현재시간 : "<<get_outTime()<<endl;
	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}