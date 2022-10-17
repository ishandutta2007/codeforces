#include <bits/stdc++.h>
using namespace std;
#define GG puts("-1"),exit(0)
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+5;
int n,nn;
ll cnt[40],pw[40],a[N],b[N],c[N];
ll sum;
int main(){
	n=read(),nn=n<<1;
	for(int i=1;i<=n;i++)sum+=b[i]=read();
	for(int i=1;i<=n;i++)sum+=c[i]=read();
	if(sum%nn)GG;sum/=nn;
	for(int i=1;i<=n;i++){
		a[i]=b[i]+c[i]-sum;
		if(a[i]%n)GG;a[i]/=n;
	}
	for(int i=1;i<=n;i++)
		for(int j=30;~j;j--)
			if(a[i]&(1<<j))cnt[j]++;
	for(int i=pw[0]=1;i<=30;i++)pw[i]=pw[i-1]<<1;
	for(int i=1;i<=n;i++){
		ll res=0;
		for(int j=30;~j;j--)
			if(a[i]&(1<<j)){
				res+=1ll*pw[j]*cnt[j];
				if(res>b[i])GG;	
			}
		if(res^b[i])GG;
		res=sum;
		for(int j=30;~j;j--)
			if(a[i]&(1<<j)){
				res+=1ll*pw[j]*(n-cnt[j]);
				if(res>c[i])GG;	
			}
		if(res^c[i])GG;
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}