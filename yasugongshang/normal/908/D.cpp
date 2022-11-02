#include<bits/stdc++.h>
using namespace std;
inline long long read() {
	long long k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
inline void write(long long a) {
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a) {
	if(a<0) {
		a=-a;
		putchar('-');
	}
	write(a);
	puts("");
}
const int mod=1000000007;
long long n,x,y,xx,yy,f[2005][2005],res,ans,sum;
inline long long ksm(long long a,long long b) {
	long long ans=1;
	for(; b; b>>=1,a=(long long)a*a%mod)
		if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
int main() {
	n=read();
	x=read();
	y=read();
	xx=ksm(x+y,mod-2)*x%mod;
	yy=ksm(x+y,mod-2)*y%mod;
	f[1][0]=ksm(x+y,n*2);
	for (long long i=1; i<=n; i++)
		for (long long j=0; j<n; j++)
			if (f[i][j]) {
				(f[i+1][j]+=f[i][j]*xx)%=mod;
				if (j+i>=n)(ans+=f[i][j]*yy%mod*(j+i)%mod)%=mod;
				else (f[i][j+i]+=f[i][j]*yy)%=mod;
			}
	for (long long i=0; i<n; i++) {
		res=(x+(n+i+1)*y)%mod;
		res=res*ksm(y,mod-2)%mod;
		ans=(ans+f[n+1][i]*res)%mod;
	}ans=ans*ksm(f[1][0],mod-2)%mod;
	cout<<ans<<endl;
}