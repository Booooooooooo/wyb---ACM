//TÁËµÄrmq
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

int t,n,q,l,r,cnt,ans;
int num[100005];
int g[100005][20];

void rmq()
{
    for(int i=1;i<=n;i++)
    {
        g[i][0]=num[i];
    }
    for(int j=1;j<20;j++)
    {
        if((1<<j)>n)
            break;
        for(int i=1;i+(1<<j)-1<=n;i++)
            g[i][j]=__gcd(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
}

int query(int l,int r)
{
    int st=1,ed=20,mid;
    int re;

    if(l==r)
        re=num[l];
    else if((r-l)==1)
        re=__gcd(num[l],num[r]);
    else
    {
        while((ed-st)>1)
        {
            mid=st+(ed-st)/2;
            if(l+(1<<mid)>n)
                ed=mid;
            else
                st=mid;
        }
        /*for(int k=1;k<30;k++)
        {
            if(i+(1<<k)>n)
                break;
        }
        re=__gcd(g[l][k-1],g[])*/
        re=__gcd(g[l][st],g[r-(1<<st)+1][st]);
    }
    return re;
}

void ct(int gc)
{
    int st,ed,mid;

    for(int i=1;i<=n;i++)
    {
        /*st=i;
        ed=n;
        while((ed-st)>1)
        {
            mid=st+(ed-st)/2;
            if(query(i,mid)<gc)
                ed=mid;
            else
                st=mid;
        }

        for(int j=i;j<=mid;j++)
        {
            if(query(i,j)==gc)
                cnt++;
        }*/
        for(int j=i;j<=n;j++)
        {
            if(query(i,j)==gc)
                cnt++;
            else if(query(i,j)<gc)
                break;
        }
    }
}

int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        rmq();
        scanf("%d",&q);
        printf("Case #%d:\n",cas);
        while(q--)
        {
            cnt=0;
            scanf("%d%d",&l,&r);
            ans=query(l,r);

            ct(ans);
            printf("%d %d\n",ans,cnt);
        }
    }
    return 0;
}
