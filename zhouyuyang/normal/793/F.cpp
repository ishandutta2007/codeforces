#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,Q,ans[N],t[265000];
vector<int> v[N];
vector<pair<int,int> > vq[N];
void build(int k,int l,int r){
	t[k]=1e9;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	t[k*2]=min(t[k*2],t[k]);
	t[k*2+1]=min(t[k*2+1],t[k]);
}
void change(int k,int l,int r,int x,int y,int v){
	if (t[k]<=v) return;
	if (l==x&&r==y){
		t[k]=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	t[k]=max(t[k*2],t[k*2+1]);
}
int ask(int k,int l,int r,int p,int v){
	if (t[k]<=v) return -1;
	if (p<=l){
		for (;l<r;){
			int mid=(l+r)/2;
			pushdown(k);
			k*=2;
			if (t[k]>v)
				r=mid;
			else l=mid+1,k++;
		}
		return l;
	}
	int mid=(l+r)/2;
	int tmp=-1;
	if (p<=mid) tmp=ask(k*2,l,mid,p,v);
	if (tmp!=-1) return tmp;
	return ask(k*2+1,mid+1,r,p,v);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<y)
			v[x].push_back(y);
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vq[x].push_back(make_pair(y,i));
	}
	build(1,1,n);
	for (int i=n;i;i--){
		for (int j=0;j<v[i].size();j++)
			change(1,1,n,i,v[i][j]-1,v[i][j]);
		for (int j=0;j<vq[i].size();j++)
			ans[vq[i][j].second]=ask(1,1,n,i,vq[i][j].first);
	}
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}