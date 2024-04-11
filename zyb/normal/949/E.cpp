#include<bits/stdc++.h>
#define N 100005
using namespace std;
int i,j,k,l,s,n,m,a[N],da[N],A[N],ans,Ans,b[25][N];
inline void work(int x,int n) {
	if (!n) {
		if (ans<Ans) {
			Ans=ans;
			for (int i=1;i<=ans;i++) da[i]=A[i];
		}
		return ;
	}
	if (x>20) return ;
	if (ans>=Ans) return ;
	for (int i=1;i<=n;i++) b[x][i]=a[i];
	int gt=0; 	
	for (int i=1;i<=n;i++) gt=gt|(a[i]&1);
	if (!gt) {
		int m=0;
		for (int i=1;i<=n;i++) if (a[i]&&((a[i]>>1)!=a[m])) a[++m]=a[i]>>1;
		work(x+1,m);
	}
	else {
		for (int i=-1;i<=1;i+=2) {
			int m=0;
			A[++ans]=i*(1<<x);
			for (int j=1;j<=n;j++) if (a[j]&1) {
				if (((a[j]-i)>>1)&&(((a[j]-i)>>1)!=a[m])) a[++m]=(a[j]-i)>>1;
			}
			else if (a[j]&&((a[j]>>1)!=a[m])) a[++m]=a[j]>>1;
			work(x+1,m);
			--ans;
			for (int j=1;j<=n;j++) a[j]=b[x][j];
		}
	}
}
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	Ans=100;
	work(0,n);
	printf("%d\n",Ans);
	for (i=1;i<=Ans;i++) printf("%d ",da[i]);
	puts("");
}