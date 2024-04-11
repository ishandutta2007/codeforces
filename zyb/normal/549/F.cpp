#include<stdio.h>
#include<algorithm>
#define N 300005
#define M 1000005
using namespace std;
int i,j,k,l,s,n,m,GT[M],gt[M],a[N];
long long ans;
struct node {
	int v,ma;
}A[N],B[N];
inline void work(int l,int r) {
	if (l>=r) return ;
	int mid=(l+r)>>1;
	work(l,mid),work(mid+1,r);
	int tot=0,ma=0,sum=0;
	for (int i=mid;i>=l;i--) {
		ma=max(ma,a[i]);
		sum+=a[i]; sum%=k;
		A[++tot].v=sum; A[tot].ma=ma;
		gt[sum]++;
	}
	int Tot=0;
	ma=0,sum=0;
	for (int i=mid+1;i<=r;i++) {
		ma=max(ma,a[i]);
		sum+=a[i]; sum%=k;
		B[++Tot].v=sum; B[Tot].ma=ma;
		GT[sum]++;
	}
	int i=tot,j=Tot;
	while (i&&j) {
		if (A[i].ma>B[j].ma) {
			ans+=GT[(k-((A[i].v-A[i].ma%k)+k)%k)%k];
			gt[A[i].v]--,i--;
		}
		else {
			ans+=gt[(k-((B[j].v-B[j].ma%k)+k)%k)%k];
			GT[B[j].v]--,j--;
		}
	}
	for (;i;i--) gt[A[i].v]--;
	for (;j;j--) GT[B[j].v]--;
}
inline int in() {
	char c=getchar();
	while (c<'0') c=getchar();
	int s=0;
	while (c>='0') s=s*10+c-48,c=getchar();
	return s;
}
int main() {
	n=in(),k=in();
	for (i=1;i<=n;i++) a[i]=in();
	work(1,n);
	printf("%I64d\n",ans);
}