#include<stdio.h>
#include<windows.h>
#define WIDTH 104	//����̨һ�п����ɵ��ַ��� 
#define LIMIT 9		//��������У��У��� 

/***********  ȫ�ֺ��� ***********/ 
int i,j,k,n;	//i,j,k��������ѭ����nΪ������У��У��� 
//array����Ϊԭ����answer����洢����� 
int array[LIMIT][LIMIT],answer[LIMIT][LIMIT];

/*************   ��������    ***************/

//���¸��������ں������崦����ϸ���� 
void Center_Print(char str[]);
void Contents_Print(void);
void Kb_Hit(void);
void Start_Contents(void);
void Contents(void);
void Pause(void);
void Temp(char str[]); 
void Func(char str_1[],char str_2[]); 
void Func_A(void);
void Func_B(void);
void Func_C(void);
void Func_D(void);
void Reset(void); 
void Input(void);
void Output_Array(void);
void Output_Answer(char str[]);
/*******************************************/
/*************    ������    ****************/
/*******************************************/

int main()
{
	//������ѭ��������������� 
	Start_Contents();
	return 0;
}

/************************************/
/*********     ���溯��     *********/ 
/************************************/ 

//���д�ӡ 
void Center_Print(char str[])
{ 
	int blank = (WIDTH - strlen(str))/2;
	while(blank--)
		printf(" ");
	printf("%s\n",str);
} 
//Ŀ¼��ӡ 
void Contents_Print(void)
{
	printf("\n\n");
	Center_Print("*            *");
	Center_Print("*          *");
	Center_Print("****************");
	Center_Print("*     0    0     *");
	Center_Print("*   �հ�����   *");
	Center_Print("****************");
	Center_Print("****");
	Center_Print("*********************");
	Center_Print("**  1    �Է���      **");
	Center_Print("***                   ***");
	Center_Print("*  *  2    �Գ���      *  *");
	Center_Print("*   *                   *   *");
	Center_Print("*  *  3    ������      *  *");
	Center_Print("* *                   * *");
	Center_Print("**  4  warshall�㷨  **");
	Center_Print("*                   *");
	Center_Print("** 0  ��дԭ����   **");
	Center_Print("*******************");
	Center_Print("***         ***");
	Center_Print("***         ***");
	Center_Print("****         ****");
}

//�򿪳���ɼ��Ľ��� 
void Start_Contents(void)
{
	system("cls");
	Contents_Print();
	Input();
	Kb_Hit();
}
//Ŀ¼���� 
void Contents(void)
{ 
	system("cls");
	Contents_Print();
	Kb_Hit();
}

//�����ӡ 
void Temp(char str[])	//�����ӡ 
{
	system("cls");
	printf("\n\n");
	Center_Print(str);
}

//��ʽ����

void Func(char str_1[],char str_2[])
{
	//ÿ������������涼������ĸ�ʽ
	 
	Temp(str_1);//���� 
	Output_Array();//���ԭ���� 
	Output_Answer(str_2); //����𰸾��� 
	Pause();//���س����� 
	Contents();//�ص������� 
 } 

/*******************************/
/*********  ��������  **********/
/*******************************/

//������Ӧ 
void Kb_Hit(void)
{
	while(1)
	{
		if(kbhit())	//���а������� 
		{
			Reset(); 	//����answer���� 
			switch(getch())
			{
				//ʵ����Ӧ���� 
				case '0':Input();break;
				case '1':Func_A();break;
				case '2':Func_B();break;
				case '3':Func_C();break;
				case '4':Func_D();break;
				default:continue;
			}
		}	
	} 
} 

//�س�����

void Pause()
{
//�� Enter ��������������������Ӧ 
	printf("\n\n");
	Center_Print("�� Enter ����"); 
	while(1)
		if(kbhit())
			if(getch() == 13)//����13��Ӧ�س��� 
				break;
	
} 

/***************************************/
/************   ���ܺ���   *************/
/***************************************/

//ԭ�������뺯������array�����������Ϣ 
void Input(void)
{
	i= 0; 
	//ȷ������ľ����У��У��� Ϊ 1-9 
	do{
		if(i++ > 0)	printf("\n���������֣�1-9 ����\n");
		printf("������ԭ������У��У�����  "); 
		scanf("%d",&n);
	}while(n>LIMIT||n < 1);
	system("cls");
	printf("������ԭ������У��У�����  %d\n\n",n);
	//ԭ��������� 
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
		{
			printf("[%d]��[%d]�е���:   ",i+1,j+1); 
			scanf("%d",&array[i][j]);
		}
	Contents();//�ص������� 
}

//���ԭ���� 
void Output_Array()	//���ԭ���� 
{
	printf("\n\n");
	Center_Print("--------------------------------------------------");	
	printf("\n");
	Center_Print("* ԭ���� *");
	printf("\n");
	for(i = 0;i < n;i++)
	{
		int blank =(WIDTH - 3*n)/2+1;
		while(blank--)
			printf(" ");
		for(j = 0;j < n;j++)
		{
			printf("%-3d",array[i][j]); 
		}
		printf("\n");
	}
}
//����𰸾��� 
void Output_Answer(char str[])	//������վ��� 
{
	printf("\n\n");
	Center_Print("--------------------------------------------------");		
	printf("\n");
	Center_Print(str);
	printf("\n");
	for(i = 0;i < n;i++)
	{
		int blank =(WIDTH - 3*n)/2+1;
		while(blank--)
			printf(" ");
		for(j = 0;j < n;j++)
		{
			printf("%-3d",answer[i][j]); 
		}
		printf("\n");
	}
}

/********************************************/
/************     �հ����㺯��    ***********/ 
/********************************************/ 

//����answer���� 
void Reset(void)
{
	/*��Ϊanswer������ʵ�ָ������ܵ�ʱ��
	������ݲ�һ����Ϊ�˲�����Ӱ�죬
	��ʵ�ָ�������֮ǰ��answer����ָ���
	��array����һ����״̬�ٽ�����ز��� */
	
	for(i = 0;i < n; i++)
		for(j = 0;j < n;j++)
			answer[i][j] = array[i][j];	
} 
//�Է��հ� 
void Func_A(void)
{
	//�Է��հ����� 
	for(i = 0;i < n;i++)
	{
		answer[i][i] = 1;
	}
	//��ӡ����
	Func("* �Է��� *","* �Է��հ����� *"); 
} 
//�ԳƱհ� 
void Func_B(void)
{
	//�ԳƱհ����� 
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n ;j++)
		{
			if(array[i][j] == 1) answer[j][i] = 1;
		}
	}
	//��ӡ���� 
	Func("* �Գ��� *","* �ԳƱհ����� *"); 
}
//���ݱհ� 
void Func_C(void)
{
	//���ݱհ����� 
	for(j = 0;j < n; j++)
	{
		for(i = 0;i < n;i++)
		{
			if(answer[i][j] == 1)
			{
				for(k = 0;k < n;k++)
				{
					if(answer[j][k] == 1)
						answer[i][k] = 1;
				}		
			}		
		}	
	}
	//��ӡ���� 
	Func("* ������ *","* ���ݱհ����� *"); 
}

//warshall �㷨 
void Func_D(void)
{
	//warshall�㷨��������� 
	/*
		answer��ʼΪԭ����array
		��answer[i][j] = 1 ��ʱ��
		��answer�����е�i�����е�Ԫ��
		���j�ж�ӦԪ�طֱ�����߼��� ��
		�������õ�ֵ���ǵ�i�е�Ԫ�� 
	*/ 
	for(j = 0;j < n; j++)
	{
		for(i = 0;i < n;i++)
		{
			if(answer[i][j] == 1)
			{
				for(k = 0;k < n;k++)
				{
					answer[i][k] = answer[i][k]+answer[j][k];
					if(answer[i][k] > 1)answer[i][k] = 1;		
				}		
			}		
		}	
	}
	//��ӡ���� 
	Func("* warshall *","* warshall�㷨 *"); 
} 
