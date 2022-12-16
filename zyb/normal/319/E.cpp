#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#define N 100005
using namespace std;
vector<int>::iterator it;
vector<int>f[N*20];
int T,i,j,k,l,s,n,m,r,q[N*50],tot;
map<int,int>ma;
struct node {
	int id,x,y;
}b[N],a[N];
int fa[N];
inline int get(int o) {
	if (fa[o]==o) return o;
	return fa[o]=get(fa[o]);
}
inline bool baohan(int x,int y) {
	if (b[y].x>b[x].x&&b[y].x<b[x].y) return true;
	if (b[y].y>b[x].x&&b[y].y<b[x].y) return true;
	return false;
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
	if (ll>rr) return ;
	if (l==ll&&r==rr) {
		f[o].push_back(p); return ;
	}
	int mid=(l+r)>>1;
	if (rr<=mid) change(o*2,l,mid,ll,rr,p);
	else if (ll>mid) change(o*2+1,mid+1,r,ll,rr,p);
	else change(o*2,l,mid,ll,mid,p),change(o*2+1,mid+1,r,mid+1,rr,p);
}
inline void ask(int o,int l,int R,int ll) {
	for (it=f[o].begin();it!=f[o].end();it++) 
	q[++r]=(*it);
	f[o].clear();
	if (l==ll&&R==ll) return ;
	int mid=(l+R)>>1;
	if (ll<=mid) ask(o*2,l,mid,ll);
	else ask(o*2+1,mid+1,R,ll);
}
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d%d%d",&a[i].id,&a[i].x,&a[i].y),q[++r]=a[i].x,q[++r]=a[i].y;
	sort(q+1,q+1+r);
	for (i=1;i<=r;i++) if (!ma[q[i]]) ma[q[i]]=++tot;
	T=0;
	for (i=1;i<=n;i++) {
		if (a[i].id==1) {
			a[i].x=ma[a[i].x];
			a[i].y=ma[a[i].y];
			fa[++T]=T;
			b[T]=a[i];
			q[r=1]=T;
			ask(1,1,tot,a[i].x);
			ask(1,1,tot,a[i].y);
			for (j=2;j<=r;j++) {
				int gt=get(q[j-1]),gtw=get(q[j]);
				b[gtw].x=min(b[gtw].x,b[gt].x),b[gtw].y=max(b[gtw].y,b[gt].y);
				fa[gt]=gtw;
			}
			change(1,1,tot,b[get(q[1])].x+1,b[get(q[1])].y-1,get(q[1]));
		}
		else {
			int gt=get(a[i].x),gtw=get(a[i].y);
			if (gt==gtw) printf("YES\n");
			else if (baohan(gtw,gt)) printf("YES\n");
			else printf("NO\n");
		}
	}
}