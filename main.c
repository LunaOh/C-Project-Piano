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
		printf("----------------------------------------------���������� �Ǿ�� > <-----------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("                                  ||                                    ||\n");
		printf("                                  || 1�� : ���̸� �����ϱ�              ||\n");
		printf("                                  || 2�� : �������� �����ϱ�            ||\n");
		printf("                                  || 3�� : ������ music �����          ||\n");
		printf("                                  || 4�� : ���� �츮 �׸��ƾƾƾ�����   ||\n");
		printf("                                  ||                                    ||\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("                                  || �� �� menu�� �����غ� : ");
		scanf_s("%d%*c", &menu);
		printf("\n\n\n");
		system("cls"); // �ܼ�â �ʱ�ȭ

		PlaySound(NULL, 0, 0);
		if (menu == 1)
			piano_menu_1();
		else if (menu == 2)
			piano_menu_2();
		else if (menu == 3)
			piano_menu_3();
		else if (menu == 4)
		{
			printf("���� �츮 �׸��ƾƾƾ�����\n");
			return 0;
		}
		system("cls"); // �ܼ�â �ʱ�ȭ
	}
	return 0;
}
