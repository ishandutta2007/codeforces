#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=1e5+7;
inline ll qpow(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1){res*=a;if(res>=mod)res=res%mod+mod;}
		a=a*a;if(a>=mod)a=a%mod+mod;b>>=1;
	}
	return res;
}
inline int get_phi(int x){
	int res=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			res=res/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)res-=res/x;
	return res;
}
unordered_map<int,int>phi;
int n,Q,a[N];
ll dfs(int l,int r,int mod){
	if(l==r+1 || mod==1)return 1;
	return qpow(a[l],dfs(l+1,r,phi[mod]),mod);
}
int main(){
	n=read();int p=read(),pp=p;
	for(int i=1;i<=n;i++)a[i]=read();
	while(p>1)p=phi[p]=get_phi(p);
	Q=read();
	while(Q--){
		int l=read(),r=read();
		printf("%d\n",dfs(l,r,pp)%pp);
	}
	return 0;
}