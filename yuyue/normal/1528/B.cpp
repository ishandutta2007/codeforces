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
const int mod=998244353,M=2e6+10;
LL f[M],s[M];
int n;
int main(){
	n=read();
	f[0]=s[0]=1;
	F(i,1,n){
		f[i]+=s[i-1]; f[i]%=mod;
		for (int j=2*i;j<=n;j+=i){
			f[j]++;
		}
		s[i]=(s[i-1]+f[i])%mod;
	}
	cout<<f[n]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/