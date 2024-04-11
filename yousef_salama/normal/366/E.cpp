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
#define MOD 1000000007
using namespace std;

int n, m, k, s, ai, qi, pqi;
int max1[10], max2[10], max3[10], max4[10];

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &s);
    
    for(int i = 0; i < k; i++){
        max1[i] = -1 << 30;
        max2[i] = -1 << 30;
        max3[i] = -1 << 30;
        max4[i] = -1 << 30;
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        scanf("%d", &ai);
        ai--;
        
        max1[ai] = max(max1[ai], i + j);
        max2[ai] = max(max2[ai], -i + j);
        max3[ai] = max(max3[ai], i - j);
        max4[ai] = max(max4[ai], -i - j);
    }
    
    scanf("%d", &pqi);
    pqi--;
    
    int ans = 0;
    for(int i = 1; i < s; i++){
        scanf("%d", &qi);
        qi--;
        
        ans = max(ans, max1[qi] + max4[pqi]);
        ans = max(ans, max2[qi] + max3[pqi]);
        ans = max(ans, max3[qi] + max2[pqi]);
        ans = max(ans, max4[qi] + max1[pqi]);
    
        pqi = qi;
    }
    
    printf("%d\n", ans);
    
    return 0;
}