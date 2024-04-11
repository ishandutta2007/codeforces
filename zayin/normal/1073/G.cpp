#include<bits/stdc++.h>
#define maxc 26
#define maxh 20
#define maxn 400050
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int F[maxh][maxn];

int sz,last;
int len[maxn];
int *fa=F[0],ch[maxn][maxc];

int n,m;
char s[maxn];

int newnode(int _len=0)
{
    len[sz]=_len;
    return sz++;
}

void insert(int c)
{
    int k=last,leaf=newnode(len[k]+1);
    for (;~k&&!~ch[k][c];k=fa[k])
        ch[k][c]=leaf;
    if (!~k)
        fa[leaf]=0;
    else
    {
        int p=ch[k][c];
        if (len[p]==len[k]+1)
            fa[leaf]=p;
        else
        {
            int np=newnode(len[k]+1);
            memcpy(ch[np],ch[p],sizeof(ch[p]));
            fa[np]=fa[p];
            fa[p]=fa[leaf]=np;
            for (;~k&&ch[k][c]==p;k=fa[k])
                ch[k][c]=np;
        }
    }
    last=leaf;
}

vector<string> str[maxn];

void travel(int k,string s="")
{
    if (!~k)    return ;
    str[k].push_back(s);
    for (int c=0;c<maxc;++c)
        travel(ch[k][c],s+(char)(c+'a'));
}

int pos[maxn];

int dep[maxn];
int T,L[maxn],R[maxn];

vector<int> G[maxn];

void dfs(int i)
{
    L[i]=T++;
    for (int j=1;~F[j-1][i];++j)
        F[j][i]=F[j-1][F[j-1][i]];
    // cout<<i<<" "<<len[i]<<" "<<str[i].back()<<endl;
    for (auto j:G[i])
        dep[j]=dep[i]+1,dfs(j);
    R[i]=T;
}

void init()
{
    memset(ch,-1,sizeof(ch));
    memset(F,-1,sizeof(F));

    scanf("%d%d%s",&n,&m,s+1);
    last=newnode();
    reverse(s+1,s+n+1);
    for (int i=1;i<=n;++i)
        insert(s[i]-'a');

    for (int k=0,i=1;i<=n;pos[n+1-i++]=k)
        k=ch[k][s[i]-'a'];
    for (int i=1;i<sz;++i)
        G[fa[i]].push_back(i);
    // travel(0);
    dfs(0);
}

int nA,nB;
int N,S[maxn];

LL cnt0[maxn],cnt1[maxn];

int stk[maxn],tp;

bool cmp(int i,int j)
{
    return L[i]<L[j];
}

int LCA(int u,int v)
{
    if (dep[u]<dep[v])
        swap(u,v);
    for (int d=dep[u]-dep[v],i=0;i<maxh;++i)
        if (d>>i&1)
            u=F[i][u];
    if (u==v)   return u;
    for (int i=maxh-1;~i;--i)
    {
        if (F[i][u]==F[i][v]) continue;
        u=F[i][u];
        v=F[i][v];
    }
    return fa[u];
}

LL ans;
vector<int> son[maxn];

void calc(int i)
{
    ans+=cnt0[i]*cnt1[i]*len[i];
    // cout<<i<<":";
    // for (auto j:son[i])
    //     cout<<j<<" ";
    // cout<<endl;
    for (auto j:son[i])
    {
        calc(j);
        ans+=(cnt0[i]*cnt1[j]+cnt1[i]*cnt0[j])*len[i];
        cnt0[i]+=cnt0[j];
        cnt1[i]+=cnt1[j];
    }
    // cout<<i<<" "<<cnt0[i]<<" "<<cnt1[i]<<endl;
}

void free(int i)
{
    for (auto j:son[i])
        free(j);
    son[i].clear();
    cnt0[i]=cnt1[i]=0;
}

int Max(int i,int j)
{
    return dep[i]>dep[j]?i:j;
}

void solve()
{
    while (m--)
    {
        scanf("%d%d",&nA,&nB);
        N=0;
        for (int x,i=0;i<nA;++i)  scanf("%d",&x),++cnt0[pos[x]],S[N++]=pos[x];//,cout<<pos[x]<<" "; cout<<endl;
        for (int x,i=0;i<nB;++i)  scanf("%d",&x),++cnt1[pos[x]],S[N++]=pos[x];//,cout<<pos[x]<<" "; cout<<endl;

        sort(S,S+N,cmp);
        S[N++]=0;

        ans=tp=0;
        stk[++tp]=0;
        for (int k=0;k<N;++k)
        {
            int i=S[k];
            if (i==stk[tp]) continue;
            int lca=LCA(i,stk[tp]);
            for (;tp&&dep[stk[tp]]>dep[lca];--tp)
                    // cout<<"edge:"<<Max(stk[tp-1],lca)<<" "<<stk[tp]<<endl,
                    son[Max(stk[tp-1],lca)].push_back(stk[tp]);
            if (stk[tp]!=lca)
                stk[++tp]=lca;
            stk[++tp]=i;
        }

        calc(0);
        free(0);
        printf("%I64d\n",ans);
    }
}

int main()
{
    init();
    solve();
    return 0;
}