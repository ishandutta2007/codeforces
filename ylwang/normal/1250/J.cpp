#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define mod 1000000007
ll f[2][2010][2010];
/*
f[op][i][j] : (i, j)/ 
*/
bool s[2010][2010];
char str[2010][2010];
int sum1[2010][2010], sum2[2010][2010];

/*
sum1[i][j] : 
sum2[i][j] : 
*/ 
 
int main(){
    int n = read(), m = read(); 
    for(int i = 1; i <= n; i++){
        scanf("%s", str[i] + 1);
        for(int j = 1; j <= m; j++)
            s[i][j] = (str[i][j] == 'R');
    }
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--){
            sum1[i][j] = s[i][j] + sum1[i + 1][j];
            sum2[i][j] = s[i][j] + sum2[i][j + 1];
        }
    f[0][1][1] = f[1][1][1] = 1;
    f[0][1][2] = -1;
    f[1][2][1] = -1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            f[0][i][j] += f[0][i][j - 1];
            f[1][i][j] += f[1][i - 1][j];
            f[0][i][j] %= mod;
            f[1][i][j] %= mod;
            
            f[1][i + 1][j] += f[0][i][j];
            f[1][i + 1][j] %= mod;
            f[1][n - sum1[i + 1][j] + 1][j] += mod - f[0][i][j];
            f[1][n - sum1[i + 1][j] + 1][j] %= mod;
 
            f[0][i][j + 1] += f[1][i][j];
            f[0][i][j + 1] %= mod;
            f[0][i][m - sum2[i][j + 1] + 1] += mod - f[1][i][j];
            f[0][i][m - sum2[i][j + 1] + 1] %= mod;
        }
    if(n == 1 && m == 1)
        printf("1\n");
    else
        printf("%lld\n", (f[0][n][m] + f[1][n][m]) % mod);
}