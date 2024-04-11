#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 100006;
const int G = (1<<20);

bool used[G];

int a[N];

vector<pii> q[N];

int kirino[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;m>=i;i++)
    {
        int l,x;
        scanf("%d %d",&l,&x);
        q[l].push_back(make_pair(x,i));
    }
    used[0] = 1;
    vector<int> v;
    v.push_back(0);
    int ans = 1;
    for (int i=1;n>=i;i++)
    {
        int _ = a[i];
        if (used[_])
        {
            ans <<= 1;
            ans %= (1000000007);
        }
        else
        {
            vector<int> vv;
            for (int i:v)
            {
                used[ (i^_) ] = true;
                vv.push_back((i^_));
            }
            for (int i:vv) v.push_back(i);
        }
        for (pii p:q[i])
        {
            int id=p.second;
            int w =p.first;
            if (used[w]) kirino[id] = ans;
            else kirino[id] = 0;
        }
    }
    for (int i=1;m>=i;i++)
    {
        printf("%d\n",kirino[i]);
    }
}