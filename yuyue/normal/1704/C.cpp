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
const int M=1e6+10,inf=2e9;
int n,a[M],m,b[M];
char s[M],t[M];
void work(){
	n=read(); m=read();
	F(i,1,m) a[i]=read();
	sort(a+1,a+m+1);
	F(i,1,m-1) b[i]=a[i+1]-a[i]-1;
	b[m]=a[1]+n-a[m]-1;
	sort(b+1,b+m+1,greater<int>());
	int cur=0;
	LL ans=0;
	F(i,1,m){
		int le=b[i]-2*(i-1)*2;
		if (le==1) ans+=1;
		else ans+=max(0,le-1);
//		cerr<<b[i]<<" "<<ans<<" "<<le<<" !!!!! \n";

	} 
	cout<<n-ans<<'\n';
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