#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n,m,k;
const long long mod=1000000007;
long long a[300005],ni[300005],c[300005],ans[300005];

long long niyuan(long long x)
{
	if(x==1)return 1;
	return niyuan(mod%x)*(mod-mod/x)%mod;
}

long long quick_mod(long long a,long long b){  
    long long ans = 1;  
    while(b){  
        if(b&1) ans=ans*a%mod;  
        b>>=1;  
        a=a*a%mod;  
    }  
    return ans;  
}  
 
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			a[temp]++;
		}
		c[n-k]=1;//c[i]为i个数中取出（k-n）个数的组合数
		//预处理 
		for(int i=n-k+1;i<=n;i++)
		{
			c[i]=c[i-1]*i%mod*niyuan(i-(n-k))%mod;
 		}
		for(int i=m;i>=1;i--)
		{
			int cnt=0;//cnt记录a中是i的倍数的数的个数
			long long ss=0;//ss记录当i=2i，3i，4i...时的结果的和
			for(int j=1;j*i<=m;j++)
			{
				cnt+=a[i*j];
				if(j>1)
				ss=(ss+ans[i*j])%mod;
 			}
 			int t=m/i;//t表示范围内i的倍数的个数 即可以变换的值的个数
			if(t==1)
			{
				if(cnt==n-k) 
				ans[i]=1;
				else 
				ans[i]=0;
				continue;
 			}
 			
 			if(cnt<n-k)
 			{
 				ans[i]=0;
 				continue;
 			}
 			
 			long long temp=1;
 			temp=(temp*c[cnt])%mod;
 			temp=(temp*quick_mod(t,n-cnt))%mod;
 			temp=(temp*quick_mod(t-1,cnt-(n-k)))%mod;
 			ans[i]=(temp-ss+mod)%mod;
		 } 
	 
	 	 
		for(int i=1;i<=m;i++)
		{
			printf("%lld",ans[i]);
			if(i<m)
			printf(" ");
			else 
			printf("\n");
		}
	}
	return 0;
}
