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
    int n; string s; cin >> n >> s;
    auto calc = [&](char c)->int{
        int l = 0, r = n-1;
        int ans = 0;
        while(l <= r){
            if(l == r) {
                ans++;
                break;
            }
            if(s[l] == s[r]){
                ans += 2;
                l++;
                r--;
                continue;
            }
            if(s[l] == c){
                l++;
            }else if(s[r] == c){
                r--;
            }else{
                return inf;
            }
        }
        return n-ans;
    };
    int ans = inf;
    for(int i = 0; i < 26; i++){
        char c = 'a'+i;
        chmin(ans, calc(c));
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