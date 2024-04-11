#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[101000][2]={0},ans=0;
int n,hea[101000]={0},cnt=1,fa[101000]={0},las=1,yz[101000]={0};
struct R{
	int to,nex;
}r[222222];

ll NY(ll a){
    ll c = 1; 
	for (int b=mod-2;b; b >>= 1, a = a * a % mod)
        if (b & 1) c = c * a % mod;
    return c;
}

void RE(int x){
	int y,fl=0;
	ll t0=1,t1=1;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fa[x]) continue;
		t0=(t0*f[y][0])%mod;t1=(t1*f[y][1])%mod;
		fl=1;
	}
	if (!fl) {
		t1=0;
		yz[x]=1;
	}
	f[x][1]=f[x][0]=(t0+t1)%mod;
}

void ddd(int x,int fff){
	fa[x]=fff;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fff) continue;
		ddd(y,x);
	}
	RE(x);
}

void cg(int x){
	if (x==las) return;
	fa[las]=x;fa[x]=0;
	ll tt=NY(f[x][0]);
	if (yz[las]) {
		f[las][0]=f[las][1]=1;
	}else{
		f[las][0]=(f[las][0]*tt)%mod;f[las][1]=(f[las][1]*tt)%mod;
	}
	tt=f[las][0];if (yz[x]) tt<<=1;
	f[x][0]=(f[x][0]*tt)%mod;f[x][1]=(f[x][1]*tt)%mod;
	las=x;
}
void dfs(int x,int fff){
	cg(x);
	ans=(ans+f[x][0])%mod;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fff) continue;
		dfs(y,x);
		cg(x);
	}
}

int main(){
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		r[++cnt]=(R){y,hea[x]};hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]};hea[y]=cnt;
	}
	memset(f,0,sizeof f);
	ddd(1,0);
	int tmp=0;
	for (int i=hea[1];i>0;i=r[i].nex){
		tmp++;
		yz[1]=tmp==1?1:0;
	}
	
	dfs(1,0);
	ans=(ans%mod+mod)%mod;
	printf("%I64d\n",ans);
}