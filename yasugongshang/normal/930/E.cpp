#include<cstdio>
#include<cctype>
#include<algorithm>
using int64=long long;
inline int getint() {
    register char ch;
    while(!isdigit(ch=getchar()));
    register int x=ch^'0';
    while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
    return x;
}
constexpr int N=1e5,mod=1e9+7;
std::pair<int,int> p[2][N];
int tmp[N*4+2],min[2][N*4+2],f[N*4+2][3];
inline int power(int a,int k) {
    int ret=1;
    for(;k;k>>=1) {
        if(k&1) ret=(int64)ret*a%mod;
        a=(int64)a*a%mod;
    }
    return ret;
}
int main() {
    const int k=getint(),n=getint(),m=getint();
    int lim=0;
    for(register int i=0;i<n;i++) {
        tmp[++lim]=p[0][i].first=getint()-1;
        tmp[++lim]=p[0][i].second=getint();
    }
    for(register int i=0;i<m;i++) {
        tmp[++lim]=p[1][i].first=getint()-1;
        tmp[++lim]=p[1][i].second=getint();
    }
    tmp[++lim]=k;
    std::sort(&tmp[0],&tmp[lim]+1);
    lim=std::unique(&tmp[0],&tmp[lim]+1)-&tmp[1];
    for(register int i=0;i<=lim;i++) {
        min[0][i]=min[1][i]=lim+1;
    }
    for(register int i=0;i<n;i++) {
        p[0][i].first=std::lower_bound(&tmp[0],&tmp[lim]+1,p[0][i].first)-tmp;
        p[0][i].second=std::lower_bound(&tmp[0],&tmp[lim]+1,p[0][i].second)-tmp;
        min[0][p[0][i].first]=std::min(min[0][p[0][i].first],p[0][i].second);
    }
    for(register int i=0;i<m;i++) {
        p[1][i].first=std::lower_bound(&tmp[0],&tmp[lim]+1,p[1][i].first)-tmp;
        p[1][i].second=std::lower_bound(&tmp[0],&tmp[lim]+1,p[1][i].second)-tmp;
        min[1][p[1][i].first]=std::min(min[1][p[1][i].first],p[1][i].second);
    }
    for(register int i=lim;i;i--) {
        min[0][i-1]=std::min(min[0][i-1],min[0][i]);
        min[1][i-1]=std::min(min[1][i-1],min[1][i]);
    }
    f[lim][0]=f[lim][1]=f[lim][2]=1;
    for(register int i=lim-1;i>=0;i--) {
        int g[3];
        g[0]=(f[i+1][0]-f[min[0][i]][0]+mod)%mod;
        g[1]=(f[i+1][1]-f[min[1][i]][1]+mod)%mod;
        g[2]=(int64)f[i+1][2]*((power(2,tmp[i+1]-tmp[i])-2+mod)%mod)%mod;
        f[i][0]=((int64)f[i+1][0]+g[1]+g[2])%mod;
        f[i][1]=((int64)f[i+1][1]+g[0]+g[2])%mod;
        f[i][2]=((int64)g[0]+g[1]+g[2])%mod;
    }
    printf("%d\n",f[0][2]);
    return 0;
}