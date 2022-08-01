/*本程序测试系统io相关函数*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
* function :删除文件的第n行
* copyright:fang
* data:2022.07.18
* 输入：文件名  行数
* 输出 0:successful  -1:faild
*/
/*int del_file(const char* name, int n)
{
	int buf[20];
	memset(buf, 0, sizeof(buf)); //设置缓冲区，并清空

	int flag = 1;//标记行数

	int fd2 = open(name, O_RDWR);
	if (fd2 < 0)
	{
		perror("open-fd2:");
		exit(1);
	}
	int len = 0;//记录读入的字符数
	int ret = 0;//记录写入的字符数
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
	off_t off2 = lseek(fd2, 1, SEEK_CUR);//将其指向第10行的开始

	int fd1 = open(name, O_RDONLY);
	if (fd1 < 0)
	{
		perror("open-fd1:");
		exit(1);
	}
	flag = 0;
	len = 0;//记录读入的字符数
	ret = 0;//记录写入的字符数
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
	off_t off1 = lseek(fd1, 1, SEEK_CUR);//将其指向第11行的开始

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
		close(fd1);//防止内存泄漏
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
		while (len > 0)//虽然想一次读len个，但是出现意外怎么办，避免意外
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