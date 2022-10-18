//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 100005;

int n, m, d[MAXN], h[MAXN];
long long D[2 * MAXN], A[2 * MAXN], B[2 * MAXN];

struct abdallah{
    long long a, b, c;
};

vector <abdallah> tree;
void build(int i, int L, int R){
    if(L == R){
        tree[i].a = A[L];
        tree[i].b = B[L];
        tree[i].c = 0;
        
        return;
    }
    
    int mid = (L + R) / 2;
    build(2 * i, L, mid);
    build(2 * i + 1, mid + 1, R);
    
    tree[i].a = max(tree[2 * i].a, tree[2 * i + 1].a);
    tree[i].b = min(tree[2 * i].b, tree[2 * i + 1].b);
    
    tree[i].c = max(max(tree[2 * i].c, tree[2 * i + 1].c), tree[2 * i + 1].a - tree[2 * i].b);
}
abdallah query(int i, int L, int R, int p, int q){
    if(q < p || R < p || q < L){
        abdallah ret;
        ret.a = -1LL << 60;
        ret.b = 1LL << 60;
        ret.c = -1LL << 60;
        
        return ret;
    }
    if(p <= L && R <= q)return tree[i];
    
    int mid = (L + R) / 2;
    abdallah essam = query(2 * i, L, mid, p, q);
    abdallah morsy = query(2 * i + 1, mid + 1, R, p, q);
    
    abdallah ret;
    ret.a = max(essam.a, morsy.a);
    ret.b = min(essam.b, morsy.b);
    ret.c = max(max(essam.c, morsy.c), morsy.a - essam.b);
    
    return ret;
}

int nO, pi, qi;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    
    nO = n;
    n *= 2;
    
    D[0] = 0;
    for(int i = 1; i < n; i++){
        if(i <= nO)D[i] = D[i - 1] + d[i - 1];
        else D[i] = D[i - 1] + d[i - nO - 1];
    }
    for(int i = 0; i < n; i++){
        if(i < nO){
             A[i] = D[i] + 2 * h[i];
             B[i] = D[i] - 2 * h[i];
        }else{
             A[i] = D[i] + 2 * h[i - nO];
             B[i] = D[i] - 2 * h[i - nO];
        }
    }
    
    tree.resize(5 * (n + 5));
    build(1, 0, n - 1);
    
    while(m--){
        scanf("%d %d", &pi, &qi);
        pi--, qi--;
 
        
        /*
        abdallah yousef = query(1, 0, n - 1, qi + 1, nO + pi - 1);
        cout << yousef.a << ' ' << yousef.b << ' ' << yousef.c << endl;
        */
        long long res = 0;
        
        if(qi < pi){
            res = max(res, query(1, 0, n - 1, qi + 1, pi - 1).c);
        }else res = max(res, query(1, 0, n - 1, qi + 1, nO + pi - 1).c);
        
        printf("%I64d\n", res);
    }
    /*
    for(int i = 0; i < (n); i++){
        cout << D[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < (n); i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < (n); i++){
        cout << B[i] << ' ';
    }
    cout << endl;
    */
    
    
    return 0;
}