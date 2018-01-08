#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<string>

using namespace std;

char stan[10][10]={"1001111","0010010","0000110","1001100","0100100","0100000","0001111","0000000","0000100"};

struct node{
    int adj;
    char s[10];
}now[10];

int chan[10];
int t,n;

int main()
{

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        memset(chan,-1,sizeof(chan));
        for(int i=0;i<n;i++)
            scanf("%d%s",&now[i].adj,now[i].s);

        for(int i=0;i<9;i++)
        {
            if(now[0].s[i]!=stan[now[0].adj-1][i])
            {
                chan[i]=i;
                cnt++;
            }
        }

        sort(chan,chan+cnt);
        int flag=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(cnt==0)
                {
                    if(now[i].s[j]!=stan[now[i].adj-1][j])
                        flag=1;
                        break;
                }
                if(chan[j]==-1)
                    continue;

                if(now[i].s[chan[j]]==stan[now[i].adj-1][chan[j]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }

        if(flag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
