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

string sub_solve(int n){
    if(n == 0) return "";
    if(n <= 25){
        string ans;
        for(int i = 0; i < n; i++) ans += 'a'+i;
        return ans;    
    }
    if(n%2 == 1){
        return sub_solve(n-1)+"e";
    }
    int l = (n-1)/2, r = (n+1)/2;
    string ans;
    for(int i = 0; i < l; i++) ans += 'a';
    ans += 'b';
    for(int i = 0; i < r; i++) ans += 'a';
    return ans;
}

void verify(string s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 1; i+j <= n; j++){
            string t = s.substr(i, j);
            int cnt = 0;
            for(int k = 0; k+j <= n; k++){
                if(t == s.substr(k, j)) cnt++;
            }
            if(cnt%2 != 1){
                cout << t << endl;
            }
            assert(cnt%2 == 1);
        }
    }
}

void solve(){
    int n; cin >> n;
    auto ans = sub_solve(n);
    cout << ans << endl;
    assert(ans.size() == n);
    // verify(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}