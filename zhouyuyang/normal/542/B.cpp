#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
#define se second
#define fi first
int n,k,pre=-1;
priority_queue<pa > q;
const int M=6666666;
int mx[M],ls[M],rs[M],tg[M],sz;
void pushup(int k){
	mx[k]=max(mx[ls[k]],mx[rs[k]])+tg[k];
}
void upd(int &k,int l,int r,int x,int v){
	if (!k) k=++sz;
	if (l==r){
		tg[k]=mx[k]=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) upd(ls[k],l,mid,x,v);
	else upd(rs[k],mid+1,r,x,v);
	pushup(k);
}
void add(int &k,int l,int r,int x,int y){
	if (!k||y<l||r<x) return;
	if (x<=l&&r<=y){
		mx[k]++; tg[k]++;
		return;
	}
	int mid=(l+r)/2;
	add(ls[k],l,mid,x,y);
	add(rs[k],mid+1,r,x,y);
	pushup(k);
}
int ask(int &k,int l,int r,int x,int y){
	if (!k||y<l||r<x) return 0;
	if (x<=l&&r<=y) return mx[k];
	int mid=(l+r)/2;
	int ans=ask(ls[k],l,mid,x,y);
	ans=max(ans,ask(rs[k],mid+1,r,x,y));
	return ans+tg[k];
}
int rt;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l=max(0,l);
		q.push(pa(-r,-l));
		q.push(pa(-l,1));
	}
	while (!q.empty()){
		int l=-q.top().se,r=-q.top().fi; q.pop();
		if (l>=0) add(rt,0,1e9,l,r);
		else{
			if (r==pre) continue;
			int u=ask(rt,0,1e9,pre,pre);
			int v=ask(rt,0,1e9,0,r-k);
			if (l==-1||u<v){
				pre=r;
				upd(rt,0,1e9,r,v);
				if (r+k<=1e9)
					q.push(pa(-r-k,2));
			}
		}
	}
	printf("%d\n",mx[1]);
}