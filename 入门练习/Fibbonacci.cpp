#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
/*int fun(int n)
{
	if (n==0)
	return 0;
	else if(n==1)
	return 1;
	else 
	return (fun(n-1)+fun(n-2));
}*/

/*int main()
{
	long long fib;
	int n;
	scanf("%d",&n);
	while (n!=-1)
	{
		//printf("%d\n",fun(n));
		fib=1/sqrt(5)*(pow((1+sqrt(5))/2,n)-(pow((1-sqrt(5))/2,n)));
		cout<<fib<<endl;
		scanf("%d",&n);
	}
	return 0;
 } */
 
 int main()
 {
 	long long fib[51];
 	int n,i;
 	scanf("%d",&n);
 	while (n!=-1)
 	{
 		fib[0]=0;
 		fib[1]=1;
 		for(i=2;i<51;i++)
 		{
 			fib[i]=fib[i-1]+fib[i-2];
		 }
		
		cout<<fib[n]<<endl;
		scanf("%d",&n);
	 }
	 return 0;
 }
