#include<bits/stdc++.h>
#define N 100005
using namespace std;
char c[N];
#define pb push_back
#define lowbit(x) x&-x
struct pa {
	int x,y;
}a[N];
int n,k;
inline bool check(int x,int y) {
	return abs(a[x].x-a[y].x)+abs(a[x].y-a[y].y)>k;
}
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n;
		scanf("%d%d",&n,&k);
		int ans=-1;
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		for (int i=1;i<=n;i++) {
			int flag=1;
			for (int j=1;j<=n;j++) if (check(i,j)) flag=0;
			if (flag) ans=1;
		}
		printf("%d\n",ans);
	}
}