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

void solve(){
    string s; cin >> s;
    int n = s.size();
    auto is_palindrome = vec2d(n+1, n+1, false);
    for(int i = 0; i <= n; i++) is_palindrome[i][i] = true;
    for(int i = 0; i < n; i++){
        is_palindrome[i][i+1] = true;
    }
    
    for(int len = 2; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = l+len;
            if(r > n) continue;
            if(is_palindrome[l+1][r-1] && s[l] == s[r-1]) is_palindrome[l][r] = true;
        }
    }
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    auto is_palindrome_rev = vec2d(n+1, n+1, false);
    for(int i = 0; i <= n; i++) is_palindrome_rev[i][i] = true;
    for(int i = 0; i < n; i++){
        is_palindrome_rev[i][i+1] = true;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = l+len;
            if(r > n) continue;
            if(is_palindrome_rev[l+1][r-1] && s_rev[l] == s_rev[r-1]) is_palindrome_rev[l][r] = true;
        }
    }
    string ans;
    // debug_value(s);
    // debug_value(s_rev);
    for(int i = 0; i < n; i++){
        for(int r = n; r >= i+1; r--){
            int len = r+i;
            if(len > n) continue;
            if(is_palindrome[i][r]){
                string tmp = s.substr(0, r);
                string t = s_rev.substr(0, i);
                reverse(t.begin(), t.end());
                tmp += t;
                if(ans.size() < tmp.size()) ans = tmp;
                break;
            }
        }
        for(int r = n; r >= i+1; r--){
            int len = r+i;
            if(len > n) continue;
            if(is_palindrome_rev[i][r]){
                string tmp = s.substr(0, i);
                string t = s_rev.substr(0, r);
                reverse(t.begin(), t.end());
                tmp += t;
                if(ans.size() < tmp.size()) ans = tmp;
                break;
            }
        }
        if(s[i] != s_rev[i]) break;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}