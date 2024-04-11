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
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int m, k, d[1005], s[1005];
int main(){
    scanf("%d %d", &m, &k);
    for(int i = 0; i < m; i++)
        scanf("%d", &d[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &s[i]);
        
    int res = 0;
    for(int i = 0; i < m; i++)
        res += d[i];
        
    int x = 0, y = 0, f = s[0];
    while(true){
        if(f >= d[y]){
            f -= d[y];
            
            y++;
            if(y == m + 1)break;
            
            f += s[y];
            if(s[y] > s[x])x = y;
        }else{
            res += k;
            f += s[x];
        }
    }
    printf("%d\n", res);
    
    return 0;
}