#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, m, X[MAXN], a, b, c;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)scanf("%d", &X[i]);
    
    double r = 0.0;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        
        r = max(r, 1.0 * (X[a] + X[b]) / c);
    }
    printf("%.15f\n", r);
    
    return 0;
}