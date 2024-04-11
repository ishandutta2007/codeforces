#include<bits/stdc++.h>
using namespace std;

int n,m,p,cnt,fa[101000],sz[101000];
long long ans=1;

int GF(int x){
	return x==fa[x]? x: fa[x]=GF(fa[x]);
}

int main(){
	cin>>n>>m>>p; if (p==1) return 0*puts("0");
	for (int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for (int x,y;m--;){
		scanf("%d%d",&x,&y);
		if (GF(x)!=GF(y)){
			sz[GF(y)]+=sz[GF(x)];
			fa[GF(x)]=GF(y);
		}
	}
	for (int i=1;i<=n;i++) if (fa[i]==i){
		ans=ans*sz[i]%p;
		cnt++;
	}
	if (cnt==1) return 0*puts("1");
	for (int i=1;i<cnt-1;i++)
		ans=ans*n%p;
	cout<<ans;
}