#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>
#include <time.h>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<T> get_vec(int n){
    vector<T> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        // v[i] = rand();
    }
    return v;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    clock_t start = clock();
    int n; cin >> n;
    auto a = get_vec<ll>(n);
    ll g = accumulate(a.begin(), a.end(), (ll)0, [](ll a, ll b){ return gcd(a, b); });
    if(g != 1){
        cout << 0 << endl;
        return 0;
    }
    Eratosthenes erat(1e6);
    auto prime_facs = [&](ll a){
        vector<ll> facs;
        ll m = a;
        for(ll p : erat.primes){
            if(p*p > a) break;
            if(m%p == 0){
                facs.push_back(p);
                while(m%p == 0) {
                    m = m/p;
                }
            }
        }
        if(m != 1) facs.push_back(m);
        return facs;
    };

    ll ans = n;
    map<ll, ll> memo;
    auto test = [&](ll g){
        if(memo.count(g)) return memo[g];
        ll ans = 0;
        for(ll x : a){
            if(x < g){
                ans += g-x;
            }else{
                ll r = x%g;
                ans += min(r, g-r);
            }
        }
        memo[g] = ans;
        return ans;
    };
    random_device rnd;
    mt19937 mt(rnd()); 
    for(int i = 0;; i++){
        int j = mt()%n;
        int k = mt()%n;
        int sgn = (i%3)-1;
        ll g = gcd(a[j]+sgn, a[k]+sgn);
        if(g == 0 || g == 1) continue;
        for(ll p : prime_facs(g)) chmin(ans, test(p));
        clock_t end = clock(); 
        if((double)(end - start) / CLOCKS_PER_SEC > 2.0) break;
    }
    cout  << ans << endl;
}