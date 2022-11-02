#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
ll n;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        ll prev = n;
        ll val = 1;
        ll ans = 0;
        for(ll i = 2;prev > 0;i++){
            ll g = gcd(val, i);
            ll nxt = prev / (i / g);
            ans = (ans + (prev - nxt) % mod * i) % mod;
            prev = nxt;
            val *= (i / g);
        }
        cout << ans << endl;
    }
    return 0;
}