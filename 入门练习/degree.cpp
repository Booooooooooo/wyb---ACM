#include<stdio.h>
#include<math.h>
int main()
{
	int t,h,m,s,degree;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&h,&m,&s);
		degree=abs(h*5-m)*6;
		if(degree>180)
		degree =360-degree;
		printf("%d\n",degree);
	}
}
