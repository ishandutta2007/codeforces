#include<stdio.h>
int Last[400002],Next[2000002],End[2000002];
int mk1[400002],mk2[400002],n,m,s,l,t,cnt1,cnt2;
void dfs1(int p){
	mk1[p]=1;
	if(p==l)return;
	for(int i=Last[p];i;i=Next[i])if(!mk1[End[i]])dfs1(End[i]);
}
void dfs2(int p){
	mk2[p]=1;
	if(p==s)return;
	for(int i=Last[p];i;i=Next[i])if(!mk2[End[i]])dfs2(End[i]);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&s,&l);
		for(int i=1;i<=n;i++)Last[i]=mk1[i]=mk2[i]=0;
		for(int i=1;i<m+m;i+=2){
			scanf("%d%d",&End[i+1],&End[i]);
			Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
			Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
		}
		dfs1(s);dfs2(l);cnt1=cnt2=0;
		for(int i=1;i<=n;i++)cnt1+=mk1[i]&&!mk2[i],cnt2+=mk2[i]&&!mk1[i];
		printf("%lld\n",1ll*cnt1*cnt2);
	}
}