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
typedef pair<ll, int> P;

int n, k;
ll a[100000];
int cnt[100000];

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
}

ll calc(ll sum, ll c){
    ll ans = 0;
    ll l = sum/c;
    ll rem = sum%c;
    ans += l*l*(c-rem);
    ans += (l+1)*(l+1)*rem;
    return ans;
}

void solve(){
    priority_queue<P> que;
    for(int i = 0; i < n; i++){
        cnt[i] = 1;
        ll g = calc(a[i], cnt[i]) - calc(a[i], cnt[i]+1);
        que.push(P(g, i));
    }
    for(int i = n; i < k; i++){
        P p = que.top(); que.pop();
        int j = p.second;
        cnt[j]++;
        ll g = calc(a[j], cnt[j]) - calc(a[j], cnt[j]+1);
        que.push(P(g, j));
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll l = a[i]/cnt[i];
        ll rem = a[i]%cnt[i];
        ans += l*l*(cnt[i]-rem);
        ans += (l+1)*(l+1)*rem;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}