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

const int inf = 1e9;
using F = frac<ll>;

void solve(){
    int h, c, t; cin >> h >> c >> t;
    h *= 2;
    c *= 2;
    t *= 2;
    if(t <= (h+c)/2){
        cout << 2 << endl;
        return;
    }
    if(t == h){
        cout << 1 << endl;
        return;
    }
    ll ave = (h+c)/2;
    auto ge = [&](ll x){
        return (x+1)*h+x*c >= t*(2*x+1);
    };
    ll l = 0, r = inf;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(ge(x)) l = x;
        else r = x;
    }
    F ft(t, 1);
    F fl(h*(l+1)+l*c, 2*l+1);
    F dl = fl-ft;
    F fr(h*(r+1)+r*c, 2*r+1);
    F dr = ft-fr;
    if(dr < dl){
        cout << 2*r+1 << endl;
    }else{
        cout << 2*l+1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}