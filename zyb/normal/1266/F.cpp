#include<bits/stdc++.h>
using namespace std;
#define N 1000005
struct pa {
	int x,y,z;
}b[N];
int aa[N],vis[N],a[N],A[N],B[N],fa[N],dis[N],q[N];
int si[N],last[N],to[N],Next[N],tot,n,m,Ans[N];
inline void add(int x,int y) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void build(int x) {
	int l=0,r=1; q[1]=x;
	dis[x]=fa[x]=0;
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=Next[i]) {
			if (fa[k]==to[i]) continue;
			fa[q[++r]=to[i]]=k;
			dis[to[i]]=dis[k]+1;
		}
	}
}
inline bool cmp(pa x,pa y) {
	return x.y<y.y;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		si[x]++,si[y]++;
		add(x,y),add(y,x);
	}
	build(1);
	for (int i=1;i<=n;i++) Ans[1]=max(Ans[1],si[i]+1);
	for (int i=n;i;i--) {
		int x=q[i];
		for (int j=last[x];j;j=Next[j]) {
			if (fa[x]==to[j]) continue;
			A[x]=max(A[x],A[to[j]]+1);
		}
	}
	for (int i=1;i<=n;i++) {
		int x=q[i],y=0;
		for (int j=last[x];j;j=Next[j]) {
			if (fa[x]==to[j]) continue;
			if (A[to[j]]+1==A[x]) y=to[j];
		}
		int s=0;
		for (int j=last[x];j;j=Next[j]) {
			if (fa[x]==to[j]) continue;
			if (to[j]!=y) B[to[j]]=max(B[x]+1,A[x]+1),s=max(s,A[to[j]]+1);
			
		}
		if (y) B[y]=max(B[x]+1,s+1);
	}		
	for (int i=1;i<=n;i++) {
		int r=0;
		for (int j=last[i];j;j=Next[j]) {
			if (fa[i]==to[j]) continue;
			a[++r]=A[to[j]]+1;
		}
		a[++r]=B[i];
		sort(a+1,a+1+r);
		int pp=0;
		a[r+1]=a[r]+1;
		for (int j=r;j;j--) {
			if (a[j]) Ans[2*a[j]-1]=max(Ans[2*a[j]-1],r-j+1);
			Ans[2*a[j]]=max(Ans[2*a[j]],r-j+1);
			if (a[j]==a[j+1]) pp++;
			else pp=0;
			Ans[2*a[j]+1]=max(Ans[2*a[j]+1],r-j+1-pp);
		}
	}
	for (int i=n;i;i--) Ans[i]=max(Ans[i],Ans[i+2]);
	for (int i=1;i<=n;i++) {
		int r=0;
		for (int j=last[i];j;j=Next[j]) {
			if (fa[i]==to[j]) continue;
			b[++r]=pa{to[j],A[to[j]]+1,1};
			for (int k=last[to[j]];k;k=Next[k]) {
				if (to[k]==i) continue;
				b[++r]=pa{to[j],A[to[k]]+1,0};
			}
		}
		b[++r]=pa{0,B[i],1};
		sort(b+1,b+1+r,cmp);
		int sum=0,ma=0;
		for (int j=r;j;j--) {
			
			if (b[j].z==1) sum++,vis[b[j].x]=(b[j].x!=0);
			if (b[j].z==0) {
				aa[b[j].x]++;
				ma=max(ma,aa[b[j].x]-vis[b[j].x]);
			}
			int ss=0;
			if (b[j].z==0) {
				ss=sum-vis[b[j].x];
				ss+=aa[b[j].x];
				Ans[2*b[j].y]=max(Ans[2*b[j].y],ss);
			}
			else {
				ss=sum+ma;
				Ans[2*b[j].y]=max(Ans[2*b[j].y],ss);
			}
		}
	}
	for (int i=n;i;i--) Ans[i]=max(Ans[i],Ans[i+2]);
	build(q[n]);
	int len=dis[q[n]];
	for (int i=1;i<=len;i++) Ans[i]=max(Ans[i],2);
	for (int i=len+1;i<=n;i++) Ans[i]=max(Ans[i],1);
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);
}