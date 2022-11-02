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

int n, k;
int a[500000], b[500000];

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
    }
}

const int INF = 2e9;

void solve_k0(){
    vector<int> dp(n+3, INF);
    for(int i = 0; i < n; i++){
        auto p = upper_bound(dp.begin(), dp.end(), a[i]-i);
        *p = a[i]-i;
    }
    auto p = lower_bound(dp.begin(), dp.end(), INF);
    cout << n-(p-dp.begin()) << endl;
}

 
int calc_lis(int l, int r){
    int m = r-l+1;
    vector<int> v;
    for(int i = l; i <= r; i++){
        int d = i-l;
        v.push_back(a[i]-a[l]-d);
    }
    vector<int> dp(m+2, INF);
    for(int x : v){
        if(x < 0) continue;
        auto p = upper_bound(dp.begin(), dp.end(), x);
        *p = x;
        // cout << x << ' ';
    }
    // cout << endl;
    auto p = upper_bound(dp.begin(), dp.end(), v[m-1]);
    return m-(int)(p-dp.begin()); 
}

int calc_l_lis(int r){
    int m = r+1;
    vector<int> v;
    for(int i = 0; i <= r; i++){
        v.push_back(a[i]-i);
    }
    vector<int> dp(m+2, INF);
    for(int x : v){
        auto p = upper_bound(dp.begin(), dp.end(), x);
        *p = x;
        // cout << x << ' ';
    }
    // cout << endl;
    auto p = upper_bound(dp.begin(), dp.end(), v[m-1]);
    return m-(int)(p-dp.begin()); 
}

int calc_r_lis(int l){
    int m = n-l;
    vector<int> v;
    vector<int> dp(m+2, INF);
    for(int i = l; i < n; i++){
        int d = i-l;
        v.push_back(a[i]-a[l]-d);
    }

    for(int x : v){
        if(x < 0) continue;
        auto p = upper_bound(dp.begin(), dp.end(), x);
        *p = x;
        // cout << a[i] << ' ';
    }
    // cout << ' ' << endl;
    auto p = lower_bound(dp.begin(), dp.end(), INF);
    return m-(int)(p-dp.begin()); 
}

void solve(){
    for(int i = 0; i < k-1; i++){
        int l = b[i], r = b[i+1];
        int d = r-l;
        if(a[l]+d > a[r]){
            cout << -1 << endl;
            return;
        }
    }
    if(k == 0){
        solve_k0();
        return;
    }
    int ans = 0;
    ans += calc_l_lis(b[0]);
    for(int i = 0; i < k-1; i++){
        int l = b[i], r = b[i+1];
        ans += calc_lis(l, r);
    }
    ans += calc_r_lis(b[k-1]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}