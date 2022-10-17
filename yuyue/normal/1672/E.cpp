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
int n;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	int l=1,r=2000*n+n,ret=r;
	while (l<=r){
		int mid=(l+r>>1);
		cout<<"? "<<mid<<endl;
		int x=read();
		if (x==1) ret=mid,r=mid-1;
		else l=mid+1;
	}
//	ret=33;
	int sm=ret-n+1;
	LL ans=ret;
	F(i,2,n){
		int tmp=sm+n-i;
		F(j,tmp,ans){
			if (j%i==0){
				cout<<"? "<<j/i<<endl;
				int x=read();
				if (x) ans=min(ans,1ll*x*(j/i));
				break;
			}
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/