#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int a[123456];
pii p[123456];

multiset<int> st;

int now_val;

struct DJS
{
    int p[123456];
    int sz[123456];
    void init(int n)
    {
        for (int i=0;n>=i;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        return p[x]==x?p[x]:p[x]=Find(p[x]);
    }
    void Union(int x,int y)
    {
        x = Find(x);
        y = Find(y);
        if (x == y) return;
        p[x] = y;
        sz[y] += sz[x];
    }
    int get_sz(int x)
    {
        x = Find(x);
        return sz[x];
    }
} djs;

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        p[i] = make_pair(a[i],i);
    }
    a[0] = a[n+1] = 2123456789;
    sort(p+1,p+n+1);
    djs.init(n);
    int ans = -1;
    int mx = -1;
    for (int i=1;n>=i;i++)
    {
        int id = p[i].S;
        int add_sz = 1;
        if (a[id-1] < a[id])
        {
            st.erase(st.find( djs.get_sz(id-1) ));
            add_sz += djs.get_sz(id-1);
            djs.Union(id-1,id);
        }
        else if (a[id+1] < a[id])
        {
            st.erase(st.find( djs.get_sz(id+1) ));
            add_sz += djs.get_sz(id+1);
            djs.Union(id+1,id);
        }
        st.insert(add_sz);
        if ((*st.begin()) == *(--st.end()))
        {
            if ((int)st.size() > mx)
            {
                mx = (int)st.size();
                ans = p[i].F;
            }
        }
    }
    printf("%d\n",ans+1);
}