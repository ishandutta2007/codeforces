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
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int n;
LL a[M],b[M];
int f[62][M],p[M],s[2][M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	LL mx=0;
	F(i,1,n) a[i]=read(),mx=max(mx,a[i]);
	F(i,1,n) b[i]=mx-a[i],p[i]=i;
	ms(f,1);
	f[0][0]=0;
	F(i,0,60){
		LL nw=(1ll<<i)-1;
		sort(p+1,p+n+1,[&](int x,int y){
			return (b[x]&nw)>(b[y]&nw);
		});
		F(j,1,n) s[0][j]=s[0][j-1],s[1][j]=s[1][j-1],s[(b[p[j]]>>i&1)][j]++; 
		int o=0;
		F(j,0,n){
			//0 in x
			int oo=s[1][j];
			f[i+1][oo]=min(f[i][j]+s[0][j]+s[1][n]-s[1][j],f[i+1][oo]);
			//1 in x
			oo=j+s[1][n]-s[1][j];
			f[i+1][oo]=min(f[i][j]+s[1][j]+s[0][n]-s[0][j],f[i+1][oo]);
		}
	}
	cout<<f[61][0]<<"\n";
	
//	F(i,0,62){
//		int co=0;
//		F(j,1,n){
//			LL o=b[j]>>i; o++;
//			int d=__builtin_ctzll(o);
//			co+=d-1;
//		}
//		if (co>=0){
//			F(j,1,n) b[j]+=(1ll<<i);
//		}
//		F(k,1,n){
//			F(j,0,60) cerr<<(b[k]>>j&1);
//			cerr<<"\n";
//		}
//		cerr<<" !!!!!!\n";
//	}
//	LL ans=0;
//	F(i,1,n) ans+=__builtin_popcountll(b[i]);
//	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/