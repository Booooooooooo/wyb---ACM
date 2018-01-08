#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORD(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn=26;
using namespace std;
int n,m;
int tot;
map<string,int> mpsi;
vector<string> vs;
int g[maxn][maxn];
int vis[maxn];
void init(){
	memset(vis,0,sizeof(vis));
	memset(g,0,sizeof(g));
	mpsi.clear();
	vs.clear();
	tot=0;
}
void input(){
	while(m--){
		string s1,s2;
		cin>>s1>>s2;
		if(!mpsi.count(s1)){mpsi[s1]=tot++;vs.push_back(s1);}
		if(!mpsi.count(s2)){mpsi[s2]=tot++;vs.push_back(s2);}
		g[mpsi[s1]][mpsi[s2]]=1;
	}
}
void floyd(){
	REP(k,n)REP(i,n)REP(j,n){
		g[i][j]=(g[i][j]||(g[i][k]&&g[k][j]));
	}
}
void dfs(int u){
	vis[u]=1;
	REP(v,n){
		if(!vis[v]&&(g[u][v]&&g[v][u])){
			cout<<", "<<vs[v];
			dfs(v);
		}
	}
}
int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.cpp","r",stdin);
//#endif // ONLINE_JUDGE
	int Cas=1;
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		input();
		floyd();
		if(Cas>1) cout<<endl;
		printf("Calling circles for data set %d:\n",Cas++);
		REP(i,n){
			if(!vis[i]){cout<<vs[i];dfs(i);cout<<endl;}
		}
	}
	return 0;
}
