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
const int M=1e6+10,inf=2e9;
int n,a[M],m,b[M];
char s[M],t[M];
void work(){
	n=read(); m=read();
	__int128 la=-1;
	LL k=0,ans=0;
	F(i,1,n){
		__int128 s=0,ss=0;
		F(j,1,m){
			a[j]=read();
			s+=a[j];
			ss+=s;
		}
		if (i!=1 && la!=ss){
			ans=(la>ss ? i : i-1);
			k=la-ss;
			k=abs(k);
		}
		la=ss;
	}
	cout<<ans<<" "<<k<<"\n";
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