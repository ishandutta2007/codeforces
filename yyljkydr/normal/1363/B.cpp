#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,c[N][2];

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<2;j++)
            c[i][j]=c[i-1][j]+(s[i]-'0'==j);
        int ans=min({c[n][0],c[n][1]});
        for(int i=1;i<=n;i++)
            ans=min(ans,c[i][0]+c[n][1]-c[i][1]),ans=min(ans,c[i][1]+c[n][0]-c[i][0]);
        printf("%d\n",ans);
    }
}