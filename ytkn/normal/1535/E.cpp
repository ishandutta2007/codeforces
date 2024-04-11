#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

int par[300005][20];

int get_par(int v, int up){
    int cur = v;
    for(int i = 0; i < 20; i++){
        if(up&(1<<i)) cur = par[cur][i];
    }
    return cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    vector<ll> a(q+1), c(q+1);
    vector<int> depth(q+1);
    cin >> a[0] >> c[0];
    for(int i = 0; i < 20; i++) par[0][i] = 0;
    auto add = [&](int v, int p){
        par[v][0] = p;
        depth[v] = depth[p]+1;
        for(int i = 1; i < 20; i++) par[v][i] = par[par[v][i-1]][i-1];
    };
    auto ask = [&](int v, ll w){
        if(a[v] == 0){
            cout << 0 << ' ' << 0 << endl;
            return;
        }
        int d;
        if(a[0] > 0) d = depth[v];
        else{
            int l = 0, r = depth[v];
            while(r-l > 1){
                int c = (l+r)/2;
                int u = get_par(v, c);
                if(a[u] == 0) r = c;
                else l = c;
            }
            d = l;
        }
        ll paid = 0;
        ll got = 0;
        for(int i = d; i >= 0; i--){
            int u = get_par(v, i);
            // cout << "visit:" << u << ' ';
            if(got+a[u] >= w){
                a[u] -= w-got;
                paid += (w-got)*c[u];
                got = w;
                break;
            }else{
                paid += c[u]*a[u];
                got += a[u];
                a[u] = 0;
            }
        }
        // cout << endl;
        cout << got << ' ' << paid << endl;
    };
    for(int i = 1; i <= q; i++){
        int t; cin >> t;
        if(t == 1){
            int p; cin >> p >> a[i] >> c[i];
            add(i, p);
        }else{
            int v; ll w; cin >> v >> w;
            ask(v, w);
            // for(int j = 0; j <= i; j++) cout << j << ':' << a[j] << ',' << c[j] << ' ';
            // cout << endl;
        }
    }
}