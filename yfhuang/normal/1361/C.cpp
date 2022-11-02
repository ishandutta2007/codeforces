#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 2e6 + 10;

int fa[maxn];

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int a[maxn];
int b[maxn];

bool vis[maxn];

struct edge{
    int to, id, u, v;
};

vector<edge> G[maxn];
vector<pi> ans;

void dfs(int u, pi last){
    while(G[u].size() > 0){
        auto e = G[u].back(); G[u].pop_back();
        if(vis[e.id]) continue;
        vis[e.id] = true;
        dfs(e.to, {e.u, e.v});
    }
    if(last != mp(-1, -1)) ans.push_back(last);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    for(int S = 20;S >= 0;S--){
        int mask = (1 << S) - 1;
        ans.clear();
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i <= mask;i++){
            G[i].clear();
        }
        for(int i = 1;i <= n;i++){
            int a1 = a[i] & mask, b1 = b[i] & mask;
            G[a1].push_back({b1, i, 2 * i - 1, 2 * i});
            G[b1].push_back({a1, i, 2 * i, 2 * i - 1});
        }
        bool flag = true;
        for(int i = 0;i <= mask;i++){
            if(G[i].size() & 1){
                flag = false;
            }
        }
        if(!flag)
            continue;
        for(int i = 0;i <= mask;i++){
            if(G[i].size()){
                dfs(i, {-1, -1});
                break;
            }
        }
        if(ans.size() == n){
            cout << S << endl;
            for(int i = 0;i < n;i++){
                cout << ans[i].se << " " << ans[i].fi << (i == n - 1 ? '\n' : ' ');
            }
            return 0;
        }
    }
    return 0;
}