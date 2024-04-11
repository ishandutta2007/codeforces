#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;
#define mp make_pair

ll Q(pair<int, int> w)
{
    ll t=w.second-w.first;
    return t*(t+1)/2;
}

struct S
{
    ll s;
    set<pair<int, int>> a;
    S() : s(0) {}
    void init(vector<int> p)
    {
        sort(p.begin(), p.end());
        for (int i=0, j;i<p.size();i=j)
        {
            for (j=i+1;j<p.size()&&p[j-1]+1==p[j];++j);
            auto z=mp(p[i], p[j-1]+1);
            a.insert(z);
            s+=Q(z);
        }
    }
    void add(int p)
    {
        int L=p, R=p+1;
        auto il=a.lower_bound(mp(p, int(1e9)));
        if (il!=a.begin())
        {
            --il;
            if (p<il->second) return;
            if (il->second==L)
            {
                auto z=*il;
                a.erase(il);
                s-=Q(z);
                L=z.first;
            }
        }
        auto ir=a.lower_bound(mp(p+1, int(-1e9)));
        if (ir!=a.end())
        {
            if (p+1==ir->first)
            {
                auto z=*ir;
                a.erase(ir);
                s-=Q(z);
                R=z.second;
            }
        }
        a.insert(mp(L, R));
        s+=Q(mp(L, R));
    }
    void del(int p)
    {
        auto it=a.lower_bound(mp(p, int(1e9)));
        if (it==a.begin()) return;
        --it;
        if (it->second<=p) return;
        auto z=*it;
        a.erase(it);
        s-=Q(z);
        if (z.first<p)
        {
            a.insert(mp(z.first, p));
            s+=Q(mp(z.first, p));
        }
        if (p+1<z.second)
        {
            a.insert(mp(p+1, z.second));
            s+=Q(mp(p+1, z.second));
        }
    }
} s[17];
const int N=10+(1e5);
int n, m, a[N];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int b=0;b<17;++b)
    {
        vector<int> t;
        for (int i=0;i<n;++i) if (a[i]&(1<<b)) t.push_back(i);
        s[b].init(t);
    }
    for (int i=0;i<m;++i)
    {
        int p, v; scanf("%d %d", &p, &v); --p;
        ll rs=0;
        for (int b=0;b<17;++b)
        {
            if (a[p]&(1<<b)) s[b].del(p);
            if (v&(1<<b)) s[b].add(p);
            rs+=s[b].s*(1<<b);
        }
        a[p]=v;
        printf("%I64d\n", rs);
    }
    return 0;
}