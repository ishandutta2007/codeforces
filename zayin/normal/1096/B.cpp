#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n;
char s[maxn];

LL F[maxn]={1};

int main()
{
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;++i)
        F[i]=F[i-1]*2%modu;
    int l=1,r=n;
    while (l<=n&&s[l]==s[1])    ++l;
    while (r&&s[r]==s[n])    --r;
    --l,++r;
    // cout<<l<<" "<<r<<endl;
    if (s[1]==s[n])
    {
        if (l==n&&r==1)
            printf("%lld\n",F[n]);
        else
            printf("%lld\n",1LL*(l+1)*(n-r+1+1)%modu);
    } else
    {
        printf("%lld\n",1LL*((l+1)+(n-r+1+1)-1+modu)%modu);
    }
    return 0;
}