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
const int M=3e5+10;
int n,a[M],pre[M],suf[M];
void solve(){
	n=read();
	pre[0]=suf[n+1]=1e9;
	F(i,1,n) a[i]=read();
	int pos=1;
	F(i,2,n) if (a[i]<a[pos]) pos=i;
	int res=a[pos];
	DF(i,pos-1,2){
		res-=max(a[i]-a[i-1],0);
	}
	F(i,pos+1,n-1) res-=max(a[i]-a[i+1],0);
	if (res>=0) puts("YES");
	else puts("NO");
}
int main(){
	int T=read();
	while (T--) solve();
	return 0;
}