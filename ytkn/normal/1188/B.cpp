#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll a[300000];
map<ll, ll> mp;
ll n, p, k;

ll calc(ll x){
    ll tmp = (((((x*x)%p)*x)%p)*x)%p;
    return (tmp-(x*k)%p+p)%p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> p >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll tmp = calc(a[i]);
        if(mp.count(tmp) == 0){
            mp[tmp] = 1;
        }else{
            mp[tmp]++;
        }
    }
    ll ans = 0;
    for( auto i : mp){
        ans += (i.second*(i.second-1))/2;
    }
    cout << ans << endl;
}