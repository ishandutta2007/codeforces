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

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

vector<int> gen_array(int n, int l, int r){
    int d = r-l;
    random_device rnd;
    mt19937 mt(rnd());
    vector<int> ans(n);
    int x = mt();
    for(int i = 0; i < n; i++) ans[i] = l+(mt()%d);
    return ans;
}

class Simulator{
    public:
    int n, k;
    vector<int> a;
    vector<int> ans;
    vector<vector<int>> s;
    Simulator(int n, int k): n(n), k(k), a(gen_array(n, 1, n)) {
        s.resize(k);
        for(int i = 0; i < n; i++){
            int j = randint(0, k+1);
            if(j != k) s[j].push_back(i);
        }
        ans.resize(k);
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i == j) continue;
            }
        }
    }
    int ask(vector<int> v){
        int ans = 0;

    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> s(k+1);
    for(int i = 1; i <= k; i++){
        int c; cin >> c;
        s[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    int cnt = 0;
    auto ask = [&](vector<int> v){
        cnt++;
        assert(cnt <= 12);
        cout << "? " << v.size() << ' ';
        for(int i: v) cout << i+1 << ' ';
        cout << endl;
        int ret; cin >> ret;
        assert(ret != -1);
        return ret;
    };
    auto verify = [&](vector<int> ans){
        // assert(ans.size() == k);
        cout << "! ";
        for(int x: ans) cout << x << ' ';
        cout << endl;
        string ret; cin >> ret;
        // assert(ret == "Correct");
        return ret;
    };
    vector<int> all(n);
    iota(all.begin(), all.end(), 0);
    int mx = ask(all);
    vector<int> ret(10);
    for(int i = 0; i < 10; i++){
        vector<int> v;
        for(int j = 1; j <= k; j++){
            if(j&(1<<i)){
                for(int idx: s[j]) v.push_back(idx);
            }
        }
        if(!v.empty()){
            ret[i] = ask(v);
        }
    }
    int maybe_only_max = 0;
    for(int i = 0; i < 10; i++){
        if(mx == ret[i]) maybe_only_max += 1<<i;
    }
    vector<int> query;
    vector<bool> ok(n, true);
    if(maybe_only_max <= k){
        for(int j: s[maybe_only_max]) ok[j] = false;
    }
    for(int i = 0; i < n; i++){
        if(ok[i]) query.push_back(i);
    }
    int maybe_only_max_ans = ask(query);
    if(maybe_only_max_ans == mx){
        vector<int> ans(k, mx);
        verify(ans);
        return;
    }
    vector<int> ans;
    for(int i = 1; i <= k; i++){
        if(i == maybe_only_max){
            ans.push_back(maybe_only_max_ans);
        }else{
            ans.push_back(mx);
        }
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