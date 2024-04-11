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

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
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
    int n_asked;
    Simulator(int n): n(n) {
        n_asked = 0;
        int x = 2;
        s = string(n, '-');
        auto p = gen_permutation(n);
        for(int i = 0; i < x; i++){
            if(i%2 == 0){
                s[p[i]] = 'S';
            }else{
                s[p[i]] = 'N';
            }
        }
    }
    int ask(vector<int> a, vector<int> b){
        n_asked++;
        int n1 = 0, s1 = 0;
        int n2 = 0, s2 = 0;
        for(int i: a){
            if(s[i] == 'S') s1++;
            if(s[i] == 'N') n1++;
        }
        for(int i: b){
            if(s[i] == 'S') s2++;
            if(s[i] == 'N') n2++;
        }
        int ans = (n1-s1)*(n2-s2);
        assert(abs(ans) <= n);
        return ans;
    }
    void verify(vector<int> v){
        print_vector(v);
        for(int i = 0; i < n; i++){
            if(s[i] == '-') cout << i << ' ';
        }
        cout << endl;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '-') cnt++;
        }
        assert(v.size() == cnt);
        for(int i: v) assert(s[i] == '-');
        if(n_asked > n){
            cout << n_asked << ' ' << n << endl;
            assert(n >= (1<<(n_asked-n)));
        }
    }
    private:
    string s;
};

// #define DEBUG

void solve(){
    int n; cin >> n;
#ifdef DEBUG
    auto sim = Simulator(n);
#endif
    auto ask = [&](vector<int> a, vector<int> b){
#ifdef DEBUG
        return sim.ask(a, b);
#else
        cout << "? " << a.size() << ' ' << b.size() << endl;
        for(int i: a) cout << i+1 << ' ';
        cout << endl;
        for(int i: b) cout << i+1 << ' ';
        cout << endl;
        int ans; cin >> ans;
        return ans;
#endif
    };
    auto verify = [&](vector<int> a){
#ifdef DEBUG
        return sim.verify(a);
#else
        cout << "! " << a.size() << ' ';
        for(int i: a) cout << i+1 << ' ';
        cout << endl;
#endif
    };
    auto find_k = [&](){
        vector<int> a = {0};
        for(int i = 1; i < n; i++){
            if(ask(a, {i}) != 0){
                return i;
            }
            a.push_back(i);
        }
    };
    int k = find_k();
    map<int, bool> cache;
    auto ok = [&](int x){
        if(x < 0) return false;
        if(x == k-1) return true;
        if(cache.count(x)) return cache[x];
        vector<int> a;
        for(int i = 0; i <= x; i++) a.push_back(i);
        int res = ask(a, {k});
        cache[x] = (res != 0);
        return res != 0;
    };
    vector<bool> demagnetized(n, true);
    demagnetized[k] = false;
    for(int i = k+1; i < n; i++){
        if(ask({k}, {i}) != 0) demagnetized[i] = false;
    }
    int j = 0;
    
    int l = -1, r = k-1;
    while(r-l > 1){
        int x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    j = r;
    
    demagnetized[j] = false;
    
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(demagnetized[i]) ans.push_back(i);
    }
    verify(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}