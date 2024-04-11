#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define id(i,j) ((i)*(m+1)+j)
using namespace std;
int a[500010],n,m,p[500100],q[500100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[id(i,j)]);
	for(int i=n,j;i>=1;--i)
		for(j=1;j<=m;++j)
			if(a[id(i,j)]<=a[id(i+1,j)])
				p[id(i,j)]=p[id(i+1,j)]+1;
			else p[id(i,j)]=1;
//	for(int i=1;i<=n;++i,putchar(10))
//		for(int j=1;j<=m;++j)printf("[%d]",a[id(i,j)]);
	for(int i=1;i<=n;++i){
		q[i]=0;
		for(int j=1;j<=m;++j)q[i]=max(q[i],p[id(i,j)]);
//		printf("[%d]",q[i]);
		q[i]+=i-1;
	}
	int Q;scanf("%d",&Q);
	for(int i=1;i<=Q;++i){
		int x,y;scanf("%d%d",&x,&y);
		puts(q[x]>=y?"Yes":"No");
	}
}