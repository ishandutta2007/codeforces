#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

pii operator-(const pii &p1,const pii &p2)
{
    return make_pair(p1.first - p2.first,p1.second - p2.second);
}

const int N = 100006;

pii v[N];

pii trim(pii p)
{
    int _ = __gcd(abs(p.first),abs(p.second));
    if (!_) return p;
    if (p.first < 0 || p.first == 0 && p.second < 0)
    {
        p.first = -p.first;
        p.second = -p.second;
    }
    return make_pair(p.first/_,p.second/_);
}

bool okay(pii p,pii q)
{
    //p --> v[i] - v[j]
    p = trim(p);
    q = trim(q);
    if (q == make_pair(0,0)) return true;
    else if (p == q) return true;
    return false;
}

bool used[N];

int n;

void check(int i,int j)
{
    //v[i] - v[j] is as vector
    pii p = v[i] - v[j];
    memset(used,0,sizeof(used));
    vector<int> vv;
    for (int k=1;n>=k;k++)
    {
        if (okay(p,v[k] - v[i]))
        {
            used[k] = true;
        }
        else
        {
            vv.push_back(k);
        }
    }
    if (vv.size() <= 2)
    {
        puts("YES");
        exit(0);
    }
    p = v[ vv[1] ] - v[ vv[0] ];
    for (int i:vv)
    {
        if (!okay(p,v[i] - v[ vv[0] ]))
        {
            return;
        }
    }
    puts("YES");
    exit(0);
}

int main ()
{
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d %d",&v[i].first,&v[i].second);
    }
    if (n <= 4)
    {
        puts("YES");
        return 0;
    }
    check(1,2);
    check(1,3);
    check(2,3);
    puts("NO");
}