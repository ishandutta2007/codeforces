#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
namespace Pollard_Rho{
	int prime[9]={2,3,5,7,11,13,17,19,23};
	ULL RR;
	int Pcnt;
	LL p[70];
	vector <LL> res;
	LL R(LL mod){
		return (RR+=4179340454199820289LL)%mod;
	}
	LL Mul(LL x,LL y,LL mod){
/*		LL res=0;
		for (;y;y>>=1,x=(x<<1)%mod)
			if (y&1)
				res=(res+x)%mod;
		return res;*/
		LL d=(LL)floor((LD)x*y/mod+0.5);
		LL res=x*y-d*mod;
		if (res<0)
			res+=mod;
		return res;
	}
	LL Pow(LL x,LL y,LL mod){
		LL ans=1%mod;
		for (;y;y>>=1,x=Mul(x,x,mod))
			if (y&1)
				ans=Mul(ans,x,mod);
		return ans;
	}
	bool Miller_Rabin(LL n){
		if (n<=1)
			return 0;
		for (int i=0;i<9;i++)
			if (n==prime[i])
				return 1;
		LL d=n-1;
		int tmp=0;
		while (!(d&1))
			d>>=1,tmp++;
		for (int i=0;i<9;i++){
			LL x=Pow(prime[i],d,n),p=x;
			for (int j=1;j<=tmp;j++){
				x=Mul(x,x,n);
				if (x==1&&p!=1&&p!=n-1)
					return 0;
				p=x;
			}
			if (x!=1)
				return 0;
		}
		return 1;
	}
	LL f(LL x,LL c,LL mod){
		return (Mul(x,x,mod)+c)%mod;
	}
	LL gcd(LL x,LL y){
		return y?gcd(y,x%y):x;
	}
	LL Get_Factor(LL c,LL n){
		LL x=R(n),y=f(x,c,n),p=n;
		while (x!=y&&(p==n||p==1)){
			p=gcd(n,max(x-y,y-x));
			x=f(x,c,n);
			y=f(f(y,c,n),c,n);
		}
		return p;
	}
	void Pollard_Rho(LL n){
		if (n<=1)
			return;
		if (Miller_Rabin(n)){
			res.push_back(n);
			return;
		}
		while (1){
			LL v=Get_Factor(R(n-1)+1,n);
			if (v!=n&&v!=1){
				Pollard_Rho(v);
				Pollard_Rho(n/v);
				return;
			}
		}
	}
	void work(LL n){
		res.clear();
		Pollard_Rho(n);
	}
}
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
const int N=200005;
int n;
LL x,y,a[N];
LL v[16],vc=0,xc[16],yc[16],c[16];
vector <LL> Mul_x;
LL A[1<<15];
void Get_V(){
	memset(xc,0,sizeof xc);
	memset(yc,0,sizeof yc);
	Pollard_Rho :: work(y);
	vector <LL> xx=Pollard_Rho :: res;
	sort(xx.begin(),xx.end());
	v[vc=1]=xx[0],yc[vc]=1;
	for (int i=1;i<xx.size();i++)
		if (xx[i]==xx[i-1])
			yc[vc]++;
		else
			v[++vc]=xx[i],yc[vc]=1;
	LL xv=x;
	for (int i=1;i<=vc;i++)
		while (xv%v[i]==0)
			xv/=v[i],xc[i]++;
}
void FWT(LL a[],int n,int flag){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++)
				a[i+j]+=a[i+j+d]*flag;
}
int main(){
	n=read(),x=read(),y=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	if (y%x){
		putchar('0');
		return 0;
	}
	if (y==1){
		int ans=0;
		for (int i=1;i<=n;i++)
			if (a[i]==1)
				ans++;
		printf("%I64d",1LL*ans*ans);
		return 0;
	}
	Get_V();
	Mul_x.clear();
	memset(A,0,sizeof A);
	for (int i=1;i<=n;i++){
		if (a[i]%x==0)
			Mul_x.push_back(a[i]);
		if (y%a[i]==0){
			memset(c,0,sizeof c);
			LL yv=a[i];
			for (int i=1;i<=vc;i++)
				while (yv%v[i]==0)
					yv/=v[i],c[i]++;
			int s=0;
			for (int i=1;i<=vc;i++)
				if (c[i]==yc[i])
					s|=1<<(i-1);
			A[s]++;
		}
	}
	FWT(A,1<<vc,1);
	LL ans=0;
	for (int i=0;i<Mul_x.size();i++){
		LL now=Mul_x[i];
		memset(c,0,sizeof c);
		LL yv=now;
		for (int i=1;i<=vc;i++)
			while (yv%v[i]==0)
				yv/=v[i],c[i]++;
		int s=(1<<vc)-1;
		for (int i=1;i<=vc;i++)
			if (c[i]==xc[i]||xc[i]==yc[i])
				s^=1<<(i-1);
		ans+=A[s];
	}
	printf("%I64d",ans);
    return 0;
}