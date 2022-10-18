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

int n, k, a[105];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    sort(a, a + n);
    reverse(a, a + n);
    
    printf("%d\n", a[k - 1]);
    
    return 0;
    
}