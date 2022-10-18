#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN];
long long b[MAXN], dp[MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[a[i] - 1] += a[i];
    }

    for(int i = MAXN - 1; i >= 0; i--){
        dp[i] = b[i];
        if(i + 1 < MAXN)dp[i] = max(dp[i], dp[i + 1]);
        if(i + 2 < MAXN)dp[i] = max(dp[i], b[i] + dp[i + 2]);
    }
    printf("%I64d\n", dp[0]);

    return 0;
}