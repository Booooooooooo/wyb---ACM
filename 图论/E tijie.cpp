#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int sets[30000] ; ///nan + 10000 ;
int find(int x){
    return sets[x] == x ? x : sets[x] = find(sets[x]) ;
}
void unionset(int x,int y){
    int fx = find(x) ; int fy = find(y) ;
    sets[fx] = fy ;
}
struct node{
    int s,e ,w;
    bool operator < (const node & A)const{
        return w < A.w ;
    }
}Edge[100000] ;
int main(){
    ///freopen("1" ,"r" ,stdin) ;
    int T ; scanf("%d",&T );
    while(T --){
        for(int i=0;i<30000;i++) sets[i] = i ;
        int n,m,k ;
        scanf("%d%d%d",&n,&m,&k) ;
        int cnt  =0 ;
        for(int i=0;i<k;i++){
            int ta, tb  ,tc;
            scanf("%d%d%d",&ta,&tb,&tc) ;
            tb += 10000 ;
            Edge[cnt].s = ta ; Edge[cnt].e = tb ; Edge[cnt++].w = 10000 - tc ;
        }
        int ans = 0 ;
        int ct = 0 ;
        sort(Edge , Edge+cnt) ;
        for(int i=0;i<cnt;i++){
            int s = Edge[i].s ;int e = Edge[i].e ;
            if(find(s) != find(e)){
                ans += Edge[i].w ;
                ct ++ ;
                unionset(s , e) ;
            }
        }
        printf("%d\n",10000*(n+m-ct) + ans) ;
    }
}
