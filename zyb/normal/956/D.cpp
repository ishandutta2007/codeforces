#include<bits/stdc++.h>
#define N 200005
#define lowbit(o) o&-o
using namespace std;
struct node {
	int x,y,v,id;
}a[N],q[N],b[N];
int i,j,k,l,s,n,m,r,f[N],tot;
long long ans;
inline bool cmp(node x,node y) {
	return (1ll*x.x*y.y)<(1ll*x.y*y.x);
}
inline bool check(node x,node y) {
	return (1ll*x.x*y.y)==(1ll*x.y*y.x);
}
inline void work(node x,int y) {
	if (x.id>n) a[x.id-n].x=y;
	else a[x.id].y=y;
}
inline void change(int x) {
	for (;x;x-=lowbit(x)) f[x]++;
}
inline int ask(int x) {
	int s=0;
	for (;x<=tot;x+=lowbit(x)) s+=f[x];
	return s;
}
inline void change1(int x) {
	for (;x<=tot;x+=lowbit(x)) f[x]++;
}
inline int ask1(int x) {
	int s=0;
	for (;x;x-=lowbit(x)) s+=f[x];
	return s;
}
inline bool cmp1(node x,node y) {
	if (x.y!=y.y) return x.y<y.y;
	return x.v>y.v;
}
inline bool cmp2(node x,node y) {
	if (x.y!=y.y) return x.y<y.y;
	return x.x>y.x;
}
inline void work(node b[]) {
	sort(b+1,b+1+r,cmp2);
	for (int i=1;i<=r;i++) {
		ans+=ask(b[i].x);
		change(b[i].x);
	}
	for (int i=1;i<=tot;i++) f[i]=0;
}
inline bool Cmp(node x,node y) {
	if (x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
inline void work1(node b[]) {
	for (int i=1;i<=n;i++) if (b[i].v==2) swap(b[i].x,b[i].y);
	sort(b+1,b+1+n,cmp1);
	for (int i=1;i<=n;i++) {
		if (b[i].v==1) ans+=ask(b[i].x);
		else change(b[i].x);
	}
/*	for (int i=1;i<=n;i++) swap(b[i].x,b[i].y);
	sort(b+1,b+1+n,cmp1);
	for (int i=1;i<=tot;i++) f[i]=0;
	for (int i=1;i<=n;i++) {
		if (b[i].v==2) ans+=ask(b[i].x);
		else change(b[i].x);
	}
	for (int i=1;i<=tot;i++) f[i]=0;
	for (int i=1;i<=n;i++) if (b[i].v==1) swap(b[i].x,b[i].y);
	sort(b+1,b+1+n,Cmp);
	int j;
	for (int i=1;i<=n;i=j) {
		j=i+1;
		int s1=0,s2=0;
		if (a[i].v==1) s1++;
		else s2++;
		while (j<=n&&b[j].x==b[i].x&&b[j].y==b[i].y) {
			if (a[j].v==1) s1++;
			else s2++;
			j++;
		}
		ans-=s1*s2;
	}*/
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x<0) a[i].v=1;
		else a[i].v=2;
		q[++r].x=abs(a[i].x);
		q[r].y=abs(a[i].y)-m;
		q[r].id=i;
		q[++r].x=abs(a[i].x);
		q[r].y=abs(a[i].y)+m;
		q[r].id=i+n;
		a[i].id=i;
	}
	sort(q+1,q+1+r,cmp);
	work(q[1],tot=1);
	for (i=2;i<=r;i++) {
		if (!check(q[i],q[i-1])) tot++;
		work(q[i],tot);
	}
	r=0;
	for (i=1;i<=n;i++) if (a[i].v==1) b[++r]=a[i];
	work(b);
	r=0;
	for (i=1;i<=n;i++) if (a[i].v==2) b[++r]=a[i];
	work(b);
	work1(a);
	printf("%I64d\n",ans);
}