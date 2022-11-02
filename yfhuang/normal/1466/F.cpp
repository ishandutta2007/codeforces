#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m;
const int mod = 1e9 + 7;

const int maxn = 5e5 + 5;
int fa[maxn];
int have[maxn];
int sz[maxn];

int Find(int x){
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}

int qpow(int a, int p){
    int ret = 1;
    while(p > 0){
        if(p & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        p >>= 1;
    }
    return ret;
}

vector<vector<int> > edges;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        vector<int> edge;
        for(int j = 1;j <= k;j++){
            int u;
            cin >> u;
            edge.push_back(u);
        }
        edges.push_back(edge);
    }
    for(int i = 1;i <= m;i++){
        fa[i] = i;
        have[i] = 0;
        sz[i] = 1;
    }
    vector<int> ans_edges;
    for(int i = 0;i < n;i++){
        if(edges[i].size() == 1){
            int u = edges[i][0];
            int fu = Find(u);
            if(have[fu] == 0){
                have[fu] = i + 1;
            }
        }else{
            int u = edges[i][0];
            int v = edges[i][1];
            int fu = Find(u);
            int fv = Find(v);
            if(fu != fv){
                if(have[fu] and have[fv])
                    continue;
                ans_edges.push_back(i + 1);
                fa[fu] = fv;
                sz[fv] += sz[fu];
                if(have[fu]){
                    have[fv] = have[fu];
                }
            }
        }
    }
    int ans = 1;
    for(int i = 1;i <= m;i++){
        int fx = Find(i);
        if(fx == i){
            int tmp = 0;
            if(have[i]){
                tmp = qpow(2, sz[i]);
                ans_edges.push_back(have[i]);
            }else{
                tmp = qpow(2, sz[i]-1);
            }
            ans = 1LL * ans * tmp % mod;
        }
    }
    sort(ans_edges.begin(), ans_edges.end());
    cout << ans << " " << ans_edges.size() << endl;
    for(int i = 0;i < ans_edges.size();i++){
        cout << ans_edges[i] << ((i == ans_edges.size() - 1) ? '\n' : ' ');
    }
    return 0;
}