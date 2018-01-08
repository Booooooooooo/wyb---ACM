#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int t,n,l;
struct s{
    int time;
    int j;
    bool vis;
}stu[20005];

bool cmp(s a,s b)
{
    return a.time<b.time;
}

bool cmp2(s a,s b)
{
    return a.j<b.j;
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
        int a,b,c,cnt=1;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)
        {
            scanf("%d:%d:%d",&a,&b,&c);
            stu[i].time=a*60*60+b*60+c;
            stu[i].j=i;
            stu[i].vis=false;
        }
        sort(stu,stu+n,cmp);
        int temp=0;
        stu[temp].vis=true;
        for(int i=temp+1;i<n;i++)
        {
            if(stu[i].time>=stu[temp].time+l)
            {
                stu[i].vis=true;
                temp=i;
                cnt++;
            }

        }
        sort(stu,stu+n,cmp2);
        printf("%d\n",cnt);
        int flag=0;
        for(int i=0;i<n;i++)
        {
        	if(!flag&&stu[i].vis)
        	{
        		printf("%d",stu[i].j+1);
        		flag=1;
			}
            else if(stu[i].vis)
            printf(" %d",stu[i].j+1);
        }
        printf("\n");
	}
}

