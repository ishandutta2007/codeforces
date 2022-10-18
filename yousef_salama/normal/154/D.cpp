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

int x1, x2, a, b;
int main(){
    scanf("%d %d %d %d", &x1, &x2, &a, &b);
    
    int d = x2 - x1;
    if(a <= 0 && 0 <= b){
        if(a <= d && d <= b){
            printf("FIRST\n");
            printf("%d\n", x2);
        }else printf("DRAW\n");
    }else{
        bool neg = false;
        if(a < 0){
            a = -a;
            b = -b;
            swap(a, b);
            
            d = -d;
            
            neg = true;
        }
        
        if(d < 0)printf("DRAW\n");
        else{
            d %= a + b;
            if(d == 0)printf("SECOND\n");
            else if(a <= d && d <= b){
                printf("FIRST\n");

                if(!neg)printf("%d\n", x1 + d);
                else printf("%d\n", x1 - d);
            }else printf("DRAW\n");
        }
    }
    
    return 0;
}