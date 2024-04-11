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
#include <cstring>
#include <sstream>
using namespace std;
int N, K, T, t[25], a[25][25], dp[1 << 22], m[25];
pair <int, int> c[25];
char s[200005];
int main(){
    scanf("%d %d %d", &N, &K, &T);
    scanf("%s", &s);
    for(int i = 0; i < K; i++)
        scanf("%d", &t[i]);
    for(int i = 0; i < K; i++)
    for(int j = 0; j < K; j++)
        scanf("%d", &a[i][j]);
    
    memset(m, -1, sizeof m);
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < K; j++)
            c[j] = make_pair(m[j], j);
        sort(c, c + K);

        int msk = 0;
        for(int j = 0; j < K; j++){
            if(c[j].first != -1){
                int x = a[s[i] - 'A'][c[j].second];
                dp[msk] += x;
                dp[msk | (1 << (s[i] - 'A'))] -= x;
                dp[msk | (1 << (c[j].second))] -= x;
                dp[msk | (1 << (s[i] - 'A')) | (1 << (c[j].second))] += x;
                
                msk |= 1 << (c[j].second);
            }
        }
        m[s[i] - 'A'] = i;
    }
    for(int i = 0; i < K; i++)
        dp[1 << i] += t[i];
    for(int i = 0; i < K; i++)
    for(int msk = 0; msk < (1 << K); msk++)
        if(msk & (1 << i))dp[msk] += dp[msk ^ (1 << i)];

    int total = 0;
    for(int i = 0; i < N; i++)
        total |= 1 << (s[i] - 'A');
        
    int cnt = 0;
    for(int i = 0; i < (1 << K); i++){
        if(dp[i] <= T && ((total | i) == total) && (i != total))
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}