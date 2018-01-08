#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=100002;
const int inf=0x7fffffff;
int x[maxn];
int n,c;

bool ok(int m)
{
	int last=0;
	for(int i=1;i<c;i++)
	{
		int cur=last+1;//curָ��ǰ��ţ��λ��
		while(cur<n&&x[cur]-x[last]<m)
			cur++;
		if(cur==n)//ֻ���µ�һͷţ���޷����µڶ�ͷţ��ʹ���ߵľ�����ڵ���m
			return false;
		last =cur;//�ѵ�iͷţ���ڱ��Ϊcur��ţ�������ţ��ͷ����ţ��ı�Ŷ��Ǵ�0��ʼ��
	}
	return true;
}
int main()
{
	cin>>n>>c;
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	sort(x,x+n);
	int l=0,r=inf;//����rҲ����д����Ŀ���������1000000000
	for(int i=0;i<100;i++)
	{
		int m=(l+r)/2;
		if(ok(m))
			l=m;
		else r=m;
	}
	cout<<l<<endl;
	return 0;
}
/*#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,c,dis[100005];
	while (scanf("%d%d",&n,&c)!=EOF)
	{
		int i,crt;
		for(i=0;i<n;i++)
		scanf("%d",&dis[i]);
		sort(dis,dis+n);
		int st,ed,mid;
		st=0;
		ed=dis[n-1];
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			int last=0;
			for(i=0;i<c;i++)
			{
				crt=last+1;
				while(crt<n&&dis[crt]-dis[last]<mid)
				{
					crt++;
				}
				
			}
			if(crt==n)
				st=mid;
			else
			{
				last=crt;
				ed=mid;
			}
		}
		printf("%d\n",mid);
	}
	return 0;
 } */
