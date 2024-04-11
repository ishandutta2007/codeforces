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

const int MAXN = 1000005;

int n, m, ans[MAXN][2];
char s[MAXN];

int main(){
    scanf("%s", s);
    n = strlen(s), m = 0;

    int prev_start = -1, prev_end = -1;
    bool x = false;
    
    while(true){
        int i = prev_end + 1;
        while(i < n && s[i] == '0')i++;
        
        if(i >= n)break;
        
        int j = i;
        while(j + 1 < n && s[j + 1] == '1')j++;
        
        if(x && (i - 2 == prev_end)){
            ans[m - 1][0]++;
            
            ans[m++][0] = j;
            ans[m - 1][1] = 1;
            
            x = true;
        }else{
            if(i == j){
                ans[m++][0] = i;
                ans[m - 1][1] = 0;
                x = false;
            }else{
                ans[m++][0] = i - 1;
                ans[m - 1][1] = 0;
                
                ans[m++][0] = j;
                ans[m - 1][1] = 1;
                
                x = true;
            }
        }
        
        
        prev_start = i;
        prev_end = j;
    }
    
    printf("%d\n", m);
    for(int i = 0; i < m; i++){
        if(ans[i][1] == 0)printf("+2^%d\n", (n - 1) - ans[i][0]);
        else printf("-2^%d\n", (n - 1) - ans[i][0]);
    }

    return 0;
}