#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, ui[303000], vi[303000];

set<int>S[303000];

ll X, a[303000];

#define pli pair<ll,int>
#define fi first
#define se second

priority_queue<pli>q;

int fa[303000];
int GF(int x){
    return x==fa[x]? x: fa[x]=GF(fa[x]);
}

void mg(set<int>&a,set<int>&b){
    if (a.size()<b.size()) swap(a,b);
    for (auto o:b) a.insert(o);
}

int main(){
    cin>>n>>m>>X;
    ll sum=0;
    for (int i=1;i<=n;++i)
        scanf("%lld",&a[i]), q.push({a[i],i}), fa[i]=i, sum+=a[i];
    if (sum<(n-1)*X){
        puts("NO"); return 0;
    }
    for (int i=1;i<=m;++i){
        scanf("%d%d",&ui[i],&vi[i]);
        S[ui[i]].insert(i);
        S[vi[i]].insert(i);
    }
    vector<int>vec;
    for (int T=n-1;T--;){
        pli p; int c, done=0;
        while (1){
            p=q.top(); c=p.se; q.pop();
            if (GF(c)==c&&a[c]==p.fi) break;
        }
        while (S[c].size()){
            int o;
            for (auto t:S[c]){
                o=t; break;
            }
            int u=ui[o], v=vi[o];
            if (GF(u)==GF(v)) S[c].erase(o);
            else break;
        }
        for (auto o:S[c]){
            int u=ui[o], v=vi[o];
            if (GF(u)==GF(v)) continue;
            // if (a[u]+a[v]<X) assert(0);
            if (GF(v)==GF(c)) swap(u,v);
            mg(S[GF(v)],S[GF(u)]);
            a[GF(v)]+=a[GF(u)]-X;
            q.push({a[GF(v)],GF(v)});
            fa[GF(u)]=GF(v); a[u]=-1e18;
            vec.push_back(o); done=1; break;
        }
        if (!done){
            puts("NO"); return 0;
        }
    }
    puts("YES");
    for (auto o:vec) printf("%d\n",o);
}