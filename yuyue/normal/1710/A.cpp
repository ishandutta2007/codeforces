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
const int M=5e5+10;
int n,m,k;
int a[M];
void work(){
	n=read(); m=read();
	k=read();
	bool f1=1,f2=1;
	LL s1=0,s2=0;
	F(i,1,k){
		a[i]=read();
		int o=a[i]/n;
		if (o>=2) s1+=o,f1&=(o==2);
		o=a[i]/m;
		if (o>=2) s2+=o,f2&=(o==2);
//		f1&=(a[i]%n==0 && a[i]>=2*n);
//		f2&=(a[i]%m==0 && a[i]>=2*m);
	}
	if ((s1>=m  && (!f1 || s1%2==m%2))|| (s2>=n && (!f2 || s2%2==n%2))) puts("Yes"); else puts("No");
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