#include<bits/stdc++.h>
#define maxn 205
using namespace std;
typedef long long LL;

int n;
char s[maxn];

int L[maxn],R[maxn];

char t[maxn];

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    R[0]=n+1,L[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        if (i&1)
        {
            L[i]=0,R[i]=R[0];
            R[0]=i,L[R[i]]=i;
        } else
        {
            R[i]=n+1,L[i]=L[n+1];
            L[n+1]=i,R[L[i]]=i;
        }
    }

    for (int c=1,i=R[0];i!=n+1;i=R[i])
        t[i]=s[c++];
    for (int i=1;i<=n;++i)
        putchar(t[i]);
    return 0;
}