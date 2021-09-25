#include "header.h"

// 메뉴 3번 화면
void piano_menu_3(void)
{
	int end;
	char answer;
	char answer2;

	printf("\n\n\n\n\n\n");
	while (1)
	{
		for (int i = 0; i < MAX; i++)
			notes[i] = '\0'; // 배열 notes의 모든 구성을 '\0'으로 초기화


		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------------------------------나만의 음악 만들기-------------------------------------------------\n");
		printf("                             ||                                                     ||\n");
		printf("                             || 1.START후 1~8을 눌러 음악을 완성하세요.             ||\n");
		printf("                             || 2.화살표를 이용하여 옥타브와 지연시간을 조절하세요  ||\n");
		printf("                             ||   ↑:+1옥타브 ↓:-1옥타브 →:+0.25초 ←:-0.25초     ||\n");
		printf("                             ||    1<= 옥타브 <=8    /    0.25<= 지연시간 <=1.00    ||\n");
		printf("                             || 3.음악 완성 시 엔터키를 누르세요.                   ||\n");
		printf("                             ||                                                     ||\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------------------------------------START--------------------------------------------------------\n");

		record_menu3(notes); // 사용자가 입력한 음 녹음
		printf("\n");

		printf("--------------------------------------------------------END---------------------------------------------------------\n");

		replay_menu3(notes); // 사용자가 녹음한 음 재생
		printf("\n");

		printf("------------------------------------------------------END PLAY------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");

		printf("                                      || 다시 녹음하시겠습니까?(Y/N) : ");
		rewind(stdin);
		scanf_s("%c%*c", &answer, 1);


		if (answer == 'N' || answer == 'n') //answer=n 혹은 answer=N이면 
		{
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("                                    || R. 메뉴로 돌아가기                      ||\n");
			printf("                                    || X. 프로그램 종료하기                    ||\n");
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("                                    || answer(R/X) : ");
			scanf_s("%c", &answer2, sizeof(answer2));

			if (answer2 == 'r' || answer2 == 'R') //answer2=r 혹은 answer2=R인 경우
				main(); // 메뉴로 돌아감
			else if (answer2 == 'x' || answer2 == 'X') //answer2=x 혹은 answer2=X인 경우
				exit(0); // 프로그램 종료
		}
	}
}


// 메뉴 3번 
// 녹음 함수 record_menu3
// 사용자가 입력한 음 저장
void record_menu3(char* notes)
{
	int size = 0; //사용자가 입력한 값의 개수
	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //음계 지정 숫자
	int NOTES[8];
	int octave = 4;
	double time = 500;

	while (1)
	{
		char user_code; //입력받을 키

		user_code = getch(); //입력받기
		notes[size] = user_code; //배열선언-입력받은거 나열

		for (int i = 0; i < 8; i++)
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq배열에 음계 저장


		if (user_code == '1')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("도 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '2')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("레 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '3')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("미 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '4')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("파 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '5')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("솔 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '6')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("라 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '7')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("시 ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}
		else if (user_code == '8')
		{
			user_code -= 49; //아스키코드 이용
			Beep(NOTES[user_code], time);
			printf("도+ ");
			printf("옥타브: %d / 지연시간: %.2lf초", octave, time / 1000);
			printf("\n");
		}


		else
		{
			arrow_key_control_menu3(user_code, &octave, &time); //옥타브와 음계 지연 시간 조절
			printf("\n");
		}


		size++; //사용자가 입력한 개수가 1씩 증가



		if (user_code == 13) // 입력받은 키의 아스키값이 13인 경우 = 엔터를 입력한 경우
		{
			printf("\n"); //줄 띄움
			return;// 입력 종료
		}

	}
}

// 메뉴 3번
// 재생 함수 replay_menu3
// 사용자가 녹음한 음 재생
void replay_menu3(char* notes)
{

	int CODES[] = { 0, 2, 4, 5, 7, 9, 11, 12 }; //음계 지정 숫자
	int NOTES[8];
	int octave = 4;
	double time = 500;
	int temp = 0;


	for (int i = 0; i < MAX; i++)
	{


		for (int i = 0; i < 8; i++)
			NOTES[i] = calc_frequency(octave, CODES[i]); //freq배열에 음계 저장


		if (notes[i] == '1')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("도");
		}
		else if (notes[i] == '2')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("레");
		}
		else if (notes[i] == '3')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("미");
		}
		else if (notes[i] == '4')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("파");
		}
		else if (notes[i] == '5')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("솔");
		}
		else if (notes[i] == '6')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("라");
		}
		else if (notes[i] == '7')
		{
			temp = notes[i] - 49; //아스키코드 이용
			Beep(NOTES[temp], time);
			printf("시");
		}
		else if (notes[i] == '8')
		{
			temp = notes[i] - 49; // 아스키코드 이용
			Beep(NOTES[temp], time);
			printf("도+");
		}


		else // 1~8의 값이 아닌 경우
		{
			arrow_key_control_menu3(notes[i], &octave, &time); // 옥타브와 음계 지연 시간 조절
		}

		if (notes[i] == '\0') // 배열이 NULL문자면 = 더 이상 녹음된 음이 없으면
		{
			printf("\n"); // 줄 띄움
			return; // 재생 종료
		}


	}
}


// 메뉴 3번
// 화살표 키로 옥타브와 지연시간을 조절하는 함수 arrow_key_control_menu3
void arrow_key_control_menu3(int note, int* octave, double* time)
{
	switch (note)
	{
	case 72: //위쪽 화살표 //옥타브 증가

		*octave += 1;
		printf("↑");

		if (8 < *octave)
			*octave = 8;

		break;

	case 75: //왼쪽 화살표 //지연시간 감소

		*time -= 250;
		printf("←");

		if (*time < 250)
			* time = 250;

		break;

	case 77: //오른쪽 화살표 //지연시간 증가

		*time += 250;
		printf("→");

		if (1000 < *time)
			* time = 1000;

		break;

	case 80: //아래쪽 화살표 //옥타브 감소

		*octave -= 1;
		printf("↓");

		if (*octave <= 1)
			*octave = 1;

		break;

	default:

		break;
	}
}
