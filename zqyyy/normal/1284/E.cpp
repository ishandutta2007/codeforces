#include <bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2507;
const ll mod=114514114514114514ll;
const db pi=acosl(-1);
struct node{
	db x,y,ang;
}a[N],b[N<<1];
int n,K;
ll C[N][N];
int main(){
	n=read(),K=5;
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read();
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	ll res=0;
	for(int now=1;now<=n;now++){
		for(int i=1;i<now;i++)b[i]=a[i];
		for(int i=now+1;i<=n;i++)b[i-1]=a[i];
		for(int i=1;i<n;i++)b[i].x-=a[now].x,b[i].y-=a[now].y,b[i].ang=atan2l(b[i].y,b[i].x);
		sort(b+1,b+n,[](node X,node Y){return X.ang<Y.ang;});
		for(int i=1;i<n;i++)b[i+n-1]=b[i],b[i+n-1].ang+=2*pi;
		ll ans=C[n-1][K-1];
		for(int i=1,j=1;i<n;i++){
			while(j<2*n-2 && b[j+1].ang-b[i].ang<pi)j++;
			ans=(ans+mod-C[j-i][K-2])%mod;
		}
		(res+=ans)%=mod;
	}
	return cout<<res,0;
}