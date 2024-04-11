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
typedef int (*func)(int, int);




const int mx = 1e5 + 10;

int p(vector<int> &par, int x){
    if(x == par[x]) return x;
    return par[x] = p(par, par[x]);
}

void solve(int tc){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    vector<int> warna(m, -1), par(n);
    iota(ALL(par), 0);
    vector<pair<int, pair<int, int>>> edge;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            y -= 1;
            edge.push_back({a[i] + b[y], {y, i}});
        }
    }
    sort(ALL(edge));
    reverse(ALL(edge));
    long long ans = 0;
    for(auto x : edge){
        if(warna[x.s.f] == -1) warna[x.s.f] = x.s.s;
        else{
            int u = warna[x.s.f];
            int v = x.s.s;
            u = p(par, u);
            v = p(par, v);
            if(u == v){
                ans += x.f;
                continue;
            }
            par[u] = v;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}