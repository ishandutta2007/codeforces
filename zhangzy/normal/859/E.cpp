#include<bits/stdc++.h>
using namespace std;
int n,fa[201000],fl[201000],sz[201000],die[201000];
long long ans=1,mod=1000000007;
int GF(int x){
	return x==fa[x]?x:fa[x]=GF(fa[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++){
		fa[i]=i;sz[i]=1;fl[i]=0;
	}
	for (int i=1,x,y,fx,fy;i<=n;i++){
		scanf("%d%d",&x,&y);
		if (x==y){
			fl[GF(x)]=die[GF(x)]=1;
		}else if ((fx=GF(x))==(fy=GF(y))){
			fl[fx]=1;
		}else{
			fa[fx]=fy;
			sz[fy]+=sz[fx];
			fl[fy]|=fl[fx];
			die[fy]|=die[fx];
		}
	}
	for (int i=1;i<=n*2;i++){
		if (GF(i)==i){
			ans=ans*(fl[i]?(die[i]?1:2):sz[i])%mod;
		}
	}
	cout<<ans;
}