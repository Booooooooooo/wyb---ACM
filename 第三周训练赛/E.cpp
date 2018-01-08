#include<stdio.h>
int main()
{
	char s[200005];
	while (scanf("%s",s)!=EOF)
	{
		int i=0,len=0;
		while(s[i]>='a'&&s[i]<='z')
		{
			len++;
			i++;
		}
		//len =sizeof(s)/sizeof(char);
		for(i=0;i<len-1;i++)
		//while (s[i]!='\0')
		{
			if(s[i+1]==s[i])
			{
				char c;
				for(c='a';c<='z';c++)
				{
					if(c!=s[i+2]&&c!=s[i])
					{
						s[i+1]=c;
						break;
					}
				}
				/*if(i==0)
				s[i]=s[len-1];
				else 
				s[i+1]=s[i-1];*/
			}
	
		}
		printf("%s\n",s);		
	}
	return 0;
 } 
