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

int n, k, c[1000005], p[1000005];
int main(){
    memset(p, -1, sizeof p);
    for(int i = 2; i <= 1000000; i++){
        if(p[i] != -1)continue;
        
        for(int j = i; j <= 1000000; j += i)
            if(p[j] == -1)p[j] = i;
    }

    scanf("%d %d", &n, &k);
    
    map <int, int> mf;
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
        
        map <int, int> pf;
        while(p[c[i]] != -1){
            pf[p[c[i]]]++;
            mf[p[c[i]]] = max(mf[p[c[i]]], pf[p[c[i]]]);
            
            c[i] /= p[c[i]];
        }
    }
    
    map <int, int> pf;
    while(p[k] != -1){
        pf[p[k]]++;
        if(mf[p[k]] < pf[p[k]]){
            printf("No\n");
            return 0;
        }
        k /= p[k];
    }
    printf("Yes\n");
    
    return 0;
}