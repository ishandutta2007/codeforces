#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

using P = pair<int, int>;
using T = tuple<int, int, int>;
const int inf = 1e9;

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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

const int N_MAX = 1000000;
Eratosthenes et(N_MAX);
vector<P> facs[N_MAX+1];

void init(){
    for(int p: et.primes){
        for(int i = 1; i*p <= N_MAX; i++){
            int x = i*p;
            int cnt = 0;
            while(x%p == 0){
                x /= p;
                cnt++;
            }
            facs[i*p].push_back(P(p, cnt));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string b; cin >> b;
    vector<vector<P>> v(N_MAX+1);
    for(int i = 0; i < n; i++){
        for(auto [p, cnt]: facs[a[i]]){
            if(b[i] == '*') v[p].push_back(P(i, cnt));
            else v[p].push_back(P(i, -cnt));
        }
    }
    vector<vector<P>> st(n+1);
    for(int p: et.primes){
        if(v[p].empty()) continue;
        vector<int> indices;
        vector<int> a;
        for(auto [idx, cnt]: v[p]){
            indices.push_back(idx);
            a.push_back(cnt);
        }
        auto cumsum = Cumsum<int>(a);
        int m = indices.size();
        int mx = *max_element(cumsum.v_cumsum.begin(), cumsum.v_cumsum.end());
        chmax(mx,  -*min_element(cumsum.v_cumsum.begin(), cumsum.v_cumsum.end()));
        OffsetVec<int> nx(mx+1, inf);
        for(int i = m-1; i >= 0; i--){
            int pre = i == 0 ? 0 : indices[i-1]+1;
            if(a[i] > 0){
                for(int x = cumsum.v_cumsum[i]+1; x <= cumsum.v_cumsum[i+1]; x++) nx[x] = indices[i]+1;
            }else{
                for(int x = cumsum.v_cumsum[i]-1; x >= cumsum.v_cumsum[i+1]; x--) nx[x] = indices[i]+1;
            }
            int r = min(n, nx[cumsum.v_cumsum[i]-1]-1);
            st[r].push_back(P(pre, indices[i]+1));
        }
    }
    
    vector<int> ans(n, n);
    set<int> idx;
    for(int i = 0; i < n; i++) idx.insert(i);
    for(int v = 0; v <= n; v++){
        for(auto [l, r]: st[v]){
            // cout << l << ' ' << r << ' ' << v << endl;
            auto p = idx.lower_bound(l);
            vector<int> erase;
            while(p != idx.end() && *p < r){
                ans[*p] = v;
                erase.push_back(*p);
                p++;
            }
            for(int x: erase) idx.erase(x);
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++) sum += ans[i]-i;
    // print_vector(ans);
    cout << sum << endl;
}