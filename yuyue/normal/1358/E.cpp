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
const int M=5e5+10;
int n,p,X,a[M];
LL s[M],mi[M]; 
int main(){
	n=read(); p=n/2; if (n&1) p++;
	F(i,1,p) a[i]=read();
	DF(i,p,1) s[i]=s[i+1]+a[i]; X=read();
	mi[0]=1e18; 
	F(i,1,p){
		mi[i]=min(mi[i-1],s[i]+1ll*X*i); 
	}
	int ans=-1;
	F(i,(p+(n%2==0)),n){
		if (mi[n-i+1]>1ll*(1+p-i)*X) ans=i;
	}
	cout<<ans<<"\n";
	return 0;
}