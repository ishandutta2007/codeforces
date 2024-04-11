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

inline char inv(char c){
    if(c == '?') return c;
    if(c == '0') return '1';
    return '0';
}

ll tri(ll x){
    return (x*(x+1))/2;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i += 2) s[i] = inv(s[i]);
    ll ans = 0;
    vector<int> l(2, -1);
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            ans += i-min(l[0], l[1]);            
        }else if(s[i] == '0'){
            ans += i-l[1];
            l[0] = i;
        }else{
            ans += i-l[0];
            l[1] = i;            
        }
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