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

char s[100005];
int m, li, ri, nx[100005], ny[100005], nz[100005];
int main(){
    scanf("%s %d", s, &m);
    
    nx[0] = s[0] == 'x';
    for(int i = 1; s[i]; i++)
        nx[i] = nx[i - 1] + (s[i] == 'x');
    ny[0] = s[0] == 'y';
    for(int i = 1; s[i]; i++)
        ny[i] = ny[i - 1] + (s[i] == 'y');
    nz[0] = s[0] == 'z';
    for(int i = 1; s[i]; i++)
        nz[i] = nz[i - 1] + (s[i] == 'z');
    
    while(m--){
        scanf("%d %d", &li, &ri);
        li--, ri--;
        
        int cur_nx = nx[ri] - (li > 0 ? nx[li - 1] : 0);
        int cur_ny = ny[ri] - (li > 0 ? ny[li - 1] : 0);
        int cur_nz = nz[ri] - (li > 0 ? nz[li - 1] : 0);
        
        if(((ri - li + 1) < 3) || 
                (abs(cur_nx - cur_ny) <= 1 && abs(cur_nx - cur_nz) <= 1 && abs(cur_ny - cur_nz) <= 1))printf("YES\n");
        else printf("NO\n");
        
    }
    return 0;
}