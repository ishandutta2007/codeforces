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

int n;
const int maxn = 1e5 + 5;
ll d[maxn];
ll sum[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> d[i];
        }
        sort(d + 1, d + 1 + n);
        sum[0] = 0;
        ll ans = d[n] - d[1];
        for(int i = 1;i <= n;i++){
            sum[i] = sum[i-1] + d[i];
            ans += sum[i] - 1LL * i * d[i];
        } 
        cout << ans << endl;
    }
    return 0;
}