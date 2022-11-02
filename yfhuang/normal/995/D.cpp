#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int n, r;

const int maxn = (1 << 18) + 5;
int a[maxn];
typedef long long LL;

int main(){
    cin >> n >> r;
    LL sum = 0;
    for(int i = 0;i < (1 << n);i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%.10lf\n", sum * 1.0 / (1 << n)); 
    for(int i = 1;i <= r;i++){
        int p, val;
        scanf("%d%d", &p, &val);
        sum -= a[p];
        a[p] = val;
        sum += a[p];
        printf("%.10lf\n", sum * 1.0 / (1 << n));
    }
    return 0;
}