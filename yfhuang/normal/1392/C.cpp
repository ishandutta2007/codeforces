#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int T;
const int maxn = 2e5 + 5;

typedef long long ll;

ll a[maxn];
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = n;i > 1;i--){
            if(a[i - 1] > a[i]){
                ans += a[i - 1] - a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}