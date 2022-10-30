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

using P = pair<char, int>;

vector<P> run_length(string s){
    int n = s.size();
    char pre = s[0];
    int cnt = 1;
    vector<P> ans;
    for(int i = 1; i < n; i++){
        if(pre != s[i]){
            ans.push_back(P(pre, cnt));
            pre = s[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }
    ans.push_back(P(pre, cnt));
    return ans;
}

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    auto cs = run_length(s);
    auto ct = run_length(t);
    if(cs.size() != ct.size()){
        cout << -1 << '\n';
        return;
    }
    int m = cs.size();
    for(int i = 0; i < m; i++){
        if(cs[i].first != ct[i].first){
            cout << -1 << '\n';
            return;
        }
    }
    ll ans = 0;
    ll diff = 0;
    for(int i = 0; i < m; i++){
        ans += abs(diff);
        ll x = cs[i].second-ct[i].second;
        diff += x;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}