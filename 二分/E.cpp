#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char p[200005],t[200005],s[200005];
int de[200005];
int main()
{
	while (scanf("%s%s",p,t)!=EOF)
	{
		int lenp=strlen(p);
		int i;
		for(i=0;i<lenp;i++)
		{
			scanf("%d",&de[i]);
		}
		int st,ed,mid;
		st=0;
		ed=lenp;
		while(ed-st>=0)//��s�����ﷴ������ַ� 
		{
			mid=st+(ed-st)/2; //midΪ��ӵĸ��� 
			for(i=0;i<lenp;i++)
			s[i]=0;
			for(i=0;i<mid;i++)
			{
				s[de[lenp-1-i]-1]=p[de[lenp-1-i]-1];
			}
			int j=0;
			for(i=0;i<lenp;i++)
			{
				if(s[i]==t[j])
				{
					j++;
					if(j==strlen(t)+1)
					break; 
					
				}
				//�ж�s�а�������t���ַ� 
			}
			if(j>=strlen(t))
			ed=mid+1;
			else 
			st=mid-1;
		}
		printf("%d\n",lenp-ed-1);
	}
	return 0;
}
