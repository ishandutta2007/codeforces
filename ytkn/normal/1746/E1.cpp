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
    int q, g;
    bool prev_true;
    mt19937 mt;
    Simulator(int n, int seed=42): n(n), q(0),g(0),  prev_true(true), mt(mt19937()){
        mt.seed(seed);
    };
    bool ask(vector<int> v){
        q++;
        assert(q <= 82);
        bool true_ans = false;
        for(int x: v){
            if(x == n) true_ans = true;
        }
        bool ans = true_ans;
        if(prev_true && mt()%2 == 1) {
            ans = !true_ans;
        }
        prev_true = (ans == true_ans);
        return ans;
    }
    bool guess(int x){
        g++;
        assert(g <= 2);
        return x == n;
    }

};

const string YES = "YES";
const string NO = "NO";
const string CORRECT = ":)";
const string INCORRECT = ":(";

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
#ifdef DEBUG
    int n = 100000;
    auto sim = Simulator(randint(1, 100001));
#else
    int n; cin >> n;
#endif
auto ask = [&](vector<int> v){
#ifdef DEBUG
        return sim.ask(v);
#else
        cout << "? ";
        cout << v.size() << ' ';
        for(int x: v) cout << x << ' ';
        cout << endl;
        string s; cin >> s;
        return s == YES;
#endif
    };
auto guess = [&](int x){
#ifdef DEBUG
        return sim.guess(x);
#else
        cout << "! " << x << endl;
        string s; cin >> s;
        return s == CORRECT;
#endif
};
    vector<int> candidate;
    auto f = [&](){
        if(candidate.size() == 1){
            assert(guess(candidate[0]));
            return;
        }
        if(candidate.size() == 2){
            if(guess(candidate[0])) return;
            assert(guess(candidate[1]));
            return;
        }
        int a = candidate[0];
        int b = candidate[1];
        int c = candidate[2];
        if(ask({a})){
            if(guess(a)) return;
            // 
            if(ask({b})){
                assert(guess(b));
            }else{
                assert(guess(c));
            }
            return;
        }
        if(ask({a})){
            if(guess(a)) return;
            // 
            if(ask({b})){
                assert(guess(b));
            }else{
                assert(guess(c));
            }
            return;
        }
        if(guess(b)) return;
        assert(guess(c));
    };
    for(int i = 1; i <= n; i++) candidate.push_back(i);
    if(candidate.size() <= 3){
        f();
        return 0;
    }
    while(candidate.size() >= 4){
        vector<vector<int>> v(4);
        for(int i = 0; i < candidate.size(); i++){
            v[i%4].push_back(candidate[i]);
        }
        vector<int> v0 = v[0];
        for(int x: v[1]) v0.push_back(x);
        vector<int> v1 = v[1];
        for(int x: v[2]) v1.push_back(x);
        bool f0 = ask(v0);
        bool f1 = ask(v1);
        int ng = -1;
        if(f0 && f1){
            ng = 3;
        }else if(f0 && !f1){
            ng = 2;
        }else if(!f0 && f1){
            ng = 0;
        }else{
            ng = 1;
        }
        candidate.clear();
        for(int i = 0; i < 4; i++){
            if(i == ng) continue;
            for(int x: v[i]) candidate.push_back(x);
        }
    }
    f();
}