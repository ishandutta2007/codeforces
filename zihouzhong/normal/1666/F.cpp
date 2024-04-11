#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int Inc(int x,int y){
  return x+=y-P,x+(x>>31&P);
}
void Add(int&x,int y){
  x+=y-P,x+=x>>31&P;
}
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=5010;
int n,A[maxn],cnt[maxn];

int C[maxn][maxn];
int dp[maxn][maxn/2],tmp[maxn][maxn/2];

void solve(){
  mem(cnt);
  cin>>n;
  rep(i,1,n)cin>>A[i],cnt[A[i]]++;
  int dt=1;
  rep(i,0,n)mem(dp[i]),mem(tmp[i]);
  A[0]=A[n+1]=-1;
//  rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
  rep(i,1,n)if(A[i]!=A[i+1]){
    int x=1;
    rep(p,1,i-1){
      int q=p;
      while(q<i-1&&A[q+1]==A[p])q++;
      x=1ll*x*C[max(0,n/2-(n-q+1-(n/2))+1-(A[p]==A[i])*2)][q-p+1]%P;
      p=q;
    }
//    rep(p,1,i-1){
//      x=1ll*x*max(0,n/2-(n-p+1-(n/2))+1)%P;
//    }
    dp[i][1]=x;
    int p,q;
    p=i;
    q=p;
    while(q>1&&A[q-1]==A[p])q--;
    rep(j,2,min(i,n/2)){
      tmp[i][j]=1ll*C[max(0,(n/2-j)-(n-p+1-(n/2-j+1))+1)][p-q+1]*(tmp[q-1][j]+dp[q-1][j-1])%P;
    }
    p=i-1;
    q=p;
    while(q>1&&A[q-1]==A[p])q--;
    rep(j,2,min(i,n/2)){
      Add(dp[i][j],1ll*C[max(0,(n/2-j)-(n-p+1-(n/2-j+1))+1-(A[p]==A[i]))][p-q+1]*(tmp[q-1][j]+dp[q-1][j-1])%P);
    }
    rep(j,2,min(i,n/2)){
      Add(dp[i][j],dp[i-1][j-1]);
//      int x=1;
//      per(p,i-1,1){
//        int q=p;
//        while(q>1&&A[q-1]==A[p])q--;
//        x=1ll*x*C[max(0,(n/2-j)-(n-p+1-(n/2-j+1))+1-(A[p]==A[i]))][p-q+1]%P;
//        p=q;
//        Add(dp[i][j],1ll*x*dp[p-1][j-1]%P);
//      }
//      rep(k,0,i-1)if(A[k]!=A[k+1]){
//        int x=dp[k][j-1];
//        if(!x)continue;
//        rep(p,k+1,i-1){
//          int q=p;
//          while(q<i-1&&A[q+1]==A[p])q++;
//          x=1ll*x*C[max(0,(n/2-j)-(n-q+1-(n/2-j+1))+1-(A[p]==A[i]))][q-p+1]%P;
//          p=q;
////          x=1ll*x*max(0,(n/2-j)-(n-p+1-(n/2-j+1))+1)%P;
//        }
//        Add(dp[i][j],x);
//      }
    }
//    rep(j,1,i)printf("%d %d : %d\n",i,j,dp[i][j]);
  }
  int ans=dp[n][n/2];
  ans=1ll*ans*dt%P;
  cout<<ans<<endl;
}

signed main(){
  rep(i,0,maxn-1){
    C[i][0]=1;
    rep(j,1,i)C[i][j]=Inc(C[i-1][j],C[i-1][j-1]);
  }
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}

/*
1
10
1 1 1 2 4 4 5 5 6 7

*/