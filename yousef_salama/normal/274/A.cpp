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

int n, k, sz, ai;
set <long long> s, vis;

void dfs(int i){
    if(vis.count(i))return;
    vis.insert(i);
    sz++;
    
    if(s.count(((long long)i) * k)){
        dfs(i * k);
    }
    if(i % k == 0){
        if(s.count(i / k)){
            dfs(i / k);
        }
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &ai);
        s.insert(ai);
    }
    
    int ans = 0;
    for(set <long long> :: iterator i = s.begin(); i != s.end(); i++){
        if(!vis.count(*i)){
            sz = 0;
            dfs(*i);
            ans += (sz + 1) / 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}