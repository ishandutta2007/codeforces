#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct node {
	int L,R;
}b[N];
int i,j,k,l,s,n,m,d,a[N],A[N],ans;
inline bool check(int x) {
	int L=(n+1)/2-x+1,R=(n+1)/2+x-1;
	if (!(n&1)) R++;
	R=min(R,n);
	int j=1;
	for (int i=1;i<=n;i++) A[i]=a[i];
	for (int i=L;i<=R;i++) {
		int s=0;
		while (b[j].R<i&&j<=n) j++;
		if (j>n) return false;
		while (s<m) {
			if (s+A[j]<m) s+=A[j],j++;
			if (j>n) return false;
			if (b[j].L>i) return false;
			if (s+A[j]>=m) {
				A[j]-=(m-s);
				s=m;
			}
			
		}
	}
	return true;
}
int main() {
	scanf("%d%d%d",&n,&d,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) {
		b[i].L=(i-1)/(d+1)+1;
		b[i].R=n-(n-i)/(d+1);
	}
	int l=0,r=(n+1)/2;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",(n+1)/2-ans);
}