#include<stdio.h>
#define int long long
int Last[3002],Next[6002],End[6002],F[3002],df[3002][3002];
int f[3002][3002],rt,s[3002],maxs[3002],n,mk[3002],t[3002],g[3002],top=0;
inline int Max(int p,int q){return p>q?p:q;}
void getsiz(int p,int f){s[p]=1;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)getsiz(End[i],p),s[p]+=s[End[i]];
}
int getg(int p,int f,int ts){
	int g=0;maxs[p]=ts-s[p];
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f){
		int h=getg(End[i],p,ts);
		if(maxs[h]<maxs[g])g=h;
		if(s[End[i]]>maxs[p])maxs[p]=s[End[i]];
	}return maxs[p]<maxs[g]?p:g;
}
void dfs0(int p){t[++top]=p;g[p]=top;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=F[p])F[End[i]]=p,dfs0(End[i]);
}
int ANS=0;
void dfs(int p){
	for(int i=Last[p];i;i=Next[i])if(End[i]!=F[p])dfs(End[i]);
	for(int i=n;i>=1;i--)if(mk[t[i]]){
		int ans=0;
		for(int j=Last[p];j;j=Next[j])if(End[j]!=F[p]&&End[j]!=df[p][t[i]])ans=Max(ans,f[End[j]][t[i]]);
		for(int j=Last[t[i]];j;j=Next[j])if(End[j]!=F[t[i]])ans=Max(ans,f[p][End[j]]);
		f[p][t[i]]=f[t[i]][p]=ans+s[t[i]]*(df[p][t[i]]?s[rt]-s[df[p][t[i]]]:s[p]);
		ANS=Max(f[p][t[i]],ANS);
	}mk[p]=1;
}
void dfss(int p){
	for(int i=g[p]+s[p]-1;i>g[p];i--){
		int ans=0;
		for(int j=Last[p];j;j=Next[j])if(End[j]!=F[p]&&End[j]!=df[p][t[i]])ans=Max(ans,f[End[j]][t[i]]);
		for(int j=Last[t[i]];j;j=Next[j])if(End[j]!=F[t[i]])ans=Max(ans,f[p][End[j]]);
		ans=Max(ans,f[F[p]][t[i]]);
		f[p][t[i]]=f[t[i]][p]=Max(f[p][t[i]],ans+s[t[i]]*(s[rt]-s[df[p][t[i]]]));
		ANS=Max(f[p][t[i]],ANS);
	}
	for(int i=Last[p];i;i=Next[i])if(End[i]!=F[p])dfss(End[i]);
}
void gdf(int p,int d,int ff){
	df[ff][p]=d;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=F[p])gdf(End[i],d,ff);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n+n-2;i+=2){
		scanf("%lld%lld",&End[i],&End[i+1]);
		Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
		Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
	}getsiz(1,0);maxs[0]=1e9;rt=getg(1,0,s[1]);getsiz(rt,0);
	dfs0(rt);
	for(int i=1;i<=n;i++){
		for(int j=Last[i];j;j=Next[j])if(End[j]!=F[i])gdf(End[j],End[j],i);
	}
	dfs(rt);dfss(rt);
	int ans=0;
	for(int i=Last[rt];i;i=Next[i]){
		ans=Max(ans,f[rt][End[i]]);
	}printf("%lld",ANS);
}