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
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=2e5+10;

int n,m,S;

vi E[maxn];

void solve(){
  cin>>n>>m>>S;
  rep(i,1,m){
    int u=read(),v=read();
    E[u].pb(v);
  }
  rep(lev,0,17){
    static int col[maxn],Q[maxn],pre[maxn];
    mem(pre);
    pre[S]=-1;
    int l=1,r=0;
    int ct1=0,ct2=0;
    for(int u:E[S]){
      Q[++r]=u;
      pre[u]=S;
      if(u>>lev&1){
        col[u]=1;
        ct1++;
      }else{
        col[u]=2;
        ct2++;
      }
    }
    if(!ct1||!ct2)continue;
    while(l<=r){
      int u=Q[l++];
      for(int v:E[u]){
        if(!pre[v]){
          pre[v]=u,col[v]=col[u],Q[++r]=v;
        }else if(v!=S&&col[v]!=col[u]){
          puts("Possible");
          vi vec;
          for(int cur=v;~pre[cur];cur=pre[cur]){
            vec.push_back(cur);
          }
          vec.push_back(S);
          reverse(ALL(vec));
          cout<<vec.size()<<endl;for(int x:vec)printf("%d ",x);puts("");
          vec.clear();
          pre[v]=u;
          for(int cur=v;~pre[cur];cur=pre[cur]){
            vec.push_back(cur);
          }
          vec.push_back(S);
          reverse(ALL(vec));
          cout<<vec.size()<<endl;for(int x:vec)printf("%d ",x);puts("");
          return;
        }
      }
    }
  }
  puts("Impossible");
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}