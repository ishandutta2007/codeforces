#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n;

const int maxn = 505;
int op[maxn];
pi a[maxn];

const int mod = 998244353;
int dp[maxn][maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int S = 0;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        if(s[0] == '-'){
            op[i] = -1;
        }else{
            op[i] = 1;
            cin >> a[i].fi;
            a[i].se = i;
            S++;
        }
    }
    int ans = 0;
    for(int k = 1;k <= n;k++){
        if(op[k] == 1){
            for(int i = 0;i <= n;i++){
                for(int j = 0;j <= S;j++){
                    dp[i][j] = 0;
                }
            }
            dp[0][0] = 1;
            for(int i = 0;i < n;i++){
                for(int j = 0;j <= S;j++){
                    if(i+1 == k){
                        add(dp[i+1][j+1], dp[i][j]);
                    }else{
                        add(dp[i+1][j], dp[i][j]);
                        if(op[i+1] == 1){
                            add(dp[i+1][j + (a[i+1] <= a[k])], dp[i][j]); 
                        }else{
                            if(i+1 > k){
                                if(j > 1)
                                    add(dp[i+1][j-1], dp[i][j]);
                            }else{
                                add(dp[i+1][max(0, j-1)], dp[i][j]);
                            }
                        }
                    }
                }
            }
            int cnt = 0;
            for(int j = 1;j <= S;j++){
                add(cnt, dp[n][j]);
            }
            add(ans, 1LL * a[k].fi * cnt % mod);
        }
    }
    cout << ans << endl;
    return 0;
}