#include<bits/stdc++.h>
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod&&(x-=mod);}
inline int Add(int x,int y){return add(x,y),x;}
inline void sub(int &x,int y){(x-=y)<0&&(x+=mod);}
inline int Sub(int x,int y){return sub(x,y),x;}
inline void mul(int &x,int y){x=1ull*x*y%mod;}
inline int Mul(int x,int y){return 1ull*x*y%mod;}
int power(int a,int b){int res=1;for(;b;b>>=1,mul(a,a))if(b&1)mul(res,a);return res;}
const int N=1e6+5;
int n,fac[N],ifac[N];
char s[N];
void init(int n){
  fac[0]=1;for(int i=1;i<=n;++i)fac[i]=Mul(fac[i-1],i);
  ifac[n]=power(fac[n],mod-2);
  for(int i=n-1;~i;--i)ifac[i]=Mul(ifac[i+1],i+1);
}
inline int C(int n,int m){return (n<0||m<0||n<m)?0:Mul(fac[n],Mul(ifac[m],ifac[n-m]));}
int solve(int x,int y,int a,int b){
  if(x<y)std::swap(x,y),std::swap(a,b);
  return Add(Mul(y,C(a+b,a+x-y)),Mul(b,C(a+b-1,a+x-y-1))); 
}
int main(){
  init(N-1),scanf("%s",s+1),n=strlen(s+1);
  int m=std::count(s+1,s+n+1,'?'),ans=0;
  for(int i=1,j=0,k1=0,k2=std::count(s+1,s+n+1,')');i<=n;++i){
    j+=s[i]=='?',k1+=s[i]=='(',k2-=s[i]==')';
    add(ans,solve(k1,k2,j,m-j));
  }
  return printf("%d\n",ans),0;
}