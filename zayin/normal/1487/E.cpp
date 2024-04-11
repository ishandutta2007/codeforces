#include<bits/stdc++.h>
#define maxh 20
#define maxn 200050
using namespace std;

int na,nb,nc,nd;
int a[maxn],b[maxn],c[maxn],d[maxn];

int m;

int Log2[maxn];
int ST[maxh][maxn];

vector<int> G[maxn];

void calcST(int *a,int n,int ST[maxh][maxn])    {
    for (int i=1;i<=n;++i) ST[0][i]=a[i];
    for (int j=1;j<=Log2[n];++j)
        for (int i=1;i+(1<<j)-1<=n;++i)
            ST[j][i]=min(ST[j-1][i],ST[j-1][i+(1<<j-1)]);
}

int Min(int l,int r)    {
    if (l>r) return 5e8;
    int t=Log2[r-l+1];
    return min(ST[t][l],ST[t][r-(1<<t)+1]);
}

void solve(int *a,int na,int *b,int nb) {    
    calcST(a,na,ST);
    scanf("%d",&m);
    for (int i=1;i<=nb;++i) G[i]={0,na+1};
    while (m--)    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[y].push_back(x);
    }
    for (int i=1;i<=nb;++i) {
        sort(G[i].begin(),G[i].end());
        int mn=5e8;
        for (int j=1;j<G[i].size();++j)
            mn=min(mn,Min(G[i][j-1]+1,G[i][j]-1));
        b[i]+=mn;
    }
}

int main()  {
    Log2[0]=-1;
    for (int i=1;i<maxn;++i) Log2[i]=Log2[i>>1]+1;
    
    scanf("%d%d%d%d",&na,&nb,&nc,&nd);
    for (int i=1;i<=na;++i) scanf("%d",a+i);
    for (int i=1;i<=nb;++i) scanf("%d",b+i);
    for (int i=1;i<=nc;++i) scanf("%d",c+i);
    for (int i=1;i<=nd;++i) scanf("%d",d+i);

    solve(a,na,b,nb);
    solve(b,nb,c,nc);
    solve(c,nc,d,nd);

    int ans=5e8;
    for (int i=1;i<=nd;++i)
        ans=min(ans,d[i]);
    
    if (ans==5e8) ans=-1;
    printf("%d\n",ans);

    return 0;
}