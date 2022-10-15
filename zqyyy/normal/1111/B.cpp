#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,k,m;
long long sum;
double ans,a[N];
int main(){
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	sort(a+1,a+(int)(n)+1);
	for(int i=0;i<n && m>=i;i++){
		sum-=a[i];
		ans=max(ans,1.0*(min(0ll+m-i,1ll*k*(n-i))+sum)/(n-i));
	}
	return printf("%.10lf\n",ans),0;	
}