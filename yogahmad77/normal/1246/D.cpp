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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int n, p[mx], sz[mx], level[mx];
vector<int> g[mx], ve;
void dfs(int now){
    sz[now] = 1;
    level[now] = 0;
    for(int i : g[now]){
        dfs(i);
        sz[now] += sz[i];
        level[now] = max(level[now], level[i] + 1);
    }
    sort(ALL(g[now]), [&](int x, int y){ return level[x] < level[y]; });
}

void DFS(int now){
    ve.pb(now);
    for(int i : g[now])
        DFS(i);
}

int depan[mx];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> p[i];
        g[p[i]].pb(i);
    }
    dfs(0);
    DFS(0);
    vector<int> ans;
    int sampai = n;
    for(int i = 1; i < n; i++) depan[ve[i]] = ve[i - 1];
    for(int i = 1; i < n; i++){
        while(depan[ve[i]] != p[ve[i]]){
            ans.pb(ve[i]);
            depan[ve[i]] = depan[depan[ve[i]]];
        }
    }
    for(int i : ve) cout << i << ' ';
    cout << endl;
    cout << sz(ans) << endl;
    for(int i : ans) cout << i << ' ';
}