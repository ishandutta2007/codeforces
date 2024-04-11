#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll a[200000];
ll v1[100000];
ll v2[100000];


void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i%2 == 0) ans += a[i];
    }
    if(n == 1){
        cout << a[0] << endl;
        return;
    }else if(n == 2){
        cout << max(a[0], a[1]) << endl;
        return;
    }
    v1[0] = a[1]-a[0];
    v2[0] = a[1]-a[2];
    ll m1 = min((ll)0, v1[0]), m2 = min((ll)0, v2[0]);
    ll sum = ans;
    ans = max(ans, sum+v1[0]);
    ans = max(ans, sum+v2[0]);
    for(int i = 3; i < n; i++){
        if(i%2 == 1){
            int j = i/2;
            v1[j] = v1[j-1]+a[i]-a[i-1];
            ans = max(ans, sum+v1[j]-m1);
            m1 = min(m1, v1[j]);
        }else{
            int j = (i-2)/2;
            v2[j] = v2[j-1]+a[i-1]-a[i];
            ans = max(ans, sum+v2[j]-m2);
            m2 = min(m2, v2[j]);
        }
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