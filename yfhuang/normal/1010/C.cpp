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

using namespace std;

const int maxn = 1e5 + 5;

int n, k;
int a[maxn];

int gcd(int x, int y){
    if(y == 0)
        return x;
    return gcd(y, x % y);
}

int main(){
    cin >> n >> k;
    int g = k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        g = gcd(g, a[i]);
    }
    printf("%d\n", k / g);
    for(int i = 0;i < k;i += g){
        printf("%d ", i);
    }
    return 0;
}