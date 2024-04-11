#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
struct HASH{
  ll bas1, bas2, mod1, mod2;
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
  
  static const int mxlen=2e5;
  int h1[mxlen+233], h2[mxlen+233], p1[mxlen+233], p2[mxlen+233];
  
  void init(char *s,int n){  // s: [1,n]
    srand(time(0));
    bas1=ranpri(1e3,1e4); bas2=ranpri(1e3,1e4);
    mod1=ranpri(5e8,1e9); mod2=ranpri(5e8,1e9);
    
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
}has[26];

char s[202000], t[202000];
int n, T, x, y, l;

vector<pii> gao(int l,int r){
  vector<pii>S; S.clear();
  for (int i=0;i<26;++i) S.push_back(has[i].gay(l,r));
  sort(S.begin(),S.end());
  return S;
}

int main(){
  scanf("%d%d%s",&n,&T,s+1);
  for (char c='a';c<='z';++c){
    for (int i=1;i<=n;++i) t[i]= s[i]==c;
    has[c-'a'].init(t,n);
  }
  for (;T--;){
    scanf("%d%d%d",&x,&y,&l);
    puts(gao(x,x+l-1)==gao(y,y+l-1)? "YES": "NO");
  }
}