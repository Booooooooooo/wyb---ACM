#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

void exgcd(ll a,ll b,ll& g,ll& x,ll& y)
{
    if(!b) g=a,x=1,y=0;
    else exgcd(b,a%b,g,y,x),y-=x*(a/b);
}

double X1,Y1,X2,Y2;

ll solve()
{
    ll x1=(X1+0.05)*10,y1=(Y1+0.05)*10,x2=(X2+0.05)*10,y2=(Y2+0.05)*10;//对拍的时候发现不加0.05貌似会有误差 
    if(x1==x2) {//平行y轴 
        if(x1%10) return 0;
        if(Y2<Y1) swap(Y1,Y2);
        return floor(Y2)-ceil(Y1)+1;
    }
    if(y1==y2) {//平行x轴 
        if(y1%10) return 0;
        if(X2<X1) swap(X1,X2);
        return floor(X2)-ceil(X1)+1;
    }
    ll a=(y2-y1)*10,b=(x1-x2)*10,c=y2*x1-y1*x2,g,x,y;//ax+by=c,注意a,b需要扩大10倍 
    exgcd(a,b,g,x,y);//找到在ax+by=gcd(a,b)条件下的一个合法解(x,y) 
    if(c%g) return 0;//c不为gcd(a,b)倍数,无解 
    x*=c/g;b=abs(b/g);//找到在ax+by=c条件下的合法解的横坐标x 
    if(X1>X2) swap(X1,X2);
    x1=ceil(X1);//小数向上取整 
    x2=floor(X2);//大数向下取整 
    x-=(x-x1)/b*b;//将x改变值至[x1,x2] 
    if(x<x1) x+=b;
    if(x2<x) return 0;
    return (x2-x)/b+1;
}

int main()
{
	//freopen("e:\\编程练习\\acm\\duipai\\data.txt","r",stdin);
	//freopen("e:\\编程练习\\acm\\duipai\\out2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) {
    	
        scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
        printf("%lld\n",solve());
    }
    return 0;
}
