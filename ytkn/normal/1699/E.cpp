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

const int M = 5000000;


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

void dfs(vector<int> &v, int p){
    int y = v.empty() ? 3 : v.back();
    for(ll x = y; x*p <= M; x++){
        v.push_back(x);
        dfs(v, p*x);
        v.pop_back();
    }
}

bool used[M+1];
int cnt[M+1];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        used[a[i]] = true;
    }
    int a_min = *min_element(a.begin(), a.end());
    int ans = m;
    vector<int> mx(m+1);
    iota(mx.begin(), mx.end(), 0);
    auto add = [&](int x){
        cnt[x]++;
    };
    int max_mx = m;
    auto del = [&](int x){
        cnt[x]--;
    };
    for(int i = 1; i <= m; i++){
        if(used[i]) add(i);
    }
    for(int x = m; x >= 1; x--){
        for(int i = x; (ll)x*i <= m; i++){
            if(used[x*i]){
                del(mx[x*i]);
            }
            chmin(mx[x*i], max(x, mx[i]));
            if(used[x*i]){
                add(mx[x*i]);
            }
        }
        if(x <= a_min){
            while(cnt[max_mx] == 0){
                max_mx--;
            }
            chmin(ans, max_mx-x);
        }
    }
    for(int i = 0; i < n; i++){
        used[a[i]] = false;
    }
    for(int i = 1; i <= m; i++) cnt[i] = 0;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}