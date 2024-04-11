#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

long long tree_cnt[MAXN], tree_sum[MAXN];

void add(long long* tree, int u, long long val){
    while(u < MAXN){
        tree[u] += val;
        u += u & (-u);
    }
}
long long query(long long* tree, int u){
    long long r = 0;
    while(u > 0){
        r += tree[u];
        u -= u & (-u);
    }
    return r;
}

int main(){
    int n;
    scanf("%d", &n);

    long long sum = 0;
    long long sum2 = 0;

    for(int i = 0; i < n; i++){
        int p;
        scanf("%d", &p);

        sum += p;

        sum2 += query(tree_sum, p);
        for(int x = p; x < MAXN; x += p){
            sum2 += 1LL * p * (i - query(tree_cnt, x - 1));
            add(tree_sum, x, p);
        }

        add(tree_cnt, p, 1);

        //cout << sum << ' ' << sum2 << endl;
        if(i > 0)printf(" ");
        printf("%lld", i * sum - sum2);
    }
    printf("\n");

    return 0;
}