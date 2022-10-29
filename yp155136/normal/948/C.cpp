#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LL;

struct Treap
{
    Treap *lc,*rc;
    LL key;
    LL sum,tag;
    int pri;
    int sz;
    Treap(){}
    Treap(LL _key):lc(NULL),rc(NULL),key(_key),pri(rand()),sum(_key),tag(0),sz(1){}
};

LL Sum(Treap* t)
{
    return t?t->sum:0;
}

int Sz(Treap* t)
{
    return t?t->sz:0;
}

void pull(Treap* t)
{
    if (!t) return;
    t->sum = Sum(t->lc) + Sum(t->rc) + t->key;
    t->sz = Sz(t->lc) + Sz(t->rc) +1;
    return;
}

void push(Treap* t)
{
    if(t->tag == 0) return;
    if (t->lc)
    {
        t->lc->tag += t->tag;
        t->lc->key += t->tag;
        t->lc->sum += Sz(t->lc)*t->tag;
    }
    if (t->rc)
    {
        t->rc->tag += t->tag;
        t->rc->key += t->tag;
        t->rc->sum += Sz(t->rc) * t->tag;
    }
    t->tag = 0;
    return;
}

Treap* merge(Treap* a,Treap* b)
{
    if (!a || !b) return a?a:b;
    else if (a->pri > b->pri)
    {
        push(a);
        a->rc = merge(a->rc,b);
        pull(a);
        return a;
    }
    else
    {
        push(b);
        b->lc = merge(a,b->lc);
        pull(b);
        return b;
    }
}

void split(Treap* t,LL k,Treap* &a,Treap* &b)
{
    if (!t)
    {
        a=b=NULL;
        return;
    }
    push(t);
    if (t->key <= k)
    {
        a=t;
        split(t->rc,k,a->rc,b);
        pull(a);
    }
    else
    {
        b=t;
        split(t->lc,k,a,b->lc);
        pull(b);
    }
}

void addd(Treap* t,LL val)
{
    if (!t) return;
    t->tag += val;
    t->key += val;
    t->sum += t->sz*val;
    return;
}

const int N = 100006;

LL v[N],t[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&v[i]);
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&t[i]);
    }
    Treap* root=NULL;
    for (int i=1;n>=i;i++)
    {
        LL ans=0;
        Treap* tr;
        split(root,v[i],root,tr);
        root = merge( merge(root,new Treap(v[i])),tr );
        Treap *tl;
        split(root,t[i],tl,root);
        ans += Sum(tl);
        ans += Sz(root)*t[i];
        addd(root,-t[i]);
        printf("%lld\n",ans);
    }
}