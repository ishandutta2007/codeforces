#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL a[156789];
set<int> st[156789];
map<LL,int> mp;

bool alive[156789];

int main ()
{
    int n;
    scanf("%d",&n);
    int id=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
        alive[i] = true;
        if (mp.find(a[i]) == mp.end())
        {
            mp[ a[i] ] = (++id);
        }
        st[ mp[ a[i] ] ].insert(i);
    }
    while (!mp.empty())
    {
        pair<LL,int> p = (*mp.begin());
        mp.erase(mp.begin());
        LL _ = p.first;
        int __ = p.second;
        while ((int)st[__].size() >= 2)
        {
            int i = (*st[__].begin());
            st[__].erase(st[__].begin());
            int ii = (*st[__].begin());
            st[__].erase(st[__].begin());
            alive[i] = false;
            a[ii] = 2*_;
            if (mp.find(a[ii]) == mp.end())
            {
                mp[ a[ii] ] = (++id);
            }
            st[ mp[ a[ii] ] ].insert(ii);
        }
    }
    vector<LL> v;
    for (int i=1;n>=i;i++)
    {
        if (alive[i])
        {
            v.push_back(a[i]);
        }
    }
    printf("%d\n",(int)v.size());
    for (int i=0;(int)v.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%lld",v[i]);
    }
    puts("");
}