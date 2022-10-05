#include<bits/stdc++.h>
using namespace std;
#define db double

int n, w[202000];
#define pii pair<int,int>
#define fi first
#define se second
vector<pii>G[202000];

int die[202000], sz[202000];
int anp; db ans=1e100;

db sb(int x,int fff,int d){
    db res=w[x]*pow(d,1.5);
    for (auto o:G[x]){
        int y=o.fi; if (y==fff) continue;
        res+=sb(y,x,d+o.se);
    }
    return res;
}
void calcall(int x){
    db sum=sb(x,0,0);
    if (sum<ans) ans=sum, anp=x;
}

db dfs(int x,int fff,int d){
    db res=w[x]*pow(d,0.5)*1.5;
    for (auto o:G[x]){
        int y=o.fi; if (y==fff) continue;
        res+=dfs(y,x,d+o.se);
    }
    return res;
}
void gaosz(int x,int fff){
    sz[x]=1;
    for (auto o:G[x]){
        int y=o.fi; if (y==fff||die[y]) continue;
        gaosz(y,x); sz[x]+=sz[y];
    }
}
int gaort(int x,int fff,int tot){
    for (auto o:G[x]){
        int y=o.fi; if (y==fff||die[y]) continue;
        if (sz[y]*2>=tot) return gaort(y,x,tot);
    }
    return x;
}

void doit(int x){
    calcall(x);

    die[x]=1;

    db mn=1e100; int mnp=0;
    for (auto o:G[x]){
        int y=o.fi; if (die[y]) continue;
        db t=-dfs(y,x,o.se);
        if (t<mn) mn=t, mnp=y;
    }
    
    if (mnp){
        //printf(" %d %d\n",mnp,x);
        gaosz(mnp,x);
        doit(gaort(mnp,x,sz[mnp]));
    }
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) scanf("%d",&w[i]);
    for (int i=1;i<n;++i){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    doit(1);
    printf("%d %.10lf\n",anp,ans);
}