#include<cstdio>
#include<vector>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,ans[100039],a[100039],pus,maxn;
int last[100039],f[400039],g[100039];
inline void get(int x,int z,int l,int r,int now){
	if(l==r){f[now]=z;return;}
	int m=(l+r)>>1;
	if(x<=m) get(x,z,l,m,now<<1);
	else get(x,z,m+1,r,now<<1|1);
	f[now]=min(f[now<<1],f[now<<1|1]);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now];
	int m=(l+r)>>1,fs1=1e9,fs2=1e9;
	if(x<=m) fs1=find(x,y,l,m,now<<1);
	if(y>m)fs2=find(x,y,m+1,r,now<<1|1);
	return min(fs1,fs2);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]),ans[1]|=(a[i]!=1?1:0),ans[2]|=(a[i]==1?1:0);
	for(i=1;i<=n;i++){
		g[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		get(a[i],i,1,n+1,1);
		if(a[i]!=1){
			pus=find(1,a[i]-1,1,n+1,1);
			//printf("%d %d\n",a[i],pus);
			if(pus>g[i]) ans[a[i]]=1; 
		}
	}
	for(i=2;i<=maxn+1;i++){
	//	printf("%d %d\n",i,find(1,i-1,1,n+1,1));
		if(find(1,i-1,1,n+1,1)>last[i]) ans[i]=1;
	}
	for(i=1;i<=n+2;i++) if(!ans[i]){printf("%d\n",i);return 0;}
}