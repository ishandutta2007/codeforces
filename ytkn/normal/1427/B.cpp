#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    if(s[0] == 'W') ans++;
    for(int i = 1; i < n; i++){
        if(s[i] == 'W'){
            if(s[i-1] == 'W') ans += 2;
            else ans++;
        }
    }
    bool found_w = false;
    int cnt_l = 0;
    int cnt_l_ok = 0;
    int tmp = 0;
    vector<int> v;
    for(char c : s){
        if(c == 'W') {
            found_w = true;
            if(tmp != 0){
                v.push_back(tmp);
                tmp = 0;
            }
        }
        if(c == 'L') {
            cnt_l++;
            if(found_w) tmp++;
        }
    }
    k = min(k, cnt_l);
    sort(v.begin(), v.end());
    for(int i : v){
        if(k >= i){
            k -= i;
            ans += 2*i+1;
        }else if(k > 0){
            ans += 2*k;
            k = 0;
        }
    }
    if(cnt_l == n){
        ans += max(0, 2*k-1);
    }else{
        ans += 2*k;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}