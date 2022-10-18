#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

double tree[MAXN], tree_cnt[MAXN];

void add(double* tree, int u, double v){
    while(u < MAXN){
        tree[u] += v;
        u += u & (-u);
    }
}
double sum(double* tree, int u){
    double r = 0;
    while(u > 0){
        r += tree[u];
        u -= u & (-u);
    }
    return r;
}

int main(){
    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    double res = 0.0;
    for(int k = 1; k <= n; k++)
        res += 0.25 * k * (k - 1) * (n - k + 1);

    for(int i = 0; i < n; i++){
        res -= sum(tree, n + 1 - a[i]) * (n - i);
        res += 0.5 * n * (n + 1) * sum(tree_cnt, n + 1 - a[i]);
        
        add(tree, n + 1 - a[i], i + 1);
        add(tree_cnt, n + 1 - a[i], 1.0);
    }

    printf("%.15f\n", res / (0.5 * n * (n + 1)));

    return 0;
}