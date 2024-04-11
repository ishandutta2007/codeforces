#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
int a[N],p[N],out[N];
ll f[N];
bool v[N];
int n,m,cnt;
void work(int p){
	int t=min(a[p],a[p+1]);
	if (t) out[++m]=p;
	a[p]-=t; a[p+1]-=t;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ll O=f[max(i-2,0)]+a[i];
		ll E=f[max(i-3,0)]+max(a[i],a[i-1]);
		f[i]=min(O,E); v[i]=(f[i]!=O);
	}
	ll ans=min(f[n-1],f[n]);
	for (int i=n-(ans==f[n-1]);i>0;i-=2+v[i])
		p[++cnt]=i;
	reverse(p+1,p+cnt+1);
	for (int i=1;i<=cnt;i++){
		int pre=p[i-1],now=p[i];
		if (v) work(now-1);
		work(pre+1);
		work(now);
	}
	printf("%d\n",m);
	for (int i=1;i<=m;i++)
		printf("%d\n",out[i]); 
}