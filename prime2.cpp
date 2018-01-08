#include<stdio.h>
#include<malloc.h>
#include<math.h>
int main()
{
	int t,n,cnt;
	int *isPrime;
	int i;
	int x;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		isPrime=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
		isPrime[i]=1;
		}
		for(x=2;x<n;x++)
		{
		 if (isPrime[x])
		 {
	 	for (i=2;i*x<n ;i++)
		 {
	 	isPrime[i*x]=0;
		 }	
	 	} 
	 }
	for (i=2; i<n ;i++)
	{
	if (isPrime[i])
	cnt++;
	}
	if(n!=1)
	printf("%d\n",cnt+1);
	else printf("%d\n",0);
	}
	return 0;
}
