#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pq priority_queue<pll,vector<pll>,greater<pll> >
ll dc[303000];
pq q[303000];

int n, m, dep[303000]; ll ans;
vector<int>G[303000];

void mg(pq &qx,ll &dx,pq &qy,ll &dy){
    if (qx.size()<qy.size()) swap(qx,qy), swap(dx,dy);
    while (qy.size()){
        pll o=qy.top(); qy.pop();
        qx.push({o.fi-dy+dx,o.se});
    }
}

void dfs(int x,int fff){
    dep[x]=dep[fff]+1;
    for (auto y:G[x])
        if (y!=fff){
            dfs(y,x);
            mg(q[x],dc[x],q[y],dc[y]);
        }
    if (x==1) return;
    while (q[x].size()&&dep[q[x].top().se]>=dep[x]) q[x].pop();
    if (!q[x].size()) exit(puts("-1")*0);
    ll res=q[x].top().fi-dc[x];
    ans+=res; dc[x]+=res;
}

int main(){
    cin>>n>>m;
    for (int i=1;i<n;++i){
        int x, y; scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i=1;i<=m;++i){
        int x, y, z; scanf("%d%d%d",&x,&y,&z);
        q[x].push({z,y});
    }
    dfs(1,0);
    cout<<ans<<endl;
}