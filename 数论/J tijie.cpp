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
    ll x1=(X1+0.05)*10,y1=(Y1+0.05)*10,x2=(X2+0.05)*10,y2=(Y2+0.05)*10;//���ĵ�ʱ���ֲ���0.05ò�ƻ������ 
    if(x1==x2) {//ƽ��y�� 
        if(x1%10) return 0;
        if(Y2<Y1) swap(Y1,Y2);
        return floor(Y2)-ceil(Y1)+1;
    }
    if(y1==y2) {//ƽ��x�� 
        if(y1%10) return 0;
        if(X2<X1) swap(X1,X2);
        return floor(X2)-ceil(X1)+1;
    }
    ll a=(y2-y1)*10,b=(x1-x2)*10,c=y2*x1-y1*x2,g,x,y;//ax+by=c,ע��a,b��Ҫ����10�� 
    exgcd(a,b,g,x,y);//�ҵ���ax+by=gcd(a,b)�����µ�һ���Ϸ���(x,y) 
    if(c%g) return 0;//c��Ϊgcd(a,b)����,�޽� 
    x*=c/g;b=abs(b/g);//�ҵ���ax+by=c�����µĺϷ���ĺ�����x 
    if(X1>X2) swap(X1,X2);
    x1=ceil(X1);//С������ȡ�� 
    x2=floor(X2);//��������ȡ�� 
    x-=(x-x1)/b*b;//��x�ı�ֵ��[x1,x2] 
    if(x<x1) x+=b;
    if(x2<x) return 0;
    return (x2-x)/b+1;
}

int main()
{
	//freopen("e:\\�����ϰ\\acm\\duipai\\data.txt","r",stdin);
	//freopen("e:\\�����ϰ\\acm\\duipai\\out2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) {
    	
        scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
        printf("%lld\n",solve());
    }
    return 0;
}
