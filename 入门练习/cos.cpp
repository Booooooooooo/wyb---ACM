#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	double x1,x2,y1,y2;
	double cos,degree;
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		cos=(x1*x2+y1*y2)/(pow(x1*x1+y1*y1,0.5)*pow(x2*x2+y2*y2,0.5));
		degree=acos(cos)*180/3.1415926535;
		if(degree>180)
		degree=360-degree;
		printf("%.2f\n",degree);
	}
	return 0;
}

