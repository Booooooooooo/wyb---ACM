#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
long long n;
int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		long long r,minn=n-1,anr=1,ank=n-1,s1=0,s2=0,s=0;
		for(r=1;r<=40;r++)   //50
		{
			long long st=1,ed,mid;
			ed=n+1-r;
  			while(ed-st>1)
			{
				mid=st+(ed-st)/2;
				s=0;
				int flag=1;
				for(int i=1;i<=r;i++)
				{
					s+=pow(mid,i);
					if(s>n||s<0)            //if(s>n-1||s<0)
					{
						flag =0;
						break;
					}
				}
				if(s==n||s==n-1)
				{
				    if(r*mid<minn)
				    {
				         anr=r;
                         ank=mid;
                    }
				}
				if(flag)
				st=mid;
				else
				ed=mid;
			}
		}
		printf("%lld %lld\n",anr,ank);
	 }
	return 0;
}
