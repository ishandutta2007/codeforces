#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k, p, h[101000], a[101000], now[101000];

ll ddl(int i){
    return m-now[i]/a[i];
}
struct cmp{
    bool operator ()(int i,int j){
        return ddl(i) < ddl(j);
    }
};
priority_queue<int,vector<int>,cmp>q, emq;

bool check(ll org){
    q=emq;
    for (int i=1;i<=n;++i){
        now[i]=org;
        if (ddl(i)>0) q.push(i);
    }
    ll els=0;
    for (int i=m-1;i>=0;--i){
        if (q.size()) if (ddl(q.top())>i) return 0;
        vector<int>todo, todo2;
        for (int T=min(k,n);T--;){
            if (q.size()){
                todo.push_back(q.top()), q.pop();
            }else{
                ++els;
            }
        }
        for (auto x:todo){
            now[x]+=p;
            if (ddl(x)>0) q.push(x);
        }
    }
    // for (int i=1;i<=n;++i)
    //     printf(" %lld\n",now[i]-m*a[i]);
    // printf(" -- %lld\n",els);
    if (q.size()) return 0;
    for (int i=1;i<=n;++i){
        ll need=h[i]-(now[i]-m*a[i]);
        if (need<=0) continue;
        els-=(need+p-1)/p;
        if (els<0) return 0;
    }
    return 1;
}

int main(){
    //ios::sync_with_stdio(0);
    cin>>n>>m>>k>>p;
    for (int i=1;i<=n;++i)
        cin>>h[i]>>a[i];
    //cout<<check(15)<<endl; return 0;
    ll l=1, r=1e16, ans=-1;
    while (l<=r){
        ll mid=l+r>>1;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
}