#include<stdio.h>
#include<memory.h>
int Last[40012],Next[1000002],End[1000002],Len[1000002],dis[40012],cur[40012],a[202][202],tot=1,n,m,T,ans=0;
void addedge(int s,int t,int v1,int v2){
	End[++tot]=t;Next[tot]=Last[s];Last[s]=tot;Len[tot]=v1;
	End[++tot]=s;Next[tot]=Last[t];Last[t]=tot;Len[tot]=v2;
}
bool bfs(){
	memset(dis,-1,sizeof(dis));dis[T]=0;
	static int q[80012];int f=0,b=0;q[b++]=T;
	while(f!=b)for(int p=q[f++],i=Last[p];i;i=Next[i])if(Len[i^1]&&!~dis[End[i]])dis[q[b++]=End[i]]=dis[p]+1;
	return ~dis[1];
}
int dfs(int p,int v){
	if(p==T)return v;int cnt=0;
	for(int i=cur[p];i;i=cur[p]=Next[i])if(dis[End[i]]==dis[p]-1&&Len[i]){
		int v0=dfs(End[i],Len[i]<v-cnt?Len[i]:v-cnt);
		Len[i]-=v0;Len[i^1]+=v0;cnt+=v0;if(cnt==v)return cnt;
	}return cnt;
}
int main(){
	scanf("%d%d",&n,&m);T=n*m+2;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		char c=getchar();
		while(c<'!')c=getchar();
		a[i][j]=c=='#';
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]){ans++;
		if(a[i-1][j]||a[i+1][j])addedge(1,i*m+j-m+1,a[i-1][j]+a[i+1][j],0);
		if(a[i][j-1]||a[i][j+1])addedge(i*m+j-m+1,T,a[i][j-1]+a[i][j+1],0);
		if(a[i+1][j])addedge(i*m+j-m+1,i*m+j+1,1,1),ans--;
		if(a[i][j+1])addedge(i*m+j-m+1,i*m+j-m+2,1,1),ans--;
	}ans<<=1;while(bfs())memcpy(cur,Last,sizeof(cur)),ans+=dfs(1,1e9);printf("%d",ans>>1);
}