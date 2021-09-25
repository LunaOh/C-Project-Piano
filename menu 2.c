#include "header.h"

// �޴� 2�� ȭ��
void piano_menu_2(void)
{
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------------�������� �����ϱ�--------------------------------------------------\n");
	printf("                              ||                                                  ||\n");
	printf("                              || 1. 9�� ������ �������� �Ҹ��� ����.              ||\n");
	printf("                              || 2. �鸮�� �Ҹ��� ���, �ش� ���� ��ȣ�� ��������.||\n");
	printf("                              || 3. �������� �������� ���ɴϴ�.                   ||\n");
	printf("                              || 4. ������ �ٽ� �ѹ� ���� !                       ||\n");
	printf("                              || 5. �޴��� ���ư��� : R                           ||\n");
	printf("                              || 6. ���α׷� �����ϱ� : X                         ||\n");
	printf("                              ||                                                  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("                  ||                                                                          ||\n");
	printf("                  || 1 : ���� ��, 2 : ��, 3 : ��, 4 : ��, 5 : ��, 6 : ��, 7 : ��, 8 : ���� �� ||\n");
	printf("                  ||                                                                          ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------------------START--------------------------------------------------------\n");
	guess_code_menu2();
}

// �޴� 2��
// ������ ���� ����ϴ� �Լ� guess_code_menu2
void guess_code_menu2(void)
{
	int CODES[] = { 0,2,4,5,7,9,11,12 };
	int NOTES[8], note;

	srand((unsigned int)time(NULL));
	char answer; // ����ڰ� ���ϴ� �� 
	while (1)
	{
		for (int i = 0; i < 8; i++) // i�� 0���� 7���� �����ϸ鼭 �ݺ�
			NOTES[i] = calc_frequency(4, CODES[i]); // NOTES�迭�� ���ļ��� ����

		answer = getch();

		if (answer == 'r' || answer == 'R') // R Ȥ�� r�� �Է��� ���
		{
			main(); // �޴��� ���ư���

		}
		else if (answer == 'x' || answer == 'X') // X Ȥ�� x�� �Է��� ���
			exit(0); // ���α׷� ����


		else if (answer == '9')  // 9�� �Է��� ���
		{
			note = rand() % 8;   // note�� 1~8 ������ ���� -> ����
			//if ('1' <= code && code <= '8') // �Է¹��� code�� '1'���� '8'�����϶�
			answer_guess_code_menu2(note, NOTES);

		}
	}
}

// �޴� 2��
// ������ ���踦 ������ �Լ� answer_guess_code_menu2
void answer_guess_code_menu2(int note, int *pNOTES)
{
	char sound;
	while (1)
	{
		Beep(pNOTES[note], 500); // Beep(���� ����, ���� ���ӽð�) -> �Ҹ� ��� �Լ�
					 // Beep(frequency, length), frequency�� ���ļ�(�������� ���� ��), length�� 1/1000�� ����

		printf("\n��� �鸰 ���� �����ϱ�� ?? : ");
		sound = getch();
		printf("%c", sound);

		if (sound >= 49 && sound <= 56)
		{
			if (sound - 49 == note) // sound-49 == note�� ���
			{
				printf("\n----> �����Դϴ� ~~~~~!\n");
				printf("----> �� ���� ���߷� ������ ~~\n");
				break; // �Լ� ����
			}
			else // sound-49 != note�� ���
			{
				printf("\n----> ���� �Ѥ� ���� !! \n");
				printf("----> �ٽ� �ѹ� ���� !!\n");
				continue; // �Ҹ��� �ٽ� ����ְ� ���� ������ �ݺ�
			}
		}
		else if (sound == 'R' || sound == 'r')
		{
			printf("\n�޴��� ���ư��ϴ�.\n");
			main();
		}
		else if (sound == 'X' || sound == 'x')
		{
			printf("\n���α׷� ����\n");
			exit(0);
		}
		else
			printf("\n----> 1~8������ �Է��� ��,,�� \n");
	}
}