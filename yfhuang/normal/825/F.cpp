#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>

using namespace std;


const int maxn = 8005;


int f[maxn][maxn];
char T[maxn],P[maxn];
int dp[maxn];
int n;
void getNext(int start){
    f[start][0] = f[start][1] = 0;
    int j = 0;
    int len = n - start + 1;
    for(int i = 1;i <= len;i++) P[i] = T[start + i - 1];
    for(int i = 2;i <= len;i++){
        while(j > 0 && P[i] != P[j + 1]) j = f[start][j];
        if(P[i] == P[j + 1]) j++;
        f[start][i] = j;
    }
}
int length(int a){
    int ans = 0;
    while(a > 0){
        ans++;
        a /= 10;
    }
    return ans;
}

int main(){
    scanf("%s",T + 1);
    n = strlen(T + 1);
    dp[0] = 0;
    fill(dp + 1,dp + 1 + n,0x3f3f3f3f);
    for(int i = 1;i <= n;i++) getNext(i);
    //cout << f[1][5] << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < i;j++){
            int sLen = i - j;
            int period = sLen - f[j + 1][sLen];
            if(sLen % period == 0){
                dp[i] = min(dp[i],dp[j] + length(sLen / period) + period);
            }else{
                dp[i] = min(dp[i],dp[j] + sLen + 1);
            }
        }
        //cout << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}