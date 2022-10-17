#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

struct Seg{
    int l,r,c;
}a[N];

bool operator <(const Seg &a,const Seg &b)
{
    return a.l<b.l||(a.l==b.l&&a.r>b.r);
}

int fa[N];

int s[2][N];

vector<int>X;

vector<Seg>g[2];

queue<int>q;

int vis[N];

int L[N],R[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        X.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].c,&a[i].l,&a[i].r),X.push_back(a[i].l),X.push_back(a[i].r);
        sort(X.begin(),X.end());
        X.resize(unique(X.begin(),X.end())-X.begin());
        for(int i=1;i<=n;i++)
        {
            a[i].l=lower_bound(X.begin(),X.end(),a[i].l)-X.begin()+1;
            a[i].r=lower_bound(X.begin(),X.end(),a[i].r)-X.begin()+1;
        }
        for(int i=0;i<=n*2;i++)
            s[0][i]=s[1][i]=0;
        for(int i=1;i<=n;i++)
            s[a[i].c][a[i].l]++,s[a[i].c][a[i].r+1]--;
        for(int i=1;i<=n*2;i++)
            for(int j=0;j<2;j++)
                s[j][i]+=s[j][i-1];
        for(int i=1;i<=n*2;i++)
            for(int j=0;j<2;j++)
                s[j][i]+=s[j][i-1];
        sort(a+1,a+n+1);
        int mx[2]={0,0};
        int ans=0;
        g[0].clear();
        g[1].clear();
        for(int i=1;i<=n;i++)
        {
            if(!(s[a[i].c^1][a[i].r]-s[a[i].c^1][a[i].l-1]))
            {
                ans++;
                continue;
            }
            if(mx[a[i].c]>=a[i].r)
                continue;
            g[a[i].c].push_back(a[i]);
            mx[a[i].c]=a[i].r;
        }
        for(int i=0,j=0,k=0;i<g[0].size();i++)
        {
            while(j+1<g[1].size()&&g[1][j+1].r<g[0][i].l)
                j++;
            while(k<g[1].size()&&g[1][k].l<=g[0][i].r)
                k++;
            //j~k-1
            L[i+1]=j+g[0].size()+1;
            R[i+1]=k+g[0].size();
        }
        for(int i=0,j=0,k=0;i<g[1].size();i++)
        {
            while(j+1<g[0].size()&&g[0][j+1].r<g[1][i].l)
                j++;
            while(k<g[0].size()&&g[0][k].l<=g[1][i].r)
                k++;
            //j~k-1
            L[i+1+g[0].size()]=j+1;
            R[i+1+g[0].size()]=k;
        }
        for(int i=1;i<=g[0].size()+g[1].size()+1;i++)
            vis[i]=0,fa[i]=i;
        int x=g[0].size()+g[1].size();
        for(int i=1;i<=x;i++)
        {
            if(vis[i])
                continue;
            ans++;
            q.push(i);
            fa[find(i)]=find(i+1);
            vis[i]=1;
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(int i=find(L[x]);i<=R[x];i=find(i))
                {
                    q.push(i);
                    vis[i]=1;
                    fa[find(i)]=find(i+1);
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*

1
10
1 8 9
0 8 9
0 1 5
0 6 9
1 7 8
0 6 7
0 2 4
1 1 1
1 3 4
0 4 10
2
5
0 590307427 625396934
1 924313168 979650811
0 210171217 390947728
1 25975616 346645372
1 184857587 391530899
14
0 82 99
1 76 98
1 14 56
1 65 72
1 81 87
0 63 71
0 58 91
0 98 99
1 44 47
1 75 84
0 56 96
0 100 100
1 87 90
1 82 84
*/