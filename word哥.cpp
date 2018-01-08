#include<stdio.h>
int main()
{
	int t,big=0,small=0,i;
	char str[50],*p;
	scanf("%d",&t);
	while(t--)
	{
		big=0;
		small=0;
		scanf("%s",str);
		p=str;
		while (*p)
		{
			
			if(*p<='Z'&&*p>='A')
			{
				big++;
			}
			else if(*p<='z'&&*p>='a')
			{
				small++;
			}
			p++;
		}
		p=str;
		if(small==0||big==0)
		;
		else 
		{
		if(small<big)
		{
			while (*p)
			{
				if(*p<='z'&&*p>='a')
				*p-=32;
				p++;
			}
		}
		else
		{
		
			while (*p!='\0')
			{
				if(*p<='Z'&&*p>='A')
				*p+=32;
				p++;
			}
		}
		}
		
		printf("%s\n",str);
	}
	return 0;
 } 
