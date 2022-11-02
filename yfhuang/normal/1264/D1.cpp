#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 998244353L;

const int maxn = 2005;
LL c[maxn][maxn];
LL pre[maxn][maxn];
int n;

void init(){
    memset(c, 0, sizeof(c));
    memset(pre, 0, sizeof(pre));
    c[0][0] = 1;
    pre[0][0] = 1;
    for(int i = 1;i <= n;i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j < i;j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
        for(int j = i;j >= 0;j--){
            pre[i][j] = (pre[i][j + 1] + c[i][j]) % mod;
        }
    }
}

LL comb(int x, int y){
    if(y < 0 || y > x) return 0;
    return c[x][y];
}

LL comb1(int x, int y){
    y = max(y, 0);
    if(y > x) return 0;
    return pre[x][y];
}

int qc[maxn], lc[maxn], rc[maxn];

char s[maxn];

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        qc[i] = qc[i - 1] + (s[i] == '?');
        lc[i] = lc[i - 1] + (s[i] == '(');
        rc[i] = rc[i - 1] + (s[i] == ')');
    }    
    init();
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == ')') continue;
        for(int j = 1;j <= n / 2;j++){
            LL ans1 = comb(qc[i - 1], (j - 1) - (lc[i - 1]));
            LL ans2 = comb1(qc[n] - qc[i], j - (rc[n] - rc[i]));
            ans = (ans + ans1 * ans2) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}