#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=600005;
int c[N],sa[N],rk[N],lim[N];
int one[N],other[N];
int st[N],in[N],pos[N];
map<int,int> two[N];
pii eve[N],ask[N];
int ans[N];
int n,C;
int mx[N*2];
void change(int k,int l,int r,int x,int v){
	if (l==r) return mx[k]=v,void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
int askkk(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return mx[k];
	int mid=(l+r)/2;
	if (y<=mid) return askkk(k*2,l,mid,x,y);
	if (x>mid) return askkk(k*2+1,mid+1,r,x,y);
	return max(askkk(k*2,l,mid,x,mid),askkk(k*2+1,mid+1,r,mid+1,y));
}
bool cmp(int x,int y){
	return c[x]<c[y];
}
int cnt,Q,id[N];
int main(){
	scanf("%d%d",&n,&C);
	For(i,1,n){
		int l,r;
		scanf("%d%d%d",&l,&r,&c[i]);
		eve[++cnt]=pii(l,i);
		eve[++cnt]=pii(r,-i);
	}
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int k=n;
	For(i,1,n){
		rk[id[i]]=i;
		for (;k&&c[id[i]]+c[id[k]]>C;k--);
		lim[i]=k;
	}
	scanf("%d",&Q);
	For(i,1,Q){
		int x;
		scanf("%d",&x);
		ask[i]=pii(x,i);
	}
	sort(ask+1,ask+Q+1);
	int free=0,top=0,use=0;
	eve[++cnt].fi=2147483647;
	sort(eve+1,eve+cnt+1);
	for (int i=1,cur=1;cur<=Q;i++){
		int now=eve[i].first-eve[i-1].first,k,t;
		if (top==2&&c[k=st[1]]+c[t=st[2]]<=C){
			two[k][t]+=now;
			two[t][k]+=now;
			other[k]=max(other[k],two[k][t]+one[t]);
			other[t]=max(other[t],two[k][t]+one[k]);
			use=max(use,one[k]+one[t]+two[k][t]);
		}
		else if (top==1&&c[k=st[1]]<=C){
			change(1,1,n,rk[k],one[k]+=now);
			use=max(use,one[k]+other[k]);
			if (rk[k]!=1&&lim[rk[k]]) use=max(use,one[k]+askkk(1,1,n,1,min(rk[k]-1,lim[rk[k]])));
			if (rk[k]!=n&&lim[rk[k]]>rk[k]) use=max(use,one[k]+askkk(1,1,n,rk[k]+1,lim[rk[k]]));
		}
		else if (!top) free+=now;
		if ((k=eve[i].se)>0) st[pos[k]=++top]=k;
		else t=pos[-k],pos[st[t]=st[top--]]=t;
		for (;cur<=Q&&ask[cur].fi<=free+use;cur++)
			ans[ask[cur].se]=eve[i].first-(free+use-ask[cur].fi);
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}