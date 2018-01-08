#include<stdio.h>
int main()
{
	int n,ten,sixteen,twelve,temp,i;
	scanf("%d",&n);
	while (n!=0)
	{
		temp=n;
		ten=0;
		sixteen=0;
		twelve=0;
		while(temp!=0)
		{
			ten+=temp%10;
			temp/=10;
		}
		temp=n;
		while (temp!=0)
		{
			sixteen +=temp%16;
			temp/=16;
		}
		temp=n;
		while (temp!=0)
		{
			twelve +=temp%12;
			temp/=12;
		}
		if(ten==sixteen&&ten ==twelve)
		printf("%d is a Sky Number.\n",n);
		else 
		printf("%d is not a Sky Number.\n",n);
		scanf("%d",&n);
	}
	return 0;
 } 
