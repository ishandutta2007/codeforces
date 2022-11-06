#include<stdio.h>
#include<queue>
#include<memory.h>
int Last1[20002],Next1[40002],End1[40002],d[20002],l[20002][16],e[20002],n,m,T;
int Last[320002],Next[10000002],End[10000002],Len[10000002],tot=1,dis[320002],cur[320002],mk[320002];
void add(int s,int t,int l){End[++tot]=t;Next[tot]=Last[s];Last[s]=tot;Len[tot]=l;End[++tot]=s;Next[tot]=Last[t];Last[t]=tot;Len[tot]=0;}
void dfs0(int p,int f){
	d[p]=d[l[p][0]=f]+1;add(1+m+p,T,1);
	for(int i=1;i<=14;i++)(l[p][i]=l[l[p][i-1]][i-1])&&(add(1+m+p+n*i,1+m+p+n*(i-1),1e6),add(1+m+p+n*i,1+m+l[p][i-1]+n*(i-1),1e6),1);
	for(int i=Last1[p];i;i=Next1[i])if(End1[i]!=f)e[End1[i]]=i+1>>1,dfs0(End1[i],p);
}
bool bfs(){
	static int st[320002];int f=0,b=0;st[b++]=T;memset(dis,0xff,sizeof(dis));memset(mk,0,sizeof(mk));dis[T]=1;
	while(f!=b){
		int p=st[f++];mk[p]=1;
		for(int i=Last[p];i;i=Next[i])if(Len[i^1]&&!~dis[End[i]])dis[End[i]]=dis[p]+1,st[b++]=End[i];
	}return ~dis[1];
}
int dfs(int p,int v){
	if(p==T)return v;int cnt=0;
	for(int i=cur[p];i;cur[p]=i=Next[i])if(Len[i]&&dis[End[i]]+1==dis[p]){
		int a=dfs(End[i],v-cnt>Len[i]?Len[i]:v-cnt);
		Len[i]-=a;Len[i^1]+=a;cnt+=a;if(cnt==v)return cnt;
	}return cnt;
}
int main(){
	scanf("%d%d",&n,&m);T=n*15+m+2;
	for(int i=1;i<n+n-2;i+=2){
		scanf("%d%d",End1+i+1,End1+i);
		Next1[i]=Last1[End1[i+1]];Last1[End1[i+1]]=i;
		Next1[i+1]=Last1[End1[i]];Last1[End1[i]]=i+1;
	}for(int i=1;i<=m;i++)add(1,i+1,1);dfs0(1,0);
	for(int i=2;i<=m+1;i++){
		int p,q;scanf("%d%d",&p,&q);
		for(int j=14;~j;j--)d[l[p][j]]>=d[q]&&(add(i,1+m+p+n*j,1e6),p=l[p][j]),d[l[q][j]]>=d[p]&&(add(i,1+m+q+n*j,1e6),q=l[q][j]);
		for(int j=14;~j;j--)l[p][j]!=l[q][j]&&(add(i,1+m+p+n*j,1e6),add(i,1+m+q+n*j,1e6),p=l[p][j],q=l[q][j]);
		if(p!=q)add(i,1+m+p,1e6),add(i,1+m+q,1e6);
	}int cnt=0;
	while(bfs())memcpy(cur,Last,sizeof(Last)),cnt+=dfs(1,1e8);
	printf("%d\n",cnt);std::queue<int>ans;
	for(int i=2;i<tot;i+=2)if(End[i^1]==1&&(mk[End[i]]^mk[End[i^1]]))ans.push(End[i]-1);
	printf("%d ",ans.size());while(!ans.empty())printf("%d ",ans.front()),ans.pop();puts("");
	for(int i=2;i<tot;i+=2)if(End[i]==T&&(mk[End[i]]^mk[End[i^1]]))ans.push(End[i^1]-m-1);
	printf("%d ",ans.size());while(!ans.empty())printf("%d ",e[ans.front()]),ans.pop();
}