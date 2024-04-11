#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(n+1);
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '+') cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1]-1;
        v[i] = min(v[i-1], cnt[i]);
    }
    ll ans = 0;
    int l = 0;
    for(int i = 0; i <= n; i++){
        while(l < n){
            if(v[l]+i < 0) break;
            l++;
        }
        ans += l;
        if(l == n && v[l]+i >= 0) break;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}