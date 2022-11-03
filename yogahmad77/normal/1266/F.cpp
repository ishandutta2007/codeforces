#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
 
 
const int MOD = 1e9 + 7;
const int mx = 1e6 + 10;
 
/////////////////////////////
int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}
/////////////////////////////
 
int n, depth[mx], atas[mx], P[mx];
vector<int> g[mx];
 
void dfs(int now, int par){
    P[now] = par;
    depth[now] = 0;
    for(int i : g[now]){
        if(i == par) continue;
        dfs(i, now);
        depth[now] = max(depth[now], depth[i] + 1);
    }
}
 
void DFS(int now, int par, int maks){
    atas[now] = maks;
    int maks2 = 0;
    int maks1 = maks;
    int di1 = 0, di2 = 0;
    vector<int> ve;
    for(int i : g[now]){
        if(i == par) continue;
        if(depth[i] + 1 > maks1){
            maks2 = maks1;
            di2 = di1;
            di1 = i;
            maks1 = depth[i] + 1;
        }
        else if(depth[i] + 1 > maks2){
            maks2 = depth[i] + 1;
            di2 = i;
        }
    }
    for(int i : g[now]){
        if(i == par) continue;
        if(i == di1) DFS(i, now, maks2 + 1);
        else DFS(i, now, maks1 + 1);
    }
}
 
int ans[mx], ans2[mx], ans3[mx];
set<int> nilai;
vector<int> satu, dua;
map<int, int> dp1, dp2;
void hitung(int now, int par){
    nilai.clear(); satu.clear(); dua.clear();
    dp1.clear(); dp2.clear();
    if(par != 0){
        nilai.insert(atas[now]);
        satu.push_back(atas[now]);
    }
    for(int j : g[now]){
        if(j == par) continue;
        nilai.insert(depth[j] + 1);
        satu.pb(depth[j] + 1);
        dua.clear();
        for(int k : g[j]){
            if(now == k) continue;
            nilai.insert(depth[k] + 1);
            dua.pb(depth[k] + 1);
        }
        sort(ALL(dua));
        reverse(ALL(dua));
        int count = 0;
        for(auto i : dua){
            count += 1;
            dp2[i] = max(dp2[i], count);
        }
    }
    sort(ALL(satu));
    reverse(ALL(satu));
    int count = 0;
    for(auto i : satu){
        count += 1;
        dp1[i] = count;
    }
 
    for(auto i : nilai){
        if(!dp2.count(i)) dp2[i] = 0;
        if(!dp1.count(i)) dp1[i] = 0;
    }
    for(auto ii = nilai.rbegin(); ii != nilai.rend(); ii++){
        auto i = *ii;
        auto it = nilai.upper_bound(i);
        if(it == nilai.end()) continue;
        dp2[i] = max(dp2[*it], dp2[i]);
        dp1[i] = max(dp1[*it], dp1[i]);
    }
    for(auto i : nilai){
        ans3[i + i] = max(ans3[i + i], dp1[i] + dp2[i] - 1);
    }
    for(int i : g[now]){
        if(i != par)
            hitung(i, now);
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    DFS(1, 0, 0);
    for(int i = 1; i <= n; i++) ans[1] = max(ans[1], sz(g[i]) + 1);
    for(int i = 1; i <= n; i++){
        vector<int> ve;
        if(P[i] != 0) ve.push_back(atas[i]);
        for(int j : g[i]){
            if(j == P[i]) continue;
            ve.push_back(depth[j] + 1);
        }
        sort(ALL(ve));
        auto vv = ve;
        reverse(ALL(ve));
        int count = 0;
        int tadi = -1;
        for(int j : ve){
            count += 1;
            // genap
            ans[j + j] = max(ans[j + j], count);
            ans[j + j - 1] = max(ans[j + j - 1], count);
            if(binary_search(ALL(vv), j - 1)) ans2[j + j - 1] = max(ans2[j + j - 1], count + 1);
            if(tadi != j){
                ans2[j + j + 1] = max(ans2[j + j + 1], count);
            }
            tadi = j;
        }
    }
    hitung(1, 0);
    for(int i = n + n + 3; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
    for(int i = n + n + 3; i >= 1; i--) ans2[i] = max(ans2[i], ans2[i + 1]);
    for(int i = n + n + 3; i >= 1; i--) ans3[i] = max(ans3[i], ans3[i + 1]);
    for(int i = 1; i <= n; i++){
        ans[i] = max(ans[i], 1);
        if(i % 2 == 0){
            cout << max(ans[i], ans3[i]) << ' ';
        }
        else cout << max(ans[i], ans2[i]) << ' ';
    }
}