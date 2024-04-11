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

const ll inf = 4e18;

void solve(){
    int n; ll k, x; cin >> n >> k >> x;
    string s; cin >> s;
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(s[i] == '*') cnt++;
        else{
            v.push_back(cnt);
            cnt = 0;
            v.push_back(-1);
        }
    }
    if(cnt > 0) v.push_back(cnt);
    string ans;
    ll rem = x-1;
    reverse(v.begin(), v.end());
    for(int x: v){
        if(x == -1) ans += 'a';
        else{
            ll y = rem%(x*k+1);
            rem /= (x*k+1);
            for(int i = 0; i < y; i++) ans += 'b';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}