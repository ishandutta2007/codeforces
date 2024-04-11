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

class Simulator{
    public:
    int n;
    vector<ll> a;
    Simulator(int n): n(n){
        int x = min(n/3, 60);
        random_device seed_gen;
        mt19937 engine(seed_gen());
        a.resize(n);
        for(int i = 0; i < x; i++){
            a[i] = 1ll<<i;
        }
        shuffle(a.begin(), a.end(), engine);
    };
    ll ask(vector<int> v){
        ll ans = 0;
        for(int i: v){
            ans |= a[i-1];
        }
        return ans;
    }
    void verify(vector<ll> ans){
        vector<ll> p(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                p[i] |= a[j];
            }
            cout << p[i] << ' ' << ans[i+1] << endl;
        }
        for(int i = 0; i < n; i++){
            assert(p[i] == ans[i+1]);
        }
    }
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    auto ask = [&](vector<int> v){
#ifdef DEBUG
        return sim.ask(v);
#else
        cout << "? " << v.size() << ' ';
        print_vector(v);
        ll ans; cin >> ans;
        return ans;
#endif
    };
    auto verify = [&](vector<ll> ans){
#ifdef DEBUG
        return sim.verify(ans);
#else
        cout << "! ";
        for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
#endif
    };
    vector<ll> ans(n+1);
    vector<int> v;
    for(int s = 0; s < (1<<13); s++){
        int cnt = 0;
        for(int i = 0; i < 13; i++){
            if(s&(1<<i)) cnt++;
        }
        if(cnt == 7){
            v.push_back(s);
        }
    }
    for(int i = 0; i < 13; i++){
        vector<int> query;
        for(int j = 1; j <= n; j++){
            if(v[j]&(1<<i)){
                query.push_back(j);
            }
        }
        if(query.empty()) continue;
        ll a = ask(query);
        for(int j = 1; j <= n; j++){
            if(v[j]&(1<<i)) continue;
            ans[j] |= a;
        }
    }
    verify(ans);
}