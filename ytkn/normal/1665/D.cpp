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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

class Simlrator{
    public:
    int n;
    int cnt;
    Simlrator(int n): n(n), cnt(0){};
    int ask(int a, int b){
        assert(a <= 2000000000);
        assert(b <= 2000000000);
        cnt++;
        return gcd(a+n, b+n);
    }
    void verify(int x){
        cout << x << ' ' << n << endl;
        assert(n == x);
        assert(cnt <= 30);
    }
};

// #define DEBUG

void solve(){
#ifdef DEBUG
    auto sim = Simlrator(randint(1, 1000000000));
#endif
    auto ask = [&](int a, int b){
#ifdef DEBUG
        return sim.ask(a, b);
#else
        cout << "? " << a << ' ' << b << endl;
        int x; cin >> x;
        return x;
#endif
    };
    auto verify = [&](int ans){
#ifdef DEBUG
        return sim.verify(ans);
#else
        cout << "! " << ans << endl;
#endif
    };
    int rem = 0;
    for(int i = 1; i <= 30; i++){
        int x = 1<<i;
        int y = x/2;
        int ans = ask(y-rem, x+y-rem);
        if(ans == x){
            rem += y;
        }
    }
    verify(rem);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}