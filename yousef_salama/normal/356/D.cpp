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

const int MAXN = 70005;
const int MAXS = 305;

int n, s, d, a[MAXN];
vector < pair <int, int> > b;

bitset <MAXN> prev, current, added;
int f[MAXN];

bool used[MAXN];
int child[MAXN];

int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b.push_back(make_pair(a[i], i));
    }
    sort(b.rbegin(), b.rend());
    
    if(s < b[0].first){
        printf("-1\n");
        return 0;
    }
    s -= b[0].first;
    
    memset(f, -1, sizeof f);
    
    prev[0] = 1;
    f[0] = 0;
    
    for(int i = 1; i < n; i++){
        current = prev | (prev << b[i].first);
        added = current & ~prev;
        
        while(added.any()){
            int j = added._Find_first();
            f[j] = i;
            
            added.reset(j);
        }
        
        prev = current;
    }
    
    if(f[s] == -1){
        printf("-1\n");
        return 0;
    }
    
    while(s > 0){
        used[f[s]] = true;
        s -= b[f[s]].first;
    }
    
    memset(child, -1, sizeof child);
    
    int prev = 0;
    for(int i = 1; i < n; i++){
        if(!used[i]){
            child[b[prev].second] = b[i].second;
            prev = i;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(child[i] == -1){
            printf("%d 0\n", a[i]);
        }else{
            printf("%d 1 %d\n", a[i] - a[child[i]], child[i] + 1);
        }
    }
    
    return 0;
}