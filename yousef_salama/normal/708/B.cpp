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
#include <unordered_map>

using namespace std;

long long a00, a01, a10, a11;
char s[1000005];

int main(){
    scanf("%I64d %I64d %I64d %I64d", &a00, &a01, &a10, &a11);
    
    
    int zeros = 1, ones = 1;
    
    while(zeros * (zeros - 1) / 2 < a00)
        zeros++;
        
    while(ones * (ones - 1) / 2 < a11)
        ones++;
        
        
    if((zeros * (zeros - 1) / 2 != a00) || (ones * (ones - 1) / 2 != a11)){
        printf("Impossible\n");
        return 0;
    }
    
    if(a00 == 0){
        if((a01 == 0) && (a10 == 0)){
            for(int i = 0; i < ones; i++)
                printf("1");
            printf("\n");
            
            return 0;
        }
    }
    if(a11 == 0){
        if((a01 == 0) && (a10 == 0)){
            for(int i = 0; i < zeros; i++)
                printf("0");
            printf("\n");
            
            return 0;
        }
    }
    
    if(zeros + ones > 1000000){
        printf("Impossible\n");
        return 0;
    }
    
    long long d = (long long)zeros * ones;

    if(a01 + a10 != d){
        printf("Impossible\n");
        return 0;
    }
    
    d -= a01;
    
    int N = zeros + ones;
    for(int i = 0; i < zeros; i++)
        s[i] = '0';
    for(int i = zeros; i < N; i++)
        s[i] = '1';
    s[N] = 0;
    
    
    int p = -1;
    
    for(int i = zeros; i < N; i++){
        if(i - (p + 1) >= d){
            //cout << 1 << ' ' << i << ' ' << (i - d) << endl;
            swap(s[i], s[i - d]);
            break;
        }else{
            //cout << 0 << ' ' << i << ' ' << (i - (p + 1)) << endl;
            swap(s[i], s[p + 1]);
            
            d -= i - (p + 1);
            p++;
        }
        
    }
    printf("%s\n", s);
    
    return 0;
}