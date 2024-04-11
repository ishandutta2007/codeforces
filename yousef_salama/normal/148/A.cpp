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
#define MOD 1000000007
using namespace std;
int k, l, m, n, d, ans = 0;
int main(){
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    for(int i = 1; i <= d; i++)
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            ans++;
    printf("%d\n", ans);
    return 0;
}