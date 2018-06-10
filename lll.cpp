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
	// LLL君小，中表示
	for (int i = 0; i<2; i++)
	{
		// 緑色を設定
		printf("\x1b[32m");
		// 表示
		std::cout << LLL_TBL[i] << "\r";
		// ms待ち，画面クリア
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL君後退
	for (int i = 0; i<ARY_SIZE(lllSml); i++)
	{
		// 緑色を設定
		printf("\x1b[32m");
		// 高輝度を設定
		//printf("\x1b[1m");
		std::cout << lllSml[i] << "\r";
		// ms待ち，画面クリア
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmAnimeInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL君前進
	for (int i = ARY_SIZE(lllSml) - 1; i != 0; i--)
	{
		// 緑色を設定
		printf("\x1b[32m");
		std::cout << lllSml[i] << "\r";
		// ms待ち，画面クリア
#ifdef WIN_BLD
		Sleep(500);
		system("cls");
#else
		nanosleep(&tmAnimeInf, NULL);
		printf("\x1b[2J");
#endif
	}

	// LLL君画面外
	for (int i = 0; i < ARY_SIZE(lllSmlRmv); i++)
	{
		// 緑色を設定
		printf("\x1b[32m");
		// 出力
		std::cout << lllSmlRmv[i] << "\r";
		// ms待ち，画面クリア
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