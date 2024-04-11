#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N],tag[4*N],n;
void Maxi(int &a, int b) {
    if (b > a) a = b;
}
void pushdown(int v) {
    if (tag[v]==0) return;
    int chl=v*2+1, chr=v*2+2;
    Maxi(tag[chl], tag[v]);
    Maxi(tag[chr], tag[v]);
    tag[v] = 0;
}


void update(int pos, int x, int v=0,int l=1,int r=n+1) {
    if (l+1==r) {
        tag[v] = 0;
        a[l] = x;
    } else {
        pushdown(v);
        int mid =(l+r)/2, chl=v*2+1,chr=v*2+2;
        if (pos<mid) update(pos,x,chl,l,mid);
        else update(pos,x,chr,mid,r);
    }
}

void getans(int v = 0, int l = 1, int r=n+1) {
    if (l+1==r) {
        Maxi(a[l], tag[v]);
    } else {
        pushdown(v);
        int mid =(l+r)/2, chl=v*2+1,chr=v*2+2;
        getans(chl,l,mid);
        getans(chr,mid,r);
    }
}

int main() {
    int q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int p,x;
            scanf("%d%d", &p, &x);
            update(p,x);
        } else {
            int x;
            scanf("%d", &x);
            Maxi(tag[0], x);
        }
    }
    getans();
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i==n]);
}