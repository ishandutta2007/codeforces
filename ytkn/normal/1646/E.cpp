#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
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

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
const ll inf = 1e18;

ll calc_pow(ll x, int r){
    ll ans = 1;
    for(int i = 0; i < r; i++){
        if(ans > inf/x) return inf;
        ans *= x;
    }
    return ans;
}

int naive(int n, int m){
    set<ll> st = {1};
    for(int x = n; x >= 2; x--){
        int pre = st.size();
        for(int i = 1; i <= m; i++) {
            st.insert(calc_pow(x, i));
        }
        cout << x << ':' << st.size()-pre << endl;
    }
    return st.size();
}

const int M = 1000000;
using P = pair<int, int>;
vector<P> fac[M+1];
int meb[M+1];

void init(){
    vector<int> v(M+1);
    iota(v.begin(), v.end(), 0);
    for(int x = 1; x <= M; x++) meb[x] = 1;
    for(int p = 2; p <= M; p++){
        for(int x = 1; p*x <= M; x++){
            int cnt = 0;
            while(v[x*p]%p == 0){
                cnt++;
                v[x*p] /= p;
            }
            if(cnt > 0){
                fac[x*p].push_back(P(p, cnt));
            }
            if(cnt == 1) meb[x*p] *= -1;
            if(cnt >= 2) meb[x*p] = 0;
        }
    }
}

ll lcm(ll x, ll y){
    ll g = gcd(x, y);
    return (x/g)*y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    ll n, m; cin >> n >> m;
    ll ans = 1;
    vector<ll> cnt(21);
    auto calc = [&](int mx) -> ll{
        ll ans = 0;
        for(int x = 1; x <= mx; x++){
            for(int s = 0; s < (1<<mx); s++){
                int sgn = 1;
                for(int i = 0; i < x; i++){
                    if(s&(1<<i)) {
                        sgn = 0;
                        break;
                    }
                }
                if(sgn == 0) continue;
                ll p = 1;
                for(int i = x; i < mx; i++){
                    if(s&(1<<i)) {
                        sgn *= -1;
                        p = lcm(p, (i+1)/gcd(x, i+1));
                        if(p > m) {
                            p = inf;
                            break;
                        }
                    }
                }
                if(p <= m){
                    ans += sgn*(m/p);
                }
            }
        }
        return ans;
    };
    for(int mx = 1; mx <= 20; mx++) cnt[mx] = calc(mx);
    for(int x = 2; x <= n; x++){
        int g = 0;
        for(auto [a, c]: fac[x]) g = gcd(g, c);
        if(g != 1) continue;
        ll prod = x;
        int mx = 1;
        while(prod*x <= n){
            mx++;
            prod *= x;
        }
        ans += cnt[mx];
    }
    cout << ans << endl;
    // cout << naive(n, m) << endl;
}