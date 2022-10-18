#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN], b[MAXN], ord[MAXN];

int tree[MAXN];
void add(int i, int v){
    i++;
    while(i < MAXN){
        tree[i] += v;
        i += i & (-i);
    }
}
int sum(int i){
    i++;
    
    int r = 0;
    while(i > 0){
        r += tree[i];
        i -= i & (-i);
    }
    return r;
}
void addord(int *p){
    memset(tree, 0, sizeof tree);
    
    for(int i = n - 1; i >= 0; i--){
        int r = sum(p[i]);
        ord[n - i - 1] += r;
        
        add(p[i], 1);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
        
    addord(a);
    addord(b);
    
    int c = 0;
    for(int i = 0; i < n; i++){
        ord[i] += c;
        c = 0;
        
        c = ord[i] / (i + 1);
        ord[i] = ord[i] % (i + 1);
    }
    
    memset(tree, 0, sizeof tree);
    for(int i = 0; i < n; i++)add(i, 1);
    
    for(int i = n - 1; i >= 0; i--){
        int j = 0, k = ord[i];
        for(int d = 20; d >= 0; d--){
            if(j + (1 << d) >= MAXN)continue;
            if(k >= tree[j + (1 << d)]){
                k -= tree[j + (1 << d)];
                j += 1 << d;
            }
        }
        
        if(i < n - 1)printf(" ");
        printf("%d", j);
        
        add(j, -1);
    }
    printf("\n");
    
    return 0;
}