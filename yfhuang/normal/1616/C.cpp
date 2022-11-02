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
const int maxn = 105;
int a[maxn];

int dp[maxn][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i]; 
        }
        int ans = n - 1;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                int tmp = 0;
                for(int k = 1;k <= n;k++){
                    if((j - i) * (a[k] - a[i]) != (k - i) * (a[j] - a[i])){
                        tmp++;
                    } 
                }
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}