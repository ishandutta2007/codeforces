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

int n, w[2000005], c[2000005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
        c[w[i]]++;
    }
    
    int X = 0, res = 0;
    for(int i = 0; i < 2000005; i++){
        if(((c[i] + X) % 2) != 0)res++;
        X = (X + c[i]) / 2;
    }
    printf("%d\n", res);
    
    return 0;
}