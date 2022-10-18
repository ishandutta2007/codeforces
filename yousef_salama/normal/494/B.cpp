#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

char s[MAXN], t[MAXN];
int N, M, p[MAXN], match[MAXN], dp[MAXN], sum[MAXN];

int main(){
    scanf("%s %s", s, t);
    
    N = strlen(s);
    M = strlen(t);
    
    t[M++] = '#';
    
    p[0] = p[1] = 0;
    for(int i = 2; i <= M; i++){
        int j = p[i - 1];
        while(true){
            if(t[i - 1] == t[j]){
                p[i] = j + 1;
                break;
            }
            if(j == 0){
                p[i] = 0;
                break;
            }
            j = p[j];
        }
    }
    
    for(int i = 0, j = 0; i < N; i++){
        while(s[i] != t[j]){
            if(j == 0)break;
            else j = p[j];
        }
        if(s[i] == t[j])j++;
        if(j == M - 1)match[i] = true;
    }
    
    int j = -1;
    for(int i = 0; i <= N; i++){
        if(i == 0)sum[i] = dp[i] = 1;
        else{
            dp[i] = dp[i - 1];
            if(match[i - 1])j = i;
            
            if(j != -1)dp[i] = (dp[i] + sum[j - (M - 1)]) % MOD;
        
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
        }
    }
    printf("%d\n", (dp[N] - 1 + MOD) % MOD);
    
    return 0;
}