#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=305,mod=1e9+7;
inline void dec(int &x,int y){x-=y,x+=x>>31&mod;}
inline void inc(int &x,int y){x+=y-mod,x+=x>>31&mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,m,K;
struct poly{
	int a[N];
	poly(){
		for(int i=1;i<m;i++)a[i]=0;
	}
	int& operator [](int i){return a[i];}
	poly& operator +=(poly b){
		for(int i=1;i<m;i++)inc(a[i],b[i]);
		return *this;
	}
	poly& operator -=(poly b){
		for(int i=1;i<m;i++)dec(a[i],b[i]);
		return *this;
	}
	poly& operator *=(int x){
		for(int i=1;i<m;i++)a[i]=1ll*a[i]*x%mod;
		return *this;
	}
	poly operator +(poly b){
		poly c=*this;
		return c+=b;
	}
	poly operator -(poly b){
		poly c=*this;
		return c-=b;
	}
	poly operator *(int x){
		poly c=*this;
		return c*=x;
	}
}a[N],x[N][N],s[N][N];
int inv[N];
inline void gauss(int n){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			if(a[j][i]){swap(a[i],a[j]);break;}
		a[i]*=qpow(a[i][i],mod-2);
		for(int j=1;j<=n;j++)
			if(i^j)a[j]-=a[i]*a[j][i];
	}
}
int main(){
	n=read(),K=read(),m=read();
	if(K==1 || K==n)printf("%d\n",n),exit(0);
	inv[1]=1;
	for(int i=2;i<=m;i++)inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
	for(int i=3;i<=m;i++)
		x[i][2][i-2]=1;
	for(int j=2;j<m;j++){
		poly sum;
		for(int i=j+1;i<=m;i++){
			poly &t=x[i+1][j+1];
			t=x[i][j];
			t-=x[i+1][j]*(1ll*(i+1-j)*(m-i)*inv[i+1]%mod*inv[m]%mod);
			t-=(sum+s[i-1][j-1])*(1ll*i*inv[i-1]%mod*inv[m]%mod);
			dec(t[m-1],1ll*(i+1)*i*inv[m]%mod*inv[i-1]%mod);
			if(i==m){
				a[j-1]=t;
				a[j-1][m-1]=(mod-a[j-1][m-1])%mod;
				break;
			}
			t*=1ll*m*(i+1)*inv[m-i]%mod*inv[j]%mod;
			sum+=x[i][j],s[i][j]=s[i-1][j-1]+x[i][j];
		}
	}
	gauss(m-2);int ans=x[n][K][m-1];
	for(int i=1;i<=m-2;i++)
		inc(ans,1ll*a[i][m-1]*x[n][K][i]%mod);
	printf("%d\n",ans);
	return 0;
}