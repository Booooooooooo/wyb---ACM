#include<stdio.h>
#include<math.h>
int main()
{
	int n,flag=0,m;
	double x,y;
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0)
	{
		flag =0;
		if(n*n-4*m>=0)
		{
			y=(n+sqrt(n*n-4*m))/2;
			if(y==(int)y)
			flag=1;
		}
		if(flag)
		printf("Yes\n");
		else 
		printf("No\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}
