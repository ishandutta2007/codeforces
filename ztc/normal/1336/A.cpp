#include<stdio.h>
#include<algorithm>
int Last[1000002],Next[1000002],End[1000002],d[1000002],n,k,s[1000002];
void dfs(int p,int f){s[p]=1;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)d[End[i]]=d[p]+1,dfs(End[i],p),s[p]+=s[End[i]];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n+n-2;i+=2){
		scanf("%d%d",&End[i+1],&End[i]);
		Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
		Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
	}dfs(1,0);for(int i=1;i<=n;i++)d[i]-=s[i]-1;
	std::sort(d+1,d+n+1,[](int p,int q){return p>q;});
	long long cnt=0;for(int i=1;i<=k;i++)cnt+=d[i];
	printf("%lld",cnt);
}