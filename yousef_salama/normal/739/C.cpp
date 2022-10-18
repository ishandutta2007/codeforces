#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, a[MAXN], q, li, ri, di;
long long d[MAXN];

struct node{
    int max, suf, pref, suf_pos, pref_neg, pos, neg, zero, size;
} tree[4 * MAXN];

node new_node(long long ai){
    node r;
    if(ai == 0){
        r.size = 1;
        
        r.max = r.suf = r.pref = r.suf_pos = r.pref_neg = r.pos = r.neg = 0;
        
        r.zero = 1;
    }else if(ai < 0){
        r.size = 1;
        
        r.max = r.suf = r.pref = r.pref_neg = 1;
        r.suf_pos = 0;
        
        r.neg = 1;
        r.pos = 0;
        r.zero = 0;
    }else{
        r.size = 1;
        
        r.max = r.suf = r.pref = r.suf_pos = 1;
        r.pref_neg = 0;
        
        r.neg = 0;
        r.pos = 1;
        r.zero = 0;
    }
    return r;
}

node merge(node a, node b){
    node c;
    
    c.max = max(a.max, b.max);
    c.max = max(c.max, a.suf + b.pref_neg);
    c.max = max(c.max, a.suf_pos + b.pref);
    
    c.pos = a.pos + b.pos;
    c.neg = a.neg + b.neg;
    c.zero = a.zero + b.zero;
    c.size = a.size + b.size;
    
    c.pref = a.pref;
    if(a.pref == a.size)c.pref = a.size + b.pref_neg;
    if(a.pos == a.size)c.pref = max(c.pref, a.size + b.pref);
    
    c.suf = b.suf;
    if(b.suf == b.size)c.suf = b.size + a.suf_pos;
    if(b.neg == b.size)c.suf = max(c.suf, b.size + a.suf);
    
    c.pref_neg = a.pref_neg;
    if(a.neg == a.size)c.pref_neg = a.size + b.pref_neg;
    
    c.suf_pos = b.suf_pos;
    if(b.pos == b.size)c.suf_pos = b.size + a.suf_pos;
    
    return c;
}

void update(int i, int L, int R, int k, int v){
    if((k < L) || (R < k))return;
    if(L == R){
        tree[i] = new_node(d[k] + v);
        d[k] += v;
        
        return;
    }
    
    int mid = (L + R) / 2;
    update(2 * i, L, mid, k, v);
    update(2 * i + 1, mid + 1, R, k, v);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for(int i = 1; i < n; i++)
        update(1, 1, n - 1, i, a[i] - a[i - 1]);

    
    scanf("%d", &q);
    while(q--){
        scanf("%d %d %d", &li, &ri, &di);
        li--, ri--;
        
        if(li > 0){
            update(1, 1, n - 1, li, di);
        }
        if(ri + 1 < n){
            update(1, 1, n - 1, ri + 1, -di);
        }

        printf("%d\n", tree[1].max + 1);
    }
        
    return 0;
}