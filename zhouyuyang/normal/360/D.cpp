#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int d[N],a[N],b[N],f[N];
int n,m,mo,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int G=mo-1;
	for (int i=1;i<=m;i++){
		int v;
		scanf("%d",&v);
		G=gcd(G,v);
	}
	for (int i=1;i*i<mo;i++)
		if ((mo-1)%i==0){
			d[++*d]=i;
			if (i*i!=mo-1)
				d[++*d]=(mo-1)/i;
		}
	sort(d+1,d+*d+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=*d;j++)
			if (power(a[i],1ll*G*d[j]%(mo-1))==1){
				b[i]=(mo-1)/d[j];
				break;
			}
	sort(b+1,b+n+1);
	*b=unique(b+1,b+n+1)-b-1;
	for (int i=*b;i>=1;i--){
		f[i]=(mo-1)/b[i];
		for (int j=i+1;j<=*b;j++)
			if (b[j]%b[i]==0) f[i]-=f[j];
		ans+=f[i];
	}
	printf("%d",ans);
}