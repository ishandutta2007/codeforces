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
    int a_max = *max_element(a.begin(), a.end());
    int a_min = *min_element(a.begin(), a.end());
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%3 != 0) cnt++;
    }
    if(a_max%3 == 0){
        if(cnt == 0) cout << a_max/3 << endl;
        else cout << a_max/3+1 << endl;
        return;
    }
    int cnt_ng = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%3 == 0) continue;
        if((a[i]%3) == (a_max%3)) continue;
        cnt_ng++;
    }
    if(a_max%3 == 2){
        if(cnt_ng == 0) cout << a_max/3+1 << endl;
        else cout << a_max/3+2 << endl;
        return;
    }
    bool req1 = a_min == 1;
    for(int i = 0; i < n; i++){
        if(a[i]+1 == a_max) req1 = true;
    }
    if(cnt_ng > 0 && req1) {
        cout << a_max/3+2 << endl;
    }
    else cout << a_max/3+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}