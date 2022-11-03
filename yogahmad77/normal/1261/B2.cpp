#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ve(n);
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int x, int y){
        if(a[x] == a[y]) return x < y;
        return a[x] > a[y];
    });
    int q;
    cin >> q;
    vector<int> x(q), y(q), jaw(q);
    vector<vector<int>> query(n);
    for(int i = 0; i < q; i++){
        cin >> x[i] >> y[i];
        query[x[i] - 1].pb(i);
    }
    pbds ini;
    for(int i = 0; i < n; i++){
        ini.insert(ve[i]);
        for(int j : query[i]){
            auto it = ini.find_by_order(y[j] - 1);
            jaw[j] = *it;
        }
    }
    for(int i : jaw) cout << a[i] << '\n';
}