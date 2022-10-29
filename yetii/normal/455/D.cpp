#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long ll;
struct V
{
    V *l, *r, *pa, *pt;
    int p, y, s;
    V(V *pt, int p) : l(0), r(0), pa(0), pt(pt), p(p), y(rand()), s(1) {}
};
typedef V *pv;
int sof(pv v)
{
    return v?v->s:0;
}
void rc(pv v)
{
    if (v)
    {
        v->s=1+sof(v->l)+sof(v->r);
        if (v->l) v->l->pa=v;
        if (v->r) v->r->pa=v;
    }
}
void sp(pv v, pv p)
{
    if (v) v->pa=p;
}
void mer(pv &t, pv l, pv r)
{
    if (!l||!r) return void(t=l?l:r);
    if (l->y<r->y) mer(l->r, l->r, r), t=l;
    else mer(r->l, l, r->l), t=r;
    rc(t);
}
void splm(pv t, pv &l, pv &r, int k)
{
    if (!t) return void(l=r=0);
    if (sof(t->l)>=k) splm(t->l, l, t->l, k), r=t;
    else splm(t->r, t->r, r, k-1-sof(t->l)), l=t;
    rc(t);
}
int gp(pv v)
{
    int rs=sof(v->l);
    while (v->pa)
    {
        if (v->pa->r==v) rs+=1+sof(v->pa->l);
        v=v->pa;
    }
    return rs;
}
void spl(pv t, pv &l, pv &r, int k)
{
    if (!t) return void(l=r=0);
    if (gp(t->pt)>=k) spl(t->l, l, t->l, k), r=t;
    else spl(t->r, t->r, r, k), l=t;
    rc(t);
}
pv rt[111111], grt;
void rsh(int l, int r)
{
    pv L, M, A, B, R;
    splm(grt, L, R, r-1);
    splm(R, M, R, 1);
    if (sof(M)!=1) throw;
    int x=M->p;
    mer(L, L, M);
    mer(grt, L, R);
    pv L1, M1, A1, B1, R1;
    spl(rt[x], L1, R1, l);
    spl(R1, M1, R1, r);
    spl(M1, A1, B1, r-1);
    if (sof(B1)!=1) throw;
    splm(grt, L, R, l);
    splm(R, M, R, r-l);
    splm(M, A, B, r-l-1);
    if (sof(B)!=1) throw;
    mer(M, B, A);
    mer(L, L, M);
    mer(grt, L, R);
    mer(M1, B1, A1);
    mer(L1, L1, M1);
    mer(rt[x], L1, R1);
}
int cnt(int l, int r, int k)
{
    pv L, M, R;
    spl(rt[k], L, M, l);
    spl(M, M, R, r);
    int rs=sof(M);
    mer(L, L, M);
    mer(rt[k], L, R);
    return rs;
}
int nx(int i, int n, int la)
{
    return (i+la-1)%n+1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, q;
    scanf("%d", &n);
    for (int i=0;i<n;++i)
    {
        int a; scanf("%d", &a);
        pv re=new V(0, a);
        mer(rt[a], rt[a], new V(re, 0));
        mer(grt, grt, re);
    }
    scanf("%d", &q); int la=0;
    for (int i=0;i<n;++i)
    {
        int t, l, r, k=0;
        scanf("%d %d %d", &t, &l, &r);
        if (t==2) scanf("%d", &k);
        l=nx(l, n, la); r=nx(r, n, la); k=nx(k, n, la);
        if (l>r) swap(l, r); --l;
        if (t==1) rsh(l, r);
        else printf("%d\n", la=cnt(l, r, k));
    }
    return 0;
}