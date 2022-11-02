#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll pow(int a, ll n){
    ll tmp = a;
    ll ans = 1;
    for(int i = 0; i <= 30; i++){
        ll m = (ll)1 << i;
        if(m&n){
            ans *= tmp;
            ans %= MOD;
        }
        tmp *= tmp;
        tmp %= MOD;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    ll p = pow(2, m)-1;
    p %= MOD;
    p += MOD;
    p %= MOD;
    ans = pow(p, n);
    cout << ans << endl;
}