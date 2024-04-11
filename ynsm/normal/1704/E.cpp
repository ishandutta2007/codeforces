#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1050, inf = 1e9, mod = 998244353;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mult(int a, int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return bp(x, mod - 2);
}

int n, m, a[N];
bool was[N];
vector< int > g[N];

struct kek{
    int val;
    bool flag;
    kek(){
        val = 0;
        flag = false;
    }
    kek(int x){
        if(x < mod) {
            val = x;
            flag = false;
        }else{
            val = x % mod;
            flag = true;
        }
    }
    kek operator +(kek other){
        kek res;
        res.flag = flag | other.flag;
        res.val = sum(val, other.val);
        if(res.val != val + other.val)
            res.flag = 1;
        return res;
    }
    kek operator *(kek other){
        kek res;
        res.flag = flag | other.flag;
        res.val = mult(val, other.val);
        if(res.val != 1ll * val * other.val)
            res.flag = 1;
        return res;
    }
} dp[N][N];

void dfs(int v){
    if(was[v])
        return;
    for(int i = 0; i <= n; i++)
        dp[v][i] = kek();
    was[v] = 1;

    if(g[v].empty()){
        dp[v][0] = kek(1);
        return;
    }

    for(auto to : g[v]){
        dfs(to);
        for(int i = 0; i < n; i++)
            dp[v][i + 1] = dp[v][i + 1] + dp[to][i];
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        g[i].clear();
        was[i] = 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].pb(u);
    }
    for(int i = 0; i < n; i++)
        dfs(i);

    int ans = 0;
    kek cur = kek(0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++)
            if(dp[j][i].flag || dp[j][i].val)
                if(a[j])
                    cur = cur + (dp[j][i] * kek(a[j]));
        if(cur.flag){
            cur.val = sub(cur.val, 1);
            ans = sum(cur.val, i + 1);
        }else if(cur.val > 0){
            cur.val = sub(cur.val, 1);
            ans = sum(cur.val, i + 1);
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}