#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100000000  // ���� ����ǥ 

typedef struct node                                           
{
	char iData[10];  //�������
	int MyScore;
	int YouScore;
	int iKey;  // ��¥(��)
	int ByteData;
	int LeftByte;
	int RightByte;
	int DataPoint;
	struct node *pNext1,*pNext2;				//��� ����
}node;

void Start();									//�����Լ�
int Insert(int iNumber, char [], int, int);						//�����Լ�
void SizeOutput(node *pLink);			//ũ��� ��� �Լ�
void FirstOutput(node *pLink);			//���� ��ȸ �Լ�
void FinalOutput(node *pLink);			//���� ��ȸ �Լ�
int Search(int iNumber);						//�˻��Լ�
int Deletion(int iNumber);
void Save(node *pLink,FILE *fp);
void Load(node *pLink,FILE *fp);
void inLoad(node *pLink,FILE *fp);

void main ()
{
	Start();
}

node *pHead = NULL;
node *pLink;

void Start()
{
	int iNum;
	int iCount=1;
	int iInsertNum;
	int StartInsert;
	int StartSearch,iSearchNum;
	int iOutputNum;
	int iDeleteNum;
	int StartDelete;
	int DataNum;
	char Data[10];  // ������
	int myScore;
	int youScore;
	int DayNum;
	int winCount = 0;
	int loseCount = 0;
	int samsamCount = 0;

	while(iCount != 0)
	{
		system("cls");
		COORD cur;
		cur.X = 40;
		cur.Y = 2; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("��������������������������������������\n");
		cur.X = 40;
		cur.Y = 3; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("�� ��¥ �Է½�                      ��\n");
		cur.X = 40;
		cur.Y = 4; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("�� ex) 2011�� 01�� 01��             ��\n");
		cur.X = 40;
		cur.Y = 5; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("��    -> 20110101                   ��\n");
		cur.X = 40;
		cur.Y = 6; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("��������������������������������������");
		cur.X = 40;
		cur.Y = 7; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("�� �� ���� : %d �� %d �� %d ��         ��",winCount, samsamCount, loseCount);
		cur.X = 40;
		cur.Y = 8; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("��������������������������������������\n");

		cur.X = 0;
		cur.Y = 1; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

		printf("������������������������������\n");
		printf("������ : �����             ��\n");
		printf("������������������������������\n");
		printf("��1. ��� ��� ���         ��\n");
		printf("��2. ��� ����              ��\n");
		printf("��3. ��� ��� �˻�         ��\n");
		printf("��4. ��� ��� ����         ��\n");
		printf("��5. ��� ��� ���Ͽ� ����  ��\n");
		printf("��6. �� ��                  ��\n");
		printf("��0. �� ��                  ��\n");
		printf("������������������������������\n");
		printf("�Է� >> ");
		scanf("%d",&iNum);
		fflush(stdin);

		if(0 <= iNum && 10 >= iNum)
		{
			switch(iNum)
			{
			case 1:														//���� �Լ�(case)
				printf("\n\n��� ��� ���\n\n");
				printf("��¥ �Է� : ");
				scanf("%d",&iInsertNum);								//���� �� �� ����
				fflush(stdin);

				printf("������� �Է� : ");
				scanf("%s",Data);
				fflush(stdin);

				printf("���� �� ���ھ� �Է� : ");
				scanf("%d",&myScore);
				printf("��� �� ���ھ� �Է� : ");
				scanf("%d",&youScore);
				fflush(stdin);

				if(0 < iInsertNum && MAX >= iInsertNum)
				{
					StartInsert = Insert(iInsertNum, Data, myScore, youScore);	

					if(StartInsert == 1)
					{
						printf("\n\n���� ����");
						winCount++;
					}
					else if(StartInsert == 2)
					{
						printf("\n\n���� ����");
						loseCount++;
					}
					else if(StartInsert == 3)
					{
						printf("\n\n���� ����");
						samsamCount++;
					}
					else
						printf("\n\n��¥ ��� ����");
					pLink = pHead;
				}

				else
				{
					printf("��� ����");
				}
				printf("\n\n\n");
				break;			

			case 2:														//��� �Լ�(case)
				printf("\n\n��� ����\n\n");
				printf("1. ��¥�� ���  2. ������ȸ 3. ������ȸ\n");
				printf("�Է� >> ");
				scanf("%d",&iOutputNum);
				fflush(stdin);

				if(0 < iOutputNum && 4 > iOutputNum)
				{
					int y = 21;
					switch(iOutputNum)
					{
					case 1:
						SizeOutput(pLink);			//ũ���
						break;
					case 2:
						FirstOutput(pLink);			//����
						break;

					case 3:
						FinalOutput(pLink);			//����
						break;

					default :
						printf("\n\n�߸� �Է�\n\n");
					}

					pLink = pHead;
				}

				else
				{
					printf("�߸� �Է� �Ͽ����ϴ�.");
				}

				printf("\n\n\n");
				break;

			case 3:
				//�˻� �Լ�(case)
				printf("\n\n�� ��\n\n");
				printf("�˻��� ��¥ �Է� : ");
				scanf("%d",&iSearchNum);								//�˻� �� �� ����
				fflush(stdin);

				if(0 < iSearchNum && MAX >= iSearchNum)
				{
					StartSearch = Search(iSearchNum);

					if(StartSearch != 0)
					{
						printf("\n\n�˻� ����\n\n");
					}
					else
						printf("\n\n�˻� ����\n\n\n");
				}

				else
					printf("�߸��Է� �Ͽ����ϴ�.\n\n\n");

				break;

			case 4:														//���� �Լ�(case)
				printf("\n\n�� ��\n\n");
				printf("\n===========================================================================\n\n");
				SizeOutput(pLink);
				printf("\n===========================================================================\n");
				printf("������ ��¥ �Է� : ");
				scanf("%d",&iDeleteNum);								//���� �� �� ����
				fflush(stdin);

				pLink = pHead;
				while(pLink != NULL)
				{
					if(iDeleteNum == pLink->iKey)
					{
						if(pLink->MyScore > pLink->YouScore)
							winCount--;
						else if(pLink->MyScore < pLink->YouScore)
							loseCount--;
						else
							samsamCount--;
						break;
					}

					if(iDeleteNum > pLink->iKey)
					{
						pLink = pLink->pNext2;
					}
					else if(iDeleteNum < pLink->iKey)
					{
						pLink = pLink->pNext1;
					}
					if(pLink == NULL)
					{
						break;
					}
				}
				pLink = pHead;

				Deletion(iDeleteNum);
				pLink = pHead;

				break;

			case 5:
				printf("\n\n�� ��\n\n�� �� �� ��\n");
				FILE *fp;
				fp = fopen("Save.bin","wb");
				Save(pLink,fp);
				fclose(fp);
				printf("\n\n");
				break;

			case 6:
				printf("\n\n�� ��\n\n");

				fp = fopen("Save.bin","rb");
				if(fp == NULL)
				{
					printf("������ ã���� �����ϴ�.");
					return;
				}

				Load(pLink,fp);

				pLink = pHead;

				printf("\n\n");
				break;

			case 0:														//����
				printf("\n\n�� ��\n\n\n");
				exit(0);

			default:													//�ٸ���
				printf("\n\n�ٽ� �Է��Ͻÿ�.\n\n\n");
			}
		}
		else
			printf("\n\n�ٽ� �Է��Ͻÿ�.\n\n\n");
		printf("Enter �Է��Ͻÿ�.");
		getchar();
	}

}
//�� 1, �� 2, �� 3
int Insert(int iNumber, char Data[], int myScore, int youScore)			//�����Լ�
{
	node *pTemp;
	int DataNum;

	if(iNumber < 0)			// ����� ������ '-' �� ����
		return 0;

	if(iNumber == 0)
		return 0;


	if(pHead == NULL)			//pHead �� NULL�� ���(ù��° ���� �� ���)
	{
		pHead = (struct node*)malloc(sizeof(struct node));
		pLink = (struct node*)malloc(sizeof(struct node));

		pHead->iKey = iNumber;
		strcpy(pHead->iData, Data);
		pHead->MyScore = myScore;
		pHead->YouScore = youScore;
		//pHead->iData = Data;

		pLink = pHead;			//pLink �� pHead ����

		pLink->pNext1 = NULL;
		pLink->pNext2 = NULL;

		if(myScore > youScore)
			return 1;
		else if(myScore < youScore)
			return 2;
		else
			return 3;
	}

	pLink = (node *)malloc(sizeof(node));
	pLink = pHead;

	/*while(pLink != NULL)  //
	{
		if(iNumber == pLink->iKey)
		{
			pLink = pLink->pNext1;
		}

		if(iNumber > pLink->iKey)
		{
			pLink = pLink->pNext2;
		}
		else if(iNumber < pLink->iKey)
		{
			pLink = pLink->pNext1;
		}
		if(pLink == NULL)
		{
			break;
		}
	}*/

	pLink = pHead;

	while(pHead != NULL)			//���ѷ���
	{
		if(iNumber == pLink->iKey)
		{
			pTemp = (struct node*)malloc(sizeof(struct node));
			pTemp->iKey = iNumber;
			strcpy(pTemp->iData, Data);
			pTemp->MyScore = myScore;
			pTemp->YouScore = youScore;
			//pTemp->iData = Data;

			pLink->pNext1 = pTemp;

			pTemp->pNext1 = NULL;
			pTemp->pNext2 = NULL;
			pLink = pHead;			//pLink�� ù ���� �̵�(pHead ����)

			if(myScore > youScore)
				return 1;
			else if(myScore < youScore)
				return 2;
			else
				return 3;
		}
		else if(iNumber > pLink->iKey)			//�������� ���� ���԰����� �������
		{
			if(pLink->pNext2 == NULL)
			{		
				pTemp = (struct node*)malloc(sizeof(struct node));
				pTemp->iKey = iNumber;
				strcpy(pTemp->iData, Data);
				pTemp->MyScore = myScore;
				pTemp->YouScore = youScore;
				//pTemp->iData = Data;

				pLink->pNext2 = pTemp;			//pLink�� ������(pNext2)�� pTemp�� ����Ŵ 

				pTemp->pNext1 = NULL;
				pTemp->pNext2 = NULL;
				pLink = pHead;			//pLink�� ù ���� �̵�

				if(myScore > youScore)
					return 1;
				else if(myScore < youScore)
					return 2;
				else
					return 3;
			}
			else								//�������� ���� ���԰����� �������
				pLink = pLink->pNext2;			//�������� ���� �̵�
		}

		else if(iNumber < pLink->iKey)			//�������� ���� ���԰����� Ŭ���
		{
			if(pLink->pNext1 == NULL)
			{
				pTemp = (struct node*)malloc(sizeof(struct node));
				pTemp->iKey = iNumber;
				strcpy(pTemp->iData, Data);
				pTemp->MyScore = myScore;
				pTemp->YouScore = youScore;
				//pTemp->iData = Data;

				pLink->pNext1 = pTemp;

				pTemp->pNext1 = NULL;
				pTemp->pNext2 = NULL;
				pLink = pHead;			//pLink�� ù ���� �̵�(pHead ����)

				if(myScore > youScore)
					return 1;
				else if(myScore < youScore)
					return 2;
				else
					return 3;
			}
			else								//�������� ���� ���԰����� Ŭ���
				pLink = pLink->pNext1;			//������ ���� �̵�
		}
	}
}

void SizeOutput(node *pLink)			//���� ũ�� ������� ���(����Լ� Ȱ��)
{
	COORD cur;
	if(pLink != NULL)
	{
		SizeOutput(pLink->pNext1);
		printf("��¥ : %d,  ������� : %s,  ���ǽ��ھ� : %d,  ��뽺�ھ� : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
		SizeOutput(pLink->pNext2);
	}
}

void FirstOutput(node *pLink)			//������ȸ(����Լ� Ȱ��)
{
	if(pLink != NULL)    // ������ȯ
	{
		printf("��¥ : %d,  ������� : %s,  ���ǽ��ھ� : %d,  ��뽺�ھ� : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
		FirstOutput(pLink->pNext1);
		FirstOutput(pLink->pNext2);
	}
}

void FinalOutput(node *pLink)			//������ȸ(����Լ� Ȱ��)
{
	if(pLink != NULL)    
	{
		FinalOutput(pLink->pNext1);
		FinalOutput(pLink->pNext2);
		printf("��¥ : %d,  ������� : %s,  ���ǽ��ھ� : %d,  ��뽺�ھ� : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
	}
}

int Search(int iNumber)			//�˻� �Լ�
{
	if(pHead == NULL)			//���� ���� ���Ե��� ���� ���(pHead���� NULL�� ���)
		return 0;

	while(pLink != NULL)			//���ѷ���
	{
		if(iNumber == pLink->iKey)			//�����Ͱ��� �˻����� �������
		{
			printf("��¥ : %d\n",pLink->iKey);
			printf("������� : %s\n",pLink->iData);
			printf("���� ���ھ� : %d\n",pLink->MyScore);
			printf("����� ���ھ� : %d\n",pLink->YouScore);
			pLink = pHead;					//
			return iNumber;					//�˻��� ����
		}

		if(iNumber > pLink->iKey)
		{
			if(pLink->pNext2 == NULL)
			{
				pLink = pHead;
				return 0;
			}
			pLink = pLink->pNext2;
		}
		else if(iNumber < pLink->iKey)
		{
			if(pLink->pNext1 == NULL)
			{
				pLink = pHead;
				return 0;
			}
			pLink = pLink->pNext1;
		}
	}
}

int Deletion(int iNumber)			//���� �Լ�
{
	node *pSave1,*pSave2,*pSaveLeft,*pSaveRight,*pTemp,*pEnd;

	if(pHead == NULL)			//���� ���� ���Ե��� ���� ���(pHead���� NULL�� ���)
		return 0;

	if(pHead->iKey == iNumber)			//�������� ù���(pHead�� �����Ͱ�)���� ��������� ó������
	{
		if(pHead->pNext2 == NULL && pHead->pNext1 == NULL)
		{
			pHead = NULL;
			return 1;
		}

		if(pHead->pNext1 != NULL && pHead->pNext2 == NULL)
		{
			pHead = pHead->pNext1;
			return 1;
		}

		if(pHead->pNext1 == NULL && pHead->pNext2 != NULL)
		{
			pHead = pHead->pNext2;
			return 1;
		}

		if(pHead->pNext1 != NULL && pHead->pNext2 != NULL)
		{
			pSaveLeft = pHead->pNext1;
			pSaveRight = pHead->pNext2;
			pLink = pHead->pNext1;
			while(pLink != NULL)
			{
				if(pLink->pNext2 == NULL)
				{
					pHead = pLink;
					pLink->pNext2 = pSaveRight;
					return 1;
				}

				if(pLink->pNext2 != NULL)
				{
					if(pLink->pNext2->pNext1== NULL && pLink->pNext2->pNext2 == NULL)
					{
						pSave1 = pLink->pNext2;
						pLink->pNext2 = NULL;
						pSaveLeft = pHead->pNext1;
						pHead = pSave1;
						pHead->pNext1 = pSaveLeft;
						pHead->pNext2 = pSaveRight;
						return 1;
					}

					if(pLink->pNext2->pNext2== NULL && pLink->pNext2->pNext1 != NULL)
					{
						pSave1 = pLink->pNext2;
						pSave1->pNext1 = NULL;
						pLink->pNext2 = pLink->pNext2->pNext1;
						pSaveLeft = pHead->pNext1;
						pHead = pSave1;
						pHead->pNext2 = pSaveRight;
						pHead->pNext1 = pSaveLeft;

						return 1;
					}

				}

				pLink = pLink->pNext2;
			}
		}
	}

	pTemp = pHead;
	pLink = pHead;

	while(pTemp != NULL)
	{
		if(pTemp->pNext1 != NULL)
		{
			if(pTemp->pNext1->iKey == iNumber && pTemp->pNext1->pNext1 != NULL && pTemp->pNext1->pNext2 != NULL)
			{ // ���ʳ�尡 NULL �� �ƴѰ��

				pSaveLeft = pTemp->pNext1->pNext1;
				pSaveRight = pTemp->pNext1->pNext2;

				pLink = pTemp->pNext1->pNext2;

				while(pLink != NULL)
				{
					if(pLink->pNext1 != NULL)
					{
						if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 == NULL)
						{
							pSave1 = pLink->pNext1;
							pLink->pNext1 = NULL;
							pTemp->pNext1 = pSave1;
							pTemp->pNext1->pNext1 = pSaveLeft;
							pTemp->pNext1->pNext2 = pSaveRight;

							return 1;
						}

						if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 != NULL)
						{
							pSave2 = pLink->pNext1->pNext2;
							pLink->pNext1->pNext2 = NULL;
							pSave1 = pLink->pNext1;
							pLink->pNext1 = pSave2;
							pTemp->pNext1 = pSave1;
							pTemp->pNext1->pNext1 = pSaveLeft;
							pTemp->pNext1->pNext2 = pSaveRight;

							return 1;
						}
					}

					else   // pLink->pNext1 == NULL
					{
						pTemp->pNext1 = pLink;
						pTemp->pNext1->pNext1 = pSaveLeft;

						return 1;
					}
					pLink = pLink->pNext1;
				}
			}

			if(pTemp->pNext1->iKey == iNumber && pTemp->pNext1->pNext1 != NULL && pTemp->pNext1->pNext2 == NULL)
			{
				pLink = pTemp->pNext1->pNext1;
				while(pLink != NULL)
				{
					if(pLink->pNext2 == NULL)
					{
						pTemp->pNext1 = pTemp->pNext1->pNext1;
						return 1;
					}
					if(pLink->pNext2->pNext2 == NULL && pLink->pNext2->pNext1 == NULL)
					{
						pSave1 = pLink->pNext2;
						pLink->pNext2 = NULL;
						pSaveRight = pTemp->pNext1->pNext1;
						pTemp->pNext1 = pSave1;
						pTemp->pNext1->pNext1 = pSaveRight;
						return 1;
					}
					if(pLink->pNext2->pNext2 == NULL && pLink->pNext2->pNext1 != NULL)
					{
						pSave1 = pLink->pNext2;
						pLink->pNext2 = pLink->pNext2->pNext1;
						pTemp->pNext1 = pSave1;
						pSave1->pNext2 = NULL;
						pSave1->pNext1 = pLink;
						return 1;
					}
					pLink = pLink->pNext2;
				}
				return 1;
			} //����� ���� ����� ���� �������̰� �� ����� ������ ��尡 NULL �� ���


			if(pTemp->pNext1->iKey == iNumber && pTemp->pNext1->pNext1 == NULL && pTemp->pNext1->pNext2 != NULL)
			{
				pLink = pTemp->pNext1->pNext2;
				while(pLink != NULL)
				{
					if(pLink->pNext1 == NULL)
					{
						pTemp->pNext1 = pTemp->pNext1->pNext2;
						return 1;
					}
					if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 == NULL)
					{
						pSave1 = pLink->pNext1;
						pLink->pNext1 = NULL;
						pSaveRight = pTemp->pNext1->pNext2;
						pTemp->pNext1 = pSave1;
						pTemp->pNext1->pNext2 = pSaveRight;
						return 1;
					}
					if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 != NULL)
					{
						pSave2 = pLink->pNext1->pNext2;
						pLink->pNext1->pNext2 = NULL;
						pSave1 = pLink->pNext1;
						pLink->pNext1 = pSave2;
						pSaveRight = pTemp->pNext1->pNext2;
						pTemp->pNext1 = pSave1;
						pTemp->pNext1->pNext2 = pSaveRight;
						return 1;
					}
					pLink = pLink->pNext1;
				}
				return 1;
			} //����� ���� ����� ���� �������̰� �� ����� ���� ��尡 NULL �� ���


			if(pTemp->pNext1->iKey == iNumber && pTemp->pNext1->pNext1 == NULL && pTemp->pNext1->pNext2 == NULL)
			{
				pTemp->pNext1 = NULL;
				return 1;
			} //����� ���� ����� ���� �����Ͱ� NULL�� ���
		}

		if(pTemp->pNext2 != NULL)
		{
			if(pTemp->pNext2->iKey == iNumber && pTemp->pNext2->pNext1 != NULL && pTemp->pNext2->pNext2 != NULL)
			{
				pSaveLeft = pTemp->pNext2->pNext1;
				pSaveRight = pTemp->pNext2->pNext2;

				pLink = pTemp->pNext2->pNext2;

				while(pLink != NULL)
				{
					if(pLink->pNext1 != NULL)
					{
						if(pLink->pNext1->pNext1== NULL && pLink->pNext1->pNext2 == NULL)
						{
							pSave1 = pLink->pNext1;
							pLink->pNext1 = NULL;
							pTemp->pNext2 = pSave1;
							pTemp->pNext2->pNext1 = pSaveLeft;
							pTemp->pNext2->pNext2 = pSaveRight;

							return 1;
						}

						if(pLink->pNext1->pNext1== NULL && pLink->pNext1->pNext2 != NULL)
						{
							pSave2 = pLink->pNext1->pNext2;
							pLink->pNext1->pNext2 = NULL;
							pSave1 = pLink->pNext1;
							pLink->pNext1 = pSave2;
							pTemp->pNext2 = pSave1;
							pTemp->pNext2->pNext1 = pSaveLeft;
							pTemp->pNext2->pNext2 = pSaveRight;

							return 1;
						}
					}
					else
					{
						pTemp->pNext2 = pLink;
						pTemp->pNext2->pNext1 = pSaveLeft;
						return 1;
					}
					pLink = pLink->pNext1;
				}
			}

			if(pTemp->pNext2->iKey == iNumber && pTemp->pNext2->pNext1 != NULL && pTemp->pNext2->pNext2 == NULL)
			{

				pLink = pTemp->pNext2->pNext1;

				while(pLink != NULL)   //�ݺ�
				{
					if(pLink->pNext2 == NULL) //���
					{
						pTemp->pNext2 = pTemp->pNext2->pNext1;
						return 1;
					}
					if(pLink->pNext2->pNext2 == NULL && pLink->pNext2->pNext1 == NULL)
					{
						pSave1 = pLink->pNext2;
						pLink->pNext2 = NULL;
						pSaveLeft = pTemp->pNext2->pNext1;
						pTemp->pNext2 = pSave1;
						pTemp->pNext2->pNext1 = pSaveLeft;
						return 1;
					}
					if(pLink->pNext2->pNext2 == NULL && pLink->pNext2->pNext1 != NULL)
					{
						pSave1 = pLink->pNext2;
						pLink->pNext2 = pLink->pNext2->pNext1;
						pTemp->pNext2 = pSave1;
						pSave1->pNext2 = NULL;
						pSave1->pNext1 = pLink;
						return 1;
					}
					pLink = pLink->pNext2;

				}
				return 1;
			} //����� ������ ����� ���� �������̰� �� ����� ������ ��尡 NULL �� ���

			if(pTemp->pNext2->iKey == iNumber && pTemp->pNext2->pNext1 == NULL && pTemp->pNext2->pNext2 != NULL)
			{
				pLink = pTemp->pNext2->pNext2;
				while(pLink != NULL)
				{
					if(pLink->pNext1 == NULL)
					{
						pTemp->pNext2 = pTemp->pNext2->pNext2;
						return 1;
					}
					if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 == NULL)
					{
						pSave1 = pLink->pNext1;
						pLink->pNext1 = NULL;
						pSaveRight = pTemp->pNext2->pNext2;
						pTemp->pNext2 = pSave1;
						pTemp->pNext2->pNext2 = pSaveRight;
						return 1;
					}
					if(pLink->pNext1->pNext1 == NULL && pLink->pNext1->pNext2 != NULL)
					{
						pSave2 = pLink->pNext1->pNext2;
						pLink->pNext1->pNext2 = NULL;
						pSave1 = pLink->pNext1;
						pLink->pNext1 = pSave2;
						pSaveRight = pTemp->pNext2->pNext2;
						pTemp->pNext2 = pSave1;
						pTemp->pNext2->pNext2 = pSaveRight;    //����**********************************************
						return 1;
					}
					pLink = pLink->pNext1;
				}
				return 1;
			} //����� ������ ����� ���� �������̰� �� ����� ���� ��尡 NULL �� ���

			if(pTemp->pNext2->iKey == iNumber && pTemp->pNext2->pNext1 == NULL && pTemp->pNext2->pNext2 == NULL)
			{
				pTemp->pNext2 = NULL;
				return 1;
			} //����� ������ ����� ���� �����Ͱ� NULL�� ���
		}

		if(pTemp->iKey != iNumber && pTemp->pNext1 == NULL && pTemp->pNext2 == NULL)			//�������� �����Ͱ��� ��ġ���� �������
			return 0;

		//��ȯ
		if(pTemp->iKey > iNumber)
		{
			pTemp = pTemp->pNext1;
		}

		else if(pTemp->iKey < iNumber)
		{
			pTemp = pTemp->pNext2;
		}
	}
	return 0;

}

void Save(node *pLink,FILE *fp)
{	
	int LeftData,RightData;

	if(pLink != NULL) 
	{
		Save(pLink->pNext1,fp);
		Save(pLink->pNext2,fp);

		if(pLink->pNext1 != NULL)
		{
			pLink->LeftByte = pLink->pNext1->ByteData;
		}
		if (pLink->pNext2 != NULL)
		{
			pLink->RightByte = pLink->pNext2->ByteData;
		}
		pLink->ByteData = ftell(fp);

		fwrite(pLink,sizeof(node),1,fp);
	}
}

void Load(node *pLink,FILE *fp)
{
	node *pTemp;
	int total_block;
	int count = 1;
	int LeftNum,RightNum;
	int a = 2;

	fseek(fp,0L,SEEK_END);
	total_block = ftell(fp)/sizeof(node);

	pTemp = (node*)malloc(sizeof(node));

	fseek(fp,-48L,SEEK_END);

	fread(pTemp,sizeof(node),1,fp);

	pHead = pTemp;
	pLink = pTemp;

	inLoad(pLink,fp);
}

void inLoad(node *pLink,FILE *fp)
{
	node *pTemp;
	int LeftNum;
	int RightNum;

	if(pLink != NULL)
	{
		LeftNum = pLink->LeftByte;
		RightNum = pLink->RightByte;

		if(pLink->pNext1 != NULL)
		{
			pTemp = (node*)malloc(sizeof(node));

			fseek(fp,LeftNum,SEEK_SET);
			fread(pTemp,sizeof(node),1,fp);
			pLink->pNext1 = pTemp;
		}

		if(pLink->pNext2 != NULL)
		{
			pTemp = (node*)malloc(sizeof(node));

			fseek(fp,RightNum,SEEK_SET);
			fread(pTemp,sizeof(node),1,fp);
			pLink->pNext2 = pTemp;
		}

		inLoad(pLink->pNext1,fp);
		inLoad(pLink->pNext2,fp);
	}	
}