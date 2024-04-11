#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second

int n, q, a[202000], pos[1001000];
bool np[1001000];
int fa[202000], bel[202000], blt; ll sz[202000], deg[202000];
int GF(int x){
    return fa[x]==x? x: fa[x]=GF(fa[x]);
}

int N=1e6+7;

vector<int>G[202000], bk[202000];
const int S=1000;
bitset<S+10>B[S+10], bitsb;

int main(){
    for (int i=2;i<=N;++i){
        if (!np[i]){
            for (int j=i+i;j<=N;j+=i)
                np[j]=1;
        }
    }

    cin>>n>>q;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]), pos[a[i]]=i, fa[i]=i;
    for (int i=2;i<=N;++i){
        if (np[i]) continue;
        int fi=0, t=0;
        for (int j=i;j<=N;j+=i){
            if (pos[j]){
                if (!fi) fi=pos[j];
                else fa[GF(pos[j])]=GF(fi);
            }
            if (pos[j-1]){
                t+=1;
            }
        }
        for (int j=i;j<=N;j+=i){
            if (pos[j]){
                deg[pos[j]]+=t;
            }
        }
    }
    for (int i=1;i<=n;++i) fa[i]=GF(i), sz[fa[i]]+=deg[i];
    vector<pii>vec;
    for (int i=1;i<=n;++i)
        if (fa[i]==i) vec.push_back({sz[i],i});
    sort(vec.begin(),vec.end(),greater<pii>());
    for (auto o:vec) bel[o.se]=++blt;
    for (int i=1;i<=n;++i) bel[i]=bel[fa[i]];

    // for (int i=1;i<=n;++i) printf(" %d",bel[i]); puts("");

    for (int i=2;i<=N;++i){
        if (np[i]) continue;
        vector<int>tmp;
        for (int j=i;j<=N;j+=i){
            if (pos[j-1]){
                tmp.push_back(pos[j-1]);
            }
        }
        if (!tmp.size()) continue;
        vector<int>tmp2;
        for (int j=i;j<=N;j+=i){
            if (pos[j]){
                tmp2.push_back(bel[pos[j]]);
            }
        }
        sort(tmp2.begin(),tmp2.end());
        tmp2.resize(unique(tmp2.begin(),tmp2.end())-tmp2.begin());
        for (auto u:tmp){
            for (auto v:tmp2){
                G[u].push_back(v);
            }
        }
    }
    for (int i=1;i<=n;++i){
        G[i].push_back(bel[i]);
        sort(G[i].begin(),G[i].end());
        G[i].resize(unique(G[i].begin(),G[i].end())-G[i].begin());
        for (auto o:G[i]){
            if (o<=S){
                bitsb[o]=1;
                B[o]|=bitsb;
            }else{
                bk[o].push_back(i);
            }
        }
        for (auto o:G[i])
            if (o<=S) bitsb[o]=0;
            else break;
                // if (B[3][2]){
                //     printf(" fuck %d\n",i);
                //     for (auto t:G[i]) printf("    %d",t);
                //     puts(""); return 0;
                // }
    }
    for (;q--;){
        int i, j;
        scanf("%d%d",&i,&j);
        if (bel[i]==bel[j]){
            puts("0");
        }else{
            int bi=bel[i], bj=bel[j];
            if (bi>bj) swap(bi,bj);
            if (bj<=S) puts(B[bj][bi]? "1": "2");
            else{
                int fl=0;
                for (auto o:bk[bj]){
                    int p=lower_bound(G[o].begin(),G[o].end(),bi)-G[o].begin();
                    if (p<G[o].size()&&G[o][p]==bi){
                        fl=1; break;
                    }
                }
                puts(fl? "1": "2");
            }
        }
    }
}