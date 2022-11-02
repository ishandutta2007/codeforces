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

const int N_MAX = 5000000;
const auto et = Eratosthenes(N_MAX);

vector<int> prime_facs[N_MAX+1];
ll cnt0[N_MAX+1];
ll cnt1[N_MAX+1];
ll dp[N_MAX+1];

void init(){
    for(int p: et.primes){
        for(int i = 1; i*p <= N_MAX; i++) prime_facs[i*p].push_back(p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt0[a[i]]++;
    }
    for(int i = 1; i <= N_MAX; i++){
        for(int j = 1; j*i <= N_MAX; j++){
            cnt1[i] += cnt0[i*j];
        }
    }
    ll ans = 0;
    dp[1] = n;
    for(int i = 2; i <= N_MAX; i++){
        // debug_value(i)
        for(ll p: prime_facs[i]){
            chmax(dp[i], dp[i/p]-cnt1[i]*(i/p)+cnt1[i]*i);
        }
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
}