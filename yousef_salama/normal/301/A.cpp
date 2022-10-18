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

int n, a[205];
int main(){
    scanf("%d", &n);
    
    int c_neg = 0, c_zero = 0;
    for(int i = 0; i < (2 * n - 1); i++){
        scanf("%d", &a[i]);

        if(a[i] == 0)c_zero++;
        if(a[i] < 0)c_neg++;
    }
    if(c_zero > 0){
        int sum = 0;
        for(int i = 0; i < (2 * n - 1); i++)sum += abs(a[i]);
        
        printf("%d\n", sum);
    }else{
        int sum = 0, mn = 1 << 30;
        for(int i = 0; i < (2 * n - 1); i++){
            sum += abs(a[i]);
            mn = min(mn, abs(a[i]));
        }

        if((n % 2) != 0)printf("%d\n", sum);
        else{
            if((c_neg % 2) != 0)printf("%d\n", sum - 2 * mn);
            else printf("%d\n", sum);
        }
    }

    return 0;
}