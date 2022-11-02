#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 3e5 + 5;
int n, m;
ll x, a[maxn];
int fa[maxn];

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

vector<int> F, B;
vector<pi> G[maxn];

ll dfs(int u, int fa, int id){
    for(auto e : G[u]){
        int v = e.fi;
        int eid = e.se;
        if(v == fa)
            continue;
        a[u] += dfs(v, u, eid);
    }
    if(a[u] >= x){
        F.push_back(id);
        return a[u] - x;
    }else{
        B.push_back(id);
        return 0;
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        int fu = Find(u);
        int fv = Find(v);
        if(fu != fv){
            fa[fu] = fv;
            G[u].push_back(mp(v, i));
            G[v].push_back(mp(u, i));
        }
    }
    if(sum >= x * (n - 1)){
        cout << "YES" << endl;
        dfs(1, 1, -1);
        reverse(B.begin(), B.end());
        for(auto v : F){
            if(v > 0)
                cout << v << endl;
        }
        for(auto v : B){
            if(v > 0)
                cout << v << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}