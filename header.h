#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include<mmsystem.h>

#pragma comment (lib, "winmm.lib") 

#define MAX 1000

#ifndef _HEADER_H_
#define _HEADER_H_
char notes[MAX];
#endif

// 메뉴 1번 관련 함수
void piano_menu_1(void);
void piano_point_menu1(int x, int y);
void piano_practice_menu1(void);
void draw_piano_keyboard_menu1(void);
void touch_keyboard_menu1(int note);
void arrow_key_control_menu1(int note, int* octave, double* time);

// 메뉴 2번 관련 함수
void piano_menu_2(void);
void guess_code_menu2(void);
void answer_guess_code_menu2(int note, int* pNOTES);

// 메뉴 3번 관련 함수
void piano_menu_3(void);
void record_menu3(char* notes);
void replay_menu3(char* notes);
void arrow_key_control_menu3(int note, int* octave, double* time);

// 계산 함수
int calc_frequency(int octave, int inx);

