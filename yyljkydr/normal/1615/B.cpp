#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,l,r;

int s[21][N];

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=2e5;i++)
        for(int j=0;j<20;j++)
            s[j][i]=s[j][i-1]+(i>>j&1);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=19;i>=0;i--)
            ans=max(ans,s[i][r]-s[i][l-1]);
        printf("%d\n",r-l+1-ans);
    }
}