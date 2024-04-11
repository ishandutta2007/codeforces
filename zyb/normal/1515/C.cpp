#include<bits/stdc++.h>
using namespace std;
#define N 200005
int a[N],b[N],ans[N];
struct pa {
	int x,y;
};
struct Cmp {
	inline bool operator() (pa x,pa y) {
		if (x.y!=y.y) return x.y<y.y;
		return x.x<y.x;
	}
};
set<pa,Cmp>S;
inline bool cmp(int x,int y) {
	return a[x]<a[y];
}
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n,m,x;
		S.clear();
		scanf("%d%d%d",&n,&m,&x);
		int tot=n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) b[i]=0;
		for (int i=1;i<=m;i++) S.insert(pa{i,0});
		for (int i=1;i<=n;i++) {
			pa gt=*S.begin();
			S.erase(S.begin());
			ans[i]=gt.x;
			b[gt.x]+=a[i];
			S.insert(pa{gt.x,b[gt.x]});
		}
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
}