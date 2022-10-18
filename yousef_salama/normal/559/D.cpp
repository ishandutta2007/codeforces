#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, x[MAXN], y[MAXN];
double p[MAXN];

int next(int i){return i + 1 < n ? i + 1 : 0;}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);
        
    p[0] = 1.0;
    for(int i = 1; i <= n; i++)
        p[i] = 0.5 * p[i - 1];
    
    double r = 0.0;
    for(int i = 0; i < n; i++){
        for(int j = next(i), k = 0; j != i && k < 60; j = next(j), k++){
            r += (p[k + 2] - p[n]) *
                ((1.0 * x[i] * y[j] - 1.0 * y[i] * x[j]) - __gcd(abs(x[i] - x[j]), abs(y[i] - y[j])));
        }
    }
    printf("%.12f\n", r / (2.0 * (1.0 + p[n] * (-n * (n + 1) / 2 - 1))) + 1);
    
    return 0;
}