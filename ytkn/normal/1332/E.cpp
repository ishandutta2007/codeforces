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

template <typename T>
T pow(T a, ll n){
    T ans = 1;
    T tmp = a;
    for(int i = 0; i <= 60; i++){
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
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    
    ll P = n*m;
    ll s = pow<ll>(R-L+1, P);
    ll inv2 = (MOD+1)/2;
    if((m%2 == 1) && (n%2 == 1)){
        cout << s << endl;
        return 0;        
    }
    if((R-L)%2 == 0){
        cout << ((s+1)*inv2)%MOD << endl;
    }else{
        cout << (s*inv2)%MOD << endl;
    }
}