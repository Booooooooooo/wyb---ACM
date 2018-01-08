#include<iostream>

int gcd(int a,int b)
{
	if(b==0)
	return a;
	else 
	return gcd(b,a%b);
}

int main()
{
	int a,b,r;
	scanf("%d%d",&a,&b);
	r=gcd(a,b);
	printf("%d\n",r);
	return 0;
 } 
