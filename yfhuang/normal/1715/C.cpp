#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m;
const int maxn = 1e5 + 5;
int a[maxn];

set<int> itv;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    itv.insert(n + 1);
    ll ans = 1LL * n * (n + 1) / 2;
    for(int i = 1;i < n;i++){
        if(a[i + 1] != a[i]){
            ans += 1LL * i * (n - i);
        }
    }
    for(int i = 1;i <= m;i++){
        int x, v;
        cin >> x >> v;
        if(x > 1 and a[x] != a[x-1]){
            ans -= 1LL * (x - 1) * (n - x + 1);
        }
        if(x < n and a[x] != a[x + 1]){
            ans -= 1LL * x * (n - x);
        }
        a[x] = v;
        if(x > 1 and a[x] != a[x-1]){
            ans += 1LL * (x - 1) * (n - x + 1);
        }
        if(x < n and a[x] != a[x + 1]){
            ans += 1LL * x * (n - x);
        }
        cout << ans << endl;
    }
    return 0;
}