#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=5005;
int n,m,i,j,s[N],f[N],h[N],lb[N],rb[N],ans1,ans2;
vector<int>ve[N];
void solve(int x,int y,int k){
	int v1=0,v2=1;
	for(j=1;j<=n;++j)if(!ve[j].empty()){
		static int f[2][2],nf[2][2];memset(f,0,sizeof f);f[0][0]=1;
		for(int u:ve[j]){
			memcpy(nf,f,sizeof f);
			for(int a=0;a<2;++a)for(int b=0;b<2;++b){
				if(rb[u]>=y && !b)nf[a][1]+=f[a][b];
				if(lb[u]<=x && !a)nf[1][b]+=f[a][b];
			}
			memcpy(f,nf,sizeof f);
		}
		if(f[1][1])v1+=2,v2=1ll*v2*f[1][1]%mo;
			else if(f[1][0] || f[0][1])++v1,v2=1ll*v2*(f[1][0]+f[0][1])%mo;
	}
	if(k==-1)v2=mo-v2;
	if(v1>ans1)ans1=v1,ans2=v2;else if(v1==ans1)ans2=(ans2+v2)%mo;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",s+i);
	for(i=1;i<=m;++i){
		scanf("%d%d",f+i,h+i);
		ve[f[i]].push_back(i);
		int x;
		for(j=1,x=0;j<=n && x<h[i];++j)x+=f[i]==s[j];if(x==h[i])lb[i]=j-1;else lb[i]=n+1;
		for(j=n,x=0;j && x<h[i];--j)x+=f[i]==s[j];if(x==h[i])rb[i]=j+1;else rb[i]=0;
	}
	solve(0,1,1);
	for(i=1;i<=n;++i)solve(i,i+1,1),solve(i-1,i+1,-1);
	printf("%d %d\n",ans1,ans2);
	return 0;
}