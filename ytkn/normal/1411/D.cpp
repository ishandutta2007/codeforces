#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s; cin >> s;
    int n = s.size();
    ll x, y; cin >> x >> y;
    if(x < y){
        swap(x, y);
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') s[i] = (s[i] == '0' ? '1' : '0');
        }
    }
    // 1 -> 0
    ll ans = 0;
    vector<ll> cnt(2);
    // 1
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            ans += y*cnt[1];
            cnt[0]++;
        }else{
            ans += x*cnt[0];
            cnt[1]++;
        }
    }
    vector<ll> cnt_after(2);
    ll cur = ans;  
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '?'){ // 0
            cnt[1]--;
            cur += y*cnt[1]+x*cnt_after[1]-x*cnt[0]-y*cnt_after[0];
            cnt_after[0]++;
        }else if(s[i] == '0'){
            cnt_after[0]++;
            cnt[0]--;
        }else if(s[i] == '1'){
            cnt_after[1]++;
            cnt[1]--;
        }
        chmin(ans, cur);
    }
    cout << ans << endl;
}