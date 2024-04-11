//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 300005;
const int MAXK = 5005;

int n, k, A[MAXN];
long long dp[2][MAXK];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A + n);
    
    int G1 = n % k, G2 = k - (n % k);
    //cout << G1 << ' ' << G2 << endl;
    for(int a = 0; a <= G1; a++)
    for(int b = 0; b <= G2; b++){
        int i = ((G1 - a) * ((n + k - 1) / k) + (G2 - b) * (n / k));
        //cout << a << ',' << b << ' ' << i << endl;        

        if(i == n)dp[a & 1][b] = 0;
        else{
            dp[a & 1][b] = 1LL << 60;
            if(a > 0)dp[a & 1][b] = min(dp[a & 1][b], dp[(a - 1) & 1][b] + A[i + ((n + k - 1) / k) - 1] - A[i]);
            if(b > 0)dp[a & 1][b] = min(dp[a & 1][b], dp[a & 1][b - 1] + A[i + (n / k) - 1] - A[i]);
        }
    }
    printf("%I64d\n", dp[G1 & 1][G2]);
    
    return 0;
}