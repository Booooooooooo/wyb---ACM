#include<stdio.h>
#include<malloc.h>

int main()
{
	int n,i;
	char tel[12];
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",tel);
		printf("6");
		for(i=6;i<11;i++)
		{
			printf("%c",tel[i]);
		}
		printf("\n");
	}
	return 0;
}
