#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;
int n;
double X1,X2,Y1,Y2;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b){x=1;y=0;return a;}
	long long d =exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}

long long solve()
{
	long long a,b,c,g;
	long long x1,x2,y1,y2,x,y;
	x1=(X1+0.05)*10;
	y1=(Y1+0.05)*10;
	x2=(X2+0.05)*10;
	y2=(Y2+0.05)*10;
	if(x1==x2)
	{
		if(x1%10)return 0;
		if(Y2<Y1)swap(Y1,Y2);
		return floor(Y2)-ceil(Y1)+1;
	}
	if(y1==y2)
	{
		if(y1%10)return 0;
		if(X2<X1)swap(X1,X2);
		return floor(X2)-ceil(X1)+1;
	}
	a=(y2-y1)*10;
	b=(x2-x1)*10;
	c=y2*x1-y1*x2;
	g=exgcd(a,b,x,y);
	if(c%g) return 0;//无解
	x*=c/g;//找到解x 
	b=abs(b/g);
 	if(X1>X2)swap(X1,X2);
 	x1=ceil(X1);
 	x2=floor(X2);
 	//x-=x-x1;//把x转到范围内 
	x-=(x-x1)/b*b;/////////////////////////////////为什么啊啊啊啊啊啊 
 	if(x<x1)x+=b;
 	if(x2<x)return 0;
 	return (x2-x)/b+1;
}


//将直线表示为ax+by=c 
int main()
{
	//freopen("e://编程练习//acm//duipai//data.txt","r",stdin);
	//freopen("e://编程练习//acm//duipai//out1.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		
		scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
		printf("%lld\n",solve());
	 } 
	return 0;
}
