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
const int M=5e5+10;
int n,m;
int f[M],used[M],ans[M];
int Fd(int x){
	if (x==f[x]) return x;
	return f[x]=Fd(f[x]);	
}
int X[M],Y[M],Z[M];
void init(){
	F(i,1,2*n) ans[i]=used[i]=0,f[i]=i;
}
void work(){
	n=read(); m=read(); init();
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		X[i]=x; Y[i]=y; Z[i]=z;
		if (z>=0) {
			z=__builtin_popcount(z)&1;
			if (!z) f[Fd(x)]=f[Fd(y)],f[Fd(x+n)]=f[Fd(y+n)];
			else f[Fd(x+n)]=f[Fd(y)],f[Fd(x)]=f[Fd(y+n)];
		}
	}
	F(i,1,m){
		int x=read(),y=read(),z=read();
		if (!z) f[Fd(x)]=f[Fd(y)],f[Fd(x+n)]=f[Fd(y+n)];
		else f[Fd(x+n)]=f[Fd(y)],f[Fd(x)]=f[Fd(y+n)];
	}
	F(i,1,n){
		if (Fd(i)==Fd(i+n) || (used[Fd(i)] && used[Fd(i+n)])){
			puts("NO");
			return ;
		}
		if (used[Fd(i+n)]) ans[i]=1;
		else used[Fd(i)]=1,ans[i]=0;
	}
	puts("YES");
	F(i,1,n-1){
		if (Z[i]==-1){
			Z[i]=(ans[X[i]]^ans[Y[i]]);
		}
		cout<<X[i]<<" "<<Y[i]<<" "<<Z[i]<<"\n";
	}
	
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