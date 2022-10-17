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
const int M=5e5+10;
//int n,a[M],p[M],k;
//map<int,int> mp;
LL n;
LL O=384,inf=1e18;
void work(){
	n=read();
	if (__builtin_popcountll(n)==1){
		cout<<"-1\n";
		return ;
	}
	F(i,0,60){
		if (n>>i&1){
			cout<<min((1ll<<i+1),n>>i)<<"\n";
			return ;
		}
	}
//	cerr<<n<<"\n";
//	
//	F(i,2,n){
//		LL tmp=1ll*i*(i-1)/2;
//		if (tmp>n) break;
//		if ((n-tmp)%i==0){
//			cout<<i<<"\n";
//			return ;
//		} 
//	}
//	assert(0);
//	cout<<"-1\n";
//	mp.clear();
//	bool fl=0,nei=0;
//	F(i,1,n) a[i]=read(),mp[a[i]]=1,nei|=(mp.count(a[i]-1) || mp.count(a[i]+1));
//	if (!mp.count(1) || !mp.count(0) && !nei) puts("YES");
//	else puts("NO");
	
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