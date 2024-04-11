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
const int mx = 2e5 + 10;

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

int a[mx], n, q, harus[mx], jadi[mx];
map<pair<int, int>, int> apa;
long long jaw = 0;

void hapus(int s, int t){
    int u = apa[{s, t}];
    harus[u] += 1;
    if(harus[u] > 0) jaw += 1;
}

void tambah(int s, int t, int u){
   harus[u] -= 1;
   if(harus[u] >= 0) jaw -= 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], jaw += a[i];
    for(int i = 1; i <= n; i++) harus[i] = jadi[i] = a[i];
    cin >> q;
    while(q--){
        int s, t, u;
        cin >> s >> t >> u;
        if(apa.count({s, t})) hapus(s, t);
        apa.erase({s, t});
        if(u == 0){
            cout << jaw << '\n';
            continue;
        }
        apa[{s, t}] = u;
        tambah(s, t, u);
        cout << jaw << '\n';
    }
}