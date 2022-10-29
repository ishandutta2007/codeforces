#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
int b[maxn],n,s,a[maxn];
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int x=lower_bound(a+1,a+n+1,s)-a-1;
	int mid=(n+1)/2;
	long long ans=0;
	if(x>=mid)for(int i=mid;i<=x;++i)ans+=abs(a[i]-s);
	else for(int i=x+1;i<=mid;++i)ans+=abs(a[i]-s);
	printf("%lld",ans);
}