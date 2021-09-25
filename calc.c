#include "header.h"

//음계별 주파수를 계산하여 반환하는 함수 calc_frequency
int calc_frequency(int octave, int inx)
{
	double scale = 32.7032; // 낮은 '도'
	double ratio = pow(2., 1 / 12.), temp; // pow함수(2의 12제곱근)
	temp = scale * pow(2, octave - 1); // temp값 초기화

	// temp값 = 주파수 값 출력
	// temp값 계산
	for (int i = 0; i < inx; i++) // 각 음계에 따라 지정된 횟수만큼 반복
	{
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp; // 주파수 값 반환
}

