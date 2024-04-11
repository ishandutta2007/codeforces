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
#include <random>

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

auto et = Eratosthenes(100000);

class Simulator{
    public:
    int n;
    Simulator(int n): n(n) {
        random_device rnd;
        mt19937 mt(rnd());
        x = 1+mt()%n;
        // x = 71011;
        n_asked = 0;
        erased.assign(n+1, false);
    }
    
    int ask_multiple(int a){
        n_asked++;
        int ans = 0;
        for(int i = 1; i*a <= n; i++){
            if(!erased[i*a]) ans++;
        }
        return ans;
    }
    int erase_multiple(int a){
        n_asked++;
        int ans = 0;
        for(int i = 1; i*a <= n; i++){
            if(!erased[i*a]) ans++;
            if(i*a != x) erased[i*a] = true;
        }
        return ans;
    }
    void verify(int a){
        cout << "asked: " << n_asked << endl;
        cout << "truth: " << x << endl;
        cout << "your answer: " << a << endl;
        assert(n_asked <= 10000);
        assert(x == a);
    }
    private:
    int x;
    int n_asked;
    vector<bool> erased;
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    #ifdef DEBUG
    auto sim = Simulator(n);
    #endif
    auto ask_multiple = [&](ll a){
        if(a > n) return 0;
    #ifdef DEBUG
        return sim.ask_multiple(a);
    #else
        cout << "A " << a << endl;
        int ans; cin >> ans;
        return ans;
    #endif
    };
    auto erase_multiple = [&](ll a){
    #ifdef DEBUG
        return sim.erase_multiple(a);
    #else
        cout << "B " << a << endl;
        int ans; cin >> ans;
        return ans;
    #endif
    };
    auto verify = [&](int a){
    #ifdef DEBUG
        sim.verify(a);
    #else
        cout << "C " << a << endl;
    #endif
    };
    vector<int> small_primes, large_primes;
    for(ll p: et.primes){
        if(p > n) break;
        if(p*p > n) large_primes.push_back(p);
        else small_primes.push_back(p);
    }
    for(ll p: small_primes){
        erase_multiple(p);
    }
    vector<vector<int>> bucktes;
    for(int i = 0; i < large_primes.size(); i++){
        int p = large_primes[i];
        if(i%100 == 0){
            bucktes.push_back({p});
        }else{
            bucktes.back().push_back(p);
        }
    }
    int n_buckets = bucktes.size();
    vector<int> rem(n_buckets+1);
    rem[0] = ask_multiple(1);
    int ans = 1;
    for(int i = 0; i < n_buckets; i++){
        for(int p: bucktes[i]){
            if(erase_multiple(p) > 1) ans *= p;
        }
        rem[i+1] = ask_multiple(1);
    }
    for(int i = 0; i < n_buckets; i++){
        if(rem[i]-rem[i+1] < bucktes[i].size()){
            for(int p: bucktes[i]){
                if(ask_multiple(p) != 0) ans *= p;
            }
        }
    }
    
    for(ll p: small_primes){
        ll q = p;
        while(q/p <= n){
            int x = ask_multiple(q);
            if(x == 0){
                ans *= q/p;
                break;
            }
            q *= p;
        }
    }
    verify(ans);
}