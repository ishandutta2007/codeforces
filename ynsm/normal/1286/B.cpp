#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N], a[N];
int n, p[N], c[N], b[N], ans[N], root;
int dfs(int v){
     if(a[v].size() == c[v]){
        a[v].pb(v); 
        ans[v] = a[v].size();
    }
    for(auto to : g[v]){
        dfs(to);
        for(auto i : a[to]){
            a[v].pb(i);
            ans[i] = a[v].size();
            if(a[v].size() == c[v]){
                a[v].pb(v); 
                ans[v] = a[v].size();
            }
        }
    }
    if(ans[v] == 0){
        cout << "NO";
        exit(0);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i] >> c[i];
        g[p[i]].pb(i);
        if(p[i] == 0)
            root = i;
    }
    dfs(root);
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}