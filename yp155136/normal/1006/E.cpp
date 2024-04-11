#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    Treap *lc,*rc;
    int sz,key,pri;
    Treap(int _key):lc(NULL),rc(NULL),sz(1),pri(rand()),key(_key){}
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
    else if (Sz(t->lc) + 1 <= k)
    {
        a=t;
        split(t->rc,k - Sz(t->lc) - 1 ,a->rc,b);
        pull(a);
    }
    else
    {
        b=t;
        split(t->lc,k,a,b->lc);
        pull(b);
    }
}

const int N = 200006;

vector<int> G[N];
vector<int> ks[N];

map< pair<int,int> , int > mp;

int u[N],k[N];

Treap* dfs(int now)
{
    Treap* root = new Treap(now);
    for (int i:G[now])
    {
        Treap* t = dfs(i);
        root = merge(root,t);
    }
    //cout << "now = " << now <<endl;
    for (int i:ks[now])
    {
        if (Sz(root) < i) mp[ make_pair(now,i) ] = -1;
        else
        {
            Treap *tl,*tr;
            split(root,i-1,tl,root);
            split(root,1,root,tr);
            assert(root != NULL);
            //cout << "root->key = " << root->key << endl;
            mp[ make_pair(now,i) ] = root->key;
            root = merge( merge(tl,root),tr );
        }
    }
    return root;
}

int main ()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=2;n>=i;i++)
    {
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    for (int i=1;q>=i;i++)
    {
        scanf("%d %d",&u[i],&k[i]);
        ks[ u[i] ].push_back(k[i]);
    }
    dfs(1);
    for (int i=1;q>=i;i++)
    {
        printf("%d\n",mp[ make_pair(u[i],k[i]) ]);
    }
}