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
const int maxn = 105;
int a[maxn];
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            cnt[abs(a[i])]++;
        }
        int ans = 0;
        for(int i = 1;i <= 100;i++){
            cnt[i] = min(cnt[i], 2);
            ans += cnt[i];
        }
        ans += (cnt[0] > 0);
        cout << ans << endl;
    }
    return 0;
}