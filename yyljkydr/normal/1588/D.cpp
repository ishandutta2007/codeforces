#include<bits/stdc++.h>
using namespace std;

const int N=11,M=111;

int T,n;

int a[N][M],pos[N][M][2];

char s[M];

int vis[1<<N][M],f[1<<N][M];

pair<int,int> to[1<<N][M];

int dp(int S,int ch)
{
    if(vis[S][ch])
        return f[S][ch];
    vis[S][ch]=1;
    f[S][ch]=1;
    to[S][ch]={-1,-1};
    for(int i=0;i<52;i++)
    {
        bool ok=1;
        int nS=0;
        for(int j=1;j<=n;j++)
        {
            int pn=pos[j][ch][(S>>(j-1))&1];
            int np=pos[j][i][0]>pn?0:1;
            if(pos[j][i][np]<=pn)
            {
                ok=0;
                break;
            }
            nS|=(np<<(j-1));
        }
        if(!ok)
            continue;
        int val=dp(nS,i)+1;
        if(val>f[S][ch])
            f[S][ch]=val,to[S][ch]={nS,i};
    }
    return f[S][ch];
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(pos,0,sizeof(pos));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            int len=strlen(s+1);
            for(int j=1;j<=len;j++)
            {
                a[i][j]=islower(s[j])?s[j]-'a':s[j]-'A'+26;
                if(!pos[i][a[i][j]][0])
                    pos[i][a[i][j]][0]=j;
                else
                    pos[i][a[i][j]][1]=j;
            }
        }
        int ans=0,fi=-1;
        for(int i=0;i<52;i++)
        {
            bool ok=1;
            for(int j=1;j<=n;j++)
                ok&=pos[j][i][0]!=0;
            if(!ok)
                continue;
            int val=dp(0,i);
            if(val>ans)
                fi=i,ans=val;
        }
        printf("%d\n",ans);
        int S=0,i=fi;
        vector<int>ns;
        while(i!=-1)
        {
            ns.push_back(i);
            auto [nS,ni]=to[S][i];
            S=nS,i=ni;
        }
        ns.push_back(-1);
        for(auto x:ns)
        {
            if(x==-1)
                puts("");
            else if(x<26)
                putchar('a'+x);
            else
                putchar('A'+x-26);
        }
    }
}