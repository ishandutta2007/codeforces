#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;
int n;
char s[maxn];
const int mod = 998244353;

void add(int &a, int b){
    a += b;
    if(a >= mod){
        a -= mod;
    }
}

int dp[maxn][2][2][2][2][2][2];

void Dp(){
    dp[0][1][1][1][0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        int d = s[i] - '0';
        for(int la = 0;la < 2;la++){
            int ua = (la == 0) ? 1 : d;
            for(int lb = 0;lb < 2;lb++){
                int ub = (lb == 0) ? 1 : d;
                for(int lc = 0;lc < 2;lc++){
                    int uc = (lc == 0) ? 1 : d;
                    for(int a0 = 0;a0 < 2;a0++){
                        for(int b0 = 0;b0 < 2;b0++){
                            for(int c0 = 0;c0 < 2;c0++){
                                for(int ja = 0;ja <= ua;ja++){
                                    for(int jb = 0;jb <= ub;jb++){
                                        for(int jc = 0;jc <= uc;jc++){
                                            int ab = ja ^ jb;
                                            int ac = ja ^ jc;
                                            int bc = jb ^ jc;  
                                            int diff = (ab != ac) | (ab != bc) | (ac != bc);
                                            int nla = la & (ja == d);
                                            int nlb = lb & (jb == d); 
                                            int nlc = lc & (jc == d);
                                            int na0 = a0 | ((ab == 0) & diff);
                                            int nb0 = b0 | ((ac == 0) & diff);
                                            int nc0 = c0 | ((bc == 0) & diff);
                                            add(dp[i][nla][nlb][nlc][na0][nb0][nc0], dp[i-1][la][lb][lc][a0][b0][c0]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } 
    }
    int ans = 0;
    for(int la = 0;la < 2;la++){
        for(int lb = 0;lb < 2;lb++){
            for(int lc = 0;lc < 2;lc++){
                add(ans, dp[n][la][lb][lc][1][1][1]);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    Dp(); 
    return 0;
}