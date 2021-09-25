#include "header.h"

//메뉴 1번 화면
void piano_menu_1(void)
{
	piano_point_menu1(0, 1); // 피아노 건반 위 커서 위치
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------------계이름 공부하기---------------------------------------------------\n");
	printf("                                  ||                                            ||\n");
	printf("                                  || 1.1~8을 누르며 계이름을 익히세요.          ||\n");
	printf("                                  || 2.옥타브와 음 지연시간을 조절이 가능합니다.||\n");
	printf("                                  || 3.메뉴로 돌아가기 : R                      ||\n");
	printf("                                  || 4.프로그램 종료하기 : X                    ||\n");
	printf("                                  ||                                            ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("                  ||                                                                          ||\n");
	printf("                  || 1 : 낮은 도, 2 : 레, 3 : 미, 4 : 파, 5 : 솔, 6 : 라, 7 : 시, 8 : 높은 도 ||\n");
	printf("                  || 키↑ : 한 옥타브 위로, 키↓: 한 옥타브 아래로                            ||\n");
	printf("                  || 키← : 음의 지연시간 짧게, 키→ : 음의 지연시간 길게                     ||\n");
	printf("                  ||                                                                          ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	piano_practice_menu1();
}

// 메뉴 1번 
// 피아노 위 커서 이동
void piano_point_menu1(int x, int y)
{
	COORD Pos = { x , y }; // 좌표 저장
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // 커서 이동
}


// 메뉴 1번
// 옥타브와 음 지연시간 제어 가능한 음 출력 함수 piano_practice_menu1
void piano_practice_menu1(void)
{
	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //음계 지정 숫자
	int NOTES[8], i;
	char note;
	int octave = 4;
	double time = 500;

	draw_piano_keyboard_menu1(); //피아노 건반

	while (1)
	{
		for (i = 0; i < 8; i++) //i가 0부터 7까지 증가하면서 반복
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq배열에 주파수값 저장

		note = getch(); // 1~8(낮은 '도'~높은 '도')까지 중 code 입력받음

		if ('1' <= note && note <= '8')
		{
			note -= 49; //아스키 코드 값을 이용

			touch_keyboard_menu1(note);
			Beep(NOTES[note], time); //소리 출력
			draw_piano_keyboard_menu1();

		}
		else
			arrow_key_control_menu1(note, &octave, &time);

		piano_point_menu1(1, 20); //위치

		printf("\n\n\t\t\t\t현재 옥타브:%d, ", octave);
		printf("현재 지연시간:%.2lf초\n", time / 1000.);


		if (note == 'r' || note == 'R') // note==r 혹은 note==R인 경후
		{
			main(); //메뉴로 돌아감

		}
		else if (note == 'x' || note == 'X') // note==x 혹은 mote==X인 경우
			exit(0); // 프로그램 종료
	}
}


// 메뉴 1번
// 피아노 건반을 그리는 함수 draw_piano_keyboard_menu1
void draw_piano_keyboard_menu1(void)
{
	piano_point_menu1(0, 15);
	printf("\n");
	printf("\t\t\t\t|  |   | |   |  |  |   | |   | |   |  |  | |\n");
	printf("\t\t\t\t|  |   | |   |  |  |   | |   | |   |  |  | |\n");
	printf("\t\t\t\t|  |___| |___|  |  |___| |___| |___|  |  |_|\n");
	printf("\t\t\t\t| 도 |  레 | 미 | 파 | 솔  |  라 | 시 | 도 |\n");
	printf("\t\t\t\t|    |     |    |    |     |     |    |    |\n");
	printf("\t\t\t\t|____|_____|____|____|_____|_____|____|____|\n");

}


//메뉴 1번
//숫자 키를 누르면 해당 건반에 ▲을 출력하는 함수 touch_keyboard_menu1
void touch_keyboard_menu1(int note)
{
	piano_point_menu1(36 + note * 5, 20); // 위치, x값만 옮김

	printf("%c%c", 0xa1, 0xe3); //▲을 출력
}


// 메뉴 1번
//화살표 키로 옥타브와 음의 지연시간을 제어하는 함수 arrow_key_control_menu1
void arrow_key_control_menu1(int note, int* octave, double* time)
{
	switch (note)
	{
	case 72: //위쪽 화살표 //옥타브 증가

		*octave += 1;

		if (8 < *octave)
			*octave = 8;

		break;

	case 75: //왼쪽 화살표 //지연시간 감소

		*time -= 250;

		if (*time < 250)
			* time = 250;

		break;

	case 77: //오른쪽 화살표 //지연시간 증가

		*time += 250;

		if (1000 < *time)
			* time = 1000;

		break;

	case 80: //아래쪽 화살표 //옥타브 감소

		*octave -= 1;

		if (*octave <= 1)
			* octave = 1;

		break;

	default:

		break;
	}
}

