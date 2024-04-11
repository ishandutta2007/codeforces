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

int n, m, a[200005], b[200005], qi, ki, xi;

int next[200005];
int find_next(int i){
    if(next[i] == i)return i;
    return next[i] = find_next(next[i]);
}
void remove(int i){
    next[i] = i + 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    scanf("%d", &m);
    
    for(int i = 0; i <= n; i++)next[i] = i;
    
    while(m--){
        scanf("%d", &qi);
        if(qi == 1){
            scanf("%d %d", &ki, &xi);
            ki--;
            
            ki = find_next(ki);
            while(ki < n && xi > 0){
                if(b[ki] > xi){
                    b[ki] -= xi;
                    break;
                }
                
                xi -= b[ki];
                b[ki] = 0;
                
                remove(ki);
                ki = find_next(ki);
            }
        }else{
            scanf("%d", &ki);
            ki--;
            
            printf("%d\n", a[ki] - b[ki]);
        }
    }
    
    
    return 0;
}