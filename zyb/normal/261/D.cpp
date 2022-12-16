#include<stdio.h>
#include<cstring>
#include<algorithm>
#define N 100005
#define lowbit(o) o&-o
using namespace std;
int i,j,k,l,s,n,m,test,maxb,t,F[N],a[N],f[N];
inline void change(int o,int p) {
	for (;o<=N-5;o+=lowbit(o)) f[o]=max(f[o],p);
}
inline int ask(int o) {
	int s=0;
	for (;o;o-=lowbit(o)) s=max(s,f[o]);
	return s;
}
int main() {
	scanf("%d%d%d%d",&test,&n,&maxb,&t);
	t=min(t,maxb);
	while (test--) {
		for (i=1;i<=n;i++) scanf("%d",&a[i]),F[i]=0;
		memset(f,0,sizeof(f));
		for (i=1;i<=t;i++)
		for (j=1;j<=n;j++) {
			int gt=ask(a[j]);
			if (gt>=F[j])
			change(a[j]+1,gt+1),F[j]=gt+1;
		}
		printf("%d\n",ask(N-5));
	}
}