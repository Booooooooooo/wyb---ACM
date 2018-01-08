#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int t,n;

/*long long mod_pow(long long x,long long y)
{
	long long res=1;
	while(y>0)
	{
		if(y&1)res=res*x%7;
		x=x*x%7;
		y>>=1;
	}
	return res;
}*/

long long mod_pow(long long x,long long y)
{
	if(y==0)return 1;
	long long res=mod_pow(x*x%7,y/2);
	if(y&1)res=res*x%7;
	return res;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
		 	/*if(i%2)
			 {
			 	ans+=mod_pow(i*i,i/2)*i;
				 }
			 else 
			 {
			 	ans+=mod_pow(i*i,i/2);
			 }
			 */
			 ans+=mod_pow(i,i);
	 		 if(ans>7)
	 		 ans%=7;
		}
		
		ans%=7;
		switch(ans)
		{
			case 0:printf("Saturday\n");break;
			case 1:printf("Sunday\n");break;
			case 2:printf("Monday\n");break;
			case 3:printf("Tuesday\n");break;
			case 4:printf("Wednesday\n");break;
			case 5:printf("Thursday\n");break;
			case 6:printf("Friday\n");break;
		}
		
	}
	return 0;
 } 

