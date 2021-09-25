#include "header.h"

// �޴� 3�� ȭ��
void piano_menu_3(void)
{
	int end;
	char answer;
	char answer2;

	printf("\n\n\n\n\n\n");
	while (1)
	{
		for (int i = 0; i < MAX; i++)
			notes[i] = '\0'; // �迭 notes�� ��� ������ '\0'���� �ʱ�ȭ


		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------------------------------������ ���� �����-------------------------------------------------\n");
		printf("                             ||                                                     ||\n");
		printf("                             || 1.START�� 1~8�� ���� ������ �ϼ��ϼ���.             ||\n");
		printf("                             || 2.ȭ��ǥ�� �̿��Ͽ� ��Ÿ��� �����ð��� �����ϼ���  ||\n");
		printf("                             ||   ��:+1��Ÿ�� ��:-1��Ÿ�� ��:+0.25�� ��:-0.25��     ||\n");
		printf("                             ||    1<= ��Ÿ�� <=8    /    0.25<= �����ð� <=1.00    ||\n");
		printf("                             || 3.���� �ϼ� �� ����Ű�� ��������.                   ||\n");
		printf("                             ||                                                     ||\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------------------------------------START--------------------------------------------------------\n");

		record_menu3(notes); // ����ڰ� �Է��� �� ����
		printf("\n");

		printf("--------------------------------------------------------END---------------------------------------------------------\n");

		replay_menu3(notes); // ����ڰ� ������ �� ���
		printf("\n");

		printf("------------------------------------------------------END PLAY------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");

		printf("                                      || �ٽ� �����Ͻðڽ��ϱ�?(Y/N) : ");
		rewind(stdin);
		scanf_s("%c%*c", &answer, 1);


		if (answer == 'N' || answer == 'n') //answer=n Ȥ�� answer=N�̸� 
		{
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("                                    || R. �޴��� ���ư���                      ||\n");
			printf("                                    || X. ���α׷� �����ϱ�                    ||\n");
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("                                    || answer(R/X) : ");
			scanf_s("%c", &answer2, sizeof(answer2));

			if (answer2 == 'r' || answer2 == 'R') //answer2=r Ȥ�� answer2=R�� ���
				main(); // �޴��� ���ư�
			else if (answer2 == 'x' || answer2 == 'X') //answer2=x Ȥ�� answer2=X�� ���
				exit(0); // ���α׷� ����
		}
	}
}


// �޴� 3�� 
// ���� �Լ� record_menu3
// ����ڰ� �Է��� �� ����
void record_menu3(char* notes)
{
	int size = 0; //����ڰ� �Է��� ���� ����
	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //���� ���� ����
	int NOTES[8];
	int octave = 4;
	double time = 500;

	while (1)
	{
		char user_code; //�Է¹��� Ű

		user_code = getch(); //�Է¹ޱ�
		notes[size] = user_code; //�迭����-�Է¹����� ����

		for (int i = 0; i < 8; i++)
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq�迭�� ���� ����


		if (user_code == '1')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '2')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '3')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '4')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '5')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '6')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '7')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("�� ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '8')
		{
			user_code -= 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[user_code], time);
			printf("��+ ");
			printf("��Ÿ��: %d / �����ð�: %.2lf��", octave, time / 1000);
			printf("\n");
		}


		else
		{
			arrow_key_control_menu3(user_code, &octave, &time); //��Ÿ��� ���� ���� �ð� ����
			printf("\n");
		}


		size++; //����ڰ� �Է��� ������ 1�� ����



		if (user_code == 13) // �Է¹��� Ű�� �ƽ�Ű���� 13�� ��� = ���͸� �Է��� ���
		{
			printf("\n"); //�� ���
			return;// �Է� ����
		}

	}
}

// �޴� 3��
// ��� �Լ� replay_menu3
// ����ڰ� ������ �� ���
void replay_menu3(char* notes)
{

	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //���� ���� ����
	int NOTES[8];
	int octave = 4;
	double time = 500;
	int temp = 0;


	for (int i = 0; i < MAX; i++)
	{


		for (int i = 0; i < 8; i++)
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq�迭�� ���� ����


		if (notes[i] == '1')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '2')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '3')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '4')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '5')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '6')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '7')
		{
			temp = notes[i] - 49; //�ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��");
		}
		else if (notes[i] == '8')
		{
			temp = notes[i] - 49; // �ƽ�Ű�ڵ� �̿�
			Beep(NOTES[temp], time);
			printf("��+");
		}


		else // 1~8�� ���� �ƴ� ���
		{
			arrow_key_control_menu3(notes[i], &octave, &time); // ��Ÿ��� ���� ���� �ð� ����
		}

		if (notes[i] == '\0') // �迭�� NULL���ڸ� = �� �̻� ������ ���� ������
		{
			printf("\n"); // �� ���
			return; // ��� ����
		}


	}
}


// �޴� 3��
// ȭ��ǥ Ű�� ��Ÿ��� �����ð��� �����ϴ� �Լ� arrow_key_control_menu3
void arrow_key_control_menu3(int note, int* octave, double* time)
{
	switch (note)
	{
	case 72: //���� ȭ��ǥ //��Ÿ�� ����

		*octave += 1;
		printf("��");

		if (8 < *octave)
			*octave = 8;

		break;

	case 75: //���� ȭ��ǥ //�����ð� ����

		*time -= 250;
		printf("��");

		if (*time < 250)
			* time = 250;

		break;

	case 77: //������ ȭ��ǥ //�����ð� ����

		*time += 250;
		printf("��");

		if (1000 < *time)
			* time = 1000;

		break;

	case 80: //�Ʒ��� ȭ��ǥ //��Ÿ�� ����

		*octave -= 1;
		printf("��");

		if (*octave <= 1)
			*octave = 1;

		break;

	default:

		break;
	}
}
