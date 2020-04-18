#include "FileIO.h"

//파일 구조체 객체 선언
FILE *fp = NULL;
//구분문자
char Delimiter = ',';

//파일열기 - 읽기모드
bool FileRead(char *filename)
{
	//프로그램이 실행된 경로 찾기
	char path[512] = { 0, };
	GetCurrentDirectoryA(512, path);
	sprintf(path, "%s\\%s", path, filename);
	//파일 열기(읽기모드)
	if (fp != NULL) fclose(fp);
	fp = fopen(path, "r");
	//파일 열기 실패 시 false 반환
	if (fp == NULL) return false;
	return true;
}

//파일열기 - 쓰기모드
bool FileWrite(char *filename)
{
	//프로그램이 실행된 경로 찾기
	char path[512] = { 0, };
	GetCurrentDirectoryA(512, path);
	sprintf(path, "%s\\%s", path, filename);
	//파일 열기(쓰기모드)
	if (fp != NULL) fclose(fp);
	fp = fopen(path, "w+");
	//파일 열기 실패 시 false 반환
	if (fp == NULL) return false;
	return true;
}

//쓰기모드 - 텍스트(string, char*) 쓰기
void WriteText(char *text)
{
	//구분문자를 포함해서 파일에 텍스트 기록
	fprintf(fp, "%s%c", text, Delimiter);
}

//쓰기모드 - 정수형(int) 쓰기
void WriteInt(int value)
{
	//구분문자를 포함해서 파일에 정수값 기록
	fprintf(fp, "%d%c", value, Delimiter);
}

//쓰기모드 - 실수형(float) 쓰기
void WriteFloat(float value)
{
	//구분문자 포함해서 파일에 실수값 기록
	fprintf(fp, "%f%c", value, Delimiter);
}

//쓰기모드 - 줄바꿈 문자
void WriteReturn()
{
	//줄바꿈 문자 기록
	//줄바꿈 문자는 읽기모드에는 영향 주지 않음
	fprintf(fp, "\n");
}

//읽기모드 - 텍스트(string, char*) 읽기
void ReadText(char *t)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//문자 하나씩 버퍼에 읽어오기
		fscanf(fp, "%c", &buf);
		//구분문자일 경우 루프 일시중지
		if (buf == Delimiter)
		{
			//포인터로 가져온 문자열 변수 t에 버퍼 값 복사넣기
			for (int i = 0; i < strlen(strbuf); i++)
			{
				t[i] = strbuf[i];
			}
			break;
		}
		//문자열 변수(버퍼)에 하나씩 쌓기
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//읽기모드 - 정수형(int) 읽기
void ReadInt(int *v)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//문자 하나씩 버퍼에 읽어오기
		fscanf(fp, "%c", &buf);
		//구분문자일 경우 루프 일시중지
		if (buf == Delimiter)
		{
			//포인터로 가져온 int 변수 v에 문자열->정수 변환 후 넣기
			*v = atoi(strbuf);
			break;
		}
		//문자열 변수(버퍼)에 하나씩 쌓기
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//읽기모드 - 실수형(float) 읽기
void ReadFloat(float *f)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//문자 하나씩 버퍼에 읽어오기
		fscanf(fp, "%c", &buf);
		//구분문자일 경우 루프 일시중지
		if (buf == Delimiter)
		{
			//포인터로 가져온 float 변수 f에 문자열->실수 변환 후 넣기
			*f = atof(strbuf);
			break;
		}
		//문자열 변수(버퍼)에 하나씩 쌓기
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//파일닫기
void FileClose()
{
	fclose(fp);
	fp = NULL;
}