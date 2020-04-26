// C++IOFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define MAX 1024
typedef int(*Fun)(char* s,FILE *file);

int chooseAction(Fun fun, char* name)
{
	FILE *file = fopen("D:\\MyProject\\c++\\FILE\\bookname.txt", "a+");
	fun(name,file);
	return 0;
}

int addFile(char *pName, FILE *file)
{
	char bookname[100] = {0};
	char autor[100] = { 0 };
	char press[100] = { 0 };
	//char string[MAX] = " ";
	
	if (file == NULL)
	{
		printf("读取文件失败");
		return -1;
	}
	printf("请输入要添加的书名：");
	scanf("%s", bookname);
	printf("请输入要添加的书的作者：");
	scanf("%s", autor);
	printf("请输入要添加的出版社：");
	scanf("%s", press);
	//strcat_s(string, sizeof(string), bookname);
	//strcat_s(string, sizeof(string), autor);
	//strcat_s(string, sizeof(string), press);
	fprintf(file, "%-20s%-20s%-20s\n", bookname, autor, press);
	//fputs(string, file);
	printf("添加完完成\n");
	/*
	while (fgets(string, MAX, file) != NULL)
	{

	}
	*/
	fclose(file);
	return 0;
}

int upDateFile(char *pName, FILE *file)
{

	return 0;
}

int selectFile(char *pName, FILE *file)
{
	char userStr[MAX] = { 0 }; 
	char sysStr[MAX] = { 0 };
	char sysString[MAX] = { 0 };
	printf("请输入要查找的书名或者作者\n");
	scanf("%s", userStr);
	while (fgets(sysStr,MAX,file) != NULL)
	{
		int i = 0;
		int j = 0;
		while (i < strlen(sysStr))
		{
			if (sysStr[i] == '\t'||sysStr[i] == '\n'||sysStr[i] == ' ') //因为记事本使用了空格（' '）与水平制表符（'\t'）,所以都要判断
			{
				if (strcmp(userStr, sysString) == 0)
				{
					printf("找到了\n");
					printf("%s \n", sysStr);
					return 0;
				}
				memset(sysString, 0, sizeof(sysString));
				j = 0;
			}
			else
			{
				sysString[j++] = sysStr[i];
			}
			i++;
		}
	}
	printf("没有找到\n");
	return 0;
}
int deleteFile(char *pName, FILE *file)
{
	return 0;
}
int main()
{
#if 1
	int offOn = 1;
	int* pAction;
	int(*arrFun[4])(char *s, FILE *file) = { selectFile,addFile,upDateFile,deleteFile };
	printf("0.查询图书：\n");
	printf("1.增加图书：\n");
	printf("2.修改图书：\n");
	printf("3.删除图书：\n");
	//printf("5.返回上一层：");
	printf("6.退出：\n");
	
	while (offOn != 6)
	{

		printf("请输入操作类型的序列号：");
		//这里如果输入了遗传字符串scanf不会给offon赋值，也不会刷新缓存区，导致死循环，加个getchar刷新缓存区
		int a = scanf("%d", &offOn);
		if (offOn < 6 && offOn >= 0 )
		{
			//printf("操作文件");
			char name[] = " ";
			chooseAction(arrFun[offOn],name);
		}
		else
		{
			//fflush(stdin); c11之后失效
			getchar();
			printf("无效输入，请从新输入 \n");
		}
	}
#endif
#if 0
	char ch;
	while ((ch = getchar()) != '#')
	{
		putchar(ch);
	}
#endif
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
