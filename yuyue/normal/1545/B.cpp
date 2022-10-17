#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,mod=998244353;
int n;
char s[M];
LL fac[M],inv[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret; 
	 
}
void init(){
	fac[0]=1;
	F(i,1,M-5) fac[i]=fac[i-1]*i%mod;
	F(i,0,M-5) inv[i]=fast(fac[i],mod-2);
}
LL C(int x,int y){ return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	int T=read(); init();
	while (T--){
		n=read(); scanf("%s",s+1);
		int d=0,z=0;
		F(i,1,n){
			if (i<n && s[i]=='1' && s[i+1]=='1'){
				d++;
				i++;
			}
			z+=(s[i]=='0');
		}
		cout<<C(z+d,z)<<"\n";
	}
	return 0;
}
/*
*/