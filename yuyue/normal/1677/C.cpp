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
const int M=1e6+5;
int n,m,a[M],b[M],f[M],sz[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
void work(){
	n=read();
	F(i,1,n) f[i]=i,sz[i]=1;
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	F(i,1,n){
		int x=Fd(a[i]),y=Fd(b[i]);
		if (x^y){
			f[y]=x;
			sz[x]+=sz[y];
		}
	}
	int np=n;
	F(i,1,n){
		if (Fd(i)==i && sz[i]&1){
			np--;
		} 
	}
	LL ans=0;
	F(i,1,np/2){
		ans+=2*(n-i+1)-2*i;
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
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