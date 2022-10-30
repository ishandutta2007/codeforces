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

using P = pair<int, int>;

vector<P> run_length(vector<P> v){
    vector<P> ans;
    int pre = v[0].first;
    int cnt = v[0].second;
    int n = v.size();
    for(int i = 1; i < n; i++){
        auto [cur, c] = v[i];
        if(cur == pre){
            cnt += c;
        }else{
            ans.push_back(P(pre, cnt));
            cnt = c;
            pre = cur;
        }
    }
    ans.push_back(P(pre, cnt));
    return ans;
} 

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<P> b(n-1);
    for(int i = 0; i < n-1; i++) b[i] = P(a[i+1]-a[i], 1);
    sort(b.begin(), b.end());
    b = run_length(b);
    sort(b.begin(), b.end());
    for(int i = 0; i < n-2; i++){
        int m = b.size();
        // for(auto [x, c]: b) cout << x << ": " << c << ' ';
        // cout << endl;
        vector<P> c;
        for(int i = 0; i < m; i++){
            auto [x, cnt] = b[i];
            if(cnt > 1) c.push_back(P(0, cnt-1)); 
        }
        for(int i = 0; i < m-1; i++){
            int x = b[i].first, y = b[i+1].first;
            c.push_back(P(y-x, 1));
        }
        sort(c.begin(), c.end());
        b = run_length(c);
        sort(b.begin(), b.end());
    }
    cout << b[0].first << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}