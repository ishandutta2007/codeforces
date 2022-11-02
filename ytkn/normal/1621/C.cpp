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

vector<int> gen_permutation(int n) {
    random_device seed_gen;
    mt19937 engine(seed_gen());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i;
    shuffle(ans.begin(), ans.end(), engine);
    return ans;
}

class Simulator{
    public:
    int n;
    Simulator(int n): n(n){
        p = gen_permutation(n);
        q.resize(n);
        for(int i = 0; i < n; i++) q[i] = i;
    }
    int ask(int i){
        int ans = q[i];
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = q[p[i]];
        }
        q = v;
        return ans;
    }
    void verify(vector<int> pp){
        print_vector(p);
        print_vector(pp);
        assert(p == pp);
    }
    private:
    vector<int> p;
    vector<int> q;
};

// #define DEBUG

void solve(){
    int n; cin >> n;
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    set<int> ok;
    auto ask = [&](int i){
    #ifdef DEBUG
        return sim.ask(i);
    #else
        cout << "? " << i+1 << endl;
        int q; cin >> q; q--;
        return q;
    #endif
    };
    auto verify = [&](vector<int> p){
    #ifdef DEBUG
        return sim.verify(p);
    #else
        cout << "! ";
        for(int x: p) cout << x+1 << ' ';
        cout << endl;
    #endif
    };
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        int pre = -1;
        while(true){
            int x = ask(i);
            if(pre != -1){
                p[pre] = x;
            }
            if(ok.count(x)) break;
            ok.insert(x);
            pre = x;
        }
    }
    verify(p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}