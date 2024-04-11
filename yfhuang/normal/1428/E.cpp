#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, k;

const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];

priority_queue<pair<double, int>> pq;

ll compute(ll x, ll y){
    ll n1 = x % y;
    ll n2 = y - n1; 
    return n1 * (x / y + 1) * (x / y + 1) + n2 * (x / y) * (x / y);
}

ll delta(ll x, ll y){
    return compute(x, y) - compute(x, y + 1);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = 1;
        pq.push(mp(delta(a[i], 1), i));
    }
    for(int i = n + 1;i <= k;i++){
        pair<double, int> p = pq.top();
        pq.pop();
        b[p.se]++;
        pq.push(mp(delta(a[p.se], b[p.se]), p.se));
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ll c = a[i] % b[i];
        ll d = b[i] - c;
        ans += d * (a[i] / b[i]) * (a[i] / b[i]) + c * (a[i] / b[i] + 1) * (a[i] / b[i] + 1);
    }
    cout << ans << endl;
    return 0;
}