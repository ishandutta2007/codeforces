#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

char s[N],t[N];

int vis[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            vis[i]=0;
        scanf("%s",s+1);
        scanf("%s",t+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i]=='1')
            {
                if(s[i-1]=='1'&&!vis[i-1])
                    ans++;
                else if(s[i]=='0'&&!vis[i])
                    ans++,vis[i]=1;
                else if(s[i+1]=='1')
                    ans++,vis[i+1]=1;
            }
        }
        printf("%d\n",ans);
    }
}