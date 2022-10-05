#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

ll bas1, bas2, mod1, mod2, hasinit;
bool ispri(int x){
  for (int i=2;i*i<=x;++i) if (x%i==0) return 0;
  return 1;
}
int ranpri(int l,int r){
  for (;;){
    ll tmp= rand()%10000*(1e8) +rand()%10000*(1e4) +rand()%10000;
    tmp= tmp%(r-l+1)+l;
    if (ispri(tmp)) return tmp;
  }
}
struct HASH{
  static const int mxlen=2e5;
  int h1[mxlen+233], h2[mxlen+233], p1[mxlen+233], p2[mxlen+233];
  
  void init(char *s,int n){  // s: [1,n]
    if (!hasinit){
      srand(time(0)); hasinit=1;
      bas1=ranpri(1e3,1e4); bas2=ranpri(1e3,1e4);
      mod1=ranpri(5e8,1e9); mod2=ranpri(5e8,1e9);
    }
    
    h1[0]=h2[0]=0; p1[0]=p2[0]=1;
    for (int i=1;i<=n;++i){
      h1[i]= (h1[i-1]*bas1+s[i])%mod1;
      h2[i]= (h2[i-1]*bas2+s[i])%mod2;
      p1[i]= p1[i-1]*bas1%mod1;
      p2[i]= p2[i-1]*bas2%mod2;
    }
  }

  pii gay(int l,int r){  //   [l,r]
    int res1= (h1[r]-(ll)h1[l-1]*p1[r-l+1]%mod1+mod1)%mod1;
    int res2= (h2[r]-(ll)h2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
    return (pii){res1,res2};
  }
}hs, ht;

char s[101000], t[101000]; int n, m, f[101000];
vector<int>S;

int lcp(int i){
  int l=1, r=min(n-i+1,m), res=0;
  for (;l<=r;){
    int mid=l+r>>1;
    if (hs.gay(i,i+mid-1)==ht.gay(1,1+mid-1)) res=mid, l=mid+1;
    else r=mid-1;
  }
  return res;
}
int fin(int x){
  return upper_bound(S.begin(),S.end(),x)-S.begin();
}

int main(){
  cin>>s+1>>t+1; n=strlen(s+1); m=strlen(t+1);
  hs.init(s,n); ht.init(t,m);
  {
    f[0]=-1; f[1]=0; int p=0;
    for (int i=2;i<=m;++i){
      while (p!=-1&&t[p+1]!=t[i]) p=f[p];
      f[i]=++p; if (p) S.push_back(i-p);
    }
  }
  sort(S.begin(),S.end());
  ll ans=(ll)n*m;
  for (int i=1;i<=n;++i){
    int l=lcp(i+1);// cerr<<' '<<l<<endl;
    ans-=fin(l);
  }
  cout<<ans<<endl;
}