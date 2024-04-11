#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MOD = 1000000009;

struct matrix{
    long long a[3][3];
} T[MAXN];
matrix operator *(matrix a, matrix b){
    matrix c;
    memset(c.a, 0, sizeof c.a);
    
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
    for(int k = 0; k < 3; k++)
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
    return c;
}

long long tree[4 * MAXN], fib[4 * MAXN][2];
void push(int i, int L, int R){
    tree[i] = (tree[i] + 
        T[R - L + 1].a[0][2] * fib[i][0] + T[R - L + 1].a[1][2] * fib[i][1]) % MOD;
    
    if(2 * i < 4 * MAXN){
        fib[2 * i][0] = (fib[2 * i][0] + fib[i][0]) % MOD;
        fib[2 * i][1] = (fib[2 * i][1] + fib[i][1]) % MOD;
    }
    if(2 * i + 1 < 4 * MAXN){
        int mid = (L + R) / 2;
        
        long long nf = T[mid - L + 1].a[0][1] * fib[i][0] + T[mid - L + 1].a[1][1] * fib[i][1];
        long long nfp = T[mid - L + 1].a[0][0] * fib[i][0] + T[mid - L + 1].a[1][0] * fib[i][1];
        
        fib[2 * i + 1][0] = (fib[2 * i + 1][0] + nfp) % MOD;
        fib[2 * i + 1][1] = (fib[2 * i + 1][1] + nf) % MOD;
    }
    
    fib[i][0] = 0;
    fib[i][1] = 0;
}
void update(int i, int L, int R, int p, int q, int s){
    push(i, L, R);
    
    if(q < L || R < p)return;
    
    if(p <= L && R <= q){
        long long f = T[L - s].a[1][1];
        long long fp = T[L - s].a[1][0];
        
        fib[i][0] = (fib[i][0] + fp) % MOD;
        fib[i][1] = (fib[i][1] + f) % MOD;
        
        push(i, L, R);
    }else{
        int mid = (L + R) / 2;
        
        update(2 * i, L, mid, p, q, s);
        update(2 * i + 1, mid + 1, R, p, q, s);
        
        tree[i] = (tree[2 * i] + tree[2 * i + 1]) % MOD;
    }
}
long long sum(int i, int L, int R, int p, int q){
    push(i, L, R);
    
    if(q < L || R < p)return 0;
    
    if(p <= L && R <= q)return tree[i];
    else{
        int mid = (L + R) / 2;
        return (sum(2 * i, L, mid, p, q) + sum(2 * i + 1, mid + 1, R, p, q)) % MOD;
    }
}

int n, m, ai, type, li, ri;
long long s[MAXN];

int main(){
    scanf("%d %d", &n, &m);
    
    s[0] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &ai);
        s[i + 1] = (s[i] + ai) % MOD;
    }
    
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        T[0].a[i][j] = (i == j);
    
    T[1].a[0][0] = 0; T[1].a[0][1] = 1; T[1].a[0][2] = 0;
    T[1].a[1][0] = 1; T[1].a[1][1] = 1; T[1].a[1][2] = 1;
    T[1].a[2][0] = 0; T[1].a[2][1] = 0; T[1].a[2][2] = 1;
    
    for(int i = 2; i <= n; i++)T[i] = T[1] * T[i - 1];
    
    while(m--){
        scanf("%d %d %d", &type, &li, &ri);
        li--, ri--;
        
        if(type == 1){
            update(1, 0, n - 1, li, ri, li);
        }else printf("%I64d\n", (s[ri + 1] - s[li] + sum(1, 0, n - 1, li, ri) + MOD) % MOD);
    }
    
    return 0;
}