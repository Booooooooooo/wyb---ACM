#include<stdio.h>
int main()
{
	int n,ticket[100005];//来的人给的钱;
	while (scanf("%d",&n)!=EOF)
	{
		int one=0,two=0;
		int i;//售票站剩的钱 
		 for(i=0;i<n;i++)
		 {
		 	scanf("%d",&ticket[i]);
		 }
		 if(ticket[0]==25)
		 {
		 	one=1;
		 	for(i=1;i<n;i++)
		 	{
		 		if(ticket[i]==50)
		 		{
		 			if(one>=1)
		 			{
		 				one-=1;
		 				two +=1;
					 }
		 			else break;
				 }
				 else if(ticket[i]==100)
				 {
				 	if(one >=1&&two >=1)
				 	{
				 		one-=1;
				 		two-=1;
					 }
					 else if(one>=3)
				 		one -=3;
				 	
					 else break;
				 }
				 else if(ticket[i]==25)
				 	one+=1;
			 }
			 if(i==n)
			 printf("YES\n");
			 else printf("NO\n");
		 }
		 else printf("NO\n");
		 
	}
	return 0;
 } 
