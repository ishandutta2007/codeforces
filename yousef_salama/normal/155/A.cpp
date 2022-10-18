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
int n, a[1005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);

    int cnt = 0;
    for(int i = 1, mn = a[0], mx = a[0]; i < n; mx = max(mx, a[i]), mn = min(mn, a[i]), i++)
        cnt += a[i] < mn || a[i] > mx;
    printf("%d\n", cnt);
    return 0;
}