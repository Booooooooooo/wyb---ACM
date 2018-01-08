#include<stdio.h>
int main()
{
	int t;
	unsigned long a,b;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		if(a%b==0)
		printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
