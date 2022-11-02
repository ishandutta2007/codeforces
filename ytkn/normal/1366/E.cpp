#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n ,m;
int a[200000], b[200000];
int a_min[200000];

map<int, ll> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    a_min[n-1] = a[n-1];
    mp[a_min[n-1]] = 1;
    for(int i = n-2; i >= 0; i--){
        a_min[i] = min(a[i], a_min[i+1]);
        if(mp.count(a_min[i]) == 0){
            mp[a_min[i]] = 1;
        }else{
            mp[a_min[i]]++;
        }
    }
    if(a_min[0] != b[0]){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1; i < m; i++){
        if(mp.count(b[i]) == 0){
            ans = 0;
        }else{
            ans *= mp[b[i]];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}