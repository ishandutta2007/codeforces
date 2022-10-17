#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N],t[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
            t[i]=s[i];
        sort(t+1,t+n+1);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=s[i]!=t[i];
        printf("%d\n",ans);
    }
}