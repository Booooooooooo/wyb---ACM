#include<stdio.h>
#include<iostream>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,x;
	set<int> a;
	set<int>::iterator it;
	set<int>::iterator j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",x);
			a.insert(x);
		}
		for(it=a.begin();it!=a.end();it++)
		{
			for(j=a.begin();j!=a.end();j++)
			{
				a.insert(abs(*it-*j));
			}
		}
		if((a.size()-n-1)%2)
		printf("Alice\n");
		else 
		printf("Bob\n");
		a.clear();
	}
	return 0;
}
