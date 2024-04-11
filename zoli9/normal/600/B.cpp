#include <bits/stdc++.h>
using namespace std;
struct elem
{
    long long v;
    long long tip;
    long long az;
};
long long n, m;
long long valasz[400009];
elem t[400009];
int ren(const void *a, const void *b)
{
    elem x=(*(elem*)a);
    elem y=(*(elem*)b);
    if(x.v==y.v)
    {
        return x.tip-y.tip;
    }
    return x.v-y.v;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].v;
        t[i].az=i;
        t[i].tip=0;
    }
    for(int i=n+1; i<=n+m; i++)
    {
        cin>>t[i].v;
        t[i].az=i-n;
        t[i].tip=1;
    }
    qsort(t+1, n+m, sizeof(elem), ren);
    long long cnt=0;
    for(int i=1; i<=n+m; i++)
    {
        if(t[i].tip==0) cnt++;
        else
        {
            valasz[t[i].az]=cnt;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<valasz[i]<<" ";
    }
    return 0;
}