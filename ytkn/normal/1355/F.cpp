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

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

class Simulator{
    public:
    ll x, n_asked;
    Simulator(): n_asked(0){
        int p = randint(0, 4);
        if(p == 0){
            x = 2*701*709*719;
        }else if(p == 2){
            x = 2*3*991*997;
        }else if(p == 3){
            // x = 997;
            x = 131*137*139*149;
        }else{
            x = 2*3*5*7*11*13*17*19*23;
        }
    };
    ll ask(ll q){
        n_asked++;
        return gcd(q, x);
    }
    void verify(int cnt){
        debug_value(n_asked)
        int ans = 0;
        for(int i = 1; i*i <= x; i++){
            if(x%i == 0) {
                ans++;
                if(i*i != x) ans++;
            }
        }
        cout << x << ' ' << cnt << ' ' << ans << endl;
        assert(n_asked <= 22);
        if(ans <= 2*cnt && cnt <= 2*ans){
            return;
        }
        if(abs(ans-cnt) <= 7){
            return;
        }
        assert(false);
    }
};

const ll MX = 1e18;
const int M = 650;
auto et = Eratosthenes(M);

vector<vector<ll>> init(){
    vector<vector<ll>> ans;
    auto primes = et.primes;
    set<ll> st;
    for(int p: primes) st.insert(p);
    while(!st.empty()){
        ll p = *prev(st.end());
        ll prod = p;
        st.erase(p);
        vector<ll> v = {p};
        while(prod < MX && !st.empty()){
            ll rem = MX/prod;
            auto ptr = st.upper_bound(rem);
            if(ptr == st.begin()) break;
            ptr--;
            ll q = *ptr;
            v.push_back(q);
            prod *= q;
            st.erase(q);
        }
        ans.push_back(v);
    }
    return ans;
}

auto v = init();

ll calc(ll p){
    ll ans = 1;
    while(ans*p < 1000000000ll){
        ans *= p;
    }
    return ans;
}

int count(ll x, ll p){
    int ans = 0;
    while(x%p == 0){
        ans++;
        x /= p;
    }
    return ans;
}

// #define DEBUG

void solve(){
#ifdef DEBUG
    auto sim = Simulator();
#endif
    auto ask = [&](ll q){
#ifdef DEBUG
        return sim.ask(q);
#else
        cout << "? " << q << endl;
        ll ans; cin >> ans;
        return ans;
#endif
    };
    auto verify = [&](int x){
#ifdef DEBUG
        sim.verify(x);
#else
        cout << "! " << x << endl;
#endif
    };
    int cnt = 1;
    ll prod = 1;
    vector<ll> prime_facs;
    for(auto u: v){
        ll query = 1;
        for(ll p: u){
            query *= p;
        }
        ll x = ask(query);
        for(ll p: u){
            if(x%p == 0){
                prime_facs.push_back(p);
            }
        }
    }
    int sz = prime_facs.size();
    for(int i = 0; i < sz; i+=2){
        ll p = prime_facs[i];
        if(i+1 < sz){
            ll q = prime_facs[i+1];
            ll query = calc(p)*calc(q);
            ll y = ask(query);
            cnt *= count(y, p)+1;
            cnt *= count(y, q)+1;
            prod *= y;
        }else{
            ll query = calc(p);
            ll y = ask(query);
            cnt *= count(y, p)+1;
            prod *= y;
        }
    }
    if(cnt == 2){
        verify(9);
    }else{
        verify(cnt*2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    // for(auto u: v) print_vector(u);
    while(t--) solve();
}