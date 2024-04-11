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
#include <cstring>
#include <sstream>
using namespace std;
int n, x, a[100005], b[100005];
int main(){
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    
    sort(a, a + n);
    sort(b, b + n);
    
    int ans = 0;
    for(int i = n - 1, j = 0; i >= 0; i--){
        while(j < n && (a[i] + b[j] < x))j++;
        
        if(j < n)ans++, j++;
    }
    printf("1 %d\n", ans);
    return 0;
}