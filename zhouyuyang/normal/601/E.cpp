#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
const ll p=10000019;
const ll mo=1000000007;
int f[31][1001],sx[N];
int n,k,tot,now,Q,fl,x;
struct jdb{int v,w,s,e;}a[N];
vector<int> q;
inline void calc(int l,int r,int d,vector<int> q){
	memcpy(f[d],f[d-1],sizeof(f[d]));
	for (int i=0;i<q.size();i++)
		if (a[q[i]].s<=l&&a[q[i]].e>=r)
			for (int j=k;j>=a[q[i]].w;j--)
				f[d][j]=max(f[d][j],f[d][j-a[q[i]].w]+a[q[i]].v);
	//printf("%d %d %d\n",l,r,sx[l]);
	if (l==r){
		ll ans=0;
		for (int i=k;i>=1;i--)
			ans=(ans*p+f[d][i])%mo;
		for (int i=1;i<=sx[l];i++)
			printf("%I64d\n",ans);
		return;
	}
	int mid=(l+r)/2;
	vector<int> L,R;
	for (int i=0;i<q.size();i++){
		if (a[q[i]].s<=l&&a[q[i]].e>=r) continue;
		if (a[q[i]].s<=mid) L.push_back(q[i]);
		if (a[q[i]].e>mid) R.push_back(q[i]);
	}
	calc(l,mid,d+1,L); calc(mid+1,r,d+1,R);
}
int main(){
	memset(sx,0,sizeof(sx));
	scanf("%d%d",&n,&k);
	tot=n; now=1;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].v,&a[i].w);
		a[i].s=1;
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d",&fl);
		if (fl==1){
			tot++; now++;
			scanf("%d%d",&a[tot].v,&a[tot].w);
			a[tot].s=now;
		}
		else if (fl==2){
			scanf("%d",&x);
			a[x].e=now;
			now++;
		}
		else sx[now]++;
	}
	for (int i=1;i<=tot;i++){
		q.push_back(i);
		if (a[i].e==0)
			a[i].e=now;
	}
	calc(1,now,1,q);
}