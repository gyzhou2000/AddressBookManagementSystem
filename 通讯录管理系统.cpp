#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100	//便于修改结构体的大小 

FILE *fp;	//定义文件指针 

int count=0;	//定义一个count，count代表通讯录中联系人的数量 

struct node		//定义一个结构体 
{
	int num;
	char name[20];
	char work[20]; 
	char tel[11];
};
typedef struct node list;
list person[N];

void CreatStruct();
char Input();
void TiShi();
void Tips(int n);
char Getchar();
void AddInfo();
void SumCount();
void ChangeInfo();
void ChangeName();
void ChangeWork();
void ChangeTell();
void FindInfo();
void DeleteInfo();
 
int main()
{
	while(1)
	{
		SumCount();
		char i;
		i=Input();
		switch(i)
		{
			case '0':					//退出
				return 0;
				break;
			case '1':                 //添加信息
				AddInfo();
				break;
			case '2':					//查询信息 
				FindInfo();
				break;
			case '3':					//删除信息 
				DeleteInfo();
				break;
			case '4':					//修改信息
				ChangeInfo();
				break;
			case '5':					//查看通讯录
				CreatStruct();
				break;
			default:
				printf("输入错误，请重新输入：\n");
				break;
		}
	}
}

char Input()
{
	char i;
	printf("\n\t\t**********通讯录管理系统**********\n");  //输出界面，使使用人更加清楚、明白 
	printf("\t\t┌-------------------------------┐\n");
	printf("\t\t│        1.添加信息             │\n");
	printf("\t\t│        2.查询信息             │\n");
	printf("\t\t│        3.删除信息             │\n");
	printf("\t\t│        4.修改信息             │\n");
	printf("\t\t│        5.查看通讯录           │\n");
	printf("\t\t│        0.退出                 │\n");
	printf("\t\t└-------------------------------┘\n");
	printf("\t\t请输入0-5以选择服务：\n");
	while(1)
	{
		i=Getchar();
		if(i=='0'||i=='1'||i=='2'||i=='3'||i=='4'||i=='5')   //判断输入是否符合规范 
			return i;
		else
			printf("输入错误！\n");
	}
}

void SumCount()        //此函数的作用是计算出count的值 ，count代表的是当前通讯录中的联系人的数量 
{
	int i,res=0;
	if((fp=fopen("通讯录.txt","r"))==NULL)   //判断文件是否能打开 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(i=0;i<N&&!feof(fp);i++)			//当读到文件末尾时，停止读取 
	{
		res=fscanf(fp,"%d\t%s\t%s\t%s",&person[i].num,person[i].name,person[i].work,person[i].tel); 		//将联系人信息写入结构体中 
		if(res==EOF)
			break;
	}
	count=i;
	fclose(fp);		//关闭文件 
}

char Getchar()		//当输入某个字符时，系统有时会将回车键误认为输入，所以此函数的作用是消除回车键对输入字符的影响
{
	char c,z;
	int flag=1;
	while((c=getchar())!='\n'||flag==1)
	{
		z=c;
		flag=0;
	}
	return z;
}

void TiShi()		//此函数的作用是提示使用人返回主界面
{
	printf("输入b返回主界面....\n");
	char tip;
	while(1)
	{
		tip=Getchar();
		if(tip=='b')		//判断输入的字符是否符合要求 
			return;
		else
			printf("输入错误！\n");
	}
}

void Tips(int n)		//此函数的作用是在“查看通讯录 ”时，提示使用人有多少个联系人 
{
	printf("当前共有%d个联系人，按b返回.\n",n);
	char tip;
	while(1)
	{
		tip=Getchar();
		if(tip=='b')			//判断输入是否符合要求 
			return;
		else
			printf("输入错误！\n");
	}
}

void AddInfo()		//此函数的作用是添加联系人 
{
	char key='y';
	int k,t;
	while(key!='n'&&key!='N')		//用key判断是否继续添加联系人
	{
		person[count].num=person[count-1].num+1;		//使新添联系人的序号比前一位大1 
		list *p;		//运用指针，使程序更高效 
		p=person+count;		 
		while(1)		// 输入新建联系人的信息 
		{
			printf("请输入要添加的联系人姓名：");
			scanf("%s",p->name);
			printf("请输入要添加的联系人的职业：");
			scanf("%s",p->work);
			printf("请输入要添加的联系人的手机号：");
			scanf("%s",p->tel);
			printf("a键确认,其他键重新输入\n");		//此条语句的作用是确认一下信息是否输入正确，否则重新输入 
			if(Getchar() == 'a')
				break;
		}
		do
		{
			k=0;
			if(strlen(p->tel)!=11)		//判断手机号码是否符合格式，否则重新输入 
			{					
				k=1;
				printf("您输入的手机号码格式不存在,请重新输入:");
				scanf("%s",p->tel);
			}
			else 
			{
				for(t=0;t<11;t++)
				{
					if(person[count].tel[t]<'0'||person[count].tel[t]>'9')	//判断输入的手机号码中是否有不合规范的字符 
					{
						k=1;
						printf("您输入的手机号码格式不合理,请重新输入:");
						scanf("%s",p->tel);
						break;
					}
				}
			}
		}while(k);
		if((fp=fopen("通讯录.txt","a"))==NULL)		//判断文件是否能够打开 
		{
			printf("cannot open file!\n");
			exit(0);
		}
		fseek(fp,count*sizeof(list),0);		//将文件的指针指向文件末尾，从而将新建联系人写入文件 
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[count].num,person[count].name,person[count].work,person[count].tel);
		rewind(fp);		//将文件指针重新返回文件的开头 
		fclose(fp);		//关闭文件 
		count+=1;		//每添加一次 联系人的数量加一
		printf("是否继续添加?(Y/N)");		//判断是否继续新建联系人 
		key=Getchar();
	}
	TiShi();
}

void FindInfo()		//此函数的作用是查询联系人信息 
{
	char key='y';
	int m,k,i;
	while(key!='n'&&key!='N')		//用key判断是否继续运行 
	{
		printf("\n\t\t*************查询方式*************\n");		//输出界面，让使用人更清楚、明白接下来需要干什么 
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│          1.查找姓名           │\n");
		printf("\t\t│          2.查找手机号         │\n");
		printf("\t\t│          3.返回               │\n");
		printf("\t\t└-------------------------------┘\n");
		char i;
		while(1)
		{
			while(1)		//输入查询方式，并检查是否符合规范 
			{
				printf("请选择查询方式:");
				i=Getchar();
				printf("a键确认,其他键重新输入\n");
				if(Getchar() == 'a')
					break;
			}
			if(i=='1'||i=='2'||i=='3')
			{
				break;	
			}
			else
				printf("输入错误！\n");
		}
		if(i=='1')		//用 姓名 查找联系人信息 
		{
			char nm[20];
			do
			{
				k=1;
				while(1)
				{
					printf("请输入您要查询的联系人:");
					scanf("%s",nm);
					printf("a键确认,q键返回主界面,其他键重新输入\n");	//使用人若输入错误，还有更改的机会 
					char w=Getchar();
					if(w=='q')		 //如果使用人不想继续查询，或者没有要查询的联系人，输入q返回主界面
						return;
					if(w == 'a')
						break;
				}
				for(i=0;i<count;i++)		//判断所查联系人是否存在 
				{
					if(strcmp(nm,person[i].name)==0)
					{
						k=0;
						break;		
					}
				}
				if(k==1)
					printf("该联系人不存在，");
			}while(k);
			printf("职业:%s\n",person[i].work);		//若存在输出其信息 
			printf("电话:%s\n",person[i].tel);
		}
		if(i=='2')		//用 手机号 查找联系人 
		{
			char te[20];
			do
			{
				k=1;
				while(1)
				{
					printf("请输入您要查询的手机号码:");
					scanf("%s",te);
					printf("a键确认,q键返回主界面,其他键重新输入\n");		//使用人若输入错误，还有更改的机会
					char w=Getchar();
					if(w=='q')			//如果使用人不想继续查询，或者没有要查询的联系人，输入q返回主界面
						return;
					if(w == 'a')
						break;
				}
				for(i=0;i<count;i++)		//判断所查手机号是否存在 
				{
					if(strcmp(te,person[i].tel)==0)
					{
						k=0;
						break;
					}
				}
				if(k==1)
					printf("该手机号不存在，");
			}while(k);
			printf("姓名:%s\n",person[i].name);		//若存在输出其信息 
			printf("职业:%s\n",person[i].work);
		}
		if(i=='3')		//返回主界面 
			return;
		printf("是否继续查询?(Y/N)");
		key=Getchar();
	}
	TiShi();		//输出提示信息 
}

void DeleteInfo()		//此函数的作用是删除联系人信息 
{
	char nm[20];
	char key='y';
	while(key!='n'&&key!='N')		//用key判断是否继续运行
	{
		int i,j,k;
		do
		{
			k=1;
			while(1)
			{
				printf("请输入您要删除的联系人姓名:");
				scanf("%s",nm);
				printf("a键确认,q键返回主界面,其他键重新输入\n");	//若使用人回心转意，可以输入q返回主界面 
				char w=Getchar();
				if(w=='q')
					return;
				if(w=='a')
					break;
			}
			for(i=0;i<count;i++)
			{
				if(strcmp(nm,person[i].name)==0)	//判断联系人是否存在
				{
					k=0;
					break;
				}
			}
			if(k==1)
				printf("该联系人不存在,");
		}while(k);
		if((fp=fopen("通讯录.txt","w"))==NULL)	//判断文件是否能打开
		{
			printf("cannot open file!\n");
			exit(0);
		}
		for(j=0;j<count;j++)
		{
			if(j!=i)
				fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);	//将指定联系人删除后的信息写入文件 
		}
		rewind(fp);		//将文件指针移到文件开头 
		fclose(fp);		//关闭文件
		printf("该联系人已删除!\n");
		printf("是否继续删除?(Y/N)");	//是否继续 
		key=Getchar();
	}
	TiShi();
}

void ChangeInfo()	//此函数的作用是修改联系人信息 
{
	char key='y';
	while(key!='n'&&key!='N')	//用key判断是否继续 
	{
		printf("\t\t┌-------------------------------┐\n");	//使界面更加友好 
		printf("\t\t│       1.姓名                  │\n");
		printf("\t\t│       2.职业                  │\n");
		printf("\t\t│       3.手机号                │\n");
		printf("\t\t│       4.返回                  │\n");
		printf("\t\t└-------------------------------┘\n");
		int k;
		char i;
		while(1)
		{
			while(1)
			{
				printf("请输入您要修改的内容的编号:");
				i=Getchar();
				printf("a键确认,q键返回主界面,其他键重新输入\n");	//若使用人回心转意，可以输入q返回主界面 
				char w=Getchar();
				if(w=='q')
					return;
				if(w=='a')
					break;
			}
			if(i=='1'||i=='2'||i=='3'||i=='4')		//判断输入字符是否符合规范 
				break;	
			else
				printf("输入错误！\n");
		}
		if(i=='1')
			ChangeName();		//修改名字 
		if(i=='2')
			ChangeWork();		//修改工作 
		if(i=='3')
			ChangeTell();		//修改电话 
		if(i=='4')				//返回主界面 
			return;
		printf("是否继续修改?(Y/N)");
		key=Getchar();
	}
}

void ChangeName()		//此函数的作用是修改联系人的名字 
{
	char nm[20],nam[20];
	int i,j,k;
	do
	{
		k=1;
		while(1)
		{
			printf("请输入您想修改信息的联系人的姓名:");
			scanf("%s",nm);
			printf("a键确认,q键返回主界面,其他键重新输入\n");	//再次确认是否继续修改 
			char w=Getchar();
			if(w=='q')
				return;
			if(w=='a')
				break;
		}
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//判断输入的联系人是否存在 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("该联系人不存在，");
	}while(k);
	while(1)
	{
		printf("请输入更改之后的联系人的姓名:");
		scanf("%s",nam);
		printf("a键确认,q键返回主界面,其他键重新输入\n");		//再次确认信息 
		char w=Getchar();
		if(w=='q')
			return;
		if(w=='a')
			break;
	}
	for(i=0;i<count;i++)
	{
		if(strcmp(nm,person[i].name)==0)
		{
			for(j=0;j<strlen(nam);j++)
			{		
				person[i].name[j]=nam[j];		//找到所要修改的联系人，并修改信息 
			}
		}
	}
	if((fp=fopen("通讯录.txt","w"))==NULL)		//判断文件是否能打开 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel); //将修改之后的联系人信息写入文件 
	}
	fclose(fp);		//关闭文件 
}

void ChangeWork()	//此函数的作用是修改联系人的工作 
{
	char nm[20]; 
	char nam[20];
	int i,j,k;
	do
	{
		k=1;
		while(1)
		{
			printf("请输入您想修改信息的联系人的姓名:");
			scanf("%s",nm);
			printf("a键确认,q键返回主界面,其他键重新输入\n");	//再次确认信息 
			char w=Getchar();
			if(w=='q')
				return;
			if(w=='a')
				break;
		}
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//判断所要修改的联系人是否存在 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("该联系人不存在,");
	}while(k);
	while(1)
	{
		printf("请输入更改之后的联系人职业：");
		scanf("%s",nam);
		printf("a键确认,q键返回主界面,其他键重新输入\n");	//再次确认 
		char w=Getchar();
		if(w=='q')
			return;
		if(w== 'a')
			break;
	}
	for(i=0;i<count;i++)
	{
		if(strcmp(nm,person[i].name)==0)
		{
			for(j=0;j<strlen(nam);j++)
			{
				person[i].work[j]=nam[j];		//找到所要修改的联系人，并修改 
			}
		}
	}
	if((fp=fopen("通讯录.txt","w"))==NULL)		//判断文件是否能够打开 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);	//将修改之后的联系人信息重新写入文件 
	}
	fclose(fp);		//关闭文件 
}

void ChangeTell()		//此函数的作用是更改联系人的电话号码 
{
	char nm[20],nam[20];
	int i,j,k;
	do
	{
		while(1)
		{
			printf("请输入您想修改信息的联系人的姓名:");
			scanf("%s",nm);
			printf("a键确认,q键返回主界面,其他键重新输入\n");	//再次确认是否继续 
			char w=Getchar();
			if(w=='q')
				return;
			if(w == 'a')
				break;
		}
		k=1;
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//判断所要修改的联系人是否存在 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("该联系人不存在,");
	}while(k);
	while(1)
	{
		printf("请输入更改之后的联系人手机号：");
		scanf("%s",nam);
		printf("a键确认,q键返回主界面,其他键重新输入\n");		//再次确认 
		char w=Getchar();
		if(w=='q')
			return;
		if(w == 'a')
			break;
	}
	for(i=0;i<count;i++)
	{
		if(strcmp(nm,person[i].name)==0)
		{
			for(j=0;j<strlen(nam);j++)
			{
				person[i].tel[j]=nam[j];		//找到所要修改的联系人，并修改信息 
			}
			
		}
	}
	if((fp=fopen("通讯录.txt","w"))==NULL)		//判断文件是否能够打开 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);		//将修改之后的信息重新写入文件 
	}
	fclose(fp);		//关闭文件 
}

void CreatStruct()		//此函数的作用是输出通讯录列表 
{
	int i,res=0;
	if((fp=fopen("通讯录.txt","r"))==NULL)		//判断文件是否能够打开 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(i=0;i<N&&!feof(fp);i++)		//判断是否到了文件的末尾 
	{
		res=fscanf(fp,"%d\t%s\t%s\t%s",&person[i].num,person[i].name,person[i].work,person[i].tel);	//将文件内的数据赋给结构体 
		if(res==EOF)
			break;
	}
	count=i;
	printf("\n************************通讯录列表************************\n");		//使界面更友好 
	printf("序号\t名字\t职业\t电话\n");
	printf("-----------------------------------------------------------\n");
	for(i=0;i<count;i++)
		printf("%d\t%s\t%s\t%s\n",person[i].num,person[i].name,person[i].work,person[i].tel);	//将文件内的信息输出到屏幕上
	fclose(fp);		//关闭文件 
	Tips(count);	//输出提示信息 
}
