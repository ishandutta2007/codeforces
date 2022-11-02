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

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
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

class Simulator{
    public:
    int n;
    Simulator(int n): n(n){
        cnt_q = 0;
        assert(n%3 == 0);
        impostor.resize(n);
        k = randint(n/3+1, 2*n/3);
        for(int i = 0; i < k; i++){
            auto gen_idx = [&](){
                while(true){
                    int idx = randint(0, n);
                    if(!impostor[idx]) return idx;
                }
            };
            impostor[gen_idx()] = true;
        }
    };
    int ask(int a, int b, int c){
        cnt_q++;
        assert(a != b);
        assert(b != c);
        assert(c != a);
        int cnt0 = 0, cnt1 = 0;
        vector<int> v = {a, b, c};
        for(int i: v){
            if(impostor[i]) cnt0++;
            else cnt1++;
        }
        if(cnt0 > cnt1) return 0;
        return 1;
    };
    void verify(int m, vector<int> v){
        assert(k == m);
        for(int i: v) assert(impostor[i]);
        assert(cnt_q <= 2*n);
        // assert(cnt_q <= n+6); // hard
    }
    private:
    int k;
    int cnt_q;
    vector<bool> impostor;
};

// #define DEBUG

void solve(){
    int n; cin >> n;
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    auto ask = [&](int a, int b, int c){
    #ifdef DEBUG
        return sim.ask(a, b, c);
    #else
        cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
        int ans; cin >> ans;
        return ans; 
    #endif
    };

    auto verify = [&](int m, vector<int> v){
    #ifdef DEBUG
        return sim.verify(m, v);
    #else
        cout << "! " << m << ' ';
        for(int x: v) cout << x+1 << ' ';
        cout << endl; 
    #endif
    };

    vector<int> ans(n, -1);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int a = i, b = (i+1)%n, c = (i+2)%n;
        v[i] = ask(a, b, c);
    }
    vector<int> rep(2);
    for(int i = 0; i < n; i++){
        int j = (i+1)%n;
        int idx = (j+2)%n;
        if(v[i] == 0 && v[j] == 1){
            ans[idx] = 1;
            rep[1] = idx;
        }
        if(v[i] == 1 && v[j] == 0){
            ans[idx] = 0;
            rep[0] = idx;
        }
    }
    for(int i = 0; i < n; i++){
        if(i == rep[0] || i == rep[1]) continue;
        ans[i] = ask(rep[0], rep[1], i);
    }
    vector<int> u;
    for(int i = 0; i < n; i++){
        if(ans[i] == 0) u.push_back(i);
    }
    verify(u.size(), u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}