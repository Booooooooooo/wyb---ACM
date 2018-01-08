#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,z;
	while (scanf("%d%d%d",&n,&m,&z)!=EOF)
	{
		int kill[10005]={0},cnt=0,i;
		for(i=1;n*i<=z;i++)
		{
			kill[n*i]=1;
		}
		for(i=1;i*m<=z;i++)
		{
			if(kill[i*m])
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
