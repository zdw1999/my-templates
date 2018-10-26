/*


定义一条路径的道路为该路径上所有边的"与"
问A->B的最短路

2<=n<=200000 , 0<=m<=200000
T<=100000

分别计算每个联通块内的所有边的与即可
注意特判s==t时dis==0

*/
#include <bits/stdc++.h>
const int N=200005;

struct edge{int f,t,v;edge(){}}E[N];
std::vector<int>G[N];
int C[N],ctot,n,m,T,s,t;
int ans[N],cnt;
/*
void dfs(int u){
    printf("%d %d\n",C[u],u);
    if(C[u])return; C[u]=ctot;
    for(auto v:G[u])
        if(!C[v])dfs(v);
}*/

int Q[N],l,r;
void bfs(int u){
    Q[l=r=0]=u;
    while(l<=r){
        u=Q[l++];
        for(auto &v:G[u])
            if(!C[v])C[Q[++r]=v]=ctot;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        E[i].f=x; E[i].t=y; E[i].v=z;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
        if(!C[i]){
            ans[++ctot]=0x7fffffff;
            bfs(i);
        }
    for(int i=1;i<=m;++i)
        //C[E[i].f]==C[E[i].t]
        ans[C[E[i].f]]&=E[i].v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&s,&t);
        if(s==t)printf("0\n");
        else if(C[s]!=C[t])printf("-1\n");
        else printf("%d\n",ans[C[s]]);
    }return 0;
}
