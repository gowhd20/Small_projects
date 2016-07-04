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

int heavyCar::getCharge()//기본요금 4,000원 대형차 10%할증
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
	cout<<"━━━━━━━대형차━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
//	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}

void heavyCar::carOut()
{
	cout<<"━━━━━━━━━━━━━━━━━\n";
	cout<<"차량이름 : "<<name<<endl;
	cout<<"차량번호 : "<<num<<endl;
	cout<<"입차시간 : "<<get_inTime()<<endl;
	cout<<"현재시간 : "<<get_outTime()<<endl;
	cout<<"요    금 : "<<getCharge()<<"원\n";
	cout<<"━━━━━━━━━━━━━━━━━\n";
}