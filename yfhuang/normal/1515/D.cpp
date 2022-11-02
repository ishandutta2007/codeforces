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
int n, L, R;
const int maxn = 2e5 + 5;
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> L >> R;
        for(int i = 1;i <= n;i++){
            cnt[i] = 0;
        }
        for(int i = 1;i <= n;i++){
            int col;
            cin >> col;
            if(i <= L){
                cnt[col]++;
            }else{
                cnt[col]--;
            }
        }
        ll ans = 0;
        if(L < R){
            for(int i = 1;i <= n;i++){
                cnt[i] = -cnt[i];
            }
        }
        L = 0, R = 0;
        for(int i = 1;i <= n;i++){
            if(cnt[i] >= 0)
                L += cnt[i];
            else
                R -= cnt[i];
        }
        for(int i = 1;i <= n;i++){
            if(cnt[i] >= 0){
                ll change = min(cnt[i], L - R) / 2;
                cnt[i] -= 2 * change;
                L -= 2 * change;
                ans += change;
            }
        }
        ans += (L - R) / 2;
        ans += (L + R) / 2;
        cout << ans << endl;
    }
    return 0;
}