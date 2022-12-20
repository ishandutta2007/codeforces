#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=610,MOD=1e9+7;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int n,m,val[N];
int c[2],a[2][N],rk[2][N];
i64 s[2][N][N],s1[2][N][N],s2[N][N],inv[2][N],pw2[N];

void init(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        val[i]=rdi();
        a[val[i]<0][++c[val[i]<0]]=val[i];
    }
    // sort by absolute value (descending order)
    sort(a[0]+1,a[0]+c[0]+1,greater<>());
    sort(a[1]+1,a[1]+c[1]+1);

    pw2[0]=1;
    for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%MOD;

    for(int p=0;p<=1;p++)
        for(int i=1;i<=c[p];i++)
            inv[p][i]=qpow(a[p][i]);
    for(int i=1,pos=1,r=1;i<=c[0]+1;i++){
        while(pos<=c[1]&&-a[1][pos]>a[0][i])
            rk[1][pos++]=r++;
        if(i<=c[0]) 
            rk[0][i]=r++;
    }

    for(int p=0;p<=1;p++){
        s[p][0][0]=s1[p][0][0]=1;
        for(int i=1;i<=c[p];i++){
            s[p][i][0]=1;
            for(int j=1;j<=i;j++){
                s[p][i][j]=(s[p][i-1][j]+s[p][i-1][j-1]*a[p][i])%MOD;
                s1[p][i][j]=s[p][i-1][j-1]*a[p][i]%MOD;
            }
        }
    }

    for(int i=1;i<=c[0];i++){
        for(int j=1;j<=c[1];j++){
            i64 &sum=s2[i][j];sum=1;
            int st[2]={i,j},lim=max(rk[0][i],rk[1][j]);
            for(int p=0;p<2;p++)
                while(st[p]<=c[p]&&rk[p][st[p]]<=lim)
                    ++st[p];
            for(int u=st[0];u<=c[0];u++) // maximum positive number that not selected
                sum+=inv[1][j]*a[0][u]%MOD*pw2[c[0]-u]%MOD;
            for(int v=st[1];v<=c[1];v++) // minimum negative number that not selected
                sum+=inv[0][i]*a[1][v]%MOD*pw2[c[1]-v]%MOD;
            for(int cnt=st[0]+st[1],u=st[0],v=st[1]-1;cnt<=c[0]+c[1];cnt++){
                if(v<c[1]){
                    ++v;
                    while(u<=c[0]&&v>=st[1]&&(i64)a[0][i]*a[0][u]>=(i64)a[1][j]*a[1][v])
                        ++u,--v;
                }
                else{
                    ++u;
                    while(u>st[0]&&v<c[1]&&(i64)a[0][i]*a[0][u-1]<(i64)a[1][j]*a[1][v+1])
                        --u,++v;
                }
                sum+=inv[0][i]*inv[1][j]%MOD*pw2[n-cnt]%MOD
                    *(a[0][i]*(s[0][u-1][1]-s[0][max(st[0],cnt-c[1])-1][1])%MOD
                        +a[1][j]*(s[1][v][1]-s[1][max(st[1],cnt-c[0])-1][1])%MOD)%MOD;
            }
            sum%=MOD;
        }
    }
}

void solve(){
    i64 ans=0;
    for(int k=1;k<m;k++){ // number of negative numbers
        for(int i=m-k;i<=c[0];i++){ // minimum positive number
            for(int j=k;j<=c[1];j++){ // maximum negative number
                int lim=max(rk[0][i],rk[1][j]);
                i64 sum=(k&1?s2[i][j]:pw2[n-lim]);
                ans+=s1[0][i][m-k]*s1[1][j][k]%MOD*sum%MOD;
            }
        }
    }
    if(m&1){
        // all positive
        for(int i=m;i<=c[0];i++)
            ans+=s1[0][i][m]*pw2[n-rk[0][i]]%MOD;
        // all negative
        static i64 f[N][N],g[N][N];
        f[c[1]+1][0]=g[c[1]+1][0]=1;
        for(int i=c[1];i>=1;i--){
            g[i][0]=1;
            for(int j=1;j<=c[1]-i+1;j++){
                g[i][j]=(g[i+1][j]+g[i+1][j-1]*a[1][i])%MOD;
                f[i][j]=(g[i+1][j-1]*a[1][i])%MOD;
            }
            if(c[1]-i+1>=m)
                ans+=f[i][m]*pw2[i-1]%MOD;
        }
        for(int i=1,pos=1;i<=c[1];i++){
            while(pos<=c[0]&&rk[0][pos]<=rk[1][i]) ++pos;
            for(int j=pos;j<=c[0];j++)
                ans+=s1[1][i][m]*inv[1][i]%MOD*a[0][j]%MOD*pw2[n-i-j]%MOD;
        }
    }
    else{
        for(int p=0;p<=1;p++)
            for(int i=m;i<=c[p];i++)
                ans+=s1[p][i][m]*pw2[n-rk[p][i]]%MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<'\n';
}

int main(){
    init();
    solve();
    return 0;
}