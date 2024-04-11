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

bool is_prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

vector<ll> prime_facs(ll n){
    ll m = n;
    vector<ll> ans;
    for(ll p = 2; p*p <= n; p++){
        if(m%p == 0){
            ans.push_back(p);
            while(m%p == 0) m /= p;
        }
    }
    if(m != 1) ans.push_back(m);
    return ans;
}

const ll inf = 4e18;

using P = pair<int, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll asum = accumulate(a.begin(), a.end(), 0ll);
    if(asum == 1){
        cout << -1 << endl;
        return 0;
    }
    auto facs = prime_facs(asum);
    auto f = [&](vector<P> ps, ll p) -> ll{
        ll ans = 0;
        ll sum = 0;
        int c = -1;
        // for(auto [i, x]: ps) cout << i << ':' << x << ' ';
        // cout << endl;
        for(auto [i, x]: ps){
            sum += x;
            if(sum*2 >= p){
                c = i;
                break;
            }
        }
        assert(c != -1);
        for(auto [i, x]: ps){
            ans += x*abs(c-i);
        }
        return ans;
    };
    auto calc = [&](ll p) -> ll{
        ll sum = 0;
        ll ans = 0;
        vector<P> vp;
        for(int i = 0; i < n; i++){
            if(sum+a[i] >= p){
                ll rem = p-sum;
                vp.push_back(P(i, rem));
                ans += f(vp, p);
                vp.clear();
                sum = (sum+a[i])%p;
                vp.push_back(P(i, sum));
            }else{
                sum += a[i];
                vp.push_back(P(i, a[i]));
            }
        }
        assert(sum == 0);
        return ans;
    };
    ll ans = inf;
    for(ll p : facs){
        // cout << p << ": " << calc(p) << endl;
        chmin(ans, calc(p));
    }
    cout << ans << endl;
}