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

auto et = Eratosthenes(1000000);

void solve(){
    int e, n; cin >> n >> e;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> v(e);
    for(int i = 0; i < n; i++){
        int r = i%e;
        v[r].push_back(a[i]);
    }
    ll ans = 0;
    for(int r = 0; r < e; r++){
        int sum = 0;
        vector<int> cumsum;
        cumsum.push_back(0);
        // print_vector(v[r]);
        for(int x: v[r]){
            if(x == 1){

            }else if(et.is_prime[x]){
                sum++;
                ans--;
            }else{
                sum += 2;
            }
            cumsum.push_back(sum);
        }
        // print_vector(cumsum);
        vector<ll> cnt(sum+1);
        for(int x: cumsum) cnt[x]++;
        for(int x = 0; x < sum; x++){
            ans += cnt[x]*cnt[x+1];
        }

    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}