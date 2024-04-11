#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    Treap *lc,*rc;
    int key,pri,sz;
    Treap(){}
    Treap(int _key):lc(NULL),rc(NULL),pri(rand()),sz(1),key(_key){}
};

int Sz(Treap* t)
{
    return t?t->sz:0;
}

void pull(Treap* t)
{
    if (!t) return;
    t->sz = Sz(t->lc) + Sz(t->rc) + 1;
}

Treap* merge(Treap* a,Treap* b)
{
    if (!a || !b) return a?a:b;
    else if (a->pri > b->pri)
    {
        a->rc = merge(a->rc,b);
        pull(a);
        return a;
    }
    else
    {
        b->lc = merge(a,b->lc);
        pull(b);
        return b;
    }
}

void split(Treap* t,int k,Treap* &a,Treap* &b)
{
    if (!t) a=b=NULL;
    else if (t->key <= k)
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

int a[512345];

Treap* root = NULL;

bool hhave(int l,int r)
{
    Treap *tl,*tr;
    split(root,l-1,tl,root);
    split(root,r,root,tr);
    bool ret = (Sz(root) != 0);
    root = merge( merge(tl,root),tr );
    return ret;
}

void addd(int x)
{
    Treap *tl;
    split(root,x,tl,root);
    root = merge( merge(tl,new Treap(x)) , root );
}

int main ()
{
    int n,k,d;
    scanf("%d %d %d",&n,&k,&d);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int ptr=1;
    addd(0);
    for (int i=1;n>=i;i++)
    {
        while (a[i] - a[ptr] > d) ++ptr;
        if (i - ptr + 1 < k) continue;
        if (hhave(ptr-1, i-k))
        {
            addd(i);
        }
    }
    if (hhave(n,n)) puts("YES");
    else puts("NO");
}