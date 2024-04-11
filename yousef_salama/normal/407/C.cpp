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
#include <complex>
#include <unordered_map>

using namespace std;

#define MOD 1000000007

int n, m, a[100005], C[100105][105], D[105];
vector < pair <int, int> > add[100005], rem[100005];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for(int i = 0; i <= n + 100; i++)
    for(int j = 0; j <= 100; j++){
        if(j == 0)C[i][j] = 1;
        else if(i == 0)C[i][j] = 0;
        else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    
    while(m--){
        int li, ri, ki;
        scanf("%d %d %d", &li, &ri, &ki);
        li--, ri--;
        
        add[li].push_back(make_pair(ki, ki));
        rem[ri].push_back(make_pair(ki + ri - li, ki));
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < add[i].size(); j++)
        for(int k = 0; k <= add[i][j].second; k++)
            D[k] = (D[k] + C[add[i][j].first][add[i][j].second - k]) % MOD;
        
        if(i > 0)printf(" ");
        printf("%d", (a[i] + D[0]) % MOD);
        
        for(int j = 0; j < rem[i].size(); j++)
        for(int k = 0; k <= rem[i][j].second; k++)
            D[k] = (D[k] - C[rem[i][j].first][rem[i][j].second - k] + MOD) % MOD;
            
        for(int k = 0; k <= 100; k++)
            D[k] = (D[k] + D[k + 1]) % MOD;
    }
    printf("\n");
    
    return 0;
}