#include<stdio.h>
int main()
{
	int n,a[10],i,j,num[10]={0};
	while (scanf("%d",&n)!=EOF)
	{
		int flag=0,temp=0,temi=0,re=n;
		for(i=1;i<10;i++)
			scanf("%d",&a[i]);
	
		if(n==0)
		printf("-1\n");
		else 
		{	
			for(j=0;re>0;)
			{
				for(i=1;i<10;i++)
				{
					if(j<a[i])
						continue;
					else 
					{
						flag =1;
						temp=a[i];
						temi=i;
					}
				}
				if(flag)
				{
					re-=temp;
					num[temi]++;
				}
				
			}
			for(i=9;i>0;i--)
				{
					while (num[i]>0)
					{
						printf("%d",i);
						num[i]--;
					}
				}
			printf("\n");
			
		
			
		}
	
	 } 
	return 0;
}
