#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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

int calc(vector<int> v){
    assert(v.size() == 10);
    int a = 0, b = 0;
    for(int i = 0; i < 5; i++){
        if(v[2*i] == 1) a++;
        if(b+5-i < a) return 2*i+1;
        if(a+5-(i+1) < b) return 2*i+1;

        if(v[2*i+1] == 1) b++;
        if(a+5-(i+1) < b) return 2*i+2;
        if(b+5-(i+1) < a) return 2*i+2;
    }
    return 10;
}

void solve(){
    string s; cin >> s;
    vector<int> u;
    int n = 10;
    for(int i = 0; i < n; i++){
        if(s[i] == '?') u.push_back(i);
    }
    
    int m = u.size();
    int ans = 10;
    for(int i = 0; i < (1<<m); i++){
        vector<int> v(10);
        for(int j = 0; j < n; j++){
            if(s[j] == '1') v[j] = 1;
        }
        for(int j = 0; j < m; j++){
            if(i&(1<<j)) v[u[j]] = 1; 
        }
        chmin(ans, calc(v));
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