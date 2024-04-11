#include<bits/stdc++.h>
using namespace std;

struct mat{
    bitset<155>b[155];
}I, nil, now, bas;

int n, m, ans=2e9, d[155];
vector<int>G[155];
struct E{
    int u, v, w;
}e[155];

mat operator * (mat a,mat b){
    mat c=nil;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (a.b[i][j])
                c.b[i]|=b.b[j];
    return c;
}
mat POW(mat x,int y){
    mat t=I;
    for (;y;y>>=1,x=x*x)
        if (y&1) t=t*x;
    return t;
}

void bfs(int els){
    queue<int>q;
    memset(d,-1,sizeof d);
    for (int i=1;i<=n;++i)
        if (now.b[1][i]) d[i]=0, q.push(i);
    for (;q.size();){
        int x=q.front(); q.pop();
        for (auto y:G[x])
            if (d[y]<0)
                d[y]=d[x]+1, q.push(y);
    }
    if (d[n]>=0) ans=min(ans,d[n]+els);
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;

    for (int i=1;i<=n;++i) I.b[i][i]=1;
    now=I;

    sort(e+1,e+m+1,[](E a,E b){return a.w<b.w;});
    for (int i=1;i<=m;++i){
        now=now*POW(bas,e[i].w-e[i-1].w);
        G[e[i].u].push_back(e[i].v);
        bas.b[e[i].u][e[i].v]=1;
        bfs(e[i].w);
    }
	if (ans>1.9e9) puts("Impossible");
    else cout<<ans<<endl;
}