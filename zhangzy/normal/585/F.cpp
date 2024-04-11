#include<bits/stdc++.h>
using namespace std;

namespace ac{
  int ch[150000][26],fai[150000],cnt,dep[150000];
  int qu[150000],tot;
  void init(){
    memset(ch,0,sizeof ch);
    cnt=1; for (int i=0;i<26;++i) ch[0][i]=1;
    memset(fai,0,sizeof fai);
  }
  int add(char *s,int l=-1){
    if (l==-1) l=strlen(s); int p=1,c;
    for (int i=0;i<l;++i){
      c=s[i]-'0';
      if (!ch[p][c]) ch[p][c]=++cnt;
      p=ch[p][c]; dep[p]=i+1;
    }
    return p;
  }
  void build(){
    queue<int>q;
    for (;!q.empty();) q.pop();
    q.push(1); tot=0;
    int x,y;
    for (;!q.empty();){
      x=q.front(); q.pop(); qu[++tot]=x;
      for (int i=0;i<26;++i)
        if (y=ch[x][i]){
          fai[y]=ch[fai[x]][i];
          q.push(y);
        }else{
          ch[x][i]=ch[fai[x]][i];
        }
    }
  }
}

int n, m;
char s[1010], s1[55], s2[55];

const int mod=1e9+7;
int f[55][50500][2][2], g[55][50500][2][2];

int F(int w,int p,int mx,int lim){
    if (w==m){
        return mx;
    }
    int &res=f[w][p][mx][lim];
    if (res!=-1) return res;
    res=0;
    for (char c='0';c<='9';++c){
        if (lim&&c>s2[w]) continue;
        int to=ac::ch[p][c-'0'];
        res=(res+F(w+1,to,max(mx,(ac::dep[to]>=m/2?1:0)),lim&&c==s2[w]))%mod;
    }
    return res;
}

int G(int w,int p,int mx,int lim){
    if (w==m){
        return mx&&!lim;
    }
    int &res=g[w][p][mx][lim];
    if (res!=-1) return res;
    res=0;
    for (char c='0';c<='9';++c){
        if (lim&&c>s1[w]) continue;
        int to=ac::ch[p][c-'0'];
        res=(res+G(w+1,to,max(mx,(ac::dep[to]>=m/2?1:0)),lim&&c==s1[w]))%mod;
    }
    return res;
}

int main(){
    cin>>s>>s1>>s2;
    n=strlen(s);
    m=strlen(s1);
    ac::init();
    for (int i=0;i<n;++i)
        ac::add(s+i,min(m/2,n-i));
    ac::build();
    memset(f,-1,sizeof f);
    memset(g,-1,sizeof g);
    // cout<<F(0,1,0,1)<<endl;
    // cout<<G(0,1,0,1)<<endl; exit(0);
    cout<<(F(0,1,0,1)-G(0,1,0,1)+mod)%mod<<endl;
}