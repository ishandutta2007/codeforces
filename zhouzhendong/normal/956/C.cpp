#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,a[N],need[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
		need[i]=max(a[i],need[i+1]-1);
	LL ans=0;
	for (int i=1;i<=n;i++){
		need[i]=max(need[i],need[i-1]);
		ans+=need[i]-a[i];
	}
	printf("%I64d",ans);
	return 0;
}