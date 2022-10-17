#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,f[N][2],g[N];

vector<int>v[N];

int ne[N];

char s[N];

int find(int x)
{
    return ne[x]==x?x:ne[x]=find(ne[x]);
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    ne[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        ne[i]=i;
        if(s[i]=='?')
            f[i][0]=f[i+1][0]+1,f[i][1]=f[i+1][1]+1;
        else
            f[i][s[i]-'0']=f[i+1][s[i]-'0']+1,f[i][(s[i]-'0')^1]=0;
        v[max(f[i][0],f[i][1])].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        int p=1,ans=0;
        while(p<=n)
        {
            int np=find(p);
            if(np>n)
                break;
            ans++,p=np+i;
        }
        for(auto x:v[i])
            ne[x]=x+1;
        printf("%d ",ans);
    }
    puts("");
}