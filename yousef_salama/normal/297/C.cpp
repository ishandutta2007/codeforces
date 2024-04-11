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
using namespace std;

int n, a[100005], b[100005];
pair <int, int> s[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i].first);
        s[i].second = i;
    }
    sort(s, s + n);
    
    int i;
    for(i = 0; i < ((n + 2) / 3); i++){
        a[s[i].second] = i;
        b[s[i].second] = s[i].first - i;
    }
    for(; i < min(n, 2 * ((n + 2) / 3)); i++){
        b[s[i].second] = i;
        a[s[i].second] = s[i].first - i;
    }
    for(; i < n; i++){
        b[s[i].second] = (n - 1) - i;
        a[s[i].second] = s[i].first - ((n - 1) - i);
    }
    
    printf("YES\n");
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");
    
    return 0;
}