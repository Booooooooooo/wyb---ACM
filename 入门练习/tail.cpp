#include<stdio.h>
int main()
{
	int a,b,i,flag;
	scanf("%d%d",&a,&b);
	while (a!=0||b!=0)
	{
		flag=0;
		for(i=0;i<100;i++)
		{
			if((a*100+i)%b==0)
			{
				if(i<10)
				{
					if(flag)
					printf(" ");
					else 
					flag=1;
					printf("0%d",i);
					
				}
				else 
				{
					if(flag)
					printf(" ");
					else 
					flag=1;
					printf("%d",i);
				}
			}
		}
		printf("\n");
		scanf("%d%d",&a,&b);
	}
	return 0;
 } 
