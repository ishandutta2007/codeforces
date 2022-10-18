#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

long long tree[4 * MAXN], flag[4 * MAXN];
void push(int i, int L, int R){
    tree[i] += (R - L + 1) * flag[i];
    
    if(2 * i < 4 * MAXN)flag[2 * i] += flag[i];
    if(2 * i + 1 < 4 * MAXN)flag[2 * i + 1] += flag[i];
    
    flag[i] = 0;
}
void add(int i, int L, int R, int p, int q, int v){
    push(i, L, R);
    
    if(q < L || R < p)return;
    
    if(p <= L && R <= q){
        flag[i] += v;
        push(i, L, R);
    }else{
        int mid = (L + R) / 2;
        
        add(2 * i, L, mid, p, q, v);
        add(2 * i + 1, mid + 1, R, p, q, v);
        
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}
long long sum(int i, int L, int R, int p, int q){
    push(i, L, R);
    
    if(q < L || R < p)return 0;
    
    if(p <= L && R <= q)return tree[i];
    else{
        int mid = (L + R) / 2;
        return sum(2 * i, L, mid, p, q) + sum(2 * i + 1, mid + 1, R, p, q);
    }
}

int n, m, type, li, ri, xi;

struct comp{
    int L, R, X;
};
bool operator <(comp a, comp b){
    return a.L < b.L;
}
set <comp> S;

void update(int L, int R, int X){
    auto d = --S.upper_bound({L, R, X});

    stack <comp> to_add, to_remove;

    to_add.push({L, R, X});
    while(d != S.end()){
        if(d->L > R)break;
        
        to_remove.push(*d);
        if(d->L < L)to_add.push({d->L, L - 1, d->X});
        if(d->R > R)to_add.push({R + 1, d->R, d->X});
        
        add(1, 0, n - 1, max(L, d->L), min(R, d->R), abs(X - d->X));
        
        d++;
    }
    
    while(!to_remove.empty()){
        S.erase(to_remove.top());
        to_remove.pop();
    }
    while(!to_add.empty()){
        S.insert(to_add.top());
        to_add.pop();
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
        S.insert({i, i, i + 1});
        
    for(int i = 0; i < m; i++){
        scanf("%d", &type);
        
        if(type == 1){
            scanf("%d %d %d", &li, &ri, &xi);
            li--, ri--;
            
            update(li, ri, xi);
        }else{
            scanf("%d %d", &li, &ri);
            li--, ri--;
            
            printf("%I64d\n", sum(1, 0, n - 1, li, ri));
        }
    }
    
    return 0;
}