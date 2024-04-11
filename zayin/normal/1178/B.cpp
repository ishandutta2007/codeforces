#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

int n;
char s[maxn];

LL L[maxn],R[maxn];

int main()  {
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;++i)  {
        L[i]=L[i-1];
        if (i&&s[i-1]=='v'&&s[i]=='v')
            ++L[i];
    }
    for (int i=n;i;--i) {
        R[i]=R[i+1];
        if (i<n&&s[i+1]=='v'&&s[i]=='v')
            ++R[i];
    }
    LL ans=0;
    for (int i=1;i<=n;++i)
        if (s[i]=='o')
            ans+=L[i-1]*R[i+1];
        printf("%lld\n",ans);
    return 0;
}