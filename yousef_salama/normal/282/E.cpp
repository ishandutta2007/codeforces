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

struct node{
    int cnt;
    node *t[2];
} *root;

void add(long long x, int d){
    node *cur = root;
    
    cur->cnt += d;
    for(int i = 50; i >= 0; i--){
        if(x & (1LL << i)){
            if(cur->t[1] == NULL)
                cur->t[1] = new node();
            cur = cur->t[1];
        }else{
            if(cur->t[0] == NULL)
                cur->t[0] = new node();
            cur = cur->t[0];
        }
        cur->cnt += d;
    }
}
long long solve(long long x){
    node *cur = root;
    
    long long ret = 0;
    for(int i = 50; i >= 0; i--){
        if(x & (1LL << i)){
            if(cur->t[0] == NULL || cur->t[0]->cnt == 0){
                cur = cur->t[1];
            }else{
                cur = cur->t[0];
                ret += 1LL << i;
            }
        }else{
            if(cur->t[1] == NULL || cur->t[1]->cnt == 0){
                cur = cur->t[0];
            }else{
                cur = cur->t[1];
                ret += 1LL << i;
            }
        }
    }
    return ret;
}

int n;
long long a[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    
    root = new node();
    add(0, 1);
    
    long long prefix = 0, suffix = 0;
    for(int i = 0; i < n; i++){
        prefix ^= a[i];
        add(prefix, 1);
    }

    long long ans = solve(0);

    for(int i = n - 1; i >= 0; i--){
        suffix ^= a[i];
        add(prefix, -1);
        prefix ^= a[i];
        
        ans = max(ans, solve(suffix));
    }
    
    printf("%I64d\n", ans);
    return 0;
}