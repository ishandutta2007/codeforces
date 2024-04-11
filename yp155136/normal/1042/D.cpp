#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Treap
{
    Treap *lc,*rc;
    LL key,pri,sz;
    Treap(LL _key):lc(NULL),rc(NULL),key(_key),pri(rand()),sz(1){}
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

void split(Treap* t,LL k,Treap* &a,Treap* &b)
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

void split_by_sz(Treap* t,int k,Treap* &a,Treap* &b)
{
	if (!t) a=b=NULL;
	else if (Sz(t->lc) + 1 <= k)
	{
		a=t;
		split_by_sz(t->rc,k-Sz(t->lc)-1,a->rc,b);
		pull(a);
	}
	else
	{
		b=t;
		split_by_sz(t->lc,k,a,b->lc);
		pull(b);
	}
}

const int N = 200006;

LL pre[N];
LL a[N];

Treap* root;

void addd(LL val)
{
    Treap *tl;
    split(root,val,tl,root);
    root = merge(merge(tl,new Treap(val)),root);
}

void dell(LL val)
{
    Treap *tl,*tr;
    split(root,val-1,tl,root);
    split(root,val,root,tr);
    Treap *a;
    split_by_sz(root,1,a,root);
    root = merge( merge(tl,root),tr) ;
}

LL Q(LL val)
{
    Treap* tl;
    split(root,val-1,tl,root);
    LL ret = Sz(tl);
    root = merge(tl,root);
    return ret;
}

int main ()
{
    srand(time(0));
    int n;
    LL t;
    scanf("%d %lld",&n,&t);
    //Treap* root = NULL;
    for (int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        pre[i] = pre[i-1] + a[i];
        addd(pre[i]);
    }
    LL p = 0;
    LL ans = 0;
    for (int i=1;i<=n;++i)
    {
        //if (i != 1) dell(pre[i]);
        ans += Q(t+p);
        //cout << "i = " << i << " , ans = " << ans << endl;
        dell(pre[i]);
        p = pre[i];
    }
    printf("%lld\n",ans);
}