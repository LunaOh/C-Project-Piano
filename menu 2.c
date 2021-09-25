#include "header.h"

// 메뉴 2번 화면
void piano_menu_2(void)
{
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------------절대음감 연습하기--------------------------------------------------\n");
	printf("                              ||                                                  ||\n");
	printf("                              || 1. 9를 누르면 랜덤으로 소리가 나요.              ||\n");
	printf("                              || 2. 들리는 소리를 듣고, 해당 음의 번호를 누르세요.||\n");
	printf("                              || 3. 정답인지 오답인지 나옵니다.                   ||\n");
	printf("                              || 4. 오답은 다시 한번 도전 !                       ||\n");
	printf("                              || 5. 메뉴로 돌아가기 : R                           ||\n");
	printf("                              || 6. 프로그램 종료하기 : X                         ||\n");
	printf("                              ||                                                  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("                  ||                                                                          ||\n");
	printf("                  || 1 : 낮은 도, 2 : 레, 3 : 미, 4 : 파, 5 : 솔, 6 : 라, 7 : 시, 8 : 높은 도 ||\n");
	printf("                  ||                                                                          ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------------------START--------------------------------------------------------\n");
	guess_code_menu2();
}

// 메뉴 2번
// 임의의 음을 출력하는 함수 guess_code_menu2
void guess_code_menu2(void)
{
	int CODES[] = { 0,2,4,5,7,9,11,12 };
	int NOTES[8], note;

	srand((unsigned int)time(NULL));
	char answer; // 사용자가 원하는 것 
	while (1)
	{
		for (int i = 0; i < 8; i++) // i가 0부터 7까지 증가하면서 반복
			NOTES[i] = calc_frequency(4, CODES[i]); // NOTES배열에 주파수값 저장

		answer = getch();

		if (answer == 'r' || answer == 'R') // R 혹은 r을 입력한 경우
		{
			main(); // 메뉴로 돌아가기

		}
		else if (answer == 'x' || answer == 'X') // X 혹은 x를 입력한 경우
			exit(0); // 프로그램 종료


		else if (answer == '9')  // 9를 입력한 경우
		{
			note = rand() % 8;   // note는 1~8 임의의 난수 -> 음계
			//if ('1' <= code && code <= '8') // 입력받은 code가 '1'부터 '8'까지일때
			answer_guess_code_menu2(note, NOTES);

		}
	}
}

// 메뉴 2번
// 임의의 음계를 맞히는 함수 answer_guess_code_menu2
void answer_guess_code_menu2(int note, int *pNOTES)
{
	char sound;
	while (1)
	{
		Beep(pNOTES[note], 500); // Beep(음의 높이, 음의 지속시간) -> 소리 출력 함수
					 // Beep(frequency, length), frequency는 주파수(높을수록 높은 음), length는 1/1000초 단위

		printf("\n방금 들린 음은 무엇일까용 ?? : ");
		sound = getch();
		printf("%c", sound);

		if (sound >= 49 && sound <= 56)
		{
			if (sound - 49 == note) // sound-49 == note인 경우
			{
				printf("\n----> 정답입니당 ~~~~~!\n");
				printf("----> 또 정답 맞추러 고고링 ~~\n");
				break; // 함수 종료
			}
			else // sound-49 != note인 경우
			{
				printf("\n----> 삐익 ㅡㅡ 오답 !! \n");
				printf("----> 다시 한번 들어봐 !!\n");
				continue; // 소리를 다시 들려주고 맞힐 때까지 반복
			}
		}
		else if (sound == 'R' || sound == 'r')
		{
			printf("\n메뉴로 돌아갑니다.\n");
			main();
		}
		else if (sound == 'X' || sound == 'x')
		{
			printf("\n프로그램 종료\n");
			exit(0);
		}
		else
			printf("\n----> 1~8까지만 입력해 ㅡ,,ㅡ \n");
	}
}