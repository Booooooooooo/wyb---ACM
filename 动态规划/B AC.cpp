#include<iostream>
using namespace std;

int main()
{
	int n,i,s[10001],a[10001],f[10001],max,st,end;  //f[i]Ϊ��iΪ��β��������У�s[i]Ϊ�俪ʼ��
	bool flag;
	scanf("%d",&n);
	while(n)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		flag=0;
		for(i=1;i<=n;i++)        //�ж��Ƿ�ȫΪ��
			if(a[i]>=0)
			{flag=1;break;}
		if(flag)                      //����ȫ��
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
		else                                           //ȫ��
			cout<<0<<" "<<a[1]<<" "<<a[n]<<endl;
		scanf("%d",&n);
	}
	return 0;
}
