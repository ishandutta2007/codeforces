#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
inline void add(int &x,const int y){(x+=y)>=P&&(x-=P);}
inline int Add(int x,const int y){return add(x,y),x;}
inline void sub(int &x,const int y){(x-=y)<0&&(x+=P);}
inline int Sub(int x,const int y){return sub(x,y),x;}
inline void mul(int &x,const int y){x=1ll*x*y%P;}
inline int Mul(const int x,const int y){return 1ll*x*y%P;}
inline int power(int x,int y){int ans=1;for(;y;y>>=1,mul(x,x))if(y&1)mul(ans,x);return ans;}
const int M=1e6+5,N=3e6+5;
int n,m,pre[N],suf[N],s[N],ifac[M];
inline int calc(int n){
  if(n<=m+1)return s[n];
  int ans=0;
  pre[0]=n;for(int i=1;i<=m+1;++i)pre[i]=Mul(pre[i-1],n-i);
  suf[m+2]=1;for(int i=m+1;~i;--i)suf[i]=Mul(suf[i+1],n-i);
  for(int i=1;i<=m+1;++i){
    int cur=Mul(ifac[i],ifac[m+1-i]);
    if((m+1-i)&1)cur=P-cur;
    add(ans,Mul(s[i],Mul(cur,Mul(pre[i-1],suf[i+1]))));
  }
  return ans;
}
int main(){
  scanf("%d%d",&n,&m);
  ifac[m+1]=1;for(int i=1;i<=m+1;++i)mul(ifac[m+1],i);ifac[m+1]=power(ifac[m+1],P-2);
  for(int i=m;~i;--i)ifac[i]=Mul(ifac[i+1],i+1);
  for(int i=1;i<N;++i)s[i]=Add(s[i-1],power(i,m));
  printf("%d\n",calc(n));
  return 0;
}