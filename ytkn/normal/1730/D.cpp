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

void test(int n){
    vector<int> v(2*n);
    iota(v.begin(), v.end(), 0);
    auto apply = [&](vector<int> v, int k){
        assert(k > 0 && k <= n);
        for(int i = 0; i < k; i++){
            int j = 2*n-k+i;
            swap(v[i], v[j]);
        }
        return v;
    };
    set<vector<int>> st;
    queue<vector<int>> que;
    auto push = [&](vector<int> v){
        if(st.count(v)) return; que.push(v);
        st.insert(v);
    };
    push(v);
    while(!que.empty()){
        auto v = que.front(); que.pop();
        for(int k = 1; k <= n; k++){
            auto u = apply(v, k);
            push(u);
        }
    }
    for(auto v: st){
        print_vector(v);
    }
    debug_value(st.size())
}

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    auto cnt = vec2d(26, 26, 0);
    for(int i = 0; i < n; i++){
        int j = n-1-i;
        int x = s[i]-'a';
        int y = t[j]-'a';
        if(x > y) swap(x, y);
        cnt[x][y]++;
    }
    for(int i = 0; i < 26; i++){
        for(int j = i+1; j < 26; j++){
            if(cnt[i][j]%2 == 1){
                cout << "NO" << endl;
                return;
            }
        }
    }
    int cnt_odd = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i][i]%2 == 1) cnt_odd++;
    }
    if(n%2 == 1){
        if(cnt_odd == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        if(cnt_odd == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // test(3);
    // return 0;
    int t; cin >> t;
    while(t--) solve();
}