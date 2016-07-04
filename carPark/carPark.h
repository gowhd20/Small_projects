#pragma once
#include <time.h>
#include <string>
using namespace std;

class carPark
{
protected:
	string name; //�����̸�
	string num; //������ȣ
	int charge; //���

	time_t inTime;  //�����ð�
	time_t outTime; // �����ð�
public:
	carPark();
	carPark(string, string);
	~carPark();
	virtual void showInfoCar(); //��������
	virtual void carOut(); //����
	string getNum(){ return num; }
	const time_t* get_inTime() const{ return &inTime; }
	const time_t* get_outTime(){
		outTime = time(NULL);
		return &outTime;
	}
};