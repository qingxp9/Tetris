#include <windows.h>
#include <stdio.h>
#include <conio.h> 
#define Maxh 19
#define Maxw 14
int score=0,t;
int shudu;
int lshezi[5][5]={0};
int xialuohezi[5][5]={0};
int x,y,a;
int pan[Maxw+2][Maxh]={0}; 

int qige[7][5][5]=
{
 {
 {0,0,0,0,0},
 {0,0,0,0,0},
 {1,1,1,1,0},
 {0,0,0,0,0},
 {0,0,0,0,0}
 },
 {
 {0,0,0,0,0},
 {0,0,1,0,0},
 {0,1,1,1,0},
 {0,0,0,0,0},
 {0,0,0,0,0}
 },
 {
 {0,0,0,0,0},
 {0,1,1,0,0},
 {0,0,1,1,0},
 {0,0,0,0,0},
 {0,0,0,0,0}
 },
 {
 {0,0,0,0,0},
 {0,0,1,1,0},
 {0,1,1,0,0},
 {0,0,0,0,0},
 {0,0,0,0,0}
 },
 {
 {0,0,0,0,0},
 {0,1,1,0,0},
 {0,0,1,0,0},
 {0,0,1,0,0},
 {0,0,0,0,0}
 }, 
 {
 {0,0,0,0,0},
 {0,0,1,1,0},
 {0,0,1,0,0},
 {0,0,1,0,0},
 {0,0,0,0,0}
 },
 {
 {0,0,0,0,0},
 {0,0,1,1,0},
 {0,0,1,1,0},
 {0,0,0,0,0},
 {0,0,0,0,0}
 }
 }; 
 void show(void);//���ͼ�� 
void yidong(void);//�ƶ� 
 void setpan(void);//��������
 void nextfangkuai(void);//���ɷ��� 
 void setfangkuai(void);
 void jianpan(void);
 int ispz(int a);
 int isman(void);
 void rotate(void);
int clear(void) ;
int main(void)
{	 
printf("\n");
printf("\t\t\t�ַ�����˹���� ��ʽ��1.01");
printf("\n\t\t\t\t\t\t by yyf 2012.11.6");
printf("\n");

printf("\n"); 
printf("\n");
printf("\n");
printf("\n");
printf("\n---------������־-------------------------------------");
printf("\n�����0.8�汾�Ĳ���bug");
printf("\n������1.0�沿��δ���ǵ���� �ٶȽ������Ż�");
printf("\n");
printf("\n");
printf("\n");
printf("\n��Ϸ˵����ʹ�÷�������� ��Ϊ��ת ");
printf("\n�����������������ĸ����ͣ ˫��q�����¿�ʼ");
printf("\n");
printf("\n�����Ѷ�1-5 :") ;
while(!scanf("%d",&shudu)||shudu<0||shudu>5)
puts("�������Ѷ�1-5:");
t=shudu;
shudu=(6-shudu)*100;

start:
x=Maxw/2-2;y=0;  

setpan();//��������
nextfangkuai();//���������һ������ 

show();

   while(1)
   {
    x=Maxw/2-2;y=0;  
		while(1)      
        {            
         Sleep(shudu);
         while(kbhit())
		 jianpan(); //��ȡ����  û��ײ���ƶ� 
 
         if(ispz(80)==0){yidong();}  //û��ײ�������� 
         else
         {	   
         setfangkuai();	 
         while(clear());
		 break;  
         }
	    } 
        
     nextfangkuai();//���������һ������    
    if(isman())break; //�Ƿ��� 
    }
    fflush(stdin);
   	system("cls");
   	printf("\n\n\n");
    puts("you lose");
    puts("(������ر���Ϸ)") ;
   getchar();
   return 0;
   
}





void setpan(void)
{
for(int i=0;i<Maxw+2;i++) //�ײ� 
	{pan[i][Maxh-1]=1;}
	
	for(int j=0;j<Maxh-1;j++)      //���� 
	{pan[0][j]=1;pan[1][j]=1; pan[Maxw+1][j]=1;pan[Maxw][j]=1;}
}

void nextfangkuai(void)
{
 a=rand()%7;
 for(int i=0;i<5;i++)
 for(int j=0;j<5;j++)
 {lshezi[i][j]=qige[a][i][j];
 xialuohezi[i][j]=qige[a][i][j];
 }
} 

void setfangkuai(void)
{
	for(int i=0;i<5;i++)
 for(int j=0;j<5;j++)
 if(xialuohezi[i][j])
 pan[x+i][y+j]=xialuohezi[i][j];
}

void jianpan(void)
{
int shuru;
getch();
shuru=getch();

    if(shuru=='q')
    {
	x=Maxw/2-2;y=0;  
	for(int i=2;i<Maxw;i++)
	for(int j=0;j<Maxh-1;j++)
    pan[i][j]=0;
    show();
    }
    if(shuru==72&&ispz(shuru)==0)//��
	{
	  if(a!=6)
	  {
	  rotate();
	  show();
	  }
	}
	
	if(shuru==80&&ispz(shuru)==0)//�� 
	{
	y++;
	show();
	}
	if(shuru==75&&ispz(shuru)==0)//��
	{
	x--;
	show();
	}
	if(shuru==77&&ispz(shuru)==0)//��
	{
		int l;
		for(int i=4;i>=0;i--)
        for(int j=0;j<5;j++)
		if(lshezi[i][j])l=i;
	if(l+x<Maxw-1)		
	{x++;
	show();
	}
    }

}

void yidong(void)
{
	y++;
	show();
}

int ispz(int b) 
{   
     if(b==72)//�� 
     {
     	int box[5][5]; 
        
     	for(int i=0;i<5;i++) 
        for(int j=4;j>=0;j--) 
        box[i][j] = lshezi[j][4 - i]; //��ת�������box 
 
     	for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        if(pan[i+x][j+y]&&box[i][j])
        return 1;
        return 0;
     }
     
	if(b==80)//�� 
	{
	   for(int i=0;i<5;i++)
	   {
	   if(xialuohezi[i][4]+pan[x+i][y+5]==2)
	   return 1;
	   }
	   for(int i=0;i<5;i++)
	   for(int j=0;j<4;j++)
	   {if(xialuohezi[i][j]+xialuohezi[i][j+1]!=2&&xialuohezi[i][j]+pan[x+i][y+j+1]==2)
	   return 1;
	   }
	}
	if(b==75)//��
	{
	   for(int j=0;j<5;j++)
	   {if(xialuohezi[0][j]+pan[x-1][y+j]==2)
	   return 1;
	   }
	   
	   for(int i=1;i<5;i++)
	   for(int j=0;j<5;j++)
	   {if(xialuohezi[i][j]+xialuohezi[i-1][j]!=2&&xialuohezi[i][j]+pan[x+i-1][y+j]==2)
	   return 1;
	   }
	}
	if(b==77)//��
	{
		
	for(int j=0;j<5;j++)
	   {
	   if(xialuohezi[4][j]+pan[x+5][y+j]==2)
	   return 1;
	   }
	   
	for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
	   {if(xialuohezi[i][j]+xialuohezi[i+1][j]!=2&&xialuohezi[i][j]+pan[x+i+1][y+j]==2)
	   return 1;
	   }	   
	}	
	return 0;
}

int isman(void)
{
	x=Maxw/2-2;y=0;
	for(int i=0;i<5;i++)
	   for(int j=0;j<5;j++)
	   {if(xialuohezi[i][j]&&pan[x+i][y+j])
	   return 1;
       }
       return 0;
}

void show(void) 
{int n,m;
 system("cls");
for(int j=0,n=0;j<Maxh;j++)
{
 for(int i=0,m=0;i<Maxw+2;i++)
 {  
	if(i==x+m&&j==y+n&&n!=5)
	{
		if(pan[i][j]||xialuohezi[m][n])
		printf("e");
		
		else printf(" ");
		
		m++;
		if(m==5){m=0;n++;}
	}
	else if(pan[i][j])printf("e");
	else printf(" ");
 }
printf("\n");
}
	printf("\nscore : %d �ȼ�: %d ,˫��q�����¿�ʼ",score,t);
}



void rotate(void)  //��ת90�� 
{
	int box[5][5];
 for(int i = 0; i <5; i++) 
 for(int j = 4; j >= 0;j--) 
 box[i][j] = lshezi[j][4 - i];
 
 int test=1;
 for(int j= 0; j< 5; j++)
 for(int i= 0; i< 5; i++)
 if(pan[i+x][j + y] && box[i][j])
 test=0;
 
 if(test)
 {
  for(int i = 0;i <5; i++) 
  for(int j = 0;j<5;j++)
  {
   xialuohezi[i][j]=box[i][j];
   lshezi[i][j]=box[i][j];
  }
 }
}

int clear(void) 
{ 
 int i,j;
 int dx,dy;
 int full;
 for(j=0;j<Maxh-1; j++) 
 { 
    full=1; 
    for(i=2;i<Maxw;i++) 
    { 
      if(!pan[i][j]) 
 	  {full=0; break;}
    }
    if(full==1)break;
 }
    if(full) //���� 
 { 
   for(dy=j;dy>0;dy--)
   for(dx=2;dx<Maxw;dx++)
   pan[dx][dy]=pan[dx][dy-1];
 
   for(dx=2;dx<Maxw;dx++) //�����һ��
   pan[dx][0]=0;

   score+=100;
   t++;
   shudu*=0.95;
   return 1;
 }
 return 0;
}
