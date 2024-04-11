#include <bits/stdc++.h>
using namespace std;
long long n;
long long elozo[100009];
long long d[100009];
long long mini;
struct beacon
{
    long long a, b;
};
beacon t[100009];
int ren(const void *x, const void *y)
{
    beacon xx=(*(beacon*)x);
    beacon yy=(*(beacon*)y);
    return xx.a-yy.a;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].a>>t[i].b;
    }
    qsort(t+1, n, sizeof(beacon), ren);
    d[0]=0;
    d[1]=1;
    elozo[1]=1;
    for(int i=2; i<=n; i++)
    {
        int e=1;
        int u=i;
        int ko;
        while(e<=u)
        {
            ko=(e+u)/2;
            if(t[i].a-t[i].b<=t[ko].a)
            {
                u=ko-1;
            }
            else
            {
                e=ko+1;
            }
        }
        elozo[i]=e;
    }
    for(int i=2; i<=n; i++)
    {
        d[i]=1+d[elozo[i]-1];
    }

    mini=n;
    for(int i=1; i<=n; i++)
    {
        mini=min(mini, n-d[i]);
    }
    cout<<mini;
    return 0;
}