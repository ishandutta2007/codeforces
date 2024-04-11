#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXM = 200005;
const int DIGITS = 10;

//int val[DIGITS][MAXM], mul[DIGITS][MAXM];
int len[DIGITS][MAXM];

int main(){
    for(int i = 0; i < MAXM; i++)
    for(int d = 0; d <= 9; d++){
        if(d + i <= 9){
            //val[d][i] = d + i;
            //mul[d][i] = 10;

            len[d][i] = 1;
        }else{
            //val[d][i] = (1LL * val[1][i - (10 - d)] * mul[0][i - (10 - d)] + val[0][i - (10 - d)]) % MOD;
            //mul[d][i] = 1LL * mul[1][i - (10 - d)] * mul[0][i - (10 - d)] % MOD;
        
            len[d][i] = (len[1][i - (10 - d)] + len[0][i - (10 - d)]) % MOD;
        }
    }

    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        /*
        long long res = 0, curmul = 1;
        while(n > 0){
            res = (res + val[n % 10][m] * curmul) % MOD;
            curmul = curmul * mul[n % 10][m] % MOD;
            n /= 10;
        }
        
        printf("%lld\n", res);
        */

        int total_len = 0;
        while(n > 0){
            total_len = (total_len + len[n % 10][m]) % MOD;
            n /= 10;
        }
        printf("%d\n", total_len);
    }

    return 0;
}