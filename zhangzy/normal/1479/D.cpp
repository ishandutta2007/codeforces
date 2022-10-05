#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q, a[303000], df1[303000], df2[303000], dft, c[606000];
int fa[303000], FA[303000][20], dep[303000];
vector<int>G[303000];

void dfs(int x,int fff){
    df1[x]=++dft; c[dft]=a[x];
    dep[x]=dep[fff]+1;
    fa[x]=fff; FA[x][0]=fff;
    for (int i=1;i<=19;++i)
        FA[x][i]=FA[FA[x][i-1]][i-1];
    for (auto y:G[x]){
        if (y==fff) continue;
        dfs(y,x);
    }
    df2[x]=++dft; c[dft]=a[x];
}

int lca(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=19;i>=0;--i)
        if (dep[FA[x][i]]>=dep[y])
            x=FA[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;--i)
        if (FA[x][i]!=FA[y][i]){
            x=FA[x][i];
            y=FA[y][i];
        }
    return FA[x][0];
}

struct QUE{
    int u, v, lc, rc, id;
    int ty, lp, rp, elp;
}que[303000];

const int B=777;

bool cmp(QUE a,QUE b){
    return a.lp/B==b.lp/B? (a.lp/B%2? a.rp<b.rp: a.rp>b.rp): a.lp/B<b.lp/B;
}

const int S=512;
bitset<303000>b;
int sum[1000], L=1, R=0, ans[303000];

void cg(int c){
    if (b[c]){
        --sum[c/S];
    }else{
        ++sum[c/S];
    }
    b.flip(c);
}
int fuck(int l,int r){
    int bl=l/S, br=r/S;
    for (int i=bl;i<=br;++i){
        if (i==bl||i==br){
            for (int j=max(l,i*S);j<=min(r,(i+1)*S-1);++j)
                if (b[j]) return j;
        }else{
            if (sum[i]){
                for (int j=i*S;j<=(i+1)*S-1;++j)
                    if (b[j]) return j;
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>q;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<n;++i){
        int u, v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=q;++i){
        int u, v, lc, rc;
        scanf("%d%d%d%d",&u,&v,&lc,&rc);
        if (df1[u]>df1[v]) swap(u,v);
        QUE &q=que[i];
        q.u=u; q.v=v; q.lc=lc; q.rc=rc; q.id=i;
        int t=lca(u,v);
        if (t==u||t==v){
            q.ty=1; q.lp=df1[u]; q.rp=df1[v];
        }else{
            q.ty=2; q.lp=df2[u]; q.rp=df1[v]; q.elp=df1[t];
        }
    }
    sort(que+1,que+q+1,cmp);
    for (int i=1;i<=q;++i){
        QUE o=que[i];
        while (R<o.rp) ++R, cg(c[R]);
        while (L>o.lp) --L, cg(c[L]);
        while (R>o.rp) cg(c[R]), --R;
        while (L<o.lp) cg(c[L]), ++L;
        if (o.ty==2){
            cg(c[o.elp]);
        }
        ans[o.id]=fuck(o.lc,o.rc);
        if (o.ty==2){
            cg(c[o.elp]);
        }
    }
    for (int i=1;i<=q;++i) printf("%d\n",ans[i]);
}