// LUOGU_RID: 94945903
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=155,INF=0x3f3f3f3f;

int n,v[N];
char s[N*10];

int g[N][N][N],f[N];

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++){
        v[i]=rdi();
        if(v[i]<0) v[i]=-INF;
    }
    scanf("%s",s+1);
    
    memset(g,0xc0,sizeof(g));

    for(int i=1;i<=n;i++)
        g[i][i][0]=v[1],g[i][i][1]=g[i][i-1][0]=0;

    for(int l=n;l>=1;l--){
        for(int r=l+1;r<=n;r++){
            for(int k=1;k<=r-l+1;k++){
                for(int p=l;p<r;p++)
                    g[l][r][k]=max({g[l][r][k],g[l][p][k]+g[p+1][r][0],g[l][p][0]+g[p+1][r][k]});
                if(s[l]==s[r]&&k>=2) g[l][r][k]=max(g[l][r][k],g[l+1][r-1][k-2]);
                g[l][r][0]=max(g[l][r][0],g[l][r][k]+v[k]);
            }
        }
    }

    f[0]=0;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        for(int j=1;j<=i;j++)
            f[i]=max(f[i],f[j-1]+g[j][i][0]);
    }
    cout<<f[n]<<'\n';
}

int main(){
    solve();
    return 0;
}