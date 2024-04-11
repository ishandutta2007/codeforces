#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

int n;
ll a[N], l[N], r[N], ans;
vector< int > g[N];
void dfs(int v){
    a[v] = 0;
    for(auto to : g[v]){
        dfs(to);
        a[v] += a[to];
    }
    a[v] = min(a[v], r[v]);
    if(a[v] < l[v])
        ans++, a[v] = r[v];
}
void solve() {
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        g[p].pb(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    dfs(1);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}