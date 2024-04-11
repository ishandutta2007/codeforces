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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

template <typename T>
class frac{
    public:
    T n, d;
    frac(T _n, T _d){
        T g = gcd(_n, _d);
        n = _n/g;
        d = _d/g;
        if(d < 0) {
            d *= -1;
            n *= -1;
        }
    }
    frac operator+(frac f){
        return frac(n*f.d+d*f.n, f.d*d);
    }
    frac operator-(frac f){
        return frac(n*f.d-d*f.n, f.d*d);
    }
    frac operator*(frac f){
        return frac(f.n*n, f.d*d);
    }
    frac inv(){
        return frac(d, n);
    }
    bool operator<(frac f){
        if(d*f.d < 0) return n*f.d-d*f.n > 0;
        else return n*f.d-d*f.n < 0;
    }
    bool operator>(frac f){
        if(d*f.d < 0) return n*f.d-d*f.n < 0;
        else return n*f.d-d*f.n > 0;
    }
    bool operator==(frac f){
        return n*f.d-d*f.n == 0;
    }
    void operator+=(frac f){
        n = n*f.d+d*f.n, d = f.d*d;
        reduction();
    }
    void operator-=(frac f){
        n = n*f.d-d*f.n, d = f.d*d;
        reduction();
    }
    void reduction(){
        T g = gcd(n, d);
        n /= g, d /= g;
    }
};

template <typename T>
bool operator<(const frac<T> f1, const frac<T> f2){
    if(f1.d*f2.d < 0) return f1.n*f2.d-f1.d*f2.n > 0;
    else return f1.n*f2.d-f1.d*f2.n < 0;
}

template <typename T>
bool operator>(const frac<T> f1, const frac<T> f2){
    if(f1.d*f2.d < 0) return f1.n*f2.d-f1.d*f2.n > 0;
    else return f1.n*f2.d-f1.d*f2.n > 0;
}

template <typename T>
bool operator==(const frac<T> f1, const frac<T> f2){
    return f1.n*f2.d-f1.d*f2.n == 0;
}

template <typename T>
ostream& operator<<(ostream& os, const frac<T>& f){
    os << f.n << '/' << f.d;
    return os;
}

using P = pair<ll, ll>;
using F = frac<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> m(n), k(m);
    for(int i = 0; i < n; i++) {
        cin >> m[i] >> k[i];
    }
    auto cp = Compress<int>(m);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = cp[m[i]];
    }
    int sz = cp.size();
    auto make_ans = [&](int x){
        vector<P> p(sz);
        for(int i = 0; i < sz; i++) p[i].second = i;
        for(int i = 0; i < n; i++){
            p[v[i]].first += min(k[i], x);
        }
        sort(p.begin(), p.end(), greater<P>());
        vector<int> ans;
        for(int i = 0; i < x; i++){
            int j = p[i].second;
            ans.push_back(cp.data[j]);
        }
        return ans;
    };
    auto calc = [&](int x){
        vector<P> p(sz);
        for(int i = 0; i < sz; i++) p[i].second = i;
        for(int i = 0; i < n; i++){
            p[v[i]].first += min(k[i], x);
        }
        sort(p.begin(), p.end(), greater<P>());
        ll sum = 0;
        for(int i = 0; i < x; i++) sum += p[i].first;
        return F(sum, x);
    };
    F ans(0, 1);
    int ans_x = -1;
    for(int i = 1; i <= min(19, sz); i++){
        if(chmax(ans, calc(i))) ans_x = i;
    }
    if(sz >= 20){
        vector<P> p(sz);
        for(int i = 0; i < sz; i++) p[i].second = i;
        for(int i = 0; i < n; i++){
            p[v[i]].first += min(k[i], 20);
        }
        sort(p.begin(), p.end(), greater<P>());
        ll sum = 0;
        for(int i = 0; i < sz; i++){
            sum += p[i].first;
            ll x = i+1;
            if(x >= 20 && chmax(ans, F(sum, x))) ans_x = x;
        }
    }
    auto vv = make_ans(ans_x);
    cout << ans_x << endl;
    print_vector(vv);
}