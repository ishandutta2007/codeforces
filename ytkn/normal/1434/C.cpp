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
typedef unsigned long long ull;
ll a, b, c, d;

ll calc(ll k){
    ll ans = a*k;
    ans -= d*b*(k*(k-1))/2;
    return ans;
}

void solve(){
    cin >> a >> b >> c >> d;
    if(a-b*c > 0){
        cout << -1 << endl;
        return;
    }
    if(c < d){
        cout << a << endl;
        return;
    }
    if(a-d*b <= 0){
        cout << a << endl;
        return;
    }
    ll l = 2, r = 2*(c+d-1)/d+1;
    // cout << r << endl;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(1+(x-1)*(d) > 1+c){
            r = x;
        }else{
            ll t = (x-1)*b*d;
            if(t >= a) r = x;
            else l = x;
        }
    }
    // cout << "H " << l << endl;
    cout << calc(l) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}