#include<stdio.h>
int main()
{
	int t,a,b,result;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		while (a>=100)
		{
			a=a%100;	//使a只剩后两位 
		}
		while (b>=100)
		{
			b=b%100;	//使b只剩后两位 
		}
		result = a+b;
		while (result >=100)
		{
			result= result%100;		//使result只剩后两位 
		}
		printf("%d\n",result);
	}
	return 0;
 } 
