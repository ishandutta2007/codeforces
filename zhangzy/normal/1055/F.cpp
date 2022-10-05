#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, fa, ch[2002000][2], sz[2002000], cnt, p1[2002000], p2[2002000];
ll a[1001000], ans, k, las;

int nnd(){
  ++cnt; ch[cnt][0]=ch[cnt][1]=sz[cnt]=0;
  return cnt;
}

int main(){
  cin>>n>>k;
  for (int i=2;i<=n;++i){
    scanf("%d%lld",&fa,&a[i]);
    a[i]^=a[fa];
  }
  for (int i=0;i<n*2+9;++i) p1[i]=p2[i]=1;
  for (int w=61;w>=0;--w){
    cnt=w&1? n: 0; las=k;
    for (int i=1;i<=n;++i){
      int &p=p1[i], c=a[i]>>w&1;
      if (!ch[p][c]) ch[p][c]=nnd();
      ++sz[p=ch[p][c]];
    }
    for (int i=1;i<=n;++i){
      int &p=p2[i], c=a[i]>>w&1;
      las-=sz[ch[p][c]];
    }
    int aim=0;
    if (las>0){
      aim=1; ans|=1ll<<w; k=las;
    }
    for (int i=1;i<=n;++i){
      int &p=p2[i], c=a[i]>>w&1;
      p=ch[p][c^aim];
    }
  }
  cout<<ans<<endl;
}