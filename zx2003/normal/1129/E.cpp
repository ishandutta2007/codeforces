#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N],i,j,t,sz[N],eu[N],ev[N],ecnt,id[N];
bool cmp(int x,int y){return sz[x]>sz[y];}
bool vi[N];
void dfs(int u){
	int l,r,m,v=id[u]+1,i,z;vi[u]=1;
	for(;;){
		for(z=0,i=v;i<=n;++i)z+=!vi[a[i]];
		if(!z)return;
		printf("1\n1\n%d\n",z);
		for(i=v;i<=n;++i)if(!vi[a[i]])printf("%d ",a[i]);
		printf("\n%d\n",u);fflush(stdout);
		scanf("%d",&z);if(!z)return;
		for(l=v,r=n;l<r;){
			m=(l+r)>>1;
			for(z=0,i=v;i<=m;++i)z+=!vi[a[i]];
			if(!z){l=m+1;continue;}
			printf("1\n1\n%d\n",z);
			for(i=v;i<=m;++i)if(!vi[a[i]])printf("%d ",a[i]);
			printf("\n%d\n",u);fflush(stdout);
			scanf("%d",&z);if(z)r=m;else l=m+1;
		}
		eu[++ecnt]=u;ev[ecnt]=a[l];
		dfs(a[l]);v=l+1;
	}
}
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;++i){
		a[i]=i;
		printf("1\n1\n%d\n",n-1);
		for(j=2;j<=n;++j)printf("%d ",j);
		printf("\n%d\n",i);fflush(stdout);
		scanf("%d",sz+i);
	}
	sort(a+2,a+n+1,cmp);for(i=1;i<=n;++i)id[a[i]]=i;id[1]=1;
	dfs(1);
	puts("ANSWER");for(i=1;i<n;++i)printf("%d %d\n",eu[i],ev[i]);fflush(stdout);
	return 0;
}