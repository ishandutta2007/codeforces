#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n;
int tot;
int used[maxn<<1];
int head[maxn],edge[maxn<<1],nxt[maxn<<1];

void join(int u,int v)  {
    edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

int sz[maxn];

int F[maxn],id[maxn];

int dfs(int i,int fa) {
    sz[i]=0;
    for (int k=head[i];~k;k=nxt[k]) {
        int j=edge[k];
        if (used[k]||fa==j) continue;
        sz[i]+=dfs(j,i);
    }
    return ++sz[i];
}

vector<int> vert;

void find(int i,int fa,int x,int y)    {
    for (int k=head[i];~k;k=nxt[k]) {
        int j=edge[k];
        if (used[k]||fa==j) continue;
        // cout<<i<<" -> "<<j<<" "<<x<<" "<<y<<" ~ "<<sz[j]<<endl;
        if (sz[j]==x) vert.push_back(k);
        if (sz[j]==y) vert.push_back(k^1);
        find(j,i,x,y);
    }
}

bool solve(int i,int k)   {
    if (k<0) return 1;
    dfs(i,0);
    assert(sz[i]==F[k]);
    // cout<<"solve:"<<i<<" "<<F[k]<<endl;
    if (sz[i]==1) {
        return 1;
    } else  {
        vert.clear();

        find(i,0,F[k-2],F[k-1]);

        assert(vert.size()<=2);
        if (!vert.size()) return 0;
        for (auto p:vert)
            used[p]=used[p^1]=1;
        if (vert.size()==1) {
            int a=edge[vert[0]],b=edge[vert[0]^1];
            return solve(a,k-2)&&solve(b,k-1);
        } else  {
            
            // cout<<"cut:"<<edge[vert[0]]<<" "<<edge[vert[0]^1]<<endl;
            // cout<<"cut:"<<edge[vert[1]]<<" "<<edge[vert[1]^1]<<endl;

            int a=edge[vert[0]],b=edge[vert[1]],c=edge[vert[0]^1];

            bool flag=solve(a,k-2);
            flag&=solve(b,k-2);
            flag&=solve(c,k-3);

            return flag;
        }
    }
}

int main()  {
    F[0]=F[1]=1;
    for (int i=1;F[i]<maxn;++i) {
        id[F[i]]=i;
        F[i+1]=F[i]+F[i-1];
    }

    tot=0;
    memset(head,-1,sizeof(head));

    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v);
    }

    if (!id[n])
        puts("NO");
    else
        puts(solve(1,id[n])?"YES":"NO");
    return 0;
}