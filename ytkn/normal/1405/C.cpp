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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<char> v(k, '?');
    for(int i = 0; i < n; i++){
        int j = i%k;
        if(s[i] == '?') continue;
        if(v[j] == '?'){
            v[j] = s[i];
            continue;
        }
        if(v[j] != s[i]){
            cout << "NO" << endl;
            return;
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for(char c : v){
        if(c == '0') cnt0++;
        if(c  == '1') cnt1++;
    }
    if(cnt0*2 <= k && cnt1*2 <= k){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}