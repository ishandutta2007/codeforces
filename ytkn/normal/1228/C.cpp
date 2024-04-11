#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

vector<ll> fac(ll n){
    vector<ll> ans;
    ll m = n;
    for(int i = 2; i*i <= n; i++){
        if(m%i == 0) ans.push_back(i);
        while(m%i == 0){
            m /= i;
        }
    }
    if(m != 1) ans.push_back(m);
    return ans;
}

// n**m
ll pow(ll n, ll m){
    ll ans = 1;
    ll tmp = n;
    for(int i = 0; i <= 62; i++){
        ll c = ((ll)1) << i;
        if(c&m) {
            ans *= tmp;
            ans %= MOD;
        }
        tmp *= tmp;
        tmp %= MOD;
    }
    return ans;
}

int main(){
    ll x, n;
    cin >> x >> n;
    vector<ll> v = fac(x);
    ll ans = 1;
    //vector<ll> cnt;
    for(int i = 0; i < v.size(); i++){
        ll tmp = v[i];
        ll c = 0;
        double tmp_ = tmp;
        while(tmp_ <= 2*n){
            c += n/tmp;
            tmp_ *= v[i];
            tmp *= v[i];
        }
        ans *= pow(v[i], c);
        ans %= MOD;
    }
    cout << ans << endl;
}