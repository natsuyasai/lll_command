#include "lll.h"
#include <iostream>
#include <stdio.h>
#ifdef WIN_BLD
#include <Windows.h>
#else
#include <stdlib.h>
#include <time.h>
#endif

template<typename T, size_t SIZE>
static int ARY_SIZE(const T(&array)[SIZE])
{
	return SIZE;
}

int main(int argc, char *argv[])
{
#ifndef WIN_BLD
	struct timespec tmInf = { 0,500000000 };
	struct timespec tmAnimeInf = { 0,100000000 };
#endif
	// LLL�N���C���\��
	for (int i = 0; i<2; i++)
	{
		// �ΐF��ݒ�
		printf("\x1b[32m");
		// �\��
		std::cout << LLL_TBL[i] << "\r";
		// ms�҂��C��ʃN���A
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL�N���
	for (int i = 0; i<ARY_SIZE(lllSml); i++)
	{
		// �ΐF��ݒ�
		printf("\x1b[32m");
		// ���P�x��ݒ�
		//printf("\x1b[1m");
		std::cout << lllSml[i] << "\r";
		// ms�҂��C��ʃN���A
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmAnimeInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL�N�O�i
	for (int i = ARY_SIZE(lllSml) - 1; i != 0; i--)
	{
		// �ΐF��ݒ�
		printf("\x1b[32m");
		std::cout << lllSml[i] << "\r";
		// ms�҂��C��ʃN���A
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmAnimeInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL�N��ʊO
	for (int i = 0; i < ARY_SIZE(lllSmlRmv); i++)
	{
		// �ΐF��ݒ�
		printf("\x1b[32m");
		// �o��
		std::cout << lllSmlRmv[i] << "\r";
		// ms�҂��C��ʃN���A
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmAnimeInf, NULL);
		printf("\x1b[2J");
#endif
	}

	return 0;
}