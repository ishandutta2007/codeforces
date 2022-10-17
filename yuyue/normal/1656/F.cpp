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
const int M=2e5+10;
int n;
LL a[M],s[M];
void work(){
	n=read();
	F(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	F(i,1,n) s[i]=s[i-1]+a[i];
	LL ans=-5e18;
	F(i,1,n-1){
		LL b=(s[n]-s[i])*a[1]+s[i]*a[n];
//		if (!i) b-=a[1]*a[1];
//		else if (i==n) b-=a[n]*a[n];
//		else b-=a[1]*a[n];
		b-=a[1]*a[n];
		LL k=s[n]+(n-i-1)*a[1]+(i-1)*a[n];
//		cerr<<k<<" "<<b<<"\n";
		LL l=-a[i+1],r=-a[i];
		if (i==1){
			if (k>0){
				cout<<"INF\n";
				return ; 
			}
		}	
		if (i==n-1){
			if (k<0){
				cout<<"INF\n";
				return ; 
			}
		}	
		ans=max(ans,k*l+b);
		ans=max(ans,k*r+b);
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