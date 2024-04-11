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

int n, m, d, ns, si, s[100005], C[100005];
bool wrong[1 << 20];
int main(){
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < m; i++){
        scanf("%d", &ns);
        for(int j = 0; j < ns; j++){
            scanf("%d", &si);
            s[si - 1] = i;
        }
    }
    
    int cmask = 0;
    for(int i = 0; i < n; i++){
        if(C[s[i]] == 0)cmask ^= (1 << s[i]);
        C[s[i]]++;
        
        if(i - d >= 0){
            C[s[i - d]]--;
            if(C[s[i - d]] == 0)cmask ^= (1 << s[i - d]);
        }
        
        if(i >= d - 1)wrong[cmask] = true;
    }
    
    for(int i = 0; i < m; i++)
    for(int mask = 0; mask < (1 << m); mask++)
        if((mask & (1 << i)) == 0 && wrong[mask])
            wrong[mask ^ (1 << i)] = true;
    
    int res = 0;
    for(int mask = 0; mask < (1 << m); mask++)
        if(!wrong[mask])res = max(res, __builtin_popcount(mask));
    printf("%d\n", m - res);
    
    return 0;
}