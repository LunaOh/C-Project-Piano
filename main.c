#include "header.h"

int main(void)
{
	int menu;
	while (1)
	{
		system("title Let's be MUSIC KING");

		PlaySound(TEXT("mu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		system("cls");
		printf("\n\n\n\n\n\n\n--------------------------------------------------------------------------------------------------------------------\n");
		printf("----------------------------------------------절대음감이 되어보자 > <-----------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("                                  ||                                    ||\n");
		printf("                                  || 1번 : 계이름 공부하기              ||\n");
		printf("                                  || 2번 : 절대음감 연습하기            ||\n");
		printf("                                  || 3번 : 나만의 music 만들기          ||\n");
		printf("                                  || 4번 : 이제 우리 그마아아아안하자   ||\n");
		printf("                                  ||                                    ||\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("                                  || 자 얼른 menu를 선택해봐 : ");
		scanf_s("%d%*c", &menu);
		printf("\n\n\n");
		system("cls"); // 콘솔창 초기화

		PlaySound(NULL, 0, 0);
		if (menu == 1)
			piano_menu_1();
		else if (menu == 2)
			piano_menu_2();
		else if (menu == 3)
			piano_menu_3();
		else if (menu == 4)
		{
			printf("이제 우리 그마아아아안하자\n");
			return 0;
		}
		system("cls"); // 콘솔창 초기화
	}
	return 0;
}
