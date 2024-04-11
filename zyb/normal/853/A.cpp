#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define N 300005
#define lowbit(o) o&(-o)
using namespace std;
int r,i,j,k,l,s,n,m,da[N],a[N];
long long ans;
struct node {
	int id,v;
}t[N];
inline void up(int x) {
	while (x>1) {
		int j=x>>1;
		if (t[j].v<t[x].v) swap(t[j],t[x]);
		else return ;
		x=j;
	}
}
inline void insert(int x,int y) {
	t[++r].id=x;
	t[r].v=y;
	up(r);
}
inline void down(int x) {
	while ((x<<1)<=r) {
		int j=x<<1;
		if (j+1<=r&&t[j+1].v>t[j].v) j++;
		if (t[j].v>t[x].v) swap(t[j],t[x]);
		else return ;
		x=j;
	}
}
inline void del() {
	t[1]=t[r--];
	down(1);
}
int main() {
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=k;i++) {
		insert(i,a[i]);
	}
	i=k+1;
	while (r) {
		if (i<=n) insert(i,a[i]);
		da[t[1].id]=i;
		ans+=1ll*t[1].v*(i-t[1].id);
		del();
		i++;
	}
	printf("%I64d\n",ans);
	for (i=1;i<=n;i++) printf("%d ",da[i]);
}