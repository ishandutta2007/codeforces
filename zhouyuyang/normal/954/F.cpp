#include<bits/stdc++.h>
#define ll long long
#define int long long
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
struct jz{int a[4][4];}dd,now,zero,one,ans;
int lsg,n,m,x,y,z,f[10],kk,d;
struct akszb{int x,y,z;}a[1000010];
jz chen(jz x,jz y){
	jz kk=zero;
	for (int k=1;k<=3;k++) 
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
				(kk.a[i][j]+=x.a[i][k]*y.a[k][j])%=lsg;
	return kk;
}void ksm(int k){
	jz x=now;ans=one;
	while (k){
		if (k&1)ans=chen(ans,x);x=chen(x,x);k>>=1;
	}
}void make(){
	now=zero;
	if (f[1]>0)now.a[1][1]=now.a[2][1]=1;
	if (f[2]>0)now.a[2][2]=now.a[1][2]=now.a[3][2]=1;
	if (f[3]>0)now.a[3][3]=now.a[2][3]=1;
}bool pd(akszb x,akszb y){return x.y<y.y;}
signed main(){
	n=read();m=read();lsg=1e9+7;
	one.a[1][1]=one.a[2][2]=one.a[3][3]=1;
	for (int i=1;i<=n;i++){
		x=read();y=read();z=read();
		a[++kk].x=x;a[kk].y=y;a[kk].z=0;
		a[++kk].x=x;a[kk].y=z+1;a[kk].z=1;
	}sort(a+1,a+1+kk,pd);
	d=1;f[1]=f[2]=f[3]=1;dd.a[2][2]=1;make();
	for (int i=1;i<=kk;i++){
		ksm(a[i].y-d-1);dd=chen(dd,ans);
		if (a[i].z)f[a[i].x]++;else f[a[i].x]--;make();d=a[i].y-1;
	}if (d!=m)ksm(m-d),dd=chen(dd,ans);
	writeln(dd.a[2][2]);
}