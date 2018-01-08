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
		while(ed-st>=0)//向s数组里反向添加字符 
		{
			mid=st+(ed-st)/2; //mid为添加的个数 
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
				//判断s中包不包含t的字符 
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
