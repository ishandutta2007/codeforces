#include <bits/stdc++.h>
using namespace std;

const int N = 206;
int f[N], n;
int ff[N];

bool ok() {
    for (int i = 1; i <= n; ++i) {
        if (ff[ ff[i] ] != ff[i]) return false;
    }
    return true;
}

void doo() {
    vector<int> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        g[i] = f[ ff[i] ];
    }
    for (int i = 1; i <= n; ++i) {
        ff[i] = g[i];
    }
}
#define REP(i, j, k) for (int (i) = (j); (i) < (k); ++(i))
void extgcd(long long a , long long b , long long &d , long long &x , long long &y){
    if(b == 0) d = a , x = 1 , y = 0;
    else extgcd(b , a % b , d , y , x) , y -= (a / b) * x;
}
vector<long long> v , m;
typedef long long ll;
struct Solver{
    pair<ll, ll> solve(vector<ll> v, vector<ll> m) {
        long long ans , mod , d , x , y;
        n = (int)v.size();
        mod = m[0] , ans = v[0];
        REP(i , 1 , n){
            long long res = ((v[i] - ans) % m[i] + m[i]) % m[i];
            extgcd(mod , m[i] , d , x , y);
            if(res % d != 0){ ans = -1; break; }

            res = (res / d * x % m[i] + m[i]) % m[i];
            ans = ans + res * mod;
            mod = mod * m[i] / d;
        }
        return {ans, mod};
        /*if(ans == -1) cout << ans << endl;
        else cout << ans % mod << endl;*/
    }
    //return 0;
} solver;

struct DJS{
    int p[N];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int Find(int x) {
        return p[x] == x ? x: p[x] = Find(p[x]);
    }
    void Union(int x, int y) {
        p[Find(x)] = Find(y);
    }
} djs;

int last_ok[N];
bool found[N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        ff[i] = f[i];
    }
    for (int k = 1; k <= 2 * n * n; ++k) {
        if (ok()) {
            printf("%d\n", k);
            return 0;
        }
        doo();
    }
    djs.init(n);
    for (int i = 1; i <= n; ++i) {
        djs.Union(i, f[i]);
    }
    vector<ll> v, m;
    for (int k = 2 * n * n + 1; ; ++k) {
        bool all_found = true;
        for (int i = 1; i <= n; ++i) {
            if (djs.Find(i) == i) all_found &= found[i];
        }
        if (all_found) break;
        //cout << "k = " << k << endl;
        if (ok()) {
            printf("%d\n", k);
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (djs.Find(i) == i && !found[i] && ff[ ff[i] ] == ff[i]) {
                if (last_ok[i] == 0) last_ok[i] = k;
                else {
                    //cout << "i = " << i << " , lastok = " << last_ok[i] << " , k = " << k << endl;
                    m.push_back(k - last_ok[i]);
                    found[i] = true;
                    v.push_back(k % m.back());
                    //cout << "m = " << m.back() << endl;
                }
            }
        }
        doo();
    }
    pair<ll, ll> ret = solver.solve(v, m);
    ll ans = ret.first;
    while (ans <= 2 * n * n) ans += ret.second;
    cout << ans << endl;
}