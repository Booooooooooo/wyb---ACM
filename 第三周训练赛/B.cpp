#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,pre[200005];
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
		scanf("%d",&pre[i]);
		}
		for(i=0;i<n/2;i+=2)
		{
			int temp=pre[i];
			pre[i]=pre[n-1-i];
			pre[n-1-i]=temp;
		}
		/*for(i=0;i<=n/2;i++)
		{
			for(int k=i;k<n/2;k++)
			{
				int temp=pre[k];
				pre[k]=pre[n-k-1];
				pre[n-k-1]=temp;
			} 
		}*/
		for(i=0;i<n;i++)
		{
			printf("%d ",pre[i]);
		}
		printf("\n");
	}
	return 0;
 } 
 
