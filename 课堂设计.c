/* 请在 Visual C++ 6.0 环境下运行 */
/*   Turbo C 2.0 环境下无法运行   */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"
#define  Limit 10

/* 函数声明 */
float       average(int x);
void inputing(int x,int y);
void   gotoxy(int x,int y);
void          sheet(int x);
void    menu();
void    sign();
void  finish();
void   input();
void  output();
void process();
void    sort();
void  demand();
void     del();
void  search();
void    save();
void    load();

int    query();
/* 函数声明 */

struct singer			//结构体
{
	int   age;		//年龄
	char  ID[15];		//编号
	char  name[15];		//姓名
	char  sex [15];		//性别
	char  tel[15];		//电话
	float score[5];		//评分
}player[Limit];




int Num=0;
void main()//main函数
{
	char option;
	sign();
	while(1)
	{
		system("cls");
		menu(1);
		gotoxy(30,5);
		printf("◆ 菜单 ◆");
		gotoxy(30,8);
		printf("1.录入数据");
		gotoxy(30,10);
		printf("2.显示数据");
		gotoxy(30,12);
		printf("3.查找数据");
		gotoxy(30,14);
		printf("4.保存数据");
		gotoxy(30,16);
		printf("5.读取数据");
		gotoxy(30,18);
		printf("0.退出程序");
		gotoxy(0,0);
		do
		{option=getch(),fflush(stdin);}
		while(option!='1'&&option!='2'&&option!='3'&&option!='4'&&option!='5'&&option!='0');
		if(option=='0')
		{break;}
		else switch(option)
		{
			case '1':
			{input();break;}
			case '2':
			{process();break;}
			case '3':
			{search();break;}
			case '4':
			{save();break;}
			case '5':
			{load();break;}
		}
	}
	finish();
}



void sign()//署名
{
	system("mode con cols=40 lines=10");
	gotoxy(8,1);
	printf("《歌手比赛成绩管理系统》");
	gotoxy(7,3);
	printf("设计者：测控1703班-王思衡");
	gotoxy(9,5);
	printf("设计日期：2017年12月");
	gotoxy(11,8);
	printf("按任意键进入主菜单");
	gotoxy(0,0);
	getch(),fflush(stdin);
}

void finish()//结束框
{
	system("cls");
	system("mode con cols=40 lines=20");
	gotoxy(13,1);
	printf("感谢您的使用！\n\n");
	printf("         __..._.-. \n");
	printf("        /.-.   '-.) \n");
	printf("        \\',       \\ \n");
	printf("         |       o'--D\n");
	printf("         \\      /    |\n");
	printf("          ;._  _\\ '-/\n");
	printf("        .'    __ `\\`.-'-. .-'-.\n");
	printf("      .'    .'  '.|'     '     ',\n");
	printf("     /      \\     '._,          |\n");
	printf("    ;        '-._     \\         /\n");
	printf("   (|           /'-.__/       .'\n");
	printf("    \\  __     ,'     '-.   .-'\n");
	printf("     `/  `\\.-'|         '.'\n");
	printf("      |    |  '-.\n");
	printf("      |    '-.   )\n");
	printf("      \\       )-'\n");
	printf("       '-----' ");
	gotoxy(27,1);
	Sleep(3000);
}

void input()//输入数据
{
	char j;
	system("cls");
	menu();
	gotoxy(25,5);
	printf("◆您已选择：录入数据");
	gotoxy(25,9);
	printf("1.清空数据并重新录入");
	gotoxy(25,13);
	printf("2.添加新的歌手信息");
	gotoxy(25,17);
	printf("0.返回主菜单");
	gotoxy(0,0);
	do
	{j=getch(),fflush(stdin);}
	while(j!='1'&&j!='2'&&j!='0');
	switch(j)
	{
		case '1':
		{
			do
			{
				system("cls");
				menu();
				gotoxy(20,5);
				printf("◆当前选择：清空数据并重新录入");
				gotoxy(15,11);
				printf("请输入要录入的人数(大于等于0,小于等于%d) ",Limit);
				gotoxy(15,14);
				scanf("%d",&Num),fflush(stdin);
			}
			while(Num<0||Num>Limit);
			inputing(Num,0);
			break;
		}
		case '2':
		{
			int i;
			if(Num>=Limit)
			{
				system("cls");
				menu(3);
				gotoxy(20,10);
				printf("歌手信息已满%d条，无法继续录入   ",Limit);
				gotoxy(25,15);
				printf("请按任意键返回主菜单   ");
				getch(),fflush(stdin);
				break;
			}
			else
			{
				do
				{
					system("cls");
					menu();
					gotoxy(20,5);
					printf("◆当前选择：添加新的歌手信息");
					gotoxy(15,11);
					printf("请输入要录入的人数(大于等于0,小于等于%d) ",Limit-Num);
					gotoxy(15,14);
					scanf("%d",&i),fflush(stdin);
				}
				while(i<0||i>Limit-Num);
				inputing(i,Num);
				Num+=i;
				break;
			}
		}
		case '0':
		{break;}
	}
}

void inputing(int x,int y)//输入主体
{
	int i,k;
	float n;
	sheet(x);
	for(i=0;i<x;i++)
	{
		gotoxy(2,i*2+3);
		scanf("%s",player[y+i].ID),fflush(stdin);
		gotoxy(13,i*2+3);
		scanf("%s",player[y+i].name),fflush(stdin);
		gotoxy(26,i*2+3);
		scanf("%s",player[y+i].sex),fflush(stdin);
		gotoxy(33,i*2+3);
		scanf("%d",&player[y+i].age),fflush(stdin);
		gotoxy(42,i*2+3);
		scanf("%s",player[y+i].tel),fflush(stdin);
		for(k=0;k<5;k++)
		{
			do
			{
				gotoxy(68+7*k,i*2+3);
				printf("    ");
				gotoxy(68+7*k,i*2+3);
				scanf("%f",&n),fflush(stdin);
			}
			while(n<0||n>10);
			player[y+i].score[k]=n;
		}
		gotoxy(106,i*2+3);
		printf("%.1f",average(y+i));
	}
	gotoxy(40,26);
	printf("恭喜！录入完成！请按任意键返回主菜单   ");
	getch(),fflush(stdin);
	system("cls");
}

void output()//输出数据
{
	int i,j;
	sheet(Num);
	for(i=0;i<Num;i++)
	{
		gotoxy(2,i*2+3);
		printf("%s",player[i].ID);
		gotoxy(13,i*2+3);
		printf("%s",player[i].name);
		gotoxy(26,i*2+3);
		printf("%s",player[i].sex);
		gotoxy(33,i*2+3);
		printf("%d",player[i].age);
		gotoxy(42,i*2+3);
		printf("%s",player[i].tel);
		for(j=0;j<5;j++)
		{
			gotoxy(68+7*j,i*2+3);
			printf("%.1f",player[i].score[j]);
		}
		gotoxy(106,i*2+3);
		printf("%.1f",average(i));
	}
}

void process()//数据处理
{
	char j;
	output();
	gotoxy(17,27);
	printf("<   1.数据排序           2.数据修改          3.数据删除          0.结束浏览   >");
	gotoxy(43,25);
	printf("按对应数字键执行对应操作");
	do
	{j=getch(),fflush(stdin);}
	while(j!='1'&&j!='2'&& j!='3'&&j!='0');
	switch(j)
	{
		case '1':
		{sort();break;}
		case '2':
		{demand();break;}
		case '3':
		{del();break;}
		case '0':
		{break;}
	}
}

void sort()//数据排序
{
	int i,j;
	struct singer vocalist;
	for(i=0;i<Num-1;i++)
	{
		for(j=0;j<Num-1-i;j++)
		{
			if(average(j)>average(j+1))
			{
				vocalist=player[j];
				player[j]=player[j+1];
				player[j+1]=vocalist;
			}
		}
	}
	process();
}

void demand()//数据修改
{
	int i,k;
	char j;
	float l;
	system("cls");
	output();
	gotoxy(45,25);
	printf("请输入待修改的歌手姓名   ");
	i=query();
	if(i==-1)
	{
		gotoxy(45,27);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(1,25);
		printf("请选择修改选项<   1.编号          2.姓名          3.性别          4.电话          5.评分          0.取消   >");
		do
		{j=getch(),fflush(stdin);}
		while(j!='1'&&j!='2'&&j!='3'&&j!='4'&&j!='5'&&j!='0');
		switch(j)
		{
			case '1':
			{
				gotoxy(42,28);
				printf("您希望修改%s的编号，是否确认?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("请输入修改后的编号：   ");
					scanf("%s",player[i].ID);
				}
				break;
			}
			case '2':
			{
				gotoxy(42,28);
				printf("您希望修改%s的姓名，是否确认?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("请输入修改后的姓名：   ");
					scanf("%s",player[i].name);
				}
				break;
			}
			case '3':
			{
				gotoxy(42,28);
				printf("您希望修改%s的性别，是否确认?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("请输入修改后的性别：   ");
					scanf("%s",player[i].sex);
				}
				break;
			}
			case '4':
			{
				gotoxy(42,28);
				printf("您希望修改%s的电话，是否确认?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("请输入修改后的电话：   ");
					scanf("%s",player[i].tel);
				}
				break;
			}
			case '5':
			{
				gotoxy(42,28);
				printf("您希望修改%s的评分，是否确认?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(38,30);
					printf("请输入修改后的评分（格式：评委号，评分）   ");
					scanf("%d,%f",&k,&l),fflush(stdin);
					player[i].score[k-1]=l;
				}
				break;
			}
			case '0':{break;}
		}
	}
	process();
}

void del()//数据删除
{
	int i,k;
	char j;
	system("cls");
	output();
	gotoxy(45,25);
	printf("请输入待删除信息的歌手姓名   ");
	i=query();
	if(i==-1)
	{
		gotoxy(47,27);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(40,27);
		printf("您希望删除%s的所有信息，是否确认?(Y/N)     ",player[i].name);
		do
		{j=getch(),fflush(stdin);}
		while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
		if(j=='Y'||j=='y')
		{
			for(i;i<Num;i++)
			{
				for(k=0;k<=15;k++)
				{
				player[i].ID[k]=player[i+1].ID[k];
				player[i].name[k]=player[i+1].name[k];
				player[i].sex[k]=player[i+1].sex[k];
				player[i].tel[k]=player[i+1].tel[k];
				}
				player[i].age=player[i+1].age;
				for(k=0;k<5;k++)
				{
				player[i].score[k]=player[i+1].score[k];
				}
			}
			Num-=1;
		}
	}
	process();
}

void search()//数据查询
{
	int i;
	system("cls");
	menu();	
	gotoxy(25,5);
	printf("◆您已选择：查询数据");
	gotoxy(24,10);
	printf("请输入待查询的歌手姓名");
	gotoxy(24,13);
	i=query();
	if(i==-1)
	{
		gotoxy(24,16);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		system("cls");
		printf("以下为该歌手的全部信息\n\n");
		printf("编号:        %s\n\n",player[i].ID);
		printf("姓名:        %s\n\n",player[i].name);
		printf("性别:        %s\n\n",player[i].sex);
		printf("年龄:        %d\n\n",player[i].age);
		printf("电话号码:    %s\n\n",player[i].tel);
		printf("评委评分:\n");
		printf("︿\n");
		printf("①:          %.1f\n",player[i].score[0]);
		printf("②:          %.1f\n",player[i].score[1]);
		printf("③:          %.1f\n",player[i].score[2]);
		printf("④:          %.1f\n",player[i].score[3]);
		printf("⑤:          %.1f\n",player[i].score[4]);
		printf("﹀\n");
		printf("平均成绩：   %.1f          请按‘Enter’键退出   ",average(i));
		getchar(),fflush(stdin);
	}
}

void sheet(int x)//打印表格
{
	int i;
	system("mode con cols=117 lines=33");
	system("cls");
	printf("┏----------------------------------------------------------------------------------------------------------------┓\n");
	printf("┃  编号   |    姓名    | 性别 | 年龄 |     电话号码     |  评分：<  ①  |  ②  |  ③  |  ④  |  ⑤  > | 平均成绩 ┃\n");
	for(i=0;i<x;i++)
	{
	printf("┃----------------------------------------------------------------------------------------------------------------┃\n");
	printf("┃         |            |      |      |                  |        <      |      |      |      |      > |          ┃\n");
	}
	printf("┗----------------------------------------------------------------------------------------------------------------┛\n");
}

void menu()//打印菜单
{
	system("mode con cols=70 lines=23");
	printf("\n                      ◆   歌手比赛成绩管理系统   ◆      \n\n");
	printf("          **************************************************\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          **************************************************\n");
}

void save()//保存数据
{
	FILE *fp;
	int i;
	char j;
	system("cls");
	menu();
	gotoxy(20,10);
	printf("您希望保存数据，是否确认?(Y/N)  ");
	do
	{j=getch(),fflush(stdin);}
	while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
	if(j=='N'||j=='n')
	return;
	if((fp=fopen("D:\\information.dat","wb"))==NULL)
	{
		gotoxy(18,14);
		printf("错误：无法正常保存！请按任意键返回");
		getch();
		return;
	}
	for(i=0;i<Limit;i++)
	{
		if(fwrite(&player[i],sizeof(struct singer),1,fp)!=1)
		{
			gotoxy(16,14);
			printf("错误：%s数据无法保存！请按任意键继续",player[i].name);
			getch();
		}
	}
	gotoxy(18,14);
	printf("恭喜，保存数据成功！请按任意键返回");
	getch();
	fclose(fp);
}

void load()//读取数据
{
	int i;
	char j;
	FILE *fp;
	system("cls");
	menu();
	gotoxy(20,10);
	printf("您希望读取数据，是否确认?(Y/N)  ");
	do
	{j=getch(),fflush(stdin);}
	while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
	if(j=='N'||j=='n')
	return;
	if((fp=fopen("D:\\information.dat","rb"))==NULL)
	{
		gotoxy(18,14);
		printf("错误：无法正常读取！请按任意键返回");
		getch();
		return;
	}
	for(i=0;i<Limit;i++)
	{
		fread(&player[i],sizeof(struct singer),1,fp);
		if(strcmp(player[i].name,"\0")==0)
		{break;}
	}
/*	for(i=0;i<Limit;i++)
	{
		if(strcmp(player[i].name,"\0")==0)
		{break;}
	}*/
	Num=i;
	gotoxy(18,14);
	printf("恭喜，读取数据成功！请按任意键返回");
	getch();
	fclose(fp);
}

void gotoxy(int x,int y)//光标移动
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

int query()//姓名检索
{
	char name[15];
	int i;
	gets(name),fflush(stdin);
	for(i=0;i<Num;i++)
	{
		if(strcmp(name,player[i].name)==0)
		{return i;}
	}
	return -1;
}

float average(int x)//求平均成绩
{
	int i=0;
	float add=0,max=player[x].score[0],min=player[x].score[0];
	for(i=0;i<5;i++)
	{
		add+=player[x].score[i];
		if(player[x].score[i]>max)
		{max=player[x].score[i];}
		if(player[x].score[i]<min)
		{min=player[x].score[i];}
	}
	return (add-max-min)/3;
}
