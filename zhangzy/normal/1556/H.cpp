#include<bits/stdc++.h>
using namespace std;


int n, k, d[55], G[55][55];

int bas[55][55], fa[55], las[55], fucked[55][55];
int ans=1e9;

int GF(int x){
    return x==fa[x]? x: fa[x]=GF(fa[x]);
}

#define pii pair<int,int>
#define fi first
#define se second

namespace nz{
    vector<int>G[3030];
    int st=3001, en=3002, val[3030];
    
    void init(){
        for (int i=0;i<=en;++i) G[i].clear();
    }
    void adde(int x,int y){
        G[x].push_back(y);
    }

    int d[3030], in[3030], pre[3030];
    int fuck(){
        memset(d,33,sizeof d);
        memset(in,0,sizeof in);
        memset(pre,0,sizeof pre);
        d[st]=0; queue<int>q; q.push(st);
        // puts("A");
        for (int tim=0;q.size();){
            // if (++tim>1000000){
            //     for (int p=q.front();p;p=pre[p]) printf(" %d",p);
            //     exit(0);
            // }
            int x=q.front(); q.pop(); in[x]=0;
            for (auto y:G[x]){
                int z=d[x]+val[y];
                if (z<d[y]){
                    d[y]=z; pre[y]=x;
                    if (!in[y]) q.push(y), in[y]=1;
                }
            }
        }
        // puts("B");
        int sum=0;
        for (int p=en;p;p=pre[p]){
            if (p!=st&&p!=en){
                int i=(p-1)/n, j=(p-1)%n+1;
                bas[i][j]^=1;
            }
            sum+=val[p];
        }
        // if (sum!=d[en]){
        //     cout<<sum<<' '<<d[en];
        //     exit(0);
        // }
        return d[en];
    }
}

int ID(int i,int j){
    return i*n+j;
}
int ID(pii p){
    return ID(p.fi,p.se);
}

void supermain(){
    for (int i=1;i<=k;++i) fa[i]=i, las[i]=d[i];
    int nowsum=0, aim=n-1;
    for (int i=1;i<=k;++i)
        for (int j=i+1;j<=k;++j)
            if (bas[i][j]){
                nowsum+=G[i][j];
                if (GF(i)==GF(j)) return;
                fa[GF(i)]=GF(j);
                --las[i]; --las[j]; --aim;
                if (las[i]<0||las[j]<0) return;
            }
    for (;aim--;){
        
        // for (int i=1;i<=n;++i){
        //     for (int j=1;j<=n;++j){
        //         printf(" %d",bas[i][j]);
        //     }puts("");
        // }
        nz::init();
        for (int i=1;i<=n;++i) fa[i]=i, las[i]=d[i];
        vector<pii>vec, vecall;
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
                if (bas[i][j]){
                    if (i<=k) --las[i];
                    if (j<=k) --las[j];
                    fa[GF(i)]=GF(j);
                    vecall.push_back({i,j});
                    if (j>k) vec.push_back({i,j});
                }
        
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
                nz::val[ID(i,j)]= bas[i][j]? -G[i][j]: G[i][j];
        
        memset(fucked,0,sizeof fucked);
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j){
                if (j<=k) continue;
                if (bas[i][j]) continue;
                if (GF(i)!=GF(j)) nz::adde(nz::st,ID(i,j)), fucked[i][j]=1;
                if (i>k||las[i]>0) nz::adde(ID(i,j),nz::en);
            }
        for (auto o:vec){
            for (int i=1;i<=n;++i) fa[i]=i;
            for (auto p:vecall) if (p!=o) fa[GF(p.fi)]=GF(p.se);
            for (int i=1;i<=n;++i)
                for (int j=i+1;j<=n;++j){
                    if (j<=k) continue;
                    if (bas[i][j]) continue;
                    if (GF(i)!=GF(j)&&!fucked[i][j]) nz::adde(ID(o),ID(i,j));
                    if (i<=k&&las[i]==0&&i==o.fi) nz::adde(ID(i,j),ID(o));
                }
        }
        nowsum += nz::fuck();
        if (nowsum>1e8) return;
    }
    ans=min(ans,nowsum);
    // if (nowsum==93){
    //     int tmp=0;
    //     for (int i=1;i<=n;++i){
    //         for (int j=1;j<=n;++j){
    //             printf(" %d",bas[i][j]);
    //             if (i<j) tmp+=bas[i][j]*G[i][j];
    //         }puts("");
    //     }
    //     cout<<tmp<<endl;
    // }
}

int main(){
    cin>>n>>k;
    for (int i=1;i<=k;++i) cin>>d[i];
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            cin>>G[i][j];
            G[j][i]=G[i][j];
        }
    }
    for (int S=0;S<(1<<k*(k-1)/2);++S){
        memset(bas,0,sizeof bas);
        int cnt=0;
        for (int i=1;i<=k;++i)
            for (int j=i+1;j<=k;++j){
                int c=S>>cnt&1;
                cnt+=1;
                bas[i][j]=bas[j][i]=c;
            }
        supermain();
    }
    cout<<ans<<endl;
}