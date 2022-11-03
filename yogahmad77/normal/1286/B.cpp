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


const int mx = 1e5 + 10;

int n, p[mx], c[mx], level[mx], a[mx];
vector<int> g[mx];

void dfs(int now, int lev){
    level[now] = lev;
    for(int i : g[now]) dfs(i, lev + 1);
}

void solve(){
    cin >> n;
    int root;
    for(int i = 1; i <= n; i++){
        cin >> p[i] >> c[i];
        if(p[i] == 0) root = i;
        else g[p[i]].pb(i);
    }
    reset(a, -1);
    dfs(root, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 1; i <= n; i++){
        if(c[i] == 0){
            pq.push({level[i], i});
        }
    }
    int idx = 0;
    while(!pq.empty()){
        int now = pq.top().s;
        a[now] = ++idx;
        pq.pop();
        while(now != 0){
            if(c[now] > 0){
                c[now] -= 1;
                if(c[now] == 0){
                    pq.push({level[now], now});
                }
            }
            else assert(a[now] != -1);
            now = p[now];
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == -1){
            cout <<"NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }
}