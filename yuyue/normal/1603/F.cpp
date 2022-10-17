#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=998244353,i2=(mod+1)/2;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
const int M=5e7+10;
int inv[M];
void init(int n){
	LL tmp=1,pw=2;
	F(i,1,n) tmp=tmp*(pw-1)%mod,pw=pw*2%mod;
	inv[n]=fast(tmp,mod-2);
	DF(i,n,1){
		pw=pw*i2%mod;
		inv[i-1]=inv[i]*(pw-1)%mod;
	}
//	cout<<inv[0]<<"\n";
}

void work(){
	int n=read(),k=read(),x=read();
	LL pw=fast(2,k);
	if (x==0){
		LL ans=1,tmp=1;
		if (n>k){
			puts("0");
			return ;
		}
		F(i,1,n){
			ans=(ans*(pw+mod-tmp))%mod;
			tmp=tmp*2%mod;
		}
		cout<<ans<<"\n";
		return ;	
	}
	LL mul=1,tmp=1,n2=fast(2,n);
	LL qb=1,ans=0;
	F(i,0,min(n,k-1)){
		ans=(ans+mul*qb%mod*inv[i])%mod;
		tmp=tmp*2%mod;
		mul=mul*(pw+mod-tmp)%mod;
		qb=qb*(n2-1)%mod; n2=n2*i2%mod;
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(); init(5e7);
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/