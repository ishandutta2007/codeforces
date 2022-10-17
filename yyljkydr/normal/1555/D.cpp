#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,q;

char s[N];

int f[6][N];

int p[3];

int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    p[0]='a',p[1]='b',p[2]='c';
    int x=0;
    do
    {
        for(int i=0;i<n;i++)
            f[x][i]=(!i?0:f[x][i-1])+(s[i]!=p[i%3]);
        x++;
    }while(next_permutation(p,p+3));
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        int ans=1e9;
        for(int i=0;i<6;i++)
            ans=min(ans,f[i][r]-(!l?0:f[i][l-1]));
        printf("%d\n",ans);
    }
}