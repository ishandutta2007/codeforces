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
using namespace std;
int n, m, r[105][30005];
char s[105][30005];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        for(int j = m; j < 2 * m; j++)
            s[i][j] = s[i][j - m];
        for(int j = 2 * m; j < 3 * m; j++)
            s[i][j] = s[i][j - m];
    }
    m *= 3;
    memset(r, -1, sizeof r);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; ){
            if(s[i][j] == '1'){
                r[i][j] = 0;
                int k = j + 1;
                
                while(k < m && s[i][k] == '0'){
                    if(r[i][k] == -1)r[i][k] = k - j;
                    else r[i][k] = min(r[i][k], k - j);
                    
                    k++;
                }
                j = k;
            }else j++;
        }
        for(int j = m - 1; j >= 0; ){
            if(s[i][j] == '1'){
                r[i][j] = 0;
                int k = j - 1;
                
                while(k >= 0 && s[i][k] == '0'){
                    if(r[i][k] == -1)r[i][k] = j - k;
                    else r[i][k] = min(r[i][k], j - k);
                    
                    k--;
                }
                j = k;
            }else j--;
        }
    }
    int ans = -1;
    for(int j = 0; j < m; j++){
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(r[i][j] == -1)cur = -1;
            else{
                if(cur != -1)cur += r[i][j];
            }
        }
        if(ans == -1)ans = cur;
        else ans = min(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}