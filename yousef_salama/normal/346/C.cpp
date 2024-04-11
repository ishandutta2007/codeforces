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

int n, x[100005], a, b;
int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)scanf("%d", &x[i]);
    sort(x, x + n);
    n = unique(x, x + n) - x;
    
    scanf("%d %d", &a, &b);
   
    int moves = 0;
    while(a > b){
        moves++;
        
        int c = a - 1;
        for(int i = 0; i < n; i++)
            if((a - a % x[i]) < c && (a - a % x[i]) >= b)c = a - a % x[i];
        a = c;
    
        while(n > 0 && (a - a % x[n - 1]) < b)
            n--;
    }
    printf("%d\n", moves);
    
    return 0;
}