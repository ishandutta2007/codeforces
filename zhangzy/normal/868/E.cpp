#include<bits/stdc++.h>
#define inf 5202333
#define ll long long
using namespace std;

int n,f[55][55];
struct R{
	int to,val,nex;
}G[233];
int hea[55]={0},cnt=1,m,st,now,nil[55],d[55],l,r,mid,ans;
int fa[55],sz[55],tmp[55];

inline void dfs(int x,int fff){
	int y;
	nil[x]=1;
	for (int i=hea[x];i>0;i=G[i].nex){
		y=G[i].to; if (y==fff) continue;
		d[y]=d[x]+G[i].val;
		dfs(y,x);
		nil[x]=0;
	}
}

inline bool pd(){
	int t=0,mx;
	for (int i=1;i<=n;i++){
		if (!nil[i]) continue;
		mx=0;
		for (int j=0;j<now;j++){
			if (d[i]+f[i][j]>=mid)
				mx=max(mx,now-j);
		}
		t+=mx;
		if (t>=now) return 1;
	}
	return 0;
}

int GF(int x){
	return fa[x]==x? x: fa[x]=GF(fa[x]);
}
void ddd(int x,int fff){
	int y;
	nil[x]=1;
	for (int i=hea[x];i>0;i=G[i].nex){
		y=G[i].to; if (y==fff) continue;
		d[y]=d[x]+G[i].val;
		if (x!=st) fa[GF(y)]=GF(x);
		ddd(y,x);
		nil[x]=0;
	}
}
bool ppp(){
	memcpy(tmp,sz,sizeof tmp);
	int mx;
	for (int i=1;i<=n;i++){
		if (!nil[i]) continue;
		mx=0;
		for (int j=0;j<m;j++){
			if (d[i]+f[i][j]>=mid)
				mx=max(mx,m-j);
		}
		//if (mid==9) printf(" %d(%d,%d) %d\n",i,d[i],f[i][2],mx);
		tmp[GF(i)]-=mx;
	}
	for (int i=1;i<=n;i++){
		if (tmp[i]>0) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	int x,y,z;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[++cnt]=(R){y,z,hea[x]}; hea[x]=cnt;
		G[++cnt]=(R){x,z,hea[y]}; hea[y]=cnt;
	}
	scanf("%d%d",&st,&m);
	memset(f,0,sizeof f);
	for (now=1;now<=m;now++){
		for (int i=1;i<=n;i++){
			d[i]=0;
			dfs(i,0);
			for (l=0,r=inf;l<=r;){
				mid=(l+r)>>1;
				if (pd()){
					f[i][now]=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
		}
	}
	
	for (int i=1;i<=n;i++) fa[i]=i;
	d[st]=0;
	ddd(st,0);
	for (int i=1;i<=m;i++){
		scanf("%d",&x); if (x==st) continue;
		sz[GF(x)]++;
	}
	for (l=0,r=inf;l<=r;){
		mid=(l+r)>>1;
		if (ppp()){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
}