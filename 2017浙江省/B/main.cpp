#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int t,n;
int num[105];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int i;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        if(n<10||n>13)
        {
            printf("No\n");
            continue;
        }
        sort(num,num+n);
        if(num[0]!=1||num[1]!=1)
        {
            printf("No\n");
            continue;
        }

        int flag=1;
        for(i=2;i<n-1;i++)
        {
            if((num[i]-num[i-1])>2)
            {
                printf("No\n");
                flag=0;
                break;
            }

        }
        if(flag)
            printf("Yes\n");
    }
    return 0;
}
