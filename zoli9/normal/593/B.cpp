#include <bits/stdc++.h>
using namespace std;
long long n, x1, x2;
struct met
{
    long long m1, m2;
};
met t[100009];
int rendez(const void *a, const void *b)
{
    met s=(*(met*)a);
    met d=(*(met*)b);
    if(s.m1==d.m1)
    {
        if(s.m2-d.m2>0) return 1;
        if(s.m2-d.m2<0) return -1;
        return 0;
    }
    if(s.m1-d.m1>0) return 1;
    if(s.m1-d.m1<0) return -1;
    return 0;
}
int main()
{
    cin>>n>>x1>>x2;
    for(int i=1; i<=n; i++)
    {
        long long a, b;
        cin>>a>>b;
        t[i].m1=a*x1+b;
        t[i].m2=a*x2+b;
    }
    qsort(t+1, n, sizeof(met), rendez);
    for(int i=2; i<=n; i++)
    {
        if(t[i].m2<t[i-1].m2)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}