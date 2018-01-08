#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int n;
float x1,x2,y1,y2;
bool prime[400020]; 

int main()
{
	for(int i=1;i<200005;i++)
	{
		if(!prime[i])
		{
			for(int j=2;j*i<200005;j++)
			{
			 	prime[i*j]=1;
	 			prime[2*i*j]=1;
			}
		}
		
	 } 
	 //素数打表
	  
	while(scanf("%d",&n)!=EOF)
	{
		memset(prime,0,sizeof(prime));
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
			double k,b;
			k=(y2-y1)/(x2-x1);
			b=y1-k*x1;
		 	
			if((int)k==k&&(int)b!=b)
			{
				if((int)x1==x1&&(int)y1==y1)
				cnt++;
				if((int)x2==x2&&(int)y2==y2)
				cnt++;
				printf("%d\n",cnt);
				break;
			 } //k是整数b不是整数 之间不会有整点
			 
		 	 if((int)k==k&&(int)b==b)
		 	 {
		 	 	if((int)(x2-x1)==(x2-x1))
		 	 	cnt=x2-x1-1;
		 	 	else
		 	 	cnt=x2-x1;
		 	 	if((int)x1==x1&&(int)y1==y1)
				cnt++;
				if((int)x2==x2&&(int)y2==y2)
				cnt++;
				printf("%d\n",cnt);
				break;
			  }//kb都是整数 中间的每个都是整点
			  
			if((int)k!=k&&(int)b==b)
			{
				if((int)x1==x1&&(int)y1==y1)
				cnt++;
				if((int)x2==x2&&(int)y2==y2)
				cnt++;
				printf("%d\n",cnt);
				break;
			 } 
			 //b是整数 则之间的整点都不成立 
			 if(x1>=0)
			 {
		        for(int x=x1+1;x<x2;x++)
				    {
						if(!prime[x])
				        {
					        float y=k*x+b;
					        if((int)y==y)
				        	{
					            cnt+=(x2-x1-1)/x;
				 	        }
				        }
				
		        	}//某个x成立 则x的倍数一定成立 只需判断范围内的质数即可 
			//注意考虑负数情况 	
			 }
			 else 
			 {
			 	for(int x=x1+1;x<0;x++)
				    {
						if(!prime[-2*x])
				        {
					        float y=k*x+b;
					        if((int)y==y)
				        	{
					            cnt+=(1-x1)/x;
				 	        }
				        }
				
		        	}
				for(int x=0;x<x2;x++)
				    {
						if(!prime[x])
				        {
					        float y=k*x+b;
					        if((int)y==y)
				        	{
					            cnt+=(x2-1)/x;
				 	        }
				        }
				
		        	}
		        	
			 }
			 		
			if((int)x1==x1&&(int)y1==y1)
			cnt++;
			if((int)x2==x2&&(int)y2==y2)
			cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
 } 
