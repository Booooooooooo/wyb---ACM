#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct hw
{
	int dead;
	int score;
};
bool cmp(hw a,hw b)//����deadline���� 
{
	if (a.dead != b.dead)  
        return a.dead < b.dead;  
    else return a.score < b.score;
    
	/*if(a.dead<b.dead)
	return true;
	else if(a.dead==b.dead)
	{
		if(a.score<b.score)
		return true;
	}
	else return false;*/
}
bool cmp2(hw a,hw b)//���շ������� 
{
	if(a.score<b.score)
	return true;
	else return false;
}
//���������ݵ�dead��Ϊ4ʱ ���������   
int solve(int &i,hw a[],int &day, int n)
{
	int j,k,cnt=0;
	int max=0;
	int maxj=i;
	for(j=i+1;j<n;j++)//�ҵ������������� 
	{
		if(a[j].score>max)
		{
			maxj=j;
			max=a[j].score;
		}
	}
	sort(a+i+1,a+maxj,cmp2);//����ΰ��������� 
	int s;
	if(i==-1)
	s=(maxj)+1-(a[maxj].dead-day);//s��Ҫ�۵��Ŀγ���Ŀ 
	else s=(maxj-i+1)-(a[maxj].dead-day);
	for(k=i+1;k<i+s+1;k++)
	cnt+=a[k].score;
	i=maxj;
	day =a[maxj].dead;
	return cnt;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		struct hw a[1005];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].dead);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].score);
		}
		int day=0,reduce=0;
		sort(a,a+n,cmp);
		for(i=-1;i<n-1;)
		{
			reduce +=solve( i, a, day, n);
		}
		
		printf("%d\n",reduce);
		/*
		for(i=0;i<n;i++)
		{
			if(a[i].dead>=day)
			day++;
			else 
			reduce +=a[i].score;
		}
		
		
		/*float rate[1005];
		for(i=0;i<n;i++)
		{
			rate[i]=score[i]/dead[i];//rate ԽСԽ���� 
		}
		*/
		
	}
	return 0;
 } 
