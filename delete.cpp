#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100000000  // 제한 가격표 

typedef struct node                                           
{
	char iData[10];  //상대팀명
	int MyScore;
	int YouScore;
	int iKey;  // 날짜(월)
	int ByteData;
	int LeftByte;
	int RightByte;
	int DataPoint;
	struct node *pNext1,*pNext2;				//노드 방향
}node;

void Start();									//시작함수
int Insert(int iNumber, char [], int, int);						//삽입함수
void SizeOutput(node *pLink);			//크기순 출력 함수
void FirstOutput(node *pLink);			//전위 순회 함수
void FinalOutput(node *pLink);			//후위 순회 함수
int Search(int iNumber);						//검색함수
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
	char Data[10];  // 데이터
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
		printf("┌─────────────────┐\n");
		cur.X = 40;
		cur.Y = 3; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("│ 날짜 입력시                      │\n");
		cur.X = 40;
		cur.Y = 4; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("│ ex) 2011년 01월 01일             │\n");
		cur.X = 40;
		cur.Y = 5; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("│    -> 20110101                   │\n");
		cur.X = 40;
		cur.Y = 6; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("├─────────────────┤");
		cur.X = 40;
		cur.Y = 7; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("│ 총 전적 : %d 승 %d 무 %d 패         │",winCount, samsamCount, loseCount);
		cur.X = 40;
		cur.Y = 8; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		printf("└─────────────────┘\n");

		cur.X = 0;
		cur.Y = 1; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

		printf("┌─────────────┐\n");
		printf("│팀명 : 장원진             │\n");
		printf("├─────────────┤\n");
		printf("│1. 경기 결과 기록         │\n");
		printf("│2. 기록 보기              │\n");
		printf("│3. 경기 결과 검색         │\n");
		printf("│4. 경기 결과 삭제         │\n");
		printf("│5. 경기 결과 파일에 저장  │\n");
		printf("│6. 로 드                  │\n");
		printf("│0. 종 료                  │\n");
		printf("└─────────────┘\n");
		printf("입력 >> ");
		scanf("%d",&iNum);
		fflush(stdin);

		if(0 <= iNum && 10 >= iNum)
		{
			switch(iNum)
			{
			case 1:														//삽입 함수(case)
				printf("\n\n경기 결과 기록\n\n");
				printf("날짜 입력 : ");
				scanf("%d",&iInsertNum);								//삽입 할 값 삽입
				fflush(stdin);

				printf("상대팀명 입력 : ");
				scanf("%s",Data);
				fflush(stdin);

				printf("나의 팀 스코어 입력 : ");
				scanf("%d",&myScore);
				printf("상대 팀 스코어 입력 : ");
				scanf("%d",&youScore);
				fflush(stdin);

				if(0 < iInsertNum && MAX >= iInsertNum)
				{
					StartInsert = Insert(iInsertNum, Data, myScore, youScore);	

					if(StartInsert == 1)
					{
						printf("\n\n삽입 성공");
						winCount++;
					}
					else if(StartInsert == 2)
					{
						printf("\n\n삽입 성공");
						loseCount++;
					}
					else if(StartInsert == 3)
					{
						printf("\n\n삽입 성공");
						samsamCount++;
					}
					else
						printf("\n\n날짜 기록 실패");
					pLink = pHead;
				}

				else
				{
					printf("기록 실패");
				}
				printf("\n\n\n");
				break;			

			case 2:														//출력 함수(case)
				printf("\n\n기록 보기\n\n");
				printf("1. 날짜순 출력  2. 전위순회 3. 후위순회\n");
				printf("입력 >> ");
				scanf("%d",&iOutputNum);
				fflush(stdin);

				if(0 < iOutputNum && 4 > iOutputNum)
				{
					int y = 21;
					switch(iOutputNum)
					{
					case 1:
						SizeOutput(pLink);			//크기순
						break;
					case 2:
						FirstOutput(pLink);			//전위
						break;

					case 3:
						FinalOutput(pLink);			//후위
						break;

					default :
						printf("\n\n잘못 입력\n\n");
					}

					pLink = pHead;
				}

				else
				{
					printf("잘못 입력 하였습니다.");
				}

				printf("\n\n\n");
				break;

			case 3:
				//검색 함수(case)
				printf("\n\n검 색\n\n");
				printf("검색할 날짜 입력 : ");
				scanf("%d",&iSearchNum);								//검색 할 값 삽입
				fflush(stdin);

				if(0 < iSearchNum && MAX >= iSearchNum)
				{
					StartSearch = Search(iSearchNum);

					if(StartSearch != 0)
					{
						printf("\n\n검색 성공\n\n");
					}
					else
						printf("\n\n검색 실패\n\n\n");
				}

				else
					printf("잘못입력 하였습니다.\n\n\n");

				break;

			case 4:														//삭제 함수(case)
				printf("\n\n삭 제\n\n");
				printf("\n===========================================================================\n\n");
				SizeOutput(pLink);
				printf("\n===========================================================================\n");
				printf("삭제할 날짜 입력 : ");
				scanf("%d",&iDeleteNum);								//삭제 할 값 삽입
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
				printf("\n\n저 장\n\n저 장 성 공\n");
				FILE *fp;
				fp = fopen("Save.bin","wb");
				Save(pLink,fp);
				fclose(fp);
				printf("\n\n");
				break;

			case 6:
				printf("\n\n로 드\n\n");

				fp = fopen("Save.bin","rb");
				if(fp == NULL)
				{
					printf("파일을 찾을수 없습니다.");
					return;
				}

				Load(pLink,fp);

				pLink = pHead;

				printf("\n\n");
				break;

			case 0:														//종료
				printf("\n\n종 료\n\n\n");
				exit(0);

			default:													//다른값
				printf("\n\n다시 입력하시오.\n\n\n");
			}
		}
		else
			printf("\n\n다시 입력하시오.\n\n\n");
		printf("Enter 입력하시오.");
		getchar();
	}

}
//승 1, 패 2, 무 3
int Insert(int iNumber, char Data[], int myScore, int youScore)			//삽입함수
{
	node *pTemp;
	int DataNum;

	if(iNumber < 0)			// 노드의 데이터 '-' 값 방지
		return 0;

	if(iNumber == 0)
		return 0;


	if(pHead == NULL)			//pHead 값 NULL일 경우(첫번째 삽입 할 경우)
	{
		pHead = (struct node*)malloc(sizeof(struct node));
		pLink = (struct node*)malloc(sizeof(struct node));

		pHead->iKey = iNumber;
		strcpy(pHead->iData, Data);
		pHead->MyScore = myScore;
		pHead->YouScore = youScore;
		//pHead->iData = Data;

		pLink = pHead;			//pLink 에 pHead 저장

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

	while(pHead != NULL)			//무한루프
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
			pLink = pHead;			//pLink값 첫 노드로 이동(pHead 지정)

			if(myScore > youScore)
				return 1;
			else if(myScore < youScore)
				return 2;
			else
				return 3;
		}
		else if(iNumber > pLink->iKey)			//데이터의 값이 삽입값보다 작은경우
		{
			if(pLink->pNext2 == NULL)
			{		
				pTemp = (struct node*)malloc(sizeof(struct node));
				pTemp->iKey = iNumber;
				strcpy(pTemp->iData, Data);
				pTemp->MyScore = myScore;
				pTemp->YouScore = youScore;
				//pTemp->iData = Data;

				pLink->pNext2 = pTemp;			//pLink의 오른쪽(pNext2)이 pTemp를 가리킴 

				pTemp->pNext1 = NULL;
				pTemp->pNext2 = NULL;
				pLink = pHead;			//pLink값 첫 노드로 이동

				if(myScore > youScore)
					return 1;
				else if(myScore < youScore)
					return 2;
				else
					return 3;
			}
			else								//테이터의 값이 삽입값보다 작은경우
				pLink = pLink->pNext2;			//오른쪽의 노드로 이동
		}

		else if(iNumber < pLink->iKey)			//데이터의 값이 삽입값보다 클경우
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
				pLink = pHead;			//pLink값 첫 노드로 이동(pHead 지정)

				if(myScore > youScore)
					return 1;
				else if(myScore < youScore)
					return 2;
				else
					return 3;
			}
			else								//데이터의 값이 삽입값보다 클경우
				pLink = pLink->pNext1;			//왼쪽의 노드로 이동
		}
	}
}

void SizeOutput(node *pLink)			//값의 크기 순서대로 출력(재귀함수 활용)
{
	COORD cur;
	if(pLink != NULL)
	{
		SizeOutput(pLink->pNext1);
		printf("날짜 : %d,  상대팀명 : %s,  나의스코어 : %d,  상대스코어 : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
		SizeOutput(pLink->pNext2);
	}
}

void FirstOutput(node *pLink)			//전위순회(재귀함수 활용)
{
	if(pLink != NULL)    // 전위순환
	{
		printf("날짜 : %d,  상대팀명 : %s,  나의스코어 : %d,  상대스코어 : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
		FirstOutput(pLink->pNext1);
		FirstOutput(pLink->pNext2);
	}
}

void FinalOutput(node *pLink)			//후위순회(재귀함수 활용)
{
	if(pLink != NULL)    
	{
		FinalOutput(pLink->pNext1);
		FinalOutput(pLink->pNext2);
		printf("날짜 : %d,  상대팀명 : %s,  나의스코어 : %d,  상대스코어 : %d\n",pLink->iKey, pLink->iData, pLink->MyScore, pLink->YouScore);
	}
}

int Search(int iNumber)			//검색 함수
{
	if(pHead == NULL)			//아직 값이 삽입되지 않을 경우(pHead값이 NULL일 경우)
		return 0;

	while(pLink != NULL)			//무한루프
	{
		if(iNumber == pLink->iKey)			//데이터값과 검색값이 같을경우
		{
			printf("날짜 : %d\n",pLink->iKey);
			printf("상대팀명 : %s\n",pLink->iData);
			printf("나의 스코어 : %d\n",pLink->MyScore);
			printf("상대팀 스코어 : %d\n",pLink->YouScore);
			pLink = pHead;					//
			return iNumber;					//검색값 리턴
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

int Deletion(int iNumber)			//삭제 함수
{
	node *pSave1,*pSave2,*pSaveLeft,*pSaveRight,*pTemp,*pEnd;

	if(pHead == NULL)			//아직 값이 삽입되지 않을 경우(pHead값이 NULL일 경우)
		return 0;

	if(pHead->iKey == iNumber)			//삭제값과 첫노드(pHead의 데이터값)값이 같을경우의 처리과정
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
			{ // 양쪽노드가 NULL 이 아닌경우

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
			} //노드의 왼쪽 노드의 값이 삭제값이고 그 노드의 오른쪽 노드가 NULL 일 경우


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
			} //노드의 왼쪽 노드의 값이 삭제값이고 그 노드의 왼쪽 노드가 NULL 일 경우


			if(pTemp->pNext1->iKey == iNumber && pTemp->pNext1->pNext1 == NULL && pTemp->pNext1->pNext2 == NULL)
			{
				pTemp->pNext1 = NULL;
				return 1;
			} //노드의 왼쪽 노드의 양쪽 포인터가 NULL일 경우
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

				while(pLink != NULL)   //반복
				{
					if(pLink->pNext2 == NULL) //통과
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
			} //노드의 오른쪽 노드의 값이 삭제값이고 그 노드의 오른쪽 노드가 NULL 일 경우

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
						pTemp->pNext2->pNext2 = pSaveRight;    //에러**********************************************
						return 1;
					}
					pLink = pLink->pNext1;
				}
				return 1;
			} //노드의 오른쪽 노드의 값이 삭제값이고 그 노드의 왼쪽 노드가 NULL 일 경우

			if(pTemp->pNext2->iKey == iNumber && pTemp->pNext2->pNext1 == NULL && pTemp->pNext2->pNext2 == NULL)
			{
				pTemp->pNext2 = NULL;
				return 1;
			} //노드의 오른쪽 노드의 양쪽 포인터가 NULL일 경우
		}

		if(pTemp->iKey != iNumber && pTemp->pNext1 == NULL && pTemp->pNext2 == NULL)			//삭제값과 데이터값이 일치하지 않을경우
			return 0;

		//순환
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