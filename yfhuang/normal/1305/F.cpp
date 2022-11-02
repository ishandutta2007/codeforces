#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;

const int maxn = 2e5 + 5;
ll a[maxn];

set<ll> s;

void cal(ll x){
    for(ll i = 2;i * i <= x;i++){
        if(x % i == 0){
            s.insert(i);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x > 1){
        s.insert(x);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    shuffle(a + 1, a + 1 + n, rng);
    for(int i = 1;i <= min(n, 20);i++){
        cal(a[i] - 1);
        cal(a[i] + 1);
        cal(a[i]);
    }
    ll ans = 1e18;
    for(auto num : s){
        ll tmp = 0;
        for(int i = 1;i <= n;i++){
            ll left = a[i] % num; 
            if(a[i] < num){
                tmp += num - a[i];
            }else{
                tmp += min(left, num - left);
            }
        } 
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}