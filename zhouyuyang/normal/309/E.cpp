#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 2010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int x,y,id;
} a[N];
int i,j,k,n,m;
int jiao[N][N],an[N],last[N],tt[N];
inline bool cc1(const ww &a,const ww &b) {
	return a.y<b.y;
}
inline bool ju(int x) {
	int i,j=1,k;
	For(i,1,n) last[i]=n;
	For(i,1,n) {
		an[i]=a[j].id; last[j]=i;
		For(k,1,n) if (jiao[j][k]) last[k]=min(last[k],i+x);
		For(k,0,n) tt[k]=0;
		For(k,1,n) tt[last[k]]++;
		For(k,1,n) {
			tt[k]+=tt[k-1];
			if (tt[k]>k) return 0;
		}
		for (k=i+1;k<=n;k++) if (tt[k]==k) break;
		For(j,1,n) if (last[j]>i&&last[j]<=k) break;
	}
	return 1;
}
int main() {
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+n+1,cc1);
	For(i,1,n)For(j,i+1,n) if (a[j].x<=a[i].y) jiao[i][j]=jiao[j][i]=1;
	int l=0,r=n,mid;
	for (;l<=r;) {
		mid=(l+r)/2;
		if (ju(mid)) r=mid-1;
		else l=mid+1;
	}
	r++;
	ju(r);
	For(i,1,n) printf("%d ",an[i]); printf("\n");
	return 0;
}