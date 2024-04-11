#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
ll a[2222], b[2222];
vector<int>G[2222];

int fl[2222], pre[2222];
ll d[2222];

bool bfs(ll &p){
    memset(d,-1,sizeof d);
    queue<int>q;
    for (int i=1;i<=n;++i) if (fl[i]) q.push(i), d[i]=p, pre[i]=0;
    for (;q.size();){
        int x=q.front(); q.pop();
        for (auto y:G[x]){
            if (y==pre[x]) continue;
            if (d[x]>a[y]||fl[y]){
                if (d[y]==-1){
                    d[y]=d[x]+b[y]; pre[y]=x;
                    q.push(y);
                }else{
                    if (!fl[y]||fl[y]&&!fl[x]){
                        for (int t=x;!fl[t];t=pre[t]){
                            p+=b[t]; fl[t]=1;
                        }
                        for (int t=y;!fl[t];t=pre[t]){
                            p+=b[t]; fl[t]=1;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

bool check(ll p){
    memset(fl,0,sizeof fl); fl[1]=1;
    while (*min_element(fl+1,fl+n+1)==0){
        if (!bfs(p)) return 0;
    }
    return 1;
}

void fuck(){
    cin>>n>>m;
    for (int i=2;i<=n;++i) cin>>a[i];
    for (int i=2;i<=n;++i) cin>>b[i];
    for (int i=1;i<=n;++i) G[i].clear();
    for (int i=1;i<=m;++i){
        int x, y; cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll l=1, r=1e9+7, ans=-1;
    while (l<=r){
        ll mid=l+r>>1;
        if (check(mid)){
            ans=mid; r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int T;
    for (cin>>T;T--;){
        fuck();
    }
}