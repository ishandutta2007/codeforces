#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000006;

int l[N];

int main ()
{
    int ans=0;
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&l[i]);
    }
    int mn = n+1;
    for (int i=n;i>=1;i--)
    {
        if (mn > i) ans++;
        mn = min(mn,i-l[i]);
    }
    printf("%d\n",ans);
}