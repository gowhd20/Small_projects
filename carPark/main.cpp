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
	int eCount=0; //�����ϴ� ���� ������ ����
	int space=100; //������ ����
	int menu, choice;
	string name, num, _num;

	smallCar *sp;
	midsizeCar *mp;
	heavyCar *hp;
	
	do{
		menu = Menu();
		if(menu == 1){
			cout<<"�����̸��� �Է��ϼ��� : ";
			cin>>name;
			cout<<"������ȣ�� �Է��ϼ��� : ";
			cin>>num;
		}
		switch(menu){
			case 1: //����
				system("cls");
				cout<<"������ �����ϼ���>>\n";
				cout<<"1.�� ��\n";
				cout<<"2.�� ��\n";
				cout<<"3.�� ��\n";
				cout<<"4.�����޴���\n";
				cin>>choice;
				if(space <= 0){
					cout<<"���� �Դϴ�.�������� �̿��� �ּ���!\n";
					break;
				}
				if(choice == 1){
					sp=new smallCar(name,num);
					cList[eCount++]=sp;
					space--;
					cout<<"���� �Ǿ����ϴ�!\n";
					cout<<"�ܿ���������>>> "<<space<<endl<<endl;
				}
				else if(choice == 2){
					mp=new midsizeCar(name,num);
					cList[eCount++]=mp;
					space--;
					cout<<"���� �Ǿ����ϴ�!\n";
					cout<<"�ܿ���������>>> "<<space<<endl<<endl;
				}
				else if(choice == 3){
					hp=new heavyCar(name,num);
					cList[eCount++]=hp;
					space--;
					cout<<"���� �Ǿ����ϴ�!\n";
					cout<<"�ܿ���������>>> "<<space<<endl<<endl;
				}
				else if(choice == 4)
					break;
				else
					cout<<"�ٽ� �Է��Ͻʽÿ�!\n";
				break;
			case 2: //����
				system("cls");
				cout<<"���� �� ������ �Է��ϼ���>>\n";
				cout<<"1.�� ��\n";
				cout<<"2.�� ��\n";
				cout<<"3.�� ��\n";
				cout<<"4.�����޴���\n";
				cin>>choice;
				if(choice == 1){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(smallCar)){
							cout<<"���� ������ ����>>>>\n";
							cList[i]->carOut();
						}
						cout<<"���� �� ������ȣ�� �Է��ϼ���>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"�����Ϸ�! �ܿ����������� "<<space<<"�� �Դϴ�.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 2){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(midsizeCar)){
							cout<<"���� ������ ����>>>>\n";
							cList[i]->carOut();
						}
						cout<<"���� �� ������ȣ�� �Է��ϼ���>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"�����Ϸ�! �ܿ����������� "<<space<<"�� �Դϴ�.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 3){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(heavyCar)){
							cout<<"���� ������ ����>>>>\n";
							cList[i]->carOut();
						}
						cout<<"���� �� ������ȣ�� �Է��ϼ���>>\n";
						cin>>_num;
						for(int i=0; i<eCount; i++){
							if(cList[i]->getNum() == _num){
								cList[i]->carOut();
								for(int j=i; j<eCount-1; j++){
									cList[j] = cList[j+1];
								}
								eCount--;
								space++;
								cout<<"�����Ϸ�! �ܿ����������� "<<space<<"�� �Դϴ�.\n\n";
								break;
							}
						}
						break;
				}
				else if(choice == 4)
					break;
				else
					cout<<"�ٽ� �Է��Ͻʽÿ�!\n";
				break;
			case 3: //���� ���� ��ȸ
				system("cls");
				cout<<"��ȸ �� ������ �����ϼ���>>>\n";
				cout<<"1.�� ��\n";
				cout<<"2.�� ��\n";
				cout<<"3.�� ��\n";
				cout<<"4.�����޴���\n";
				cin>>choice;
				if(choice == 1){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++){
						if(typeid(*cList[i])==typeid(smallCar))
							cList[i]->showInfoCar();
					}
				}
				else if(choice == 2){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(midsizeCar))
							cList[i]->showInfoCar();
				}
				else if(choice == 3){
					if(space == 100){
						cout<<"�����Ǿ� �ִ� ������ �����ϴ�!\n";
						break;
					}
					for(int i=0; i<eCount; i++)
						if(typeid(*cList[i])==typeid(heavyCar))
							cList[i]->showInfoCar();
				}
				else if(choice == 4)
					break;
				else
					cout<<"�ٽ� �Է��Ͻʽÿ�!\n\n";
				break;
			case 4: //����
				cout<<"���α׷��� �����մϴ�.\n";
				return;
			default: cout<<"�޴��� �߸� �����ϼ̽��ϴ�. �ٽ� �Է��ϼ���>>\n\n";
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
	cout<<"������������������������������������\n";
	cout<<"��   �ַ� ���� ������ ���� �ý��� ��\n";
	cout<<"��                                ��\n";
	cout<<"��1)��  ��                        ��\n";
	cout<<"��2)��  ��                        ��\n";
	cout<<"��3)������ ���� ��ȸ              ��\n";
	cout<<"��4)��  ��                        ��\n";
	cout<<"������������������������������������\n";
	cin>>choice;
	return choice;
}