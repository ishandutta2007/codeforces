#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2005;

long long P[2 * MAXN][2 * MAXN], dp[2][MAXN][11], dp_neg[2][MAXN][11];

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < 2 * MAXN; i++)
    for(int j = 0; j <= i; j++){
        if(j == 0){
            P[i][j] = 1;
        }else{
            P[i][j] = P[i - 1][j - 1] * i % MOD;
        }
    }

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> pos, neg;

        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            int r = a % 11;
            
            int digits = 0;
            while(a > 0){
                a /= 10;
                digits++;
            }

            if(digits % 2 == 0){
                pos.push_back(r);
            }else{
                neg.push_back(r);
            }
        }

        for(int i = 0; i <= (int)neg.size(); i++)
        for(int j = 0; j <= i; j++)
        for(int r = 0; r < 11; r++){
            if(i == 0){
                dp_neg[i & 1][j][r] = (r == 0);
            }else{
                dp_neg[i & 1][j][r] = 0;
                if(j < i){
                    dp_neg[i & 1][j][r] = (i - j) * dp_neg[(i & 1) ^ 1][j][(r + neg[i - 1]) % 11] % MOD;
                }
                if(j > 0){
                    dp_neg[i & 1][j][r] = (dp_neg[i & 1][j][r] + j * dp_neg[(i & 1) ^ 1][j - 1][(r - neg[i - 1] + 11) % 11]) % MOD;
                }
            }
        }

        for(int i = (int)pos.size(); i >= 0; i--)
        for(int j = 0; j <= (int)pos.size(); j++)
        for(int r = 0; r < 11; r++){
            if(i == (int)pos.size()){
                long long cnt_neg = (neg.empty() ? j == 0 : P[j + ((int)neg.size() + 1) / 2 - 1][j]);
                long long cnt_pos = P[(int)pos.size() - j + (int)neg.size() / 2][(int)pos.size() - j];
                dp[i & 1][j][r] = cnt_neg * cnt_pos % MOD * dp_neg[((int)neg.size()) & 1][(int)neg.size() / 2][r] % MOD;
            }else{
                dp[i & 1][j][r] = dp[(i & 1) ^ 1][j + 1][(r - pos[i] + 11) % 11] + dp[(i & 1) ^ 1][j][(r + pos[i]) % 11];
                if(dp[i & 1][j][r] >= MOD)dp[i & 1][j][r] -= MOD;
            }
        }

        printf("%lld\n", dp[0][0][0]);
    }
    return 0;
}