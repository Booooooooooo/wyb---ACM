#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double r,x,y,a,b;
int main()
{
	while(scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&a,&b)!=EOF)
	{
		int k;
		k=sqrt((a-x)*(a-x)+(b-y)*(b-y))/(r*2);
		if(k*2*r<sqrt((a-x)*(a-x)+(b-y)*(b-y)))
		k++;
		printf("%d\n",k);
	}
	return 0;
}
