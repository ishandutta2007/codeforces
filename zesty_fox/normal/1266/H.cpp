#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef __uint128_t u128;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=65;

const ll MOD1=9019283818374625387,MOD2=9019283818374625391;

ll qpow(ll x,ll y,ll MOD){
    ll res=1;
    while(y){
        if(y&1) res=(u128)res*x%(MOD==MOD1?MOD1:MOD2);
        x=(u128)x*x%(MOD==MOD1?MOD1:MOD2),y>>=1;
    }
    return res;
}

struct Num{
    u64 fi,se;
    Num(u64 a,u64 b):fi(a),se(b){}
    Num(u128 a,u128 b):fi(a),se(b){}
    Num(ll x=0){fi=x%MOD1,se=x%MOD2;}
};
Num operator * (Num a,Num b) {return {(u128)a.fi*b.fi%MOD1,(u128)a.se*b.se%MOD2};}
Num operator / (Num a,Num b) {return {(u128)a.fi*qpow(b.fi,MOD1-2,MOD1)%MOD1,(u128)a.se*qpow(b.se,MOD2-2,MOD2)%MOD2};}
Num operator + (Num a,Num b) {return {(a.fi+b.fi)%MOD1,(a.se+b.se)%MOD2};}
Num operator - (Num a,Num b) {return {(a.fi-b.fi+MOD1)%MOD1,(a.se-b.se+MOD2)%MOD2};}

int n,b[N],r[N];
vi R[N],B[N];

Num a[N][N];
vector<Num> xs;

void Gauss(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            Num mul=a[j][i]/a[i][i];xs.pb(mul);
            for(int k=1;k<=n;k++) a[j][k]=a[j][k]-a[i][k]*mul;
        }
    }
}

Num a1[N];
void Gauss1(){
    auto it=xs.begin();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            a1[j]=a1[j]-a1[i]*(*it++);
        }
    }
}

ll calc(int v,const string &s){
    ll res=0;
    static ll val[N];
    for(int i=1;i<=n;i++){
        Num x=a1[i]/a[i][i],y=x-(s[i-1]=='R');
        if(x.fi!=x.se||y.fi!=y.se) return -1;
        res+=x.fi+y.fi,val[i]=x.fi;
    }
    
    static int vis[N];
    for(int i=1;i<=n;i++){
        if(!val[i]) continue;
        for(int j=1;j<=n+1;j++) vis[j]=0;
        int x=i;
        while(!vis[x]){
            vis[x]=1,x=s[x-1]=='R'?r[x]:b[x];
            if(x>n) break;
        }
        if(!vis[v]) return -1;
    }
    return res;
}

int main(){
    n=rdi()-1;
    for(int i=1;i<=n;i++){
        b[i]=rdi(),r[i]=rdi();
        R[r[i]].pb(i),B[b[i]].pb(i);
    }

    for(int i=1;i<=n;i++){
        a[i][i]=2;
        for(auto r:R[i]) a[i][r]=a[i][r]-1;
        for(auto b:B[i]) a[i][b]=a[i][b]-1;
    }
    Gauss();

    int Q=rdi();
    while(Q--){
        int v;string s;cin>>v>>s;
        for(int i=1;i<=n;i++){
            a1[i]=(s[i-1]=='R')+(i==1)-(i==v);
            for(auto b:B[i]) a1[i]=a1[i]-(s[b-1]=='R');
        }
        Gauss1();
        cout<<calc(v,s)<<'\n';
    }
    return 0;
}