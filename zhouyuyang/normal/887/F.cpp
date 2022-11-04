#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,t;
int a[N],p[N],nxt[N],q[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,cmp);
	for (int i=n;i;i--){
		for (;t&&a[q[t]]>=a[i];t--);
		nxt[i]=(t?q[t]:n+1);
		q[++t]=i;
	}
	int x=n+1,y=n+1;
	for (int i=1;i<=n;i++){
		int id=p[i];
		if (y>id+k) return puts("NO"),0;
		if (x>id+k){
			bool f=1;
			for (int i=1;i<id;i++)
				if (nxt[i]-i>k) f=0;
			puts(f?"YES":"NO");
			return 0;
		}
		y=min(y,x-k);
		x=min(x,id);
	}
	puts("YES");
}