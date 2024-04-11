#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=75,M=310;

int n,m,cnt,col[M],e[N][N];

int a[M*50][M];
bool Gauss(){
   for(int r=1,i=1;r<=cnt&&i<=m;i++,r++){
      if(!a[r][i]){
         bool flg=0;
         for(int j=r+1;j<=cnt;j++)
            if(a[j][i]) {flg=1;swap(a[r],a[j]);break;}
         if(!flg) {r--;continue;}
      }
      for(int j=1;j<=cnt;j++){
         if(j==r||!a[j][i]) continue;
         int mul=a[j][i]*a[r][i]%3;
         for(int k=i;k<=m+1;k++) a[j][k]=(a[j][k]-mul*a[r][k]%3+3)%3;
      }
   }
   for(int i=1;i<=m;i++){
      int id=0;
      for(int j=1;j<=cnt;j++) if(a[j][i]) {id=j;break;}
      if(!id) col[i]=3;
      else{
         col[i]=a[id][m+1]*a[id][i]%3;
         if(!col[i]) col[i]=3;
         for(int j=1;j<=cnt;j++){
            (a[j][m+1]+=(3-a[j][i]*col[i]%3))%=3;
            a[j][i]=0;
         }
      }
   }
   for(int i=1;i<=cnt;i++){
      int sum=0;
      for(int j=1;j<=m;j++) sum+=a[i][j]*col[j];
      sum%=3;
      if(sum!=a[i][m+1]) return false;
   }
   return true;
}

void clear(){
   memset(a,0,sizeof(a));
   memset(col,0,sizeof(col));
   memset(e,0,sizeof(e));
   cnt=0;
}

void solve(){
   n=rdi(),m=rdi();
   for(int i=1;i<=m;i++){
      int x=rdi(),y=rdi(),z=rdi();
      if(x>y) swap(x,y);
      e[x][y]=i;
      if(z!=-1) ++cnt,a[cnt][i]=1,a[cnt][m+1]=z;
   }
   for(int x=1;x<=n;x++){
      for(int y=x+1;y<=n;y++){
         for(int z=y+1;z<=n;z++){
            if(!e[x][y]||!e[y][z]||!e[x][z]) continue;
            ++cnt;
            for(int i:{e[x][y],e[y][z],e[x][z]}) a[cnt][i]=1;
         }
      }
   }
   if(Gauss()){
      for(int i=1;i<=m;i++) cout<<col[i]<<' ';
      cout<<endl;
   }
   else cout<<-1<<endl;
   clear();
}

int T;
int main(){
#ifdef LOCAL
   freopen(".in","r",stdin);
   freopen(".out","w",stdout);
#endif
   T=rdi();
   while(T--) solve();
   return 0;
}