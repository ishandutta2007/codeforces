#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=998244353,M=4e5+10;
LL a[M];
LL fast(LL x,LL p){
	LL ret=1; 
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int n;
int main(){
	n=read();
	F(i,1,2*n) a[i]=read();
	sort(a+1,a+2*n+1);
	LL sum=0;
	F(i,1,n){
		sum=(mod+sum-a[i])%mod;
	}
	F(i,n+1,2*n) sum=(sum+a[i])%mod;
	F(i,1,2*n){
		LL iv=fast(i,mod-2);
		sum=sum*i%mod;
		if (i<=n){
			sum=sum*iv%mod*iv%mod;
		}
	}
	cout<<sum<<"\n";
	return 0;
}