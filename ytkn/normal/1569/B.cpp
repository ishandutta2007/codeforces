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
    int n; cin >> n;
    string s; cin >> s;
    assert(s.size() == n);
    vector<int> u;
    for(int i = 0; i < n; i++) {
        if(s[i] == '2') u.push_back(i);
    }
    if(u.size() > 0 && u.size() <= 2){
        cout << "NO" << endl;
        return;
    }
    vector<string> ans(n, string(n, '='));
    for(int i = 0; i < n; i++) ans[i][i] = 'X';
    int m = u.size();
    for(int i = 0; i < m; i++){
        int j = (i+1)%m;
        int p = u[i];
        int q = u[j];
        ans[p][q] = '+';
        ans[q][p] = '-';
    }
    cout << "YES" << endl;
    for(string t: ans) cout << t << endl;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            for(int j = 0; j < n; j++) assert(ans[i][j] != '-');
        }else{
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == '+') cnt++;
            }
            assert(cnt > 0);
        }
    }
   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}