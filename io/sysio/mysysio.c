/*���������ϵͳio��غ���*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
* function :ɾ���ļ��ĵ�n��
* copyright:fang
* data:2022.07.18
* ���룺�ļ���  ����
* ��� 0:successful  -1:faild
*/
/*int del_file(const char* name, int n)
{
	int buf[20];
	memset(buf, 0, sizeof(buf)); //���û������������

	int flag = 1;//�������

	int fd2 = open(name, O_RDWR);
	if (fd2 < 0)
	{
		perror("open-fd2:");
		exit(1);
	}
	int len = 0;//��¼������ַ���
	int ret = 0;//��¼д����ַ���
	while (flag < n)
	{
		len = read(fd2, buf, 20);
		if (len <= 0)
		{
			break;
		}
		int i = 0;
		for (i = 0; i < len; i++)
		{
			if (buf[i] == '\n')
				flag++;
			if (flag == n)
				break;
		}
	}
	if (flag < n)
	{
		fprintf(sterr, "file does not have %d lines\n", n);
		return -1;
	}
	off_t off2 = lseek(fd2, 1, SEEK_CUR);//����ָ���10�еĿ�ʼ

	int fd1 = open(name, O_RDONLY);
	if (fd1 < 0)
	{
		perror("open-fd1:");
		exit(1);
	}
	flag = 0;
	len = 0;//��¼������ַ���
	ret = 0;//��¼д����ַ���
	while (flag < n+1)
	{
		len = read(fd1, buf, 20);
		if (len <= 0)
		{
			break;
		}
		int i = 0;
		for (i = 0; i < len; i++)
		{
			if (buf[i] == '\n')
				flag++;
			if (flag == n+1)
				break;
		}
	}
	off_t off1 = lseek(fd1, 1, SEEK_CUR);//����ָ���11�еĿ�ʼ

	return 0;
}*/
#define MAXSIZE 10
#define FILE  "/tmp/out"
int main(int argc, char* argv[])
{
#if 0
	char buf[MAXSIZE];
	int len = 0;
	int ret = 0;
	int fd1;
	int fd2;
	memset(buf, 0, sizeof(buf));
	if (argc < 3)
	{
		fprintf(stderr, "argc error:\n");
		exit(1);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
	{
		perror("open-fd1:");
		exit(1);
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd2 < 0)
	{
		close(fd1);//��ֹ�ڴ�й©
		perror("open-fd2:");
		exit(1);
	}
	while (1)
	{
		len = read(fd1, buf, 10);
		if (len < 0)
		{
			perror("read:");
			break;
		}
		if (len == 0)
		{
			break;
		}
		int offset = 0;
		while (len > 0)//��Ȼ��һ�ζ�len�������ǳ���������ô�죬��������
		{
			ret = write(fd2, buf+offset, len);
			if (ret < 0)
			{
				perror("write:");
				break;
			}
			offset += ret;
			len -= ret;
		}
	}
	
	close(fd1);
	close(fd2);
#endif
	int fd;
	close(1);
	fd = open(FILE, O_WRONLY | O_CREAT | O_TRUNC,0666);
	if (open < 0)
	{
		perror("open:");
		exit(1);
	}
	//dup2(fd, 1);
	//close(1);
	//dup(fd);
	if (fd != 1)
	{
		close(fd);
	}
	//puts("hello!");

	return 0;
}