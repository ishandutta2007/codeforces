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

class Simulator{
    public:
    ll a, q;
    Simulator(ll a): a(a), q(0) {}
    string ask(ll x, ll y){
        ll rx = x%a, ry = y%a;
        if(rx >= ry) return "x";
        else return "y";
    }
    void verify(ll ans){
        if(ans != a){
            cout << ans << " != " << a << endl;
        }
        if(q > 60){
            cout << "asked " << q << " times" << endl;
        }
    }
};

void test(int a){
    for(int x = 1; x <= 100; x++) cout << x%a << ' ' << (x*2)%a << endl;
}

// #define DEBUG

void solve(int n){
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    map<P, string> memo;
    auto ask = [&](ll x, ll y){
        assert(x <= 2e9);
        assert(y <= 2e9);
        P p(x, y);
        if(memo.count(p)) return memo[p];
#ifdef DEBUG
        auto ans = sim.ask(x, y);
        memo[p] = ans;
        return ans;
#else
        cout << "? " << x << ' ' << y << endl;
        string ans; cin >> ans;
        memo[p] = ans;
        return ans;
#endif
    };

    auto verify = [&](ll ans){
#ifdef DEBUG
        sim.verify(ans);
#else
        cout << "! " << ans << endl;
#endif
    };
    if(ask(1, 2) == "x" && ask(2, 1) == "x"){
        verify(1);
        return;
    }
    if(ask(1, 2) == "x" && ask(2, 1) == "y"){
        verify(2);
        return;
    }
    ll x = 1;
    while(true){
        if(ask(x, 2*x) == "y"){
            x *= 2;
        }else{
            break;
        }
    }
    ll l = 1, r = x;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(ask(x, 2*x) == "x") r = x;
        else l = x;
    }
    if(ask(2*r-1, 2*r) == "x"){
        verify(2*r);
    }else{
        verify(2*r-1);
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // for(int a = 1; a <= 128; a++) solve(a);
    // for(int a = 1; a <= 1000000000; a<<=1) solve(a);
    // return 0;
    while(true){
        string s; cin >> s;
        if(s == "start"){
            solve(-1);
        }else{
            break;
        }
    }
}