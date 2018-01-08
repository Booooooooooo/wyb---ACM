#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long n,m;

int main()
{
	scanf("%lld%lld",&n,&m);
	long long g=__gcd(n,m),cnt=0,cn=0,cm=0;
	for(long long i=1;i<=g;i++)
	{
		if(!(n%i))
		{
			if(!(m%i))
			cnt++;
		}
	}
	for(long long i=1;i<=sqrt(n);i++)
	{
		if(!(n%i))
		{
			cn++;
		}
	}
	
	for(long long i=1;i<=sqrt(m);i++)
	{
		if(!(m%i))
		{
			cm++;
		}
	}
	if(n!=1)
	cn*=2;
	if(m!=1)
	cm*=2;
	long long k;
	k=__gcd(cn*cm,cnt);
		printf("%lld %lld\n",cn*cm/k,cnt/k);
	return 0;
}
