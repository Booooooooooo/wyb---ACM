#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=50000;
struct node
{
  int u;
  int v;
  int w;
}e[MAX+5];
int f[20000+5];
bool cmp(node com1,node com2)
{
  return com1.w<com2.w? true:false;
  
}
int find(int h)
{
  if(h==f[h])
    {
      return h;

    }
  else 
    {
      f[h]=find(f[h]);
    }
}
int main()
{
     int t;
     scanf("%d",&t);
     int sum;
     int i;
     while(t--)
    {
    	
      sum=0;
      int n,m,line;
      scanf("%d %d %d",&n,&m,&line);
      int total;
      total=n+m;
      for(i=0;i<=total;i++)
      {
      	f[i]=i;
      }

      int r1,r2;
      for(i=0;i<line;i++)
	{
	  scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	  e[i].v+=n;
	  e[i].w=-e[i].w;
	  
	}
      sort(&e[0],&e[line],cmp);
      for(i=0;i<line;i++)
	{
	  r1=find(e[i].u);
	  r2=find(e[i].v);
	//  cout<<"r1"<<r1<<endl;
	 // cout<<"r2"<<r2<<endl;
	  if(r1!=r2)
	    {
	      f[r1]=r2;
	      sum+=e[i].w;
	      
	    }
	}
      printf("%d\n",(n+m)*10000+sum);
      
      
	
      
      
    }
  
}
