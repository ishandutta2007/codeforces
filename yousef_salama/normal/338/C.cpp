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

int n, nprimefactors[10], nprimes;
long long a[10];
vector <long long> tree;

int solve(int i, int nroots, int nleafs){
    if(i == n){
        if(nroots == 1)return n + nleafs - nprimes;
        else return 1 + n + nleafs - nprimes;
    }else{
        int ret = 1 << 30;
        for(int j = 0; j < tree.size(); j++){
            if(tree[j] % a[i] == 0){
                tree[j] /= a[i];
                tree.push_back(a[i]);
                
                if(j == 0)ret = min(ret, solve(i + 1, nroots + 1, nleafs + nprimefactors[i]));
                else ret = min(ret, solve(i + 1, nroots, nleafs));
                
                tree[j] *= a[i];
                tree.pop_back();
            }
        }
        return ret;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%I64d", &a[i]);
    
    sort(a, a + n);
    reverse(a, a + n);
    
    nprimes = 0;
    for(int i = 0; i < n; i++){
        nprimefactors[i] = 0;
        
        long long t = a[i];
        for(long long j = 2; j * j <= t; j++){
            while(t % j == 0){
                t /= j;
                nprimefactors[i]++;
            }
        }
        if(t > 1)nprimefactors[i]++;
        
        if(nprimefactors[i] == 1)nprimes++;
    }
    
    tree.push_back(0);
    printf("%d\n", solve(0, 0, 0));
    
    return 0;
}