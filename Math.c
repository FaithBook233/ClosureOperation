#include<stdio.h>
#include<windows.h>
#define WIDTH 104	//控制台一行可容纳的字符数 
#define LIMIT 9		//矩阵最大行（列）数 

/***********  全局函数 ***********/ 
int i,j,k,n;	//i,j,k用来控制循环，n为矩阵的行（列）数 
//array数组为原矩阵，answer数组存储运算答案 
int array[LIMIT][LIMIT],answer[LIMIT][LIMIT];

/*************   函数声明    ***************/

//以下各个函数在函数定义处有详细解释 
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
/*************    主函数    ****************/
/*******************************************/

int main()
{
	//主界面循环函数及相关运算 
	Start_Contents();
	return 0;
}

/************************************/
/*********     界面函数     *********/ 
/************************************/ 

//居中打印 
void Center_Print(char str[])
{ 
	int blank = (WIDTH - strlen(str))/2;
	while(blank--)
		printf(" ");
	printf("%s\n",str);
} 
//目录打印 
void Contents_Print(void)
{
	printf("\n\n");
	Center_Print("*            *");
	Center_Print("*          *");
	Center_Print("****************");
	Center_Print("*     0    0     *");
	Center_Print("*   闭包运算   *");
	Center_Print("****************");
	Center_Print("****");
	Center_Print("*********************");
	Center_Print("**  1    自反性      **");
	Center_Print("***                   ***");
	Center_Print("*  *  2    对称性      *  *");
	Center_Print("*   *                   *   *");
	Center_Print("*  *  3    传递性      *  *");
	Center_Print("* *                   * *");
	Center_Print("**  4  warshall算法  **");
	Center_Print("*                   *");
	Center_Print("** 0  重写原矩阵   **");
	Center_Print("*******************");
	Center_Print("***         ***");
	Center_Print("***         ***");
	Center_Print("****         ****");
}

//打开程序可见的界面 
void Start_Contents(void)
{
	system("cls");
	Contents_Print();
	Input();
	Kb_Hit();
}
//目录界面 
void Contents(void)
{ 
	system("cls");
	Contents_Print();
	Kb_Hit();
}

//标题打印 
void Temp(char str[])	//标题打印 
{
	system("cls");
	printf("\n\n");
	Center_Print(str);
}

//格式函数

void Func(char str_1[],char str_2[])
{
	//每个功能整体界面都是下面的格式
	 
	Temp(str_1);//标题 
	Output_Array();//输出原矩阵 
	Output_Answer(str_2); //输出答案矩阵 
	Pause();//按回车继续 
	Contents();//回到主界面 
 } 

/*******************************/
/*********  按键函数  **********/
/*******************************/

//功能响应 
void Kb_Hit(void)
{
	while(1)
	{
		if(kbhit())	//若有按键按下 
		{
			Reset(); 	//重置answer数组 
			switch(getch())
			{
				//实现相应功能 
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

//回车继续

void Pause()
{
//按 Enter 键继续，其他按键无响应 
	printf("\n\n");
	Center_Print("按 Enter 继续"); 
	while(1)
		if(kbhit())
			if(getch() == 13)//数字13对应回车键 
				break;
	
} 

/***************************************/
/************   功能函数   *************/
/***************************************/

//原矩阵输入函数，让array接收输入的信息 
void Input(void)
{
	i= 0; 
	//确保输入的矩阵行（列）数 为 1-9 
	do{
		if(i++ > 0)	printf("\n请输入数字：1-9 ！！\n");
		printf("请输入原矩阵的行（列）数：  "); 
		scanf("%d",&n);
	}while(n>LIMIT||n < 1);
	system("cls");
	printf("请输入原矩阵的行（列）数：  %d\n\n",n);
	//原矩阵的输入 
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
		{
			printf("[%d]行[%d]列的数:   ",i+1,j+1); 
			scanf("%d",&array[i][j]);
		}
	Contents();//回到主界面 
}

//输出原矩阵 
void Output_Array()	//输出原矩阵 
{
	printf("\n\n");
	Center_Print("--------------------------------------------------");	
	printf("\n");
	Center_Print("* 原矩阵 *");
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
//输出答案矩阵 
void Output_Answer(char str[])	//输出最终矩阵 
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
/************     闭包运算函数    ***********/ 
/********************************************/ 

//重置answer矩阵 
void Reset(void)
{
	/*因为answer矩阵在实现各个功能的时候
	存的数据不一样，为了不互相影响，
	在实现各个功能之前让answer矩阵恢复到
	和array矩阵一样的状态再进行相关操作 */
	
	for(i = 0;i < n; i++)
		for(j = 0;j < n;j++)
			answer[i][j] = array[i][j];	
} 
//自反闭包 
void Func_A(void)
{
	//自反闭包运算 
	for(i = 0;i < n;i++)
	{
		answer[i][i] = 1;
	}
	//打印界面
	Func("* 自反性 *","* 自反闭包运算 *"); 
} 
//对称闭包 
void Func_B(void)
{
	//对称闭包运算 
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n ;j++)
		{
			if(array[i][j] == 1) answer[j][i] = 1;
		}
	}
	//打印界面 
	Func("* 对称性 *","* 对称闭包运算 *"); 
}
//传递闭包 
void Func_C(void)
{
	//传递闭包运算 
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
	//打印界面 
	Func("* 传递性 *","* 传递闭包运算 *"); 
}

//warshall 算法 
void Func_D(void)
{
	//warshall算法的相关运算 
	/*
		answer开始为原矩阵array
		当answer[i][j] = 1 的时候，
		将answer数组中第i行所有的元素
		与第j行对应元素分别进行逻辑加 ，
		并将所得的值覆盖第i行的元素 
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
	//打印界面 
	Func("* warshall *","* warshall算法 *"); 
} 
