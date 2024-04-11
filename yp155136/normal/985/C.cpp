#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

int a[N];

bool used[N];

int main ()
{
    int n,k,l;
    scanf("%d %d %d",&n,&k,&l);
    int m = n*k;
    for (int i=1;m>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+m+1);
    if (abs(a[1] - a[m/k]) > l)
    {
        puts("0");
        return 0;
    }
    int __ = -1;
    for (int i=1;m>=i;i++)
    {
        if (a[i] - a[1] <= l)
        {
            __ = i;
        }
    }
    vector<int> v;
    int cnt = m/k;
    for (int i=1;m>=i;i+=k)
    {
        if (a[i] - a[1] <= l)
        {
            v.push_back(a[i]);
            used[i] = true;
            --cnt;
        }
    }
    while (cnt--)
    {
        while (used[__]) --__;
        used[__] = true;
        v.push_back(a[__]);
    }
    assert(cnt == -1);
    long long ans=0;
    for (int i:v) ans+= i;
    printf("%lld\n",ans);
}