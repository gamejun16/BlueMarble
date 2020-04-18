#include "FileIO.h"

//���� ����ü ��ü ����
FILE *fp = NULL;
//���й���
char Delimiter = ',';

//���Ͽ��� - �б���
bool FileRead(char *filename)
{
	//���α׷��� ����� ��� ã��
	char path[512] = { 0, };
	GetCurrentDirectoryA(512, path);
	sprintf(path, "%s\\%s", path, filename);
	//���� ����(�б���)
	if (fp != NULL) fclose(fp);
	fp = fopen(path, "r");
	//���� ���� ���� �� false ��ȯ
	if (fp == NULL) return false;
	return true;
}

//���Ͽ��� - ������
bool FileWrite(char *filename)
{
	//���α׷��� ����� ��� ã��
	char path[512] = { 0, };
	GetCurrentDirectoryA(512, path);
	sprintf(path, "%s\\%s", path, filename);
	//���� ����(������)
	if (fp != NULL) fclose(fp);
	fp = fopen(path, "w+");
	//���� ���� ���� �� false ��ȯ
	if (fp == NULL) return false;
	return true;
}

//������ - �ؽ�Ʈ(string, char*) ����
void WriteText(char *text)
{
	//���й��ڸ� �����ؼ� ���Ͽ� �ؽ�Ʈ ���
	fprintf(fp, "%s%c", text, Delimiter);
}

//������ - ������(int) ����
void WriteInt(int value)
{
	//���й��ڸ� �����ؼ� ���Ͽ� ������ ���
	fprintf(fp, "%d%c", value, Delimiter);
}

//������ - �Ǽ���(float) ����
void WriteFloat(float value)
{
	//���й��� �����ؼ� ���Ͽ� �Ǽ��� ���
	fprintf(fp, "%f%c", value, Delimiter);
}

//������ - �ٹٲ� ����
void WriteReturn()
{
	//�ٹٲ� ���� ���
	//�ٹٲ� ���ڴ� �б��忡�� ���� ���� ����
	fprintf(fp, "\n");
}

//�б��� - �ؽ�Ʈ(string, char*) �б�
void ReadText(char *t)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//���� �ϳ��� ���ۿ� �о����
		fscanf(fp, "%c", &buf);
		//���й����� ��� ���� �Ͻ�����
		if (buf == Delimiter)
		{
			//�����ͷ� ������ ���ڿ� ���� t�� ���� �� ����ֱ�
			for (int i = 0; i < strlen(strbuf); i++)
			{
				t[i] = strbuf[i];
			}
			break;
		}
		//���ڿ� ����(����)�� �ϳ��� �ױ�
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//�б��� - ������(int) �б�
void ReadInt(int *v)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//���� �ϳ��� ���ۿ� �о����
		fscanf(fp, "%c", &buf);
		//���й����� ��� ���� �Ͻ�����
		if (buf == Delimiter)
		{
			//�����ͷ� ������ int ���� v�� ���ڿ�->���� ��ȯ �� �ֱ�
			*v = atoi(strbuf);
			break;
		}
		//���ڿ� ����(����)�� �ϳ��� �ױ�
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//�б��� - �Ǽ���(float) �б�
void ReadFloat(float *f)
{
	char buf;
	char strbuf[1024] = { 0, };
	while (!feof(fp))
	{
		//���� �ϳ��� ���ۿ� �о����
		fscanf(fp, "%c", &buf);
		//���й����� ��� ���� �Ͻ�����
		if (buf == Delimiter)
		{
			//�����ͷ� ������ float ���� f�� ���ڿ�->�Ǽ� ��ȯ �� �ֱ�
			*f = atof(strbuf);
			break;
		}
		//���ڿ� ����(����)�� �ϳ��� �ױ�
		sprintf(strbuf, "%s%c", strbuf, buf);
	}
}

//���ϴݱ�
void FileClose()
{
	fclose(fp);
	fp = NULL;
}