#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll c[10000001],mal,l,r,n,k,m,ans,a[1000005];
void read(ll &x){
	x=0;
	char ch=getchar();
	while (ch<'0'&&ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}
int jud(ll m){
	for (int i=1;i<=mal;i++) c[i]=0;
	for (int i=1;i<=n;i++) c[a[i]]++;
	ll tot=0;
	for (int i=mal;i>=m;i--)
		if (i/2>=m){
			c[i/2]+=c[i];
			c[i-i/2]+=c[i];
		} 
		else tot+=c[i];
	if (tot>=k) return 1;
	return 0;
}
int main(){
	read(n);
	read(k);
	for (int i=1;i<=n;i++){
		read(a[i]);
		r=max(r,a[i]);
	}
	l=1;
	mal=r;
	while (l<=r){
		m=(l+r)/2;
		if (jud(m)){
			ans=m;
			l=m+1; 
		}
		else r=m-1;
	}
	if (ans==0) ans=-1;
	printf("%I64d",ans);
}