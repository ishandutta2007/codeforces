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

vector<int> gen_permutation(int n) {
    random_device seed_gen;
    mt19937 engine(seed_gen());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i;
    shuffle(ans.begin(), ans.end(), engine);
    return ans;
}

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

const int inf = 1e9;

class Simulator{
    public:
    int n;
    Simulator(int n): n(n) {
        a.resize(n+2);
        a[0] = inf;
        int cur = 2;
        auto p = gen_permutation(n);
        for(int i = 0; i < n; i++) a[i+1] = p[i];
        a[n+1] = inf;
    }
    int ask(int i){
        n_ask++;
        return a[i];
    }
    void verify(int i){
        assert(a[i-1] > a[i]);
        assert(a[i] < a[i+1]);
        assert(n_ask <= 100);
    }
    private:
    int n_ask = 0;
    vector<int> a;
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
    vector<int> memo(n+2, -1);
    memo[0] = inf;
    memo[n+1] = inf;
    auto ask = [&](int i){
        if(memo[i] == -1){
#ifdef DEBUG
            memo[i] = sim.ask(i);
#else
            cout << "? " << i << endl;
            int ans; cin >> ans;
            memo[i] = ans;
#endif
        }
        return memo[i];
    };
    auto diff = [&](int i){ // a[i+1]-a[i]
        return ask(i+1)-ask(i);
    };
    auto verify = [&](int i){
#ifdef DEBUG
        sim.verify(i);
#else
        cout << "! " << i << endl;
#endif
    };
    if(diff(0) < 0 && diff(1) > 0){
        verify(1);
        return 0;
    }
    if(diff(n-1) < 0 && diff(n) > 0){
        verify(n);
        return 0;
    }
    int l = 0, r = n-1;
    while(r-l > 1){
        int x = (l+r)/2;
        if(diff(x) < 0 && diff(x+1) > 0){
            verify(x+1);
            return 0;
        }else if(diff(x) < 0 && diff(x+1) < 0){
            l = x;
        }else{
            r = x;
        }
    }
    assert(false);
}