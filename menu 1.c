#include "header.h"

//�޴� 1�� ȭ��
void piano_menu_1(void)
{
	piano_point_menu1(0, 1); // �ǾƳ� �ǹ� �� Ŀ�� ��ġ
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------------���̸� �����ϱ�---------------------------------------------------\n");
	printf("                                  ||                                            ||\n");
	printf("                                  || 1.1~8�� ������ ���̸��� ��������.          ||\n");
	printf("                                  || 2.��Ÿ��� �� �����ð��� ������ �����մϴ�.||\n");
	printf("                                  || 3.�޴��� ���ư��� : R                      ||\n");
	printf("                                  || 4.���α׷� �����ϱ� : X                    ||\n");
	printf("                                  ||                                            ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("                  ||                                                                          ||\n");
	printf("                  || 1 : ���� ��, 2 : ��, 3 : ��, 4 : ��, 5 : ��, 6 : ��, 7 : ��, 8 : ���� �� ||\n");
	printf("                  || Ű�� : �� ��Ÿ�� ����, Ű��: �� ��Ÿ�� �Ʒ���                            ||\n");
	printf("                  || Ű�� : ���� �����ð� ª��, Ű�� : ���� �����ð� ���                     ||\n");
	printf("                  ||                                                                          ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	piano_practice_menu1();
}

// �޴� 1�� 
// �ǾƳ� �� Ŀ�� �̵�
void piano_point_menu1(int x, int y)
{
	COORD Pos = { x , y }; // ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // Ŀ�� �̵�
}


// �޴� 1��
// ��Ÿ��� �� �����ð� ���� ������ �� ��� �Լ� piano_practice_menu1
void piano_practice_menu1(void)
{
	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //���� ���� ����
	int NOTES[8], i;
	char note;
	int octave = 4;
	double time = 500;

	draw_piano_keyboard_menu1(); //�ǾƳ� �ǹ�

	while (1)
	{
		for (i = 0; i < 8; i++) //i�� 0���� 7���� �����ϸ鼭 �ݺ�
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq�迭�� ���ļ��� ����

		note = getch(); // 1~8(���� '��'~���� '��')���� �� code �Է¹���

		if ('1' <= note && note <= '8')
		{
			note -= 49; //�ƽ�Ű �ڵ� ���� �̿�

			touch_keyboard_menu1(note);
			Beep(NOTES[note], time); //�Ҹ� ���
			draw_piano_keyboard_menu1();

		}
		else
			arrow_key_control_menu1(note, &octave, &time);

		piano_point_menu1(1, 20); //��ġ

		printf("\n\n\t\t\t\t���� ��Ÿ��:%d, ", octave);
		printf("���� �����ð�:%.2lf��\n", time / 1000.);


		if (note == 'r' || note == 'R') // note==r Ȥ�� note==R�� ����
		{
			main(); //�޴��� ���ư�

		}
		else if (note == 'x' || note == 'X') // note==x Ȥ�� mote==X�� ���
			exit(0); // ���α׷� ����
	}
}


// �޴� 1��
// �ǾƳ� �ǹ��� �׸��� �Լ� draw_piano_keyboard_menu1
void draw_piano_keyboard_menu1(void)
{
	piano_point_menu1(0, 15);
	printf("\n");
	printf("\t\t\t\t|  |   | |   |  |  |   | |   | |   |  |  | |\n");
	printf("\t\t\t\t|  |   | |   |  |  |   | |   | |   |  |  | |\n");
	printf("\t\t\t\t|  |___| |___|  |  |___| |___| |___|  |  |_|\n");
	printf("\t\t\t\t| �� |  �� | �� | �� | ��  |  �� | �� | �� |\n");
	printf("\t\t\t\t|    |     |    |    |     |     |    |    |\n");
	printf("\t\t\t\t|____|_____|____|____|_____|_____|____|____|\n");

}


//�޴� 1��
//���� Ű�� ������ �ش� �ǹݿ� ���� ����ϴ� �Լ� touch_keyboard_menu1
void touch_keyboard_menu1(int note)
{
	piano_point_menu1(36 + note * 5, 20); // ��ġ, x���� �ű�

	printf("%c%c", 0xa1, 0xe3); //���� ���
}


// �޴� 1��
//ȭ��ǥ Ű�� ��Ÿ��� ���� �����ð��� �����ϴ� �Լ� arrow_key_control_menu1
void arrow_key_control_menu1(int note, int* octave, double* time)
{
	switch (note)
	{
	case 72: //���� ȭ��ǥ //��Ÿ�� ����

		*octave += 1;

		if (8 < *octave)
			*octave = 8;

		break;

	case 75: //���� ȭ��ǥ //�����ð� ����

		*time -= 250;

		if (*time < 250)
			* time = 250;

		break;

	case 77: //������ ȭ��ǥ //�����ð� ����

		*time += 250;

		if (1000 < *time)
			* time = 1000;

		break;

	case 80: //�Ʒ��� ȭ��ǥ //��Ÿ�� ����

		*octave -= 1;

		if (*octave <= 1)
			* octave = 1;

		break;

	default:

		break;
	}
}

