#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#define INF 0x3f3f3f3f

using namespace std;

int n;
long long edge[20][20],dp[1<<16][16];
bool vis[20];

long long rec(int s,int v,int now)
{
    if(dp[s][v]>=0)
        return dp[s][v];

    if(s==(1<<n)-1&&v==now)
        return dp[s][v]=0;

    long long res=INF;
    for(int u=0;u<n;u++)
    {
        if(!(s>>u&1))
        {
            res=min(res,rec(s|1<<u,u,now)+edge[v][u]);
        }
    }

    return dp[s][v]=res;
}


int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&edge[i][j]);
                if(edge[i][j]==0)
                edge[i][j]=INF;
            }
        }

        memset(dp,-1,sizeof(dp));

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(edge[0][i]==1)
                cnt++;
        }

        long long ans=INF;
        ans=min(ans,rec(0,0,0));
        /*for(int i=0;i<n;i++)
        {
            ans=min(ans,rec(0,i,i));
        }
        */

        if(ans!=INF)
        printf("%lld\n",ans);
        else
        printf("NoAnswer\n");
    }
    return 0;
}
