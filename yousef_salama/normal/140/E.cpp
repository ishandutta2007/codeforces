#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MAXN 1000005
#define MAXL 5005
using namespace std;
long long p, n, m, L[MAXN], layer[MAXL][MAXL], dp[2][MAXL], fact[MAXL], coff[MAXL];
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
        cin >> L[i];
    
    layer[0][0] = 1;
    for(int i = 1; i < MAXL; i++)
    for(int j = 1; j < MAXL; j++){
        layer[i][j] = (layer[i - 1][j] * (j - 1)) % p;
        if(j)layer[i][j] = (layer[i][j] + layer[i - 1][j - 1]) % p;
    }
    fact[0] = 1;
    for(int i = 1; i < MAXL; i++)
        fact[i] = (fact[i - 1] * i) % p;
    
    coff[0] = 1;
    for(int i = 1; i < MAXL; i++)
        coff[i] = (coff[i - 1] * (m - i + 1)) % p;

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        memset(dp[i & 1], 0, sizeof dp[i & 1]);
        
        long long x = 0;
        for(int j = 0; j <= L[i - 1]; j++)
            x = (x + dp[(i & 1) ^ 1][j]) % p;
        
        for(int j = 1; j <= L[i]; j++){
            long long &ret = dp[i & 1][j];
            ret = (layer[L[i]][j] * coff[j]) % p;
            ret = (ret * x) % p;
            
            long long t = (dp[(i & 1) ^ 1][j] * fact[j]) % p;
            t = (t * layer[L[i]][j]) % p;
            ret = (ret - t + p) % p;
        }
    }
    long long res = 0;
    for(int j = 0; j <= L[n]; j++)
        res = (res + dp[n & 1][j]) % p;
    cout << res << endl;
    return 0;
}