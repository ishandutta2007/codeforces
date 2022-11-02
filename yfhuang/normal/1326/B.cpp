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

int n;
const int maxn = 2e5 + 5;

typedef long long LL;

LL b[maxn];
LL a[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &b[i]);
    }
    LL x = 0;
    for(int i = 1;i <= n;i++){
        a[i] = b[i] + x;
        x = max(x, a[i]);
    }
    for(int i = 1;i <= n;i++){
        printf("%lld%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}