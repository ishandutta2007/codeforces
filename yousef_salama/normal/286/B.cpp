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

const int MAXN = 1000005;

int n, a[2 * MAXN], b[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        a[i] = i;
    
    int st = 0;
    for(int k = 2; k <= n; k++){
        for(int i = 0; i * k < n; i++)
            b[i] = a[st + i * k];
        
        for(int i = 0; i * k < n; i++){
            int j = min((i + 1) * k, n);
            a[st + j] = b[i];
        }
        st++;
    }
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", a[i + st] + 1);
    }
    printf("\n");
    
    return 0;
}