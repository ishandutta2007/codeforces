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
    int n, k;
    Simulator(int n, int k): n(n), k(k) {
        w.resize(n);
        is_stone.resize(n);
        random_device seed_gen;
        engine = mt19937(seed_gen());
        vector<int> v(n);
        for(int i = 0; i < n-k; i++) v[i] = 1;
        shuffle(v.begin(), v.end(), engine);
        for(int i = 0; i < n; i++){
            if(v[i] == 1){
                is_stone[i] = true;
                w[i] = 1000;
            }else{
                is_stone[i] = false;
                w[i] = engine()%1000;
            }
        }
    }
    string ask(vector<int> a, vector<int> b){
        int asum = 0, bsum = 0;
        for(int i: a) asum += w[i];
        for(int i: b) bsum += w[i];
        if(asum > bsum) return "FIRST";
        if(bsum > asum) return "SECOND";
        return "EQUAL";
    }
    void verify(int x){
        print_vector(is_stone);
        print_vector(w);
        debug_value(x);
        for(int i = 0; i < n; i++){
            if(!is_stone[i]){
                assert(x == i);
                break;
            }
        }
    }
    private:
    vector<int> w;
    vector<bool> is_stone;
    mt19937 engine;
};

const string FIRST = "FIRST";
const string SECOND = "SECOND";
const string EQUAL = "EQUAL";

// #define DEBUG

void solve(){
    int n, k; cin >> n >> k;
#ifdef DEBUG
    auto sim = Simulator(n, k);
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
        string s; cin >> s;
        return s;
#endif
    };
    auto verify = [&](int x){
#ifdef DEBUG
        return sim.verify(x);
#else
    cout << "! " << x+1 << endl;
#endif
    };
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i;
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
    int m = 30;
    while(v.size() > m) v.pop_back();
    while(v.size() > 1){
        int i = v.back(); v.pop_back();
        int j = v.back(); v.pop_back();
        if(ask({i}, {j}) == FIRST){
            v.push_back(i);
        }else{
            v.push_back(j);
        }
    }
    int stone = v[0];
    vector<int> stones = {stone};
    vector<int> candidates;
    int idx = 0;
    while(true){
        candidates.clear();
        while(idx < n){
            if(idx == stone) {
                idx++;
                continue;
            }
            candidates.push_back(idx); idx++;
            if(candidates.size() == stones.size()) break;
        }
        while(candidates.size() < stones.size()) stones.pop_back();
        string ans = ask(stones, candidates);
        if(ans == FIRST){
            break;
        }
        assert(ans == EQUAL);
        for(int i: candidates) stones.push_back(i);
    }
    auto judge = [&](int x)->bool{
        vector<int> a, b;
        for(int i = 0; i < x; i++){
            a.push_back(stones[i]);
            b.push_back(candidates[i]);
        }
        return ask(a, b) == FIRST;
    };
    int l = 1, r = stones.size();
    if(judge(l)){
        verify(candidates[0]);
        return;
    }
    while(r-l > 1){
        int x = (l+r)/2;
        if(judge(x)) r = x;
        else l = x;
    }
    verify(candidates[l]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}