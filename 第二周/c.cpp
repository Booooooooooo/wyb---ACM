#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int n,a[100005],i,r;
	while (scanf("%d",&n)!=EOF)
	{
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int max=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
			max=a[i];
		}
		r=ceil(sum/(n-1.0));
		if(r>max)
		max=r;
		cout<<max<<endl;
	}
	return 0;
}
