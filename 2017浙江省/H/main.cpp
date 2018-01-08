#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int t,n;
//int tree1[100005],tree2[100005];
struct tree{
    int num;
    //int parent;
    bool vis;
}t1[100005],t2[100005];
int parent[100005];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t1[i].num);
            //t1[i].vis=false;
            //t2[i].vis=false;
        }
        for(int i=0;i<n;i++)
            scanf("%d",&t2[i].num);

        parent[t1[0].num]=0;
        int p=t1[0].num;
        //int flag=1;
        for(int i=1;i<n;i++)
        {

            if(t1[i].num==t2[i].num)
            {
                //t1[i].vis=true;
                //t2[i].vis=true;
                //if(i)
                parent[t1[i].num]=p;
                p=t1[i].num;
                //flag=1;
                //else
                  //  parent[t1[i].num]=0;
                continue;
            }

            else
            {
                for(int j=i+1;j<n;j++)
                {
                    if(t2[j].num==t1[i].num)
                    {
                        int k;
                        for(k=1;k+j<n;k++)
                        {
                            if(t2[k+j].num!=t1[i+k].num)
                                break;
                        }
                        parent[t1[i+k].num]=t1[i-1].num;
                        parent[t1[i].num]=t1[i-1].num;
                        p=parent[t1[i-1].num];
                        //flag=0;
                    }

                }
            }
            //if(flag)
                //p=t1[i].num;
        }
        for(int i=1;i<=n;i++)
            printf("%d ",parent[i]);
        printf("\n");
    }
    return 0;
}
