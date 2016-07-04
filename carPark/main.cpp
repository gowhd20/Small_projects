#include "carPark.h"
#include "smallCar.h"
#include "midsizeCar.h"
#include "heavyCar.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int Menu();

void main()
{
	char inTime[30];
	char outTime[30];
	carPark *cList[100];
	int eCount=0; //입차하는 차량 저장할 변수
	int space=100; //주차장 공간
	int menu, choice;
	string name, num, _num;

	smallCar *sp;
	midsizeCar *mp;
	heavyCar *hp;
	
	do{
		menu = Menu();
		if(menu == 1){
			cout<<"차량이름을 입력하세요 : ";
			cin>>name;
			cout<<"차량번호를 입력하세요 : ";
			cin>>num;
		}
		switch(menu){
			case 1: //입차
				system("cls");
				cout<<"차종을 선택하세요>>\n";
				cout<<"1.소 형\n";
				cout<<"2.중 형\n";
				cout<<"3.대 형\n";
				cout<<"4.상위메뉴로\n";
				cin>>choice;
				if(space <= 0){
					cout<<"만차 입니다.다음번에 이용해 주세요!\n";
					break;
				}
				if(choice == 1){
					sp=new smallCar(name,num);
					cList[eCount++]=sp;
					space--;
					cout<<"입차 되었습니다!\n";
					cout<<"잔여주차공간>>> "<<space<<endl<<endl;
				}
				else if(choice == 2){
					mp=new midsizeCar(name,num);
					cList[eCount++]=mp;
					space--;
					cout<<"입차 되었습니다!\n";
					cout<<"잔여주차공간>>> "<<space<<endl<<endl;
				}
				else if(choice == 3){
					hp=new heavyCar(name,num);
					cList[eCount++]=hp;
					space--;
					cout<<"입차 되었습니다!\n";
					cout<<"잔여주차공간>>> "<<space<<endl<<endl;
				}
				else if(choice == 4)
					break;
				else
					cout<<"다시 입력하십시오!\n";
				break;
			case 2: //출차
				system("cls");
				cout<<"출차 할 차종를 입력하세요>>\n";
				cout<<"1.소 형\n";
				cout<<"2.중 형\n";
				cout<<"3.대 형\n";
				cout<<"4.상위메뉴로\n";
				cin>>choice;
				if(choice == 1){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(smallCar)){
							cout<<"현재 입차된 차량>>>>\n";
							cList[i]->carOut();
						}
						cout<<"출차 할 차량번호를 입력하세요>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"출차완료! 잔여주차공간은 "<<space<<"대 입니다.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 2){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(midsizeCar)){
							cout<<"현재 입차된 차량>>>>\n";
							cList[i]->carOut();
						}
						cout<<"출차 할 차량번호를 입력하세요>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"출차완료! 잔여주차공간은 "<<space<<"대 입니다.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 3){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(heavyCar)){
							cout<<"현재 입차된 차량>>>>\n";
							cList[i]->carOut();
						}
						cout<<"출차 할 차량번호를 입력하세요>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"출차완료! 잔여주차공간은 "<<space<<"대 입니다.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 4)
					break;
				else
					cout<<"다시 입력하십시오!\n";
				break;
			case 3: //주차 차량 조회
				system("cls");
				cout<<"조회 할 차종을 선택하세요>>>\n";
				cout<<"1.소 형\n";
				cout<<"2.중 형\n";
				cout<<"3.대 형\n";
				cout<<"4.상위메뉴로\n";
				cin>>choice;
				if(choice == 1){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++){
						if(typeid(*cList[i])==typeid(smallCar))
							cList[i]->showInfoCar();
					}
				}
				else if(choice == 2){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(midsizeCar))
							cList[i]->showInfoCar();
				}
				else if(choice == 3){
					if(space == 100){
						cout<<"주차되어 있는 차량이 없습니다!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(heavyCar))
							cList[i]->showInfoCar();
				}
				else if(choice == 4)
					break;
				else
					cout<<"다시 입력하십시오!\n\n";
				break;
			case 4: //종료
				cout<<"프로그램을 종료합니다.\n";
				return;
			default: cout<<"메뉴를 잘못 선택하셨습니다. 다시 입력하세요>>\n\n";
				getch();
		}
	}while(menu != 4);

	delete[] sp;
	delete[] mp;
	delete[] hp;
}

int Menu()
{
	int choice;
	cout<<"┏━━━━━━━━━━━━━━━━┓\n";
	cout<<"┃   주례 공용 주차장 관리 시스템 ┃\n";
	cout<<"┃                                ┃\n";
	cout<<"┃1)입  차                        ┃\n";
	cout<<"┃2)출  차                        ┃\n";
	cout<<"┃3)주차된 차량 조회              ┃\n";
	cout<<"┃4)종  료                        ┃\n";
	cout<<"┗━━━━━━━━━━━━━━━━┛\n";
	cin>>choice;
	return choice;
}