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
int n, x;
pair <int, int> a[1005];
int main(){
    scanf("%d %d", &x, &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    sort(a, a + n);
    
    int j;
    for(j = 0; j < n; j++){
        if(x <= a[j].first)break;
        
        x += a[j].second;
    }
    if(j == n)printf("YES\n");
    else printf("NO\n");
    return 0;
}