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

int smallCar::getCharge()//기본요금 4,000원,소형차 50%할인
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
	cout<<"━━━━━━━소형차━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
//	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}

void smallCar::carOut()
{
	cout<<"━━━━━━━━━━━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
	cout<<"현재시간 : "<<get_outTime()<<endl;
	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}