#pragma once
#include <time.h>
#include <string>
using namespace std;

class carPark
{
protected:
	string name; //차량이름
	string num; //차량번호
	int charge; //요금

	time_t inTime;  //입차시간
	time_t outTime; // 출차시간
public:
	carPark();
	carPark(string, string);
	~carPark();
	virtual void showInfoCar(); //차량정보
	virtual void carOut(); //출차
	string getNum(){ return num; }
	const time_t* get_inTime() const{ return &inTime; }
	const time_t* get_outTime(){
		outTime = time(NULL);
		return &outTime;
	}
};