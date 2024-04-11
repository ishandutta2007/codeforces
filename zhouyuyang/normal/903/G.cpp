#include<bits/stdc++.h>
#define pa pair<int,int>
#define ll long long
#define N 200005
using namespace std;
vector<pa> v[N];
int n,m,q,a[N],b[N];
ll tg[N*3],mn[N*3],ans[N];
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
	mn[k*2]+=tg[k]; mn[k*2+1]+=tg[k];
	tg[k]=0;
}
void add(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		mn[k]+=v; tg[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),
		 add(k*2+1,mid+1,r,mid+1,y,v);
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
struct heap{
	priority_queue<ll,vector<ll>,greater<ll> > p,q;
	void push(ll x){p.push(x);}
	void erase(ll x){q.push(x);}
	ll top(){
		for (;!q.empty()&&p.top()==q.top();p.pop(),q.pop());
		return p.top();
	}
}Q;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(pa(y,z));
	}
	for (int i=2;i<=n;i++)
		add(1,1,n,i,i,b[i-1]);
	for (int i=1;i<=n;i++){
		for (int j=0;j<v[i].size();j++)
			add(1,1,n,1,v[i][j].first,v[i][j].second);
		ans[i]=mn[1];
	}
	for (int i=1;i<=n;i++)
		Q.push(ans[i]+a[i]);
	printf("%I64d\n",Q.top());
	while (q--){
		int p,v;
		scanf("%d%d",&p,&v);
		Q.erase(ans[p]+a[p]);
		a[p]=v;
		Q.push(ans[p]+a[p]);
		printf("%I64d\n",Q.top());
	}
}