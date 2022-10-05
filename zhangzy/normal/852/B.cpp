#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,k,m,a[1001000],b[1001000],c[1001000];
ll g[110]={0},gg[110]={0},h[110]={0},cnt[110]={0};
struct jz{
	ll v[102][102];
	void pri(){
		for (int i=0;i<m;i++){
			for (int j=0;j<m;j++){
				printf(" %lld",v[i][j]);
			}printf("\n");
		}
	}
}f[20],nil,an;

jz cheng(jz f1,jz f2){
	jz f3=nil;ll t;
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			t=0;
			for (int k=0;k<m;k++){
				t=(t+f1.v[i][k]*f2.v[k][j])%mod;
			}
			f3.v[i][j]=t;
		}
	}
	return f3;
}

void doit(){
	k-=2;
	memset(nil.v,0,sizeof nil.v);
	f[0]=nil;
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			f[0].v[i][j]=cnt[(i-j+m)%m];
		}
	}
	for (int i=1;i<20;i++){
		f[i]=cheng(f[i-1],f[i-1]);
	}
	//f[0].pri();
	an=nil;
	an.v[0][0]=1;
	for (int i=19;i>=0;i--){
		if (k>=(1<<i)){
			k-=(1<<i);
			an=cheng(f[i],an);
		}
	}
	for (int i=0;i<m;i++){
		g[i]=an.v[i][0];
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		g[a[i]%m]++;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		cnt[b[i]%m]++;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		gg[(b[i]+c[i])%m]++;
	}
	int t;
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			t=(i+j)%m;
			h[t]=(h[t]+g[i]*gg[j])%mod;
		}
	}
	for (int i=0;i<m;i++){
		gg[i]=h[i];
	}
	memset(g,0,sizeof g);
	memset(h,0,sizeof h);
	
	doit();
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			t=(i+j)%m;
			h[t]=(h[t]+g[i]*gg[j])%mod;
		}
	}
	printf("%I64d\n",h[0]);
}