#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int a[M],L,R,cl[M],cr[M],n;
void work(){
	n=read(); L=read(); R=read();
	F(i,1,n) a[i]=read();
	if (L<R) swap(L,R),reverse(a+1,a+n+1);
	F(i,1,L) cl[a[i]]++;
	F(i,L+1,n) cr[a[i]]++;
	int mt=0,res=(L-R)/2;
	F(i,1,n){
		mt+=min(cl[i],cr[i]);
		while (res && cl[i]-1>=cr[i]+1) res--,mt++,cl[i]--,cr[i]++;
	}
	cout<<(L-R)/2+n/2-mt<<"\n";
	F(i,1,n) cl[i]=cr[i]=0;
}
int main(){
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