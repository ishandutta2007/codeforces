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
#define oo 1 << 25
using namespace std;
int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(abs(a[i] - a[j]) <= d)ans++;
    cout << 2 * ans << endl;
    return 0;
}