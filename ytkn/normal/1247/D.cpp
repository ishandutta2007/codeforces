#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
ll a[100000];
ll n, k;

P calc(ll N){
    ll ans = 1;
    ll inv = 1;
    for(ll i = 2; i*i <= N; i++){
        if(N%i == 0){
            ll cnt = 0;
            while(N%i == 0){
                N /= i;
                cnt++;
            }
            cnt = cnt%k;
            for(ll j = 0; j < cnt; j++) ans *= i;
            for(ll j = 0; j < (k-cnt)%k; j++) inv *= i;
        }
    }
    if(N != 1){
        ans *= N;
        for(int i = 0; i < k-1; i++) inv *= N;
    }
    return P(ans, inv);
}

ll inv[100000], b[100000];
map<ll, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        P p = calc(a[i]);
        inv[i] = p.second;
        b[i] = p.first;
        if(mp.count(p.first) == 0){
            mp[p.first] = 1;
        }else{
            mp[p.first]++;
        }
       // cout << p.first << ' ' << p.second << endl;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(inv[i] == b[i]){
            ans += (mp[b[i]]-1);
        }
        else if(mp.count(inv[i]) != 0){
            ans += mp[inv[i]];
        }
    }
    ans /= 2;
    cout << ans << endl;
}