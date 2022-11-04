#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll a[N],b[N],c[N],d[N];
int n,cnt[32][2];
ll sum;
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for (int i=1;i<=n;i++) d[i]=b[i]+c[i],sum+=d[i];
	if (sum%(2*n)) GG();
	sum/=2*n;
	for (int i=1;i<=n;i++){
		if (d[i]<sum) GG();
		d[i]-=sum;
		if (d[i]%n) GG();
		a[i]=d[i]/n;
	}
	for (int i=1;i<=n;i++){
		int tmp=a[i];
		for (int j=0;j<30;j++)
			cnt[j][tmp&1]++,tmp>>=1;
	}
	for (int i=1;i<=n;i++){
		int tmp=a[i];
		for (int j=0;j<=30;j++){
			int now=tmp&1; tmp>>=1;
			for (int k=0;k<2;k++){
				b[i]-=(1ll<<j)*(now&k)*cnt[j][k];
				c[i]-=(1ll<<j)*(now|k)*cnt[j][k]; 
			}
		}
		if (b[i]||c[i]) GG();
	}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}