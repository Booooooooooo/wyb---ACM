#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
int main(void)
{
    freopen("e://编程练习//acm//duipai//data.txt","w",stdout);
    srand(time(NULL));
    int n=10000;//n多少自己定??
    while(n--)
    {
       printf("%d\n",rand());
    }
    return 0;
}
