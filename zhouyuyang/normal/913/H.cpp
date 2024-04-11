#include<bits/stdc++.h>
#define mo 998244353
#define INV 616898040
#define JDB 1000000
#define N 32
using namespace std;
int n,C[N][N],s[N];
int num[N],inv[N];
int sum[N],all[N];
int F[N][10005];
struct Poly{
	int a[33],len;
	Poly(){
		memset(a,0,sizeof(a));
	}
	Poly(int x,int y){
		memset(a,0,sizeof(a));
		len=2; a[1]=x; a[0]=y;
	}
	friend Poly operator +(const Poly &a,const Poly &b){
		Poly c;
		c.len=max(a.len,b.len);
		for (int i=0;i<c.len;i++)
			c.a[i]=(a.a[i]+b.a[i])%mo;
		return c;
	}
	friend Poly operator -(const Poly &a,const Poly &b){
		Poly c;
		c.len=max(a.len,b.len);
		for (int i=0;i<c.len;i++)
			c.a[i]=(a.a[i]+mo-b.a[i])%mo;
		return c;
	}
	Poly trans(){
		Poly c;
		c.len=len;
		for (int i=0;i<len;i++)
			for (int j=0;j<=i;j++)
				c.a[j]=(c.a[j]+1ll*a[i]*C[i][j]%mo*((i-j)&1?mo-1:1))%mo;
		return c;
	}
	Poly jifen(){
		if (!len) return *this;
		Poly c; c.len=len+1;
		for (int i=0;i<len;i++)
			c.a[i+1]=1ll*a[i]*inv[i+1]%mo;
		return c;
	}
	int calc(int x){
		int ans=0;
		for (int j=len-1;j>=0;j--)
			ans=(1ll*ans*x+a[j])%mo;
		return ans;
	}
}a[N][10005];
void calcinter(int x){
	int tot=0;
	all[x]=a[x][num[x]].calc(1ll*F[x][num[x]]*INV%mo);
	for (int i=1;i<=num[x];i++){
		a[x][i]=a[x][i].jifen();
		int vr=a[x][i].calc(1ll*F[x][i]*INV%mo);
		int vl=a[x][i].calc(1ll*F[x][i-1]*INV%mo);
		a[x][i].a[0]=(1ll*a[x][i].a[0]+tot-vl+mo)%mo;
		tot=(1ll*tot+vr+mo-vl)%mo;
	}
	sum[x]=tot;
}
Poly query(int x,int s){
	if (s<=0) return a[n+1][0];
	if (s>F[x][num[x]]){
		int now=1ll*F[x][num[x]]*INV%mo;
		return Poly(all[x],(sum[x]+mo-1ll*now*all[x]%mo)%mo);
	}
	int pos=lower_bound(F[x]+1,F[x]+num[x]+1,s)-F[x];
	return a[x][pos];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		double v;
		scanf("%lf",&v);
		s[i]=min((int)(v*JDB+0.5),i*JDB);
	}
	for (int i=n-1;i;i--)
		s[i]=min(s[i],s[i+1]);
	inv[0]=inv[1]=1;
	for (int i=2;i<=n+2;i++){
		s[i]=min(s[i],s[i-1]+JDB);
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	}
	for (int i=0;i<=n+1;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	num[1]=1;
	F[1][1]=s[1];
	a[1][1].len=2;
	a[1][1].a[1]=1;
	for (int i=2;i<=n;i++){
		num[i]=1; F[i][1]=JDB;
		for (int j=1;j<=num[i-1];j++)
			F[i][++num[i]]=F[i-1][j],
			F[i][++num[i]]=F[i-1][j]+JDB;
		sort(F[i]+1,F[i]+num[i]+1);
		num[i]=unique(F[i],F[i]+num[i]+1)-F[i]-1;
		for (;F[i][num[i]]>=s[i];num[i]--);
		F[i][++num[i]]=s[i];
		calcinter(i-1);
		for (int j=1;j<=num[i];j++)
			a[i][j]=query(i-1,F[i][j])-query(i-1,F[i][j]-JDB).trans();
	}
	printf("%d\n",a[n][num[n]].calc(1ll*s[n]*INV%mo));
}