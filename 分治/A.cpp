#include<stdio.h>

char str[8005];
int num[26]={0};
int main()
{
	int n,i,cnt=0;
	char *p;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",str);
		int len=strlen(str);
		for(p=str;p!='\0';p++)
		{
			num[*p-'a']++;
		}
		if(len%2)
		{
			for(i=0;i<26;i++)
			{
				if(num[i]%2)
					cnt++;
				if(cnt>1)
				{
					printf("Impossible\n");
					break;
			}	
		}
		else 
		{
			for(i=0;i<26;i++)
			{
				if(num[i]%2)
				{
					printf("Impossible\n");
					break;	
				}
			}	
		}
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len-1;j++)
			{
				if (str[i]==str[j])
				{
					temp=str[j];
					str[j]=str[len-2-i];
					str[len-2-i]=temp;
					ans++;
				}
				
			}
			if(j==len-1)
			{
				temp=str[len/2+1];
				str[len/2+1]=str[j-1];
				str[j-1]=temp;
			}
		}
	 } 
	return 0;
 } 
