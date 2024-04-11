#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

int a[N];
int v[N];
int pre[N];
int pre2[N];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&v[i]);
    }
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] + a[i];
        pre2[i] = pre2[i-1];
        if (v[i]) pre2[i] += a[i];
    }
    int ans=0;
    for (int i=1;n-k+1>=i;i++)
    {
        ans = max( ans, pre2[i-1] + (pre[i+k-1] - pre[i-1]) + (pre2[n] - pre2[i+k-1])  );
    }
    printf("%d\n",ans);
}