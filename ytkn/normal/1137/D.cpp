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
    int t, c, q;
    vector<int> pos;
    Simulator(int t, int c): t(t), c(c), q(0), pos(vector<int>(10)) {}
    vector<int> next_move(vector<int> v){
        q++;
        for(int i: v){
            pos[i]++;
            if(pos[i] == t+c) pos[i] = t;
        }
        map<int, vector<int>> mp;
        for(int i = 0; i < 10; i++) mp[pos[i]].push_back(i);
        vector<int> ans(10);
        int idx = 0;
        for(auto [x, v]: mp){
            for(int i: v) ans[i] = idx;
            idx++;
        }
        return ans;
    }
    void verify(){
        for(int i = 0; i < 10; i++){
            assert(pos[i] == t);
        }
        if(q > 3*(t+c)){
            cout << t << ' ' << c << ':' << q << " > " << 3*(t+c) << endl;
        }
    }
};

// #define DEBUG

void solve(int tt, int cc){
    #ifdef DEBUG
    auto sim = Simulator(tt, cc);
#endif
    auto next_move = [&](vector<int> v){
#ifdef DEBUG
        return sim.next_move(v);
#else
        cout << "next ";
        print_vector(v);
        int n; cin >> n;
        vector<int> ans(10);
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            for(char c: s){
                ans[c-'0'] = i;
            }
        }
        return ans;
#endif
    };
    auto verify = [&](){
#ifdef DEBUG
        sim.verify();
#else
        cout << "done" << endl;
#endif
    };
    vector<int> group;
    while(true){ // x, 2*x
        group = next_move({0, 1});
        group = next_move({1});
        if(group[0] == group[1]){
            break;
        }
    }
    bool overtake = false;
    int c = 0;
    while(true){
        c++;
        group = next_move({1, 2});
        if(group[2] == group[0]) overtake = true;
        if(group[0] == group[1]){
            break;
        }
    }
    while(true){
        if(!overtake){
            group = next_move({2, 3, 4, 5, 6, 7, 8, 9});
            if(group[2] == group[0]) overtake = true;
        }else{
            group = next_move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        }
        if(group[2] == group[3]){
            break;
        }
    }
    while(group[0] != group[2]){
        group = next_move({0, 1});
    }
    verify();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    solve(0, 0);
    // for(int c = 1; c <= 10; c++){
    //     for(int t = 1; t <= 10; t++){
    //         solve(t, c);
    //     }
    // }
}