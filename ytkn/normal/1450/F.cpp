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

void solve(){
    int n; cin >> n;
    vector<int> a(n), cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        cnt[a[i]]++;
    }
    int cnt_max = *max_element(cnt.begin(), cnt.end());
    if(cnt_max >= (n+1)/2+1) {
        cout << -1 << endl;
        return;
    }
    vector<int> sect_cnt(n);
    int ans = 0;
    int l = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            ans++;
            sect_cnt[l]++;
            sect_cnt[a[i-1]]++;
            // cout << l << '-' << a[i] << ' ';
            l = a[i];
        }
        if(i == n-1){
            sect_cnt[l]++;
            sect_cnt[a[i]]++;
            // cout << l << '-' << a[i] << ' ';
        }
    }
    // cout << endl;
    int max_sect_cnt = *max_element(sect_cnt.begin(), sect_cnt.end());
    int sum_sect_cnt = accumulate(sect_cnt.begin(), sect_cnt.end(), 0);
    if(2*(max_sect_cnt-2) > sum_sect_cnt-2){
        // cout << max_sect_cnt << ' ' << sum_sect_cnt << endl;
        ans += (2*(max_sect_cnt-2) - (sum_sect_cnt-2))/2;
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