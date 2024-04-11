#include<bits/stdc++.h>
#define db double
#define rint register int
using namespace std;

struct cp{
  db x,y;
};
inline cp operator + (const cp u,const cp v){
  return (cp){u.x+v.x,u.y+v.y};
}
inline cp operator - (const cp u,const cp v){
  return (cp){u.x-v.x,u.y-v.y};
}
inline cp operator * (const cp u,const cp v){
  return (cp){u.x*v.x-u.y*v.y , u.x*v.y+u.y*v.x};
}
namespace FFT{
  
  db pi=atan2(0,-1), pipi=pi*2;
  cp W[1050000]; int dp[1050000];
  #define N (1<<n)
  
  void fft(cp *a,int n){
    dp[0]=0;
    for (rint i=1,j;i<N;++i){
      dp[i]= j= i&1? dp[i-1]+(1<<n-1): dp[i>>1]>>1;
      if (i<j) swap(a[i],a[j]);
    }
    for (int b=0;b<n;++b){
      int len1=1<<b, len2=1<<b+1; int w, w0=N/len2;
      for (int i=0;i<N;i+=len2){
        cp *l=a+i, *r=a+i+len1, tmp; w=0;
        for (rint j=0;j<len1;++j){
          tmp=r[j]*W[w];
          r[j]=l[j]-tmp;
          l[j]=l[j]+tmp;
          w+=w0;
        }
      }
    }
  }
  
  void realmain(cp *a,cp *b,int la,int lb){ // a: [0,la]  b: [0,lb]
    int n=0; for (;la+lb>=N;) ++n;
    for (rint i=la+1;i<N;++i) a[i]=(cp){0,0};
    for (rint i=lb+1;i<N;++i) b[i]=(cp){0,0};
    W[0]=(cp){1.,0.};
    for (int i=1;i<N;++i){
      if ((i&3)==1) W[i]=(cp){cos(pipi/N*i),sin(pipi/N*i)};
      else W[i]=W[i-1]*W[1];
    }
    fft(a,n); fft(b,n);
    for (int i=0;i<N;++i) a[i]=a[i]*b[i];
    reverse(a+1,a+N); fft(a,n);
    for (int i=0;i<N;++i) a[i].x/=N, a[i].y/=N;
  }
}

int T, n, m, x, fl[1050000];
cp a[1050000], b[1050000];
char s[1050000];
vector<int>ans;

int main(){
  for (scanf("%d",&T);T--;){
    scanf("%d",&n); scanf("%s",s);
    memset(fl,0,sizeof (int)*(n+3));
    for (int i=0;i<n;++i){
      a[i]= s[i]=='V'? (cp){1,0}: (cp){0,0};
      b[i]= s[i]=='K'? (cp){1,0}: (cp){0,0};
    }
    reverse(b,b+n);
    FFT::realmain(a,b,n-1,n-1);
    reverse(a,a+n);
    for (int i=1;i<=n;++i){
      for (int j=i;j<n;j+=i)
        fl[i]|=a[j].x>0.5;
    }
    for (int i=0;i<n;++i){
      a[i]= s[i]=='K'? (cp){1,0}: (cp){0,0};
      b[i]= s[i]=='V'? (cp){1,0}: (cp){0,0};
    }
    reverse(b,b+n);
    FFT::realmain(a,b,n-1,n-1);
    reverse(a,a+n);
    for (int i=1;i<=n;++i){
      for (int j=i;j<n;j+=i)
        fl[i]|=a[j].x>0.5;
    }
    ans.clear();
    for (int i=1;i<=n;++i) if (!fl[i]) ans.push_back(i);
    cout<<ans.size()<<endl;
    for (auto o:ans) printf("%d ",o); puts("");
  }
}