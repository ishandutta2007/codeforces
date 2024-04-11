#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;
bool vis[maxn];
int n;
int a[maxn];
int b[maxn];

int fa[maxn], rear[maxn];
int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

vector<int> rG[maxn];
int deg[maxn];
int p[maxn];

bool cmp(int u, int v){
    return deg[u] < deg[v];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            fa[i] = i;
            cin >> a[i];
            rG[i].clear();
            deg[i] = 0;
            rear[i] = i;
        }
        for(int i = 1;i <= n;i++){
            deg[a[i]]++;
            rG[a[i]].push_back(i);
        }
        for(int i = 1;i <= n;i++){
            p[i] = i;
        }
        sort(p + 1, p + 1 + n, cmp);
        for(int i = 1;i <= n;i++){
            for(auto v : rG[p[i]]){
                int fx = Find(p[i]);
                int fy = Find(v);
                if(fx != fy){
                    fa[fy] = fx;
                    rear[fx] = rear[fy];
                    b[v] = p[i];
                    break;
                }
            }
        }
        int tot = 0;
        for(int i = 1;i <= n;i++){
            int fx = Find(i);
            if(i == fx){
                if(a[i] != rear[i]){
                    p[tot++] = i;
                }else{
                    b[i] = rear[i];
                }
            }
        }
        for(int i = 0;i < tot;i++){
            int nxt = (i+1) % tot;
            b[p[i]] = rear[p[nxt]];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ans += (b[i] == a[i]);
        }
        cout << ans << endl;
        for(int i = 1;i <= n;i++){
            cout << b[i] << ((i == n) ? '\n' : ' ');
        }
    }
    return 0;
}