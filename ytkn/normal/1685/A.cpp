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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n%2 == 1){
        cout << "NO" << endl;
        return;
    }
    int m = n/2;
    sort(a.begin(), a.end());
    vector<int> al, ar;
    for(int i = 0; i < n/2; i++) al.push_back(a[i]);
    for(int i = n/2; i < n; i++) ar.push_back(a[i]);
    vector<int> ans;
    if(al.back() < ar[0]){
        for(int i = 0; i < m; i++) {
            ans.push_back(al[i]);
            ans.push_back(ar[i]);
        }
    }else{
        int c = al.back();
        int cnt_l = 0, cnt_r = 0;
        for(int x: al) {
            if(x == c) cnt_l++;
        }
        for(int x: ar) {
            if(x == c) cnt_r++;
        }
        if(cnt_r == m || cnt_l == m){
            cout << "NO" << endl;
            return;
        }
        if(m-cnt_l < cnt_r+1){
            cout << "NO" << endl;
            return;
        }
        if(m-cnt_r < cnt_l+1){
            cout << "NO" << endl;
            return;
        }
        reverse(ar.begin(), ar.end());
        reverse(al.begin(), al.end());
        for(int i = 0; i < m; i++) {
            ans.push_back(ar[i]);
            ans.push_back(al[i]);
        }
    }
    cout << "YES" << endl;
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}