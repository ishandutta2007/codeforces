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
const int M=1e5+10; 
int n,a[M];
LL f[M],sf[M];
void work(){
	n=read();
	LL sm=0;
	F(i,1,n) a[i]=read(),sm+=a[i];
	f[1]=1;
	F(i,2,60) f[i]=f[i-1]+f[i-2];
	F(i,1,60) sf[i]=sf[i-1]+f[i];
	int j=1;
	while (sf[j]<sm) j++;
//	cerr<<j<<" "<<sf[j]<<""
	if (sf[j]!=sm){
		puts("No");
		return ;
	}
	int la=-1;
	while (j){
		int mx=0;
		F(i,1,n) if (i!=la && a[i]>a[mx]) mx=i;
//		cerr<<mx<<" "<<f[j]<<" !!!\n";
		if (a[mx]<f[j]){
			puts("No");
			return ;
		}
		a[mx]-=f[j];
		la=mx;
		j--;
	}
	puts("Yes");
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