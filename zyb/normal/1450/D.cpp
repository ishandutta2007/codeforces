#include<bits/stdc++.h>
#define N 300005
using namespace std;
int a[N],n,A[N],f[N],L[N],R[N];
#define pb push_back
#define lowbit(x) x&-x
struct pa {
	int x,y;
}q[N];
vector<int>B[N];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) f[i]=0,scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) f[a[i]]++,B[i].clear();
		int mex=1;
		for (int i=1;i<=n;i++) if (f[i]&&mex==i) mex=i+1;
		int r=1; q[1]=pa{0,0};
		for (int i=1;i<=n;i++) {
			while (r&&q[r].y>=a[i]) r--;
			L[i]=q[r].x;
			q[++r]=pa{i,a[i]};
		}
		r=1; q[1]=pa{n+1,0};
		for (int i=n;i;i--) {
			while (r&&q[r].y>a[i]) r--;
			R[i]=q[r].x;
			q[++r]=pa{i,a[i]};
		}
		for (int i=1;i<=n;i++) {
			B[R[i]-L[i]-1].pb(a[i]);
		}
		for (int i=1;i<=n;i++) {
			if (mex==n-i+2) printf("1");
			else printf("0");
			for (auto p:B[i]) {
				f[p]--;
				if (!f[p]) mex=min(mex,p);
			}
		}
		puts("");
	}
}