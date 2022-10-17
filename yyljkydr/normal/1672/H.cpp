#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,q;

char ss[N];

int a[N];

int s[2][N];

int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",ss+1);
    for(int i=1;i<=n;i++)
        a[i]=(ss[i]-'0');
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            s[j][i]=s[j][i-1]+(a[i]==j&&a[i]==a[i-1]);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=max(s[0][r]-s[0][l],s[1][r]-s[1][l])+1;
        printf("%d\n",ans);
    }
}
/*
000
*/