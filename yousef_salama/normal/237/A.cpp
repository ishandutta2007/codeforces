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
using namespace std;
int n;
pair <int, int> v[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v, v + n);
    int Max = 1, ans = 1;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i - 1])ans++;
        else ans = 1;
        
        Max = max(Max, ans);
    }
    printf("%d\n", Max);
    return 0;
}