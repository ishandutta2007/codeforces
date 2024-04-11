#include<stdio.h>
int Last[1000002],Next[2000002],End[2000002],Len[2000002],s[1000002],n,t;
long long ans1,ans2;
inline int Min(int p,int q){return p<q?p:q;}
void dfs(int p,int f){
	s[p]=1;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)dfs(End[i],p),ans1+=s[End[i]]&1?Len[i]:0,ans2+=1ll*Min(s[End[i]],n-s[End[i]])*Len[i],s[p]+=s[End[i]];
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);n<<=1;ans1=ans2=0;
		for(int i=1;i<=n;i++)Last[i]=0;
		for(int i=1;i<n+n-2;i+=2){
			scanf("%d%d%d",&End[i+1],&End[i],&Len[i]);Len[i+1]=Len[i];
			Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
			Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
		}dfs(1,0);
		printf("%lld %lld\n",ans1,ans2);
	}
}