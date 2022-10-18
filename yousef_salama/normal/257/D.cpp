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
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MAXN 100005
using namespace std;

int n, a[MAXN], x[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    x[n - 1] = 1;
    int sum = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(sum >= a[i])sum -= a[i];
        else{
            sum = a[i] - sum;
            x[i] = 1;
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        k ^= x[i];

        if(k)printf("+");
        else printf("-");
    }
    printf("\n");
    return 0;
}