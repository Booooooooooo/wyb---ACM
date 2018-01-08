#include<iostream>
using namespace std;

int main()
{
	int cnt=1,t,n,i,s[100001],a[100001],f[100001],max,st,end;  //f[i]为以i为结尾最长连续序列，s[i]为其开始点
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		f[1]=a[1];
		s[1]=1;
		for(i=2;i<=n;i++)
		{
		if(f[i-1]+a[i]>=a[i])
		{
			f[i]=f[i-1]+a[i];
			s[i]=s[i-1];
		}
		else
		{
			f[i]=a[i];
			s[i]=i;
		}
		}
		 max=f[1];
		 st=1;
		 end=1;
		 for(i=2;i<=n;i++)
		 {
			if(f[i]>max)
			{
				max=f[i];
				st=s[i];
				end=i;
			}
		 }
		 	cout<<"Case "<<cnt++<<":\n";
			cout<<max<<" "<<st<<" "<<end<<endl;
			if(t)
			cout<<endl;
		
		
	}
	return 0;
}
