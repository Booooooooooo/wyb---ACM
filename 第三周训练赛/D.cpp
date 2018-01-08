#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	char cock[100005],p[100005],q[100005];
	while (scanf("%d",&n)!=EOF)
	{
		int cnt1=0,cnt2=0,i,r1=0,b1=0,ans=0,k,b2=0,r2=0;
		scanf("%s",cock);
		for(i=0;i<n;i+=2)
		{
			//if(cock[i]=='r')
			//r++;
			//else b++;
			p[i]='r';
			q[i]='b';
		}
		for(i=1;i<n;i+=2)
		{
			//if(cock[i]=='r')
			//r++;
			//else b++;
			p[i]='b';
			q[i]='r';
		}
		for(i=0;i<n;i++)
		{
			if(p[i]!=cock[i])
			{
				//cnt1++;
				if(cock[i]=='b')
				b1++;
				else r1++;
			}
			if(q[i]!=cock[i])
			{
			//	cnt2++;
				if(cock[i]=='b')
				b2++;
				else r2++;
			}
		}
		
		/*if(r-b>1)
		{
			k=n/2-b;
			for(i=1;k;i+=2,k--)
			{
				if(cock[i]!='b')
				{
					cock[i]='b';
					ans++;
					}	
			}	
			
		}
		else if(b-r>1)
		{
			k=n/2-r;
			for(i=1;k;i+=2,k--)
			{
				if(cock[i]!='r')
				{
					cock[i]='r';
					ans++;
					}	
			}
		}*/
	//	else
	//	{
		if(r1>b1)
		cnt1=r1;
		else 
		cnt1=b1;
		if(r2>b2)
		cnt2=r2;
		else cnt2=b2;
		//if(cnt1%2&&cnt1)
		//cnt1=cnt1/2+1;
		//else cnt1=cnt1/2;
		//if(cnt2%2&&cnt2)
		//cnt2=cnt2/2+1;
		//else cnt2=cnt2/2;
		
		if(cnt1<cnt2)
		ans+=cnt1;
		else ans+=cnt2;
	//	}
		
		printf("%d\n",ans);
	}
	return 0;
 } 
