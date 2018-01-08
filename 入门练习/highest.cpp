#include<stdio.h>
#include<malloc.h>
int main()
{
	int t,n,i;
	float *h,max;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		h=(float*) malloc (n*sizeof(float));
		for(i=0;i<n;i++)
		{
			scanf("%f",&h[i]);
		}
		max=h[0];
		for(i=1;i<n;i++)
		{
			if(h[i]>max)
			max=h[i];
		}
		printf("%.2f\n",max);
	}
	return 0;
}

