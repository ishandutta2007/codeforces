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

int n, k, a[100005];
int solve(int x){
    if(x == 0)return 0;
    if(x == 1)return 1;

    if(k == 0){
        if((x % 2) != 0)return 0;
        
        int s = solve(x - 1);
        if(s == 0)return 1;
        if(s == 1)return 2;
        if(s == 2)return 1;
    }else{
        if((x % 2) != 0){
            if(x == 3)return 1;
            else return 0;
        }
        
        int s1 = solve(x - 1), s2 = solve(x / 2);
        if((s1 != 0) && (s2 != 0))return 0;
        if((s1 != 1) && (s2 != 1))return 1;
        return 2;
    }
}
int main(){
    scanf("%d %d", &n, &k);
    k %= 2;

    int X = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        X ^= solve(a[i]);
    }
    
    if(X != 0)printf("Kevin\n");
    else printf("Nicky\n");

    return 0;
}