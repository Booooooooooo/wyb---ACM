#include<stdio.h>
long long n,m,k;
int main()
{
	while (scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		long long st,ed,mid;
		st=0;
		ed=m+1;
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			long long sum,s1,s2,i,a;
			i=mid-1;
			/*if(mid%2)
			{
				i=mid/2;
				a=1;	
			}
			else 
			{
				i=mid/2-1;	
				a=2;
			}
			*/
			if(k>=i)
			{
				s1=(1+mid)*(i+1)/2+k-i-1;
			}
			else 
			s1=(2*mid-k+1)*(k)/2;
			if((n-k)>=i)
			s2=(1+mid-1)*i/2+n-k-i;
			else
			s2=(2*mid-n+k-1)*(n-k);

			sum=s1+s2;
			if(sum>m)
			ed=mid;
			else
			st=mid;
		}
		printf("%d\n",st);
	}
	return 0;
}
