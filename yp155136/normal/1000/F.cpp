#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 500006;

int a[N];
int aa[N];
int last[N];
int l[N],r[N];

vector<int> qs[N];
int ans[N];

struct Treap
{
    Treap *lc,*rc;
    pii key;
    int pri;
    pii val,mn;
    Treap(pii _key,pii _val) : lc(NULL),rc(NULL),key(_key),val(_val),mn(_val),pri(rand()){}
};

pii Mn(Treap* t)
{
    return t?t->mn:make_pair(123456789,987654321);
}

void pull(Treap* t)
{
    if (!t) return;
    t->mn = min( min( Mn(t->lc) , Mn(t->rc) ) , t->val );
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

void split(Treap* t,pii k,Treap* &a,Treap* &b)
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

Treap* root;

void addd(pii key,pii val)
{
    Treap *tl;
    split(root,key,tl,root);
    root = merge( merge( tl,new Treap(key,val) ) , root );
}

void dell(pii key)
{
    Treap *tl,*tr;
    split(root,make_pair(key.first,key.second-1),tl,root);
    split(root,key,root,tr);
    assert(root != NULL);
    root = merge(tl,tr);
}

int main ()
{
    root = NULL;
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);
    for (int i=1;q>=i;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
        qs[ r[i] ].push_back(i);
    }
    memset(aa,-1,sizeof(aa));
    for (int i=1;n>=i;i++)
    {
        if (aa[ a[i] ] == -1)
        {
            aa[ a[i] ] = 0;
            addd(make_pair( aa[ a[i] ] , a[i] ) , make_pair(-i,a[i]));
            //st.insert(make_pair(aa[ a[i] ] , a[i]));
        }
        else
        {
            dell( make_pair( aa[ a[i] ] , a[i] ) );
            //st.erase(st.find(make_pair( aa[ a[i] ] , a[i] )));
            aa[ a[i] ] = last[ a[i] ];
            addd(make_pair( aa[ a[i] ] , a[i] ) , make_pair(-i,a[i]));
            //st.insert(make_pair(aa[ a[i] ] , a[i]));
        }
        last[ a[i] ] = i;
        //for (pii p:st) cout << p.first << ' ' << p.second << endl;
        for (int qid:qs[i])
        {
            pii yee = make_pair( l[qid],-1 );
            Treap *tl;
            split(root,yee,tl,root);
            pii p = Mn(tl);
            root = merge(tl,root);
            if (p.first >= 0) continue;
            if (l[qid] <= -p.first)ans[ qid ] = p.second;
        }
    }
    for (int i=1;q>=i;i++)
    {
        printf("%d\n",ans[i]);
    }
}