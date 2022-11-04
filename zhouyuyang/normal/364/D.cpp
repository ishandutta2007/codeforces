#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
ll a[N],d[10005],ans;
int b[10005],n,m;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void work(int x){
	m=0;
	memset(b,0,sizeof(b));
	for (int i=1;1ll*i*i<=a[x];i++)
		if (a[x]%i==0){
			d[++m]=i;
			d[++m]=a[x]/i;
		}
	sort(d+1,d+m+1);
	m=unique(d+1,d+m+1)-d-1;
	for (int i=1;i<=n;i++)
		b[lower_bound(d+1,d+m+1,gcd(a[i],a[x]))-d]++;
	for (int i=m;i&&d[i]>ans;i--){
		int tmp=0;
		for (int j=i;j<=m;j++)
			if (d[j]%d[i]==0) tmp+=b[j];
		if (tmp*2>=n){
			ans=max(ans,d[i]);
			return;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=10;i++)
		work(((rand()<<15)+rand())%n+1);
	printf("%lld",ans);
}