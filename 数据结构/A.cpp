#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long n,q,u;
char s[100005];

long long lowbit(long long num)
{
    return num&(-num);
}

int main() {
    while(scanf("%lld%lld",&n,&q)!=EOF) {

        while(q--) {
            scanf("%lld",&u);
            scanf("%s",s);
            int i=0;
            long long root =(n+1)/2;
           // printf("%lld\n",u);
            while(s[i]!='\0')//父亲的lowbit始终是孩子的两倍
            {
                if(s[i]=='R')
                {
                    u+=lowbit(u)/2;
             //       printf("%lld %lld\n",u,lowbit(u));
                }
                   
                else if(s[i]=='L')
                {
                    u-=lowbit(u)/2;
               //     printf("%lld %lld\n",u,lowbit(u));
                }
                    
                else if(s[i]=='U') {
                    if (u == root)
                        {
                        	i++;
                        	continue;
						}
                    else {
                        long long temp;
                        temp = lowbit(u);
                        if (lowbit(u + temp) == 2 * lowbit(u))
                            u += lowbit(u);//是左孩子
                        else
                            u -= lowbit(u);//是右孩子
                        
                 //       printf("%lld %lld %lld\n",temp,u,lowbit(u));
                    }
                }
                i++;
            }
            printf("%lld\n",u);

        }
    }
    return 0;
}
