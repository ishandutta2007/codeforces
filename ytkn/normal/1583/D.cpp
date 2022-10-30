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
    int asked;
    vector<int> p;
    Simulator(int n) : n(n){
        asked = 0;
        p = gen_permutation(n);
        for(int i = 0; i < n; i++) p[i]++;
    }
    int ask(vector<int> a){
        asked++;
        vector<int> s(n);
        for(int i = 0; i < n; i++) s[i] = a[i]+p[i];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]) return i;
            }
        }
        return -1;
    }
    void verify(vector<int> q){
        if(asked > 2*n){
            cout << "asked too much:" << asked << endl;
        }
        if(p == q) cout << "OK" << endl;
        else{
            cout << "NG" << endl;
            cout << "correct: ";
            print_vector(p);
            cout << "answered: ";
            print_vector(q);
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

#ifdef DEBUG
    auto ask = [&](vector<int> a){
        return sim.ask(a);    
    };
#else
    auto ask = [&](vector<int> a){
        cout << "? ";
        print_vector(a);
        int ans; cin >> ans; ans--;
        return ans;
    };
#endif
#ifdef DEBUG
    auto verify = [&](vector<int> a){
        return sim.verify(a);    
    };
#else
    auto verify = [&](vector<int> a){
        cout << "! ";
        print_vector(a);
    };
#endif
    auto calc_last = [&](){
        for(int x = 1; x <= n-1; x++){
            vector<int> a(n);
            a[n-1] = 1;
            for(int i = 0; i < n-1; i++) a[i] = 1+x;
            if(ask(a) == -1) return x;
        }
        return n;
    };
    vector<int> ans(n);
    int ls = calc_last();
    ans[n-1] = ls;
    for(int x = 1; x <= n; x++){
        if(x == ls) continue;
        vector<int> a(n);
        for(int i = 0; i < n-1; i++) a[i] = ls;
        a[n-1] = x;
        int idx = ask(a);
        ans[idx] = x;
    }
    verify(ans);
}