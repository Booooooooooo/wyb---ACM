#include<stdio.h>
int main() 
{
	int n,cnt,i;
	int mag[100005];
	while (scanf("%d",&n)!=EOF)
	{
		cnt=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&mag[i]);
		}
		if(n==1)
		cnt=1;
		else if(n==2)
		{
			if(mag[0]!=mag[1])
			cnt=2;
		}
		else
		{
		for(i=0;i<n-1;i++)
		{
		
			if(mag[i]!=mag[i+1])
			cnt++;
		}	
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}
