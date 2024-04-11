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
const int M=6060;
int n,X[M],Y[M],c[M][2];
int main(){
	n=read();
	F(i,1,n){
		X[i]=read(); Y[i]=read();
		F(j,1,i-1){
			int hh=__gcd(X[i]-X[j],Y[i]-Y[j]);
			hh=abs(hh); hh%=4;
			if (hh==2) c[i][1]++,c[j][1]++;
			else c[i][0]++,c[j][0]++;
		}
	}
	LL ans=0,a0=0,a1=0;
	F(i,1,n){
		a0+=c[i][1]*c[i][0];
		a1+=c[i][0]*(c[i][0]-1)/2;
	}
	ans=a0/2+a1/3;
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