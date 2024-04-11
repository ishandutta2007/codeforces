#include<bits/stdc++.h>
#define N 15005
#define P 500
using namespace std;
int f[N][P+5],g[N][P+5],a[N],n;
#define lowbit(x) x&-x
struct tree {
    int f[N];
    inline void change(int x, int y) {
        for (;x;x-=lowbit(x)) f[x]=min(f[x],y);
    }
    inline int ask(int x) {
        int s=n+1;
        for (;x<=n;x+=lowbit(x)) s=min(s,f[x]);
        return s;
    }
    inline void init() {
        for (int i=0;i<=n;i++) f[i]=n+1;
    }
}F[P+5];
struct tree1 {
    int f[N];
    inline void change(int x, int y) {
        for (;x<=n;x+=lowbit(x)) f[x]=max(f[x],y);
    }
    inline int ask(int x) {
        int s=0;
        for (;x;x-=lowbit(x)) s=max(s,f[x]);
        return s;
    }
    inline void init() {
        for (int i=0;i<=n;i++) f[i]=0;
    }
}G[P+5];
struct tree2 {
    int f[N];
    inline void change(int x, int y) {
        for (;x;x-=lowbit(x)) f[x]=min(f[x],y);
    }
    inline int ask(int x) {
        int s=n+1;
        for (;x<=n;x+=lowbit(x)) s=min(s,f[x]);
        return s;
    }
    
    inline void init() {
        for (int i=0;i<=n;i++) f[i]=n+1;
    }
}F1[P+5];
struct tree3 {
    int f[N];
    inline void change(int x, int y) {
        for (;x<=n;x+=lowbit(x)) f[x]=max(f[x],y);
    }
    inline int ask(int x) {
        int s=0;
        for (;x;x-=lowbit(x)) s=max(s,f[x]);
        return s;
    }
    inline void init() {
        for (int i=0;i<=n;i++) f[i]=0;
    }
}G1[P+5];
inline int work(int flag) {
	for (int i=0;i<=P;i++) F[i].init(),G[i].init(),F1[i].init(),G1[i].init();
	for (int i=1;i<=n;i++)
	for (int k=0;k<=P;k++) f[i][k]=n+1,g[i][k]=0;
	f[n][1]=g[n][1]=a[n];
	for (int i=n;i;i--) {
		if (!flag) {
			f[i][1]=g[i][1]=a[i];
		}
		for (int k=2;k<=P;k++) f[i][k]=n+1,g[i][k]=0;
		for (int k=2;k<P;k++) {
			f[i][k]=F[k-1].ask(a[i]);
		}
		for (int k=2;k<P;k++) {
			g[i][k]=G[k-1].ask(a[i]);
		}

		for (int k=1;k<P;k++) {
			int y=i+k+(!flag);
			if (y<=n&&g[y][k])
			F1[k].change(g[y][k],a[y]);
			f[i][k+1]=min(f[i][k+1],F1[k].ask(a[i]));
			
		}
		for (int k=1;k<P;k++) {
			int y=i+k+(!flag);
			if (y<=n&&f[y][k]!=n+1)
			G1[k].change(f[y][k],a[y]);
			g[i][k+1]=max(g[i][k+1],G1[k].ask(a[i]));
			
		}
		for (int k=0;k<=P;k++) {
			F[k].change(a[i],f[i][k]);
			G[k].change(a[i],g[i][k]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=P;j++) {
		if (f[i][j]<=n) ans=max(ans,j);
		if (g[i][j]>0) ans=max(ans,j);
	}
	return ans;
}
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=work(0);
		ans=max(ans,work(1));
        printf("%d\n",ans);
    }
}