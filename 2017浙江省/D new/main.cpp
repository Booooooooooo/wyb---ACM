#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int t,n,m,x,y;
struct day{
    int st,ed;

}a[105],b[105];

bool cmp(day a,day b)
{

    return a.st<b.st;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i=0;i<x;i++)
        {
            scanf("%d%d",&a[i].st,&a[i].ed);
        }
        int maxx,minn,ans=0;
        for(int i=0;i<y;i++)
        {
            scanf("%d%d",&b[i].st,&b[i].ed);
        }
        for(int i=0;i<x;i++)
        {
        	if((a[i].ed-a[i].st)+1<m)
        	continue;
        	
        	for(int j=0;j<y;j++)
        	{
        		if((b[j].ed-b[j].st+1)<m)
        		continue;
        		
        		maxx=min(a[i].ed,b[j].ed);
        		minn=max(a[i].st,b[j].st);
        		
        		if((maxx-minn+1)>=m)
        		ans+=maxx-minn-m+2;
			}
		}
        printf("%d\n",ans);
    }
    return 0;
}
