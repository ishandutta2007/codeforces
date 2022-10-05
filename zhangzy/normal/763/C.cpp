#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace has{
	int v,p=9999991,b[10101000];
	void RE(){
		memset(b,-1,sizeof b);
	}
	void add(int x){
		v=(ll)x*x%p;
		while (~b[v]&&b[v]!=x) v++;
		b[v]=x;
	}
	bool fin(int x){
		v=(ll)x*x%p;
		while (~b[v]&&b[v]!=x) v++;
		return b[v]==x;
	}
}

int n,mod,a[101000],num[101000];
ll inv,sum=0,st,cc,tmp;

ll K(ll x,int y){
	ll t=1; for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod; return t;
}

bool check(){
	if (cc>mod/2||cc==0) return 0;
	if (mod-n<=700){
		for (int i=mod-n;i>0;i--){
			tmp=(st-cc*i)%mod;
			tmp=(tmp+mod)%mod;
			if (has::fin(tmp)) return 0;
		}
		return 1;
	}else{
		for (int i=1;i<n;i++){
			tmp=(st+cc*num[i])%mod;
			if (!has::fin(tmp)) return 0;
		}
		return 1;
	}
}

int main(){
	//freopen("pacifist.in","r",stdin); freopen("pacifist.out","w",stdout);
	has::RE();
	scanf("%d%d",&mod,&n);
	if (n==mod) return 0*printf("0 1");
	for (int i=1;i<n;i++) num[i]=i;
	srand(time(0));
	for (int tim=10;tim--;) random_shuffle(num+1,num+n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		has::add(a[i]);
		sum+=a[i];
	}
	if (n==1) return 0*printf("%d 1",a[1]);
	inv=K((ll)n*(n-1)/2%mod,mod-2);
	for (int i=1;i<=n;i++){
		st=a[i];
		cc=(sum-st*n)%mod*inv%mod;
		cc=(cc+mod)%mod;
		if (check()) return 0*printf("%lld %lld",st,cc);
	}
	puts("-1");
}