#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set <string> dict;
int main()
{
	string s,buf;
	while (cin>>s){
		for(int i=0;i<s.length();i++)
		{
			if(isalpha(s[i])) s[i]=tolower(s[i]);  //isalpha ÅÐ¶ÏÊÇ·ñÎª×ÖÄ¸  tolower½«´óÐ´×ÖÄ¸»»³ÉÐ¡Ð´×ÖÄ¸ 
			else s[i]=' ';
			stringstream ss(s);
			while(ss>>buf) 
			dict.insert(buf);
		}
		for(set <string>::iterator it =dict.begin();it!=dict.end();++it)
		cout<<*it<<"\n";
		return 0;
	}
}
