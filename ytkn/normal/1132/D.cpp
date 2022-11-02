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

const ll inf = 1e18;
using F = frac<ll>;
using P = pair<ll, int>;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    const ll safe_energy = k*10000000ll;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    auto ok = [&](ll x){
        priority_queue<P, vector<P>, greater<P>> que;
        auto aa = a;
        for(int i = 0; i < n; i++) que.push(P(a[i]/b[i], i));
        for(int t = 0; t < k; t++){
            auto [deadline, i] = que.top(); que.pop();
            // debug_value(i)
            // debug_value(deadline)
            if(deadline < t){
                return false;
            }
            aa[i] += x;
            chmin(aa[i], safe_energy);
            ll new_deadline = aa[i]/b[i];
            chmin(new_deadline, (ll)k);
            que.push(P(new_deadline, i));
        }
        return true;
    };
    if(ok(0)){
        cout << 0 << endl;
        return 0;
    }
    if(!ok(safe_energy)){
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = safe_energy;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}