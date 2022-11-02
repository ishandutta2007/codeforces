#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 5;

typedef long long ll;

ll k;
ll a[maxn];
ll b[maxn];

ll f(ll b, ll a){
    return a - (3 * b * b - 3 * b + 1);
}

int cal(int id, ll val){
    int l = 0, r = a[id];
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(f(mid, a[id]) >= val){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}

ll solve(ll val){
    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        cnt += cal(i, val);       
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    ll l = -4e18, r = 4e18;
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(solve(mid) >= k){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    ll del = solve(l) - k;
    for(int i = 1;i <= n;i++){
        b[i] = cal(i, l);
        if(del > 0 and f(b[i], a[i]) == l){
            b[i]--, del--;
        }
    }
    for(int i = 1;i <= n;i++){
        cout << b[i] << ((i == n) ? '\n' : ' ');
    }
    return 0;
}