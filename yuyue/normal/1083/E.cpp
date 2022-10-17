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
const int M=1e6+10;
struct rect{
	LL x,y,v;
}a[M];
bool cmp(rect A,rect B){
	return A.x<B.x;
}
int n,q[M];
LL dp[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) a[i]=(rect){read(),read(),read()};
	sort(a+1,a+n+1,cmp);
	int l=1,r=0;
	F(i,1,n){
		dp[i]=1ll*a[i].x*a[i].y-a[i].v;
//		if (i>1) assert(a[i].y<a[i-1].y);
		while (l+1<=r && (dp[q[l+1]]-dp[q[l]])>=1ll*a[i].y*(a[q[l+1]].x-a[q[l]].x)) l++;
		if (l<=r) dp[i]=max(dp[i],dp[q[l]]+1ll*(a[i].x-a[q[l]].x)*a[i].y-a[i].v);
		while (l+1<=r && (__int128)1ll*(a[q[r]].x-a[q[r-1]].x)*(dp[i]-dp[q[r-1]])-(__int128)1ll*(a[i].x-a[q[r-1]].x)*(dp[q[r]]-dp[q[r-1]])>=0) r--;
		q[++r]=i;
	}
	LL ans=0;
	F(i,1,n) ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/