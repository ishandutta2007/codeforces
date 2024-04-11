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
char s[100005], ans[100005];
int n;
void go(int m){
    for(int i = 0; i < m / 2; i++)
        ans[i] = '4';
    for(int i = m / 2; i < m; i++)
        ans[i] = '7';
    ans[m] = 0;
}
bool solve(int i, int c4, bool greater){
    if(i == n)return c4 == 0;
    
    if(greater){
        if(c4){
            ans[i] = '4';
            return solve(i + 1, c4 - 1, true);
        }else{
            ans[i] = '7';
            return solve(i + 1, c4, true);
        }
    }else{
        if(s[i] < '4'){
            if(c4){
                ans[i] = '4';
                return solve(i + 1, c4 - 1, true);
            }else{
                ans[i] = '7';
                return solve(i + 1, c4, true);
            }
        }else if(s[i] == '4'){
            if(c4){
                ans[i] = '4';
                if(solve(i + 1, c4 - 1, false))return true;
            }
            ans[i] = '7';
            return solve(i + 1, c4, true);
        }else if(s[i] <= '7'){
            ans[i] = '7';
            return solve(i + 1, c4, s[i] < '7');
        }
        return false;
    }
}
int main(){
    scanf("%s", s);
    n = strlen(s);
    
    if(n % 2 == 0){
        if(!solve(0, n / 2, false))
            go(n + 2);
        else ans[n] = 0; 
    }else{
        go(n + 1);
    }
    
    printf("%s\n", ans);
    return 0;
}