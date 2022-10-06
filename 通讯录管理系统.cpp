#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100	//�����޸Ľṹ��Ĵ�С 

FILE *fp;	//�����ļ�ָ�� 

int count=0;	//����һ��count��count����ͨѶ¼����ϵ�˵����� 

struct node		//����һ���ṹ�� 
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
			case '0':					//�˳�
				return 0;
				break;
			case '1':                 //�����Ϣ
				AddInfo();
				break;
			case '2':					//��ѯ��Ϣ 
				FindInfo();
				break;
			case '3':					//ɾ����Ϣ 
				DeleteInfo();
				break;
			case '4':					//�޸���Ϣ
				ChangeInfo();
				break;
			case '5':					//�鿴ͨѶ¼
				CreatStruct();
				break;
			default:
				printf("����������������룺\n");
				break;
		}
	}
}

char Input()
{
	char i;
	printf("\n\t\t**********ͨѶ¼����ϵͳ**********\n");  //������棬ʹʹ���˸������������ 
	printf("\t\t��-------------------------------��\n");
	printf("\t\t��        1.�����Ϣ             ��\n");
	printf("\t\t��        2.��ѯ��Ϣ             ��\n");
	printf("\t\t��        3.ɾ����Ϣ             ��\n");
	printf("\t\t��        4.�޸���Ϣ             ��\n");
	printf("\t\t��        5.�鿴ͨѶ¼           ��\n");
	printf("\t\t��        0.�˳�                 ��\n");
	printf("\t\t��-------------------------------��\n");
	printf("\t\t������0-5��ѡ�����\n");
	while(1)
	{
		i=Getchar();
		if(i=='0'||i=='1'||i=='2'||i=='3'||i=='4'||i=='5')   //�ж������Ƿ���Ϲ淶 
			return i;
		else
			printf("�������\n");
	}
}

void SumCount()        //�˺����������Ǽ����count��ֵ ��count������ǵ�ǰͨѶ¼�е���ϵ�˵����� 
{
	int i,res=0;
	if((fp=fopen("ͨѶ¼.txt","r"))==NULL)   //�ж��ļ��Ƿ��ܴ� 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(i=0;i<N&&!feof(fp);i++)			//�������ļ�ĩβʱ��ֹͣ��ȡ 
	{
		res=fscanf(fp,"%d\t%s\t%s\t%s",&person[i].num,person[i].name,person[i].work,person[i].tel); 		//����ϵ����Ϣд��ṹ���� 
		if(res==EOF)
			break;
	}
	count=i;
	fclose(fp);		//�ر��ļ� 
}

char Getchar()		//������ĳ���ַ�ʱ��ϵͳ��ʱ�Ὣ�س�������Ϊ���룬���Դ˺����������������س����������ַ���Ӱ��
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

void TiShi()		//�˺�������������ʾʹ���˷���������
{
	printf("����b����������....\n");
	char tip;
	while(1)
	{
		tip=Getchar();
		if(tip=='b')		//�ж�������ַ��Ƿ����Ҫ�� 
			return;
		else
			printf("�������\n");
	}
}

void Tips(int n)		//�˺������������ڡ��鿴ͨѶ¼ ��ʱ����ʾʹ�����ж��ٸ���ϵ�� 
{
	printf("��ǰ����%d����ϵ�ˣ���b����.\n",n);
	char tip;
	while(1)
	{
		tip=Getchar();
		if(tip=='b')			//�ж������Ƿ����Ҫ�� 
			return;
		else
			printf("�������\n");
	}
}

void AddInfo()		//�˺����������������ϵ�� 
{
	char key='y';
	int k,t;
	while(key!='n'&&key!='N')		//��key�ж��Ƿ���������ϵ��
	{
		person[count].num=person[count-1].num+1;		//ʹ������ϵ�˵���ű�ǰһλ��1 
		list *p;		//����ָ�룬ʹ�������Ч 
		p=person+count;		 
		while(1)		// �����½���ϵ�˵���Ϣ 
		{
			printf("������Ҫ��ӵ���ϵ��������");
			scanf("%s",p->name);
			printf("������Ҫ��ӵ���ϵ�˵�ְҵ��");
			scanf("%s",p->work);
			printf("������Ҫ��ӵ���ϵ�˵��ֻ��ţ�");
			scanf("%s",p->tel);
			printf("a��ȷ��,��������������\n");		//��������������ȷ��һ����Ϣ�Ƿ�������ȷ�������������� 
			if(Getchar() == 'a')
				break;
		}
		do
		{
			k=0;
			if(strlen(p->tel)!=11)		//�ж��ֻ������Ƿ���ϸ�ʽ�������������� 
			{					
				k=1;
				printf("��������ֻ������ʽ������,����������:");
				scanf("%s",p->tel);
			}
			else 
			{
				for(t=0;t<11;t++)
				{
					if(person[count].tel[t]<'0'||person[count].tel[t]>'9')	//�ж�������ֻ��������Ƿ��в��Ϲ淶���ַ� 
					{
						k=1;
						printf("��������ֻ������ʽ������,����������:");
						scanf("%s",p->tel);
						break;
					}
				}
			}
		}while(k);
		if((fp=fopen("ͨѶ¼.txt","a"))==NULL)		//�ж��ļ��Ƿ��ܹ��� 
		{
			printf("cannot open file!\n");
			exit(0);
		}
		fseek(fp,count*sizeof(list),0);		//���ļ���ָ��ָ���ļ�ĩβ���Ӷ����½���ϵ��д���ļ� 
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[count].num,person[count].name,person[count].work,person[count].tel);
		rewind(fp);		//���ļ�ָ�����·����ļ��Ŀ�ͷ 
		fclose(fp);		//�ر��ļ� 
		count+=1;		//ÿ���һ�� ��ϵ�˵�������һ
		printf("�Ƿ�������?(Y/N)");		//�ж��Ƿ�����½���ϵ�� 
		key=Getchar();
	}
	TiShi();
}

void FindInfo()		//�˺����������ǲ�ѯ��ϵ����Ϣ 
{
	char key='y';
	int m,k,i;
	while(key!='n'&&key!='N')		//��key�ж��Ƿ�������� 
	{
		printf("\n\t\t*************��ѯ��ʽ*************\n");		//������棬��ʹ���˸���������׽�������Ҫ��ʲô 
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��          1.��������           ��\n");
		printf("\t\t��          2.�����ֻ���         ��\n");
		printf("\t\t��          3.����               ��\n");
		printf("\t\t��-------------------------------��\n");
		char i;
		while(1)
		{
			while(1)		//�����ѯ��ʽ��������Ƿ���Ϲ淶 
			{
				printf("��ѡ���ѯ��ʽ:");
				i=Getchar();
				printf("a��ȷ��,��������������\n");
				if(Getchar() == 'a')
					break;
			}
			if(i=='1'||i=='2'||i=='3')
			{
				break;	
			}
			else
				printf("�������\n");
		}
		if(i=='1')		//�� ���� ������ϵ����Ϣ 
		{
			char nm[20];
			do
			{
				k=1;
				while(1)
				{
					printf("��������Ҫ��ѯ����ϵ��:");
					scanf("%s",nm);
					printf("a��ȷ��,q������������,��������������\n");	//ʹ������������󣬻��и��ĵĻ��� 
					char w=Getchar();
					if(w=='q')		 //���ʹ���˲��������ѯ������û��Ҫ��ѯ����ϵ�ˣ�����q����������
						return;
					if(w == 'a')
						break;
				}
				for(i=0;i<count;i++)		//�ж�������ϵ���Ƿ���� 
				{
					if(strcmp(nm,person[i].name)==0)
					{
						k=0;
						break;		
					}
				}
				if(k==1)
					printf("����ϵ�˲����ڣ�");
			}while(k);
			printf("ְҵ:%s\n",person[i].work);		//�������������Ϣ 
			printf("�绰:%s\n",person[i].tel);
		}
		if(i=='2')		//�� �ֻ��� ������ϵ�� 
		{
			char te[20];
			do
			{
				k=1;
				while(1)
				{
					printf("��������Ҫ��ѯ���ֻ�����:");
					scanf("%s",te);
					printf("a��ȷ��,q������������,��������������\n");		//ʹ������������󣬻��и��ĵĻ���
					char w=Getchar();
					if(w=='q')			//���ʹ���˲��������ѯ������û��Ҫ��ѯ����ϵ�ˣ�����q����������
						return;
					if(w == 'a')
						break;
				}
				for(i=0;i<count;i++)		//�ж������ֻ����Ƿ���� 
				{
					if(strcmp(te,person[i].tel)==0)
					{
						k=0;
						break;
					}
				}
				if(k==1)
					printf("���ֻ��Ų����ڣ�");
			}while(k);
			printf("����:%s\n",person[i].name);		//�������������Ϣ 
			printf("ְҵ:%s\n",person[i].work);
		}
		if(i=='3')		//���������� 
			return;
		printf("�Ƿ������ѯ?(Y/N)");
		key=Getchar();
	}
	TiShi();		//�����ʾ��Ϣ 
}

void DeleteInfo()		//�˺�����������ɾ����ϵ����Ϣ 
{
	char nm[20];
	char key='y';
	while(key!='n'&&key!='N')		//��key�ж��Ƿ��������
	{
		int i,j,k;
		do
		{
			k=1;
			while(1)
			{
				printf("��������Ҫɾ������ϵ������:");
				scanf("%s",nm);
				printf("a��ȷ��,q������������,��������������\n");	//��ʹ���˻���ת�⣬��������q���������� 
				char w=Getchar();
				if(w=='q')
					return;
				if(w=='a')
					break;
			}
			for(i=0;i<count;i++)
			{
				if(strcmp(nm,person[i].name)==0)	//�ж���ϵ���Ƿ����
				{
					k=0;
					break;
				}
			}
			if(k==1)
				printf("����ϵ�˲�����,");
		}while(k);
		if((fp=fopen("ͨѶ¼.txt","w"))==NULL)	//�ж��ļ��Ƿ��ܴ�
		{
			printf("cannot open file!\n");
			exit(0);
		}
		for(j=0;j<count;j++)
		{
			if(j!=i)
				fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);	//��ָ����ϵ��ɾ�������Ϣд���ļ� 
		}
		rewind(fp);		//���ļ�ָ���Ƶ��ļ���ͷ 
		fclose(fp);		//�ر��ļ�
		printf("����ϵ����ɾ��!\n");
		printf("�Ƿ����ɾ��?(Y/N)");	//�Ƿ���� 
		key=Getchar();
	}
	TiShi();
}

void ChangeInfo()	//�˺������������޸���ϵ����Ϣ 
{
	char key='y';
	while(key!='n'&&key!='N')	//��key�ж��Ƿ���� 
	{
		printf("\t\t��-------------------------------��\n");	//ʹ��������Ѻ� 
		printf("\t\t��       1.����                  ��\n");
		printf("\t\t��       2.ְҵ                  ��\n");
		printf("\t\t��       3.�ֻ���                ��\n");
		printf("\t\t��       4.����                  ��\n");
		printf("\t\t��-------------------------------��\n");
		int k;
		char i;
		while(1)
		{
			while(1)
			{
				printf("��������Ҫ�޸ĵ����ݵı��:");
				i=Getchar();
				printf("a��ȷ��,q������������,��������������\n");	//��ʹ���˻���ת�⣬��������q���������� 
				char w=Getchar();
				if(w=='q')
					return;
				if(w=='a')
					break;
			}
			if(i=='1'||i=='2'||i=='3'||i=='4')		//�ж������ַ��Ƿ���Ϲ淶 
				break;	
			else
				printf("�������\n");
		}
		if(i=='1')
			ChangeName();		//�޸����� 
		if(i=='2')
			ChangeWork();		//�޸Ĺ��� 
		if(i=='3')
			ChangeTell();		//�޸ĵ绰 
		if(i=='4')				//���������� 
			return;
		printf("�Ƿ�����޸�?(Y/N)");
		key=Getchar();
	}
}

void ChangeName()		//�˺������������޸���ϵ�˵����� 
{
	char nm[20],nam[20];
	int i,j,k;
	do
	{
		k=1;
		while(1)
		{
			printf("�����������޸���Ϣ����ϵ�˵�����:");
			scanf("%s",nm);
			printf("a��ȷ��,q������������,��������������\n");	//�ٴ�ȷ���Ƿ�����޸� 
			char w=Getchar();
			if(w=='q')
				return;
			if(w=='a')
				break;
		}
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//�ж��������ϵ���Ƿ���� 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("����ϵ�˲����ڣ�");
	}while(k);
	while(1)
	{
		printf("���������֮�����ϵ�˵�����:");
		scanf("%s",nam);
		printf("a��ȷ��,q������������,��������������\n");		//�ٴ�ȷ����Ϣ 
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
				person[i].name[j]=nam[j];		//�ҵ���Ҫ�޸ĵ���ϵ�ˣ����޸���Ϣ 
			}
		}
	}
	if((fp=fopen("ͨѶ¼.txt","w"))==NULL)		//�ж��ļ��Ƿ��ܴ� 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel); //���޸�֮�����ϵ����Ϣд���ļ� 
	}
	fclose(fp);		//�ر��ļ� 
}

void ChangeWork()	//�˺������������޸���ϵ�˵Ĺ��� 
{
	char nm[20]; 
	char nam[20];
	int i,j,k;
	do
	{
		k=1;
		while(1)
		{
			printf("�����������޸���Ϣ����ϵ�˵�����:");
			scanf("%s",nm);
			printf("a��ȷ��,q������������,��������������\n");	//�ٴ�ȷ����Ϣ 
			char w=Getchar();
			if(w=='q')
				return;
			if(w=='a')
				break;
		}
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//�ж���Ҫ�޸ĵ���ϵ���Ƿ���� 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("����ϵ�˲�����,");
	}while(k);
	while(1)
	{
		printf("���������֮�����ϵ��ְҵ��");
		scanf("%s",nam);
		printf("a��ȷ��,q������������,��������������\n");	//�ٴ�ȷ�� 
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
				person[i].work[j]=nam[j];		//�ҵ���Ҫ�޸ĵ���ϵ�ˣ����޸� 
			}
		}
	}
	if((fp=fopen("ͨѶ¼.txt","w"))==NULL)		//�ж��ļ��Ƿ��ܹ��� 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);	//���޸�֮�����ϵ����Ϣ����д���ļ� 
	}
	fclose(fp);		//�ر��ļ� 
}

void ChangeTell()		//�˺����������Ǹ�����ϵ�˵ĵ绰���� 
{
	char nm[20],nam[20];
	int i,j,k;
	do
	{
		while(1)
		{
			printf("�����������޸���Ϣ����ϵ�˵�����:");
			scanf("%s",nm);
			printf("a��ȷ��,q������������,��������������\n");	//�ٴ�ȷ���Ƿ���� 
			char w=Getchar();
			if(w=='q')
				return;
			if(w == 'a')
				break;
		}
		k=1;
		for(i=0;i<count;i++)
		{
			if(strcmp(nm,person[i].name)==0)		//�ж���Ҫ�޸ĵ���ϵ���Ƿ���� 
			{
				k=0;
				break;		
			}
		}
		if(k==1)
			printf("����ϵ�˲�����,");
	}while(k);
	while(1)
	{
		printf("���������֮�����ϵ���ֻ��ţ�");
		scanf("%s",nam);
		printf("a��ȷ��,q������������,��������������\n");		//�ٴ�ȷ�� 
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
				person[i].tel[j]=nam[j];		//�ҵ���Ҫ�޸ĵ���ϵ�ˣ����޸���Ϣ 
			}
			
		}
	}
	if((fp=fopen("ͨѶ¼.txt","w"))==NULL)		//�ж��ļ��Ƿ��ܹ��� 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(j=0;j<count;j++)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\n",person[j].num,person[j].name,person[j].work,person[j].tel);		//���޸�֮�����Ϣ����д���ļ� 
	}
	fclose(fp);		//�ر��ļ� 
}

void CreatStruct()		//�˺��������������ͨѶ¼�б� 
{
	int i,res=0;
	if((fp=fopen("ͨѶ¼.txt","r"))==NULL)		//�ж��ļ��Ƿ��ܹ��� 
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for(i=0;i<N&&!feof(fp);i++)		//�ж��Ƿ����ļ���ĩβ 
	{
		res=fscanf(fp,"%d\t%s\t%s\t%s",&person[i].num,person[i].name,person[i].work,person[i].tel);	//���ļ��ڵ����ݸ����ṹ�� 
		if(res==EOF)
			break;
	}
	count=i;
	printf("\n************************ͨѶ¼�б�************************\n");		//ʹ������Ѻ� 
	printf("���\t����\tְҵ\t�绰\n");
	printf("-----------------------------------------------------------\n");
	for(i=0;i<count;i++)
		printf("%d\t%s\t%s\t%s\n",person[i].num,person[i].name,person[i].work,person[i].tel);	//���ļ��ڵ���Ϣ�������Ļ��
	fclose(fp);		//�ر��ļ� 
	Tips(count);	//�����ʾ��Ϣ 
}
