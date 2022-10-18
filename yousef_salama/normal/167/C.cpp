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

int t;
long long at, bt;

bool solve(long long a, long long b){
    if(a > b)swap(a, b);

    if(a == 0)return false;
    
    if(solve(b % a, a)){
        b -= b % a;
        b /= a;
        
        if(a % 2 != 0){
            return (b % 2) == 0;
        }else{
            b %= a + 1;
            return (b % 2) == 0;
        }
        
    }else return true;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%I64d %I64d", &at, &bt);
        
        if(solve(at, bt))printf("First\n");
        else printf("Second\n");
    }
    return 0;
}