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
const int M=1e6+5,mod=998244353;
int n,k,v[M],in[M];
LL inv[M];
void init(){
	inv[1]=1;
	F(i,2,M-5) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
}
void work(){
	n=read(); k=read();
	F(i,1,n){
		v[i]=read(); in[i]=0;
	}
	F(i,1,n){
		if (v[i]>0){
			int ps=i+k;
			if (ps>n){
				cout<<"0\n";
				return ;
			}
			in[ps]=1;
		}
	}
	LL ans=1;
	F(i,1,n){
		if (!in[i]){
			ans=ans*min(i,k+1)%mod;
		}
	}
	F(i,1,n){
		if (v[i]==-1){
			if (i+k<=n){
				ans=ans*(inv[k+1]*(i-1)%mod+1)%mod;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(); init();
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