#include "header.h"

//���躰 ���ļ��� ����Ͽ� ��ȯ�ϴ� �Լ� calc_frequency
int calc_frequency(int octave, int inx)
{
	double scale = 32.7032; // ���� '��'
	double ratio = pow(2., 1 / 12.), temp; // pow�Լ�(2�� 12������)
	temp = scale * pow(2, octave - 1); // temp�� �ʱ�ȭ

	// temp�� = ���ļ� �� ���
	// temp�� ���
	for (int i = 0; i < inx; i++) // �� ���迡 ���� ������ Ƚ����ŭ �ݺ�
	{
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp; // ���ļ� �� ��ȯ
}

