#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1010,mod=998244353;
int n,k,a[M],ps[M];
LL s[M],f[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); k=read();
	F(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	LL ans=0;
	DF(o,a[n]/(k-1)+2,1){
		F(i,1,n) while (a[i]-a[ps[i]+1]>=o) ps[i]++;
		F(i,1,n) f[i]=1;
		F(j,2,k){
			F(i,1,n) s[i]=(s[i-1]+f[i])%mod;
			F(i,1,n){
				f[i]=s[ps[i]];
			}
		}
		LL tmp=0;
		F(i,1,n) ans+=f[i],tmp+=f[i];
		ans%=mod;
//		if (i>=1000 && tmp) cout<<o<<" "<<tmp<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
5 2
1 10 100 1000 10000
*/