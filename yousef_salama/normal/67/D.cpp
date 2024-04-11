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
#define MAXN 1000005
using namespace std;
int N, a[MAXN], b[MAXN], dp[MAXN], tree[MAXN];
map <int, int> mp;
void update(int i, int v){
    while(i < MAXN){
        tree[i] = max(tree[i], v);
        i += i & (-i);
    }
}
int query(int i){
    int ans = 0;
    while(i > 0){
        ans = max(ans, tree[i]);
        i -= i & (-i);
    }
    return ans;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < N; i++){
        scanf("%d", &b[i]);
        mp[b[i]] = i + 1;
    }
    for(int i = 0; i < N; i++)
        a[i] = mp[a[i]];
    reverse(a, a + N);
    dp[0] = 1;
    update(a[0], dp[0]);
    for(int i = 1; i < N; i++){
        dp[i] = 1 + query(a[i]);
        update(a[i], dp[i]);
    }
    int opt = 0;
    for(int i = 0; i < N; i++)
        opt = max(opt, dp[i]);
    printf("%d\n", opt);
    return 0;
}