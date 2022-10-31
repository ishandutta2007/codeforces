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

class Eratosthenes{
    public:
    int m;
    vector<bool> is_prime;
    vector<int> primes;
    Eratosthenes(int m_){
        m = m_;
        init();
    }
    private:
    void init(){
        is_prime.assign(m+1, true);
        is_prime[0] = false, is_prime[1] = false;
        for(int i = 2; i <= m; i++){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = 2; i*j <= m; j++) is_prime[i*j] = false;
            }
        }
    }
};

Eratosthenes et(100);
int mebius[100];

const ll inf = 2e18;

ll pow_ll(ll n, int r){
    ll ans = 1;
    for(int i = 0; i < r; i++) {
        if(ans > inf/n) return inf;
        ans *= n;
    }
    return ans;
}

ll root_ll(ll n, int r){
    long long x = pow(n, 1.0/(double)r)+0.1;
    while(pow_ll(x, r) > n) x--;
    while(pow_ll(x+1, r) <= n) x++;
    // assert(pow_ll(x, r) <= n);
    // assert(pow_ll(x+1, r) > n);
    return x;
}

void init(){
    for(int i = 0; i < 100; i++) {
        mebius[i] = 1;
        for(int p: et.primes){
            if(i%p == 0){
                if(i%(p*p) == 0) mebius[i] = 0;
                else mebius[i] *= -1;
            }
        }
    }
}

void solve(){
    ll n; cin >> n;
    ll ans = 0;
    for(int i = 1; i < 60; i++){
        if(mebius[i] == 0) continue;
        ans += mebius[i]*(root_ll(n, i)-1);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}