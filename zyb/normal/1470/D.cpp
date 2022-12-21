#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 3000005
int i,j,k,l,s,n,m,test;
#define pb push_back
vector<int>A[N],ans;
set<int>C;
int fa[N],a[N];
inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int main() {
	scanf("%d",&test);
	while (test--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) a[i]=0,fa[i]=i,A[i].clear();
		for (int i=1;i<=m;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			A[x].pb(y),A[y].pb(x);
			fa[get(x)]=get(y);
		}
		int flag=0;
		for (int i=1;i<=n;i++) {
			if (get(i)!=get(1)) flag=1;
		}
		if (flag) {
			puts("NO");
			continue;
		}
		puts("YES");
		ans.clear();
		a[1]=2;
		C.clear();
		C.insert(1);
		while (C.size()>0) {
			int p=(*C.begin());
			a[p]=3;
			C.erase(p);
			ans.pb(p);
			for (auto x:A[p]) {
				assert(a[x]!=3);
				if (a[x]==1) continue;
				if (a[x]==2) {
					a[x]=1;
					for (auto y:A[x]) {
						if (a[y]==1) continue;
						if (!a[y]) {
							a[y]=2;
							C.insert(y);
						}
					}
					C.erase(x);
					continue;
				}
				a[x]=1;	
				for (auto y:A[x]) {
					if (a[y]==1) continue;
					if (!a[y]) {
						a[y]=2;
						C.insert(y);
					}
				}
			}
		}
		for (int i=1;i<=n;i++) assert(a[i]>0);
		printf("%d\n",ans.size());
		for (auto p:ans) printf("%d ",p);
		puts("");
	}
}