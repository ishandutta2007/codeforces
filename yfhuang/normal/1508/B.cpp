#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
int n;
ll k;

const int maxn = 1e5 + 5;
const ll INF = 1e18 + 100;
ll f[maxn];
ll suf[maxn];
int ans[maxn];

void add(ll &a, ll b){
    a += b;
    if(a > INF)
        a = INF;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        f[n + 1] = 1; 
        suf[n + 1] = 1;
        for(int i = n;i >= 1;i--){
            f[i] = suf[i + 1]; 
            suf[i] = suf[i + 1];
            add(suf[i], f[i]);
        }
        if(k > f[1]){
            cout << -1 << endl;
        }else{
            int cur = 0;
            for(int i = 1;i <= max(0, n - 100);i++){
                ans[i] = ++cur;
            } 
            for(int i = max(0, n - 100) + 1, j;i <= n;i = j){
                ll now = 0;
                for(j = i + 1;j <= n + 1;j++){
                    if(f[j] >= k){
                        break;
                    }else{
                        k -= f[j];
                    }
                }
                for(int k = j - 1;k >= i;k--){
                    ans[k] = ++cur;
                } 
            }
            for(int i = 1;i <= n;i++){
                cout << ans[i] << ((i == n) ? '\n' : ' ');
            }
        }
    }
    return 0;
}