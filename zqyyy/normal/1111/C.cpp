#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#define re register
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,k,A,B,a[100001];
long long get(int l,int r,int ll,int rr){
	if(ll>rr) return A;if(l==r) return 1ll*B*(rr-ll+1);
	int mid=l+r>>1,x=upper_bound(a+ll,a+rr+1,mid)-a-1;
	return min(1ll*B*(rr-ll+1)*(r-l+1),get(l,mid,ll,x)+get(mid+1,r,x+1,rr));
}
int main(){
	n=read(),k=read(),A=read(),B=read();
	for(re int i=1;i<=k;i++)a[i]=read();
	sort(a+1,a+k+1);
	printf("%lld\n",get(1,1<<n,1,k));
	return 0;
}