#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,mo=1e9+7;
struct P{
	ll x,y;
	inline void in(){scanf("%lld%lld",&x,&y);}
	inline ll operator*(const P&rhs)const{return x*rhs.y-rhs.x*y;}
	inline P operator+(const P&rhs)const{return (P){x+rhs.x,y+rhs.y};}
	inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
	inline void moo(){x%=mo;y%=mo;}
}a[N],s2[N];
int n,i,j,ans,s1[N];
ll s0[N],z,tot;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)a[i].in(),s2[i]=s2[i-1]+a[i],s2[i].moo();
	for(i=2;i<=n;++i)z=a[i-1]*a[i],s0[i]=s0[i-1]+z,s1[i]=(s1[i-1]+s0[i])%mo;
	tot=abs(s0[n+1]=s0[n]+a[n]*a[1]);
	for(i=3,j=1;i<=n;++i){
		for(;j<i-1 && abs(s0[i]-s0[j]+a[i]*a[j])>tot/2.0;++j);
		ans=(ans+s0[i]%mo*(i-1-j)-(s1[i-2]-s1[j-1])+a[i]*(s2[i-2]-s2[j-1]))%mo;
		ans=(ans+s1[j-1]+s2[j-1]*a[i]+(s0[n+1]-s0[i])%mo*(j-1))%mo;
	}
	ans=((tot%mo*(mo+1>>2)%mo*n%mo*(n-3)%mo+ans)%mo+mo)*2%mo;
	printf("%d\n",ans);
	return 0;
}