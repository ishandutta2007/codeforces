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
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int n;

long long ri[100005], hi[100005], vi[100005];
long long tree[100005], dp[100005];

void add(int i, long long v){
    i += 2;
    
    while(i < 100005){
        tree[i] = max(tree[i], v);
        i += i & (-i);
    }
}
long long findr(int i){
    i += 2;
    
    long long r = 0;
    while(i > 0){
        r = max(r, tree[i]);
        i -= i & (-i);
    }
    return r;
}

int main(){
    scanf("%d", &n);
    
    vector <long long> vx;
    for(int i = 0; i < n; i++){
        scanf("%I64d %I64d", &ri[i], &hi[i]);
        
        vi[i] = ri[i] * ri[i] * hi[i];
        vx.push_back(vi[i]);
    }
    sort(vx.begin(), vx.end());
    
    long long r = 0;
    for(int i = 0; i < n; i++){
        int v_ = lower_bound(vx.begin(), vx.end(), vi[i]) - vx.begin();
        dp[i] = vi[i] + findr(v_ - 1);
        
        add(v_, dp[i]);
        r = max(r, dp[i]);
    }
    printf("%.9f\n", 2 * r * acos(0));
    
    return 0;
}