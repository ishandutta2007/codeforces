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

const int inf = 1e9;

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int diff = 0;
    auto cnt = vec2d(2, 2, 0); // (, a)
    for(int i = 0; i < n; i++){
        int x = 0;
        if(a[i] != b[i]) {
            diff++;
            x = 1;
        }
        cnt[x][a[i]-'0']++;
    }
    if(diff == 0){
        cout << 0 << endl;
        return;
    }
    if(cnt[0][0]+cnt[1][0] == n){ // 0
        cout << -1 << endl;
        return;
    }
    if(cnt[0][1]+cnt[1][1] == n){ // 1
        int x = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == '1') x++;
        }
        if(x == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    
    int ans = inf;
    int same = n-diff;
    auto f = [&](int x, int y)->int{
        if(x == y || x == y+1) return x+y;
        return inf;
    };
   
    if(diff%2 == 0){ // 
        chmin(ans, f(cnt[1][1], cnt[1][0]));
    }
    if(same%2 == 1){ // diff
        chmin(ans, f(cnt[0][1], cnt[0][0]));
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}