#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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

const int N=255,MOD=1e9+7;

int n,m,k;

i64 qpow(i64 x,i64 y=MOD-2){
    i64 res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

struct Node{
    int a[N];
    int& operator [] (int id) {return a[id];}
    const int& operator [] (int id) const{return a[id];}
    Node& operator += (const Node &b){
        for(int i=0;i<m-1;i++) ((a[i]+=b[i])>=MOD?a[i]-=MOD:0);
        return *this;
    }
    Node operator + (const Node &b){
        Node tmp(*this);
        return tmp+=b;
    }

    Node& operator -= (const Node &b){
        for(int i=0;i<m-1;i++) ((a[i]+=(MOD-b[i]))>=MOD?a[i]-=MOD:0);
        return *this;
    }
    Node operator - (const Node &b){
        Node tmp(*this);
        return tmp-=b;
    }

    Node& operator *= (i64 x){
        for(int i=0;i<m-1;i++) a[i]=x*a[i]%MOD;
        return *this;
    }
    Node operator * (i64 x){
        Node tmp(*this);
        return tmp*=x;
    }
}f[N][N],s1[N][N],s2[N][N],v[N];

i64 inv[N];

void init(){
    for(int i=1;i<=m;i++) inv[i]=qpow(i);

    for(int i=1;i<=m;i++) f[i][1][m-2]=f[i][i][m-2]=i;
    for(int i=3;i<=m;i++) f[i][2][i-3]=1;

    for(int j=1;j<=m;j++){
        s1[j][1]=s1[j-1][1]+f[j][1],s2[j][1]=f[j][1];
        s1[j][j]=f[j][j],s2[j][j]=s2[j-1][j-1]+f[j][j];
    }

    for(int j=2;j<m;j++){
        for(int i=j+1;i<=m;i++){
            s1[i][j]=s1[i-1][j]+f[i][j],s2[i][j]=s2[i-1][j-1]+f[i][j];
            f[i+1][j+1]=f[i][j]-f[i+1][j]*((m-i)*(i+1-j)*inv[m]%MOD*inv[i+1]%MOD)-
                    (s2[i-1][j-1]+s1[i-1][j])*(i*inv[m]%MOD*inv[i-1]%MOD);
            if(i==m){
                v[j-2]=f[i+1][j+1],v[j-2][m-2]=MOD-v[j-2][m-2];
                break;
            }
            f[i+1][j+1]*=(m*(i+1)*inv[m-i]%MOD*inv[j]%MOD);
        }
    }
}

i64 res[N];
void gauss(){
    for(int i=0;i<m-2;i++){
        if(!v[i][i])
            for(int j=i+1;j<m-2;j++)
                if(v[j][i]) {swap(v[i],v[j]);break;}
        for(int j=0;j<m-2;j++){
            if(i==j) continue;
            v[j]-=v[i]*(v[j][i]*qpow(v[i][i])%MOD);
        }
    }
    for(int i=0;i<n-2;i++) res[i]=v[i][m-2]*qpow(v[i][i])%MOD;
}

int main(){
    n=rdi(),k=rdi(),m=rdi();
    if(k==1||k==n) {cout<<n<<'\n';return 0;}
    init();gauss();
    i64 ans=0;
    for(int i=0;i<m-2;i++) ans+=res[i]*f[n][k][i]%MOD;
    ans+=f[n][k][m-2];
    ans=(ans%MOD+MOD)%MOD;cout<<ans<<endl;
    return 0;
}