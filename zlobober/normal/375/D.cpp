#include <cstdio>
#include <cstdlib>
#include <map>
#include <cassert>
#include <vector>
using namespace std;


const int N = 100500;
vector<int> E[N];
int C[N];

vector<pair<int, int> > Q[N];

const int MEGASZ = 40 * 1000 * 1000;
char MEGABUF[MEGASZ];
int mpt = 0;

struct node
{
    node *l, *r;
    pair<int, int> x;
    int sz;
    int y;
    static node* null;
    node(pair<int, int> _x)
    {
        x = _x; 
        l = r = null;
        y = rand();
        sz = 1;
    }
    void recount()
    {
        if (this == null)
            return;
        this->sz = l->sz + r->sz + 1;
    }
    void* operator new(size_t sz)
    {
        void* ret = (void*)(MEGABUF + mpt);
        mpt += sz;
        assert(mpt < MEGASZ * 0.99); 
        return ret;
    }
    node()
    {
        l = r = this;
        sz = 0;
    }
};

#define null node::null
node* null = new node();

// ..< >=...
inline pair<node*, node*> split(node* n, pair<int, int> x)
{
    if (n == null)
        return make_pair(null, null);
    if (n->x >= x)
    {
        pair<node*, node*> pr = split(n->l, x);
        n->l = pr.second;
        n->recount();
        return make_pair(pr.first, n);
    }
    else
    {
        pair<node*, node*> pr = split(n->r, x);
        n->r = pr.first;
        n->recount();
        return make_pair(n, pr.second);
    }
}

inline node* merge(node* a, node* b)
{
    if (a == null)
        return b;
    if (b == null)
        return a;
    if (a->y < b->y)
    {
        b->l = merge(a, b->l);
        b->recount();
        return b;
    }
    else
    {
        a->r = merge(a->r, b);
        a->recount();
        return a;
    }
}

struct info
{
    map<int, int> sz;
    node* t;
};

info I[N];

node* erase(node* t, pair<int, int> x)
{
    if (t == null)
        return null;
    else if (t->x == x)
        return merge(t->l, t->r);
    else if (t->x > x)
    {
        t->l = erase(t->l, x);
        t->recount();
        return t;
    }
    else
    {
        t->r = erase(t->r, x);
        t->recount();
        return t;
    }
}

void merge(info& a, info& b)
{
    if (a.sz.size() < b.sz.size())
    {
        a.sz.swap(b.sz);
        swap(a.t, b.t);
    }
    for (map<int, int>::iterator it = b.sz.begin(); it != b.sz.end(); it++)
    {
        int osz = a.sz[it->first];
        int nsz = osz + it->second;
        a.t = erase(a.t, make_pair(osz, it->first));
        pair<node*, node*> pr = split(a.t, make_pair(nsz, it->first));
        a.t = merge(pr.first, merge(new node(make_pair(nsz, it->first)), pr.second));
        a.sz[it->first] += it->second;
    }
    b.sz.clear();
}

int ans[N];

int cnt(node* t, int v)
{
    if (t == null)
        return 0;
    if (t->x.first >= v)
    {
        return 1 + t->r->sz + cnt(t->l, v);
    }
    else
        return cnt(t->r, v);
}

void DFS(int x, int p = -1)
{
    I[x].sz[C[x]] = 1;
    I[x].t = new node(make_pair(1, C[x]));
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
            continue;
        DFS(y, x);
        merge(I[x], I[y]);
    }
    for (int i = 0; i < Q[x].size(); i++)
        ans[Q[x][i].second] = cnt(I[x].t, Q[x][i].first);
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int v, k;
        scanf("%d %d", &v, &k);
        Q[v].push_back(make_pair(k, i));
    }
    DFS(1);
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
}