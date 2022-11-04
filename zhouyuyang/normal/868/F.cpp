#include<bits/stdc++.h>
#define ll long long 
#define N 100005
using namespace std;
int s[N],a[N];
ll f[N],g[N],now;
int n,k,l,r;
void work(int l1,int r1,int l2,int r2){
	//printf("%d %d %d %d\n",l1,r1,l2,r2);
	if (l1>r1) return;
	int mid=(l1+r1)/2,tmp=min(r2,mid)+1;
	for (;l<tmp;now-=(--s[a[l]]),l++);
	for (;l<tmp;l--,now+=(s[a[l]]++));
	for (;r<mid;r++,now+=(s[a[r]]++));
	for (;r>mid;now-=(--s[a[r]]),r--);
	ll mx=1e18; int at;
	for (;tmp>=l2;tmp--){
		if (f[tmp-1]+now<mx)
			mx=f[tmp-1]+now,at=tmp;
		l--; now+=(s[a[l]]++);
	}
	g[mid]=mx;
	work(l1,mid-1,l2,at);
	work(mid+1,r1,at,r2);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=k;i++){
		memset(g,60,sizeof(g));
		memset(s,0,sizeof(s));
		l=1,r=0,now=0;
		work(1,n,1,n);
		memcpy(f,g,sizeof(f));
	}
	printf("%I64d",f[n]);
}