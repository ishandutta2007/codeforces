#include<bits/stdc++.h>
using namespace std;

int T,n,m;

string s[200001];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            cin>>s[i];
        int ans=0;
        for(int i=0;i<m-1;i++)
            ans+=s[n][i]!='R';
        for(int i=1;i<n;i++)
            ans+=s[i][m-1]!='D';
        printf("%d\n",ans);
    }
}