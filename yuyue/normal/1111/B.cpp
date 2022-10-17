#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int M=1e5+10;
long double ans;
int n,m,k,w[M];
LL sum[M];
int main(){
	n=read(); k=read(); m=read();
	for (int i=1;i<=n;i++)
	w[i]=read();
	sort(w+1,w+n+1);
	for (int i=1;i<=n;i++)
	sum[i]=sum[i-1]+w[i];
	for (int i=1;i<=n;i++){
		if (n-i>m) continue ;
		long double now;
		now=sum[n]-sum[n-i];
		now+=min(1ll*i*k,1ll*(m-n+i));
		ans=max(ans,now/i);	
	}
	cout<<fixed<<setprecision(10)<<ans<<"\n";
	
//		cout<<fixed<<setprecision(10)<<ans/r<<"\n";
	
//	cout<<fixed<<setpercision(6)<<ans<<"\n";
	return 0;
}