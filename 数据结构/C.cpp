#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

char ch[1005],m;
struct num{
    char s;
    bool vis;
}n[1005];

int main()
{
    while(scanf("%s%d",ch,&m)!=EOF)
    {
        bool flag=false;
        int len=strlen(ch);
        if(m>=len)
        {
            printf("0\n");
            break;
        }
        for(int i=0;i<len;i++)
        {
            n[i].s=ch[i];
            n[i].s=true;
        }
        while(m--)
        {
            for(int i=0;i<len-1;i++)
            {
                /*if(m==0)
                    break;
                    */
                //int f=0;

                if(n[i].vis)
                {


                  /*  if(n[i].s>n[i+1].s)
                    {
                        n[i].vis=false;
                        break;
                    }*/
                    int j;
                    for(j=i+1;j<len;j++)
                    {
                        if(n[j].vis)
                            break;
                        /*if(n[i].s>n[j].s&&n[j].vis)
                        {
                           n[i].vis=false;
                           f=1;
                           break;
                        }*/
                    }
                    if(n[i].s>n[j].s)
                    {
                        n[i].vis=false;
                        break;
                    }
                    else
                    {
                        n[j].vis=false;
                        break;
                    }
                   // if(f)
                     //   break;
                }
               // m--;

            }
        }

        for(int i=0;i<len;i++)
        {
            if(n[i].vis)
            {
                if(n[i].s=='0'&&!flag)
                    continue;
                else
                {
                    printf("%c",n[i].s);
                    flag=true;
                }

            }
        }
        if(!flag)
            printf("0");
        printf("\n");
        /*for(int i=0;i<len;)
        {
            if(ch[i]=='0')
                i++;
            for(int j=i+1;len-j-1<m;j++)
            {
                if(ch[j]<ch[i])
                    i=j;
            }
        }*/
    }
    return 0;
}

