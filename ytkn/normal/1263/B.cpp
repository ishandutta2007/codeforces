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
    vector<string> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    int cnt = 0;
    vector<string> ans(n);
    ans[0] = p[0];
    for(int i = 1; i < n; i++){
        bool ok = true;
        for(int j = 0; j < i; j++){
            if(ans[j] == p[i]) ok = false;
        }
        vector<bool> used(10);
        for(int j = 0; j < i; j++){
            used[ans[j][0]-'0'] = true;
        }
        ans[i] = p[i];
        if(ok) continue;
        cnt++;
        for(int j = i+1; j < n; j++){
            used[p[j][0]-'0'] = true;
        }
        for(int x = 0; x < 10; x++){
            if(!used[x]){
                ans[i][0] = '0'+x;
                break;
            }
        }
    }
    cout << cnt << endl;
    print_vector(ans, '\n');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}