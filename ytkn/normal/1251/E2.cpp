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

ll p_[200000], m[200000];
P p[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll t;
    cin >> t;
    for(ll dum = 0; dum < t; dum++){
        ll n;
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> m[i] >> p_[i];
            p[i] = P(m[i], p_[i]);
        }
        sort(p, p+n, greater<P>());
        
        priority_queue<ll, vector<ll>, greater<ll>> que;
        ll cnt = 1;
        ll pay = 0;
        ll ans = 0;
        que.push(p[0].second);
        for(ll i = 1; i < n; i++){
            if(p[i].first == p[i-1].first){
                cnt++;
                que.push(p[i].second);
            }else{
                ll prev = p[i-1].first;
                while(n-i+pay < prev){
                    ll top = que.top();
                    que.pop();
                    ans += (ll) top;
                    pay++;
                }
                cnt = 1;
                que.push(p[i].second);
            }
        }
        ll prev = p[n-1].first;
        while(pay < prev){
            ll top = que.top();
            que.pop();
            ans += (ll) top;
            pay++;
        }
        cout << ans << endl;
    }
}