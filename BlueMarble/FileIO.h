//FileIO ���, ��������� �Լ�
#ifndef __FILEIO_H__
#define __FILEIO_H__

#include <stdio.h>
#include <Windows.h>

bool FileRead(char *filename);		//���Ͽ��� - �б���
bool FileWrite(char *filename);		//���Ͽ��� - ������

void WriteText(char *text);			//������ - �ؽ�Ʈ(string, char*) ����
void WriteInt(int value);			//������ - ������(int) ����
void WriteFloat(float value);		//������ - �Ǽ���(float) ����
void WriteReturn();					//������ - �ٹٲ� ����

void ReadText(char *t);				//�б��� - �ؽ�Ʈ(string, char*) �б�
void ReadInt(int *v);				//�б��� - ������(int) �б�
void ReadFloat(float *f);			//�б��� - �Ǽ���(float) �б�

void FileClose();					//���ϴݱ�

#endif