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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

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

using F = frac<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> v(n);
    ll v_sum = 0;
    vector<F> mx;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v_sum += v[i];
        F f(v_sum, i+1);
        if(i == 0) mx.push_back(f);
        else{
            mx.push_back(max(f, mx.back()));
        }
    }
    int q; cin >> q;
    while(q--){
        ll t; cin >> t;
        auto ok = [&](int x){
            if(x == 0) return false;
            if(t*x < v_sum) return false;
            if(mx[x-1] > F(t, 1)) return false;
            return true;
        };
        if(!ok(n)){
            cout << -1 << endl;
            continue;
        }
        int l = 0, r = n;
        while(r-l > 1){
            int x = (l+r)/2;
            if(ok(x)) r = x;
            else l = x;
        }
        cout << r << endl;
    }

}