#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 4005;
const int maxm = 805;
int u[maxn][maxn];
int dp[maxm][maxn];
int f[maxm][maxn];

void read(int &x){
	char ch;x=0;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	x=ch-'0';
}

int Sum(int l, int r){
    return u[r][r] - u[l-1][r] - u[r][l-1] + u[l-1][l-1];
}

int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            read(u[i][j]);
            u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
        }
    }
    for(int i = 1;i <= n;i++){
        dp[0][i] = 1e9;
    }
    for(int i = 1;i <= m;i++){
        for(int j = n;j >= 1;j--){
            dp[i][j] = 1e9;
            for(int k = f[i-1][j];k <= ((j == n) ? n : f[i][j+1]) and k < j;k++){
                if(dp[i][j] > dp[i-1][k] + Sum(k+1, j)){
                    dp[i][j] = dp[i-1][k] + Sum(k+1, j);
                    f[i][j] = k; 
                }
            }
        }
    }
    cout << dp[m][n] / 2 << endl;
    return 0;
}