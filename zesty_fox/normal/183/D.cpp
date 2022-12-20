#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>

const int N=3010,M=310;
int n,m,cnt[N];
double p[N][M],f[M][N],g[N],ans;
double sum[M],sum1[M],val[M],c[M];
void update(int id){
    memcpy(g,f[id],sizeof(double)*(n+3));
    f[id][0]=0;
    for(int i=1;i<=n;i++) f[id][i]=f[id][i-1]*(1-p[i][id])+g[i-1]*p[i][id];
    cnt[id]++;sum[id]+=cnt[id]*f[id][n],sum1[id]+=f[id][n];
    double tmp=sum[id]+cnt[id]*(1-sum1[id]);
    c[id]=tmp-val[id],val[id]=tmp;
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) p[i][j]=rdi()/1000.0;
    }
    for(int i=1;i<=m;i++){
        f[i][0]=1;
        for(int j=1;j<=n;j++) f[i][j]=f[i][j-1]*(1-p[j][i]);
        sum1[i]=f[i][n],update(i);
    }
    for(int i=1;i<=n;i++){
        int maxn=-1;
        for(int j=1;j<=m;j++) if(c[maxn]<c[j]) maxn=j;
        if(maxn<0) break;
        ans+=c[maxn],update(maxn);
    }
    printf("%.9lf\n",ans);
    return 0;
}