#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
typedef long long LL;

int n; 
char s[maxn];

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int l,r;
    for (l=1;l<=n;++l)
        if (s[l]=='[')
            break;
    for (r=n;r;--r)
        if (s[r]==']')
            break;
    if (l>r)
        return puts("-1"),0;
    
    int L,R;
    for (L=l;L<=r;++L)
        if (s[L]==':')
            break;
    for (R=r;R>=l;--R)
        if (s[R]==':')
            break;
    if (L>=R)
        return puts("-1"),0;
    int ans=4;
    for (int i=L;i<=R;++i)
        ans+=s[i]=='|';
    printf("%d\n",ans);
    return 0;
}