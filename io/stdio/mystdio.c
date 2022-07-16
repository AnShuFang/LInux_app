/*本程序实现标准io相关操作*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 12
int main(int argc, char* argv[])
{
#if 0  //本段测试fopen fclose fgetc fputc相关功能
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int ch;
	int count = 0;//统计文件的字符个数
	FILE* f1 = NULL;
	FILE* f2 = NULL;
	f1 = fopen(argv[1], "r");
	if (NULL == f1)
	{
		perror("fopen1:");
		exit(1);
	}
	f2 = fopen(argv[2], "w");
	if (NULL == f2)
	{
		fclose(f1);//说明前面的f1打开成功了
		perror("fopen2:");
		exit(1);
	}
	while (1)
	{
		ch=fgetc(f1);
		//printf("%d\n", ch);
		if (ch == EOF) //又把==号写错了，一定要注意
			break;
		fputc(ch, f2);
		fputc(ch, stdout);
		count++;
	}
	printf("%d\n", count);
	fclose(f1);
	fclose(f2);
#endif

#if 0 //本段测试fopen fclose fgets fputs相关功能
	char buf[SIZE];
	memset(buf, 0, sizeof(buf));
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int count = 0;//统计打印次数
	char* ch;
	FILE* f1 = NULL;
	FILE* f2 = NULL;
	f1 = fopen(argv[1], "r");
	if (NULL == f1)
	{
		perror("fopen1:");
		exit(1);
	}
	f2 = fopen(argv[2], "w");
	if (NULL == f2)
	{
		fclose(f1);//说明前面的f1打开成功了
		perror("fopen2:");
		exit(1);
	}
	while (1)
	{
		ch=fgets(buf,SIZE,f1);
		//printf("%d\n", ch);
		if (ch== NULL) //又把==号写错了，一定要注意
			break;
		fputs(buf, f2);
		fputs(buf, stdout);
		count++;
	}
	printf("%d\n", count);
	fclose(f1);
	fclose(f2);
#endif
#if 0//本段测试fopen fclose fread fwrite相关功能
	char buf[SIZE];
	memset(buf, 0, sizeof(buf));
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int count = 0;//统计打印次数
	size_t ch = 0;
	FILE* f1 = NULL;
	FILE* f2 = NULL;
	f1 = fopen(argv[1], "r");
	if (NULL == f1)
	{
		perror("fopen1:");
		exit(1);
	}
	f2 = fopen(argv[2], "w");
	if (NULL == f2)
	{
		fclose(f1);//说明前面的f1打开成功了
		perror("fopen2:");
		exit(1);
	}
	while ((ch= fread(buf, 1, SIZE, f1))>0) //区别fgets与fread的区别，不需要在缓冲区的的最后一关空间添加'\0’
	{
		fwrite(buf, 1,ch,f2);
		fwrite(buf,1,ch, stdout);
		count++;
	}
	printf("%d\n", count);
	fclose(f1);
	fclose(f2);
#endif
#if 0
	char* buf = "-123456";
	int a = atoi(buf);
	printf("%d\n", a);
#endif

	FILE* fp1;
	fp1 = fopen(argv[1], "r");
	if (NULL == fp1)
	{
		perror("fopen:");
		exit(1);
	}
	fseek(fp1, 0, SEEK_END);
	printf("%ld\n", ftell(fp1));

	return 0;
}
