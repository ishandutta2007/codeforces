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

int n, m, v[1005], xi, yi;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    int res = 0;
    while(m--){
        scanf("%d %d", &xi, &yi);
        xi--, yi--;
        
        res += min(v[xi], v[yi]);
    }
    printf("%d\n", res);
    
    return 0;
}