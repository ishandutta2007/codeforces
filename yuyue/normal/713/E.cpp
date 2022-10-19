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
const int M=2e5+10;
int n,m,a[M];
void init(){
	int mx=0,ps=0;
	F(i,1,n){
		if (mx<a[i+1]-a[i]){
			mx=a[i+1]-a[i];
			ps=i+1;
		}
	}
	int bg=a[ps];
	F(i,1,n) a[i]=a[i+ps-1]-bg;
//	,cerr<<a[i]<<" ";
//	cerr<<"\n";
}
int dp[M];
bool chk(int x){
	dp[1]=0;
	F(i,2,n){
		dp[i]=dp[i-1];
		if (dp[i-1]>=a[i]-1){//->
			dp[i]=max(dp[i],a[i]+x);
		}
		if (dp[i-1]>=a[i]-x-1){
			dp[i]=max(dp[i],a[i]);
		}
		if (i>2 && dp[i-2]>=a[i]-x-1){
			dp[i]=max(dp[i],a[i-1]+x);
		}
	}
	if (dp[n]>=(m-x-1)) return 1;
	dp[2]=max(a[2],x);
	dp[1]=0;
	F(i,3,n){
		dp[i]=dp[i-1];
		if (dp[i-1]>=a[i]-1){//->
			dp[i]=max(dp[i],a[i]+x);
		}
		if (dp[i-1]>=a[i]-x-1){
			dp[i]=max(dp[i],a[i]);
		}
		if (i>2 && dp[i-2]>=a[i]-x-1){
			dp[i]=max(dp[i],a[i-1]+x);
		}
	}
	
	if (dp[n]>=min(m-1,m-1+a[2]-x)) return 1;
	return 0;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	m=read(); n=read();
	F(i,1,n) a[i]=read(),a[i+n]=a[i]+m;
	sort(a+1,a+n*2+1);
	init();
	int l=0,r=m,ans=m;
	while (l<=r){
		int mid=(l+r>>1);
		if (chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
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
*/