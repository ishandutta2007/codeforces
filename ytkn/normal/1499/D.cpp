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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
const int N_MAX = 10000000;

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


vector<int> facs(int n){
    vector<int> ans;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0) {
            ans.push_back(i);
            if(i*i != n) ans.push_back(n/i);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    auto erat = Eratosthenes(2*N_MAX);
    vector<int> cnt(2*N_MAX+1);
    for(int p : erat.primes){
        for(int j = 1; p*j <= 2*N_MAX; j++){
            cnt[j*p]++;
        }
    }
    // auto cnt_prime_facs = [&](int n){
    //     int ans = 0;
    //     int sz = erat.primes.size();
    //     for(int i = 0; ; i++){
    //         ll p = erat.primes[i];
    //         if(p*p > n) break;
    //         if(n%p == 0){
    //             ans++;
    //             while(n%p == 0) n /= p;
    //         }
    //     }
    //     if(n != 1) ans++;
    //     return ans;
    // };
    int t; cin >> t;
    while(t--) {
        ll ans = 0;
        int c, d, x; cin >> c >> d >> x;
        auto v = facs(x);
        for(int g : v){
            int p = x/g+d;
            if(p%c != 0) continue;
            int t = p/c;
            ans += (ll)1<<cnt[t];
        }
        cout << ans << endl;
    }
}