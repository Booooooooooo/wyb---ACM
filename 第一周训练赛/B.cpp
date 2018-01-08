#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		float x,y,z;
		x=(a+b-c)/2.0;
		y=(b+c-a)/2.0;
		z=(c-b+a)/2.0;
		if(x==(int)x&&y==(int)y&&z==(int)z)
		{
			if((x==0&&y==0)||(x==0&&z==0)||(y==0&&z==0))printf("Impossible\n");
			else if(x<0||y<0||z<0)printf("Impossible\n");
			else printf("%d %d %d\n",(int)x,(int)y,(int)z);
		}
		else 
		printf("Impossible\n");
	}
	return 0;
}
