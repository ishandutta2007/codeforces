#include<bits/stdc++.h>
using namespace std;

struct E{
	int u,v,w;
}e[202000];

int n,m,fa[202000],die[202000],ans=0;

int GF(int x){
	return x==fa[x]? x: fa[x]=GF(fa[x]);
}

bool cmp(E e1,E e2){
	return e1.w>e2.w;
}

void doit(E t){
	int f1=GF(t.u),f2=GF(t.v);
	if (f1==f2){
		if (!die[f1]){
			die[f1]=1;
			ans+=t.w;
		}
	}else{
		if (die[f1]+die[f2]!=2){
			ans+=t.w;
			die[f2]|=die[f1];
			fa[f1]=f2;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	
	for (int i=1;i<=m;i++){
		doit(e[i]);
	}
	cout<<ans;
}