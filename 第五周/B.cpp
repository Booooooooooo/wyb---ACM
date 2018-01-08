#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int c1,c2,c3,c4;
int b,t;
int bus[1005],tro[1005];
int main()
{
	while(scanf("%d%d%d%d",&c1,&c2,&c3,&c4)!=EOF)
	{
		scanf("%d%d",&b,&t);
		int i,sb=0,st=0,temp,cnt;
		int s1=0,s2=0,s3=0,s4=c4;
		for(i=0;i<b;i++)
		{
			scanf("%d",&bus[i]);
			s1+=bus[i];
			sb+=bus[i];
		}
	
		for(i=0;i<t;i++)
		{
			scanf("%d",&tro[i]);
			s1+=tro[i];
			st+=tro[i];
		}
		s1*=c1;//s1ÎªÈ«Âòc1 
		sort(tro,tro+t);
		sort(bus,bus+b);
		/*sort(tro,tro+t);
		temp=0;
		cnt=1;
		s3=c3+(st-tro[0])*c1+tro[0]*c2;
		for(i=0;i<t;i++)
		{
			if(tro[i]=tro[temp])
			cnt++;
			else
			{
				temp=i;
				cnt=1;
				s3+=max(,c3+(st-cnt*tro[i-1])*c1+tro[i-1]*c2);
				}
			}
			s3=max(s3,c3+st*c1);
			
		}
		else 
		{
			sort(bus,bus+b);
			temp=0;
			cnt=1;
			s3=c3+(sb-bus[0])*c1+bus[0]*c2;
			for(i=1;i<t;i++)
			{
				if(bus[i]=bus[temp])
				cnt++;
				else
				{
					temp=i;
					cnt=1;
					s3=max(s3,c3+(sb-cnt*bus[i-1])*c1+bus[i-1]*c2);
				}
			}
			s3=max(s3,c3+sb*c1);
		}*/
		
		temp=0;
		cnt=1;
		for(i=0;i<b;i++)
		{
			
			s2+=min(bus[i]*c1,c2);
			/*if(bus[i]==bus[temp])
			{
				cnt++;
				if(i==b-1)
				{
					s2+=min(cnt*bus[i]*c1,bus[i]*c2);
				}
			}
			else
			{
				s2+=min(cnt*bus[i-1]*c1,bus[i-1]*c2);
				temp=i;
				cnt=1;
				if(i==b-1)
				s2+=min(bus[i]*c1,c2);
			}*/
		}
		s3=min(s2,c3);
		s1=s2;
		
		temp=0;
		cnt=1;
		/*if(c2<c1)
		s2+=tro[0]*c2+(st-tro[0])*c1;
		else 
		s2+=tro[0]*c1;*/
		for(i=0;i<t;i++)
		{
			/*if(tro[i]==tro[temp])
			{
				cnt++;
				if(i==t-1)
				{
					s2+=min(cnt*tro[i]*c1,tro[i]*c2);
				}
			}
			else
			{
				s2+=min(cnt*tro[i-1]*c1,tro[i-1]*c2);
				temp=i;
				cnt=1;
				if(i==t-1)
				s2+=min(tro[i]*c1,c2);
			}*/
			s2+=min(tro[i]*c1,c2);
		}
		
		s3+=min(c3,s2-s1);
		
		/*int s=min(s1,s2);
		s=min(s,s3);
		s=min(s,s4);*/
		s3=min(s3,s4);
		
		printf("%d\n",s3);
	}
	return 0;
}
