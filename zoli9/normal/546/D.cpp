#include <iostream>
#include <cstdio>
using namespace std;
int primedivisor[5000009];
int primefactors[5000009];
long long a[5000009];
int t;
int x[1000009];
int y[1000009];
long long ans[1000009];
int main()
{
    for(int i=2; i<=5000007; i++)
    {
        if(primedivisor[i]==0)
        {
            int akt=i;
            while(akt<=5000007)
            {
                primedivisor[akt]=i;
                akt+=i;
            }
        }
    }
    primefactors[1]=0;
    for(int i=2; i<=5000007; i++)
    {
        primefactors[i]=primefactors[i/primedivisor[i]]+1;
    }
    for(int i=2; i<=5000007; i++)
    {
        a[i]=a[i-1]+primefactors[i];
    }
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i=1; i<=t; i++)
    {
        ans[i]=a[x[i]]-a[y[i]];
    }
    for(int i=1; i<=t; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}