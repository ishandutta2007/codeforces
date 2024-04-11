#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int trie[N][10],fail[N],tot,tag[N];

void ins(vector<int>v)
{
    int x=0;
    for(int i=0;i<v.size();i++)
    {
        if(trie[x][v[i]]==-1)
        {
            trie[x][v[i]]=++tot;
            for(int j=0;j<10;j++)
                trie[tot][j]=-1;
        }
        x=trie[x][v[i]];
    }
    tag[x]=1;
}

queue<int>q;

void getfail()
{
    for(int i=0;i<10;i++)
		if(trie[0][i]!=-1)
			fail[trie[0][i]]=0,q.push(trie[0][i]);
		else
			trie[0][i]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<10;i++)
            if(trie[x][i]==-1)
                trie[x][i]=trie[fail[x]][i];
            else
                fail[trie[x][i]]=trie[fail[x]][i],q.push(trie[x][i]);
    }
}

int n,m;

char s[N];

vector<int>v;

void dfs(int cur)
{
    if(cur==0)
    {
        for(int i=0;i<v.size();i++)
        {
            int sum=0;
            for(int j=i;j<v.size();j++)
            {
                sum+=v[j];
                if(sum!=m&&m%sum==0)
                    return;
            }
        }
        ins(v);
        return;
    }
    for(int i=1;i<=min(9,cur);i++)
        v.push_back(i),dfs(cur-i),v.pop_back();
}

int f[1001][5001];

int main()
{
    for(int i=0;i<10;i++)
        trie[0][i]=-1;
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&m);
    dfs(m);
    // cout<<tot<<endl;
    getfail();
    for(int i=0;i<=tot;i++)
        tag[i]|=tag[fail[i]];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=tot;j++)
            f[i][j]=1e9;
    f[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=tot;j++)
        {
            f[i+1][j]=min(f[i+1][j],f[i][j]+1);
            int np=trie[j][s[i+1]-'0'];
            if(!tag[np])
                f[i+1][np]=min(f[i+1][np],f[i][j]);
        }
    int ans=1e9;
    for(int i=0;i<=tot;i++)
        ans=min(ans,f[n][i]);
    printf("%d\n",ans);
}