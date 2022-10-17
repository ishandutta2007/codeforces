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
const int M=1111,mod=1e9+7;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int a[M][M],n,m;
int main(){
	ms(a,-1);
	n=read(); m=read();
	F(i,1,n){
		int x=read();
		F(j,1,x){
			if (a[i][j]==0) {
				puts("0");
				return 0;
			}
			a[i][j]=1;
		}
		if (a[i][x+1]==1) {
			puts("0");
			return 0;
		}
		a[i][x+1]=0;
	}
	F(i,1,m){
		int x=read();
		F(j,1,x){
			if (a[j][i]==0) {
				puts("0");
				return 0;
			}
			a[j][i]=1;
		}
		if (a[x+1][i]==1) {
			puts("0");
			return 0;
		}
		a[x+1][i]=0;
	}
	int ans=0;
	F(i,1,n) F(j,1,m) if (a[i][j]==-1) ans++;
	cout<<fast(2,ans)<<"\n";
	return 0;
}