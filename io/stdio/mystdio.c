/*������ʵ�ֱ�׼io��ز���*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1024
int main(int argc, char* argv[])
{
#if 0  //���β���fopen fclose fgetc fputc��ع���
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int ch;
	int count = 0;//ͳ���ļ����ַ�����
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
		fclose(f1);//˵��ǰ���f1�򿪳ɹ���
		perror("fopen2:");
		exit(1);
	}
	while (1)
	{
		ch=fgetc(f1);
		//printf("%d\n", ch);
		if (ch == EOF) //�ְ�==��д���ˣ�һ��Ҫע��
			break;
		fputc(ch, f2);
		fputc(ch, stdout);
		count++;
	}
	printf("%d\n", count);
	fclose(f1);
	fclose(f2);
#endif

#if 0 //���β���fopen fclose fgets fputs��ع���
	char buf[SIZE];
	memset(buf, 0, sizeof(buf));
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int count = 0;//ͳ�ƴ�ӡ����
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
		fclose(f1);//˵��ǰ���f1�򿪳ɹ���
		perror("fopen2:");
		exit(1);
	}
	while (1)
	{
		ch=fgets(buf,SIZE,f1);
		//printf("%d\n", ch);
		if (ch== NULL) //�ְ�==��д���ˣ�һ��Ҫע��
			break;
		fputs(buf, f2);
		fputs(buf, stdout);
		count++;
	}
	printf("%d\n", count);
	fclose(f1);
	fclose(f2);
#endif
#if 0//���β���fopen fclose fread fwrite��ع���
	char buf[SIZE];
	memset(buf, 0, sizeof(buf));
	if (argc < 3)
	{
		fprintf(stderr, "Usage: lock parameter\n");
		exit(1);
	}
	int count = 0;//ͳ�ƴ�ӡ����
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
		fclose(f1);//˵��ǰ���f1�򿪳ɹ���
		perror("fopen2:");
		exit(1);
	}
	while ((ch= fread(buf, 1, SIZE, f1))>0) //����fgets��fread�����𣬲���Ҫ�ڻ������ĵ����һ�ؿռ����'\0��
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
#if 1
	FILE* fp1;
	fp1 = fopen(argv[1], "r");
	if (NULL == fp1)
	{
		perror("fopen:");
		exit(1);
	}
	fseek(fp1, 0, SEEK_END);
	printf("%ld\n", ftell(fp1));
#endif
#if 0
	if (argc < 2)
	{
		fprintf(stderr, "argv err:\n");
		exit(1);
	}
	FILE* fp1;
	char* buf=NULL; //�������ر���Ҫ��getline���ݳ�ʼֵ�ж���Ҫ����ռ仹����չ
	size_t n=0;
	fp1 = fopen(argv[1], "r");
	if (NULL == fp1)
	{
		perror("fopen1:");
		exit(1);
	}
	while (1)
	{
		if (getline(&buf, &n, fp1) < 0) //getlineû�п���Ĳ���������Ŀռ�û���ͷ�
			break;
		printf("%ld\n", strlen(buf));
		printf("%s\n", buf);
	}
	//free(buf);
	fclose(fp1);
#endif
	return 0;
}
