#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <ctime>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

int K = 50;
typedef long long LL;
LL x[maxn * 2], y[maxn * 2];
int n;

LL gcd(LL x, LL y){
    return y == 0 ? x : gcd(y, x % y);
}

LL cal(int i, int j){
    return x[i] * y[j] - y[i] * x[j] - abs(gcd(x[i] - x[j], y[i] - y[j]));
}

typedef long double ld;

ld power[maxn];
ld half[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld", &x[i], &y[i]);
        x[i + n] = x[i];
        y[i + n] = y[i];
    }    
    power[0] = 1;
    half[0] = 1;
    for(int i = 1;i <= n;i++){
        power[i] = power[i - 1] * 2.0;
        half[i] = half[i - 1] * 0.5;
    }
    ld ans = 0;
    ld z = power[n] - 1 - n - n * (n - 1) / 2.0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j < i + min(n, K);j++){
            ld now;
            if(n > 50)
                now = half[j - i + 1];
            else{
                now = (power[n - (j - i + 1)] - 1) / z;
            }
            ans += cal(i, j) * now;
        }
    }
    ans /= 2;
    ans += 1;
    printf("%.10Lf\n", ans);
    return 0;
}