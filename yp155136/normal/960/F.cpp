#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    Treap *lc,*rc;
    int key,val,mx,pri;
    Treap(){}
    Treap(int _key,int _val) : lc(NULL),rc(NULL),key(_key),val(_val),mx(_val),pri(rand()){}
};

int Mx(Treap* t)
{
    return t?t->mx:0;
}

void pull(Treap* t)
{
    if (!t) return;
    t->mx = max( max( Mx(t->lc),Mx(t->rc) ),t->val );
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

const int N = 100006;

Treap *root[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int ans = 0;
    for (int i=1;n>=i;i++)
    {
        root[i] = NULL;
        root[i] = merge(root[i], new Treap(-1,0));
    }
    for (int i=1;m>=i;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        Treap *tl;
        split(root[x],z-1,tl,root[x]);
        int _ = Mx(tl);
        root[x] = merge(tl,root[x]);
        ans = max(ans,_+1);
        tl = NULL;
        split(root[y],z,tl,root[y]);
        root[y] = merge( merge( tl,new Treap(z,_+1) ),root[y] );
    }
    printf("%d\n",ans);
}