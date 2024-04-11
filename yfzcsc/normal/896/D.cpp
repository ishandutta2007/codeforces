#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int n,l,r,m,P;
void exgcd(int a,int b,int& x,int& y){
	if(b==0){
		x=1,y=0;
	} else exgcd(b,a%b,y,x),y-=a/b*x;
}
int inv(int x,int y){
	int a,b;
	exgcd(x,y,a,b);
	int c=a<0?a+y:a;
	return c;
}
int qpow(int a,int b,int mod){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
struct data{
	int x,y,p;
	data(){}
	data(int x,int y,int p):x(x),p(p),y(y){}
	data operator/(const data& d)const{return data(1ll*inv(d.x,p)*x%p,y-d.y,p);}
	data operator*(const data& d)const{return data(1ll*x*d.x%p,y+d.y,p);}
	int cal(int _p){return 1ll*x*qpow(_p,y,p)%p;}
}fac[maxn];
data C(int x,int y){
	if(x<0||x>y)return data(0,0,1);
	return fac[y]/fac[x]/fac[y-x];
}
int getans(int p,int P){
	int ans=0;
	fac[0]=data(1,0,P);
	for(int i=1;i<=n;++i){
		fac[i]=data(i,0,P);
		while(fac[i].x%p==0)fac[i].x/=p,fac[i].y++;
		fac[i]=fac[i]*fac[i-1];
	}
	for(int i=0;i<=n;++i){
		int x=(n-i)/2-((l&1)==(n-i&1)?l:l+1)/2,y=(n-i)/2-((r&1)==(n-i&1)?r:r-1)/2-1;
		if(x<0&&y<0)break;
		if(((l&1)==(n-i&1)?l:l+1)/2>((r&1)==(n-i&1)?r:r-1))continue;
		ans=(ans+1ll*C(i,n).cal(p)*(1ll*C(x,n-i).cal(p)-C(y,n-i).cal(p)+P))%P;
	//	printf("{%d(%d,%d,[%d,%d])}",ans,C(x,n-i).cal(p),C(y,n-i).cal(p),x,n-i);
	}
//	printf("[%d,%d]\n",P,ans);
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&r);
	int ans=0,z=1;
	for(int i=2;i*i<=m;++i)if(m%i==0){
		int p=i,P=1;
		while(m%i==0)m/=i,P*=i;
		int nz=z*P,x=1ll*inv(z%P,P)*(1ll*getans(i,P)-ans%P+P)%P;
		ans=(ans+1ll*x*z)%(nz),z=nz;
	}
	if(m>1){
		int P=m;
		int nz=z*P,x=1ll*inv(z%P,P)*(1ll*getans(P,P)-ans%P+P)%P;
		ans=(ans+1ll*x*z)%(nz),z=nz;
	}
	printf("%d",ans);
}