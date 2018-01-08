#include<stdio.h>
#include<malloc.h>
#include<math.h> 
struct zuobiao
{
	int x;
	int y;
 } ;
int main()
{
	int t,n,*v,i;
	double *time,min;
	struct zuobiao lucie,*taxi;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&lucie.x,&lucie.y);
		scanf("%d",&n);
		taxi=(struct zuobiao* )malloc(sizeof(struct zuobiao)*n);
		v=(int *)malloc(sizeof(int)*n);
		time=(double *)malloc(sizeof(double)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&taxi[i].x,&taxi[i].y);
			scanf("%d",&v[i]);
			time[i]=pow((taxi[i].y-lucie.y)*(taxi[i].y-lucie.y)+(taxi[i].x-lucie.x)*(taxi[i].x-lucie.x),0.5)/v[i];
		}
		min=time[0];
		for(i=0;i<n;i++)
		{
			if(time[i]<min)
			min=time[i];
		}
		printf("%.2f\n",min);
	}
}
