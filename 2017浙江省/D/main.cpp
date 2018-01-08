#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int t,n,m,x,y;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int starta=0,enda=0,startb=0,endb=0,tmps,tmpe;
        int point=0;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i=0;i<x;i++)
        {
            scanf("%d%d",&tmps,&tmpe);
            if(tmps<starta&&starta)
                starta=tmps;
            else if(!starta)
                starta=tmps;
            if(tmpe>enda&&enda)
                enda=tmpe;
            else if(!enda)
                enda=tmpe;
        }
        for(int i=0;i<y;i++)
        {
            scanf("%d%d",&tmps,&tmpe);
            if(tmps<startb&&startb)
                startb=tmps;
            else if(!startb)
                startb=tmps;
            if(tmpe>endb&&endb)
                endb=tmpe;
            else if(!endb)
                endb=tmpe;
        }
        //printf("%d%d%d%d\n",starta,enda,startb,endb);
        int start=0,ed=0;
        if(starta<startb&&enda>=startb)
            start=startb;
        else if(starta>=startb&&endb>=starta)
            start=starta;
        if(enda>endb&&starta<=endb)
            ed=endb;
        else if(enda<=endb&&startb<=enda)
            ed=enda;
        //printf("%d%d\n",start,ed);

        if(start&&ed)
        {
            for(int p=start;p<=ed;p+=m)
            {
                point++;
            }
        }

        printf("%d\n",point);
    }
    return 0;
}
