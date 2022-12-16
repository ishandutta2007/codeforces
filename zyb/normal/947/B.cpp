#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long i,j,k,l,s,n,m,a[N],b[N],S[N],A[N],ans[N];
int main() {
	scanf("%I64d",&n);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<=n;i++) scanf("%I64d",&b[i]),S[i]=S[i-1]+b[i];
	for (i=1;i<=n;i++) {
		int l=i,r=n,s=i-1;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (S[mid]-S[i-1]<=a[i]) s=mid,l=mid+1;
			else r=mid-1;
		}
		ans[s+1]+=a[i]-(S[s]-S[i-1]);
		A[i]++,A[s+1]--;
	}
	s=0;
	for (i=1;i<=n;i++) {
		s+=A[i];
		ans[i]+=b[i]*s;
		printf("%I64d ",ans[i]);
	}
}