#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[55],i,j,k,l,s,n,m,tot,r,vis[32][50005],G[65];
bool b[62][62];
struct node {
	int x,y,z,last;	
}q[10000005];
struct Node {
	int id,v;
}T[65];
inline bool cmp(Node x,Node y) {
	return x.v>y.v;
}
inline bool work(int x) {
	q[r=1].x=0,q[1].y=0,q[1].z=0;
	q[0].x=-1;
	l=0;
	while (l<r) {
		++l;
		if (q[l].x==x) return (vis[n][x*(x-1)/2]==tot);
		if (q[l].x!=q[l-1].x) tot++;
		if (q[l].z<q[l].x*(q[l].x-1)/2) continue;
		if (q[l].y&&(q[l].z+a[q[l].y]<=(x*(x-1)/2))) if (vis[q[l].y][q[l].z+a[q[l].y]]!=tot) {
			vis[q[l].y][q[l].z+a[q[l].y]]=tot;
			q[++r].x=q[l].x+1;
			q[r].y=q[l].y;
			q[r].z=q[l].z+a[q[l].y];
			q[r].last=l;
		}
		if (q[l].y+1<=n&&(q[l].z+a[q[l].y+1]<=(x*(x-1)/2))) if (vis[q[l].y+1][q[l].z+a[q[l].y+1]]!=tot) {
			vis[q[l].y+1][q[l].z+a[q[l].y+1]]=tot;
			q[++r].x=q[l].x+1;
			q[r].y=q[l].y+1;
			q[r].z=q[l].z+a[q[r].y];
			q[r].last=l;
		}
	}
	
}
inline void print(int x) {
	int i;
	for (i=r;i;i--) if (q[i].x==x&&q[i].y==n&&q[i].z==x*(x-1)/2) break;
	int GT=i;
	for (i=x;i;i--) {
		int gt=a[q[GT].y];
		for (int j=x;j>i;j--) {
			if (!b[j][i]&&!b[i][j]&&gt) b[i][j]=1,gt--;
		}
		for (int j=1;j<i;j++) T[j].id=j,T[j].v=G[j];
		sort(T+1,T+i,cmp);
		for (int j=1;j<i;j++) {
			if (!b[T[j].id][i]&&!b[i][T[j].id]&&gt&&T[j].v) b[i][T[j].id]=1,gt--,G[T[j].id]--;
		}
		GT=q[GT].last;
	}
	for (int i=x;i;i--) {
		for (int j=x;j;j--) if (b[i][j]) printf("1");
		else printf("0");
		puts("");
	}
}
inline void Print(int x) {
	int i;
	for (i=r;i;i--) if (q[i].x==x&&q[i].y==n&&q[i].z==x*(x-1)/2) break;
	int GT=i;
	for (i=x;i;i--) {
		G[i]=x-1-a[q[GT].y];
		GT=q[GT].last;
	}
}
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (i=n;i<=61;i++) 
	if (work(i)) {
		printf("%d\n",i);
		Print(i);
		print(i);
		return 0;
	}
	puts("=(");
}