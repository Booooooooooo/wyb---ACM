#include<stdio.h>
#include<algorithm>

using namespace std;

int t,y,day,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&y);
		if(y-2016<0)
		{
			n=(2016-y)/4*5;
			y=2016-y;
			if(y%4==3)
			n+=4;
			else if(y%4==2)
			n+=3;
			else if(y%4==1)
			n+=2;
			
			day=7-n;
			while(day<0)
			{
				day+=7;
			}
			if(day==0)
			day=7;
		}
		else 
		{
			n=(y-2016)/4*5;
			y=y-2016;
			if(y%4==3)
			n+=3;
			else if(y%4==2)
			n+=2;
			else if(y%4==1)
			n+=1;
			
			day=7+n;
			day%=7;
			if(day==0)
			day=7;
		}
		
		switch(day)
		{
			case 1:day=9;break;
			case 2:day=6;break;
			case 3:day=5;break;
			case 4:day=5;break;
			case 5:day=5;break;
			case 6:day=5;break;
			case 7:day=6;break;
		}
		
		printf("%d\n",day);
		
	 } 
	return 0;
 } 
