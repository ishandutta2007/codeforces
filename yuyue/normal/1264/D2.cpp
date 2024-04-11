#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=998244353,M=1e6+10;
int n;
LL fac[M],inv[M];
LL C(int x,int y){
	if (y>x || y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
char s[M];
LL fast(LL x,LL p){
	LL ret=1; 
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
} 
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	int l=0,x=0,y=0,r=0;
	F(i,1,n){
		if (s[i]=='(') l++;
		if (s[i]=='?') x++;
	}
	LL ans=0;
	DF(i,n,1){
		if (s[i]=='(') l--;
		if (s[i]==')') r++;
		if (s[i]=='?') x--,y++;
		ans=(ans+C(x+y,y+r-l)*l+C(x+y-1,y+r-l-1)*x)%mod; 
	}
	cout<<ans<<'\n';
    return 0;
}