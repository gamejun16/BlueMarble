//FileIO 헤더, 파일입출력 함수
#ifndef __FILEIO_H__
#define __FILEIO_H__

#include <stdio.h>
#include <Windows.h>

bool FileRead(char *filename);		//파일열기 - 읽기모드
bool FileWrite(char *filename);		//파일열기 - 쓰기모드

void WriteText(char *text);			//쓰기모드 - 텍스트(string, char*) 쓰기
void WriteInt(int value);			//쓰기모드 - 정수형(int) 쓰기
void WriteFloat(float value);		//쓰기모드 - 실수형(float) 쓰기
void WriteReturn();					//쓰기모드 - 줄바꿈 문자

void ReadText(char *t);				//읽기모드 - 텍스트(string, char*) 읽기
void ReadInt(int *v);				//읽기모드 - 정수형(int) 읽기
void ReadFloat(float *f);			//읽기모드 - 실수형(float) 읽기

void FileClose();					//파일닫기

#endif