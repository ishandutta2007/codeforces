#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;

struct jdb{
	int x,y;
	friend ll operator ^(const jdb &a,const jdb &b){
		return 1ll*a.x*b.y-1ll*a.y*b.x;
	}
	friend ll operator *(const jdb &a,const jdb &b){
		return 1ll*a.x*b.x+1ll*a.y*b.y;
	}
	friend bool operator <(const jdb &a,const jdb &b){
		return (a.x!=b.x?a.x<b.x:a.y<b.y);
	}
	friend jdb operator -(const jdb &a,const jdb &b){
		return (jdb){a.x-b.x,a.y-b.y};
	}
}p[N],st[N];
struct que{
	int x,y;
	ll ans;
	que(){ans=-(1ll<<62);};
}q[N];
vector<jdb> vec[N*4];
int L[N],pos[N];
bool fl[N],isq[N];
int n,m,tot,top,cnt;
void insert(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		vec[k].push_back(p[v]);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) insert(k*2,l,mid,x,y,v);
	else if (x>mid) insert(k*2+1,mid+1,r,x,y,v);
	else insert(k*2,l,mid,x,mid,v),
		 insert(k*2+1,mid+1,r,mid+1,y,v);
}
void query(int i){
	if (!top) return;
	jdb tmp=(jdb){q[i].x,q[i].y};
	int l=1,r=top;
	while (r-l>=3){
		int m1=l+(r-l)/3;
		int m2=r-(r-l)/3;
		if (tmp*st[m1]>tmp*st[m2]) r=m2;
		else l=m1;
	}
	for (int j=l;j<=r;j++)
		q[i].ans=max(q[i].ans,tmp*st[j]);
}
void solve(int k,int l,int r){
	ll mid=(l+r)/2;
	if (l<r){
		solve(k*2,l,mid);
		solve(k*2+1,mid+1,r);
	}
	top=0;
	sort(vec[k].begin(),vec[k].end());
	for (int i=0;i<vec[k].size();i++){
		for (;top>1&&((vec[k][i]-st[top])^(st[top]-st[top-1]))<=0;top--);
		st[++top]=vec[k][i];
	}
	for (int i=l;i<=r;i++)
		if (isq[i]) query(i);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int tp,x,y;
		scanf("%d",&tp);
		if (tp==1){
			scanf("%d%d",&x,&y);
			p[++tot]=(jdb){x,y};
			L[tot]=i; pos[i]=tot;
			cnt++;
		}
		if (tp==2){
			scanf("%d",&x);
			x=pos[x];
			insert(1,1,n,L[x],i,x);
			L[x]=0; cnt--;
		}
		if (tp==3){
			scanf("%d",&q[i].x);
			q[i].y=1; isq[i]=1;
			if (!cnt){
				fl[i]=1;
				q[i].x=q[i].y=isq[i]=0;
			}
		}
	}
	for (int i=1;i<=tot;i++)
		if (L[i]) insert(1,1,n,L[i],n,i);
	solve(1,1,n);
	for (int i=1;i<=n;i++){
		if (fl[i]) puts("EMPTY SET");
		if (isq[i]) printf("%I64d\n",q[i].ans);
	}
}