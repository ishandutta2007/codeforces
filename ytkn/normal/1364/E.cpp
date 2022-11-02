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

using P = pair<int, int>;

int popcount(int x){
    int ans = 0;
    for(int i = 0; i < 20; i++){
        if(x&(1<<i)) ans++;
    }
    return ans;
}

class Simulator{
    public:
    int n;
    int n_asked;
    vector<int> p;
    Simulator(int n): n(n), n_asked(0), p(gen_permutation(n)){}
    int ask(int i, int j){
        n_asked++;
        return p[i]|p[j];
    }
    void verify(vector<int> ans){
        print_vector(p);
        print_vector(ans);
        assert(ans == p);
        assert(n_asked <= 4269);
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
    map<P, int> memo;
    auto ask = [&](int i, int j){
        assert(i != j);
        if(i > j) swap(i, j);
        P p(i, j);
        if(memo.count(p)) return memo[p];
#ifdef DEBUG
        int ans = sim.ask(i, j);
#else
        cout << "? " << i+1 << ' ' << j+1 << endl;
        int ans; cin >> ans;
#endif
        memo[p] = ans;
        return ans;
    };
    auto verify = [&](vector<int> p){
#ifdef DEBUG
        sim.verify(p);
#else
        cout << "! ";
        print_vector(p);
#endif
    };
    int min_popcount = 30;
    int min_index = -1;
    for(int i = 0; i < 100; i++){
        int x = randint(0, n);
        int y = randint(0, n);
        if(x == y) continue;
        if(x > y) swap(x, y);
        if(memo.count(P(x, y))) continue;
        int ans = ask(x, y);
        if(chmin(min_popcount, popcount(ans))){
            min_index = x;
        }
    }
    int min_or = n;
    for(int i = 0; i < n; i++){
        if(i == min_index) continue;
        chmin(min_or, ask(i, min_index));
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(i == min_index) continue;
        int ans = ask(i, min_index);
        if((min_or|ans) == min_or) v.push_back(i);
    }
    if(min_or == 1) v.push_back(min_index);
    while(v.size() > 2){
        int m = v.size();
        int idx = v[randint(0, m)];
        // debug_value(sim.p[idx]);
        // for(int i: v) cout << sim.p[i] << ' ';
        // cout << endl;
        int min_or = n;
        int all_and = (1<<20)-1;
        for(int i: v){
            if(i == idx) continue;
            int ans = ask(i, idx);
            chmin(min_or, ans);
            all_and &= ans;
        }
        if(all_and == 0){
            v = {idx};
            break;
        }
        vector<int> u;
        for(int i: v){
            if(i == idx) continue;
            int ans = ask(i, idx);
            if((min_or|ans) == min_or) u.push_back(i);
        }
        v = u;
    }
    if(v.size() == 2){
        int idx = v[0];
        int x = ask(v[0], v[1]);
        for(int i = 0; i < 30; i++){
            int j = randint(0, n);
            while(j == idx) j = randint(0, n);
            int ans = ask(idx, j);
            if((ans&x) == 0){
                v = {idx};
                break;
            }
        }
        if(v.size() == 2) v = {v[1]};
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(i == v[0]) continue;
        ans[i] = ask(i, v[0]);
    }
    verify(ans);
}