#include<iostream>
using namespace std;

int main()
{
	int n,i,s[10001],a[10001],f[10001],max,st,end;  //f[i]为以i为结尾最长连续序列，s[i]为其开始点
	bool flag;
	scanf("%d",&n);
	while(n)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		flag=0;
		for(i=1;i<=n;i++)        //判断是否全为负
			if(a[i]>=0)
			{flag=1;break;}
		if(flag)                      //不是全负
		{
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
			cout<<max<<" "<<a[st]<<" "<<a[end]<<endl;
		}
		else                                           //全负
			cout<<0<<" "<<a[1]<<" "<<a[n]<<endl;
		scanf("%d",&n);
	}
	return 0;
}
