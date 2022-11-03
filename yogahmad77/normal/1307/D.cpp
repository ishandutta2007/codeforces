#include <bits/stdc++.h>
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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> penting(k), ya(n, 0);
    for(int &i : penting){
        cin >> i;
        i -= 1;
        ya[i] = 1;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        g[u].pb(v);
        g[v].pb(u);
    }
    function<void(int, vector<int>&)> bfs = [&](int s, vector<int> &dist){
        for(int i = 0; i < n; i++) dist[i] = -1;
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int i : g[x]){
                if(dist[i] == -1){
                    dist[i] = dist[x] + 1;
                    q.push(i);
                }
            }
        }
    };
    vector<int> a(n), b(n);
    bfs(0, a);
    bfs(n - 1, b);
    // udah ada
    for(int i = 0; i < n; i++){
        for(int x : g[i]){
            if(ya[i] && ya[x]){
                cout << a[n - 1] << '\n';
                return;
            }
        }
    }
    // dua dua nya lebih deket
    auto ve = penting;
    sort(ALL(ve), [&](int i, int j){
        if(a[i] == a[j]) return b[i] < b[j];
        return a[i] < a[j];
    });
    int mini = 1e9;
    for(int i : ve){
        if(mini <= b[i]){
            cout << a[n - 1] << '\n';
            return;
        }
        mini = min(mini, b[i]);
    }
    int maks = 0;
    for(int i = 1; i < k; i++){
        int x = ve[i - 1];
        int y = ve[i];
        maks = max(maks, a[x] + b[y] + 1);
    }
    int ans = min(maks, a[n - 1]);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}