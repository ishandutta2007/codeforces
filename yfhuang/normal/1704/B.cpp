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
ll n, x;
const ll INF = 1e15;
const int maxn = 2e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> x;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        ll l = -INF, r = INF;
        ll ans = 0;
        for(int i = 1;i <= n;i++){
            if(r < a[i] - x or l > a[i] + x){
                ans++;
                l = a[i] - x;
                r = a[i] + x;
            }else{
                r = min(r, a[i] + x);
                l = max(l, a[i] - x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}