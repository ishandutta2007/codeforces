#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 500006;

struct DSU
{
    static const int N = 500006;
    int p[N];
    void init(int n)
    {
        for (int i=0;n>=i;i++) p[i] = i;
    }
    int Find(int x)
    {
        return p[x] == x?x:p[x] = Find(p[x]);
    }
    void Union(int x,int y)
    {
        p[Find(x)] = Find(y);
    }
} djs,djs2;

vector<int> G[N];
pii e[N];
bool is_wa[N];
int weight[N];

pii sagiri[N];

void hahaha(pii &p1)
{
    p1 = make_pair(max(p1.first,p1.second),min(p1.first,p1.second));
}

int kirino[N];

int Find_kirino(int x)
{
    return kirino[x] == x?x:kirino[x] = Find_kirino(kirino[x]);
}

void kirino_merge(int x,int y)
{
    kirino[Find_kirino(x)] = Find_kirino(y);
}

void recover(vector<int> v)
{
    for (int i:v)
    {
        kirino[ e[i].first ] = e[i].first;
        kirino[ e[i].second ] = e[i].second;
    }
}

void solve(vector<int> v)
{
    bool is_really_wa = false;
    for (int i:v) is_really_wa |= is_wa[i];
    if (is_really_wa)
    {
        puts("NO");
        return;
    }
    set<pii> st;
    for (int i:v)
    {
        if (Find_kirino(e[i].first) == Find_kirino(e[i].second))
        {
            recover(v);
            puts("NO");
            return;
        }
        kirino_merge(e[i].first,e[i].second);
        st.insert(sagiri[i]);
    }
    recover(v);
    if (st.size() == v.size()) puts("YES");
    else puts("NO");
}

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        G[z].push_back(i);
        e[i] = make_pair(x,y);
        weight[i] = z;
    }
    djs.init(n);
    djs2.init(n);
    for (int i=0;N>i;i++)
    {
        for (int q:G[i])
        {
            pii p=e[q];
            if (djs.Find(p.first) == djs.Find(p.second)) is_wa[q] = true;
            else sagiri[q] = make_pair( djs.Find(p.first),djs.Find(p.second) );
            hahaha(sagiri[q]);
        }
        for (int q:G[i])
        {
            djs.Union(e[q].first,e[q].second);
        }
    }
    for (int i=0;N>i;i++)
    {
        kirino[i] = i;
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int k;
        scanf("%d",&k);
        vector<int> v;
        for (int i=0;k>i;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        solve(v);
    }
}