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


// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

using P = pair<int, int>;
using T = tuple<int, int, int>;

vector<int> sub_solve(vector<int> &b){
    int n = b.size();
    vector<vector<P>> adds(n+1);
    for(int i = 0; i < n; i++){
        int x = i+1;
        int r = b[i] == 0 ? n : x/b[i];
        int l = ceil_div(x, (b[i]+1));
        if(x%(b[i]+1) == 0) l++;
        adds[l].push_back(P(r, i));
    }
    vector<int> ans(n);
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i <= n; i++){
        for(auto [r, idx]: adds[i]) que.push(P(r, idx));
        if(i >= 1){
            auto [r, idx] = que.top(); que.pop();
            ans[idx] = i;
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    auto ans = sub_solve(b);
    print_vector(ans);
    // print_vector(b);
    // for(int i = 0; i < n; i++){
    //     cout << (i+1)/ans[i] << ' ';
    // }
    // cout << endl;
}

void test(int n){
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    do{
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            b[i] = (i+1)/p[i];
        }
        auto a = sub_solve(b);
        for(int i = 0; i < n; i++){
            if(b[i] != (i+1)/a[i]){
                print_vector(b);
            }
        }
    }while(next_permutation(p.begin(), p.end()));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}