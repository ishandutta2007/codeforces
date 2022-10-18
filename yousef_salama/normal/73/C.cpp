#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int M, N, K, c, cost[27][27], dp[105][105][27];
char a, b, s[105];
int main(){
    scanf("%s %d", &s, &K);
    M = strlen(s);
    scanf("%d", &N);
    while(N--){
        cin >> a >> b >> c;
        cost[a - 'a'][b - 'a'] = c;
    }
    for(int idx = M - 1; idx >= 0; idx--)
        for(int rem = 0; rem <= K; rem++)
            for(int per = 0; per <= 26; per++){
                dp[idx][rem][per] = dp[idx + 1][rem][s[idx] - 'a'] + cost[per][s[idx] - 'a'];
                for(int cur = 0; cur < 26; cur++)if(cur != s[idx] - 'a' && rem > 0)
                    dp[idx][rem][per] = max(dp[idx][rem][per],
                            dp[idx + 1][rem - 1][cur] + cost[per][cur]);
            }
    printf("%d\n", dp[0][K][26]);
    return 0;
}