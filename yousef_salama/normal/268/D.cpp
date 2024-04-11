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
using namespace std;

const int MOD = 1000000009;

int n, h, C[2][35][35][35][2];
int main(){
    scanf("%d %d", &n, &h);
    
    C[0][0][0][0][1] = 1;
    for(int height = 0; height < n; height++)
    for(int other1 = 0; other1 <= h; other1++)
    for(int other2 = 0; other2 <= h; other2++)
    for(int other3 = 0; other3 <= h; other3++)
    for(int last_ok = 0; last_ok <= 1; last_ok++){
        int cur = C[height & 1][other1][other2][other3][last_ok], other0 = last_ok == 0 ? h : 0;
        
        C[(height + 1) & 1][min(other1 + 1, h)][min(other2 + 1, h)][min(other3 + 1, h)][last_ok] += cur;
        C[(height + 1) & 1][min(other1 + 1, h)][min(other2 + 1, h)][min(other3 + 1, h)][last_ok] %= MOD;
    
        C[(height + 1) & 1][min(other0 + 1, h)][min(other2 + 1, h)][min(other3 + 1, h)][other1 < h] += cur;
        C[(height + 1) & 1][min(other0 + 1, h)][min(other2 + 1, h)][min(other3 + 1, h)][other1 < h] %= MOD;
        
        C[(height + 1) & 1][min(other0 + 1, h)][min(other1 + 1, h)][min(other3 + 1, h)][other2 < h] += cur;
        C[(height + 1) & 1][min(other0 + 1, h)][min(other1 + 1, h)][min(other3 + 1, h)][other2 < h] %= MOD;
        
        C[(height + 1) & 1][min(other0 + 1, h)][min(other1 + 1, h)][min(other2 + 1, h)][other3 < h] += cur;
        C[(height + 1) & 1][min(other0 + 1, h)][min(other1 + 1, h)][min(other2 + 1, h)][other3 < h] %= MOD;
        
        C[height & 1][other1][other2][other3][last_ok] = 0;
    }
    
    int res = 0;
    for(int other1 = 0; other1 <= h; other1++)
    for(int other2 = 0; other2 <= h; other2++)
    for(int other3 = 0; other3 <= h; other3++)
    for(int last_ok = 0; last_ok <= 1; last_ok++)
        if(other1 < h || other2 < h || other3 < h || last_ok){
            res += C[n & 1][other1][other2][other3][last_ok];
            res %= MOD;
        }
    
    printf("%d\n", res);
    return 0;
}