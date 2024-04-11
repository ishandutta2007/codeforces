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
LL K;
LL n,a[M],b[M];
bool chk(LL d){
	LL tt=0;
	F(i,1,n){
		//a-3x^2+3x-1>=d
		//3x^2-3x+d-a+1<=0
		//x=(3+sqrt(9+12(a-d-1)))/6
		if (a[i]-d-1<0) 
		{
			b[i]=0;
			continue;
		}
		LL x=floor(sqrt(9+12.*(a[i]-d-1)));
		x=(x+3)/6;
		while (a[i]-3ll*x*x+3*x-1<d) x--;
		x=min(x,(LL)a[i]);
		tt+=x;
		b[i]=x;
//		assert(x>=0 && a[i]-3ll*x*x+3*x-1>=d);
	}
//	cerr<<d<<" "<<tt<<'\n';
	return tt>=K;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	cerr<<log10(LONG_LONG_MAX)<<"\n";
	n=read(); K=read();
	F(i,1,n) a[i]=read();
	LL l=-4e18,r=1e9+10,ret=r;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (chk(mid)) l=mid+1,ret=mid;
		else r=mid-1;
	}
	chk(ret);
	LL hh=0;
	F(i,1,n) hh+=b[i];
	F(i,1,n){
		if (hh>K && a[i]-3ll*b[i]*b[i]+3ll*b[i]-1==ret && b[i]>0){
			hh--;
			b[i]--;
		}
	}
	F(i,1,n){
		cout<<b[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/