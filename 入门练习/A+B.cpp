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
			a=a%100;	//ʹaֻʣ����λ 
		}
		while (b>=100)
		{
			b=b%100;	//ʹbֻʣ����λ 
		}
		result = a+b;
		while (result >=100)
		{
			result= result%100;		//ʹresultֻʣ����λ 
		}
		printf("%d\n",result);
	}
	return 0;
 } 
