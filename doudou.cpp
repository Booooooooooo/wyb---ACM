#include<stdio.h>
#include<malloc.h>
int ji(int num[],int n)
{
	int i,cnt=0;
	for(i=0;i<n;i++)
	{
		
		if(num[i])
		{
		cnt++;
		if(cnt%2==1)
		num[i]=0;
		}
		
	}
	if(cnt==1)
	{
	for(i=0;i<n&&num[i];i++)
	printf("%d ",i+1);
	}
	if (i=n)
	i=0;
	else ji(num,n);
}
int main()
{
	int t,n,*p,i,num,cnt;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		p=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		p[i]=1;
		if(n!=1)
		{
		do
		{
			num=0;
			cnt=0;
			for(i=0;i<n;i++)
			{
		
				if(p[i])
				{
				cnt++;
				if(cnt%2==1)
				p[i]=0;
				}
			}
			for(i=0;i<n;i++)
		{
			if(p[i])
			num++;
		}
		}while(num>1);
		
		}
		else
		p[0]=1;
		for(i=0;i<n;i++)
		{
			if(p[i])
			break;
		}
		printf("%d\n",i+1);
		//ji(p,n);
	}
	return 0;
}
