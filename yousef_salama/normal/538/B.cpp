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

char s[10];
int N;
int main(){
    scanf("%s", s);
    N = strlen(s);
    
    int k = 0;
    for(int i = 0; i < N; i++)
        k = max(k, s[i] - '0');
    
    printf("%d\n", k);
    for(int i = 0; i < k; i++){
        if(i > 0)printf(" ");
        
        int p = 1, o = 0;
        for(int j = 0; j < N; j++){
            int d = N - j - 1;
            if((s[d] - '0') > i)o += p;
            
            p *= 10;
        }
        printf("%d", o);
    }
    printf("\n");
    
    return 0;
}