#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,k,l,mod,g[2],res;

struct jz{
	ll v[2][2];
}f,ans,nil;

jz operator * (jz a,jz b){
	jz c=nil;
	ll t;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			t=0;
			for (int k=0;k<2;k++){
				t=(t+a.v[i][k]*b.v[k][j])%mod;
			}
			c.v[i][j]=t;
		}
	}
	return c;
}

void doit(){
	memset(nil.v,0,sizeof nil.v);
	ans.v[0][0]=1; ans.v[0][1]=0;
	ans.v[1][0]=1; ans.v[1][1]=0;
	
	f.v[0][0]=1;   f.v[0][1]=1;
	f.v[1][0]=1;   f.v[1][1]=0;
	
	
	for (ll y=n-1;y>0;y>>=1){
		if (y&1){
			ans=f*ans;
		}
		f=f*f;
	}
	g[0]=(ans.v[0][0]+ans.v[1][0])%mod;
	
	ll t=1,x=2;
	for (ll y=n;y>0;y>>=1){
		if (y&1){
			t=(t*x)%mod;
		}
		x=(x*x)%mod;
	}
	g[1]=(t-g[0]+mod)%mod;
	//printf(" g0= %lld ; g1= %lld\n",g[0],g[1]);
}

int main(){
	cin>>n>>k>>l>>mod;
	if (k>=((ll)1<<l)&&l!=64){
		puts("0");return 0;
	}
	doit();
	
	res=1;
	for (int i=0;i<l;i++){
		res=(res*g[(k&(1ll<<i))>0?1:0])%mod;
	}
	res%=mod;
	cout<<res;
}