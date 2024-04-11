#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],n,A[N];
#define pb push_back
#define lowbit(x) x&-x
struct pa {
	int l,r;
}q[N];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),A[a[i]]=0;
		int L=1;
		int r=0;
		for (int i=2;i<=n;i++) {
			if (a[i]==a[i-1]) q[++r]=pa{L,i-1},L=i;
		}
		q[++r]=pa{L,n};
		int ma=0;
		int ans=0;
		for (int i=1;i<=r;i++) {
			int x=a[q[i].l];
			A[x]++;
			if (A[x]>A[ma]) ma=x;
			ans++;
			x=a[q[i].r];
			A[x]++;
			if (A[x]>A[ma]) ma=x;
		}
		int y=2*r-A[ma];
		ans--;
		if (A[ma]<=2+y) {
			printf("%d\n",ans);
			continue;
		}
		A[ma]-=y;
		for (int i=2;i<=n;i++) {
			if (a[i]==a[i-1]) continue;
			if (a[i]==ma||a[i-1]==ma) continue;
			A[ma]-=2;
			if (A[ma]>=2) ans++;
		}
		if (A[ma]<=2) {
			printf("%d\n",ans);
			continue;
		}
		printf("-1\n");
	}
}